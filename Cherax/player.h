#pragma once
#include <cstdint>
#include "fwddec.h"
#include "base.h"
#include "vector.h"


namespace rage
{
	template <typename T>
	class fwRefAwareBaseImpl : public T
	{
	private:
		void* m_ref; // 0x08
	};

	class fwRefAwareBase : public fwRefAwareBaseImpl<datBase>
	{
	};

	static_assert(sizeof(fwRefAwareBase) == 0x10);
}

//////////////////////////////////////////////////

namespace rage
{
	class fwExtension
	{
	public:
		virtual ~fwExtension() = default;
		virtual void unk_0x08() = 0;
		virtual void unk_0x10() = 0;
		virtual std::uint32_t get_id() = 0;
	};

	class fwExtensionContainer
	{
	public:
		fwExtension* m_entry;
		fwExtensionContainer* m_next;
	};

	class fwExtensibleBase : public fwRefAwareBase
	{
	public:
		virtual bool is_of_type(std::uint32_t hash) = 0;
		virtual std::uint32_t const& get_type() = 0;
	public:
		fwExtensionContainer* m_extension_container; // 0x10
	private:
		void* m_extensible_unk;                      // 0x18
	public:
		template <typename T>
		bool is_of_type()
		{
			static auto name = (typeid(T).name()) + 6; // Skip "class "
			static auto name_hash = util::joaat(name);

			return is_of_type(name_hash);
		}
	};

	static_assert(sizeof(fwExtensibleBase) == 0x20);
}

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
		std::uint64_t m_unk1;         // 0x00
		std::uint64_t m_unk2;         // 0x08
		std::uint32_t m_sec_key_time; // 0x10
		netAddress    m_lan_ip;       // 0x14
		std::uint16_t m_lan_port;     // 0x18
		char          m_pad1[0x02];   // 0x1A
		netAddress    m_relay_ip;     // 0x1C
		std::uint16_t m_relay_port;   // 0x20
		char          m_pad2[0x02];   // 0x22
		netAddress    m_online_ip;    // 0x24
		std::uint16_t m_online_port;  // 0x26
		char          m_pad3[0x1E];   // 0x28
		std::uint64_t m_rockstar_id;  // 0x48
		bool          m_id_flag;      // 0x50
		char          m_pad4[0x0B];   // 0x51
		char          m_name[0x14];   // 0x5C
		char pad_0x0090[0x4]; //
		int32_t iTeam; // 
		char pad_0x0098[0xB0]; //
		float fSwimSpeed; // 
		float fRunSpeed; // 
		char pad_0x0150[0x68]; //
		uint32_t ulState; // 
		char pad_0x01BC[0xC]; //
		CPed* pCPed; // 0x01C8
		char pad_0x01D0[0x28]; //0x01D0
		int64_t m_frameflags; //0x01F8
		char pad_0200[1552]; //0x0200
		bool m_is_wanted; //0x0810
		char pad_0811[51]; //0x0811
		int32_t m_fake_wanted_level; //0x0844
		int32_t m_wanted_level; //0x0848
		char pad_084C[0x464]; //0x084C
		float fStamina; //0xCB0
		float fMaxStamina; // 0xCB4

	};
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
		virtual const char* get_name() const = 0;  // 3 (0x18)
		virtual void _0x20() = 0;                  // 4 (0x20)
		virtual bool is_host() = 0;                // 5 (0x28)
		virtual netPlayerData* get_net_data() = 0; // 6 (0x30)
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

};

class CWantedData
{
public:
	char m_padding[0x98];
	std::int32_t m_wanted_level;
};

class CPlayerInfo : public rage::fwExtensibleBase
{
public:
	std::uint64_t m_unk1;         // 0x00 + 0x20
	std::uint64_t m_unk2;         // 0x08 + 0x20
	std::uint32_t m_sec_key_time; // 0x10 + 0x20
	rage::netAddress    m_lan_ip;       // 0x14 + 0x20
	std::uint16_t m_lan_port;     // 0x18 + 0x20
	char          m_pad1[0x02];   // 0x1A + 0x20
	rage::netAddress    m_relay_ip;     // 0x1C + 0x20
	std::uint16_t m_relay_port;   // 0x20 + 0x20
	char          m_pad2[0x02];   // 0x22 + 0x20
	rage::netAddress    m_online_ip;    // 0x24 + 0x20 
	std::uint16_t m_online_port;  // 0x26 + 0x20
	char          m_pad3[0x1E];   // 0x28 + 0x20
	std::uint64_t m_rockstar_id;  // 0x48 + 0x20
	bool          m_id_flag;      // 0x50 + 0x20
	char          m_pad4[0x0B];   // 0x51 + 0x20
	char          m_name[0x14];   // 0x5C + 0x20
	char pad_0x0090[0x4]; // 0x007C
	int32_t iTeam; // 0x0084
	char pad_0x0098[0xB0]; //0x008C
	float fSwimSpeed; // 0x0094
	float fRunSpeed; // 0x0098
	char pad_0x0150[0x68]; //0x0148
	uint32_t ulState; // 0x014C
	char pad_0x01BC[0xC]; //0x0150
	CPed* pCPed; // 0x01C8
	char pad_0x01D0[0x28]; //0x01D0
	int64_t m_frameflags; //0x01F8
	char pad_0200[1552]; //0x0200
	bool m_is_wanted; //0x0810
	char pad_0811[51]; //0x0811
	int32_t m_fake_wanted_level; //0x0844
	int32_t m_wanted_level; //0x0848
	char pad_084C[0x464]; //0x084C
	float fStamina; //0xCB0
	float fMaxStamina; // 0xCB4
	char pad_0xCB8[0x10]; //0xCB8
	float fWeaponDamgeMP; //0xCC8
	char pad_0xCCC[0x8]; //0xCCC
	float fMeleeDamageMP; //0xCD4
	float fMeleeKnockbackMP; //0xCD8

};

static_assert(sizeof(CNonPhysicalPlayerData) == 0x1C);
#pragma pack(pop)

class CWeapon
{
public:
	char pad_0x0000[0x10]; //0x0000	
	int32_t nameHash; //0x0010	
	int32_t modelHash; ////0x0014
	char pad_0x0018[0x58]; //0x0018	
	float fSpread; //0x070
	float fWeaponSpread; //0x074
	char pad_0x078[0x38]; //0x078	
	float fBulletDamage; //0x00B0
	char pad_0x00B4[0x20]; //0x00B4
	float fForceOnPed; //0x00D4
	float fForceOnVehicle; //0x00D8
	float fForceOnHeli; //0x00DC
	char pad_0x00C0[0x4C]; //0x00C0
	float fReloadSpeed; //0x012C
	char pad_0x0130[0x15C]; //0x0130
	float fWeaponRange; //0x28C
	char pad_0x290[0x48]; //0x290
	float fRecoil;	//0x2D8
	char pad_0x2DC[0xC]; //0x2DC		
	float fWeaponRecoil;	//0x2E8
};

class CWeaponManager
{
public:
	char pad_0x0000[0x20]; //0x0000		
	CWeapon* currentWeapon;	 //0x20
};

#pragma pack(push, 1)
class CPed
{
public:
	char pad_0x0000[0x28]; //0x0000
	BYTE btEntityType; //0x0028 
	char pad_0x0029[0x3]; //0x0029
	BYTE btInvisible; //0x002C 
	char pad_0x002D[0x1]; //0x002D
	BYTE btFreezeMomentum; //0x002E 
	char pad_0x002F[0x1]; //0x002F
	CNavigation* pCNavigation; //0x0030 
	char pad_0x0038[0x10]; //0x0038
	CPedStyle* pCPedStyle; //0x0048
	char pad_0x0050[0x40]; //0x0050
	rage::vector3 v3VisualPos; //0x0090 
	char pad_0x009C[0xED]; //0x009C
	BYTE btGodMode; //0x0189 
	char pad_0x018A[0xF6]; //0x018A
	float fHealth; //0x0280 
	char pad_0x0284[0x1C]; //0x0284
	float fHealthMax; //0x02A0 
	char pad_0x02A4[0x4]; //0x02A4
	CAttacker* pCAttacker; //0x02A8 
	char pad_0x02B0[0x70]; //0x02B0
	rage::vector3 v3Velocity; //0x0320 
	char pad_0x032C[0x9FC]; //0x032C
	CVehicle* pCVehicleLast; //0x0D28 
	char pad_0x0D30[0x378]; //0x0D30
	BYTE btNoRagdoll; //0x10A8 
	char pad_0x10A9[0xF]; //0x10A9
	CPlayerInfo* pCPlayerInfo; //0x10B8 
	char pad_0x10C0[0x8]; //0x10C0
	CWeaponManager* pCWeaponManager; //0x10C8 
	char pad_0x10D0[0x31C]; //0x10D0
	BYTE btSeatBelt; //0x13EC 
	char pad_0x13ED[0xB]; //0x13ED
	BYTE btSeatbeltWindshield; //0x13F8 
	char pad_0x13F9[0x1]; //0x13F9
	BYTE btCanSwitchWeapons;
	char pad_0x13FB[0x5];
	BYTE btForcedAim; //0x1400 
	BYTE N00000936; //0x1401 
	BYTE N00000939; //0x1402 
	BYTE N00000937; //0x1403 
	char pad_0x1404[0x67]; //0x1404
	BYTE btIsInVehicle; //0x146B 
	char pad_0x146C[0x4C]; //0x146C
	float fArmor; //0x14B0 + 8 -> 14b8
	char pad_0x14B4[0x20]; //0x14B4 + 8
	float fFatiguedHealthThreshold; //0x14D4 + 8
	float fInjuredHealthThreshold; //0x14D8  + 8
	float fDyingHealthThreshold; //0x14DC + 8 
	float fHurtHealthThreshold; //0x14E0 + 8
	char pad_0x14E4[0xC]; //0x14E4+ 8
	CVehicle* pCVehicleLast2; //0x14F0 + 8
	char pad_0x14F8[0xDC]; //0x14F8 + 8
	__int32 iCash; //0x15D4  + 8
};
#pragma pack(pop)

class CPedFactory
{
public:
	virtual ~CPedFactory() = default;
	CPed* m_local_ped;
};

class CBlip
{
public:
	__int32 iID; //0x0000 
	__int8 iID2; //0x0004 
	char _0x0005[3];
	BYTE N000010FB; //0x0008 (80 = moves with player, some values will turn icon into map cursor and break it)
	char _0x0009[7];
	float x;
	float y;
	float z;
	char _0x001C[6];
	BYTE bFocused; //0x0022   (Focused? 0100 0000)
	char _0x0023[5];
	char* szMessage; //0x0028 If not null, contains the string of whatever the blip says when selected.
	char _0x0030[16];
	int iIcon; //0x0040
	char _0x0044[4];
	DWORD dwColor; //0x0048 (Sometimes works?)
	char _0x004C[4];
	float fScale; //0x0050 
	__int16 iRotation; //0x0054 Heading
	BYTE bInfoIDType; //0x0056 GET_BLIP_INFO_ID_TYPE
	BYTE bZIndex; //0x0057 
	BYTE bDisplay; //0x0058  Also Visibility 0010
	BYTE bAlpha; //0x0059
};//Size=0x005A

class CBlipList
{
public:
	CBlip* m_Blips[1500]; //0x0000
	char _0x2EE0[56];

};//Size=0x2F18


class CVehicle
{
public:
	CPed* pVTable; //0x0000 // not sure i cped or cpedvtable something like this idk
	char pad_0x0008[0x18]; //0x0008
	CVehicleModelInfo* pCModelInfo; //0x0020 
	char pad_0x0028[0x8]; //0x0028
	CNavigation* pCNavigation; //0x0030 
	char pad_0x0038[0x10]; //0x0038
	CVehicleMods* pCVehicleMods; //0x0048 
	char pad_0x0050[0x40]; //0x0050
	rage::vector3 v3VisualPos; //0x0090 
	char pad_0x009C[0x3C]; //0x009C
	BYTE btState; //0x00D8 
	char pad_0x00D9[0xB0]; //0x00D9
	BYTE btGodMode; //0x0189 
	char pad_0x018A[0xF6]; //0x018A
	float fHealth; //0x0280 
	char pad_0x0284[0x1C]; //0x0284
	float fHealthMax; //0x02A0 
	char pad_0x02A4[0x4]; //0x02A4
	CAttacker* pCAttacker; //0x02A8 
	char pad_0x02B0[0x72]; //0x02B0
	BYTE btVolticRocketState; //0x0322 
	char pad_0x0323[0x1]; //0x0323
	float fVolticRocketEnergy; //0x0324 
	char pad_0x0328[0x448]; //0x0328
	rage::vector3 v3Velocity; //0x0770 
	char pad_0x077C[0x100]; //0x077C
	float fHealth2; //0x087C 
	char pad_0x0880[0x28]; //0x0880
	CVehicleHandling* pCVehicleHandling; //0x08A8 
	char pad_0x08B0[0x3]; //0x08B0
	BYTE btBulletproofTires; //0x08B3 
	char pad_0x08B4[0x4]; //0x08B4
	BYTE btStolen; //0x08B8 
	char pad_0x08B9[0x11]; //0x08B9
	BYTE N00000954; //0x08CA 
	char pad_0x08CB[0x41]; //0x08CB
	float N0000081E; //0x090C 
	char pad_0x0910[0x58]; //0x0910
	float fDirtLevel; //0x0968 
	char pad_0x096C[0xA8]; //0x096C
	uint32_t dwCarAlarmLength; //0x0A14 
	char pad_0x0A18[0x148]; //0x0A18
	BYTE btOpenableDoors; //0x0B60 
	char pad_0x0B61[0x4B]; //0x0B61
	float fGravity; //0x0BAC 
	BYTE btMaxPassengers; //0x0BB0 
	char pad_0x0BB1[0x1]; //0x0BB1
	BYTE btNumOfPassengers; //0x0BB2 
	char pad_0x0BB3[0x5]; //0x0BB3
	CPed* pPassenger[16]; //0x0BB8 
};


class CPickupHandle
{
public:
	CPickup* pCPickup; //0x0000 
	__int32 iHandle; //0x0008 
	char pad_0x000C[0x4]; //0x000C

}; //Size=0x0010

class CPickupList
{
public:
	CPickupHandle pickups[73]; //0x0000 

}; //Size=0x0490

class CPickup
{
public:
	char pad_0x0000[0x30]; //0x0000
	CNavigation* pCNavigation; //0x0030 
	char pad_0x0038[0x58]; //0x0038
	rage::vector3 v3VisualPos; //0x0090 
	char pad_0x009C[0x3F4]; //0x009C
	__int32 iValue; //0x0490 
	char pad_0x0494[0xC4]; //0x0494

}; //Size=0x0558

class CPedHandle
{
public:
	CPed* pCPed; //0x0000 
	__int32 iHandle;
	char _pad0[0x4];

}; //Size=0x0010

class CPedList
{
public:
	CPedHandle peds[256]; //0x0000 

}; //Size=0x1000

class CVehHandle
{
public:
	CVehicle* pCVehicle; //0x0000 
	__int32 iHandle;
	char _pad0[0x4];

}; //Size=0x0010

class CVehList
{
public:
	CVehHandle vehs[300]; //0x0000 

}; //Size=0x1000

class CObjectHandle
{
public:
	CObject* pCObject; //0x0000 
	__int32 iHandle; //0x0008 
	char pad_0x000C[0x4]; //0x000C

}; //Size=0x0010

class CObjectList
{
public:
	CObjectHandle ObjectList[2300]; //0x0000 

}; //Size=0x8FC0

class CObject
{
public:
	char pad_0x0000[0x8]; //0x0000

}; //Size=0x0008


class CCameraInterface
{
public:
	char pad_0x0000[0x248]; //0x0000

}; //Size=0x0248

class CObjectInterface
{
public:
	char pad_0x0000[0x158]; //0x0000
	CObjectList* pCObjectList; //0x0158 
	__int32 iMaxObjects; //0x0160 
	char pad_0x0164[0x4]; //0x0164
	__int32 iCurObjects; //0x0168 
	char pad_0x016C[0x5C]; //0x016C

	CObject* get_object(const int& index)
	{
		if (index < iMaxObjects)
			return pCObjectList->ObjectList[index].pCObject;
		return nullptr;
	}
}; //Size=0x01C8

class CVehicleInterface
{
public:
	char pad_0x0000[0x180]; //0x0000
	CVehList* VehList; //0x0180 
	__int32 iMaxVehicles; //0x0188 
	char pad_0x018C[0x4]; //0x018C
	__int32 iCurVehicles; //0x0190 
	char pad_0x0194[0x74]; //0x0194

	CVehicle* get_vehicle(const int& index)
	{
		if (index < iMaxVehicles)
			return VehList->vehs[index].pCVehicle;
		return nullptr;
	}
}; //Size=0x0208

class CPedInterface
{
public:
	char pad_0x0000[0x100]; //0x0000
	CPedList* PedLIst; //0x0100 
	__int32 iMaxPeds; //0x0108 
	char pad_0x010C[0x4]; //0x010C
	__int32 iCurPeds; //0x0110 
	char pad_0x0114[0x34]; //0x0114

	CPed* get_ped(const int& index)
	{
		if (index < iMaxPeds)
			return PedLIst->peds[index].pCPed;
		return nullptr;
	}
}; //Size=0x0148

class CPickupInterface
{
public:
	char pad_0x0000[0x100]; //0x0000
	CPickupList* pCPickupList; //0x0100 
	__int32 iMaxPickups; //0x0108 
	char pad_0x010C[0x4]; //0x010C
	__int32 iCurPickups; //0x0110 

	CPickup* get_pickup(const int& index)
	{
		if (index < iMaxPickups)
			return pCPickupList->pickups[index].pCPickup;
		return nullptr;
	}
}; //Size=0x0114

class CReplayInterface
{
public:
	void* N000006F5; //0x0000 
	CCameraInterface* pCCameraInterface; //0x0008 
	CVehicleInterface* pCVehicleInterface; //0x0010 
	CPedInterface* pCPedInterface; //0x0018 
	CPickupInterface* pCPickupInterface; //0x0020 
	CObjectInterface* pCObjectInterface; //0x0028 

}; //Size=0x0030