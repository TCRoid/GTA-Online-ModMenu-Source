#pragma once
#include "fwddec.hpp"

#pragma pack(push, 1)
class CPed
{
public:
	char pad_0000[393]; //0x0000
	uint8_t godmode; //0x0189
	char pad_018A[246]; //0x018A
	float health; //0x0280
	char pad_0284[28]; //0x0284
	float maxhealth; //0x02A0
	char pad_02A4[2700]; //0x02A4
	class CVehicle* vehicle; //0x0D30
	char pad_0D38[912]; //0x0D38
	class CPlayerInfo* m_playerinfo; //0x10C8
	char pad_10D0[828]; //0x10D0
	uint8_t seatbelt; //0x140C
	char pad_140D[211]; //0x140D
	float armor; //0x14E0
	char pad_14E4[124]; //0x14E4
}; //Size: 0x1560
#pragma pack(pop)

class CPedFactory
{
public:
	virtual ~CPedFactory() = default;
	CPed *m_local_ped;
};
