#pragma once
namespace rage
{
#pragma pack(push, 1)
	struct RGBAF
	{
		int r, g, b, a, f;
	};
#pragma pack(pop)

#pragma pack(push, 1)
	struct RGBA
	{
		int r, g, b, a;
	};
#pragma pack(pop)
#pragma pack(push, 1)
	struct RGBAD
	{
		int R, G, B, A;
	};
#pragma pack(pop)
#pragma pack(push, 1)
	struct RGB
	{
		int r, g, b;
	};
#pragma pack(pop)
}