#pragma once

void TeleportToClient(int Client);

extern int RP_Value;
void Set_RP(int RP_Value);

extern DWORD model;
void CREATE_OBJECT_WITH_ROTATION(DWORD model, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float rotW, bool dynamic, bool visible);
void ExplosionPlayer(Ped targetPlayer, int damage, int type, int cam, bool Invisible, bool Audio);
void request_control_id(int network_id);
