#include "common.h"
#include "pattern_batch.h"
#include "range.h"

namespace memory
{
	void pattern_batch::add(std::string name, pattern pattern, std::function<void(handle)> callback)
	{
		m_entries.emplace_back(std::move(name), std::move(pattern), std::move(callback));
	}

	void pattern_batch::run(range region)
	{
		bool all_found = true;
		for (auto& entry : m_entries)
		{
			if (auto result = region.scan(entry.m_pattern))
			{
				if (entry.m_callback)
				{
					std::invoke(std::move(entry.m_callback), result);
					std::cout << "Found: " << entry.m_name << std::endl;
				}
				else
				{
					all_found = false;
					std::cout << "Failed finding: " << entry.m_name << std::endl;
					//throw std::runtime_error(entry.m_name);
				}
			}
		}

		m_entries.clear();
		if (!all_found)
		{
			printf("Failed finding some patterns.\n");
			//throw std::runtime_error("Failed to find some patterns.");
		}
	}
}
