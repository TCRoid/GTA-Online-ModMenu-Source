#pragma once
#include "stdafx.h"
std::vector<Hash> blacklistedObjects = {
	0x9CF21E0F ,0x34315488,//need 2 of this obj , 
	0x6A27FEB1, 0xCB2ACC8,
	0xC6899CDE, 0xD14B5BA3,
	0xD9F4474C, 0x32A9996C,
	0x69D4F974, 0xCAFC1EC3,
	0x79B41171, 0x1075651,
	0xC07792D4, 0x781E451D,
	0x762657C6, 0xC2E75A21,
	0xC3C00861, 0x81FB3FF0,
	0x45EF7804, 0xE65EC0E4,
	0xE764D794, 0xFBF7D21F,
	0xE1AEB708, 0xA5E3D471,
	0xD971BBAE, 0xCF7A9A9D,
	0xC2CC99D8, 0x8FB233A4,
	0x24E08E1F, 0x337B2B54,
	0xB9402F87, 0x4F2526DA,
	0xD75E01A6, 0xB015923B,
	0xC4C9551E,0x1AD51F27,
	0x675D244E,0x68E49D4D,
	122627294, 29828513,
	2180726768,2041844081,
	2783171697,2015249693,
	1781006001,2250084685,
	3864969444,3284142177,
	3330907358,3656664908,
	213036232,1173321732,
	875648136,3480918685,
	2889736519,3305783941,
	1481697203,3854081329,
	2761316604,2494305715
};
std::vector<int> CrashObject;
std::vector<Hash> blacklistveh = {
    0x82CAC433,0x4FAF0D70,
	0xF337AB36,0x6827CF72,
	0xFCFCB68B,0x60A7EA10,
	0x53174EEF,0x78BC1A3C,
	0x810369E2,0xD6BC7523,
	0x81BD2ED0,0xFE0A508C,
	0x15F27762,0x1AAD0DED,
	0x761E2AD3,0x7BE032C6,
	0x6A59902D,0x7CAB34D0,
	0xB12314E0,0xE5A2D6C6,
    0x46699F47,0x3E48BF23,
    0xA09E15FD,0x7074F39D,
    0xD36A4B44,0x9441D8D5,
    3872089630,1257886169,
    0x71D3B6F0,0x287FA449,
    0xD039510B,0x6827CF72
};
std::vector<Hash> blacklistped = {
	0x9B22DBAF,0x9B22DBAF,
    0x9B22DBAF,0x9B22DBAF,
    0x9B22DBAF,0x9B22DBAF,
    0x9B22DBAF,0x9B22DBAF,
    0x9B22DBAF,0x9B22DBAF,
    0x9B22DBAF,0x9B22DBAF,
    0x9B22DBAF,0x9B22DBAF,
    0x9B22DBAF,0x9B22DBAF,
    0x9B22DBAF,0x9B22DBAF,
    0x9B22DBAF,0x9B22DBAF,
    0x9B22DBAF,0x9B22DBAF,
    0x9B22DBAF,0x9B22DBAF,
    0x9B22DBAF,0x9B22DBAF,
    0x9B22DBAF,0x9B22DBAF
};
std::vector<Hash> modelchange =
{
	0x400AEC41,0x89768941,
	0xF0AC2626,0x5442C66B,
	0x55446010,0xB564882B,
	0x4BA14CCA,0x80E59F2E,
	0xD172497E,0xFBF98469,
	0x6DBBFC8B,0xD770C9B4,
	0x5D71A46F,0x62018559,
	0xF0EC56E2,0x6D1E15F7,
	0x9E08633D,0x0DE9A30A,
	0x47E4EEA0,0xDA116E7E
};
std::vector<char*> WalkStyle =
{
	"Generic Male",
	"Generic Female",
	"Cop",
	"Gangster",
	"Hipster",
	"Hobo",
	"Obese",
	"Lester",
	"Drunk",
	"Moderate Drunk",
	"Very Drunk",
	"Sexy",
	"Alien",
	"Buisness",
	"Casual",
	"Clipboard",
	"Coward",
	"Burning",
	"Flee",
	"Hiking",
	"Hurry",
	"Injured",
	"Intimidation",
	"Muscular",
	"Quick",
	"Sad",
	"Shady",
	"Shocked",
	"Arrogant",
	"Handbag Walk",
	"Heels",
	"Thug",
};
std::vector<char*> PTFXOutputNameList = {
	"NONE", "Clown Appears", "Firework 1", "Firework 2",
	"Firework 3", "Banknotes", "Truck Crash", "Alien 1",
	"Alien 2", "Electric Box", "Water Splash", "Bubbles",
	"Blood Entry", "Sniper Impact", "Dirt Throw", "Blood Stab",
	"Ped Sliced", "Camera", "Meth Smoke", "Burial Dirt"
};

std::vector<char*> PTFXAssetsList = {
	"NONE", "scr_rcbarry2", "scr_indep_fireworks", "proj_xmas_firework",
	"proj_xmas_firework", "scr_ornate_heist", "scr_fbi4", "scr_rcbarry1",
	"scr_rcbarry1", "scr_agencyheistb", "scr_fbi5a", "scr_fbi5a",
	"scr_finalec2", "scr_martin1", "core_snow", "scr_michael2",
	"scr_michael2", "scr_rcpaparazzo1", "scr_familyscenem", "scr_reburials"
};

std::vector<char*> PTFXNamesList = {
	"NONE", "scr_clown_appears", "scr_indep_firework_trailburst", "scr_firework_xmas_burst_rgw",
	"scr_firework_xmas_spiral_burst_rgw", "scr_heist_ornate_banknotes", "scr_fbi4_trucks_crash", "scr_alien_disintegrate",
	"scr_alien_teleport", "scr_agency3b_elec_box", "scr_fbi5_ped_water_splash", "water_splash_ped_bubbles",
	"scr_finale2_blood_entry", "scr_sol1_sniper_impact", "cs_mich1_spade_dirt_throw", "scr_mich2_blood_stab",
	"scr_abattoir_ped_sliced", "scr_rcpap1_camera", "scr_meth_pipe_smoke", "scr_burial_dirt"
};

std::vector<char*> appartments = {
	"Eclipse Tower apt 1",	"Eclipse Tower apt 2",	"Eclipse Tower apt 3",	"Eclipse Tower apt 4",	"3 Alta St",	"3 Alta St",	"Del Perro Heights apt 1",	"1162 Power St",	"0605 Spanish Ave",	"0604 Las Lagunas Blvd",	"0184 Milton Rd",	"The Royale",	"0504 S Mo Milton Dr",	"0115 Bay City Ave","0325 South Rockford Dr","Dream Tower",
	"2143 Las Lagunas Blvd","1561 San Vitas St",	"0112 S Rockford Dr",	"2057 Vespucci Blvd",	"0069 Cougar Ave",	"1237 Prosperity St",	"1115 Blvd Del Perro",	"0120 Murrieta Heights",	"Unit 14 Popular St",	"Unit 2 Popular St",	"331 Supply St",	"Unit 1 Olympic Fwy",	"0753 Roy Lowenstein Blvd","12 Little Bighorn Ave",
	"Unit 124 Popular St",	"0552 Roy Lowenstein Blvd",	"0432 Davis Ave",	"Del Perro Heights apt 2",	"Weazel Plaza apt 1",	"Weazel Plaza apt 2",	"Weazel Plaza apt 3",	"4 Integrity Way apt 1",	"4 Integrity Way apt 2",	"Richards Majestic apt 1",	"Richards Majestic apt 2",	"Tinsel Towers apt 1",	"Tinsel Towers apt 2",
	"142 Paleto Blvd",	"1 Strawberry Ave",	"1932 Grapeseed Ave",	"1920 Senora Way",	"2000 Great Ocean Highway",	"197 Route 68",	"870 Route 68 Approach",	"1200 Route 68",	"8754 Route 68",	"1905 Davis Ave",	"1623 South Shambles St",	"4531 Dry Dock St",	"1337 Exceptionalists Way",	"Unit 76 Greenwich Parkway",	"Garage Innocence Blvd",	"634 Blvd Del Perro",	"0897 Mirror Park Blvd",	"Eclipse Tower apt 5",	"Del Perro Heights apt 3",	"Richards Majestic apt 3",	"Tinsel Towers apt 3",	"4 Integrity Way apt 3",
	"4 Hangman Ave",	"12 Sustancia Rd",	"4584 Procopio Dr",	"4401 Procopio Dr",	"0232 Paleto Blvd",	"140 Zancudo Ave",	"1893 Grapeseed Ave",	"3655 Wild Oats Drive",	"2044 North Conker Avenue",	"2868 Hillcrest Avenue",	"2862 Hillcrest Avenue",	"3677 Whispymound Drive",	"2117 Milton Road",	"2868 Hillcrest Avenue",	"2874 Hillcrest Avenue",
	"2113 Mad Wayne Thunder Drive",	"2045 North Conker Avenue",	"Eclipse Tower apt 6",	"Eclipse Tower apt 7",	"Eclipse Tower apt 8",	"Eclipse Tower apt 9",	"LOMBANK Apartment 1",	"MazeBank Hotel Apartment 1",	"ARCADIUS Business center 1",	"MazeBank Tower Apartment 1",	"Auto Body Shop",	"Apartment 1 near the beach",
	"Hotel Wisdahl",	"Xero tank station",	"Apartment 1 next of the weapon shop",	"Apartment 2 next of the weapon shop",	"Clubhouse 1",	"Clubhouse 2",	"Clubhouse 3",	"Clubhouse 4",	"Clubhouse 5",	"Apartment 2 near the beach",	"LOMBANK Apartment 2",	"LOMBANK Apartment 3",	"LOMBANK Apartment 4",	"MazeBank Hotel Apartment 2",	"MazeBank Hotel Apartment 3",	"MazeBank Hotel Apartment 4",	"ARCADIUS Business center 2",	"ARCADIUS Business center 3",	"ARCADIUS Business center 4","MazeBank Tower Apartment 2","MazeBank Tower Apartment 3","MazeBank Tower Apartment 4"
};

std::vector<Hash> weaponListmk2 = {
	3219281620 ,2024373456 ,961495388,
	4208062921 ,3686625920 ,177293209
};

std::vector<char*> eventsidList = {
	"CEO_BAN","CEO_KICK","CEO_KICK2","SE_Crash","Unkonwn","Unkonwn2"
};
std::vector<char*>eventsidListKicks = {
	"KICK_1","KICK_TO_SM","KICK_2IMP","KICK_3,KICK_4XF"
};
std::vector<int> eventsidKicks = {
	KICK_1,KICK_TO_SM,KICK_2IMP,KICK_3,KICK_4XF
};

std::vector<int>eventsidlist =
{
	CEO_BAN,CEO_KICK,CEO_KICK2,SE_Crash,Unkonwn,Unkonwn2
};

std::vector<char*> objects = {
"prop_bskball_01","prop_flag_japan","prop_flag_us","prop_flag_canada","prop_flag_scotland_s","prop_flag_russia","prop_flag_german","prop_flag_uk_s","prop_flag_france","prop_acc_guitar_01_d1","PROP_MP_RAMP_03", "PROP_MP_RAMP_02", "PROP_MP_RAMP_01", "PROP_JETSKI_RAMP_01", "PROP_WATER_RAMP_03","prop_mp_ramp_03","PROP_VEND_SNAK_01", "PROP_TRI_START_BANNER", "PROP_TRI_FINISH_BANNER", "PROP_TEMP_BLOCK_BLOCKER", "PROP_SLUICEGATEL", "PROP_SKIP_08A", "PROP_SAM_01", "PROP_RUB_CONT_01B", "PROP_ROADCONE01A", "PROP_MP_ARROW_BARRIER_01", "PROP_HOTEL_CLOCK_01",
"PROP_LIFEBLURB_02", "PROP_COFFIN_02B", "PROP_MP_NUM_1", "PROP_MP_NUM_2", "PROP_MP_NUM_3", "PROP_MP_NUM_4", "PROP_MP_NUM_5", "PROP_MP_NUM_6", "PROP_MP_NUM_7", "PROP_MP_NUM_8", "PROP_MP_NUM_9", "prop_xmas_tree_int", "prop_bumper_car_01", "prop_beer_neon_01", "prop_space_rifle", "prop_dummy_01", "prop_rub_trolley01a", "prop_wheelchair_01_s", "PROP_CS_KATANA_01", "PROP_CS_DILDO_01", "prop_armchair_01", "prop_bin_04a",
"prop_chair_01a", "prop_dog_cage_01", "prop_dummy_plane", "prop_golf_bag_01", "prop_arcade_01",
"hei_prop_heist_emp", "prop_alien_egg_01", "prop_air_towbar_01", "hei_prop_heist_tug", "prop_air_luggtrolley", "PROP_CUP_SAUCER_01", "prop_wheelchair_01", "prop_ld_toilet_01", "prop_acc_guitar_01", "prop_bank_vaultdoor", "p_v_43_safe_s", "p_spinning_anus_s", "prop_can_canoe", "prop_air_woodsteps",
"Prop_weed_01", "prop_a_trailer_door_01", "prop_apple_box_01", "prop_air_fueltrail1", "prop_barrel_02a", "prop_barrel_float_1", "prop_barrier_wat_03b", "prop_air_fueltrail2", "prop_air_propeller01", "prop_windmill_01", "prop_Ld_ferris_wheel", "p_tram_crash_s", "p_oil_slick_01", "p_ld_stinger_s", "p_ld_soc_ball_01", "prop_juicestand", "p_oil_pjack_01_s",
"prop_barbell_01", "prop_barbell_100kg", "p_parachute1_s", "p_cablecar_s", "prop_beach_fire", "prop_lev_des_barge_02","prop_lev_des_barge_01", "prop_a_base_bars_01", "prop_beach_bars_01", "prop_air_bigradar", "prop_weed_pallet", "prop_artifact_01", "prop_attache_case_01", "prop_large_gold", "prop_roller_car_01", "prop_water_corpse_01", "prop_water_corpse_02",
"prop_dummy_01", "prop_atm_01", "hei_prop_carrier_docklight_01", "hei_prop_carrier_liferafts", "hei_prop_carrier_ord_03", "hei_prop_carrier_defense_02", "hei_prop_carrier_defense_01", "hei_prop_carrier_radar_1",
"hei_prop_carrier_radar_2", "hei_prop_hei_bust_01", "hei_prop_wall_alarm_on", "hei_prop_wall_light_10a_cr", "prop_afsign_amun", "prop_afsign_vbike", "prop_aircon_l_01", "prop_aircon_l_02", "prop_aircon_l_03", "prop_aircon_l_04", "prop_airhockey_01", "prop_air_bagloader", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_cargo_01a", "prop_air_chock_01", "prop_air_chock_03", "prop_air_gasbogey_01", "prop_air_generator_03",
"prop_air_stair_02", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_donut", "prop_amb_handbag_01", "prop_amp_01", "prop_anim_cash_pile_02", "prop_asteroid_01", "prop_arm_wrestle_01", "prop_ballistic_shield", "prop_bank_shutter", "prop_barier_conc_02b", "prop_barier_conc_05a", "prop_barrel_01a", "prop_bar_stool_01", "prop_basejump_target_01"
};


std::vector<char*> animOutputList = {
	"None", "Sex Receiver", "Sex Giver", "Sex In Car", "Sex In Car 2",
	"Stripper Dance 1", "Stripper Dance 2", "Stripper Dance 3", "Drunk Stripper", "Pole Dance",
	"Push Ups", "Sit Ups", "Celebrate", "Electrocution", "Suicide",
	"Showering", "Dog Fucking", "Meditation", "Arrested", "Dance",
	"Fixing Car", "Move Hands Up", "Sit Down Drunk", "Party Dance", "Party Dance 2",
	"Search In Box", "Plant", "Plant 2", "Cleaner", "Gum Exercise",
	"Gum Exercise 2", "Tired", "Sit Down Side", "Sit Down", "Power Walk",
	"Space Gravity", "Space Gravity 2", "Space Gravity 3", "Super Hero", "Middle Finger",
	"Middle Finger 2", "Thumbs Up", "Point Up", "Hands Up", "Injured",
	"Upside Down"
};

std::vector<char*> animDictList = {
	"none","rcmpaparazzo_2", "rcmpaparazzo_2", "mini@prostitutes@sexnorm_veh_first_person", "mini@prostitutes@sexnorm_veh_first_person",
	"mini@strip_club@private_dance@part1", "mini@strip_club@private_dance@part2", "mini@strip_club@private_dance@part3", "amb@world_human_prostitute@crackhooker@idle_a", "mini@strip_club@pole_dance@pole_dance1",
	"amb@world_human_push_ups@male@base", "amb@world_human_sit_ups@male@base", "rcmfanatic1celebrate", "ragdoll@human", "mp_suicide",
	"mp_safehouseshower@male@", "missfra0_chop_find", "rcmcollect_paperleadinout@", "random@arrests", "timetable@tracy@ig_5@idle_b",
	"mini@repair", "random@mugging5", "amb@world_human_stupor@male_looking_left@base", "amb@world_human_partying@female@partying_beer@base", "amb@world_human_partying@female@partying_beer@idle_a",
	"amb@prop_human_bum_bin@base", "amb@world_human_gardener_plant@female@base", "amb@world_human_gardener_plant@female@idle_a", "amb@world_human_janitor@male@idle_a", "amb@world_human_jog@female@idle_b",
	"amb@world_human_jog_standing@female@idle_a", "amb@world_human_jog_standing@male@idle_b", "amb@world_human_picnic@female@base", "amb@world_human_picnic@male@idle_a", "amb@world_human_power_walker@female@idle_a",
	"mini@biotech@blowtorch_def", "mini@biotech@blowtorch_def", "mini@biotech@blowtorch_str", "amb@world_human_superhero@male@space_pistol@idle_b", "anim@mp_player_intselfiethe_bird",
	"anim@mp_player_intupperfinger", "anim@mp_player_intincarthumbs_uplow@ds@", "anim@mp_point", "anim@mp_rollarcoaster", "combat@damage@injured_pistol@to_writhe",
	"dead@fall"
};

std::vector<char*> animNameList = {
	"none","shag_loop_poppy", "shag_loop_a", "bj_loop_prostitute", "sex_loop_prostitute",
	"priv_dance_p1", "priv_dance_p2", "priv_dance_p3", "idle_c", "pd_dance_01",
	"base", "base", "celebrate", "electrocute", "pistol",
	"male_shower_idle_b", "hump_loop_chop", "meditiate_idle", "kneeling_arrest_idle", "idle_e",
	"fixing_a_player", "001445_01_gangintimidation_1_female_idle_b", "base", "base", "idle_a",
	"base", "base_female", "idle_a_female", "idle_a", "idle_d",
	"idle_a", "idle_d", "base", "idle_a", "idle_a",
	"blowtorch_intro", "blowtorch_start_loop", "blowtorch_success_outro", "idle_f", "idle_a",
	"idle_a_fp", "enter", "additive_walk", "hands_up_idle_a_player_one", "variation_b",
	"dead_fall_down"
};

std::vector<char*> pedModels = {
	"A_C_Boar","A_C_Chimp","A_C_Coyote","A_C_Fish","A_C_Pig","A_C_Rhesus","A_F_M_Beach_01","A_F_M_BevHills_01","A_F_M_BevHills_02","A_F_M_BodyBuild_01","A_F_M_Business_02","A_F_M_Downtown_01","A_F_M_EastSA_01",
	"A_F_M_EastSA_02","A_F_M_FatBla_01","A_F_M_FatCult_01","A_F_M_FatWhite_01","A_F_M_KTown_01","A_F_M_KTown_02","A_F_M_ProlHost_01","A_F_M_Salton_01","A_F_M_SkidRow_01","A_F_M_SouCentMC_01","A_F_M_SouCent_01","A_F_M_SouCent_02",
	"A_F_M_Tourist_01","A_F_M_TrampBeac_01","A_F_M_Tramp_01","A_F_O_GenStreet_01","A_F_O_Indian_01","A_F_O_KTown_01","A_F_O_Salton_01","A_F_O_SouCent_01","A_F_O_SouCent_02","A_F_Y_Beach_01","A_F_Y_BevHills_01","A_F_Y_BevHills_02",
	"A_F_Y_BevHills_03","A_F_Y_BevHills_04","A_F_Y_Business_01","A_F_Y_Business_02","A_F_Y_Business_03","A_F_Y_Business_04","A_F_Y_EastSA_01","A_F_Y_EastSA_02","A_F_Y_EastSA_03","A_F_Y_Epsilon_01","A_F_Y_Fitness_01",
	"A_F_Y_Fitness_02","A_F_Y_GenHot_01","A_F_Y_Golfer_01","A_F_Y_Hiker_01","A_F_Y_Hipster_01","A_F_Y_Hipster_02","A_F_Y_Hipster_03","A_F_Y_Hipster_04","A_F_Y_Indian_01","A_F_Y_Juggalo_01","A_F_Y_Runner_01",
	"A_F_Y_RurMeth_01","A_F_Y_SCDressy_01","A_F_Y_Skater_01","A_F_Y_SouCent_01","A_F_Y_SouCent_02","A_F_Y_SouCent_03","A_F_Y_Tennis_01","A_F_Y_Topless_01","A_F_Y_Tourist_01","A_F_Y_Tourist_02","A_F_Y_Vinewood_01",
	"A_F_Y_Vinewood_02","A_F_Y_Vinewood_03","A_F_Y_Vinewood_04","A_F_Y_Yoga_01","A_M_M_ACult_01","A_M_M_AfriAmer_01","A_M_M_Beach_01","A_M_M_Beach_02","A_M_M_BevHills_01","A_M_M_BevHills_02","A_M_M_Business_01",
	"A_M_M_EastSA_01","A_M_M_EastSA_02","A_M_M_Farmer_01","A_M_M_FatLatin_01","A_M_M_GenFat_01","A_M_M_GenFat_02","A_M_M_Golfer_01","A_M_M_HasJew_01","A_M_M_Hillbilly_01","A_M_M_Hillbilly_02","A_M_M_Indian_01",
	"A_M_M_KTown_01","A_M_M_Malibu_01","A_M_M_MexCntry_01","A_M_M_MexLabor_01","A_M_M_OG_Boss_01","A_M_M_Paparazzi_01","A_M_M_Polynesian_01","A_M_M_ProlHost_01","A_M_M_RurMeth_01","A_M_M_Salton_01","A_M_M_Salton_02",
	"A_M_M_Salton_03","A_M_M_Salton_04","A_M_M_Skater_01","A_M_M_Skidrow_01","A_M_M_SoCenLat_01","A_M_M_SouCent_01","A_M_M_SouCent_02","A_M_M_SouCent_03","A_M_M_SouCent_04","A_M_M_StLat_02","A_M_M_Tennis_01",
	"A_M_M_Tourist_01","A_M_M_TrampBeac_01","A_M_M_Tramp_01","A_M_M_TranVest_01","A_M_M_TranVest_02","A_M_O_ACult_01","A_M_O_ACult_02","A_M_O_Beach_01","A_M_O_GenStreet_01","A_M_O_KTown_01","A_M_O_Salton_01",
	"A_M_O_SouCent_01","A_M_O_SouCent_02","A_M_O_SouCent_03","A_M_O_Tramp_01","A_M_Y_ACult_01","A_M_Y_ACult_02","A_M_Y_BeachVesp_01","A_M_Y_BeachVesp_02","A_M_Y_Beach_01","A_M_Y_Beach_02","A_M_Y_Beach_03","A_M_Y_BevHills_01",
	"A_M_Y_BevHills_02","A_M_Y_BreakDance_01","A_M_Y_BusiCas_01","A_M_Y_Business_01","A_M_Y_Business_02","A_M_Y_Business_03","A_M_Y_Cyclist_01","A_M_Y_DHill_01","A_M_Y_Downtown_01","A_M_Y_EastSA_01","A_M_Y_EastSA_02",
	"A_M_Y_Epsilon_01","A_M_Y_Epsilon_02","A_M_Y_Gay_01","A_M_Y_Gay_02","A_M_Y_GenStreet_01","A_M_Y_GenStreet_02","A_M_Y_Golfer_01","A_M_Y_HasJew_01","A_M_Y_Hiker_01","A_M_Y_Hipster_01","A_M_Y_Hipster_02",
	"A_M_Y_Hipster_03","A_M_Y_Indian_01","A_M_Y_Jetski_01","A_M_Y_Juggalo_01","A_M_Y_KTown_01","A_M_Y_KTown_02","A_M_Y_Latino_01","A_M_Y_MethHead_01","A_M_Y_MexThug_01","A_M_Y_MotoX_01","A_M_Y_MotoX_02","A_M_Y_MusclBeac_01",
	"A_M_Y_MusclBeac_02","A_M_Y_Polynesian_01","A_M_Y_RoadCyc_01","A_M_Y_Runner_01","A_M_Y_Runner_02","A_M_Y_Salton_01","A_M_Y_Skater_01","A_M_Y_Skater_02","A_M_Y_SouCent_01","A_M_Y_SouCent_02","A_M_Y_SouCent_03","A_M_Y_SouCent_04",
	"A_M_Y_StBla_01","A_M_Y_StBla_02","A_M_Y_StLat_01","A_M_Y_StWhi_01","A_M_Y_StWhi_02","A_M_Y_Sunbathe_01","A_M_Y_Surfer_01","A_M_Y_VinDouche_01","A_M_Y_Vinewood_01","A_M_Y_Vinewood_02","A_M_Y_Vinewood_03","A_M_Y_Vinewood_04",
	"A_M_Y_Yoga_01","CSB_Abigail","CSB_Anita","CSB_Anton","CSB_BallasOG","CSB_Bride","CSB_BurgerDrug","CSB_Car3guy1","CSB_Car3guy2","CSB_Chef","CSB_Chin_goon","CSB_Cletus","CSB_Cop","CSB_Customer","CSB_Denise_friend",
	"CSB_FOS_rep","CSB_G","CSB_Groom","CSB_Grove_str_dlr","CSB_Hao","CSB_Hugh","CSB_Imran","CSB_Janitor","CSB_Maude","CSB_MWeather","CSB_Ortega","CSB_Oscar","CSB_PornDudes","CSB_PrologueDriver","CSB_ProlSec","CSB_Ramp_gang",
	"CSB_Ramp_hic","CSB_Ramp_hipster","CSB_Ramp_marine","CSB_Ramp_mex","CSB_Reporter","CSB_RoccoPelosi","CSB_Screen_Writer","CSB_Stripper_01","CSB_Stripper_02","CSB_Tonya","CSB_TrafficWarden","G_F_Y_ballas_01","G_F_Y_Families_01",
	"G_F_Y_Lost_01","G_F_Y_Vagos_01","G_M_M_ArmBoss_01","G_M_M_ArmGoon_01","G_M_M_ArmLieut_01","G_M_M_ChemWork_01","G_M_M_ChiBoss_01","G_M_M_ChiCold_01","G_M_M_ChiGoon_01","G_M_M_ChiGoon_02","G_M_M_KorBoss_01","G_M_M_MexBoss_01",
	"G_M_M_MexBoss_02","G_M_Y_ArmGoon_02","G_M_Y_Azteca_01","G_M_Y_BallaEast_01","G_M_Y_BallaOrig_01","G_M_Y_BallaSout_01","G_M_Y_FamCA_01","G_M_Y_FamDNF_01","G_M_Y_FamFor_01","G_M_Y_Korean_01","G_M_Y_Korean_02","G_M_Y_KorLieut_01",
	"G_M_Y_Lost_01","G_M_Y_Lost_02","G_M_Y_Lost_03","G_M_Y_MexGang_01","G_M_Y_MexGoon_01","G_M_Y_MexGoon_02","G_M_Y_MexGoon_03","G_M_Y_PoloGoon_01","G_M_Y_PoloGoon_02","G_M_Y_SalvaBoss_01","G_M_Y_SalvaGoon_01","G_M_Y_SalvaGoon_02",
	"G_M_Y_SalvaGoon_03","G_M_Y_StrPunk_01","G_M_Y_StrPunk_02","IG_Abigail","IG_Ashley","IG_Bankman","IG_Barry","IG_BestMen","IG_Bride","IG_Car3guy1","IG_Car3guy2","IG_Casey","IG_Chef","IG_ChengSr","IG_Clay","IG_ClayPain","IG_Cletus",
	"IG_Dale","IG_Dreyfuss","IG_FBISuit_01","IG_Groom","IG_Hao","IG_Hunter","IG_Janet","IG_JewelAss","IG_JimmyBoston","IG_JoeMinuteMan","ig_JohnnyKlebitz","IG_Josef","IG_Josh","IG_KerryMcIntosh","IG_LifeInvad_01","IG_LifeInvad_02","IG_Magenta",
	"IG_Manuel","IG_Marnie","IG_MaryAnn","IG_Michelle","IG_MrsPhillips","IG_Natalia","IG_Nigel","IG_Old_Man1A","IG_Old_Man2","IG_ONeil","IG_Ortega","IG_Paper","IG_Priest","IG_ProlSec_02","IG_Ramp_Gang","IG_Ramp_Hic","IG_Ramp_Hipster","IG_Ramp_Mex",
	"IG_RoccoPelosi","IG_RussianDrunk","IG_Screen_Writer","IG_Talina","IG_Terry","IG_TomEpsilon","IG_Tonya","IG_TrafficWarden","IG_TylerDix","IG_Zimbor","MP_G_M_Pros_01","MP_M_ExArmy_01","S_F_M_Fembarber","S_F_M_Maid_01","S_F_M_Shop_HIGH",
	"S_F_M_SweatShop_01","S_F_Y_AirHostess_01","S_F_Y_Bartender_01","S_F_Y_Baywatch_01","S_F_Y_Cop_01","S_F_Y_Factory_01","S_F_Y_Hooker_01","S_F_Y_Hooker_02","S_F_Y_Hooker_03","S_F_Y_Migrant_01","S_F_Y_MovPrem_01","S_F_Y_Ranger_01",
	"S_F_Y_Scrubs_01","S_F_Y_Sheriff_01","S_F_Y_Shop_LOW","S_F_Y_Shop_MID","S_F_Y_StripperLite","S_F_Y_Stripper_01","S_F_Y_Stripper_02","S_F_Y_SweatShop_01","S_M_M_AmmuCountry","S_M_M_Armoured_01","S_M_M_Armoured_02","S_M_M_AutoShop_01",
	"S_M_M_AutoShop_02","S_M_M_Bouncer_01","S_M_M_ChemSec_01","S_M_M_CIASec_01","S_M_M_CntryBar_01","S_M_M_DockWork_01","S_M_M_Doctor_01","S_M_M_FIBOffice_01","S_M_M_FIBOffice_02","S_M_M_Gaffer_01","S_M_M_Gardener_01","S_M_M_GenTransport",
	"S_M_M_HairDress_01","S_M_M_HighSec_01","S_M_M_HighSec_02","S_M_M_Janitor","S_M_M_LatHandy_01","S_M_M_LifeInvad_01","S_M_M_Linecook","S_M_M_LSMetro_01","S_M_M_Mariachi_01","S_M_M_Marine_01","S_M_M_Marine_02","S_M_M_Migrant_01",
	"S_M_M_MovAlien_01","S_M_M_MovPrem_01","S_M_M_MovSpace_01","S_M_M_Paramedic_01","S_M_M_Pilot_01","S_M_M_Pilot_02","S_M_M_Postal_01","S_M_M_Postal_02","S_M_M_PrisGuard_01","S_M_M_Scientist_01","S_M_M_Security_01","S_M_M_SnowCop_01",
	"S_M_M_StrPerf_01","S_M_M_StrVend_01","S_M_M_Trucker_01","S_M_M_UPS_01","S_M_M_UPS_02","S_M_O_Busker_01","S_M_Y_AirWorker","S_M_Y_AmmuCity_01","S_M_Y_ArmyMech_01","S_M_Y_Autopsy_01","S_M_Y_Barman_01","S_M_Y_BayWatch_01",
	"S_M_Y_BlackOps_01","S_M_Y_BlackOps_02","S_M_Y_BlackOps_03","S_M_Y_BusBoy_01","S_M_Y_Chef_01","S_M_Y_Clown_01","S_M_Y_Construct_01","S_M_Y_Construct_02","S_M_Y_Cop_01","S_M_Y_Dealer_01","S_M_Y_DevinSec_01","S_M_Y_DockWork_01","S_M_Y_Doorman_01",
	"S_M_Y_DWService_01","S_M_Y_DWService_02","S_M_Y_Factory_01","S_M_Y_Fireman_01","S_M_Y_Garbage","S_M_Y_Grip_01","S_M_Y_HwayCop_01","S_M_Y_Marine_01","S_M_Y_Marine_02","S_M_Y_Marine_03","S_M_Y_PestCont_01","S_M_Y_Pilot_01","S_M_Y_PrisMuscl_01",
	"S_M_Y_Prisoner_01","S_M_Y_Ranger_01","S_M_Y_Robber_01","S_M_Y_Sheriff_01","S_M_Y_Shop_MASK","S_M_Y_StrVend_01","S_M_Y_Swat_01","S_M_Y_USCG_01","S_M_Y_Valet_01","S_M_Y_Waiter_01","S_M_Y_WinClean_01","S_M_Y_XMech_01","S_M_Y_XMech_02",
	"U_F_M_Corpse_01","U_F_M_Miranda","U_F_M_ProMourn_01","U_F_O_ProlHost_01","U_F_Y_BikerChic","U_F_Y_corpse_01","U_F_Y_corpse_02","U_F_Y_HotPosh_01","U_F_Y_JewelAss_01","U_F_Y_Mistress","U_F_Y_PoppyMich","U_F_Y_Princess","U_F_Y_SpyActress",
	"U_M_M_Aldinapoli","U_M_M_BankMan","U_M_M_BikeHire_01","U_M_M_FIBArchitect","U_M_M_FilmDirector","U_M_M_GlenStank_01","U_M_M_JewelSec_01","U_M_M_JewelThief","U_M_M_MarkFost","U_M_M_PartyTarget","U_M_M_ProlSec_01","U_M_M_ProMourn_01",
	"U_M_M_RivalPap","U_M_M_SpyActor","U_M_M_WillyFist","U_M_O_TapHillBilly","U_M_O_Tramp_01","U_M_Y_Abner","U_M_Y_AntonB",	"U_M_Y_BabyD","U_M_Y_BurgerDrug_01","U_M_Y_Chip","U_M_Y_Cyclist_01","U_M_Y_FIBMugger_01","U_M_Y_Guido_01","U_M_Y_GunVend_01",
	"U_M_Y_Justin","U_M_Y_Paparazzi","U_M_Y_Party_01","U_M_Y_Pogo_01","U_M_Y_Prisoner_01","U_M_Y_ProlDriver_01","U_M_Y_RSRanger_01","U_M_Y_SBike","U_M_Y_StagGrm_01","U_M_Y_Tattoo_01",
};

std::vector<char*> Ped_List = {
			   "player_zero", "player_one", "player_two", "ig_mp_agent14", "ig_taocheng", "ig_stevehains",
			   "ig_orleans", "ig_amandatownley", "mp_s_m_armoured_01", "mp_m_claude_01", "ig_wade", "ig_lestercrest_2",
			   "ig_avon", "ig_rashcosvki", "ig_paige", "mp_m_marston_01", "ig_lestercrest", "ig_lamardavis"
};

std::vector<char*> Ped_List_animal = {
		"a_c_boar", "a_c_chickenhawk", "a_c_chop", "a_c_cormorant", "a_c_crow", "a_c_cow", "a_c_coyote",
		"a_c_deer", "a_c_dolphin", "a_c_fish", "a_c_sharkhammer", "a_c_hen", "a_c_humpback", "a_c_husky",
		"a_c_killerwhale", "a_c_mtlion", "a_c_pig", "a_c_pigeon", "a_c_poodle", "a_c_pug", "a_c_rabbit_01",
		"a_c_rat", "a_c_retriever", "a_c_rhesus", "a_c_rottweiler", "a_c_seagull", "a_c_shepherd",
		"a_c_stingray", "a_c_sharktiger", "a_c_westy"
};

std::vector<Hash> PedProtex =
{
    0x9B22DBAF,0x9B810FA2,0x0D7114C9,
    0x92991B72,0xD266D9D6
};
//地下车友会DLC
char* tunersDLC[15] =
{
    "PREVION","DOMINATOR7","TAILGATER2",
    "ZR350","CALICO","FUTO2","EUROS","JESTER4",
    "REMUS","COMET6","GROWLER","VECTRE","CYPHER",
    "SULTAN3","RT3000"
};
//名钻赌场DLC
char* diamondDLC[21] = {
            "CARACARA2",
            "DRAFTER",
            "DYNASTY",
            "EMERUS",
            "GAUNTLET3",
            "GAUNTLET4",
            "HELLION",
            "ISSI7",
            "JUGULAR",
            "KRIEGER",
            "LOCUST",
            "NEBULA",
            "NEO",
            "NOVAK",
            "PARAGON",
            "PARAGON2",
            "PEYOTE2",
            "RROCKET",
            "THRAX",
            "ZION3",
            "ZORRUSSO"
    };
//名钻赌场豪劫DLC更新
char* casinoHeistDLC[20] = {
            "ASBO",
            "EVERON",
            "FORMULA",
            "FORMULA2",
            "FURIA",
            "IMORGON",
            "JB7002",
            "KANJO",
            "KOMODA",
            "MINITANK",
            "OUTLAW",
            "REBLA",
            "RETINUE2",
            "STRYDER",
            "SUGOI",
            "SULTAN2",
            "VAGRANT",
            "VSTR",
            "YOSEMITE2",
            "ZHABA"
    };
//竞技场之战DLC
char* arenaWarDLC[46] = {
            "impaler", "toros", "tulip", "vamos", "deveste", "deviant", "rcbandito", "schlagen", "italigto",
            "bruiser", "bruiser2", "bruiser3", "brutus", "brutus2", "brutus3", "cerberus", "cerberus2", "cerberus3",
            "clique", "deathbike", "deathbike2",
            "deathbike3", "dominator4", "dominator5", "dominator6", "impaler2", "impaler3", "impaler4", "imperator",
            "imperator2", "imperator3", "issi4", "issi5", "issi6", "monster3", "monster4", "monster5", "scarab",
            "scarab2", "scarab3", "slamvan4", "slamvan5",
            "slamvan6", "zr380", "zr3802", "zr3803"
    };
//船只
char* boats[21] = {
            "DINGHY", "DINGHY2", "DINGHY3", "DINGHY4", "JETMAX",
            "MARQUIS", "PREDATOR", "SEASHARK", "SEASHARK2", "SEASHARK3",
            "SPEEDER", "SPEEDER2", "SQUALO", "SUBMERSIBLE", "SUBMERSIBLE2",
            "SUNTRAP", "TORO", "TORO2", "TROPIC", "TROPIC2",
            "TUG"
    };
//商业广告车辆
char* commercial[11] = {
            "BENSON", "BIFF", "HAULER", "MULE", "MULE2",
            "MULE3", "PACKER", "PHANTOM", "POUNDER", "STOCKADE",
            "STOCKADE3"
    };
//小型车辆
char* compacts[8] = {
            "BLISTA", "BRIOSO", "DILETTANTE", "DILETTANTE2", "ISSI2",
            "PANTO", "PRAIRIE", "RHAPSODY"
    };
//轿跑车
char* coupes[14] = {
            "COGCABRIO", "EXEMPLAR", "F620", "FELON", "FELON2",
            "JACKAL", "ORACLE", "ORACLE2", "SENTINEL", "SENTINEL2",
            "WINDSOR", "WINDSOR2", "ZION", "ZION2"
    };
//自行车
char* cycles[7] = {
            "BMX", "CRUISER", "FIXTER", "SCORCHER", "TRIBIKE",
            "TRIBIKE2", "TRIBIKE3"
    };
//警用
char* emergency[18] = {
            "AMBULANCE", "FBI", "FBI2", "FIRETRUK", "LGUARD",
            "PBUS", "PRANGER", "POLICE", "POLICE2", "POLICE3",
            "POLICE4", "POLICEB", "POLICEOLD1", "POLICEOLD2", "POLICET",
            "SHERIFF", "SHERIFF2", "RIOT"
    };
//直升机
char* helicopters[22] = {
            "ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
            "CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
            "FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
            "SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
            "VALKYRIE2", "VOLATUS"
    };
//工业车辆
char* industrial[11] = {
            "BULLDOZER", "CUTTER", "DUMP", "FLATBED", "GUARDIAN",
            "HANDLER", "MIXER", "MIXER2", "RUBBLE", "TIPTRUCK",
            "TIPTRUCK2"
    };
//军用
char* military[5] = {
            "BARRACKS", "BARRACKS2", "BARRACKS3", "CRUSADER", "RHINO"
    };
//摩托
char* motorcycles[48] = {
            "AKUMA", "AVARUS", "BAGGER", "BATI", "BATI2",
            "BF400", "CARBONRS", "CHIMERA", "CLIFFHANGER", "DAEMON",
            "DAEMON2", "DEFILER", "DOUBLE", "ENDURO", "ESSKEY",
            "FAGGIO", "FAGGIO2", "FAGGIO3", "GARGOYLE", "HAKUCHOU",
            "HAKUCHOU2", "HEXER", "INNOVATION", "LECTRO", "MANCHEZ",
            "NEMESIS", "NIGHTBLADE", "PCJ","OPPRESSOR","OPPRESSOR2",
            "RATBIKE", "RUFFIAN","SANCHEZ", "SANCHEZ2", "SANCTUS",
            "SHOTARO", "SOVEREIGN","THRUST", "VADER", "VINDICATOR", 
            "VORTEX", "WOLFSBANE","ZOMBIEA", "ZOMBIEB", "DIABLOUS", 
            "DIABLOUS2", "FCR", "FCR2"
    };
//美式肌肉车
char* muscle[41] = {
            "BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
            "COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2",
            "GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
            "HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
            "PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER", "RUINER2", "RUINER3",
            "SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
            "STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO",
            "VIRGO2", "VIRGO3", "VOODOO", "VOODOO2"
    };
//越野车
char* offRoad[31] = {
            "BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
            "BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
            "DUNE", "DUNE2", "INSURGENT", "INSURGENT2", "KALAHARI",
            "MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
            "REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
            "TROPHYTRUCK", "TROPHYTRUCK2", "TECHNICAL2", "DUNE4", "DUNE5",
            "BLAZER5"
    };
//飞机
char* planes[19] = {
            "BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
            "HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
            "MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
            "TITAN", "VELUM", "VELUM2", "VESTRA"
    };
//轿车
char* sedans[31] = {
            "ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
            "COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
            "FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
            "PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
            "SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
            "STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARRENER",
            "WASHINGTON"
    };
//公共服务车辆
char* services[11] = {
            "AIRBUS", "BRICKADE", "BUS", "COACH", "RALLYTRUCK",
            "RENTALBUS", "TAXI", "TOURBUS", "TRASH", "TRASH2",
            "WASTELANDER",
    };
//跑车
char* sports[46] = {
            "ALPHA", "BANSHEE", "BESTIAGTS", "BLISTA2", "BLISTA3",
            "BUFFALO", "BUFFALO2", "BUFFALO3", "CARBONIZZARE", "COMET2",
            "COQUETTE", "ELEGY", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
            "FUTO", "JESTER", "JESTER2", "KHAMELION", "KURUMA",
            "KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
            "NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2",
            "RAPTOR", "SCHAFTER3", "SCHAFTER4", "SCHWARTZER", "SEVEN70",
            "SULTAN", "SURANO", "SPECTER", "SPECTER2", "TAMPA2", "TROPOS", "VERLIERER2",
            "RUINER2", "PHANTOM2", "RUSTON"
    };
//经典跑车
char* sportsClassics[23] = {
            "BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
            "FELTZER3", "JB700", "MAMBA", "MANANA", "MONROE",
            "PEYOTE", "PIGALLE", "STINGER", "STINGERGT", "TORNADO",
            "TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5", "TORNADO6",
            "ZTYPE", "INFERNUS2", "TURISMO2",
    };
//超级跑车
char* Super[29] = {
            "ADDER", "BANSHEE2", "BULLET", "CHEETAH", "ENTITYXF",
            "FMJ", "SHEAVA", "INFERNUS", "NERO", "NERO2", "OSIRIS", "LE7B",
            "ITALIGTB", "ITALIGTB2", "PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS", "T20",
            "TEMPESTA", "TURISMOR", "TYRUS", "VACCA", "VOLTIC", "ZENTORNO", "VOLTIC2", "PENETRATOR", "XA21","GP1"
    };
//SUV
char* sUVs[27] = {
            "BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
            "BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
            "DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
            "HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
            "PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
            "XLS", "XLS2"
    };
//拖车
char* trailer[22] = {
            "ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
            "DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
            "TANKER", "TANKER2", "TR2", "TR3", "TR4",
            "TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
            "TRFLAT", "TVTRAILER"
    };
//火车
char* trains[8] = {
            "CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
            "FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
    };
//公共事业
char* utility[18] = {
            "AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT",
            "MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
            "TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
            "UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3"
    };
//货车
char* vans[32] = {
            "BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
            "BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
            "BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
            "GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
            "PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
            "SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
            "YOUGA", "YOUGA2"
    };
//走私大暴走dlc
char* smugglersDLC[19] = {
            "VIGILANTE", "BOMBUSHKA", "ALPHAZ1", "TULA", "HUNTER",
            "ROGUE", "PYRO", "MOGUL", "NOKOTA", "MOLOTOK", "SEABREEZE",
            "HAVOK", "microlight", "HOWARD", "STARLING", "RAPIDGT3",
            "RETINUE", "CYCLONE", "VISIONE"
    };
//军火霸业DLC
char* gunrunningDLC[15] = {
            "APC", "ARDENT", "CADDY3", "CHEETAH2", "DUNE3", "HALFTRACK", "HAULER2", "INSURGENT3",
            "NIGHTSHARK", "OPPRESSOR", "PHANTOM3", "TAMPA3", "TORERO", "VAGNER", "XA21"
    };
//末日豪劫DLC
char* doomsdayDLC[30] = {
            "Z190", "AKULA", "AUTARCH", "AVENGER", "AVENGER2", "BARRAGE", "CHERNOBOG",
            "COMET4", "COMET5", "DELUXO", "GT500", "HERMES", "HUSTLER", "KAMACHO",
            "KHANJALI", "NEON", "PARIAH", "RAIDEN", "REVOLTER", "RIATA", "RIOT2", "SAVESTRA",
            "SC1", "SENTINEL3", "STREITER", "STROMBERG", "THRUSTER",
            "VISERIS", "VOLATOL", "YOSEMITE"
    };
//南圣安地列斯超级系列赛
char* sportSeries[15] = {
            "CHEBUREK", "DOMINATOR3", "ELLIE", "ENTITY2", "FAGALOA", "FLASHGT", "GB200",
            "HOTRING", "ISSI3", "JESTER3", "MICHELLI", "SEASPARROW", "TAIPAN", "TEZERACT",
            "TYRANT"
    };