#pragma once
#include "common.h"
#include "array.h"
#include "player.h"
#include "structs.h"
#include "pointers.h"

namespace gta_util
{
	template <typename F, typename ...Args>
	void execute_as_script(rage::joaat_t script_hash, F&& callback, Args&&...args)
	{
		auto tls_ctx = rage::tlsContext::get();
		for (auto thread : *g_pointers->m_script_threads)
		{
			if (!thread || !thread->m_context.m_thread_id || thread->m_context.m_script_hash != script_hash)
				continue;

			auto og_thread = tls_ctx->m_script_thread;

			tls_ctx->m_script_thread = thread;
			tls_ctx->m_is_script_thread_active = true;

			std::invoke(std::forward<F>(callback), std::forward<Args>(args)...);

			tls_ctx->m_script_thread = og_thread;
			tls_ctx->m_is_script_thread_active = og_thread != nullptr;

			return;
		}
	}

	inline rage::scrThread* find_script_thread(rage::joaat_t script_hash)
	{
		for (rage::scrThread* thread : *g_pointers->m_script_threads)
		{
			if (!thread || !thread->m_context.m_thread_id || thread->m_context.m_script_hash != script_hash)
				continue;

			return thread;
		}
		return nullptr;
	}

	template <typename F, typename ...Args>
	void list_script_threads()
	{
		for (GtaThread* thread : *g_pointers->m_script_threads)
		{
			if (!thread || !thread->m_context.m_thread_id)
				continue;

			ImGui::Text("%s 0x%X", thread->m_name, thread->m_context.m_script_hash);
		}
	}
}
