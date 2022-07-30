#pragma once
#include "common.h"
#include "joaat.h"
#include "base.h"
#include "fwddec.h"

struct MemoryPool
{
	uintptr_t ListAddr;
	char* BoolAdr;
	int MaxCount;
	int ItemSize;
};

namespace rage
{
	class tlsContext
	{
	public:
		char m_padding1[0xC8];          // 0x00
		sysMemAllocator* m_allocator;   // 0xC8
		char m_padding2[0x760];         // 0xD0
		scrThread* m_script_thread;     // 0x830
		bool m_is_script_thread_active; // 0x838

		static tlsContext* get()
		{
			return *reinterpret_cast<tlsContext**>(__readgsqword(0x58));
		}
	};

	static_assert(sizeof(tlsContext) == 0x840);
}

namespace rage
{
	enum class eThreadState : std::uint32_t
	{
		idle,
		running,
		killed,
		unk_3,
		unk_4,
	};

	class scrThreadContext
	{
	public:
		std::uint32_t m_thread_id;           // 0x00
		joaat_t m_script_hash;               // 0x04
		eThreadState m_state;                // 0x08
		std::uint32_t m_instruction_pointer; // 0x0C
		std::uint32_t m_frame_pointer;       // 0x10
		std::uint32_t m_stack_pointer;       // 0x14
		float m_timer_a;                     // 0x18
		float m_timer_b;                     // 0x1C
		float m_timer_c;                     // 0x20
		char m_padding1[0x2C];               // 0x24
		std::uint32_t m_stack_size;          // 0x50
		char m_padding2[0x54];               // 0x54
	};

	class scrThread
	{
	public:
		virtual ~scrThread() = default;                                                                 // 0 (0x00)
		virtual void reset(std::uint32_t script_hash, void* args, std::uint32_t arg_count) = 0;         // 1 (0x08)
		virtual eThreadState run() = 0;                                                                 // 2 (0x10)
		virtual eThreadState tick(std::uint32_t ops_to_execute) = 0;                                    // 3 (0x18)
		virtual void kill() = 0;                                                                        // 4 (0x20)

		static scrThread* get()
		{
			return rage::tlsContext::get()->m_script_thread;
		}
	public:
		scrThreadContext m_context;                 // 0x08
		void* m_stack;                              // 0xB0
		char m_padding[0x10];                       // 0xB8
		const char* m_exit_message;                 // 0xC8
		char m_name[0x40];                          // 0xD0
		scriptHandler* m_handler;                   // 0x110
		scriptHandlerNetComponent* m_net_component; // 0x118
	};

	static_assert(sizeof(scrThreadContext) == 0xA8);
	static_assert(sizeof(scrThread) == 0x120);
}

class GtaThread : public rage::scrThread
{
public:
	rage::joaat_t m_script_hash;                // 0x120
	char m_padding3[0x14];                      // 0x124
	std::int32_t m_instance_id;                 // 0x138
	char m_padding4[0x04];                      // 0x13C
	std::uint8_t m_flag1;                       // 0x140
	bool m_safe_for_network_game;               // 0x141
	char m_padding5[0x02];                      // 0x142
	bool m_is_minigame_script;                  // 0x144
	char m_padding6[0x02];                      // 0x145
	bool m_can_be_paused;                       // 0x147
	bool m_can_remove_blips_from_other_scripts; // 0x148
	char m_padding7[0x0F];                      // 0x149
};

static_assert(sizeof(GtaThread) == 0x158);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace rage
{
	template <typename T, typename Base = datBase>
	class atDNode : public Base
	{
	public:
		T m_data;
		void* m_unk;
		atDNode<T, Base>* m_next;
	};

	template <typename Node>
	class atDList
	{
	public:
		Node* m_head;
		Node* m_tail;
	};
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(push, 1)
namespace rage
{
	class scriptIdBase
	{
	public:
		virtual ~scriptIdBase() = default;                            // 0 (0x00)

		// Assumes the script thread's identity.
		virtual void assume_thread_identity(scrThread*) {};           // 1 (0x08)

		// Returns whether the hash of the script id is valid.
		virtual bool is_valid() {};                                   // 2 (0x10)

		// Gets the hash of the script id.
		virtual joaat_t* get_hash(joaat_t* out) {};                   // 3 (0x18)

		// Gets an unknown value from the script id.
		virtual std::uint32_t* get_hash2(std::uint32_t* out) {};      // 4 (0x20)

		// Gets the name of the script id.
		virtual const char* get_name() {};                            // 5 (0x28)

		// Serializes the script id from the buffer.
		virtual void deserialize(datBitBuffer* buffer) {};            // 6 (0x30)

		// Serializes the script id to the buffer.
		virtual void serialize(datBitBuffer* buffer) {};              // 7 (0x38)

		// Calculates some information with the position hash & instance id.
		virtual std::uint32_t _0x40() {};                             // 8 (0x40)

		// Calls _0x40 and returns it's value added to another value.
		virtual std::uint32_t _0x48() {};                             // 9 (0x48)

		// Logs some information about the script id.
		virtual void log_information(netLoggingInterface* logger) {}; // 10 (0x50)

		// Copies the information of other to this object.
		virtual void copy_data(scriptIdBase* other) {}                // 11 (0x58)

		// Returns whether the other script id is equal.
		virtual bool operator==(scriptIdBase*) {};                    // 12 (0x60)

		virtual bool _0x68(void*) {};                                 // 13 (0x68)
	};

	class scriptId : public scriptIdBase
	{
	public:
		joaat_t m_hash;           // 0x08
		char m_name[0x20];        // 0x0C
	};
}

class CGameScriptId : public rage::scriptId
{
public:
	char m_padding[0x04];         // 0x2C
	std::int32_t m_timestamp;     // 0x30
	std::int32_t m_position_hash; // 0x34
	std::int32_t m_instance_id;   // 0x38
	std::int32_t m_unk;           // 0x3C
};

static_assert(sizeof(CGameScriptId) == 0x40);
#pragma pack(pop)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma pack(push, 1)
namespace rage
{
	class scriptResource
	{
	public:
		virtual ~scriptResource() = default;
	};

	class scriptResourceEntry
	{
	public:
		scriptResource* m_data;      // 0x00
		std::uint32_t m_unk;         // 0x04
		char m_padding[0x0C];        // 0x0C
		scriptResourceEntry* m_next; // 0x18
	};

	class scriptHandlerNetComponent
	{
	public:
		virtual ~scriptHandlerNetComponent() = default;

	public:
		scriptHandler* m_script_handler; // 0x08
	};

	class scriptHandler
	{
	public:
		class atDScriptObjectNode : public atDNode<scriptHandlerObject*>
		{
		};
	public:
		virtual ~scriptHandler() = default;                                                                   //  0 (0x00)

		virtual bool _0x08() = 0;                                                                             //  1 (0x08)

		virtual void _0x10() = 0;                                                                             //  2 (0x10)

		virtual void cleanup_objects() = 0;                                                                   //  3 (0x18)

		virtual scriptId* _0x20() = 0;                                                                        //  4 (0x20)

		virtual scriptId* get_id() = 0;                                                                       //  5 (0x28)

		// Returns whether the script handler belongs to a networked script.
		virtual bool is_networked() = 0;                                                                      //  6 (0x30)

		// Initializes the network component for the script handler.
		virtual void init_net_component() = 0;                                                                //  7 (0x38)

		// Deletes the script handler's network component, if it exists.
		virtual void reset_net_component() = 0;                                                               //  8 (0x40)

		// Destroys the script handler.
		virtual bool destroy() = 0;                                                                           //  9 (0x48)

		// Adds the object to the script handler's list of objects.
		virtual void add_object(scriptHandlerObject*, bool is_network, bool is_network_and_scriptcheck) = 0; // 10 (0x50)

		// Something related to reservations.
		virtual void _0x58(void*) = 0;                                                                        // 11 (0x58)

		virtual void register_resource(scriptResource*, void*) = 0;                                           // 12 (0x60)

		virtual void _0x68() = 0;                                                                             // 13 (0x68)

		virtual void _0x70() = 0;                                                                             // 14 (0x70)

		virtual void _0x78() = 0;                                                                             // 15 (0x78)

		virtual void _0x80() = 0;                                                                             // 16 (0x80)

		virtual void _0x88() = 0;                                                                             // 17 (0x88)

		virtual void _0x90() = 0;                                                                             // 18 (0x90)

		virtual void _0x98() = 0;                                                                             // 19 (0x98)
	public:
		void* m_0x08;                                // 0x08
		void* m_0x10;                                // 0x10
		scrThread* m_script_thread;                  // 0x18
		atDList<atDScriptObjectNode> m_objects;      // 0x20
		scriptResource* m_resource_list_head;        // 0x30
		scriptResource* m_resource_list_tail;        // 0x38
		void* m_0x40;                                // 0x40
		scriptHandlerNetComponent* m_net_component;  // 0x48
		std::uint32_t m_0x50;                        // 0x50
		std::uint32_t m_0x54;                        // 0x54
		std::uint32_t m_0x58;                        // 0x58
		std::uint32_t m_0x60;                        // 0x5C
	};

	class scriptHandlerMgr
	{
	public:
		virtual ~scriptHandlerMgr() = default;

		// Initializes some scripting-related pools.
		virtual bool initialize() = 0;                                                          // 1 (0x08)

		// Called every tick.
		virtual void _0x10() = 0;                                                               // 2 (0x10)

		// Frees some scripting-related pools.
		virtual void shutdown() = 0;                                                            // 3 (0x18)

		virtual void _0x20() = 0;                                                               // 4 (0x20)
		virtual void _0x28() = 0;                                                               // 5 (0x28)
		virtual void _0x30() = 0;                                                               // 6 (0x30)

		// Generates a rage::scriptId from the thread and copies it over to a global structure.
		virtual void _0x38(scrThread*) = 0;                                                     // 7 (0x38)

		// Allocates and constructs a script handler.
		virtual scriptHandler* create_script_handler() = 0;                                     // 8 (0x40)

		// Finds the script handler for a given script id.
		virtual scriptHandler* get_script_handler(scriptId*) = 0;                               // 9 (0x48)

		// Attaches a script thread.
		virtual void attach_thread(scrThread*) = 0;                                             // 10 (0x50)

		// Detaches a script thread.
		virtual void detach_thread(scrThread*) = 0;                                             // 11 (0x58)

		// Called when a player joins.
		virtual void on_player_join(netPlayer*) = 0;                                            // 12 (0x60)

		// Called when a player leaves.
		virtual void on_player_left(netPlayer*) = 0;                                            // 13 (0x68)

		virtual std::int32_t _0x70() = 0;                                                       // 14 (0x70)
		virtual void* _0x78() = 0;                                                              // 15 (0x78)
	public:
		char m_padding1[0x28];                         // 0x08
		bool m_initialized;                            // 0x30
		bool m_initialized2;                           // 0x31
		char m_padding2[0x0E];                         // 0x32
		rage::netLoggingInterface* m_logger;           // 0x40
	};
}

class CGameScriptHandler : public rage::scriptHandler
{
public:
	CGameScriptId m_script_id; // 0x60
};

class CGameScriptHandlerNetwork : public CGameScriptHandler
{
public:
	std::uint8_t m_0xA0;        // 0xA0
	std::uint8_t m_0xA1;        // 0xA1
	std::uint8_t m_0xA2;        // 0xA2
	std::uint8_t m_0xA3;        // 0xA3
	std::uint8_t m_num_players; // 0xA4
	std::uint8_t m_0xA5;        // 0xA5
	std::uint8_t m_0xA6;        // 0xA6
	std::uint8_t m_0xA7;        // 0xA7
	std::uint8_t m_0xA8;        // 0xA8
	std::uint8_t m_0xA9;        // 0xA9
	std::uint8_t m_0xAA;        // 0xAA
	std::uint8_t m_0xAB;        // 0xAB
	std::uint8_t m_0xAC;        // 0xAC
	std::uint8_t m_0xAD;        // 0xAD
	std::uint8_t m_0xAE;        // 0xAE
	std::uint8_t m_0xAF;        // 0xAF
};

class CGameScriptHandlerMgr : public rage::scriptHandlerMgr
{
};

static_assert(sizeof(rage::scriptHandler) == 0x60);
static_assert(sizeof(CGameScriptHandler) == 0xA0);
static_assert(sizeof(CGameScriptHandlerNetwork) == 0xB0);
#pragma pack(pop)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(push, 1)
namespace rage
{
	class scrProgram : public pgBase
	{
	public:
		std::uint8_t** m_code_blocks;  // 0x10
		std::uint32_t m_hash;          // 0x18
		std::uint32_t m_code_size;     // 0x1C
		std::uint32_t m_arg_count;     // 0x20
		std::uint32_t m_local_count;   // 0x24
		std::uint32_t m_global_count;  // 0x28
		std::uint32_t m_native_count;  // 0x2C
		void* m_local_data;            // 0x30
		std::int64_t** m_global_data;  // 0x38
		void** m_native_entrypoints;   // 0x40
		char m_padding6[0x10];         // 0x48
		std::uint32_t m_name_hash;     // 0x58
		char m_padding7[0x04];         // 0x5C
		const char* m_name;            // 0x60
		const char** m_strings_data;   // 0x68
		std::uint32_t m_strings_count; // 0x70
		char m_padding8[0x0C];         // 0x74

		bool is_valid() const
		{
			return m_code_size != 0;
		}

		std::uint32_t get_num_code_pages() const
		{
			return (m_code_size + 0x3FFF) >> 14;
		}

		std::uint32_t get_code_page_size(std::uint32_t page) const
		{
			auto num = get_num_code_pages();
			if (page < num)
			{
				if (page == num - 1)
					return m_code_size & 0x3FFF;
				return 0x4000;
			}

			return 0;
		}

		std::uint32_t get_full_code_size() const
		{
			auto numPages = get_num_code_pages();
			if (!numPages)
				return 0;
			if (numPages == 1)
				--numPages;

			return (numPages * 0x4000) + (m_code_size & 0x3FFF);
		}

		std::uint8_t* get_code_page(std::uint32_t page) const
		{
			return m_code_blocks[page];
		}

		std::uint8_t* get_code_address(std::uint32_t index) const
		{
			if (index < m_code_size)
				return &m_code_blocks[index >> 14][index & 0x3FFF];

			return nullptr;
		}

		const char* get_string(std::uint32_t index) const
		{
			if (index < m_strings_count)
				return &m_strings_data[index >> 14][index & 0x3FFF];

			return nullptr;
		}

		void** get_address_of_native_entrypoint(void* entrypoint)
		{
			for (std::uint32_t i = 0; i < m_native_count; ++i)
			{
				if (m_native_entrypoints[i] == entrypoint)
				{
					return m_native_entrypoints + i;
				}
			}

			return nullptr;
		}
	};

	class scrProgramTableEntry
	{
	public:
		scrProgram* m_program;     // 0x00
		char m_Pad1[0x04];         // 0x08
		joaat_t m_hash;            // 0x0C
	};

	class scrProgramTable
	{
	public:
		scrProgramTableEntry* m_data;    // 0x00
		char m_padding[0x10];            // 0x08
		std::uint32_t m_size;            // 0x18

		scrProgram* find_script(joaat_t hash)
		{
			for (std::uint32_t i = 0; i < m_size; ++i)
			{
				if (m_data[i].m_hash == hash)
				{
					return m_data[i].m_program;
				}
			}

			return nullptr;
		}

		scrProgramTableEntry* begin()
		{
			return m_data;
		}

		scrProgramTableEntry* end()
		{
			return m_data + m_size;
		}
	};

	static_assert(sizeof(scrProgram) == 0x80);
	static_assert(sizeof(scrProgramTableEntry) == 0x10);
	static_assert(sizeof(scrProgramTable) == 0x1C);
}
#pragma pack(pop)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////