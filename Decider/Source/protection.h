#pragma once
class feat
{
public:
	bool m_bRestored = true;
	feat();
	virtual			~feat();
};

void AntiCeoKick(bool t);
void AntiSPKick(bool t);
void AntiApartmentTP(bool t);
void AntiRemoteBounty(bool t);
void antiRemoteVehicleKick(bool t);
void antiRemoteForceMission(bool t);
void AntiReport(bool t);
void AntiKick(bool t);
void AntiFreeze(bool t);
void AntiAttachment(bool toggle);
void AntiExplosion(bool t);
void AntiSound(bool t);
void AntiStars(bool t);
void AntiStat(bool t);
void AntiGiveWeapon(bool t);
void AntiRemoveWeapon(bool t);
void AntiFire(bool t);
void AntiDrop(bool t);
void AntiPTFX(bool t);
void AntiInvite(bool t);
void BlockAllNetEvents(bool t);
void AntiVoteKick(bool t);
void AntiRequestControl(bool t);
void AntiCage(bool toggle);
void AntiCargonplane(bool toggle);
void BlockAllEntity(bool toggle);
void BlockObjectCrash(bool toggle);
void BlockPedCrash(bool toggle);
void BlockVehicleCrash(bool toggle);