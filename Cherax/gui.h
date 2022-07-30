#pragma once
#include "common.h"
#include "function_types.h"
#include "features.h"

#include "ImGui/imgui.h"
#include "ImGui/imgui_internal.h"
#include "ImGui/examples/imgui_impl_win32.h"
#include "ImGui/examples/imgui_impl_dx11.h"

struct RGBA
{
	int R, G, B, A;
};

class GUI
{
public:
	void init();
	void initStyle();
	void initFonts();
	void initTextures();
	void on_frame();

	void mainMenu();
	void backgroundOverlay();

	void Self();
	void PlayerList();
	void Weapon();
	void Visuals();
	void Spawner();
	void VehicleMenu();
	void World();
	void Teleport();
	void Misc();
	void Protections();
	void Settings();

	void script_init();
	static void script_func();
	void run_tick();

public:
	ImVec2 mainWindowPos;
	ImVec2 mainWindowSize;
	bool autoResize{ false };
	std::string menus[14] = {"Self", "Online", "Playerlist", "Weapon", "Visual", "Spawner", "Vehicle", "World", "Teleport", "Recovery", "Misc", "Protections", "Hotkeys", "Settings"};
	std::string watermark = "Cherax Premium v3.0";
	bool initDone{ false };
	bool m_opened{ false };
	int selectedTab = 0;

	ImFont* tabFont{};
	ImFont* textFont{};
	ImFont* childHeaderFont{};

	ImVec4 enemyColor = ImGui::ColorConvertU32ToFloat4(ImColor(255, 0, 0, 255));
	ImVec4 teamColor = ImGui::ColorConvertU32ToFloat4(ImColor(0, 0, 255, 255));
	ImVec4 friendColor = ImGui::ColorConvertU32ToFloat4(ImColor(0, 255, 0, 255));
	ImVec4 NpcColor = ImGui::ColorConvertU32ToFloat4(ImColor(0, 255, 162, 255));
	ImVec4 CopColor = ImGui::ColorConvertU32ToFloat4(ImColor(0, 107, 255, 255));
	ImVec4 yourColor = ImGui::ColorConvertU32ToFloat4(ImColor(89, 66, 250, 204));
	ImVec4 crosshairColor = ImGui::ColorConvertU32ToFloat4(ImColor(255, 80, 0, 255));

	ImU32 u32_enemyColor{};
	ImU32 u32_teamColor{};
	ImU32 u32_friendColor{};
	ImU32 u32_NpcColor{};
	ImU32 u32_CopColor{};
	ImU32 u32_yourColor{};
	ImU32 u32_crosshairColor{};

	bool enableScreenFilter{};
	ImVec4 screenFilter = ImGui::ColorConvertU32ToFloat4(ImColor(158, 124, 19, 37));

	ImVec2 resizeVec(ImVec2 xy);
	float resizefloat(float val);
	bool radioButton(const char* label, bool* v);
	ImVec2 WorldToScreen(Vector3 pos);
	BOOL Draw2DBox(tPlayerData data, ImVec2 head, ImVec2 feet);
	BOOL DrawLine(tPlayerData data, ImVec2 a, ImVec2 b);
	BOOL drawHealthBar(tPlayerData data, ImVec2 head, ImVec2 feet);
	BOOL drawAmourBar(tPlayerData data, ImVec2 head, ImVec2 feet);
	BOOL DrawDistanceAndName(tPlayerData data, ImVec2 a, ImVec2 b);

	bool ToggleButton(const char* str_id, bool* v);

	int* hsi_to_rgb(float H, float S, float I);
	RGBA DWORD2RGBA(unsigned long dwColor);

public:
	bool resourceInitDone{ false };
	std::string iconList[20]{"host", "ip", "port", "alive", "health", "armour", "wantedlevel","invehicle", "interior", "speed", "distance", "coords", "rp", "rockstar", "wallet", "bank", "totalmoney", "kdratio", "kills", "deaths"};
	std::map<std::string, ID3D11ShaderResourceView*> Icons;
	std::vector<ID3D11ShaderResourceView*> idleHeader;
	std::vector<ID3D11ShaderResourceView*> openingHeader;

	bool xmlSpawnerTabActive{};

	static struct tPTFX {
		std::string DisplayName;
		std::string PTFXCall;
		std::string PTFXName;
	};

	tPTFX ePTFX[64] = {
			{ std::string("None"), std::string("None"),  std::string("None") },
			{ "Starburst FW", "scr_indep_fireworks", "scr_indep_firework_starburst" },
			{ "Fountain FW", "scr_indep_fireworks", "scr_indep_firework_fountain" },
			{ "Shotburst FW", "scr_indep_fireworks", "scr_indep_firework_shotburst" },
			{ "Trailburst FW", "scr_indep_fireworks", "scr_indep_firework_trailburst" },
			{ "NYE FW", "proj_xmas_firework", "scr_firework_xmas_burst_rgw" },
			{ "Spiral FW", "proj_xmas_firework", "scr_firework_xmas_spiral_burst_rgw" },
			{ "Ring FW", "proj_xmas_firework", "scr_firework_xmas_ring_burst_rgw" },
			//{ "Flare Fuse", "core", "proj_flare_fuse" }, // Requires LOOPED_PTFX
			//{ "Flare", "scr_fbi5a", "scr_fbi5a_flare" },
			{ "Magical Flowers", "scr_rcbarry2", "scr_exp_clown" },
			//{ "Magical Stars", "scr_rcbarry2", "scr_clown_bull" },
			{ "Magical Smoke", "scr_rcbarry2", "scr_clown_appears" },
			{ "Magical Smoke 2", "scr_rcbarry2", "scr_clown_death" },
			{ "MoneySwap Smoke", "scr_tplaces", "scr_tplaces_team_swap" },
			{ "Firey Particles", "scr_rcbarry1", "scr_alien_teleport" },
			{ "Disintegration", "scr_rcbarry1", "scr_alien_disintegrate" },
			//{ "Charges", "scr_rcbarry1", "scr_alien_charging" },
			//{ "Beam", "scr_rcbarry1", "scr_alien_beam" },
			//{ "Impact", "scr_rcbarry1", "scr_alien_impact" },
			//{ "Door Heavy Stat", "scr_agencyheista", "scr_agency3a_door_hvy_stat" },
			//{ "Door Heavy Trigger", "scr_agencyheista", "scr_agency3a_door_hvy_trig" },
			//{ "Dry Ice", "scr_fbi5a", "scr_fbi5_dry_ice" },
			//{ "Blaze", "scr_agencyheist", "scr_fbi_ext_blaze" },
			{ "Mop Drips", "scr_agencyheist", "scr_fbi_mop_drips" },
			{ "Mop Squeeze", "scr_agencyheist", "scr_fbi_mop_squeeze" },
			//{ "Large Water Splash", "scr_exile3", "scr_ex3_water_dinghy_wash" },
			{ "Water Splash", "scr_fbi5a", "scr_fbi5_ped_water_splash" },
			//{ "Water Bubbles", "scr_fbi5a", "water_splash_ped_bubbles" },
			//{ "Puke", "scr_family5", "scr_trev_puke" },
			{ "Puke", "scr_familyscenem", "scr_trev_puke" },
			{ "Puke Ambient", "scr_familyscenem", "scr_trev_amb_puke" },
			//{ "Blood", "scr_finalec2", "scr_finale2_blood_entry" },
			//{ "Autopsy Blood", "scr_agencyheist", "scr_fbi_autopsy_blood" },
			{ "Blood Stab", "scr_michael2", "scr_mich2_blood_stab" },
			{ "Blood Impact", "scr_solomon3", "scr_trev4_747_blood_impact" },
			{ "Blood Spasm", "scr_michael2", "scr_abattoir_ped_sliced" },
			{ "Tyre Spiked", "scr_bigscore", "scr_bigscore_tyre_spiked" },
			{ "Tyre Smoke", "scr_mp_creator", "scr_mp_plane_landing_tyre_smoke" },
			//{ "Landing Tyre Smoke", "scr_fm_intro_cut_dev", "scr_mp_plane_landing_tyre_smoke" },
			{ "Gold Ball Trail", "scr_minigamegolf", "scr_golf_ball_trail" },
			{ "Sniper Impact", "scr_martin1", "scr_sol1_sniper_impact" },
			{ "Dirt Throw", "core_snow", "cs_mich1_spade_dirt_throw" },
			{ "Camera", "scr_rcpaparazzo1", "scr_rcpap1_camera" },
			//{ "Fire Ring", "scr_ie_export", "scr_ie_export_fire_ring" },
			{ "Meth Pipe Smoke", "scr_familyscenem", "scr_meth_pipe_smoke" },
			{ "Pipefall Debris", "scr_reconstructionaccident", "scr_reconstruct_pipefall_debris" },
			{ "Pipe Impact", "scr_reconstructionaccident", "scr_reconstruct_pipe_impact" },
			//{ "Sparking Generator", "scr_reconstructionaccident", "scr_sparking_generator" },
			{ "Burial Dirt", "scr_reburials", "scr_burial_dirt" },
			{ "Wheel Burnout", "scr_recartheft", "scr_wheel_burnout" },
			//{ "Rescue Fire", "scr_recrash_rescue", "scr_recrash_rescue_fire" },
			{ "Bank Notes", "scr_paletoscore", "scr_paleto_banknotes" },
			//{ "Blow Torch", "scr_paletoscore", "cs_paleto_blowtorch" },
			//{ "Trailer Splash", "scr_tevor1", "scr_trev1_trailer_splash" },
			//{ "Trailer Wires", "scr_tevor1", "scr_trev1_trailer_wires" },
			//{ "Crash Dust", "scr_tevor1", "scr_trev1_crash_dust" },
			//{ "Wheelspin Dirt", "scr_tevor1", "scr_trev1_wheelspin_dirt" },
			//{ "Train Sparks", "scr_oddjobtowtruck", "scr_ojtt_train_sparks" },
			//{ "Hotbox Trail", "scr_oddjobtaxi", "scr_ojtaxi_hotbox_trail" },
			{ "Engine Debris", "scr_solomon3", "scr_trev4_747_engine_debris" },
			{ "Car Impact", "scr_exile2", "scr_ex2_car_impact" },
			{ "Helicopter Explosion", "scr_agencyheistb", "scr_agency3b_heli_expl" },
			{ "Explosion Light", "scr_josh3", "scr_josh3_light_explosion" },
			{ "Building Story Explosion", "scr_agencyheist", "scr_fbi_exp_building" },
			{ "Drug Plane Explosion", "scr_oddjobtraffickingair", "scr_drug_grd_plane_exp" },
			{ "Drug Train Explosion", "scr_oddjobtraffickingair", "scr_drug_grd_train_exp" },
			{ "Water Explosion", "scr_oddjobtraffickingair", "scr_ojdg4_water_exp" },
			{ "Boat Explosion", "scr_oddjobtraffickingair", "scr_ojdg4_boat_exp" },
			//{ "Moving Cloud", "scr_exile1", "scr_ex1_moving_cloud" },
			//{ "Jeep Engine Fire", "scr_exile2", "scr_ex2_jeep_engine_fire" },
			//{ "Cargo Engine Trail", "scr_exile1", "scr_ex1_cargo_engine_trail" },
			{ "Cargo Engine Burst", "scr_exile1", "scr_ex1_cargo_engine_burst" },
			//{ "Cargo Smoke", "scr_exile1", "scr_ex1_cargo_smoke" },
			//{ "Cargo Fire", "scr_exile1", "cs_ex1_cargo_fire" },
			//{ "Cargo Debris", "scr_exile1", "scr_ex1_cargo_debris" },
			{ "Plane Explosion", "scr_exile1", "scr_ex1_plane_exp" },
			{ "Dust Impact", "scr_exile1", "scr_ex1_dust_impact" },
			{ "Car Impact Dust", "scr_finale1", "scr_fin_trev_car_impact" },
			//{ "Dust Settle", "scr_exile1", "scr_ex1_dust_settle" },
			//{ "Sparking Wires", "scr_exile1", "cs_ex1_sparking_wires_sm" },
			{ "Bike Burnout", "scr_jewelheist", "scr_jew_bike_burnout" },
			{ "Cab Smash", "scr_jewelheist", "scr_jewel_cab_smash" },
			{ "Wheel Burnout", "scr_carsteal4", "scr_carsteal4_wheel_burnout" },
			{ "Muzzle Flash", "scr_carsteal4", "scr_carsteal5_car_muzzle_flash" },
			{ "Flame", "core", "ent_sht_flame" },
			//{ "Fire Trail", "scr_martin1", "scr_sol1_fire_trail" },
			//{ "Falling Debris", "scr_agencyheist", "scr_fbi_falling_debris" },
			//{ "Building Smoke", "scr_agencyheistb", "scr_agency3b_blding_smoke" },
			{ "Breach Smoke", "scr_agencyheist", "scr_fbi_dd_breach_smoke" },
			{ "Electric Box Smoke", "scr_agencyheistb", "scr_agency3b_elec_box" },
			//{ "Shot Chopper", "scr_agencyheistb", "scr_agency3b_shot_chopper" },
			//{ "Wood Splinter", "scr_agencyheistb", "scr_agency3b_wood_splinter" },
			//{ "Rooftop Explosion", "scr_agencyheist", "scr_fbi_ext_rooftop" },
			{ "Explosion Fire Trail", "scr_agencyheistb", "scr_agency3b_heli_exp_trail" },
			//{ "RPG Trail", "scr_agencyheistb", "scr_agency3b_proj_rpg_trail" },
			//{ "Lighter Flame", "scr_mp_house", "scr_sh_lighter_flame" },
			{ "Petrol Fire", "scr_finale1", "scr_fin_fire_petrol_trev" },
			//{ "Petrol Fire 2", "ent_damage", "ent_sht_petrol_fire" },
			{ "Sparks", "scr_fbi4", "scr_fbi4_trucks_crash" },
			{ "Lighter Sparks", "scr_mp_house", "scr_sh_lighter_sparks" },
			{ "Blue Sparks", "scr_trevor1", "scr_trev1_trailer_boosh" },
			{ "Purplish Sparks", "scr_family4", "scr_fam4_trailer_sparks" },
			{ "Slipstream Formation", "scr_bike_adversary", "scr_adversary_slipstream_formation" },
			{ "Sodium Pour", "scr_bike_business", "scr_bike_meth_sodium_pour" },
			{ "Propylene Pour", "scr_bike_business", "scr_bike_meth_propylene_pour" },
			{ "Weed Smoke", "scr_bike_contraband", "scr_bike_truck_weed_smoke_cabin" },
	};

	static struct tAnimation {
		std::string DisplayName;
		std::string AnimationName;
		std::string AnimationId;
	};

	tAnimation eAnimation[99] = {
		{ std::string("Stop Animation"), std::string("Stop Animation"),  std::string("Stop Animation") },
		{ "Pole Dance", "mini@strip_club@pole_dance@pole_dance3", "pd_dance_03" },
		{ "Hood Dance", "missfbi3_sniping", "dance_m_default" },
		{ "Burning", "ragdoll@human", "on_fire" },
		{ "Getting Stunned", "ragdoll@human", "electrocute" },
		{ "Private Dance", "mini@strip_club@private_dance@part1", "priv_dance_p1" },
		{ "Sex receiver", "rcmpaparazzo_2", "shag_loop_poppy" },
		{ "Sex giver", "rcmpaparazzo_2", "shag_loop_a" },
		{ "Push ups", "amb@world_human_push_ups@male@base", "base"},
		{ "Sit ups", "amb@world_human_sit_ups@male@base", "base"},
		{ "Wave Yo' Arms", "random@car_thief@victimpoints_ig_3", "arms_waving"},
		{ "Give BJ to Driver", "mini@prostitutes@sexnorm_veh", "bj_loop_prostitute"},
		{ "Pleasure Driver", "mini@prostitutes@sexnorm_veh", "sex_loop_prostitute"},
		{ "Mime", "special_ped@mime@monologue_8@monologue_8a", "08_ig_1_wall_ba_0"},
		{ "Mime 2", "special_ped@mime@monologue_7@monologue_7a", "11_ig_1_run_aw_0"},
		{ "Throw", "switch@franklin@throw_cup", "throw_cup_loop"},
		{ "Smoke Coughing", "timetable@gardener@smoking_joint", "idle_cough"},
		{ "They Think We Dumb", "timetable@ron@they_think_were_stupid", "they_think_were_stupid"},
		{ "Come Here", "gestures@m@standing@fat", "gesture_come_here_hard"},
		{ "No Way", "gestures@m@standing@fat", "gesture_no_way"},
		{ "They're Gonna Kill Me", "random@bicycle_thief@ask_help", "my_dads_going_to_kill_me"},
		{ "You Gotta Help Me", "random@bicycle_thief@ask_help", "please_man_you_gotta_help_me"},
		{ "Sleep", "savecouch@", "t_sleep_loop_couch"},
		{ "Sleep 2", "savem_default@", "m_sleep_r_loop"},
		{ "Sleep 3", "timetable@tracy@sleep@", "idle_c"},
		{ "Meditate", "rcmcollect_paperleadinout@", "meditiate_idle"},
		{ "Fap", "switch@trevor@jerking_off", "trev_jerking_off_loop"},
		{ "Idle On Laptop", "switch@franklin@on_laptop", "001927_01_fras_v2_4_on_laptop_idle"},
		{ "Hands Up", "random@arrests", "idle_2_hands_up"},
		{ "Stand Still, Arms Spread", "mp_sleep", "bind_pose_180"},
			{ "Surrender", "random@arrests@busted", "idle_a" },
			{ "Police - Use Radio", "random@arrests", "generic_radio_chatter" },
			{ "Sniper Crouch", "missfbi2", "franklin_sniper_crouch" },
			{ "Crouch Walking", "move_weapon@rifle@generic", "walk_crouch" },
			{ "Hip Hop Dance", "missfbi3_sniping", "dance_m_default" },
			{ "Private Dance", "mini@strip_club@private_dance@part1", "priv_dance_p1" },
			{ "Mountain Dance", "special_ped@mountain_dancer@monologue_1@monologue_1a", "mtn_dnc_if_you_want_to_get_to_heaven" },
			{ "Bump and Grind", "mini@strip_club@private_dance@idle", "priv_dance_idle" },
			{ "Corny Dancing", "anim@mp_player_intincardancebodhi@rds@", "idle_a" },
			{ "Dirty Dancing", "oddjobs@assassinate@multi@yachttarget@lapdance", "yacht_ld_f" },
			{ "Crazy Dancing", "misschinese2_crystalmazemcs1_ig", "dance_loop_tao" },
			{ "Shake Your Butt", "switch@trevor@mocks_lapdance", "001443_01_trvs_28_idle_stripper" },
			{ "Jerking Off", "switch@trevor@jerking_off", "trev_jerking_off_loop" },
			{ "Butt Scratch", "mp_player_int_upperarse_pick", "mp_player_int_arse_pick" },
			{ "Peeing", "misscarsteal2peeing", "peeing_loop" },
			{ "Pooping", "missfbi3ig_0", "shit_loop_trev" },
			{ "Pick Nose", "anim@mp_player_intincarnose_pickstd@rps@", "idle_a" },
			{ "Wash Hands", "missheist_agency3aig_23", "urinal_sink_loop" },
			{ "Look at Fingernails", "missfbi3_camcrew", "base_gal" },
			{ "Brush Shoulders Off", "missfbi3_camcrew", "base_gal" },
			{ "Drunk", "move_m@drunk@verydrunk_idles@", "fidget_01" },
			{ "Twitchy", "oddjobs@bailbond_hobotwitchy", "idle_a" },
			{ "Ow, My Head", "misscarsteal4@actor", "dazed_idle" },
			{ "So Depressed", "oddjobs@bailbond_hobodepressed", "idle_a" },
			{ "Kick Rocks", "timetable@ron@ig_1", "ig_1_idle_a" },
			{ "Looking for Something", "missmic_4premierejimwaitbef_prem", "wait_idle_a" },
			{ "Bend Over to Look", "switch@franklin@admire_motorcycle", "base_franklin" },
			{ "Examining", "missfbi5ig_15", "look_into_microscope_c_scientistb" },
			{ "It's a Bird, It's a Plane", "oddjobs@basejump@", "ped_a_loop" },
			{ "Flip the Bird", "anim@mp_player_intincarfingerbodhi@ds@", "idle_a" },
			{ "Yelling at Someone", "misscarsteal4@actor", "actor_berating_loop" },
			{ "Getting Yelled At", "misscarsteal4", "assistant_loop" },
			{ "Arguing Girl", "missfbi3_camcrew", "first_action_gal" },
			{ "Arguing Guy", "missfbi3_camcrew", "first_action_guy" },
			{ "Kicking Guy on Ground 1", "missheistdockssetup1ig_13@kick_idle", "guard_beatup_kickidle_guard1" },
			{ "Kicking Guy on Ground 2", "missheistdockssetup1ig_13@kick_idle", "guard_beatup_kickidle_guard2" },
			{ "Getting Kicked", "missheistdockssetup1ig_13@kick_idle", "guard_beatup_kickidle_dockworker" },
			{ "Tough Guy - Arms Crossed", "missdocksshowoffcar@idle_a", "idle_b_5" },
			{ "Stand at Rail", "anim@amb@yacht@rail@standing@male@variant_01@", "base" },
			{ "Out of Breath", "re@construction", "out_of_breath" },
			{ "Base Jump Prep", "oddjobs@bailbond_mountain", "base_jump_idle" },
			{ "Jazzercise 1", "timetable@tracy@ig_5@idle_a", "idle_c" },
			{ "Jazzercise 2", "timetable@tracy@ig_5@idle_b", "idle_e" },
			{ "Warmup Stretching 1", "mini@triathlon", "idle_a" },
			{ "Warmup Stretching 2", "mini@triathlon", "ig_2_gen_warmup_01" },
			{ "Jog in Place", "amb@world_human_jog_standing@male@fitbase", "base" },
			{ "Cat - Scratch Ear", "creatures@cat@player_action@", "action_a" },
			{ "Dog - Sit", "creatures@dog@move", "sit_loop" },
			{ "Dog - Walk in Circles", "creatures@dog@move", "idle_turn_l" },
			{ "Rabbit - Scratch Ear", "creatures@rabbit@player_action@", "action_a" },
			{ "Monkey - Idle 1", "missfbi5ig_30monkeys", "monkey_a_idle" },
			{ "Monkey - Idle 2", "missfbi5ig_30monkeys", "monkey_b_idle" },
			{ "Monkey - Idle 3", "missfbi5ig_30monkeys", "monkey_c_idle" },
			{ "Monkey - Freakout 1", "missfbi5ig_30monkeys", "monkey_a_freakout_loop" },
			{ "Monkey - Freakout 2", "missfbi5ig_30monkeys", "monkey_b_freakout_loop" },
			{ "Monkey - Freakout 3", "missfbi5ig_30monkeys", "monkey_c_freakout_loop" },
			{ "Move to the Beat 1", "amb@world_human_strip_watch_stand@male_a@base", "base" },
			{ "Move to the Beat 2", "amb@world_human_strip_watch_stand@male_b@base", "base" },
			{ "Move to the Beat 3", "amb@world_human_strip_watch_stand@male_c@base", "base" },
			{ "Move to the Beat 4", "amb@world_human_strip_watch_stand@male_c@idle_a", "idle_a" },
			{ "Move to the Beat 5", "amb@world_human_partying@female@partying_beer@base", "base" },
			{ "Idle - Conceal Weapon 1", "anim@miss@low@fin@vagos@", "idle_ped01" },
			{ "Idle - Conceal Weapon 2", "anim@miss@low@fin@vagos@", "idle_ped02" },
			{ "Idle - Conceal Weapon 3", "anim@miss@low@fin@vagos@", "idle_ped03" },
			{ "Idle - Conceal Weapon 4", "anim@miss@low@fin@vagos@", "idle_ped04" },
			{ "Idle - Conceal Weapon 5", "anim@miss@low@fin@vagos@", "idle_ped05" },
			{ "Idle - Conceal Weapon 6", "anim@miss@low@fin@vagos@", "idle_ped06" },
			{ "Idle - Conceal Weapon 7", "anim@miss@low@fin@vagos@", "idle_ped07" },
			{ "Idle - Conceal Weapon 8", "anim@miss@low@fin@vagos@", "idle_ped08" }
	};

	static struct tScenario {
		std::string DisplayName;
		std::string Scenario;
	};

	tScenario eScenario[57] = {
		{ std::string("Stop Scenario"), std::string("Stop Scenario") },
		{ "Drilling", "WORLD_HUMAN_CONST_DRILL" },
		{ "Hammering", "WORLD_HUMAN_HAMMERING" },
		{ "Mechanic", "WORLD_HUMAN_VEHICLE_MECHANIC" },
		{ "Janitor", "WORLD_HUMAN_JANITOR" },
		{ "Hang Out", "WORLD_HUMAN_HANG_OUT_STREET" },
		{ "Play Guitar", "WORLD_HUMAN_MUSICIAN_MALE_BONGOS" },
		{ "Play Bongos", "WORLD_HUMAN_MUSICIAN_MALE_GUITAR" },
		{ "Clipboard", "WORLD_HUMAN_CLIPBOARD" },
		{ "Smoking", "WORLD_HUMAN_SMOKING" },
		{ "Smoking 2", "WORLD_HUMAN_AA_SMOKE" },
		{ "Smoking Weed", "WORLD_HUMAN_SMOKING_POT" },
		{ "Standing With Phone", "WORLD_HUMAN_STAND_MOBILE" },
		{ "Standing With Phone 2", "WORLD_HUMAN_STAND_MOBILE_UPRIGHT" },
		{ "Standing Guard", "WORLD_HUMAN_GUARD_STAND" },
		{ "Standing Impatiently", "WORLD_HUMAN_STAND_IMPATIENT" },
		{ "Standing Impatiently 2", "WORLD_HUMAN_STAND_IMPATIENT_UPRIGHT" },
		{ "Soldier Stand", "WORLD_HUMAN_GUARD_STAND_ARMY" },
		{ "Hobo Stand", "WORLD_HUMAN_BUM_STANDING" },
		{ "Doing Pushups", "WORLD_HUMAN_PUSH_UPS" },
		{ "Lifting Weights", "WORLD_HUMAN_MUSCLE_FREE_WEIGHTS" },
		{ "Flexing", "WORLD_HUMAN_MUSCLE_FLEX" },
		{ "Drug Dealer", "WORLD_HUMAN_DRUG_DEALER_HARD" },
		{ "Hooker", "WORLD_HUMAN_PROSTITUTE_LOW_CLASS" },
		{ "Hooker 2", "WORLD_HUMAN_PROSTITUTE_HIGH_CLASS" },
		{ "Drunk", "WORLD_HUMAN_STUPOR" },
		{ "Drinking", "WORLD_HUMAN_DRINKING" },
		{ "Drinking Coffee", "WORLD_HUMAN_AA_COFFEE" },
		{ "Binoculars", "WORLD_HUMAN_BINOCULARS" },
		{ "Welding", "WORLD_HUMAN_WELDING" },
		{ "Shocked", "WORLD_HUMAN_MOBILE_FILM_SHOCKING" },
		{ "Taking Pictures", "WORLD_HUMAN_PAPARAZZI" },
		{ "Medic", "CODE_HUMAN_MEDIC_KNEEL" },
		{ "Window Shopping", "WORLD_HUMAN_WINDOW_SHOP_BROWSE" },
		{ "Cleaning", "WORLD_HUMAN_MAID_CLEAN" },
		{ "Doing Yoga", "WORLD_HUMAN_YOGA" },
		{ "Tourist Map", "WORLD_HUMAN_TOURIST_MAP" },
		{ "Tennis Player", "WORLD_HUMAN_TENNIS_PLAYER" },
		{ "Sunbathing", "WORLD_HUMAN_SUNBATHE" },
		{ "Sunbathing 2", "WORLD_HUMAN_SUNBATHE_BACK" },
		{ "Fishing", "WORLD_HUMAN_STAND_FISHING" },
		{ "Shining Torch", "WORLD_HUMAN_SECURITY_SHINE_TORCH" },
		{ "Picnic", "WORLD_HUMAN_PICNIC" },
		{ "Partying", "WORLD_HUMAN_PARTYING" },
		{ "Leaning", "WORLD_HUMAN_LEANING" },
		{ "Jog Standing", "WORLD_HUMAN_JOG_STANDING" },
		{ "Human Statue", "WORLD_HUMAN_HUMAN_STATUE" },
		{ "Hanging Out (Street)", "WORLD_HUMAN_HANG_OUT_STREET" },
		{ "Golf Player", "WORLD_HUMAN_GOLF_PLAYER" },
		{ "Gardening", "WORLD_HUMAN_GARDENER_PLANT" },
		{ "Drug Dealing", "WORLD_HUMAN_DRUG_DEALER_HARD" },
		{ "Cheering", "WORLD_HUMAN_CHEERING" },
		{ "Parking Attendant", "WORLD_HUMAN_CAR_PARK_ATTENDANT" },
		{ "Wash", "WORLD_HUMAN_BUM_WASH" },
		{ "Holding Sign", "WORLD_HUMAN_BUM_FREEWAY" },
		{ "Laying Down (Hobo)", "WORLD_HUMAN_BUM_SLUMPED" },
		{ "BBQ", "PROP_HUMAN_BBQ" }
	};
};

inline GUI g_gui{};