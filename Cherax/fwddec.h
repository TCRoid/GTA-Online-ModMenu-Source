#pragma once

namespace memory
{
	class handle;
	class range;
	class module;
	class pattern;
	class pattern_batch;
}

namespace rage
{
	template <typename T>
	class atArray;

	class datBitBuffer;
	class sysMemAllocator;

	class scriptIdBase;
	class scriptId;
	class scriptHandler;
	class scriptHandlerNetComponent;
	class scriptHandlerObject;
	class scriptHandlerMgr;

	class scrProgram;
	class scrProgramTable;

	class scrThreadContext;
	class scrThread;
	class tlsContext;

	class netLoggingInterface;
	class netLogStub;

	class netPlayer;
	class netPlayerMgr;
	class netPlayerData;

	class netGameEvent;
	class netEventMgr;

	class netObject;
	class netObjectMgrBase;

	class scrNativeCallContext;
	class scrNativeRegistration;
	class scrNativeRegistrationTable;

	class fwRefAwareBase;
	class fwExtensibleBase;
	class fwEntity;
	class fwArchetype;
}

class GtaThread;

class CGameScriptId;
class CGameScriptHandler;
class CGameScriptHandlerNetwork;
class CGameScriptHandlerMgr;

class CEntity;
class CDynamicEntity;
class CPhysical;

class CWantedData;
class CPed;
class CVehicle;
class CVehicleModelInfo;
class CVehicleMods;
class CVehicleHandling;
class CObject;
class CPickup;

class CWeaponManager;
class CAttacker;
class CPedStyle;
class CNavigation;

class CPedFactory;
class CVehicleFactory;

class CNetGamePlayer;
class CNetworkPlayerMgr;
class CPlayerInfo;

class CBlipList;
class CBlip;
