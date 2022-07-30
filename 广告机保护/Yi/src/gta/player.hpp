#pragma once
#include <cstdint>
#include "fwddec.hpp"
#include "extensible.hpp"
#include "vector.hpp"
#include "gta\natives.hpp"

#pragma pack(push, 1)
namespace rage
{
#	pragma warning(push)
#	pragma warning(disable : 4201) // nonstandard extension used: nameless struct/union
	union netAddress
	{
		std::uint32_t m_raw;
		struct
		{
			std::uint8_t m_field4;
			std::uint8_t m_field3;
			std::uint8_t m_field2;
			std::uint8_t m_field1;
		};
	};
#	pragma warning(pop)

	class netPlayerData
	{
	public:
		char pad_0000[8]; //0x0000
		uint64_t m_rockstar_id_0; //0x0008
		char pad_0010[56]; //0x0010
		uint16_t N000005BF; //0x0048
		char pad_004A[2]; //0x004A
		netAddress m_relay_ip; //0x004C
		uint32_t m_relay_port; //0x0050
		netAddress m_online_ip; //0x0054
		uint16_t m_online_port; //0x0058
		char pad_005A[6]; //0x005A
		uint32_t m_host_token; //0x0060
		char pad_0064[12]; //0x0064
		uint64_t m_rockstar_id; //0x0070
		char pad_0078[12]; //0x0078
		char m_name[20]; //0x0084
		CPed* pCPed;//0x01E8
	}; //Size: 0x0098

	class nonPhysicalPlayerDataBase
	{
	public:
		virtual ~nonPhysicalPlayerDataBase() = default;    // 0 (0x00)
		virtual void unk_0x08() = 0;                       // 1 (0x08)
		virtual void unk_0x10() = 0;                       // 2 (0x10)
		virtual void unk_0x18() = 0;                       // 3 (0x18)
		virtual void log(netLoggingInterface* logger) = 0; // 4 (0x20)
	};

	class netPlayer
	{
	public:
		virtual ~netPlayer() = default;            // 0 (0x00)
		virtual void reset() = 0;                  // 1 (0x08)
		virtual bool is_valid() const = 0;         // 2 (0x10)
		virtual const char *get_name() const = 0;  // 3 (0x18)
		virtual void _0x20() = 0;                  // 4 (0x20)
		virtual bool is_host() = 0;                // 5 (0x28)
		virtual netPlayerData *get_net_data() = 0; // 6 (0x30)
		virtual void _0x38() = 0;                  // 7 (0x38)
	};

	class netPlayerMgrBase
	{
	public:
		virtual ~netPlayerMgrBase() = default; // 0 (0x00)
	};
}

namespace gta
{
	inline constexpr auto num_players = 32;
}

class CNonPhysicalPlayerData : public rage::nonPhysicalPlayerDataBase
{
public:
	std::int32_t  m_bubble_id; // 0x08
	std::int32_t  m_player_id; // 0x0C
	rage::vector3 m_position;  // 0x10
};

class CNetGamePlayer : public rage::netPlayer
{
public:
	char pad_0008[25]; //0x0008
	int8_t player_id; //0x0021
	char pad_0022[126]; //0x0022
	CPlayerInfo* player_info; //0x00B0
	char pad_00A8[20]; //0x00A8
	uint32_t bubble_id; //0x00BC
	uint32_t player; //0x00C0
}; //Size: 0x00C4
static_assert(sizeof(CNetGamePlayer) == 0xC4);

class CPlayerInfo
	//: public rage::fwExtensibleBase
{
public:
	char pad_0000[32]; //0x0000
	uint32_t m_internal_ip; //0x0020
	uint16_t m_internal_port; //0x0024
	char pad_0026[2]; //0x0026
	uint32_t m_relay_ip; //0x0028
	uint16_t m_relay_port; //0x002C
	char pad_002E[66]; //0x002E
	uint32_t N00000124; //0x0070
	uint32_t m_external_ip; //0x0074
	uint16_t m_external_port; //0x0078
	char pad_007A[22]; //0x007A
	uint64_t m_rockstar_id; //0x0090
	char pad_0098[12]; //0x0098
	char m_name[20]; //0x00A4
	char pad_00B8[184]; //0x00B8
	float m_swim_speed; //0x0170
	char pad_0174[164]; //0x0174
	uint32_t m_frame_flags; //0x0218
	char pad_021D[1644]; //0x021C
	int32_t m_wanted_level; //0x0888
	int32_t m_wanted_level_2; //0x088C
	char pad_0890[1120]; //0x0890
	float m_run_speed; //0x0CF0
	float m_stamina; //0x0CF4
	float m_stamina_regen; //0x0CF8
}; //Size: 0x0CFC
//static_assert(sizeof(CPlayerInfo) == 0x869);

static_assert(sizeof(CNonPhysicalPlayerData) == 0x1C);
#pragma pack(pop)
