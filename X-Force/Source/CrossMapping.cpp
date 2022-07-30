#include "stdafx.h"
#include <mmsystem.h>
#include <ios>
#include <fstream>
#include <fileapi.h>
#include <experimental/filesystem>
::std::unordered_map<uint64_t, uint64_t> nativeHashMap;

uint64_t __HASHMAPDATA[] = {

	// 1.46 Crossmap
	// Made by @ImShotZz - Credits @Revan600
0xd9e3006fb3cbd765, 0x1bfbc1e2615e22fc, // remove_model_hide
0x544810ed9db6bbe6, 0x7235037f1f386609,
0x9b079e5221d984d3, 0x8396dfd3e7e1e0e8, // _0x9b079e5221d984d3
0x46e9ae36d8fa6417, 0x8ed4328770bee4a1, // is_thread_active
0x47efa040ebb8e2ea, 0x10909f5aa0579608, // waypoint_playback_stop_aiming_or_shooting
0xc153c43ea202c8c1, 0x36cdbd83df514ac4, // _does_door_exist
0x2245fe4bed318b8, 0x8a7f864dab908749, // has_additional_text_loaded
0xf03755696450470c, 0x4d9da18ab3c2a466,
0xee53b14a19e480d4, 0x2873410b0c800927,
0xf92099527db8e2a7, 0xc36688699e88d7a9, // _0xf92099527db8e2a7
0xccd078c2665d2973, 0xa020e766c7aafb77, // _0xccd078c2665d2973
0x13a80fc08f6e4f2, 0xdefb5e2e5cbd460a, // start_audio_scene
0x6cd79468a1e595c6, 0xeabba3f8727c0fe7, // _0x6cd79468a1e595c6
0xb6e6fba95c7324ac, 0x1abc36611cbe0e84, // _set_door_ajar_angle
// 0xaebf081ffc0a0e5e, 0x0,
0xf271147eb7b40f12, 0x4d5f3407f1f37e28, // get_vehicle_body_health
// 0x5068f488ddb54dd8, 0x0,
0x655b91f1495a9090, 0x148e92e2b2454bc6,
// 0x330ed4d05491934f, 0x0, // network_session_enter
0x416b62ac8b9e5bbd, 0xc69e0417eae41394, // get_vehicle_waypoint_target_point
0xba9775570db788cf, 0xa4d5fc7c4aaafd7c,
0xdccfd3f106c36ab4, 0x5cb6d04db0945eb7, // is_player_free_for_ambient_task
0x477d5d63e63eca5d, 0xe7a95202bf2383f, // simulate_player_input_gait
0xd40148f22e81a1d9, 0x4fa24ef930189eca, // is_vehicle_attached_to_cargobob
0xbb6f1caec68b0bce, 0xae949fbd474d8c74, // set_vehicle_radio_loud
0xee5d2a122e09ec42, 0xcc9a41dd2cd0c58b, // would_entity_be_occluded
0xbcbf4fef9fa5d781, 0xdb7a20748c5e6ef3, // can_register_mission_peds
0x18f621f7a5b1f85d, 0x318f372a7af1eefb, // set_nightvision
0x42156508606de65e, 0xd7e7db1f90914ae9, // _set_third_person_aim_cam_near_clip
0xefacc8aef94430d5, 0x36debf67fd66a599, // _transition_from_blurred
0xdffcef48e511db48, 0x9620e1eb3cfcb8b7, // _0xdffcef48e511db48
0x608207e7a8fb787c, 0xdf6dc9a9113951a5, // set_all_low_priority_vehicle_generators_active
0x55bf0ac0c34f4fd, 0xc88d742adbae062c, // get_random_vehicle_model_in_memory
0x50085246abd3fefa, 0x3e282335477723ec, // clear_floating_help
0xe04b48f2cc926253, 0xbbc0b8e2f3d2eeec, // set_ped_paths_back_to_original
0x759299c5bb31d2a9, 0xbe3e1cafd66994b8, // _0x759299c5bb31d2a9
0x1930dfa731813ec4, 0x598cacc0d6ec2645,
0x90a09f3a45fed688, 0xa7772238da986e33, // is_ped_being_arrested
0x67a5589628e0cff6, 0x67e385fad2957ef2,
0x4008edf7d6e48175, 0x4f0bd5cf38878e96, // _0x4008edf7d6e48175
0x75d3691713c3b05a, 0x1bc2b60a3ecc3dd7,
0x88578f6ec36b4a3a, 0x251c98beb8e8161e, // _0x88578f6ec36b4a3a
0x158ec424f35ec469, 0x19196040b344798f, // _0x158ec424f35ec469
0x61a3dba14ab7f411, 0x4b94ea4f20951105, // attach_cam_to_ped_bone
0x29961d490e5814fd, 0xe0f5041aada12b1c, // set_player_lockon_range_override
0x98a4eb5d89a0c952, 0x5d98d654cdc2165a, // has_model_loaded
0xc7abcaca4985a766, 0xb07c5277d109e240, // prepare_synchronized_audio_event
0x344f393b027e38c3, 0x549c3845d2c45a5, // freeze_radio_station
0xf133bbbe91e1691f, 0x1851e897858b61fd, // is_move_blend_ratio_walking
0x6ea101606f6e4d81, 0xedabe00011531589,
0x9cd43eee12bf4dd0, 0x31f644ea9f9ccc1a, // add_entity_icon
0x39246a6958ef072c, 0xe9c932db3dde6db7, // task_seek_cover_to_coords
0x567384dfa67029e6, 0x88c4de9d30b921aa,
0x995a65f15f581359, 0xd8987a612e450e2b, // network_spent_robbed_by_mugger
0x7f08e26039c7347c, 0xd4852608038dc5f6, // was_ped_killed_by_takedown
0xdcfb5d4db8bf367e, 0x1a2693c8ad793668, // _0xdcfb5d4db8bf367e
0xa2fabbe87f4bad82, 0x3f320d30ce85293b, // detach_cam
0x3133b907d8b32053, 0xc61a66b51690706d, // _0x3133b907d8b32053
0xc5f68be9613e2d18, 0x848c95091f9ecb9, // apply_force_to_entity
0xc2f84b7f9c4d0c61, 0x3ff1b191d160bad1, // stat_set_current_posix_time
0x5983472f0494e60, 0xec46b8a749db209f, // create_incident_with_entity
0x8a9ba1ab3e237613, 0xc8f93d36f11f7be8,
0x8db296b814edda07, 0xbec6c06c290982d0,
0xc4ea073d86fb29b0, 0x657046d7b5023c3b, // has_anim_set_loaded
0x1a092bb0c3808b96, 0xe231caa30dc79fc2, // _0x1a092bb0c3808b96
0xd3a10fc7fd8d98cd, 0x944eb76c2728d7a3,
0x6b3c4650bc8bee47, 0x4941587a59024e36, // set_text_right_justify
0x407f8d034f70f0c2, 0xaae8071e391cb646, // _array_value_add_vector3
0xb48fced898292e52, 0x4accc545aba180ac, // _get_des_object
0x36dd3fe58b5e5212, 0x74c034eac144ccb7, // add_explosion_with_user_vfx
// 0xab13a5565480b6d9, 0x0, // _0xab13a5565480b6d9
0x15a522136d7f951, 0xfaf00ec53d4815fe, // get_ammo_in_ped_weapon
0xac8c7b9b88c4a668, 0xea54fc70893db8ba,
0xb309ebea797e001f, 0xa6477b11ff619f49, // _0xb309ebea797e001f
0x80ec114669daeff4, 0xb767426878b17869,
0xcd015e5bb0d96a57, 0xcca49caf391d1a15, // end_text_command_display_text
0xf4435d66a8e2905e, 0x52938f910bfdebda,
0x38d5b0febb086f75, 0x5ce84bd41cbc95bb, // network_get_presence_invite_handle
0x1f4ed342acefe62d, 0x9ea78777174de734, // network_fade_in_entity
0xbb8de8cf6a8dd8bb, 0x69267f2bcc4caf14, // reset_ped_last_vehicle
0x244f70c84c547d2d, 0xd0aaa345e1fd34ca, // waypoint_playback_resume
0x308f96458b7087cc, 0x47c62181f8dd90d6, // _0x308f96458b7087cc
0x1ee7d8df4425f053, 0x6bfa9158a12cc006, // _0x1ee7d8df4425f053
// 0x5006d96c995a5827, 0x0, // _expand_world_limits
0x614da022990752dc, 0x41aad0031d053a00, // set_ped_shoot_rate
0x6b07b9ce4d390375, 0xa60a51a355a5cbc1, // _network_block_kicked_players
0x8785e6e40c7a8818, 0xab810eae07038a51, // is_driveby_task_underneath_driving_task
0x2afd795eeac8d30d, 0xa30ed2722a26eefc, // set_garbage_trucks
0xe44a982368a4af23, 0xb2ec6f28d6d4a25a, // _0xe44a982368a4af23
0x4fbacce3b4138ee8, 0x2adcdd5710dd5a07, // is_ped_being_stunned
0xb124b57f571d8f18, 0x4a5cdd2be8070a7f, // network_clan_player_is_active
0x601736cfe536b0a0, 0x6d2eb365ec51f891, // task_sky_dive
0x76d683c108594d0e, 0x67bcd927176f31b0, // set_horn_enabled
0x364df566ec833de2, 0x9ded39101e732cea, // set_ped_capsule
0xd62a67d26d9653e6, 0xa70f5bb55d0343e6, // request_script_with_name_hash
0x93d9bd300d7789e5, 0xb40411faddca9cc8, // set_vehicle_door_shut
0x8b5fadcc4e3a145f, 0xb7183f7564696517, // _array_value_get_object
0x63bb75abedc1f6a0, 0xae6b215b3ac34290, // set_mp_gamer_tag_visibility
0xc55a0b40ffb1ed23, 0xc56c31f4513304e8,
0xe46a3fcbde2a1b1, 0xa0b8c2d60705843c, // set_entity_max_speed
0x565e430db3b05bec, 0xaca1a60306a949f6, // _network_player_is_cheater
0x57a25cfcc9db671, 0xfcfde20d8a7c151b, // waypoint_playback_start_shooting_at_coord
0xb6871b0555b02996, 0x1902af62862a56cd, // _0xb6871b0555b02996
0x7792424aa0eac32e, 0x31ed4d527db1269d,
0xba5eceea120e5611, 0x50a231e493ecb642, // set_zone_enabled
0x16ec4839969f9f5e, 0xb05ebd564c7a1480, // is_cop_ped_in_area_3d
0xd9d2cfff49fab35f, 0x71ec91ba8c88bce0,
0xb96b00e976be977f, 0xc9aca82a6f7019a7, // _set_current_intensity
0x9438f7ad68771a20, 0xd17b6c48b7a93ec1, // skip_time_in_playback_recorded_vehicle
0x145f696aaaad2e4, 0xd83c9f072d059cc4, // has_streamed_texture_dict_loaded
0xe5c0cf872c2ad150, 0x8fcbb2ec6e427d58,
0xa5e78ba2b1331c55, 0xeaa05a9fd0b77a1c, // display_ammo_this_frame
// 0x9bddc73cc6a115d4, 0x0, // _0x9bddc73cc6a115d4
0xf9b8f91aad3b953e, 0xedfc3488bb017053, // set_ped_defensive_sphere_attached_to_ped
0xdf97cdd4fc08fd34, 0x833138fbc55273f7, // _0xdf97cdd4fc08fd34
0x55df6db45179236e, 0x963dc7339180c32b,
0x2fa133a4a9d37ed8, 0xd49d32559a1a6e45, // _set_vehicle_door_can_break
0xd125ae748725c6bc, 0x860de2971f678b0, // is_ped_ducking
0x867365e111a3b6eb, 0x321808b6a32cca20, // has_achievement_been_passed
0x1fc289a0c3ff470f, 0x291ddd464ac1190f, // _0x1fc289a0c3ff470f
0x71a5c1dba060049e, 0xc4c169622f69b7b0, // _set_ped_face_feature
0xf9d02130ecdd1d77, 0x39060c0b0edee4bd, // _set_camera_range
0x726256cc1eeb182f, 0x1400da3cd323b316, // clear_facial_idle_anim_override
0x295d82a8559f9150, 0x77b889f505926e0, // set_entity_motion_blur
0x10c2fa78d0e128a1, 0x51bfcf6074916597, // register_enum_to_save
0x6462a961e94b67c, 0xe83363ba15ebdc50,
0x76bf03fadbf154f5, 0x7bf59ee8c8208a29,
0x1f9fb66f3a3842d2, 0x59a5b7dd7120ba03, // _0x1f9fb66f3a3842d2
0x34e82f05df2974f5, 0x2663979b26e8b87e, // get_screen_coord_from_world_coord
0xf6af6cb341349015, 0x95b959f18401c09a, // get_vehicle_doors_locked_for_player
0x71b0892ec081d60a, 0xfa4cf8cc5059360b, // set_vehicle_explodes_on_high_explosion_damage
0x51210ced3da1c78a, 0xd4b4f68f3449cbec, // is_entity_in_angled_area
0x673ed815d6e323b7, 0xa4b2d4c8aa14d701, // _0x673ed815d6e323b7
0x94495889e22c6479, 0xa2f0ea9ab6142d97, // is_ped_on_any_bike
0x48c2bed9180fe123, 0xf7e6c8c5bd75e317, // get_entity_attached_to
0x6b1de27ee78e6a19, 0xeef6ab6169ee0f5e, // _0x6b1de27ee78e6a19
0x198f77705fa0931d, 0x1c86bd57d4dab0d3, // set_focus_entity
// 0x1b2366c3f2a5c8df, 0x0,
0x152d90e4c1b4738a, 0x1ef4bf6b1a42aba7, // _0x152d90e4c1b4738a
0xb8322eeb38be7c26, 0x95f023d6893b5cc0, // set_balance_add_machines
0xd77edadb0420e6e0, 0x140c08484208a7f0, // fade_decals_in_range
0x8edf950167586b7c, 0x4af4743d9bab178b, // add_patrol_route_node
0x27561561732a7842, 0x4f6a06f27f1f391b, // get_number_of_ped_drawable_variations
0x50b196fc9ed6545b, 0x541925e49dba82e9,
0x8c90fe4b381ba60a, 0xd8c2570e7c7759f6, // is_object_near_point
0x2a179df17ccf04cd, 0xb073db452891dc0b, // clear_additional_text
0xdd19fa1c6d657305, 0x40ef19475e844ce3, // remove_particle_fx_in_range
0x6f79b93b0a8e4133, 0xec566f0d860729d3, // network_is_handle_valid
0x6e8834b52ec20c77, 0xc035e897edde5afa, // set_player_can_do_drive_by
0x31d16b74c6e29d66, 0xf1cfa0046bb67893, // remove_scenario_blocking_area
0xc15b0e443b2349d, 0x5aa3937c0625b549,
0x9134873537fa419c, 0xb4185a89b91b3c53, // is_ped_in_flying_vehicle
0x3f69145bba87bae7, 0xc69f0e93d95e37fc, // get_ped_money
0xd68a5ff8a3a89874, 0x6dc7cba4fe2b0af8, // _0xd68a5ff8a3a89874
0x71c33b22606cd88a, 0xfe7877db9db46613, // network_is_gamer_talking
0x56a3b51944c50598, 0xb6fe237b648e60b4, // network_receive_player_jobshare_cash
0x3f2023999ad51c1f, 0x416c37c19cce0077, // is_bullet_in_area
0xf0bc12401061dea0, 0x5b948815b881fb6b, // is_projectile_type_in_angled_area
0x7c9c91ab74a0360f, 0x1256e5ea03020804, // get_hud_colour
0x6dd05e9d83efa4c9, 0x79d896a612d00806, // _set_mp_gamer_tag_color
0xc3b07ba00a83b0f1, 0x96122a1648e7bf43, // set_widescreen_format
0x534aeba6e5ed4cab, 0x82c50dfcb0299f4c, // get_active_vehicle_mission_type
0xc5f0a8ebd3f361ce, 0x29074975f22a27b9, // _set_unk_map_flag
0x77b612531280010d, 0x8871859ef0ab8004,
0x8927cbf9d22261a4, 0xb92c3c556226e8f9, // atan2
0xff2862b61a58af9, 0xdc7925edaac33878, // _0x0ff2862b61a58af9
0x1f13d5ae5cb17e17, 0x276149cffb30eade, // get_num_reserved_mission_peds
0x996dd1e1e02f1008, 0xfa5246ae06dcbf35,
0xf314cf4f0211894e, 0xfa923a5cdffa4422, // _set_hud_colour
0xdeaaf77eb3687e97, 0xdebee396d4f453f5, // _0xdeaaf77eb3687e97
0x1837af7c627009ba, 0xe4d75345359ad13c, // set_vehicle_friction_override
0xd2d57f1d764117b1, 0x40ac0b9efcb6a65b,
// 0x5a4a6a6d3dc64f52, 0x0, // task_ped_slide_to_coord_hdg_rate
0x9afeff481a85ab2e, 0x1ca155ec47f3aebb, // set_ped_coords_keep_vehicle
0x1a8b5f3c01e2b477, 0x7e480c68737c0b83, // is_bullet_in_angled_area
0x7b5280eba9840c72, 0x434854e9cae13c4a, // _get_label_text
0x40f7e66472df3e5c, 0xe49c5b34f3e3055, // _0x40f7e66472df3e5c
0x9a73240b49945c76, 0xef4753434b24594d,
0x430386fe9bf80b45, 0x8ccc0a0504c52531,
0x3be0bb12d25fb305, 0xfb0da5436d45fdef, // get_weapon_damage_type
0x51f0feb9f6ae98c0, 0x68d5c2596d103ea7, // get_mod_slot_name
0x83961498679dc9f, 0xbeea641ee4f42dbd, // is_any_ped_near_point
0x5b7a89bd78797fc, 0x30b9fcf52baaeb11, // get_interior_at_coords_with_type
0xec03c719db2f4306, 0xe7099b1a79d501b1, // network_spent_carwash
0xd3f2ffeb8d836f52, 0xc861eb0a567b2235, // _array_value_get_string
0xc1e8a365bf3b29f2, 0x41e36a540f8f323f, // set_ped_reset_flag
// 0xb5cc40fbcb586380, 0x0, // _is_vehicle_siren_sound_on
0x9c0403ed9a751c2, 0xd5f57dabde4be28f, // _0x09c0403ed9a751c2
0x80ead8e2e1d5d52e, 0x21a61420bf35a0e9, // add_text_component_substring_blip_name
0xe851e480b814d4ba, 0xa3f615b115f0305e, // _0xe851e480b814d4ba
0x1218e6886d3d8327, 0xa4e357abbef712c9, // is_entity_static
0x9f3480fe65db31b5, 0x140d4a6561e11695, // set_ped_as_group_member
0xa2c6fc031d46fff0, 0x5009a219b22d2352, // get_time_difference
0x5fff4cfc74d8fb80, 0xa5c8d37514acc1fa, // is_ped_in_any_plane
0x5270a8fbc098c3f8, 0x34db0ac28a1fde20, // is_projectile_in_area
0x1ad5b71586b94820, 0x91151e1f0a759b4f, // _0x1ad5b71586b94820
0x9a41cf4674a12272, 0xfc234596ed1aed40,
0x943e5b8e078e76e, 0xdc3500d83e19b1d6, // clear_ped_prop
0x4319e335b71fff34, 0xfc5b5cff164247db, // is_vehicle_alarm_activated
0x1b84df6af2a46938, 0xf8e1de22deb7e100, // network_get_participant_index
0xe3a3db414a373dab, 0x94a8b1d385430451,
0xed3f346429ccd659, 0x9de409ee898c6e2d, // remove_decal
0xc82630132081bb6f, 0xea53eede31477017, // network_member_id_from_gamer_handle
// 0x3442775428fd2daa, 0x0,
0x8389cd56ca8072dc, 0x7bc172c1973d1722, // get_vehicle_custom_secondary_colour
0x7d5dabe888d2d074, 0x660bc449336f0502, // get_vehicle_petrol_tank_health
0xec6935ebe0847b90, 0x7134cb98764ec541, // _0xec6935ebe0847b90
0x32dd916f3f7c9672, 0xee0efb638a85eb6b, // _0x32dd916f3f7c9672
0x42fdd0f017b1e38e, 0x9334d6ffe155018f, // get_ped_relationship_group_default_hash
0xb743f735c03d7810, 0xdcac766b866d4a2e, // _0xb743f735c03d7810
0x61cb768363d6424, 0x7a392eeba7436663, // _0x061cb768363d6424
0xac97af97fa68e5d5, 0x53ab2e2c7b8d1e48, // _get_date_and_time_from_unix_epoch
0x3599d741c9ac6310, 0x7d7ba83b811b174, // _0x3599d741c9ac6310
0xf5ed37f54cd4d52e, 0x177fdbe7d68bb089, // delete_checkpoint
0xd57aaae0e2214d11, 0xe67cbbb1404117c2,
0x55e86af2712b36a1, 0xaff9058ff075cfd5, // _enable_interior_prop
0x57fff03e423a4c0b, 0xc87f06df3a5185fe, // set_super_jump_this_frame
0xdb4eacd4ad0a5d6b, 0xd9a84b163d46bd9b, // get_pedheadshot_txd_string
0x9a7d091411c5f684, 0xd6f59240f9f10c5e, // task_warp_ped_into_vehicle
0xb6463cf6af527071, 0xa4e89042a770108e, // is_entity_in_zone
0x6cd5a433374d4cfb, 0xdaaa48ce50d80f52, // _can_ped_see_ped
0xb81f6d4a8f5eeba8, 0x9086ea75889422cd, // set_vehicle_doors_locked_for_team
0x9cfdd90b2b844bf7, 0xe0262ee0d949fa55, // _0x9cfdd90b2b844bf7
0x292564c735375edf, 0xd424d2c37cd3336,
// 0x5324a0e3e4ce3570, 0x0, // _0x5324a0e3e4ce3570
0x5ffe9b4144f9712f, 0xb7b36b6be857b203, // use_player_colour_instead_of_team_colour
0x29c24bfbed8ab8fb, 0xfc92fe0912ba37c8, // _0x29c24bfbed8ab8fb
0xe9b99b6853181409, 0xd7682516344962c9,
0x6c6b148586f934f7, 0x39ca484fc4903fcf, // set_global_min_bird_flight_height
0xb60a9cfeb21ca6aa, 0xa04e8db8e71b259f, // get_cam_far_clip
0x9f65dbc537e59ad5, 0x743ec1e3dc1090f3, // is_ped_going_into_cover
0x711327cd09c8f162, 0x611b44656e4a1584,
0x38c16a305e8cdc8d, 0xc0e20fb79bf9680e, // stop_pad_shake
0x31c55ed33227371, 0x4b8496ef792b5ba8, // _object_value_get_type
0x5b1f2e327b6b6fe1, 0x12b2408e6fffe7b9,
// 0x3fd2ec8bf1f1cf30, 0x0, // suppress_shocking_event_type_next_frame
0xe5da8615a6180789, 0x29f342be632acff4, // task_stay_in_cover
0x4b5b4da5d79f1943, 0x7bb05d34eb0cdcc9, // _set_checkpoint_icon_height
// 0x3ca6050692bc61b0, 0x0, // _0x3ca6050692bc61b0
0xfbc5e768c7a77a6a, 0x98242c63711a91c4,
0x88eaec617cd26926, 0x6dd82b6e322cf7e6, // _0x88eaec617cd26926
0x5fbd7095fe7ae57f, 0xad7f551cf4409350, // _0x5fbd7095fe7ae57f
0x6a09d0d590a47d13, 0x29a85bd70bedb01b, // special_ability_lock
0x2fc5650b0271cb57, 0x68edb4a170416007,
0xe3b27e70ceab9f0c, 0xe8c49ce004f363a, // _clear_ped_facial_decorations
0x52818819057f2b40, 0xb8353c13d01e8e38, // _0x52818819057f2b40
0x19af7ed9b9d23058, 0xbca9b529044ec902,
0x8a4986851c4ef6e7, 0xda780a74c4b71784, // set_create_random_cops_not_on_scenarios
0x287f1f75d2803595, 0xece629e063baeb1f, // _0x287f1f75d2803595
0x869daacbbe9fa006, 0x315e728a4bf2a1fd,
0xb5a4db34fe89b88a, 0xce33d92ee61980b3,
0x82e7ffcd5b2326b3, 0xe9d4034837df677c, // set_timecycle_modifier_strength
// 0x7b718e197453f2d9, 0x0, // network_buy_bounty
0xf107e836a70dce05, 0xf1d4d3425a1faf38, // set_ped_id_range
0x9a1b3fcdb36c8697, 0x930fb6cde4b41dd2, // network_start_synchronised_scene
0x3a54e33660ded67f, 0x27ac733f761835e, // network_can_bet
0x2ec0af5c5a49b7a, 0xfaa5c555ed0cec9b, // is_cam_rendering
0x447c1e9ef844bc0f, 0x2e088aa96005f9eb, // task_vehicle_aim_at_coord
0xa018a12e5c5c2fa6, 0x41edd559141ff338, // interrupt_conversation
0x9a62ec95ae10e011, 0x14b71b5ebee445b8,
0xb8fbc8b1330ca9b4, 0x8aa4c81d39275ef3, // _set_vehicle_jet_engine_on
0x33d47e85b476abcd, 0xe1c1e4509805902a, // _0x33d47e85b476abcd
0x5099bc55630b25ae, 0x5efbeab90d78e60, // get_pickup_object
0x4ec6cfbc7b2e9536, 0x4af95d264a0916e4, // get_vehicle_deformation_at_pos
0x236406f60cf216d6, 0x7f4fd9df8f92132b, // network_add_followers
0x4b0311d3cdc4648f, 0x58355301cba19400,
0xbe9b0959ffd0779b, 0xc39b72329fe2f3e8, // get_blip_info_id_type
0x5cee3df569cecab0, 0xb4afad4adef0fcf6, // does_weapon_take_weapon_component
0x245a6883d966d537, 0x453924f2aae93ad9, // set_vehicle_density_multiplier_this_frame
0x524ac5ecea15343e, 0x68481daf84b9654, // is_entity_a_ped
0x2c933abf17a1df41, 0x29b6d8efad395b92, // set_timecycle_modifier
0xe32efe9ab4a9aa0c, 0x76909d790ddfdce9, // play_synchronized_cam_anim
0xc79ae21974b01fb2, 0x7f76e751c3c67971,
0xd9b86b9872039763, 0xa14965140eff1dfd, // network_spent_holdups
0xf511f759238a5122, 0x948c3657c8bdcf3e, // script_is_moving_mobile_phone_offscreen
0xb8ecd61f531a7b02, 0x94a515f253c4267a, // task_go_to_coord_any_means_extra_params_with_cruise_speed
0x6c5ae23efa885092, 0x4769bf076894e691, // stop_ped_ringtone
0xe3e2c1b4c59dbc77, 0xb01645ecf87d883f, // _0xe3e2c1b4c59dbc77
0x3910051ccecdb00c, 0xfe8201efb515d77b, // _set_entity_something
0x6c188be134e074aa, 0xd61e5ed1d4e687a5, // add_text_component_substring_player_name
0x6cc27c9fa2040220, 0xf29c37cb006ae9dd,
0x271017b9ba825366, 0x7057e4344996ce99, // _0x271017b9ba825366
0x6c3b4d6d13b4c841, 0xe70913441986f324, // set_ped_can_arm_ik
0x261e97ad7bcf3d40, 0x4f8c63ec3c44ac75, // _0x261e97ad7bcf3d40
0x9f7794730795e019, 0x28f648743d7de312, // set_ped_combat_attributes
// 0x7e58745504313a2e, 0x0, // network_is_inactive_profile
0x812595a0644ce1de, 0xe9d7b652961d4aa3, // is_dlc_present
0x2cea2839313c09ac, 0xce6723d95898cce9,
0x552369f549563ad5, 0x73a36a4c1edb618a, // _force_ambient_siren
// 0x3e9bb38102a589b0, 0x0, // network_do_transition_to_game
0x8d68c8fd0faca94e, 0xa3a29db165882310, // is_entity_an_object
0x4a39db43e47cf3aa, 0x65dbb4cda77ffe97, // _0x4a39db43e47cf3aa
0xdb89591e290d9182, 0x175878ee6ae912f7, // get_time_since_player_drove_against_traffic
0xdd902d0349afad3a, 0xc1540ecc5f9bddf4,
0x83bcce3224735f05, 0x88ca3aa820e98af8, // _0x83bcce3224735f05
0x46a6cc01e0826106, 0x876889652bf6f5b5, // task_shoot_at_coord
0xb39786f201fee30b, 0x7334ba59cfe4922, // set_radio_track
0x9fd452bfbe7a7a8b, 0xe809dd2813dadd34, // _get_tattoo_zone
0xca7d9b86eca7481b, 0xd3957903b061a8c8,
0xa097ab275061fb21, 0x20e8b706b4e2babf,
0xe30524e1871f481d, 0xff64d2a8496f701d, // _0xe30524e1871f481d
0xedc1a5b84aef33ff, 0xc93121af532a9255, // get_state_of_closest_door_of_type
0xa10b2db49e92a6b0, 0x87b28bb152797b98, // get_cam_anim_current_phase
0xdcd4ea924f42d01a, 0xf93137a2acf7baa4, // set_widescreen_borders
0x13337b38db572509, 0x33cab544faae661d, // _is_input_just_disabled
0xb824797c9bf2159, 0x4e663d1791e32e5b,
0x1381539fee034cda, 0x82f7b27b2208c2b7, // set_cam_spline_duration
0x6fddf453c0c756ec, 0x952f01f9387b7183,
0xef93e9f3d08c178, 0x493014a3701a3c65, // stop_gameplay_cam_shaking
0xe39b4ff4fdebde27, 0x903d86a54a398682, // task_goto_entity_offset
0x8e06a6fe76c9eff4, 0xdd2afe9a8ecf5e35, // set_ped_path_can_use_climbovers
0xba416d68c631496a, 0xcd41d7b87ef6e67c,
0x28d3fed7190d3a0b, 0x17260b4ea0652e1c, // is_entity_on_fire
0x351220255d64c155, 0xae4810e427ad9203, // enable_control_action
0x967278682cb6967a, 0x27a2c5f2e91f5a15, // _0x967278682cb6967a
// 0x9ff28d88c766e3e8, 0x0, // network_spent_pay_vehicle_insurance_premium
0xca2c8073411ecdb6, 0x4fd606066bcb647c, // network_set_gamer_invited_to_transition
0x21986729d6a3a830, 0x74ab4b97208b4cc6,
0xa7a1127490312c36, 0x328c8647ac9feed6, // _0xa7a1127490312c36
// 0x64f62afb081e260d, 0x0,
0xc7848efccc545182, 0x6ada542e698077eb, // set_cam_near_clip
0x120364de2845daf8, 0x8f3486fd565cced7, // _0x120364de2845daf8
0xf0a4f1bbf4fa7497, 0xcf7e081f27fe838, // set_ped_ragdoll_on_collision
0x13ad665062541a7e, 0x296fee33e6a2157a, // override_trevor_rage
0x28004f88151e03e0, 0xf434f252df55d532, // stop_entity_anim
0xeeb64139ba29a7cf, 0x2a7958a2e0496b2, // set_ped_dies_instantly_in_water
0xf2eab31979a7f910, 0x8cf360bbbd42762d, // task_hands_up
0x7277f1f2e085ee74, 0x9907fb1f75c1a914, // can_register_mission_vehicles
0x83f28ce49fbbffba, 0x51d2c61ffb4872c9, // _0x83f28ce49fbbffba
0x58fce43488f9f5f4, 0x67eb575efccb9ad1,
0xd86d101fcfd00a4b, 0x45c6e26b40e7f5ef, // _reset_ped_ragdoll_blocking_flags
0x53afd64c6758f2f9, 0x9294f570d6d6a061,
0xf2f6a2fa49278625, 0x93a28bfa046ed31, // _0xf2f6a2fa49278625
0x95d9f4bc443956e7, 0x83e0b9f1391440c9, // add_ped_to_conversation
0x5e29243fb56fc6d4, 0x2e68b0f85993946b, // clear_relationship_between_groups
0x960c9ff8f616e41c, 0x9ba2e2e65b12c39b, // display_help_text_this_frame
0x1cea6bfdf248e5d9, 0xaed1f3230e36a119, // is_control_enabled
0x71bdb63dbaf8da59, 0x44e288d136fad2fd, // set_minimap_golf_course
0x14922ed3e38761f0, 0x364e483d067a314a,
0x814c9d19dfd69679, 0x811759b11ba35221, // get_max_range_of_current_ped_weapon
0xf1307ef624a80d87, 0x63151314b8b4d6eb, // _get_aspect_ratio
0x5dc40a8869c22141, 0xc320800073f03d4d, // _0x5dc40a8869c22141
0x9ccc9525bf2408e0, 0x26fd410baceddb8b, // get_vehicle_plate_type
0x40afb081f8add4ee, 0x7971758ce6d9f156, // _return_two
0x1093408b4b9d1146, 0x9a132cf89e5d0c95, // _0x1093408b4b9d1146
0x9b62392b474f44a0, 0xb3fcfee10111abed, // create_random_ped_as_driver
0x77f1beb8863288d5, 0xd76d6bcc14b95ce1, // get_script_task_status
0x9a75585fb2e54fad, 0x40df010a0815e0a, // _0x9a75585fb2e54fad
0xcbf12d65f95ad686, 0x9af76919b02033c0, // network_set_talker_proximity
0xe38e9162a2500646, 0x3de306309922f8d1, // get_num_vehicle_mods
0x6d8eb211944dce08, 0x294d14ee061a66fd, // set_scaleform_movie_to_use_system_time
0x86e0660e4f5c956d, 0x2ce182d6d4547051,
0xbf1a602b5ba52fee, 0x496be3dba113d228, // set_roads_in_area
0x3270f67eed31fbc1, 0x83c067b4dc60ba06, // _0x3270f67eed31fbc1
0xd5e460ad7020a246, 0xc0911d7961156d23, // set_player_can_be_hassled_by_gangs
0xf5f6378c4f3419d3, 0x493912b04ea384eb, // set_ped_max_health
0x3eed80dff7325caa, 0x514f49e17636419, // hide_special_ability_lockon_operation
0xdfd5033fdba0a9c8, 0x1235b764f6c5379b, // has_entity_been_damaged_by_any_vehicle
0x6e575d6a898ab852, 0x281f3c55c2638ac, // is_ped_in_any_taxi
0xaf348afcb575a441, 0xd219f857f67deaba, // _0xaf348afcb575a441
0x3317dedb88c95038, 0xdfb97818ad6c09cc, // is_ped_dead_or_dying
0x5ce587fb5a42c8c4, 0xad99bb486392f937, // leaderboards2_read_by_radius
0x2ce056ff3723f00b, 0xf6ecf3b61557bdb3, // stat_get_number_of_seconds
0x5ae17c6b0134b7f1, 0xff29843c6711c395,
0x7cce5c737a665701, 0x5ebff603912491c2, // leaderboards_read_clear
0xe374c498d8badc14, 0x614b77e15f87084e, // hide_scripted_hud_component_this_frame
0xa3f3564a5b3646c0, 0xa448db70453df6a8, // _0xa3f3564a5b3646c0
0xfb18df9cb95e0105, 0xebbe9fffe2328927, // network_give_player_jobshare_cash
0x26e1cd96b0903d60, 0x79a4dcb5325955ad, // network_get_presence_invite_session_id
0x2fdff4107b8c1147, 0x6ecb6fc67cc8cc48, // slide_object
0x19f2a026edf0013f, 0x7ca951d4d3a0d1ad, // get_shop_ped_outfit_component_variant
0x58fadded207897dc, 0x9c071fe7c7ebfefa, // set_minimap_block_waypoint
// 0x83f7e01c7b769a26, 0x0, // apply_ped_blood
0xce58b1cfb9290813, 0x451fca12b4c44bf,
0x77a5b103c87f476e, 0x734f1c6e754d9474, // set_ped_path_can_use_ladders
0xb8eb95e5b4e56978, 0xbef03c6751e44cb4,
0x4b5ae2eee4a8f180, 0x1322c21eeb842b90, // unpin_rope_vertex
0xf086ad9354fac3a3, 0xa4d1abfd08fc5015, // _0xf086ad9354fac3a3
0x9724fb59a3e72ad0, 0xaa39add6c36e5a2e, // update_task_aim_gun_scripted_target
0x42e4b70b93e6054, 0x385a6e03336a8550,
0xf6c09e276aeb3f2d, 0xb1d0d338d38fbd61, // link_named_rendertarget
0xf66a602f829e2a06, 0xff2dea68e2d3602e, // remove_anim_dict
0x20ac25e781ae4a84, 0x9505857bb7896ad2,
0x494c8fb299290269, 0xb3d3ee75fe0655b0, // network_add_entity_area
0x715135f4b82ac90d, 0xbd8c91725d5d54c0, // _0x715135f4b82ac90d
0x710311adf0e20730, 0x7fc263d448dc8cac, // activate_physics
0x9222f300bf8354fe, 0xf081a5b81c8b1c8a, // register_hated_targets_around_ped
0x4c61c75bee8184c2, 0x36d865fc91b4c899, // _0x4c61c75bee8184c2
0xfc859e2374407556, 0xcf5490505b6d51be,
0x341de7ed1d2a1bfd, 0xea26831785699c09, // _is_tag_restricted
0x102d125411a7b6e6, 0xb0705228ef9b005f, // get_total_duration_of_vehicle_recording_id
// 0x6d3a430d1a809179, 0x0, // network_spent_buy_passive_mode
0xe787bf1c5cf823c9, 0x39e9eb9ac1178322, // set_noiseoveride
0xc3675780c92f90f9, 0x2a51383f28e775ca, // attach_entity_to_entity_physically
0xf538081986e49e9d, 0x765f7f4bf11748c, // set_force_object_this_frame
0x7d7d2b47fa788e85, 0x9d135fcb3e3cc96a, // waypoint_playback_override_speed
0x2ca429c029ccf247, 0xddf57f769fd85704, // _load_interior
0x24409fc4c55cb22d, 0x389108f07cf085a2, // _0x24409fc4c55cb22d
0x8f719973e1445ba2, 0xe66521afbb17ac59, // _0x8f719973e1445ba2
0xfead16fc8f9dfc0f, 0xfe62afd89e9fed89, // _get_free_stack_slots_count
0x7a5487fe9faa6b48, 0x78dcc5d0cb43deba,
0xc2ee020f5fb4db53, 0xba1fed9fc19036cc, // _0xc2ee020f5fb4db53
0x826aa586edb9fef8, 0x5c415d10d5cbf689, // is_ped_sitting_in_any_vehicle
0x85f462badc7da47f, 0x671b852fe3a6cc02, // add_vehicle_subtask_attack_ped
0xf46cdc33180fda94, 0x12772fc739a13f81, // get_weapontype_model
0x816562badfdec83e, 0x64649c2df7b1dfdc, // set_vehicle_mod_color_2
// 0x82a3d6d9cc2cb8e3, 0x0, // set_ped_cloth_prone
0xaa295b6f28bd587d, 0xb20795cdb13cae4f, // _draw_notification_award
0x14f19a8782c8071e, 0x922453713201594a, // set_scenario_peds_to_be_returned_by_next_command
0x43865688ae10f0d7, 0x629526c58537ab41,
0xf07e7745a236711, 0x3de34b8864800b14,
0x24e4e51fc16305f9, 0xa82c0412d2b0e64d,
0xe43a13c9e4cccbcf, 0x95eb51ae3552bcac, // _0xe43a13c9e4cccbcf
0xe532f5d78798daab, 0x71ca80d41e1338b4, // set_model_as_no_longer_needed
0xc3376f42b1faccc6, 0xe92f0e313f2856a7, // _0xc3376f42b1faccc6
0xca4ae345a153d573, 0xa2f8f0835cc1899d, // _0xca4ae345a153d573
0xa2c1f5e92afe49ed, 0xbddc4623f4198271,
0x900086f371220b6f, 0x984ea185f9510be6, // _0x900086f371220b6f
0xa5ffe9b05f199de7, 0xdbf747ff76d31c20, // enable_all_control_actions
0xd6d09a6f32f49ef1, 0x746cdef5db7a4e20, // _network_session_is_player_voted_to_kick
0x70a64c0234ef522c, 0x1673ee3f36c67f0f,
0xb3da2606774a8e2d, 0x7e9dfc89709bb7f5,
0x5bc448cb78fa3e88, 0x7b7a3e5cc3fbe978, // task_go_to_coord_any_means
0x3d7fb09e75d6b7e, 0xb9e84a421c105943, // set_blip_colour
0x7718d2e2060837d2, 0x93c1bffd8c824f82, // network_player_get_name
0x71bc8e838b9c6035, 0x8822a7e5068264c6, // resurrect_ped
0x1dd45f9ecfdb1bc9, 0x57fc8a645c1810fd, // task_go_to_coord_any_means_extra_params
0xbc8983f38f78ed51, 0x3d732b99f6301c4d, // force_cleanup
0xb0034a223497ffcb, 0xd9c92b0885a075f8,
0xdba3c090e3d74690, 0xb0a4f7928b78dd26, // _request_vehicle_scaleform_movie
0xa03502fc581f7d9b, 0x28efda4831599410,
0x84f0f13120b4e098, 0xe305c0869bee7b4d,
0x9a294b2138abb884, 0xdd9a603448a23a17, // create_object_no_offset
0x15b8ecf844ee67ed, 0x9fc2a869f7656459, // does_ped_have_ai_blip
0xe21d3df1051399d, 0x9f19cfbf4bd10b36, // detach_vehicle_from_cargobob
0xee21293dad47c95, 0x362ee6c496fa3d80, // get_vehicle_window_tint
0xf434a10ba01c37d0, 0x86fa82a9da72649a, // _0xf434a10ba01c37d0
0x279d50de5652d935, 0xfcc0d6ce886462ff, // _0x279d50de5652d935
0xc0c527b525d7cfb5, 0xca46a19fb7000be6, // _array_value_get_float
0xacb5dcca1ec76840, 0xaeed1b983783f3b3, // _get_vehicle_horn_hash
0xdc48473142545431, 0x8c3d5f9d70af1ad2,
0x3e933cff7b111c22, 0x1816d3ddd9d0fe59, // is_vehicle_door_fully_open
0x55aa95f481d694d2, 0xb5fe01de5342ed95, // _get_content_id
0x9ba001cb45cbf627, 0x20f6311890a35a07, // _0x9ba001cb45cbf627
0x846bf6291198a71e, 0xc88d23e28da9ee6c, // _get_entity_physics_heading
0x4f8a26a890fd62fb, 0x2eee89525f08c860, // _0x4f8a26a890fd62fb
0x2ce1d6ac0fc73ea, 0x3098d440e766a1dd, // network_earn_from_rockstar
0x442e0a7ede4a738a, 0xd178ef744f20b712,
0xbb6e6fee99d866b2, 0x7a6fe97527e9a6e6, // network_clan_remote_memberships_are_in_cache
0x68e835a1d0dc0e3, 0xa94473fee1796aed, // animpostfx_stop
0x4af92acd3141d96c, 0x5ec1b075c44ef32b,
0x4d953df78ebf8158, 0x57bcedaf14c57bf8,
0x5db660b38dd98a31, 0xaa649ae6bd17a3ac, // set_player_health_recharge_multiplier
0xbfa0a56a817c6c7d, 0xf1c524002e6c95c7, // _0xbfa0a56a817c6c7d
0xf8dee0a5600cbb93, 0x8354079adadd7439, // _set_minimap_revealed
0x6793e42be02b575d, 0x44efdf16ae23d81b,
// 0xbf22e0f32968e967, 0x0, // _network_respawn_player
0xa98fcafd7893c834, 0x2c7a26c1838e0411, // update_task_hands_up_duration
// 0xd9b067e55253e3dd, 0x0, // network_buy_healthcare
0xafc1ca75ad4074d1, 0xeccfcab0a094eb5b, // does_pickup_exist
0x27cfb1b1e078cb2d, 0x970ac7d7f9179e19,
0x9e80a5ba8109f974, 0x86a608bdba7fce83, // network_do_transition_to_new_freemode
0x6b24bfe83a2be47b, 0x4d8a5efbd6acb8d4, // is_cam_shaking
0x4a58a47a72e3fcb4, 0x6377b13f4704663a, // task_guard_current_position
0x2aee8f8390d2298c, 0x2619ca061d2f052, // set_blip_fade
0xdd6cb2cce7c2735c, 0x1c8f7a99e1d52769, // _draw_notification_with_button
0x3bbbd13e5041a79e, 0x8d58d909cd341593,
// 0xd3a9971cadac7252, 0x0, // draw_box
0xcac57395b151135f, 0xcd3435e7c7be1b84, // _0xcac57395b151135f
0xfddb234cf74073d9, 0x8a74f8d0cedfc96a, // remove_ped_preferred_cover_set
0x61a23b7eda9bda24, 0x8e7b9f9d56b99439,
0xf1ca12b18aef5298, 0x6b8fd1d1616ee677, // _network_set_entity_invisible_to_network
0xae1f1653b554ab9, 0xc6013cc233275c04, // _facebook_set_milestone_complete
0x90a38e9838e0a8c1, 0xdd86272c593a9d9c, // get_vehicle_mod_modifier_value
0x31b927bbc44156cd, 0x9152a6430680bf0a, // set_vehicle_is_considered_by_player
0xe67c6dfd386ea5e7, 0x9458b71bc1e88779, // _0xe67c6dfd386ea5e7
0x19d8da0e5a68045a, 0x2fc47f84a140195c,
0x2f137b508de238f2, 0xf2c2ab090a8bc16d, // _0x2f137b508de238f2
0x4cffc65454c93a49, 0xba3b59e967441c4, // _set_ped_hair_color
0xc197616d221ff4a4, 0x4abb9ef39da515d7,
0xd8d19675ed5fbdce, 0xa75de3df9d3d284, // clear_ped_alternate_movement_anim
0xe861d0b05c7662b8, 0xacdbff0189f77062, // _0xe861d0b05c7662b8
0x46494a2475701343, 0x75c2cac63db7654e, // _0x46494a2475701343
0xa38dcffcea8962fa, 0xec730a4395ba7f81, // get_max_ammo_in_clip
0xe495d1ef4c91fd20, 0x36d5183a1158c307, // get_vehicle_cause_of_destruction
0xc847b43f369ac0b5, 0x20ea2e53ddddb234,
0x290f35c0ad97864, 0x6a7644aa958747cc, // is_cam_spline_paused
0xc158d28142a34608, 0x6b967a72028ada75, // stop_ped_weapon_firing_when_dropped
0x3a815db3ea088722, 0xc69dd20c20c463e6, // is_scenario_type_enabled
0xc7827959479dcc78, 0x371ecbec27af4be, // network_get_entity_is_networked
// 0xb9cfd27a5d578d83, 0x0, // network_session_host_friends_only
0x3f5cc444dcaaa8f2, 0x56409eb0aae02110, // _0x3f5cc444dcaaa8f2
0x7497d2ce2c30d24c, 0xa30f14b621e3269d,
0x21e253a7f8da5dfb, 0x413f5770d259c876, // _0x21e253a7f8da5dfb
0x7f1be2bccaa27a7, 0x5d19bf64e3ac6863, // find_anim_event_phase
0xdf02a2c93f1f26da, 0xe0c12bcc1ef902bd, // network_am_i_muted_by_gamer
0x48838ed9937a15d1, 0x51572297799d4291, // set_dispatch_time_between_spawn_attempts_multiplier
0x755d6d5267cbbd7e, 0x10ed0d9ec9296972, // _are_propellers_undamaged
0xbdecf64367884ac3, 0x85961bf1c6552672, // stop_cam_shaking
0x323f647679a09103, 0x46b18935fdc07b35, // get_decal_wash_level
0xf75b0d629e1c063d, 0x94626c0798ae1f8, // set_ped_into_vehicle
0xec51713ab6ec36e8, 0x10b8b8286bbb62a4, // set_network_vehicle_respot_timer
0x8093f23abaccc7d4, 0x1790b816b917d10e, // set_cutscene_fade_values
0x5728bb6d63e3ff1d, 0x1ecddc517193dd19, // network_mark_transition_gamer_as_fully_joined
0xd1032e482629049e, 0xb1fd891620f7745, // _0xd1032e482629049e
0x730f5f8d3f0f2050, 0x4c12203504063e31, // set_entity_render_scorched
0x761b77454205a61d, 0xc45da56d614d2498, // _add_text_component_app_title
0xa74a541c6884e7b8, 0x31f16ab3b7e2e9a2, // set_srl_time
0xf9d9f7f2db8e2fa0, 0x1d384ba3b0d163c2, // get_ped_combat_range
0xf1f8157b8c3f171c, 0xe0d6519438f34544, // _0xf1f8157b8c3f171c
0x367b936610ba360c, 0xfc00f22e930bfd55, // net_to_veh
0xcf463d1e9a0aecb1, 0x5e692e6c0fd48e1, // detach_portable_pickup_from_ped
0x593850c16a36b692, 0xe8917592107a062a,
0x163e252de035a133, 0xcd1edcb38767b47c, // _get_object_offset_from_coords
0x1a8e2c8b9cf4549c, 0xa9f7b2f12f21d79f, // _0x1a8e2c8b9cf4549c
0x82377b65e943f72d, 0xbbe4600873c65633, // _0x82377b65e943f72d
0x7c2ac9ca66575fbf, 0xbfcf1429b1dc83c2, // get_ped_stealth_movement
0x6170941419d7d8ec, 0x9a046caf0798327b, // disable_interior
0x19464cb6e4078c8a, 0x816788e0ca50bb83, // set_follow_vehicle_cam_zoom_level
0x8a35c742130c6080, 0x2afe1c81f4d74bee, // _override_decal_texture
0xe64a3ca08dfa37a9, 0xdbb7d36074c0b9bb, // _0xe64a3ca08dfa37a9
0x3311e47b91edcbbc, 0xb957ad9b5155a2e4, // apply_ped_blood_by_zone
0xfc1e275a90d39995, 0xba12ba352ffffcdf,
0x4f14f9f870d6fbc8, 0x854e8b95ce1c5d29, // decor_is_registered_as_type
0xac678e40be7c74d2, 0x21a4e034efc28450, // clear_entity_last_weapon_damage
0xe8af77c4c06adc93, 0xddb55beb9d76717d,
0xc2d15bef167e27bc, 0xcb088a853bc66809,
0x57e4c39de5ee8470, 0x8edbe29feab08840, // does_vehicle_have_stuck_vehicle_check
0xb1fa61371af7c4b7, 0x63b8af155fc68cd7, // give_weapon_object_to_ped
0xa6e7f1ceb523e171, 0x1c4c0ff903f4c757, // get_number_of_ped_prop_texture_variations
0x12b6281b6c6706c0, 0x2bd84c5844b4a89d, // _0x12b6281b6c6706c0
0x37ebbf3117bd6a25, 0x9cf9beb99beb3a83, // _set_vehicle_forklift_height
0x213b91045d09b983, 0x9499aacaf0452a29, // get_entity_rotation_velocity
0xbb779c0ca917e865, 0x25e480e1b3cee87c, // set_mobile_phone_rotation
0x4811bbac21c5fcd5, 0x98a27947ffd9bbdf, // _0x4811bbac21c5fcd5
0x4d79439a6b55ac67, 0xfac8f20fbc764f4d,
0x82ebb79e258fa2b7, 0x576963ea28e5bd52, // _0x82ebb79e258fa2b7
0x33c0f9a64e229ae, 0x85f91f38af4ded49, // remove_model_swap
// 0x2bf66d2e7414f686, 0x0,
0xb938b7e6d3c0620c, 0x9bf09af4e34a2e6c, // set_credits_active
0xeaa0ffe120d92784, 0x1c95cd840303fc37, // set_blip_name_from_text_file
0x17ad8c9706bdd88a, 0x111bcb502f280084, // _0x17ad8c9706bdd88a
0x556c1aa270d5a207, 0x1c51d7f2678bafeb, // delete_incident
0x953da1e1b12c0491, 0xa62924207648ed33, // set_vehicle_deformation_fixed
0x517aaf684bb50cd1, 0x89f592de615a3f69, // set_vehicle_doors_locked_for_player
0xf73eb622c4f1689b, 0xacc2d6d9762c28bb, // get_closest_vehicle
0x9ff447b6b6ad960a, 0xc8a447e7f01b331e, // set_ped_gravity
0x2fbf47b1b36d36f9, 0x1553f3b8629a7c60,
0xb3b3359379fe77d3, 0x744ce45de2f4254b, // set_random_vehicle_density_multiplier_this_frame
0xa1fcf8e6af40b731, 0xa0ccd64e6ba66710, // get_player_underwater_time_remaining
0x46e56a7cd1d63c3f, 0x5e242bae5c968620,
0x36e353271f0e90ee, 0x45f471986387527, // has_weapon_asset_loaded
0xa1cadd00108836, 0x80b98c6dedfc3f8, // set_player_model
0x2398b627547189c, 0x7dd84cfd9febb5f, // _0x02398b627547189c
0x89f149b6131e57da, 0x4be687130e0dedf0, // set_vehicle_gravity
0x6eb5f71aa68f2e8e, 0x8f59de352cfe248b, // request_script
0x255f8dafd540d397, 0xad560f0e5589b880, // get_cam_far_dof
0xdcb194b85ef7b541, 0xd18bebbd5df53e9d, // set_particle_fx_looped_far_clip_dist
0xfdec055ab549e328, 0x768e45fd8446a395,
0x14892474891e09eb, 0x5f6f1bd7ac5cb0fa, // set_blip_secondary_colour
0x14c9fdcc41f81f63, 0xb66f454450132bcb, // _0x14c9fdcc41f81f63
0x31727907b2c43c55, 0x62c9d29cee9559ff, // _0x31727907b2c43c55
0x4f548cabeae553bc, 0xe6a77568d0646e57, // set_save_house
0xc694d74949cafd0c, 0x6a679f5037f6430d, // is_decal_alive
0xe86051786b66cd8e, 0x1280d19558d98d77, // network_get_local_handle
0xc2db6b6708350ed8, 0x2e4a13d268041e72, // detach_vehicle_from_tow_truck
0x629526aba383bcaa, 0x96d913d7d4fc1784,
// 0xafc976fd0580c7b3, 0x0, // _0xafc976fd0580c7b3
0xf162e133b4e7a675, 0xd73ac2f2dbbb17e5, // get_ped_group_index
// 0xa0fa4ec6a05da44e, 0x0,
0xe73364db90778ffa, 0xdce8bf85629fa987,
0xfa932de350266ef8, 0x2dc76e93d04e09f3, // use_siren_as_horn
0x267d00af114f17a, 0xc4ba1231bbaf1161, // has_entity_clear_los_to_entity_in_front
0xe8a25867fba3b05e, 0x7fb1ce0b11e78110, // _set_control_normal
0xb365fc0c4e27ffa7, 0x3c3c75d27de5486b, // clear_room_for_entity
0xca7dc8329f0a1e9e, 0x7190435e988b974c, // set_air_drag_multiplier_for_players_vehicle
0x9fa4664cf62e47e8, 0x5622e75af92fffbd, // reset_ped_ragdoll_timer
0x71a78003c8e71424, 0x2ee8d1440c9060ef, // request_additional_text
0x137bc35589e34e1e, 0xfb9d4e6534d32f54, // _draw_notification_clan_invite
0xa6385deb180f319f, 0x3a348fe792fd0699, // _0xa6385deb180f319f
0x2de3f0a134ffbc0d, 0xa649e2da0f4ee5b8, // get_network_id_from_sound_id
0x6e0eb3eb47c8d7aa, 0xbaf900ab0cd16bc6,
0xa50abc31e3cdfaff, 0xbd5053f7ffeb44e5, // set_text_leading
0x3daca8ddc6fd4980, 0xac1d3da2ffe0570f, // special_ability_fill_meter
0xcbb203c04d1abd27, 0x5b03624774eeb900, // load_rope_data
0x95c9e72f3d7dec9b, 0x59444f5d27c23602, // _move_finger
0x742d6fd43115af73, 0x2bdf928db52ade8a, // pulse_blip
0xf35425a4204367ec, 0x7ab9adafc83d086f, // set_ped_paths_width_plant
0x30de938b516f0ad2, 0xf218306fe038d44, // network_set_transition_activity_id
0xdb90c6cca48940f1, 0x9fa100da3eb90a2b, // _0xdb90c6cca48940f1
0x1e9057a74fd73e23, 0xda1e0961423703fb,
0x625b774d75c87068, 0xf650d038dc33dfea, // is_ped_responding_to_event
0x9b5a68c6489e9909, 0x4c975a5c7ec6831, // stat_increment
0xc7ef1ba83230ba07, 0x4d2362dd6552a70e, // set_ped_can_be_shot_in_vehicle
0x6f44cbf56d79fac0, 0x83168e8b851c1a83, // _0x6f44cbf56d79fac0
0xf6829842c06ae524, 0xfb4292281b89a28, // get_water_height
0x407c7f91ddb46c16, 0x9d2aa1151de44286,
0x3123faa6db1cf7ed, 0xf606706197a2c3a5, // task_vehicle_follow_waypoint_recording
0xaf66059a131aa269, 0xaf813fa635da238f, // network_override_transition_chat
0xbe70724027f85bcd, 0xcb16af340c4862be, // set_ped_targettable_vehicle_destroy
0x187382f8a3e0a6c3, 0xfa11c4e1c7222047, // _get_tunables_content_modifier_id
0xb893215d8d4c015b, 0x4b0f8ad495cc3930, // _set_plane_min_height_above_terrain
0xcf1182f682f65307, 0xe5710a2828393af0, // _0xcf1182f682f65307
0xd8050e0eb60cf274, 0x8dd9343dca32ce78, // disable_vehicle_impact_explosion_activation
0x93cf869baa0c4874, 0x341dad0128e99c8, // network_remove_entity_area
0xe3ebaae484798530, 0xc38521b2365dbcf5, // _0xe3ebaae484798530
0x70db57649fa8d0d8, 0xb81134eaac434d76, // set_vehicle_petrol_tank_health
0x2311dd7159f00582, 0xef4ce307751de06, // _0x2311dd7159f00582
0xd30c50df888d58b5, 0xe7e396453ca1fda4, // _set_ped_ai_blip
0x759650634f07b6b4, 0x6a0d1bf409e67ab1, // _0x759650634f07b6b4
0xef39ee20c537e98c, 0x78c9c48a5854d7ad, // _0xef39ee20c537e98c
0xd48fe545cd46f857, 0x77b79721ed5165f8, // set_mp_gamer_tag_alpha
0x11fa5d3479c7dd47, 0x9700629998a577d7, // _0x11fa5d3479c7dd47
0xb385454f8791f57c, 0x9bb4993730ec8e93, // set_vehicle_light_multiplier
// 0xcc3fdded67bcfc63, 0x0,
0xf6062e089251c898, 0xe073a021dc60be5e,
0xf10b05ddf8d16e9, 0x42cb4f785ba62376, // network_is_gamer_in_my_session
// 0xddf803377f94aaa8, 0x0, // set_ped_gesture_group
0x313ce5879ceb6fcd, 0x9562e33c057f7589, // get_random_float_in_range
0xbb062b2b5722478e, 0x707ffb0e65c1c546, // is_ped_getting_into_a_vehicle
0xc9156dc11411a9ea, 0xeb2114a9bf12f78e, // request_additional_collision_at_coord
0x29fe7cd1b7e2e75, 0xf1adc233be18a66, // prepare_synchronized_audio_event_for_scene
0xf6792800ac95350d, 0x82eb0bba1b560b25, // _0xf6792800ac95350d
0xe6c0c80b8c867537, 0x3d1d49e6ba088ffb, // _0xe6c0c80b8c867537
0xe7a0d23dc414507b, 0xf12696e54f216bca,
// 0xcd183314f7cd2e57, 0x0, // get_weapon_object_tint_index
0xfcf37a457cb96dc0, 0xc5dc7627bd3861cf, // _0xfcf37a457cb96dc0
0xcea04d83135264cc, 0xf1b97b949f89e84d, // set_ped_armour
0xfc4bd125de7611e4, 0xb964c249d7a2ca69, // explode_projectiles
0x638a3a81733086db, 0x3031f3812e92b62b,
0xae4e8157d9ecf087, 0xddc0258aa51be94d,
0xdc8c5d7cfeab8394, 0xcc2f38b1bc216a44, // has_bullet_impacted_in_box
0x98e2bc1ca26287c3, 0xfe6cd51e0b0bc5d2,
0xff0b610f6be0d7af, 0x5b9a42789310a300,
0x1bf094736dd62c2e, 0x37fbf97457299644, // is_ped_using_scenario
0x83cd99a1e6061ab5, 0x6c1ebc003c18f1f,
0x5b73c77d9eb66e24, 0xf1cde9fd207c4cd8, // _0x5b73c77d9eb66e24
0xb59e4bd37ae292db, 0x199bb9ea8dc26f8e, // _set_vehicle_engine_torque_multiplier
0x2b15662d7f8886f, 0x5d1b43675b257f3a,
0xe4e6dd5566d28c82, 0x784e3bc1f2706892,
0x4962cc4aa2f345b7, 0x2b5ad06882a4d084, // network_get_presence_invite_inviter
0xef0d582cbf2d9b0f, 0x5cd36a082654514, // apply_ped_blood_specific
0x726845132380142e, 0x6082cf5a3bb6d714, // set_particle_fx_looped_alpha
0x7ec6f9a478a6a512, 0xd9aa6c2c3d2c285c,
0x38491439b6ba7f7d, 0x4a5e83e738313295, // _0x38491439b6ba7f7d
0xaf514cabe74cbf15, 0xd51062c52bcd2ae8, // request_vehicle_recording
0xa358f56f10732ee1, 0x58a8b3f2ec67ef7f, // _object_value_add_object
0xf55e4046f6f831dc, 0x710ed64678f60844, // _0xf55e4046f6f831dc
0xce60de011b6c7978, 0x2b1e6e274dda8154, // network_is_gamer_muted_by_me
0x8c0d57ea686fad87, 0xa6a5ad1b71e28251, // _ped_skip_next_reloading
0xa86478c6958735c5, 0x70561b8c5a4201d4,
0xa1cb9094635d1a6, 0x9fdf63945c690003, // clear_area_of_projectiles
// 0xd4793dff3af2abcd, 0x0,
0x7ff548385680673f, 0x5cbe369bed96b7e, // remove_script_fire
0x9d40df90fad26098, 0x6c7b3b04b7d86c9e, // network_is_script_active
0x23b59d8912f94246, 0x456b68a8be5bc4fc,
0x8d8acd8388cd99ce, 0xd0fa15cc9fc1b425, // revive_injured_ped
0x1885bc9b108b4c99, 0xd3cfc7872f6fc22a, // get_player_sprint_time_remaining
0x4a595c32f77dff76, 0x282693b934bdb480, // network_invite_gamers_to_transition
0x5a039bb0bca604b6, 0x2c0ed4741a007c6a, // add_blip_for_coord
0xa5edc40ef369b48d, 0x3ee1295cefbefed4,
0xcb3c68adb06195df, 0x92d2f5199a78a0bd, // network_has_control_of_door
0x2e22fefa0100275e, 0xf1e4bf8810f354d,
0xb0a6cfd2c69c1088, 0x87dd3b7965d84461, // _set_network_task_param_bool
0x8ff3847dadd8e30c, 0x3012adf1b72a3a6b, // _object_value_add_string
0xa0ebb943c300e693, 0xdff589a2149528ce, // display_radar
0xc980e62e33df1d5c, 0x6938b282813053c6, // _leaderboards2_write_data_ex
0xe45087d85f468bc2, 0xf3866242eed6fa38, // _set_mission_name_2
0x4737980e8a283806, 0xf3227b8fdf5975bf, // _0x4737980e8a283806
0x169bd9382084c8c0, 0x874dc40b8d8fd604, // _get_text_substring
0x23f09eadc01449d6, 0x809b77e9d322fbbe, // _0x23f09eadc01449d6
0x2ed61456317b8178, 0xb9254b81d3defa91,
0x539de94d44fdfd0d, 0x82384635cdb4b1fa, // get_vehicle_model_max_traction
0x2a2a52824db96700, 0xc4910103d1bdf94d, // _0x2a2a52824db96700
0x8817605c2ba76200, 0x792e356b31c0cb11,
0x8362b09b91893647, 0xcd0ddc12da979fff,
0xb2cc4836834e8a98, 0xc5a334d1f44d5be5, // network_earn_from_job
0x2c96cdb04fca358e, 0x11166da34df0a74, // _0x2c96cdb04fca358e
0x759e13ebc1c15c5a, 0x7fc70ea5c123778, // _set_gameplay_cam_raw_pitch
0x743607648add4587, 0xecd075b93a09a2b6,
0x697157ced63f18d4, 0x3aa7bdd1a9c14e75, // apply_damage_to_ped
0xfefcf11b01287125, 0x978f18a8de1f6ef3, // is_sniper_bullet_in_area
0xc69eda28699d5107, 0x9d8c631256fc1c8f, // set_radio_to_station_name
0x4d36070fe0215186, 0x6f3d61b58c7b4025, // network_has_control_of_network_id
0x5c29f698d404c5e1, 0xed0f188b4f015cbb, // _set_des_object_state
0x7ec52cc40597d170, 0x37d4d3708d21b21b,
0x475768a975d5ad17, 0x9ed464aaa493c8ef, // is_ped_armed
0xd3997889736fd899, 0x6c937dfcef8719ad, // set_entity_can_be_targeted_without_los
0xbd12f8228410d9b4, 0xb90003646a14c0b1, // _end_text_command_busy_string
0x706d57b0f50da710, 0x65ba35d6d61f1574, // trigger_music_event
0x5688585e6d563cd8, 0xe2ae4e6f010fa5c5, // _0x5688585e6d563cd8
0x4a355e041e004e6, 0xceb55689c694866c, // get_ped_texture_variation
0x851cd923176eba7c, 0x61e9c56df132f9,
0x8f17bc8ba08da62b, 0x8fe1e440c51947f5, // get_vehicle_dirt_level
0x7aefb85c1d49deb6, 0xde9ff07cfd5dc172, // set_ped_accuracy
// 0xfb1f9381e80fa13f, 0x0, // _0xfb1f9381e80fa13f
0xdb41d07a45a6d4b7, 0x9a2eec0fe15d519a, // _0xdb41d07a45a6d4b7
0x52991e59076e4e4, 0x74367f010d68e456, // _0x052991e59076e4e4
0x7f8f6405f4777af6, 0x68fff67710ca5c91, // _0x7f8f6405f4777af6
0xb4271092ca7edf48, 0x169f6af92ec67dbd, // _0xb4271092ca7edf48
0x9737a37136f07e75, 0xd52c9eadb5d68c6c, // _0x9737a37136f07e75
0x43fa0dfc5df87815, 0xbbf5e06891323097, // _0x43fa0dfc5df87815
0x42bc05c27a946054, 0x150da9909d3fd212, // get_current_playback_for_vehicle
0xe22d8fde858b8119, 0x3f0ecdd5cc67fc67, // set_entity_can_be_damaged_by_relationship_group
0x298b91ae825e5705, 0xbeac9df5323bb074, // is_ped_in_any_heli
0xb1252e3e59a82aaf, 0x44fdc3a27d4134ba, // _remove_current_rise
0xae2206545888ae49, 0x4adc4ac6d9182d71, // leaderboards2_write_data
0xd7ae6c9c9c6ac54c, 0x1c6f24eca1a88e67, // stat_get_float
0xcd536c4d33dcc900, 0x8b14e24e4296b254, // play_end_credits_music
0x692d58df40657e8c, 0x9ba048b93820ce57, // _0x692d58df40657e8c
0x678bb03c1a3bd51e, 0x245d49d6b0d31de6, // _0x678bb03c1a3bd51e
0xe7dcb5b874bcd96e, 0x974bef45d557b847, // add_text_component_float
0xfc695459d4d0e219, 0xc130f0eccd773bc, // _set_cursor_location
0x17299b63c7683a2b, 0xb797fc97a1aae6de, // add_text_component_substring_text_label_hash_key
0x88bc673ca9e0ae99, 0x8634a553709c2912, // _0x88bc673ca9e0ae99
0xef4ced81cebedc6d, 0x541d5c57194e73c4, // set_userids_uihidden
0x47c3b5848c3e45d8, 0xe58124354ec682ac, // set_clock_time
0x1b5c85c612e5256e, 0x335d8135051ea56, // add_scenario_blocking_area
0x158bb33f920d360c, 0x94a82f47ff139f3d, // task_vehicle_drive_to_coord_longrange
0x4f056e1affef17ab, 0x7b40fe633a95abf8, // task_force_motion_state
0x2707aae9d9297d89, 0x4136f4541fd3a564, // set_checkpoint_cylinder_height
0x876046a8e3a4b71c, 0x4517bc4dd6d865d7, // get_random_ped_at_coord
0xc8535819c450eba8, 0x64ad22f2e9b48d42, // disable_hospital_restart
0xe6cc9f3ba0fb9ef1, 0x7ab0925a06bd5ad, // has_script_loaded
0x560a43136eb58105, 0x2b4a2e9ed65d5c93, // set_ped_helmet
0x5faf9754e789fb47, 0x20e6751dab3c09c6, // get_number_of_ped_prop_drawable_variations
0xe1cd1e48e025e661, 0xd384c2e6be0d5abf,
0x87eb7a3ffcb314db, 0xe97d3e05a6165d8d, // _network_is_friend_handle_online
0x7f2c4cdf2e82df4c, 0x3676dfc4503b6862, // _0x7f2c4cdf2e82df4c
0x3556041742a0dc74, 0x6f275a9e4b496428, // close_bomb_bay_doors
0xc1c5d756fb5f337, 0x98913689763c69ac, // _has_named_scaleform_movie_loaded
0x346ef3ecaaab149e, 0xcb93ae2bb6a05af7,
// 0xac83b1db38d0ada0, 0x0, // task_heli_chase
0xdcd4ec3f419d02fa, 0x9ff59d8c46007501,
0x40cf0d12d142a9e8, 0xe6740f20bad9e7a0, // _reset_ambient_voice
0x163f8b586bc95f2a, 0x7539dad6142cd493, // _0x163f8b586bc95f2a
0xab54a438726d25d5, 0x4522ad7364b6aa54, // set_vehicle_forward_speed
0xf401b182dba8af53, 0x3ecff2c524e351a4, // set_player_can_leave_parachute_smoke_trail
0x1d132d614dd86811, 0x83a1d480db0b52cc, // set_scaleform_movie_as_no_longer_needed
0x3b6405e8ab34a907, 0xc733703096dc0a81, // set_ped_visual_field_center_angle
0xe7e72961ba18619, 0xcc059005678422d8, // start_particle_fx_non_looped_on_ped_bone
0x67c540aa08e4a6f5, 0xf8eaeec97ddbcb3, // play_sound_frontend
0x4d89d607cb3dd1d2, 0xcdc0790b374d52f1, // _0x4d89d607cb3dd1d2
0x717cd6e6faebbedc, 0xe288c38b19ef787e, // set_game_pauses_for_streaming
0xb695e2cd0a2da9ee, 0x2dae73e0b3cdcff7,
0x662635855957c411, 0xa73d4db6b7561b0b, // _0x662635855957c411
0x407091cf6037118e, 0x5d39110d96d2618d, // _0x407091cf6037118e
0xede476e5ee29edb1, 0x144904d2eaa84341, // set_input_exclusive
0x37181417ce7c8900, 0x78c7815d761e5e66, // start_shape_test_bound
0x2c4a1590abf43e8b, 0x132824c3371ecc61, // _0x2c4a1590abf43e8b
// 0x5c90988e7c8e1af4, 0x0,
0x1d08b970013c34b6, 0x4d0306f9e1621374, // acos
0x92f0cf722bc4202f, 0x9993e7216cf52c4, // set_vehicle_has_strong_axles
0x9e3b3e6d66f6e22f, 0xb720980077e47817, // get_offset_from_interior_in_world_coords
0x98c494fd5bdfbfd5, 0x389a33706e7bdc3a, // _begin_scaleform_movie_method_hud_component
0x93a3996368c94158, 0x8151ad3fa05f1c0f, // _set_vehicle_engine_power_multiplier
0xd4d7b033c3aa243c, 0xc4ed190294e9e658, // _is_dlc_data_empty
0x451294e859ecc018, 0x5692743cf44411a6, // _0x451294e859ecc018
0xbd06c611bb9048c2, 0xde14ea4aead50935, // _request_scaleform_movie_interactive
0x30a6614c1f7799b8, 0x34850f59030a3049, // _0x30a6614c1f7799b8
0x616093ec6b139dd9, 0x3cd0bc562a4081d7, // _0x616093ec6b139dd9
0x24fb80d107371267, 0xeb9dc13235c0b345, // network_get_player_index
0xe520ff1ad2785b40, 0x8d255802ebf1da76,
0x47d6f43d77935c75, 0x42b0e494045a7df, // is_entity_visible
0xf159a63806bb5ba8, 0xd39b9199ee31e8e6, // rope_draw_shadow_enabled
0x3158c77a7e888ab4, 0x86165ee9c569ab48, // set_mp_gamer_tag_health_bar_colour
0xdde23f30cc5a0f03, 0xfb814ad22cdb53d2, // _start_networked_particle_fx_looped_on_entity_bone
0x2df9038c90ad5264, 0x10403e3173535455, // _0x2df9038c90ad5264
0x195aeeb13cefe2ee, 0x35e0c134b84d7e0a, // task_vehicle_goto_navmesh
// 0x8204da7934df3155, 0x0, // network_spent_request_job
0xbc1cc91205ec8d6e, 0xc8ac934fd0b61cfa,
0x15ff52b809db2353, 0x36cc7a463c6de49c, // _0x15ff52b809db2353
0x8a8694b48715b000, 0x9193ff8b2f309eec,
0x465c84bc39f1c351, 0xcfb6e66e3665bf86, // set_text_dropshadow
0xec72c258667be5ea, 0x384c27a09b555f32, // _0xec72c258667be5ea
0xa6f6f70fdc6d144c, 0x93113bdb76c695c5, // remove_decals_from_object_facing
0xd839450756ed5a80, 0x691e8ef7dcb53aad, // is_ped_fatally_injured
0x80ec48e6679313f9, 0xc52b92c972695208, // has_pickup_been_collected
0xb0760331c7aa4155, 0xa9680ddfb5eb643a, // get_is_task_active
0x1b1ab132a16fda55, 0x4e5a7cb33ce58180,
0x8efccf6ec66d85e4, 0xf1c5180b808f93ba, // _0x8efccf6ec66d85e4
0xb606e6cc59664972, 0xbc803c497366b0e3, // _0xb606e6cc59664972
0x94d94bf1a75aed3d, 0x955cdccd13613323, // set_ped_plays_head_on_horn_anim_when_dies_in_vehicle
0xe944c4f5af1b5883, 0x18995d0bcbc9767e, // network_is_gamer_blocked_by_me
0x468056a6bb6f3846, 0xb6c71936127cfaf2, // is_vehicle_bumper_broken_off
0x5e6cc07646bbeab8, 0xba45bb6f2247fce9, // disable_player_firing
0x81cbae94390f9f89, 0x1c4e3934365ad58f,
0x1454f2448de30163, 0x7b56b61eca4663b, // set_fake_wanted_level
0x28d37d4f71ac5c58, 0x8d51a3997e8f3769, // get_vehicle_layout_hash
0x24da7d7667fd7b09, 0x2e5316e0622f35e7,
0xc912af078af19212, 0xfb9e5ca1dfc10c99,
0x8524a8b0171d5e07, 0x1c8705f667f673ea, // set_entity_rotation
// 0xdeadc0dedeadc0de, 0x0, // _entity_description_text
0x6dee77aff8c21bd1, 0xdfde4dc8546f54cf, // _0x6dee77aff8c21bd1
0xbf59707b3e5ed531, 0x174cecbd338f3a2c, // _0xbf59707b3e5ed531
0xe3a7742e0b7a2f8b, 0x8f571639f76e26c0, // _shoot_single_bullet_between_coords_preset_params
0x8ef6b7ac68e2f01b, 0x4474d76207f09de7, // clear_ped_last_damage_bone
0xe3ad2bdbaee269ac, 0xb7c14a395669007f, // add_explosion
0xb07d3185e11657a5, 0x462247b843778df4, // _0xb07d3185e11657a5
0x7679cc1bcebe3d4c, 0x9aee135cb539b737, // _0x7679cc1bcebe3d4c
0xa123435a26c36cd, 0xf717f78e86807071,
0x4e9021c1fcdd507a, 0x5e1ada1ae0f71df1, // set_player_stealth_perception_modifier
0x76d9b976c4c09fde, 0xdd507f4d4926b287,
0x1a78ad3d8240536f, 0xa133a899bfac42b4, // _0x1a78ad3d8240536f
0xedf4079f9d54c9a1, 0xdd9d9ffe59b3e34d, // set_ped_stay_in_vehicle_when_jacked
0xa1c996c2a744262e, 0x48034bd71bfdf069, // _0xa1c996c2a744262e
// 0xe301bd63e9e13cf0, 0x0, // _0xe301bd63e9e13cf0
0xb57a49545ba53ce7, 0x8cb86a22fa87265d, // _0xb57a49545ba53ce7
0x2ce544c68fb812a0, 0xd347320f93f4399a, // _add_speed_zone_for_coord
// 0x80c75307b1c42837, 0x0, // _get_pstat_bool_hash
// 0xe977fc5b08af3441, 0x0, // has_stealth_mode_asset_loaded
0x96695e368ad855f3, 0x85334364619494c8,
0xaeab987727c5a8a4, 0x2c824df7ffa0c226, // _0xaeab987727c5a8a4
0x5f61ebbe1a00f96d, 0x163682bec76cfed2, // _remove_named_ptfx_asset
0xd9284a8c0d48352c, 0xf17c5b01deca3f49, // set_player_parachute_variation_override
0xcbdb9b923cacc92d, 0xdc13d996a8a3be3b, // _get_cargobob_hook_position
0xe0a0aec214b1faba, 0x6536fcd126bb1c53, // is_conversation_ped_dead
0xb15162cb5826e9e8, 0x30cdd4cea6a71edd,
0x13945951e16ef912, 0xedef87ed9ad0ca33, // assisted_movement_override_load_distance_this_frame
0x4a18e01df2c87b86, 0x61fc243328eb16dd, // set_fade_out_after_death
0x9483af821605b1d8, 0xeb5dd88fb5dfc736, // get_ped_armour
0xded5af5a0ea4b297, 0x7a66899f7e549ba6, // set_driver_racing_modifier
0x849648349d77f5c5, 0x2a800dc75d41b200, // network_earn_from_property
0x1a9205c1b9ee827f, 0x23298ab8a7d0f403, // set_entity_collision
0xcd90657d4c30e1ca, 0xe2b961c714ad503c, // get_name_of_zone
0xe599a503b3837e1b, 0x5d0b382f3e14a5e9,
0xd1c55b110e4df534, 0xcb4fb82994217ec0, // _0xd1c55b110e4df534
0xdff09646e12ec386, 0xa018b856ad5a1659, // network_get_presence_invite_id
0x41bc0d722fc04221, 0xe3af628b41f75538, // clean_itemset
0xd2c91a0b572aae56, 0xf8206f55d10b747c,
0xc91c6c55199308ca, 0xd58ecc0ef259a65d, // _0xc91c6c55199308ca
0x2afe52f782f25775, 0x5b88aa27ed51387b, // is_ped_running_mobile_phone_task
0x9969599ccff5d85e, 0x845b854d38c19b13, // set_ability_bar_value
0x5cd3cb88a7f8850d, 0xfb2c4d32fed130ab, // is_ped_headtracking_ped
0xc92ba89f1af26f8, 0xd447f8a4207d2975, // get_player_wanted_centre_position
0x2b3451fa1e3142e2, 0x97c63d95072367ba, // test_vertical_probe_against_all_water
0x4645de9980999e93, 0xc9170667725c9fe2, // _0x4645de9980999e93
0xbc9ae166038a5cec, 0xe36ed860d907c5f8, // play_pain
0x439e9bc95b7e7fbe, 0x25f356beb062beb7, // cell_cam_is_char_visible_no_face_check
0x89d9fcc2435112f1, 0xe74fcd8c8caa5060, // task_climb
0x3dbfc55d5c9bb447, 0xdd02ec6c22fd1487, // set_ped_never_leaves_group
0xd2f1c53c97ee81ab, 0xe982737e4539daf7, // task_parachute
0xf29cf591c4bf6cee, 0x18e5e2b41cd6ce17, // set_ped_seeing_range
0xf28da9f38cd1787c, 0xec4a6f43ae4bdd62, // start_particle_fx_looped_on_ped_bone
0x51669f7d1fb53d9f, 0x52830ee89c97404, // set_cinematic_button_active
0x7619364c82d3bf14, 0x3b5835c5ece98a78, // set_local_player_visible_locally
0x4f1d4be3a7f24601, 0x65ea11cf317fe4fa, // set_vehicle_colours
0x9f0c0a981d73fa56, 0x2669ee639501d506, // network_gamertag_from_handle_start
0xac51915d27e4a5f7, 0xcbb37e866d5db277, // _get_heli_engine_health
0xfc2d89ac25a5814, 0x8c4ea5f6857553ae, // set_vehicle_model_is_suppressed
0x49482f9fcd825aaa, 0xb78f106d9262eb22, // _0x49482f9fcd825aaa
// 0xfd813bb7db977f20, 0x0, // switch_train_track
0x9414e18b9434c2fe, 0x11cf5f3b4061b0c8, // set_ped_head_blend_data
0x4487c259f0f70977, 0x8e2ebae8ca6648a5, // set_entity_anim_current_time
0xa4664972a9b8f8ba, 0xd84760afd70acc07, // _0xa4664972a9b8f8ba
0x444d98f98c11f3ec, 0x96fdb6af87e8a6bd, // set_random_seed
0xa9d0c2a3bbc86c1, 0x52c7f2cbe015c31d, // does_scenario_of_type_exist_in_area
0x99b72c7abde5c910, 0xd3024ce00f392f7f, // _network_copy_ped_blend_data
0x2c2e3dc128f44309, 0x118f80020cbc9cdc, // _0x2c2e3dc128f44309
0xfd3151cd37ea2245, 0xc8241935d70645f5, // _0xfd3151cd37ea2245
0xad15f075a4da0fde, 0xb5327081b2948314, // start_player_teleport
0xf51d36185993515d, 0xa7a6ba984bd6731a, // _0xf51d36185993515d
0x70da3bf8dacd3210, 0xefb1052d4125f1b7, // network_set_override_spectator_mode
0xb128377056a54e2a, 0xc2a270e9c5578803, // set_ped_can_ragdoll
0x811381ef5062fec, 0xc2080e0ed4cea5a, // _0x0811381ef5062fec
0x3edcb0505123623b, 0x568f2c15e27b386, // set_ped_infinite_ammo
// 0xe0d36e5d9e99cc21, 0x0, // _is_ped_hair_color_valid
0xd45b1ffccd52ff19, 0x73ee98a5db0530da, // activate_damage_tracker_on_network_id
0xeaf5f7e5ae7c6c9d, 0x1dc68e6a07c3c268, // get_ped_parachute_tint_index
0xa21c118553bbdf02, 0xc97c43513d826f25, // _0xa21c118553bbdf02
0xc978fda19692c2c, 0x47ba1b424971031, // _0x0c978fda19692c2c
0x71b008056e5692d6, 0x24f536ddc32b32c8,
0x92b35082e0b42f66, 0xa56208ab5f9ec61a, // set_vehicle_brake_lights
0xdfa80cb25d0a19b3, 0x69b80ae60ad91302,
// 0xa60bb5ce242bb254, 0x0, // network_host_transition
0x7dd234d6f3914c5b, 0x9b60d03515b36d37, // _set_cam_dof_fnumber_of_lens
0xe6ac6c45fbe83004, 0xbd1087abd1970b9c, // _start_shape_test_capsule_2
// 0xc79196dcb36f6121, 0x0, // _clear_ped_cover_clipset_override
0xc900596a63978c1d, 0x4f729c0b5ccb6fee, // playstats_mission_checkpoint
0xbf4f34a85ca2970c, 0xbf3fbfae3c7ce476,
0x4c68ddddf0097317, 0x9d2fbe4e4b7be8d1, // force_cleanup_for_all_threads_with_this_name
0xb1b6216ca2e7b55e, 0x8e2533d4c3a1b02e, // _0xb1b6216ca2e7b55e
0x25b99872d588a101, 0x1e78e2489d1b38fa, // _0x25b99872d588a101
0xd559d2be9e37853b, 0xd6f2465c123afabb, // get_time_since_player_drove_on_pavement
0x806058bbdc136e06, 0x151d1b83673fce66,
0xd031a9162d01088c, 0xe9ccf312047ebee0, // has_anim_dict_loaded
// 0x5fd5ed82cbbe9989, 0x0, // network_pay_employee_wage
0xeaceeda81751915c, 0x8a7eb7e2ef5205b7,
0xffee8fa29ab9a18e, 0x27baf1197b0de5fd, // _0xffee8fa29ab9a18e
0xa711568eedb43069, 0xd4a76b5e6c175542, // remove_vehicle_window
0x70793bdca1e854d4, 0x2f0bcf622d7975e8, // set_ped_visual_field_max_angle
0x5a7f62fda59759bd, 0x51b32ce3a24fe983,
0x72d0706cd6ccdb58, 0xa7d52bdfe6a4e28d,
0xdfb2b516207d3534, 0x49d25022440e65ee, // is_cam_active
0x480357ee890c295a, 0xf26f606f8b36e2ac,
0x3d3d8b3be5a83d35, 0x240ae498a651e3be,
0xa09f896ce912481f, 0x9ee72fafeaf54089, // _0xa09f896ce912481f
0x7669f9e39dc17063, 0x4e988e435e501536,
0xc5bc038960e9db27, 0x7316ea42e2f967b0, // set_script_with_name_hash_as_no_longer_needed
0x908311265d42a820, 0xe53694b55dfcaadf,
0x4c60e6efdaff2462, 0xc9cefb3a060444af, // set_player_vehicle_defense_modifier
0x65f0c5ae05943ec7, 0xb15e06e3e9c9aea5, // is_ped_current_weapon_silenced
0x117b45156d7eff2e, 0xa49d21c7e5e23816, // leaderboards_get_number_of_columns
0x6a12d88881435dca, 0xfa46656b2b84a52d,
0xd49f9b0955c367de, 0x9ba5cf280376eea4, // create_ped
0x689cde5f7c6787, 0x5bfe23553f943c83, // remove_vehicle_high_detail_model
0x102e68b2024d536d, 0x379324d4caf6c2d1, // set_create_random_cops
0xd01d20616fc73fb, 0xd494746a356e59d6, // _0x0d01d20616fc73fb
0x97c9e4e7024a8f2c, 0x1f65ec88d1b3caad, // _draw_notification_apartment_invite
0xc5286ffc176f28a2, 0x6105cdb23e256b76, // is_ped_running
0xe1615ec03b3bb4fd, 0xa5c0d3c085a49e49,
0x476ae72c1d19d1a8, 0x8a816e2881394b49, // set_ped_drops_weapons_when_dead
0xceda60a74219d064, 0x2cee5bbff325d0a0, // _0xceda60a74219d064
0x7206f674f2a3b1bb, 0x14b30805aca532bf, // network_set_currently_selected_gamer_handle_from_invite_menu
0x7f93691ab4b92272, 0xa148ea6edb5ee66c, // task_everyone_leave_vehicle
0xf239400e16c23e08, 0xb9cd65d96a74dedf, // _0xf239400e16c23e08
0xbc3144deb678666, 0x5d4c9d26d45b1904, // _0x0bc3144deb678666
0x5354c5ba2ea868a4, 0x7574039d7020b3d1, // _set_map_full_screen
0xf82d8f1926a02c3d, 0x41d9972de84520ab, // set_state_of_closest_door_of_type
0x79cfd9827cc979b6, 0xdbac1efc22d74e44, // get_ped_parachute_state
0x7660c6e75d3a078e, 0xd68e5c7e86469f11, // stop_cinematic_shot
// 0x515b4a22e4d3c6d7, 0x0, // network_earn_from_ai_target_kill
0x8b32ace6326a7546, 0xc5183090d5499516, // is_object_visible
0x9d26502bb97bfe62, 0x1b7961a070fb048f, // _network_spent_request_heist
0x4e404a9361f75bb2, 0xdaf3d0c5f7ffc576, // _0x4e404a9361f75bb2
0xb096419df0d06ce7, 0x671d2ae4291f252e, // set_clock_date
0x25367de49d64cf16, 0x8a065911c6f917c0, // _0x25367de49d64cf16
0x7141766f91d15bea, 0xb652c463de18181e, // set_vehicle_custom_primary_colour
0xbfefe3321a3f5015, 0xc934de5e2fa02b19, // _create_mp_gamer_tag
0x61a885d3f7cfee9a, 0x4742207943d8eb65,
0xd7021272eb0a451e, 0x1b1c99dfb775068d, // _preset_interior_ambient_cache
0xb11d94bc55f41932, 0x241ab2281ff1751a, // _0xb11d94bc55f41932
0xdeb2b99a1af1a2a6, 0xb0d268c9d1bf25d8, // _0xdeb2b99a1af1a2a6
0xc6f8ab8a4189cf3a, 0x2f6fbc239b6c4fbc,
0x6fd7816a36615f48, 0xaf0a8c7b08d420f5, // knock_off_ped_prop
0x46d1a61a21f566fc, 0x9b1105bbc773aa14, // _0x46d1a61a21f566fc
0x8aba6af54b942b95, 0xe043fb70a76de4ae, // set_vehicle_undriveable
0x814fa8be5449445d, 0x18a3618891ee1d1e, // get_vehicle_ped_is_trying_to_enter
0x45b8154e077d9e4d, 0x21c816a90beb45ba, // network_earn_from_holdups
0xbedb96a7584aa8cf, 0xdc17890b0b8b5081,
0xee76ff7e6a0166b0, 0x72bff73e1609d4d6, // _set_mp_gamer_tag_
0x317eba71d7543f52, 0x4f9021f32a32f422, // _0x317eba71d7543f52
// 0x311438a071dd9b1a, 0x0, // _0x311438a071dd9b1a
0xd9b71952f78a2640, 0x8d1ea98c316ea2ee, // _0xd9b71952f78a2640
0xc0296a2edf545e92, 0xe96a50f1de6657cb, // is_model_valid
// 0x2b69f5074c894811, 0x0, // _0x2b69f5074c894811
0xcd8a7537a9b52f06, 0xf52bf9a82abda815, // clear_all_ped_props
0x7a556143a1c03898, 0x2e6ec0fab080c550, // set_scenario_ped_density_multiplier_this_frame
0xc0714d0a7eeeca54, 0x302a3b601c20eed9, // register_save_house
0x5dd35c8d074e57ae, 0xbfdffbe4976dd48e, // get_vehicle_acceleration
0xdadfada5a20143a8, 0x2689df1ad1d65cfe,
0x78cfe51896b6b8a4, 0xffaaf12f0e94e37, // is_player_targetting_anything
0x7a3f19700a4d0525, 0xc99322ffeb21bc08,
0x46df918788cb093f, 0x25c292b90705215c, // apply_ped_damage_pack
0xd1f7ca1535d22818, 0x12fa423580be1050,
0xd38744167b2fa257, 0xce5c49921a521962, // set_blip_scale
// 0xb5d3453c98456528, 0x0,
0xe81afc1bc4cc41ce, 0x73f9a78d00fb9c0, // get_entity_submerged_level
0xdac073c7901f9e15, 0x59dd23556bf7c12e, // _0xdac073c7901f9e15
0xa9f2a468b328e74, 0x1c180287a7d01554, // _0x0a9f2a468b328e74
0x5aa3befa29f03ad4, 0x3cedcf35b2ffe080,
// 0xb13e88e655e5a3bc, 0x0,
0xbc9490ca15aea8fb, 0xbe4ef1cc6597ea75, // _0xbc9490ca15aea8fb
0xe4b90f367bd81752, 0x60f149b1e077551d, // has_player_damaged_at_least_one_non_animal_ped
0x27b0405f59637d1f, 0x19cfb571f503632b, // set_ped_sweat
0x1f1f957154ec51df, 0xeabee41ae38d3281, // load_stream
0x59e727a1c9d3e31a, 0xd5933dc5fab0505e, // set_radar_as_interior_this_frame
// 0xa091a5e44f0072e5, 0x0, // network_do_transition_quickmatch_async
0x72dd432f3cdfc0ee, 0x50b82dfeb5b3a3af, // _0x72dd432f3cdfc0ee
0xe620fd3512a04f18, 0x88090bc67ddd427d, // _0xe620fd3512a04f18
0x6a5d89d7769a40d8, 0x885c9e33523e51d6, // _0x6a5d89d7769a40d8
0x7a983aa9da2659ed, 0xcafaf7bfa6f10cdf, // _object_value_get_array
0x89049dd63c08b5d1, 0xc119e2a4afb3a74d, // play_stream_from_ped
0x42fb3b532d526e6c, 0x4b9549b568ad849c,
0x3d245789ce12982c, 0xf1d5a39d327a49fa, // prefetch_srl
0x6671f3eec681bda1, 0x36f61aefb7df9586, // task_aim_gun_at_coord
0xada24309fe08dacf, 0x69e8edfea57e361d,
0x19f21e63ae6eae4e, 0x1fea416e00837afc, // set_user_radio_control_enabled
0x9a83f5f9963775ef, 0x2d810307dd6e0e0d, // _is_vehicle_mod_load_done
0x8ef5573a1f801a5c, 0x84d5f76a867b0569, // _0x8ef5573a1f801a5c
0xf804f1db19b9689, 0xe0dac4abe9900d9a, // task_clear_look_at
0x6483c25849031c4f, 0x1a9faaea48a0d857, // _0x6483c25849031c4f
0x4f32c0d5a90a9b40, 0x51b931529c63adc,
0xd69736aae04db51a, 0x8dab5b12d7b9ad29, // _add_scaleform_movie_method_parameter_float
0x5b48a06dd0e792a5, 0xc067e4369ead32fb,
0x8b05f884cf7e8020, 0xf81197adab63fe81,
0x6b7a646c242a7059, 0x6ee33b67dcac6db1, // set_ped_can_evasive_dive
0xb2a592b04648a9cb, 0x3750f07952a8cce,
0x726e0375c7a26368, 0x8b04f708d5801167,
0x14590ddbedb1ec85, 0xb223380a2229670d, // _0x14590ddbedb1ec85
0xabd5e88b8a2d3db2, 0xf92570fd95bcb781, // network_session_voice_connect_to_player
0x564b884a05ec45a3, 0x60870bec3f8387d6,
0x44a113dd6ffc48d1, 0x8ee1b0849b12e514, // set_follow_ped_cam_cutscene_chat
0x9135584d09a3437e, 0x6ad830edb1e9ab29,
0x23703cd154e83b88, 0x4ea529533f2c0e2a, // task_plane_mission
0xc5238c011af405e4, 0xf3086b820f7410c3, // _load_ugc_file
0x5b712761429dbc14, 0x7312779496a8d460, // wash_decals_from_vehicle
0x1e7889778264843a, 0x7fd73ed82f5851e3, // task_extend_route
0xafaf86043e5874e9, 0x91412c77b0592576, // are_player_flashing_stars_about_to_drop
0x16a96863a17552bb, 0xbfa6c8bd35454f02, // set_cam_use_shallow_dof_mode
0x6bfb12ce158e3dd4, 0xfd06704bd48bd0c, // _0x6bfb12ce158e3dd4
0xea23c49eaa83acfb, 0x96a38548c8fb752e, // network_resurrect_local_player
0x88a741e44a2b3495, 0x771ea747b50636, // is_ipl_active
0x93054c88e6aa7c44, 0xc143016960b0dd7d, // playstats_npc_invite
0x36c1451a88a09630, 0xb767be40f891053d, // _0x36c1451a88a09630
// 0x5f3b7749c112d552, 0x0,
0x92f0da1e27db96dc, 0x78a71b821bec04f9, // _set_notification_background_color
0x817268968605947a, 0xe27a063f1211c3f5, // assisted_movement_request_route
0x350f82ccb186aa1b, 0x285670efff35afda, // stat_get_pos
// 0x150b6ff25a9e2e5, 0x0,
0x97ce68cb032583f0, 0x5766ba01380e23cf, // set_force_hd_vehicle
0x6816fb4416760775, 0x9a64deed09590304, // _network_earn_from_job_bonus
0x5ce62918f8d703c7, 0xadb810fa0ed79194, // _0x5ce62918f8d703c7
0x77a1eec547e7fcf1, 0xaa35cb1652ae220e, // play_entity_scripted_anim
0xd01015c7316ae176, 0x84d46d4351e931d5, // _set_network_task_action
0xa80ae305e0a3044f, 0x69c19c4a66a58974, // _0xa80ae305e0a3044f
0x8bdc7bfc57a81e76, 0xc13e21630c52c675, // _get_ground_z_coord_with_offsets
// 0xbe84c318ba6ec22, 0x0, // register_object_script_brain
0x183dadc6aa953186, 0xbd9192e78665989f, // set_ped_infinite_ammo_clip
0x45905be8654ae067, 0xdc5e58a8757761ad, // get_nth_closest_vehicle_node_favour_direction
0x5aba3986d90d8a3b, 0x13a2d602cd10cbac, // task_perform_sequence
0x7fb218262b810701, 0x1be9de786d9e5df3, // play_entity_anim
0xb3caf387ae12e9f8, 0x827151dd29f83326, // get_weapon_component_hud_stats
0x471d2ff42a94b4f2, 0x4ae93b307fdb2941, // set_all_random_peds_flee_this_frame
0x4668d80430d6c299, 0x1130eb06cde2ecd0, // _0x4668d80430d6c299
0x5afeedd9bb2899d7, 0xd266f9d236ae6c86, // set_vehicle_provides_cover
0xe184f4f0dc5910e7, 0xc5466c3a31dbcd76, // start_particle_fx_looped_at_coord
0xa9da48fab8a76c12, 0x242d64c1b067cec6, // task_goto_entity_aiming
0xe9f6ffe837354dd4, 0xbfca64ee1b88fd4e, // release_named_rendertarget
0xd5002d78b7162e1b, 0x8e94664fdc9f0094, // assisted_movement_set_route_properties
0xaa19f5572c38b564, 0x37ff9ec5b6b5ee03, // _0xaa19f5572c38b564
0xeebfc7a7efdc35b4, 0xbbcec7eb03b44376, // _0xeebfc7a7efdc35b4
// 0x7c0043fdff6436bc, 0x0, // _0x7c0043fdff6436bc
0x4afe3690d7e0b5ac, 0xb5de290a9418133a, // clear_ped_drive_by_clipset_override
// 0x1185a8087587322c, 0x0, // _0x1185a8087587322c
0x2bba30b854534a0c, 0xf6a439ec966ac290, // task_combat_hated_targets_around_ped_timed
0xc3981dce61d9e13f, 0xe62f31d05eb2ac, // create_cam
0x1e8c308fd312c036, 0x9975da2bf7f980a7, // init_shop_ped_component
0xe50e52416ccf948b, 0xc6cde40f70f13196, // get_nth_closest_vehicle_node
0x7ee9f5d83dd4f90e, 0x36fb861f8ccf0ea4, // start_shape_test_los_probe
0xbbf327ded94e4deb, 0xe97b055524edba45, // _0xbbf327ded94e4deb
0xf98dde0a8ed09323, 0x3a88bd59dc524fb2, // _0xf98dde0a8ed09323
0xa6db4965674d243, 0xb3167e6a31a2f1dc, // get_selected_ped_weapon
0x499ef20c5db25c59, 0xdcac33aabab4f878, // does_cutscene_entity_exist
0x33ee12743ccd6343, 0xb667aa7e1c679d03, // _draw_notification_unlock
0xc6033d32241f6fb5, 0xdfb884bd9085c5fc, // _0xc6033d32241f6fb5
0xf8ebccc96adb9fb7, 0xf3afa7573aa3781d, // _0xf8ebccc96adb9fb7
0xb2c1a29588a9f47c, 0xdff996ed119d35b1, // set_player_sneaking_noise_multiplier
0x16e42e800b472221, 0x9ceb044dd108bd00, // force_ped_to_open_parachute
0xd79185689f8fd5df, 0x699fd6ef08d81548, // _0xd79185689f8fd5df
0x97b0db5b4aa74e77, 0x9047d2a75a34d3ee, // reset_ped_weapon_movement_clipset
0x48f069265a0e4bec, 0xfc2e79b0cb49d54e, // _0x48f069265a0e4bec
0x729bac1b8c64317, 0x644af0d47b01902e, // set_parachute_task_thrust
// 0x9896ce4721be84ba, 0x0, // set_cutscene_trigger_area
0xeeeda5e6d7080987, 0xf50af234b86e0351, // network_change_transition_slots
0xfa1e0e893d915215, 0xa24ecdc98dc81ed5, // _0xfa1e0e893d915215
0x21973bbf8d17edfa, 0x38af70eb3e8a94, // _0x21973bbf8d17edfa
0x886e37ec497200b6, 0x7dd221c91135596a, // is_entity_in_air
0x99bfdc94a603e541, 0xe0e192d65881ac2, // obj_to_net
0x44dbad7a7fa2be5, 0x5b1df403216cd477, // _0x044dbad7a7fa2be5
0xd0263801a4c5b0bb, 0x977d0ff0f921fb32,
0xec3c9b8d5327b563, 0xafd26c4e558d823b, // get_control_normal
0xd7cd9cf34f2c99e8, 0xd464deab5266c12e, // unblock_decision_maker_event
0x3195f8dd0d531052, 0x786af4a44e1b5b4b, // _0x3195f8dd0d531052
0x5a859503b0c08678, 0x73da1542b2f0c458,
0x278f76c3b0a8f109, 0xc75efc344b2fceb8, // _get_num_decorations
0x3cdc1e622cce0356, 0x4054db5fb70ba618, // override_veh_horn
0x46e2b844905bc5f0, 0x528d1cb713d980df, // _nullify
// 0x12782ce0a636e9f0, 0x0,
0xbb9ce077274f6a1b, 0xbd4591245c650283, // task_wander_standard
0xad6875bbc0fc899c, 0xff5362bb04445217, // _0xad6875bbc0fc899c
0xa277800a9eae340e, 0x298ddd544331fb15,
0x34c9ee5986258415, 0x8e3d2a1dfa294fb, // register_int_to_save
0x2f8af0e82773a171, 0x9294ea9b5694081, // task_drive_by
0x4a7d6e727f941747, 0x88c4c02836f71cc6, // _0x4a7d6e727f941747
0x56a8a219b8e829f, 0x87a1f7523b14e2c9, // stop_fire_in_range
0x933c06518b52a9a4, 0x9f7162e310a9fb84, // task_set_sphere_defensive_area
0x949f397a288b28b3, 0x4760a9058742162f, // _0x949f397a288b28b3
0x3afdc536c3d01674, 0x90425f35dd715133, // set_vehicle_enveff_scale
0xc3654a441402562d, 0xcff077f8990d751b, // _set_cam_dof_max_near_in_focus_distance
0x428baccdf5e26ead, 0x26d5ea44545890ed, // _0x428baccdf5e26ead
0x8d7a43ec6a5fea45, 0xdfc7a30776d41f1c, // _get_is_projectile_type_in_area
0x93376b65a266eb5f, 0x73d993bca1cec58d, // set_ped_prop_index
0x121fb4dddc2d5291, 0x53ac171451b28488, // playstats_ros_bet
0x4b53f92932adfac0, 0xeae1362b9f5c7b18, // get_vehicle_index_from_entity_index
0xfd280b4d7f3abc4d, 0x6e15f06772c40ac4, // set_heli_blades_speed
0xc22912b1d85f26b1, 0x770f66a071d3538, // _0xc22912b1d85f26b1
0xed34ab6c5cb36520, 0x9d4ed2b94675ea0a, // set_ped_drive_by_clipset_override
0xaccfb4acf53551b0, 0x1f6a09ae9372ae6c, // new_load_scene_start_sphere
0x5619bfa07cfd7833, 0x7dc925869ba99fc1, // _set_ped_facial_decoration
0xf445de8da80a1792, 0xc04b993e9bacb3d5,
0xb203b4afde53a4f, 0xb1782272fcb4aacb, // _0x0b203b4afde53a4f
0xd3c2e180a40f031e, 0x286c823e0969f22a,
0x6ee9048fd080382, 0x4e1a94bfd954685c, // _0x06ee9048fd080382
0x4bf54c16ec8fec03, 0x7880662a729659de, // get_vehicle_class_max_braking
0xdb6708c0b46f56d8, 0xb61eaf8af5f8ef1a,
0x910a32e7aad2656c, 0xdbea4f184ca4ea54, // get_is_vehicle_secondary_colour_custom
0x4655f9d075d0ae5, 0xdb789c36a5980222, // _0x04655f9d075d0ae5
0xa46b73faa3460ae1, 0xe4ad17ab4ec5011, // _0xa46b73faa3460ae1
0x1ccd9a37359072cf, 0xde1ba36e3bacf7c1, // _set_notification_message_2
0xadbe4809f19f927a, 0x1fa33938bf46eae3, // _mark_object_for_deletion
0x11d862a3e977a9ef, 0xac70371d5467ccc0, // are_all_vehicle_windows_intact
0x46326e13da4e0546, 0x318b0b93a1e366c, // _0x46326e13da4e0546
0x6585d955a68452a5, 0x4631a2b983e6a71a, // _0x6585d955a68452a5
0xbeb2d9a1d9a8f55a, 0x953bafeb49393d3e, // _0xbeb2d9a1d9a8f55a
0x25f87b30c382fca7, 0x3d404fd169632ca,
0xc61b86c9f61eb404, 0x6b9bb8bc34daffd9, // _0xc61b86c9f61eb404
0xaa81b5f10bc43ac2, 0x88cd84c553ef6ed9, // get_num_reserved_mission_objects
0x2b5e102e4a42f2bf, 0xdee36ad64fd35324,
0xee9f297c738720, 0x715473842579507f, // decor_remove
0xc55854c7d7274882, 0x8fa1b4db1d31b12e,
0x595583281858626e, 0x7448716470aa4105, // task_follow_point_route
0xa2767257a320fc82, 0xec3fce1d8cbb37a4, // _0xa2767257a320fc82
0xbb41afbbbc0a0287, 0x39df7ebbdad69f4b,
0x43c851690662113d, 0xb49a488497d2a8fe, // set_ped_max_time_in_water
0x2f3c3d9f50681de4, 0x969f80598f7fc7cf, // _0x2f3c3d9f50681de4
0xecc01b7c5763333c, 0xf328de4d29d7eb24, // get_dlc_vehicle_model
0x5a42ba9fc8da96b, 0x126456df071acb35, // _get_name_of_thread
0x9fedf86898f100e9, 0x4d9d329accb95f04,
0x423de3854bb50894, 0xa8ea180dfdadf854, // network_set_in_spectator_mode
0x9b9039dbf2d258c1, 0xe45a5867882940b9,
0xec9264727eec0f28, 0xd362430cd61a9b08,
0x93b93a37987f1f3d, 0x43ead1f94ec8561f, // task_achieve_heading
0xa6c90fbc38e395ee, 0xf839a4fc3e76d324,
0x1e0b4dc0d990a4e7, 0x7848bcc2a9ff04c2, // set_fade_out_after_arrest
// 0x2b171e6b2f64d8df, 0x0, // network_earn_from_challenge_win
0x333fc8db079b7186, 0x822990e2390829a8, // set_ped_parachute_tint_index
0xa328a24aaa6b7fdc, 0xd097ddc820c7e185, // _transition_to_blurred
0xa87b2335d12531d7, 0xcff1380498f20ff, // stat_set_string
0x61bb1d9b3a95d802, 0x5c58d0ada22491fa, // _set_ui_layer
0x580ce4438479cc61, 0x303cd9cb61bcec23,
0xa0fd21bed61e5c4c, 0xd6fa57ee4bdbeff3, // network_handle_from_member_id
0x863b23efde9c5df2, 0xd30a58e4712eeddb, // is_ped_being_stealth_killed
0xcb82a0bf0e3e3265, 0xf50c2e8138c028f, // _0xcb82a0bf0e3e3265
0x95a7dabddbb78ae7, 0x9dda3334b0556bd8, // _0x95a7dabddbb78ae7
0x570389d1c3de3c6b, 0xb13b4a13090e7801, // _0x570389d1c3de3c6b
0x30b4fa1c82dd4b9f, 0xcec7055fc138cf8d,
0x2e93c796abd3a97, 0x7b08495349ab9ca1, // _0x02e93c796abd3a97
// 0x63eb2b972a218cac, 0x0,
0x6070104b699b2ef4, 0x90a60d41dceb601e, // _0x6070104b699b2ef4
0x6e0859b530a365cc, 0x366b197241f54094, // _set_helicopter_roll_pitch_yaw_mult_health
0x66a49d021870fe88, 0x4f97c61d4c56b8b2,
0xe38cb9d7d39fdbcc, 0x88ebe1c95f2b36d8, // _eject_jb700_roof
0x75a16c3da34f1245, 0x983d75d9630fd905, // _0x75a16c3da34f1245
0xac29253eef8f0180, 0x579646d752bd05ec, // is_ped_still
0xee778f8c7e1142e2, 0xcb75c331dd5ddccc, // _0xee778f8c7e1142e2
0xa0696a65f009ee18, 0xa126fe43ae9add79, // special_ability_charge_normalized
0x49ec8030f5015f8b, 0xa7f023f87af01bb6, // _network_sctv_slots
0x17440aa15d1d3739, 0x15c9dec85034c4f,
0x1eae0a6e978894a2, 0x667e9887f10a4fad, // _0x1eae0a6e978894a2
0x3b504cf259931bc, 0xe800dc85fdf60f85, // add_text_component_integer
0x36b77bb84687c318, 0x4b8b69dae5bac592, // _0x36b77bb84687c318
0x7beb0c7a235f6f3b, 0xfb439458a2b0897f, // create_pick_up_rope_for_cargobob
0x3e8349c08e4b82e4, 0xf9667d8f97480a54, // can_create_random_ped
// 0x51db102f4a3ba5e0, 0x0, // _0x51db102f4a3ba5e0
0x3d2fd9e763b24472, 0x29b4e82a77d0306, // _object_value_get_string
0x9c74b0bc831b753a, 0x7e92dee57adb65e9, // set_ped_visual_field_peripheral_range
0x8378627201d5497d, 0xe53211b793893ffd, // set_ped_chance_of_firing_blanks
0x19531c47a2abd691, 0x8c0025a3f2af47dd, // reset_player_input_gait
0x1b8247a7a8b9ad1, 0x4e1190a8d88abdb7,
0xbfdf984e2c22b94f, 0x7e7ed9c91ecf37f2, // set_vehicle_name_debug
0x42a8ec77d5150cbe, 0x288465326f320354, // set_vehicle_steer_bias
0xdbc86d85c5059461, 0x27ecff7baf3864b5, // get_vehicle_class_max_traction
0xbddb8d9ec6bcf3c, 0x9aa80ca39f863d9d, // set_ped_group_member_passenger_index
0x1f2300cb7fa7b7f6, 0xdc1105cdb8032dca,
0xbad8f2a42b844821, 0x14ab1cbd24964da7, // network_is_friend_index_online
0x977db4641f6fc3db, 0xdb2f38469a693f8e, // set_player_parachute_model_override
0x5a0a3d1a186a5508, 0x351036c5225186fd,
0x9a77dfd295e29b09, 0xb75b2cddbcf03fa6, // _0x9a77dfd295e29b09
0x5ef37013a6539c9d, 0x56a5285283c8f98b, // _get_num_parent_peds_of_type
0xc6f580e4c94926ac, 0x5533afc8fcf79ddc, // _set_notification_message_3
0xa1dd317ea8fd4f29, 0xa3b3e54143896fe9, // set_vehicle_damage
0xccba154209823057, 0x68135a7434393cc1, // is_object_within_brain_activation_range
0x1a6478b61c6bdc3b, 0x61a52f6201aa9959, // get_named_rendertarget_render_id
0xa0ad7e2af5349f61, 0xc75b8261937de3b7,
0x8ec74ceb042e7cff, 0xcb1db79af4b7a4bc, // _0x8ec74ceb042e7cff
0x8a7391690f5afd81, 0x739a7d2db09904e4, // set_object_targettable
0xbda5df49d080fe4e, 0x67ad0714691bdff0, // task_patrol
0xe4cb7541f413d2c5, 0xe2b85980ac6dcad1, // _get_heli_main_rotor_health
0x439bfde3cd0610f6, 0xf10148167495c2fd,
0x8968400d900ed8b3, 0x277489a9b64e1d40, // waypoint_playback_start_aiming_at_coord
0x299eeb23175895fc, 0xce5a2c773b9fdc41, // set_network_id_can_migrate
// 0x29b260b84947dfcc, 0x0, // network_spent_bounty
0xe41ca53051197a27, 0xd3819a29dd56f51b, // is_blip_on_minimap
0x10c54e4389c12b42, 0xf686074d2145120, // clear_player_parachute_pack_model_override
0xc406be343fc4b9af, 0x1cc3274269dbcb21,
0x238db2a2c23ee9ef, 0x9287bfee1d9f6ef, // is_player_wanted_level_greater
0x202709f4c58a0424, 0x1f85ad4b26b92795, // _set_notification_text_entry
0xc44aa05345c992c6, 0x9e5361cebac3a352, // set_ped_random_props
0xea386986e786a54f, 0x7ac8df0b83eb4c6b, // delete_vehicle
0xc7abac5de675ee3b, 0xa704058ee0b7fe04,
0xfba550ea44404ee6, 0x97f21fd01f5c91a, // set_vehicle_needs_to_be_hotwired
0x7503f7948f491a7, 0x247d6e3fbe2fceaa, // request_collision_at_coord
0x426141162ebe5cdb, 0xc5301535e0afe21f, // network_get_gamertag_from_handle
0xcae1dc9a0e22a16d, 0xc79345083bccdc56, // get_weapon_object_from_ped
0xb3924ecd70e095dc, 0x9ea1e2f3ada356e7, // get_vehicle_mod_variation
0x8507bcb710fa6dc0, 0x5a55f54738bbf615, // has_ped_received_event
0xd9a897a4c6c2974f, 0x6359f1f7f5174d4a, // set_synchronized_scene_looped
0xa7c4f2c6e744a550, 0xc92aa0dbddde8bb8, // get_vehicle_max_number_of_passengers
0xe41885592b08b097, 0xf277688e4b531aa7, // task_vehicle_aim_at_ped
0xc77720a12fe14a86, 0xcf73ed7f74f29138, // play_synchronized_entity_anim
0x6d03bfbd643b2a02, 0x7440d26962dd2eb4, // _network_get_server_time
// 0xf78f94d60248c737, 0x0, // _0xf78f94d60248c737
0xcee4490cd57bb3c2, 0xe9b30318257f029d, // is_vehicle_in_garage_area
0xe5f773c1a1d9d168, 0xe2eb264502b9c116, // set_local_player_invisible_locally
0x5edef0cf8c1dab3c, 0x701ae414ae6c6433,
0x375f0e738f861a94, 0x2a1fba66f74d782, // special_ability_reset
0x14e85c5ee7a4d542, 0x77f5a8b03703391, // set_vehicle_searchlight
0x5f43d83fd6738741, 0x334ac6fc831e4abc,
0xaa0a52d24fb98293, 0xb623c0af503b1ea7, // is_vehicle_visible
0x10ab107b887214d8, 0x28dac95a7546c6e7, // task_vehicle_shoot_at_ped
0x9de327631295b4c2, 0x4571d88090e0f77, // is_ped_swimming
0x7a192be16d373d00, 0x951f0d4171e5b81d, // task_aim_gun_scripted
// 0x2b5aa717a181fb4c, 0x0, // _0x2b5aa717a181fb4c
0x4f930ad022d6de3b, 0x5a719acf626b92c0, // get_vehicle_class_max_agility
0x8c8d2739ba44af0f, 0xe2e6dd5abecf84c2, // _0x8c8d2739ba44af0f
0xb6ba2444ab393da2, 0xcee359851f3c8198, // remove_relationship_group
0x4448eb75b4904bdb, 0x340f713a0f70cae2, // load_scene
0xb736a491e64a32cf, 0x4955686ef8308b47, // set_entity_as_no_longer_needed
0x8c4b92553e4766a5, 0xa8dc0d4489fec63c, // _is_vehicle_neon_light_enabled
0x3ec8bf18aa453fe9, 0xd849f5c793b0d3dd, // was_counter_activated
0x7583b4be4c5a41b5, 0x261c6d5c12d2b87a, // stat_get_number_of_minutes
0xfbcfa2ea2e206890, 0x3d766f5fd36e703e,
0xc6e0e2616a7576bb, 0xcec2a3315151559c,
0x8a1c8b1738ffe87e, 0x535c9c52117da0ad,
0x6c0023bed16dd6b, 0x5356f3c969417f71, // _0x06c0023bed16dd6b
0x80338406f3475e55, 0x713febe56d2bd403, // begin_text_command_scaleform_string
0x7b3703d2d32dfa18, 0xcfc70bdc1d078fe, // get_entity_quaternion
0x57c5db656185eac4, 0x92db511543af4538, // set_entity_trafficlight_override
// 0xcce26000e9a6fad7, 0x0,
0x208784099002bc30, 0x65f534ddbf48606f, // _0x208784099002bc30
0xef01d36b9c9d0c7b, 0x3acb8cb68abafab1, // activate_frontend_menu
0x873b82d42ac2b9e5, 0x8950ed5730f62ee8, // get_vehicle_attached_to_cargobob
0x24a60deb0ea69f0, 0x611594da095be345, // _0x024a60deb0ea69f0
// 0x9bdf59818b1e38c1, 0x0, // _get_num_props_from_outfit
0x580417101ddb492f, 0x833b1a3d9f713e03, // is_control_just_pressed
0xba739d6d5a05d6e7, 0xecd8c6cc59f9955e, // playstats_prop_change
0xd39b3fff8ffdd5bf, 0xb7ab69880d656284, // _0xd39b3fff8ffdd5bf
0xd45dc2893621e1fe, 0xd3b014d54aea6296, // get_entity_pitch
0xb1b1ea596344dfab, 0x5ce11831d071ebc9, // is_itemset_valid
0xcdda42f9e360ca6, 0xb5a86d27af1a1406, // _0x0cdda42f9e360ca6
0x93c8b64deb84728c, 0x7a521f1fc4cdf679, // get_ped_source_of_death
0x3655f544cd30f0b5, 0x4959c58de045df78, // get_rope_vertex_count
0xe18b138fabc53103, 0x15c85368e432c647,
0x94a8394d150b013a, 0x9a8251fc04519edc,
0xd5bb4025ae449a4e, 0xc54fc54752882f2d, // _set_network_task_param_float
0x460bc76a0e10655e, 0x12bc8708cc473113, // is_ped_on_mount
0xe6f13851780394da, 0xa984f83e1b91014f, // _0xe6f13851780394da
0xea2f2061875eed90, 0xa40887cdafca7502,
0xe9676f61bc0b3321, 0x715998283b012f11, // has_collision_loaded_around_entity
0x7aa5b4ce533c858b, 0x209dacc0922d288c,
0x87d51d72255d4e78, 0xdd9e6db1a6a3e1f2, // draw_scaleform_movie_3d
0x75a9a10948d1dea6, 0xa0d67403a74c9705, // set_minimap_component
0xa53ed5520c07654a, 0x6eb479eb6ff2894d, // set_entity_no_collision_entity
0x644546ec5287471b, 0x3131bb06d6934fe4,
0x3b963160cd65d41e, 0x19e990cdd7ae5c79, // get_number_of_vehicle_colours
0x3448505b6e35262d, 0x42e083a703bd8bf, // texture_download_get_name
0xc7272775b4dc786e, 0x5f62f61da4bb2c0b, // stop_cutscene
0xb4c8d77c80c0421e, 0x95c408e367a4399f, // _0xb4c8d77c80c0421e
0x5f15302936e07111, 0x98e765cb9e761233, // set_text_render_id
0xbc3cca5844452b06, 0x5418d000e3892f32, // _0xbc3cca5844452b06
0xeaa572036990cd1b, 0xf53c391a859ace88,
0xa921ded15fdf28f5, 0x9db9a6268543c077, // network_clear_character_wallet
0xc946fe14be0eb5e2, 0xdb8ba9faeba7aa3, // task_guard_sphere_defensive_area
0x41bd2a6b006af756, 0x7c1c88877e8aaa50, // int_to_playerindex
0xbc1d768f2f5d6c05, 0x771810413d71c060, // _network_hash_from_player_handle
0x68d353ab88b97e0c, 0x71989a566eeca28, // _get_first_parent_id_for_ped_type
0x1a24a179f9b31654, 0xfc40dd2526841632, // network_is_friend
0xf5bb8dac426a52c0, 0x5495756d489336b5, // _0xf5bb8dac426a52c0
0xdf2e1f7742402e81, 0xdb2f66be96a97789, // _animate_gameplay_cam_zoom
0x44f28f86433b10a9, 0xe05bcfd9e12ae8d8, // is_prev_weather_type
0xd966d51aa5b28bb9, 0xe13e9dcb2041ebc1, // give_weapon_component_to_ped
0x56c8b608cfd49854, 0xca60c9df983245f9,
0xed6d8e27a43b8cde, 0xd845d2dbfbe133c4, // _0xed6d8e27a43b8cde
0x5e0165278f6339ee, 0x9e203afc455ee066, // _0x5e0165278f6339ee
0x21a1684a25c2867f, 0xf874bdef39a98f7d, // network_get_player_loudness
0xe131a28626f81ab2, 0x5856cd5a7124df2d, // get_ped_prop_texture_index
0xba96394a0eecfa65, 0xb4c456243c3edb69,
0x52f0982d7fd156b6, 0xce9f8d3bdd7206b,
0xc4bbf625ca98c4e, 0xdeeebbce424e6f55, // _is_ai_blip_always_shown
0xf0210268db0974b1, 0x5365bdc6d8a34b95, // network_remove_presence_invite
0x9072c8b49907bfad, 0x7292b2edb334b14, // is_ambient_speech_playing
0x31acb6aba18c729, 0x35198a4d7e2f8bfe, // _0x031acb6aba18c729
0x5a59271ffadd33c1, 0x89f20c4a841a3473, // does_scenario_exist_in_area
0x45f1de9c34b93ae6, 0xaadd45f5da54f1c8, // set_cam_inherit_roll_vehicle
0x1de0f5f50d723caa, 0xa07f34305110961b, // _0x1de0f5f50d723caa
0x21d04d7bc538c146, 0x9a1a35cbbf391c78, // _0x21d04d7bc538c146
0x4851997f37fe9b3c, 0xb04a838ee49fbbad, // stat_set_float
0xd01005d2ba2eb778, 0xac9d950541866e3f, // _0xd01005d2ba2eb778
0x74bd83ea840f6bc9, 0xe91a0159e5b74c02,
0x22da66936e0fff37, 0x9e7041638b5499f4, // _0x22da66936e0fff37
// 0x94f12abf9c79e339, 0x0, // _0x94f12abf9c79e339
0x3841422e9c488d8c, 0xa7a57e7757ed035e, // clear_sequence_task
0x6b7513d9966fbec0, 0xbde9076965fcc2c, // set_ped_drops_weapon
0x47e4e977581c5b55, 0x3af2b3b68dd52355, // is_ped_ragdoll
0x9dcff2afb68b3476, 0xa50d8c39c0d226a8, // network_get_found_gamer
// 0x2801d0012266df07, 0x0, // _0x2801d0012266df07
0x91ef6ee6419e5b97, 0xe2d6c9163931ba70, // _0x91ef6ee6419e5b97
0x6ddbf9dffc4ac080, 0x48c0f400b56fc429, // _0x6ddbf9dffc4ac080
0x19aac8f07bfec53e, 0xbb8f0b8d18ff4982, // is_model_a_vehicle
0x645d0b458d8e17b5, 0x29c7798a160b50ed, // can_set_enter_state_for_registered_entity
0x17c07fc640e86b4e, 0x61b226c460a8fcc2, // get_ped_bone_coords
0x59424bd75174c9b1, 0xfd435b95c49e4547,
0xd53acdbef24a46e8, 0xbbba11f675ce9e98,
0xeffed78e9011134d, 0x7d8e16fb3c783d5e, // get_ped_weapontype_in_slot
0x49c32d60007afa47, 0x5a8abda4992da968, // is_player_control_on
0x67406f2c8f87fc4f, 0x34a7f341d19b9f7b, // uncuff_ped
0x629bfa74418d6239, 0x65f544b458249682, // set_vehicle_as_no_longer_needed
0x405591ec8fd9096d, 0x6e1fcb9f8ea4da08, // _0x405591ec8fd9096d
0x1ce592fdc749d6f5, 0x266c81c04f8214cf, // _draw_scaleform_movie_3d_non_additive
0x71a5197d6afc8b3, 0x692bb84fc63fb91e,
0xfedb7d269e8c60e3, 0x5a488f57f21b3451, // attach_cam_to_entity
0x772960298da26fdb, 0xeeca910c75bff02b, // get_vehicle_mod
0x9e778248d6685fe0, 0xeec8262bd93af156, // _0x9e778248d6685fe0
// 0x4b490a6832559a65, 0x0, // attach_rope_to_entity
0x405dc2aef6af95b9, 0x6770bf761b8e6ef7, // _0x405dc2aef6af95b9
0xa352c1b864cafd33, 0xc113a61827bce74a, // restore_player_stamina
0x53f4892d18ec90a4, 0xe2270d4da1247350, // _0x53f4892d18ec90a4
// 0x11883f41211432a, 0x0, // _0x011883f41211432a
0xb85f26619073e775, 0x2099e5e61f809c4f, // set_hd_area
0xaa6a47a573abb75a, 0x8d2f681a9f7e5b6f, // network_access_tunable_bool
0xae8ce82a4219ac8c, 0xef6587868d039a4f, // _get_heli_tail_rotor_health
0xcddc2b77ce54ac6e, 0xcffbe889d65db477, // task_writhe
0xe52b8e7f85d39a08, 0xd8e6a14e9458a3bd, // _set_ai_blip_type
0x10bd227a753b0d84, 0xa1cc958cc911ad1,
0xc906a7dab05c8d2b, 0x8c1596bad35d957a, // get_ground_z_for_3d_coord
0x20c6c7e4eb082a7f, 0x86f5504293efc0c6, // _0x20c6c7e4eb082a7f
0x7ea2b6af97eca6ed, 0x90346dace0a79a81,
0xea02e132f5c68722, 0x428c55a965f78103, // set_entity_is_target_priority
0xdc833f2568dbf6, 0x8362ffa61bb1bc36, // display_onscreen_keyboard
0x586afe3ff72d996e, 0x7bc3899bf7085a7d, // get_blip_coords
0x2016c603d6b8987c, 0x36b774208cdabad5, // _0x2016c603d6b8987c
0x4a2d4e8bf4265b0f, 0x78af9e1e56a2b5d5, // _0x4a2d4e8bf4265b0f
0xd3cd6fd297ae87cc, 0x43598712ec9e921c, // set_blip_flash_timer
0x2b626a0150e4d449, 0x32f4e9c78f0a6c92,
0x8c2d6c52a3104bb, 0x4016ecda17563175,
0x9b2bd3773123ea2f, 0x2dc029018b618fb8, // _0x9b2bd3773123ea2f
// 0xc16de94d9bea14a0, 0x0, // rope_reset_length
0x8b6817b71b85ebf0, 0xcdb0be96af54d877, // is_streaming_additional_text
0x8cc469ab4d349b7c, 0xcd1d6d98e59a09b0, // _0x8cc469ab4d349b7c
0x394b9cd12435c981, 0x34c803c2bc1cafb2, // _set_synchronized_scene_occlusion_portal
0x53e8cb4f48bfe623, 0x6c296f3a10e6939b, // is_ped_climbing
0x18ff00fc7eff559e, 0x8ccaabead6ee0a13, // apply_force_to_entity_center_of_mass
0xfcbdce714a7c88e5, 0x66de54bd13b1bd88, // has_sound_finished
0x513403fb9c56211f, 0xfb4925a947e64714, // set_gameplay_hint_fov
0xa7b2458d0ad6ded8, 0x50e893c437d3ac10, // remove_ped_helmet
// 0x703cc7f60cbb2b57, 0x0, // _0x703cc7f60cbb2b57
0x98760c7461724cd, 0x7c07eae6d6d106bb,
// 0xdbd2056652689917, 0x0, // is_network_vehicle_been_damaged_by_any_object
0xa50a1eedad01e65, 0x825e05c179f7d608, // set_entity_records_collisions
0xa2e9c1ab8a92e8cd, 0xcfcaab7403da452a, // _0xa2e9c1ab8a92e8cd
0xbe8be4fe60e27b72, 0xd99530e6e53b24bf, // set_blip_as_short_range
0xf3cc740d36221548, 0xe0511da19ab37f5c, // get_vehicle_color
0xaf35d0d2583051b0, 0xc651c43ab13a15e5, // create_vehicle
0x149aee66f0cb3a99, 0x9e7df55c9d7e2540, // _0x149aee66f0cb3a99
0x49b99bf3fda89a7a, 0x703744dbebd1252b, // _can_ped_speak
0x95a88f0b409cda47, 0x6f10e9b95245828b, // set_vehicle_number_plate_text
// 0x2c328af17210f009, 0x0, // _0x2c328af17210f009
0x8c044c5c84505b6a, 0xd95a5ecea48d8c3, // get_vehicle_model_acceleration
0x97d47996fc48cbad, 0xc581305829d875ea,
0x81aa4610e3fd3a69, 0x4519579164cf69f, // network_buy_heli_strike
0x1115f16b8ab9e8bf, 0xdc97362660946df9, // add_text_component_substring_time
0x132f52bba570fe92, 0xaf894373822c8b54, // get_closest_road
0x45bbcba77c29a841, 0x8b4a9ad7825395fd, // knock_ped_off_vehicle
0x6af0636ddedcb6dd, 0xb4b3aeabe432069b, // set_vehicle_mod
0xa238192f33110615, 0xe846cea840ad1017, // _0xa238192f33110615
0x892b6ab8f33606f5, 0x6bf55e3e0f51145a, // _0x892b6ab8f33606f5
0x3a539d52857ea82d, 0x8ff43f2584faa061, // play_vehicle_door_open_sound
0xf1160accf98a3fc8, 0x4167b14d99bd7d75, // remove_vehicle_recording
// 0xfd1d220394bcb824, 0x0, // set_multiplayer_hud_cash
0x5aab586ffec0fd96, 0x67485074c2f23c15, // _0x5aab586ffec0fd96
0x2615aa2a695930c1, 0xa40c2b6387e05522, // network_are_transition_details_valid
0x2e7b9b683481687d, 0x3245694e65cc4562, // special_ability_charge_small
0x72de52178c291cb5, 0xc5b91c5a37a7bc35,
0x74e20c9145fb66fd, 0xbd0c0793be016fe0,
0x67722aeb798e5fab, 0x112676e834169f33, // is_ped_on_vehicle
// 0xa03d4ace0a3284ce, 0x0, // _network_earn_from_gang_pickup
0xbac038f7459ae5ae, 0xb29314fdacfd865e, // get_cam_coord
0xf854439efbb3b583, 0xa6eb5be9706d75d,
0xfca9373ef340ac0a, 0xb87f249e4a6384a3,
0x9243bac96d64c050, 0x84cfe9237092e41b,
0xcbbd7c4991b64809, 0xf6523ed2fb266878, // fillout_pm_player_list
0xb721981b2b939e07, 0xc79b88235ca0a6c2, // get_player_invincible
0xafc7e5e075a96f46, 0x9f2d3b1d1363b691, // _playstats_ambient_mission_crate_created
0x89215ec747df244a, 0x7393af2dd0e51dd8, // _0x89215ec747df244a
0x6ce36c35c1ac8163, 0x18d63d71d9cb1524,
0xbbb45c3cf5c8aa85, 0xe8601d6a0ce713a6,
0xd69411aa0cebf9e9, 0x367904f70fe2b6ee, // _0xd69411aa0cebf9e9
0xc208b673ce446b61, 0xbe7d976300d6e27f, // set_player_switch_outro
0xfe466162c4401d18, 0x5246c2012139fd35, // start_shape_test_box
0xa0d3d71ea1086c55, 0x49ae866f340da815, // is_any_ped_shooting_in_area
0xf0b67a4de6ab5f98, 0xbadacd2849bc0e8c, // clear_player_has_damaged_at_least_one_ped
0xe0a7d1e497ffcd6f, 0x66d901f8097e8e86, // set_player_wanted_level_now
0x4967a516ed23a5a1, 0xb9f8f8eacd4aeb66, // get_vehicle_mod_color_2_name
0xb335f761606db47c, 0x846c30837f025c5d, // _0xb335f761606db47c
0xfb6db092fbae29e6, 0xde1422fa669581fd, // _network_earn_from_ambient_job
0x3e5ae19425cd74be, 0xba56d8052297a73b, // _array_value_get_integer
0x60fe567df1b1af9d, 0xe755d52af808318e, // _start_save_array
0x8bd6c6dea20e82c6, 0x5bac542b7625c26a, // _0x8bd6c6dea20e82c6
0x44a0870b7e92d7c0, 0xb1ae03136e03301e, // set_entity_alpha
0xee99784e4467689c, 0x9b45fa4f3b7e1a65, // network_spent_in_stripclub
0x511f1a683387c7e2, 0xeb1ce6563ab2fdfd, // _0x511f1a683387c7e2
0x1dda930a0ac38571, 0x9f878fe3f23e2c8b, // task_turn_ped_to_face_coord
0x1cae5d2e3f9a07f0, 0x5ef60f8e1f2daaec, // _0x1cae5d2e3f9a07f0
0xb8b52e498014f5b0, 0xa549cb3b1293199a, // _0xb8b52e498014f5b0
0xd202b92cbf1d816f, 0xbe903c985cca7c01, // _draw_notification_with_icon
0x1897ca71995a90b4, 0x239e30c22d4ee2c6,
0xf372bc22fcb88606, 0x9315fcf6cfe2ab41, // add_relationship_group
0x36ccb9be67b970fd, 0x178fc1710e62fea5, // _0x36ccb9be67b970fd
0xe05e81a888fa63c8, 0x9fd099b0593cd91d, // set_network_id_exists_on_all_machines
0x9c720776daa43e7e, 0x104fa8dc0e2278e8, // clear_ped_wetness
0x85443ff4c328f53b, 0xdbb8379205debbfe,
0x1f464ef988465a81, 0x168188896745c353, // add_hospital_restart
0xcb00196b31c39eb1, 0x37eb897d6d75166f, // _0xcb00196b31c39eb1
0x3ea03af85a85cb7, 0x8d59673a7e40adea, // _0x03ea03af85a85cb7
0xd0a9f0e7bd91e3c, 0x24f08f9426a12b11, // stat_slot_is_loaded
0x930de22f07b1cce3, 0x857362f4be6039f4, // _0x930de22f07b1cce3
0xb80ca294f2f26749, 0x2304946fe02ab910, // is_ped_weapon_ready_to_shoot
// 0xf020c96915705b3a, 0x0, // _draw_notification_4
0x228d3d94f8a11c3c, 0xcb46b7f7245145d9, // has_this_cutscene_loaded
0x6f761ea47c1d3ed, 0x271071a087a1badb, // _0x06f761ea47c1d3ed
0x1cba05ae7bd7ee05, 0x75f12d9731cd9783, // _0x1cba05ae7bd7ee05
0x3117d84efa60f77b, 0x260e491ffe13e891, // _0x3117d84efa60f77b
0x6f697a66ce78674e, 0x34da00d7712c21b5, // _0x6f697a66ce78674e
0x26af0e8e30bd2a2c, 0xeb2ae681052facd3, // _0x26af0e8e30bd2a2c
0x290e2780bb7aa598, 0x8991da79d3df4bae, // request_action_mode_asset
0x30cf4bda4fcb1905, 0x9e7ab96d7830e5b1,
0xc1f6ebf9a3d55538, 0x1824656166809c13, // _0xc1f6ebf9a3d55538
// 0x2a0a62fcdee16d4f, 0x0, // request_stealth_mode_asset
0xfbfc01ccfb35d99e, 0xff29c0328e1d9f8d, // is_ped_in_any_sub
0x11d1e53a726891fe, 0x214f8b8ab8262218, // _0x11d1e53a726891fe
0x2622e35b77d3aca2, 0x6c3d450f961fea9b, // set_ped_weapon_movement_clipset
0xeb6891f03362fb12, 0xb526da140b61dbb,
0xa5e41fd83ad6cef0, 0xd6b80456723e619e, // is_blip_flashing
0x723c1ce13fbfdb67, 0xf155b9f8cdea94f5, // _0x723c1ce13fbfdb67
0x9d80cd1d0e6327de, 0x63974d63d653ecef, // network_invite_gamers
0xa72bc0b675b1519e, 0xf5db888c353e2bed,
0xf70731baccfbb96, 0x6a2beb76f34ab0ff,
0x4ba92a18502bca61, 0xe797e40d3e5ed014, // _0x4ba92a18502bca61
0x8844bbfce30aa9e9, 0x53d6cdf9a1057fdb, // clear_ped_alternate_walk_anim
0x73b000f7fbc55829, 0xe641355959f912ca, // network_get_transition_members
0xa3b0c41ba5cc0bb5, 0xcbe6af58552c63b2, // stop_sound
0x70033c3cc29a1ff4, 0xdd81af79d6772d05, // set_anim_looped
0xb8ff7ab45305c345, 0x12d95e2959cbd0ee, // start_vehicle_alarm
0xbec7076d64130195, 0xbecc4fbac9c8e5e7, // give_achievement_to_player
0x9e8c908f41584ecd, 0xa9d10d2c7ffc0fdf, // set_ped_move_anims_blend_out
0x2208438012482a1a, 0x880b00f3fae4c022, // _0x2208438012482a1a
0x353fc880830b88fa, 0x44d426446faf55fb, // release_sound_id
0xe16142b94664defd, 0xf0a217fe853ec9ac, // _0xe16142b94664defd
0x6e9c742f340ce5a2, 0x6f8f62a5243893d1, // get_player_parachute_pack_tint_index
0x3dda37128dd1aca8, 0x4e609369225efc41, // _0x3dda37128dd1aca8
0x725a4ccfded9a70, 0x7957afe79874e7d, // set_ped_current_weapon_visible
0x7a2d8ad0a9eb9c3f, 0xc16c998d785abf3a,
0x8bad02f0368d9e14, 0xd386fbdf1e8cd84, // has_entity_collided_with_anything
0x62ab793144de75dc, 0xccd9f87c7ec21379, // hide_ped_blood_damage_by_zone
0x1090044ad1da76fa, 0x5894dc159447e10a,
0xba7148484bd90365, 0xe3f1dcc670198d2d, // _add_scaleform_movie_method_parameter_string
0x7c65dac73c35c862, 0x4a3bd9d189356b69, // set_vehicle_door_open
0xaf9e59b1b1fbf2a0, 0x712b120c5a12d9f5, // get_ped_reset_flag
0x27cb772218215325, 0xdd9a940b22dd40c2,
0x2eb41072b4c1e4c0, 0xd0f2465af6f5e0b1, // get_street_name_at_coord
0x813a0a7c9d2e831f, 0x7e4fd94ba083e45b, // is_ped_headtracking_entity
0xfa8904dc5f304220, 0xfecf68385821ac9a, // network_session_kick_player
0xb91b4c20085bd12f, 0x26a7056bfb1177f0, // get_vehicle_lights_state
0x378e809bf61ec840, 0x5169c81c134cf70b, // _draw_notification_3
0xb203913733f27884, 0x3dee082a9850b2fe, // set_blip_bright
0x150e808b375a385a, 0xe02a7b5ee70ef82f, // create_forced_object
0x50969b9b89ed5738, 0x34a6a87253b1d35d, // set_ped_weapon_tint_index
0xde564951f95e09ed, 0x41c955c667f66f10, // network_fade_out_entity
0x2de7efa66b906036, 0x82d58da03789627a, // _get_scaleform_movie_function_return_int
0x4f5070aa58f69279, 0xb024bd7ba99751da, // _get_is_slow_road_flag
0xcac66558b944da67, 0x3c816554df1fc144, // _0xcac66558b944da67
0x14d29bb12d47f68c, 0xdeda5c6b41643c72, // _0x14d29bb12d47f68c
0x25cb5a9f37bfd063, 0x8553bfc970ae2ec8,
0xf42323798a58c8c, 0x58fc43c40a92dbef, // is_entity_touching_model
0xef21a9ef089a2668, 0xe6882f1e16916952, // set_audio_scene_variable
0xe9b09589827545e7, 0xd155487e7e231d33, // report_crime
0xfaa457ef263e8763, 0xf93d5fa77c69805a, // _0xfaa457ef263e8763
0x5a6ffa2433e2f14c, 0x3d20368e3e7da9ab, // _0x5a6ffa2433e2f14c
0x48de78af2c8885b8, 0x7ed9d272cb2f0ca2, // network_clan_get_membership_desc
0x7368e683bb9038d6, 0x68bcb67a166a16ce, // network_unregister_networked_entity
0x9becd4b9fef3f8a6, 0x8f40cb8dde1232ce, // _0x9becd4b9fef3f8a6
0x32c7a7e8c43a1f80, 0x197788925bf207b5, // _0x32c7a7e8c43a1f80
// 0x1b9025bda76822b6, 0x0, // blip_siren
0xbc38b49bcb83bc9b, 0xc35da253230b9f05, // end_text_command_set_blip_name
0xccf1e97befdae480, 0x17f48c7dff3bef83, // _get_entity_collison_disabled
0x5262cc1995d07e09, 0x5cfb4d665c2a88d, // set_no_loading_screen
0x44a8fcb8ed227738, 0x2d49816199c51b0c, // get_world_position_of_entity_bone
0xdea92412fcaeb3f5, 0x4b375a6f386d1059, // get_ped_combat_movement
0x87b63e25a529d526, 0x4a7ab87632044178, // get_vehicle_livery_count
0xf9acf4a08098ea25, 0x5a6fe4c87d1c7ead, // _0xf9acf4a08098ea25
0xfc52e0f37e446528, 0xede64042cead966f, // remove_all_projectiles_of_type
0x659427e0ef36bcde, 0x2bc4614f764725a6, // task_vehicle_mission
0x1e8e5e20937e3137, 0x27cafaac9e3db655, // is_ped_ringtone_playing
0xfdf3d97c674afb66, 0x11dfdc1a614e78c2,
0xede326d47cd0f3e, 0x767f544e943fb776, // _0x0ede326d47cd0f3e
0x7c814d2fb49f40c0, 0x8da50a8c94bed8b2,
0xb980061da992779d, 0x81feedf0a4196b0f, // is_ped_human
0xa7e30de9272b6d49, 0x91bacdf87def06a, // _0xa7e30de9272b6d49
0x5e5e99285ae812db, 0x1da488a1fd5528e9,
0xf1cea8a4198d8e9a, 0x281dc487cd66874b, // _0xf1cea8a4198d8e9a
0x13b350b8ad0eee10, 0xa8a58275ce7c3be5,
0x50b56988b170afdf, 0x5238ceeb40c9050b, // _set_ped_eye_color
0xa150a4f065806b1f, 0x8c7673eb7ad38963, // network_can_communicate_with_gamer
0x933bbeeb8c61b5f4, 0x69f43c768f86bc3,
0xf28965d04f570dca, 0x13c3fe558ed056ee, // force_ped_motion_state
0xe4e53e1419d81127, 0x7b28c9eb176105d1, // _network_does_tunable_exist_hash
0xcca1072c29d096c2, 0xf3622d832771d4b9,
0x1eac5f91bcbc5073, 0x61d8ae977ed6b25d, // _0x1eac5f91bcbc5073
0x6a03bf943d767c93, 0x29e95727a3de7ade, // _is_ped_standing_in_cover
0xeffb25453d8600f9, 0x26f0a4e8798e63f9,
0x212a8d0d2babfac2, 0x25fbda8ba15a928a, // new_load_scene_start
0x5343532c01a07234, 0xf62cd3b9a6291969, // waypoint_recording_get_num_points
0x9aeb285d1818c9ac, 0x3f4dbd0f910c454b,
// 0xb45eff719d8427a6, 0x0, // _0xb45eff719d8427a6
0xd38c4a6d047c019d, 0xebcbd2deebf3ba9d,
0x9007a2f21dc108d4, 0x6b7e5f3e065ab93, // _0x9007a2f21dc108d4
0x9a8d700a51cb7b0d, 0xb813c678f8323528, // get_entity_speed_vector
0x2f25d9aefa34fba2, 0xc6a79a7458b90086, // register_target
0x4e5c93bd0c32fbf8, 0x12f5ddeab00b8213, // reserve_network_mission_objects
0x1b857666604b1a74, 0x9980ae643a60f372, // _0x1b857666604b1a74
0x112942c6e708f70b, 0x16d56d398fb73be7, // set_ped_to_inform_respected_friends
0x916f0a3cdec3445e, 0x46d12e4d89cfebbb,
0xa516c198b7dca1e1, 0x1e113d5f49d20644, // _clamp_gameplay_cam_pitch
0xcf8bd3b0bd6d42d7, 0xa5802c7de8f10f39, // _network_force_local_use_of_synced_scene_camera
0x34770b9ce0e03b91, 0x753cda136f226b28, // _0x34770b9ce0e03b91
0xfaa10f1fafb11af2, 0x371198b155442603, // set_player_visible_locally
0xcfdbdf5ae59ba0f4, 0x60eceb0ee3d8b4fd, // _end_text_command_objective
0xe07bca305b82d2fd, 0x79f64705e08c0951, // stat_save
0x2238e588e588a6d7, 0xb1e5bf6a447fd19c, // stop_cinematic_cam_shaking
0xa44ff770dfbc5dae, 0x6c941f751e68b0d9,
0x56ce820830ef040b, 0xd59a497fed2b3289, // _network_session_get_unk
0x21543c612379db3c, 0xbc87a51648397337, // get_vehicle_recording_id
0xedd91296cd01aee0, 0x42b463a42a598a38, // set_cam_far_dof
0x2eac52b4019e2782, 0xbaa5e93732372e34,
0x9d6bfc12b05c6121, 0xe56df2d1b4265fa7, // is_horn_active
0x8951eb9c6906d3c8, 0xc6fb169e3887184d,
0x891804727e0a98b7, 0x3b3aef3a73fb80c9, // create_pickup_rotate
0x55598d21339cb998, 0x5e1fa2076d53c3f5, // _clear_notifications_pos
0x5f91d5d0b36aa310, 0x26227e84df922de7,
0xbc8dbdca2436f7e8, 0x525753dc633d9f8, // get_blip_from_entity
0xe42fcdfd0e4196f7, 0xb016b122c6322f0c, // block_decision_maker_event
0xf751b16fb32abc1d, 0x31bfb13a57714134, // _0xf751b16fb32abc1d
0x8269816f6cfd40f8, 0x8462666c01912360, // _0x8269816f6cfd40f8
0xbfa48e2ff417213f, 0x8fcf53827ac6136e, // does_object_of_type_exist_at_coords
0x317b11a312df5534, 0xa979677a83b8bbac, // set_render_train_as_derailed
0x733c87d4ce22bea2, 0x86daf422c98b71d3, // _0x733c87d4ce22bea2
0x8c71288ae68ede39, 0xa2f1fb3287be81ec, // network_is_player_muted_by_me
0x923cb32a3b874fcb, 0x57a2affe0b85c36d, // request_collision_for_model
0x2bc338a7b21f4608, 0x8dbe7210c47d73e7, // get_ped_flood_invincibility
0x4b805e6046ee9e47, 0xfc7404297ed3cf49, // get_anim_initial_offset_rotation
0x8acd366038d14505, 0xf7ca9d10a9587f66, // get_entity_type
0x699e4a5c8c893a18, 0x7e940ca1a7f72fb6, // _0x699e4a5c8c893a18
0x4899cb088edf59b8, 0x681fb12989bd5dea, // remove_weapon_from_ped
0xca97246103b63917, 0x295bea3fe13e5c3d,
// 0xb4ab419e0d86acae, 0x0, // network_session_change_slots
// 0x73ca26b079f956e, 0x0, // get_shop_ped_outfit_locate
0x62a0296c1bb1ceb3, 0xb5587109d4b8d3e6,
0xd3dbce61a490be02, 0xff06fd8deb3ab01, // task_leave_vehicle
0x7984c03aa5cc2f41, 0xc4b7d5901eda35b5,
0x264ac28b01b353a5, 0xe87b9caaf890d1bf, // remove_dispatch_spawn_blocking_area
0xd33daa36272177c4, 0x3f754530261f807b, // _0xd33daa36272177c4
0xb664292eaecf7fa6, 0xd303e20cb0ae4ad0, // set_vehicle_doors_locked
0x37f4ad56ecbc0cd6, 0x3bac30e4b1bbae7, // get_ped_accuracy
0x5640bff86b16e8dc, 0x1c98d51d7c424a85, // point_cam_at_entity
0xcc9682b8951c5229, 0x1171e3efa13cfbfa, // _0xcc9682b8951c5229
0x465bf26ab9684352, 0xbde685791f16e73, // set_disable_vehicle_petrol_tank_fires
0x1c99bb7b6e96d16f, 0xc496dd5f2d1b6923, // set_entity_velocity
0x6599d834b12d0800, 0x103995bbae7f1e0a, // waypoint_playback_use_default_speed
0x9faaa4f4fc71f87f, 0xd3b95a52f4970a2, // network_clan_join
0x62b9fec9a11f10ef, 0x6822526c79b32ede,
0xec4686ec06434678, 0xc36b7971576cc42f, // set_ped_can_use_auto_conversation_lookat
0x5e9daf5a20f15908, 0xc3780945b3d82af7, // _0x5e9daf5a20f15908
0x4334bc40aa0cb4bb, 0xcb8e07064e08f927, // get_zone_popschedule
0xd8e694757bcea8e9, 0xaa6c5b326e8f5e69,
0xd9454b5752c857dc, 0xa11528f6b1d60172,
0x17ffc1b2ba35a494, 0x4ed4d1d8b2023fd8, // is_entity_touching_entity
0x9cd27b0045628463, 0xe3903f59e2f22150,
0x43286d561b72b8bf, 0xfd3c67782aae4e02, // set_police_radar_blips
// 0xa7ffba498e4aaf67, 0x0, // _0xa7ffba498e4aaf67
0x85e5f8b9b898b20a, 0x29aae09c249c2b5b, // network_does_tunable_exist
0x5983bb449d7fdb12, 0x382181e8439581b0, // is_ped_hurt
0xc9d55b1a358a5bf7, 0x3234e15469ea77bb, // is_ped_model
0xc116ff9b4d488291, 0xc50e8d93e6d238df, // _network_send_presence_transition_invite
0xd40ee2a7f2b2d6d, 0xef6f0cf344eea0c5,
0xf7ddebec43483c43, 0x71b2e6e793bcd3a7, // set_particle_fx_looped_offsets
0x218297bf0cfd853b, 0x6a848dd440025039, // _get_ped_using_vehicle_door
0x797ac7cb535ba28f, 0x75a50a9e5219c397,
0x906b778ca1dc72b6, 0x5e52b00cbe70530c,
0x18c1270ea7f199bc, 0xc78552daee19d97b,
0x47619abe8b268c60, 0x9e53817126a5362e, // get_phone_gesture_anim_current_time
0x51ac07a44d4f5b8a, 0x315999d057792d46, // can_knock_ped_off_vehicle
0xc142be3bb9ce125f, 0xfa0f238e5d72b269, // disable_player_vehicle_rewards
0x63c6cca8e68ae8c8, 0xeb5d8a701ba05e99, // create_mission_train
0x78e8e3a640178255, 0x27f2b81498b433b0, // _0x78e8e3a640178255
0xdb88a37483346780, 0x6486d2a6f2dc8dcb, // _get_text_scale_height
// 0xacde7185b374177c, 0x0, // network_spent_call_player
0x402f9ed62087e898, 0xbb50d9c8e5cb9ae9,
0x970f608f0ee6c885, 0x163940e51b9c8a0d, // get_blip_alpha
0x57e457cd2c0fc168, 0xc90e2cd6bfe5cc33, // is_ped_sprinting
0x2746bd9d88c5c5d0, 0xb9b00290dc78a70b, // _get_ped_head_blend_data
0x54b0f614960f4a5f, 0x729fa4955b2e681b, // _0x54b0f614960f4a5f
0xcf228e2aa03099c3, 0x11a4b380c2c7af10, // set_mp_gamer_tag_wanted_level
0xb32209effdc04913, 0x4884e65ed5f13c69,
0x841142a1376e9006, 0xe26818c7adfbf785,
0x4237e822315d8ba9, 0xc78af36bf20eb915,
0x20fe7fdfeead38c0, 0x6a26c1f1de3f6b15,
// 0x9c6a6c19b6c0c496, 0x0, // _0x9c6a6c19b6c0c496
0xa6a279f3aa4fd70, 0x10a9066d8a7991bb, // _0x0a6a279f3aa4fd70
// 0x38d28da81e4e9bf9, 0x0, // _0x38d28da81e4e9bf9
0x96b1361d9b24c2ff, 0x381d44c2f0113354, // unregister_pedheadshot
0xe0e854f5280fb769, 0x2db0f0a2d2af8d9c, // stat_get_number_of_days
0x1753344c770358ae, 0xa8693d1ddd75af7f, // _sc_has_check_string_task_completed
0x8eeda153ad141ba4, 0xcff7a8f330fef751, // set_everyone_ignore_player
0xd53a3b8da0809d2, 0xd9f039b57895690f, // start_particle_fx_non_looped_on_entity
0x19e00d7322c6f85b, 0x108bcd583149af69, // set_minigame_in_progress
0xa2ae5c478b96e3b6, 0xf9130d332492faaf, // _get_supports_gps_route_flag
0xac7bfd5c1d83ea75, 0x7bd9a176069a2daf,
0xda1df03d5a315f4e, 0x3bd53fa40d2c8fef,
0xfc18db55ae19e046, 0xacdbb3815702c101, // _0xfc18db55ae19e046
0x34318593248c8fb2, 0x30267feb358aa2e4, // is_projectile_type_within_distance
0x953563ce563143af, 0x2d596b08ed6679a8, // get_quadbike_display_variations
0x367ef5e2f439b4c6, 0xae7623b2407257d1, // _0x367ef5e2f439b4c6
0xb568201dd99f0eb, 0x4d72358f8f7aee, // _0x0b568201dd99f0eb
0x58e2e0f23f6b76c3, 0x1ec46d51c0c9524b, // task_use_nearest_scenario_to_coord_warp
0x1f400fef721170da, 0x65b6104f9cc5016c,
0xeb47ec4e34fb7ee1, 0xcc323859a8da2b88, // set_scenario_type_enabled
0x729e3401f0430686, 0xfa5b3876b1481d67, // _network_clan_animation
0xdc57a637a20006ed, 0x7b5a7a8ad08faf7f, // _hide_rope
0x3a48ab4445d499be, 0x8e6999cc90f5206e,
// 0x4ee5367468a65ccc, 0x0, // add_script_to_random_ped
0x69dea3e9db727b4c, 0x198bcb9897710eab, // playstats_oddjob_done
0xe3b6097cc25aa69e, 0x3d858ab1f749cc60, // is_ped_running_ragdoll_task
0xa36bfb5ee89f3d82, 0x11eb963358e13d24, // open_patrol_route
0x6bff5f84102df80a, 0x2310490b31c6f872, // _0x6bff5f84102df80a
0xb6ae90edde95c762, 0xff455285eb6a7977, // set_microphone_position
0x271cc6ab59ebf9a5, 0xda11f5abd49d09f4, // network_session_mark_visible
// 0x812f5488b1b2a299, 0x0, // network_spent_arrest_bail
0x58a850eaee20faa3, 0x148f2f9880c74aba, // place_object_on_ground_properly
0x2a7776c709904ab0, 0x2ab0252f50f8e7d4, // _0x2a7776c709904ab0
0xa73667484d7037c3, 0x311b5f5db4cdfc83, // network_session_block_join_requests
0x30ed88d5e0c56a37, 0xc44aae72432d8c34, // _0x30ed88d5e0c56a37
0x1f3f018bc3afa77c, 0x43c011d577edc1, // _0x1f3f018bc3afa77c
0xdeb6d52126e7d640, 0x181998d7d100c503, // is_ped_in_writhe
0xabb2fa71c83a1b72, 0x2b9036e1f65e50b3,
0x2ea9a3bedf3f17b8, 0x921e6c9c850ee0b5, // network_is_friend_in_same_title
0x1c2473301b1c66ba, 0x30259127efe86ca,
0x6ac7003fa6e5575e, 0x680558231c80291d, // is_entity_a_vehicle
0x600048c60d5c2c51, 0x655d730077361ec6, // _0x600048c60d5c2c51
0x22b0d0e37ccb840d, 0xeccd4fda45197f97, // task_smart_flee_ped
0x643e26ea6e024d92, 0x30f43446e6952e9e, // _set_rain_fx_intensity
0x9d7afcbf21c51712, 0x2ec4ffc8740228d3, // _0x9d7afcbf21c51712
0xfe4c1d0d3b9cc17e, 0x51dc111ccd463f, // _0xfe4c1d0d3b9cc17e
0x418dc16fae452c1c, 0x392260d073bc121, // _0x418dc16fae452c1c
0xb4ac7d0cf06bfe8f, 0x4e106c48e691ac31, // create_random_ped
0x69f5c3bd0f3ebd89, 0xdbc3bc97b1db197e, // task_vehicle_play_anim
0xb0c56bd3d808d863, 0x595cac9ece2780ed, // _0xb0c56bd3d808d863
0x90986e8876ce0a83, 0xbf4289280fd7809a,
0x7a6535691b477c48, 0x66cda3dcbcedf782, // set_ped_can_be_knocked_off_vehicle
0x1a5aa1208af5db59, 0xaf9ea4e314ed45c2, // set_roads_in_angled_area
0x703f12425eca8bf5, 0x88268a1e6a0f525c, // _0x703f12425eca8bf5
0xa13b0222f3d94a94, 0xce339cde5cc9f2ee,
0x8cde909a0370bb3a, 0xb44cdce4c2063cea, // _0x8cde909a0370bb3a
0xaff4710e2a0a6c12, 0x5278f2353f0e6ddb, // _0xaff4710e2a0a6c12
0xd9d620e0ac6dc4b0, 0xe48a80c34fc9559, // set_script_vehicle_generator
0xbcdf8baf56c87b6a, 0xcca47a1a16953a07, // set_players_last_vehicle
0x65019750a0324133, 0xd718803088b91796,
0x2b320cf14146b69a, 0x5fb6e3d6bec3bb41, // pin_rope_vertex
0xfc00454cf60b91dd, 0x39b710036d4a9d50, // unfreeze_radio_station
0x27f9d613092159cf, 0xca5167252dffb962, // remove_all_pickups_of_type
0xd0d7b1e680ed4a1a, 0xcc8396e846f83268, // set_ped_gadget
0x4c6a6451c79e4662, 0x3ca08f647cead042, // can_set_exit_state_for_registered_entity
0xa0f93d5465b3094d, 0xa8f2705cc9772956, // _0xa0f93d5465b3094d
0x52bba29d5ec69356, 0x81dd0edf91d5a264, // set_can_respray_vehicle
0xf5134943ea29868c, 0xdeacdda7f5bab4e0, // is_waypoint_playback_going_on_for_vehicle
0xa0a9668f158129a2, 0x5e83461198335d9b, // is_pedheadshot_valid
0xbf4fef46db7894d3, 0x8b6d2896eabeb3d1, // leaderboards_get_column_type
0x2ada21ea2f6918f, 0xfdc992b5f88743ed,
0x679be1daf71da874, 0x67001c5cc88c66a8, // is_vehicle_stuck_timer_up
0xed98e10b0afce4b4, 0xb9e79d851f5ca91, // set_ped_waypoint_route_offset
0xc87e740d9f3872cc, 0x7c43d45db84821d7,
0xa9b61a329bfdcbea, 0x9cbce00f59bd6654, // _0xa9b61a329bfdcbea
// 0xe59343e9e96529e7, 0x0,
// 0xb99c4e4d9499df29, 0x0, // _0xb99c4e4d9499df29
0xb094bc1db4018240, 0xbab024e81cb73e1, // _0xb094bc1db4018240
0xde44a00999b2837d, 0xcad2858165b4553c, // get_shop_ped_query_prop
0xd5037ba82e12416f, 0x8bb475ea09c9a0eb, // get_entity_speed
0xa82819cac9c4c403, 0x2bd8211377875222, // get_vehicle_enveff_scale
0x93ae6a61be015bf1, 0x18a74017afd59d9b, // set_vehicle_lod_multiplier
0xebfa8d50addc54c4, 0x210976b2f7cf69e9, // _0xebfa8d50addc54c4
0x6f0f77fba9a8f2e6, 0xcf60966e9fe84cb, // set_cam_motion_blur_strength
0x888c3502dbbeef5, 0x816ea810e1858ae4,
0x1d9d45004c28c916, 0x7143409dbd96942c, // set_group_formation_spacing
0x166e7cf68597d8b5, 0x77172c3632bd7ce5, // set_entity_max_health
0xe66c690248f11150, 0xad002c1c7bb450bc, // _0xe66c690248f11150
0x763b4bd305338f19, 0x711ee1e31b95f173, // network_buy_airstrike
// 0xe5608ca7bc163a5f, 0x0, // network_access_tunable_float
0x17430b918701c342, 0x8b99542d88537d3c, // _set_notification_flash_color
0x5f7d596bac2e7777, 0xe3c59193ba1113b8, // override_popschedule_vehicle_model
0x9304881d6f6537ea, 0xbb954b59c79a6d32, // _request_hud_scaleform
0x5db8010ee71fdef2, 0x3ed54aae2fb131e1, // _0x5db8010ee71fdef2
0xb2a16444ead9ae47, 0x1e6d9db41bedafb3, // task_go_to_coord_while_aiming_at_entity
0x3c27e13b42a0e82, 0xb81e8bd834c4700, // _0x03c27e13b42a0e82
0x2bdd44cc428a7eae, 0x97b6a6696d936191,
0x9ca5de655269fec4, 0xd836927543512b0d, // network_set_in_mp_cutscene
0xf1eea2dda9ffa69d, 0x2a13fca346e423bf, // _0xf1eea2dda9ffa69d
0x12561fcbb62d5b9c, 0xdba9e7389f779b73, // _0x12561fcbb62d5b9c
0xf033419d1b81fae8, 0xb9b60ef2ec7bfcc9, // _0xf033419d1b81fae8
0xbf94dd42f63bded2, 0xc3622ec0e0215a79, // is_this_model_a_bicycle
0x77f33f2ccf64b3aa, 0x5df33f31c6066615, // _set_object_lod
0x46399a7895957c0e, 0xf4bf002874250db7, // remove_navmesh_blocking_object
0x1f6594b923b9251, 0x8021ae396339fccf, // set_ped_ragdoll_force_fall
0x23285ded6ebd7ea3, 0x99074a3b1185c542, // disable_police_restart
0xd642319c54aadeb6, 0x257c32e24b8beaae,
0x873c9f3104101dd3, 0x3a5e614ec752b188, // _get_active_screen_resolution
0xd75960f6bd9ea49c, 0xbac19d13ef3fbb2e, // get_ped_last_damage_bone
0xc7c6789aa1cfedd0, 0xe354a0599f1dbbd5,
0x8c825bdc7741d37c, 0xf9a71bb673c8a85f, // set_high_fall_task
0xd93db43b82bc0d00, 0x9bda1567f3312f06, // set_cam_shake_amplitude
0x5d6b2d4830a67c62, 0x2532e297cf3112f2, // remove_decals_in_range
0x6bab9442830c7f53, 0x46ed2cf120c8949, // _set_door_acceleration_limit
0x9b12f9a24fabedb0, 0xccbed19ef0483c96, // _door_control
0x252e5f915eabb675, 0xeca228def8beffbf, // start_script_phone_conversation
0x55384438fc55ad8e, 0x76167b5fb384e221, // _0x55384438fc55ad8e
0xbb8ea16ecbc976c4, 0x35d8ea476ef629a1, // _sc_inbox_message_init
0x26aa915ad89bfb4b, 0x67e42c11097164ba, // is_entity_attached_to_any_vehicle
0xf095c0405307b21b, 0x17097e17c445781f, // get_is_vehicle_primary_colour_custom
0x182f266c2d9e2beb, 0x87e18dd05b22a005, // _0x182f266c2d9e2beb
// 0x8621390f0cdcfe1f, 0x0,
0xc9a763d8fe87436a, 0xaf40cd16d7f807f4, // _0xc9a763d8fe87436a
0x499d7b09fc9b407, 0x4464d5595ceed843, // get_control_instructional_button
0x4a9fde3a5a6d0437, 0xab27cbdeb9712da8, // _network_block_invites_2
0x2f83e7e45d9ea7ae, 0xb8b82117df4cf099, // get_vehicle_class_max_acceleration
0xf6086bc836400876, 0x884fff0ea3260fa5, // does_script_vehicle_generator_exist
0x2eabe3b06f58c1be, 0x42ffeb8ac39c983d, // get_closest_major_vehicle_node
0x973d76aa760a6cb6, 0x11d6f9de1302ba46, // _0x973d76aa760a6cb6
0xd4438c0564490e63, 0x9a8b96a93df76776,
0x65db281590cea2d, 0xe75248806d55a24b, // _array_value_get_size
0x77b21be7ac540f07, 0x6fbc94381b016ab4, // set_entity_quaternion
0x60296af4ba14abc5, 0xa2a8afe6757c42d2, // add_next_message_to_previous_briefs
0x60edd13eb3ac1ff3, 0x45d01b7a29aaad51,
0xc20e50aa46d09ca8, 0xc838ce9837d0abaf, // task_enter_vehicle
0xf2d4b2fe415aafc3, 0x6151d8f3d747dbd6, // stat_get_number_of_hours
0xe2892e7e55d7073a, 0xfd0caa61acbc8cea, // _0xe2892e7e55d7073a
0x5746f3a7ab7fe544, 0x95f9f6ed1c84efec, // get_time_position_in_recording
0xc8bc2011f67b3411, 0x2aee0765a4c13e05, // network_clan_get_membership
0xedec3c276198689, 0x50403c3bfa227fe5, // ped_to_net
0xf1ae5dcdbfca2721, 0x66b7c5cb3e0b91de, // _0xf1ae5dcdbfca2721
// 0x5bc62ec1937b9e5b, 0x0, // stat_set_bool_masked
0x4e929e7a5796fd26, 0xcdd28a9dfce2fce, // is_mp_gamer_tag_active
0x66972397e0757e7a, 0x7750e92942d854d5, // _0x66972397e0757e7a
0x68f01422be1d838f, 0xe535ed113e0ab354, // stat_set_profile_setting_value
0xb3271d7ab655b441, 0x12b6e23f244ddb0f, // stat_set_int
0x2f7f2b26dd3f18ee, 0x33c31820457e0a73, // _0x2f7f2b26dd3f18ee
0x8eb2f69076af7053, 0xe165d08883ed40ab, // remove_group
0xbd2a8ec3af4de7db, 0x6e690c20044225cb, // task_use_mobile_phone
// 0x74c180030fde4b69, 0x0, // _0x74c180030fde4b69
0x583be370b1ec6eb4, 0x688593ec9461e416, // get_weapon_clip_size
0xe4a84abf135ef91a, 0xe056c244facc746c, // get_interior_group_id
0x597f8dba9b206fc7, 0xc66348b676aefe7d,
0xebcab9e5048434f4, 0x6ed9f181e1e24dbf,
0xb088e9a47ae6edd5, 0x80db3bb11d028d2f, // _0xb088e9a47ae6edd5
0x4198ab0022b15f87, 0x411e3f93ec413bf3, // _vehicle_has_landing_gear
0xd2e6822dbfd6c8bd, 0x34b1602009421b58, // is_vehicle_extra_turned_on
0x4927fc39cd0869a0, 0xd60da11960e17cc7, // network_player_get_userid
0x3a87e44bb9a01d54, 0x96c4b46f194803a7, // get_current_ped_weapon
0xdcf0754ac3d6fd4e, 0x65389dd6e97b2939, // set_cinematic_mode_active
0x4c9296cbcd1b971e, 0xfa6bee2b1507ff1e,
0xf1a1803d3476f215, 0x5d371dfe416bbbca, // _0xf1a1803d3476f215
// 0xc4582015556d1c46, 0x0,
0x13518ff1c6b28938, 0x86176583ff025729, // _0x13518ff1c6b28938
0x956b409b984d9bf7, 0x9a9cbd3159794c11, // does_vehicle_exist_with_decorator
0xd4d4f6a4ab575a33, 0x45dd72322a48ef4b, // set_vehicle_door_broken
0xc571d0e77d8bbc29, 0x7d220d4b3aa5be6c,
0x41350b4fc28e3941, 0x5d3c390a7c0feb0f, // _0x41350b4fc28e3941
0x50bd2730b191e360, 0x204deacc5becf723, // get_entity_anim_total_time
// 0xa37b9a517b133349, 0x0, // set_vehicle_wheels_can_break_off_when_blow_up
0x5776ed562c134687, 0x4275ca312579e4e7, // texture_download_has_failed
0xb64cf2cca9d95f52, 0xb6bb43d4eac89240, // get_vehicle_custom_primary_colour
0x8217fd371a4625cf, 0x1572ca2af3dbd9e4, // set_player_parachute_smoke_trail_color
0x1171a97a3d3981b6, 0xbde62a6849174b04, // _0x1171a97a3d3981b6
0x759591819534f7b, 0x89bdcedf5972595, // task_follow_waypoint_recording
0x4a4722448f18eef5, 0x860d3e500aeadb97, // set_entity_has_gravity
0x1e09c32048fefd1c, 0x967d9c68bde528cb, // task_vehicle_heli_protect
0xe361c5c71c431a4f, 0x4280426804263490, // set_ped_path_can_drop_from_height
0x2b51edbefc301339, 0x40cb32b151caf8f8, // _0x2b51edbefc301339
0x27040c25de6cb2f4, 0x5cf28fa5a7977da1, // get_zone_at_coords
0x68edda28a5976d07, 0x52370fb78e42e275,
0xae2af67e9d9af65d, 0xa0220bf0ab292278, // set_blip_coords
0x45eee61580806d63, 0xfda78b1ca2b4fb0a, // set_ped_default_component_variation
0x7e5b515db0636fc, 0x63f0b040ce6edf0f, // render_script_cams
0xb45085b721efd38c, 0x6dfeb7d8695fc302, // get_vehicle_mod_color_1_name
0x88c6814073dd4a73, 0xaef90bd69e5087cf,
0x8fd89a6240813fd0, 0xd165ea9dc60aaa7b, // _0x8fd89a6240813fd0
0xc265df9fb44a9fbd, 0x282f3ad3511f8a07, // _0xc265df9fb44a9fbd
0x113e6e3e50e286b0, 0xae633ea7bdd8c378, // _0x113e6e3e50e286b0
0x71b74d2ae19338d0, 0x14a5407c61374492, // _0x71b74d2ae19338d0
0xaaa553e7dd28a457, 0xcf0caf9c89e232c2, // _0xaaa553e7dd28a457
0xbf9bd71691857e48, 0xd4285932032eabd0, // start_firing_amnesty
0x9d44fcce98450843, 0x8b16b124fdf63c03, // _set_vehicle_silent
0x3039ae5ad2c9c0c4, 0x156c9fc9ab3ddf17, // network_override_chat_restrictions
0x23dfb504655d0ce4, 0xa1b5ae30a14c4de2,
0x9f8aa94d6d97dbf4, 0x4a852f02088ecc9d, // set_blocking_of_non_temporary_events
0xa8cf1cc0afcd3f12, 0x561f7ccb9c9a4f1b,
0x717e4d1f2048376d, 0x46d699bf63e9f9a2, // _get_ped_network_task_phase
0xd716f30d8c8980e2, 0x8ce1a59cba4b57b9, // add_to_clock_time
0xba71116adf5b514c, 0x87d8deabf0fefae6, // explode_vehicle
0x63f9ee203c3619f2, 0x334a13058bfbbaba, // network_is_player_in_mp_cutscene
0xa3a9299c4f2adb98, 0x3e2a39f699947160, // _0xa3a9299c4f2adb98
0x9dd368bf06983221, 0x8641d293a077f12c, // network_disable_invincible_flashing
0x6d3465a73092f0e6, 0xa584e193c941898b,
0x6dd8f5aa635eb4b2, 0xdf73b9b8f283bb7b, // _0x6dd8f5aa635eb4b2
0xe83a3e3557a56640, 0x3efc6497702202d6, // _add_scaleform_movie_method_parameter_button_name
0x44cb6447d2571aa0, 0x4591d77abfab3d55, // set_ped_wetness_height
0x1280804f7cfd2d6c, 0x90781deb29534be4, // _0x1280804f7cfd2d6c
0x50f940259d3841e6, 0x1771f6baf60b44fa, // is_control_just_released
// 0xff266d1d0eb1195d, 0x0,
0x42a4beb35d372407, 0x3d25ac5dcf1cf8f, // _0x42a4beb35d372407
0x6004bcb0e226aaea, 0x85c687d051f75384, // preload_script_phone_conversation
0xebaa9b64d76356fd, 0x6cb35be26d83e603, // play_stream_from_object
// 0xd5a4b59980401588, 0x0, // _0xd5a4b59980401588
0x7fe61782ad94cc09, 0x20284e8c37b5322f, // network_spent_telescope
0x5c3b791d580e0bc2, 0x9b4bc884ce3e8bb, // _0x5c3b791d580e0bc2
0x62e849b7eb28e770, 0x739fd1cac998d66a, // _0x62e849b7eb28e770
0xf6a9d9708f6f23df, 0x1c2eab81a6a52839, // start_entity_fire
0xff071fb798b803b0, 0x5a5015cf0b2de07a, // get_closest_vehicle_node_with_heading
0xca9d2aa3e326d720, 0xaa970f1d889fd650,
0x17f58b88d085dbac, 0x2efd82fcbabd29f7, // task_follow_nav_mesh_to_coord_advanced
0x717c8481234e3b88, 0xe0afbca0eda1dac8, // has_vehicle_got_projectile_attached
0xbca1d2c47b0d269, 0x652497bd2553f5e9, // _0x0bca1d2c47b0d269
0x728c4cc7920cd102, 0x38d1e990aa4b938f, // _0x728c4cc7920cd102
0x99c82f8a139f3e4e, 0xb5c87a752d9de7d6, // _set_vehicle_hud_special_ability_bar_active
0xaa5a7ece2aa8fe70, 0x41d41eefdac914ac, // set_ped_desired_heading
0xf2fd55cb574bcc55, 0xd03ffb848b947122, // network_gamer_has_headset
0x26b0e73d7eaaf4d3, 0xde9b75bb528ac06e, // is_valid_interior
0x277f471ba9db000b, 0xa9128aa30f3036c7, // task_use_nearest_scenario_to_coord
0x300d614a4c785fc4, 0x371855a6f27f144b, // has_vehicle_recording_been_loaded
0x22ac59a870e6a669, 0x67ffbb75d2430704, // is_vehicle_seat_free
0x8b0facefc36c824b, 0xab43a7f7367199dd, // stat_get_date
0xa436b8643716d14, 0x458484959aa7e2d0,
0xa72835064dd63e4c, 0xabba91e34c64a7f1,
0xdc3a310219e5da62, 0xe3238518b355643, // is_sphere_visible_to_player
0x58575ac3cf2ca8ec, 0xfc65f2e6b00888d0, // _network_hash_from_gamer_handle
0x68b2b5f33ba63c41, 0x5d86523248274828, // point_cam_at_ped_bone
0xc7f76df27a5045a1, 0x7081b6e272ec7c2, // set_ped_angled_defensive_area
0xf833ddba3b104d43, 0x823383849cd52de4, // set_ped_can_play_viseme_anims
0xc58424ba936eb458, 0x295b86de57a0721d, // _add_scaleform_movie_method_parameter_bool
0xf8bdbf3d573049a1, 0x25251ff925945b3d, // _0xf8bdbf3d573049a1
0xf9b83b77929d8863, 0xe137c845024d2e5d,
0x3e802f11fbe27674, 0xb1759fec1728688c, // _0x3e802f11fbe27674
0xa134777ff7f33331, 0xc54303d38f95cf2f, // _0xa134777ff7f33331
// 0xe4973dbdbe6e44b3, 0x0, // update_task_sweep_aim_entity
0xbaf107b6bb2c97f0, 0x5972ee9bf3c1be95,
0x693a5c6d6734085b, 0x727f454f1d40bae4, // set_mobile_phone_position
0xff41b4b141ed981c, 0x4099b0626c455ec7, // set_combat_float
0x29a16f8d621c4508, 0xdb2e3ac6577ccd75, // attach_vehicle_to_tow_truck
0x7116e24e9d1929d, 0x9718ffce41ff74d1, // steer_unlock_bias
0x97ff36a1d40ea00a, 0xccaf0916949dd646, // stop_anim_task
0x8ef07e15701d61ed, 0xd9e7c31daf9cc2a, // set_bits_in_range
0x26695ec767728d84, 0xbe470acbedcbf6fc, // _set_ped_ragdoll_blocking_flags
0x7aa80209bda643eb, 0xb66f510766d11582, // task_shuffle_to_next_vehicle_seat
0x172f75b6ee2233ba, 0x6b53cf8a19454315,
0x1186940ed72ffeec, 0x4461633977bb7415, // _object_value_get_boolean
0xe5810ac70602f2f5, 0x470437d86809bae6, // _0xe5810ac70602f2f5
0x24a2ad74fa9814e2, 0xc4f43168474e0dc1, // is_move_blend_ratio_sprinting
0x226435cb96ccfc8c, 0x90d2ecc8a42dff63, // is_alarm_playing
0x3b39236746714134, 0xff14ec9301f95fd5, // _0x3b39236746714134
0x2fa9923062dd396c, 0x1f986633c8e180ba, // add_vehicle_stuck_check_with_warp
0x7ae0589093a2e088, 0x528a00a9f596e1, // _draw_notification_unlock_3
0x4e209b2c1ead5159, 0xa08b8aec5b1a55d6, // is_ped_in_melee_combat
0xa78b8fa58200da56, 0x3684a8749fb3c6eb, // _0xa78b8fa58200da56
0x2e0dc353342c4a6d, 0x7eee8b447ab73c25, // is_projectile_type_in_area
0xc92717ef615b6704, 0x19dd747264520c12, // _0xc92717ef615b6704
0x643ed62d5ea3bebd, 0x1b3f43df6f208d4,
0xcd67ad041a394c9c, 0xc9606cafd68b3558, // get_player_advanced_modifier_privileges
0x414641c26e105898, 0xd97e13bb3066d750, // is_ped_evasive_diving
0x6d14bfdc33b34f55, 0x3f8f5094462c70a6,
0xef29a16337facadb, 0x11f75b88e9f55349, // clone_ped
0xfa0675ab151073fa, 0x2bc096ad87238048, // set_ped_min_ground_time_for_stungun
0xda95ea3317cc5064, 0x67ac116d7dea4ecc, // does_entity_have_physics
// 0x9e4cfff989258472, 0x0,
0x397dc58ff00298d1, 0xc106293d8bb9b710, // is_any_object_near_point
0xee066c7006c49c0a, 0x5031e50f85092948, // _0xee066c7006c49c0a
0x5549ee11fa22fcf2, 0x3fe655b5470d5457, // get_dlc_vehicle_flags
0x5539c3ebf104a53a, 0xd38337a5879e2fcf, // _0x5539c3ebf104a53a
0xccf71cbddf5b6cb9, 0xe7253dcfa89dc442, // remove_decals_from_object
0x5f2013f8bc24ee69, 0x222fb8ce7e670a13, // _0x5f2013f8bc24ee69
0x5ddfe2ff727f3ca3, 0x18129ed6e2877a8c, // get_player_has_reserve_parachute
0xcfd778e7904c255e, 0x9a2146048c127afb, // _0xcfd778e7904c255e
0x2162c446dfdf38fd, 0xac2f88b1da944af1, // _log_debug_info
0x1ca59e306ecb80a5, 0x210e46a190fb3cb3, // network_set_this_script_is_network_script
0xa1607996431332df, 0xc6a42001af5fde0e, // _network_can_network_id_be_seen
0x18d0456e86604654, 0x396a8511217f9c1a,
0x47cbed6f6f8b63c, 0x779e97a945caa2a1,
0x918c7b2d2ff3928b, 0x9fe070720b6057b4, // _0x918c7b2d2ff3928b
0x67f3780dd425d4fc, 0xa603fba9f3c17d3a, // get_ped_drawable_variation
0xc53eb42a499a7e90, 0x251d428435e55081, // remove_vehicle_upsidedown_check
0x8183455e16c42e3a, 0xd3260f66bca580a2,
0xb885852c39cc265d, 0x4bfc550028f4ffb7,
0xc70b5fae151982d8, 0x105cb7a75e93dc77, // is_ped_planting_bomb
0xc443fd757c3ba637, 0xafefadc285965bbe, // modify_water
0x2274bc1c4885e333, 0x16068053f8800179, // get_offset_from_entity_given_world_coords
0x3fb99a8b08d18fd6, 0x95130a9e973d4ef7, // network_player_has_headset
0x7cd6bc4c2bbdd526, 0x6d57e93cb68152fe, // network_create_synchronised_scene
0x9c00e77af14b2dff, 0x9f4f05e712d04be8, // _task_get_off_boat
0x8f96ca6c551ad51, 0x93916b4639501b8, // _get_weapon_hash_from_pickup
0x801bd273d3a23f74, 0x3827586cffa71f4b, // get_length_of_string_with_this_text_label
0x1f0b79228e461ec9, 0x1ce8f0a08e65ca6a, // is_entity_playing_anim
0x1d97d1e3a70a649f, 0xe0fce9a7ac7bb541, // _0x1d97d1e3a70a649f
0x85973643155d0b07, 0x833a05a7ad82ea44, // set_cam_rot
0x21115bcd6e44656a, 0x28e8a01ff6bbfda8, // _0x21115bcd6e44656a
0xfde9dbfc0a6bc65, 0xa0e445a07d6b59cd, // _0x0fde9dbfc0a6bc65
0x99cad8e7afdb60fa, 0xe34fede3a39a1483, // _0x99cad8e7afdb60fa
0x8f75998877616996, 0x91f3e4311d34b364, // stop_particle_fx_looped
0x1775961c2fbbcb5c, 0x309f5552a225efd1, // network_set_property_id
0x5cde92c702a8fce7, 0x8848a15cbdaddc60, // add_blip_for_entity
0xbb40dd2270b65366, 0x7bdc41a7ca0c77a2, // get_ped_in_vehicle_seat
0xb158dfccc56e5c5b, 0x8db611856bf44381, // give_ped_nm_message
0x293220da1b46cebc, 0xb5d26bfa756d0d11, // _0x293220da1b46cebc
0x3da5ecd1a56cba6d, 0x858db7b752ad2e42, // network_initialize_cash
0x5da3a8de8cb6226f, 0xc623fd25993075c2, // playstats_idle_kick
0xc6ed9d5092438d91, 0xcb7f618cc6fabc72, // register_script_with_audio
0x2513dfb0fb8400fe, 0xb013d1b3810666e1,
0xc4301e5121a0ed73, 0xc48a4babdfaab2b9, // set_mission_flag
0xff8f3a92b75ed67a, 0xbe05f1f3b28865e3,
0x1dd2139a9a20dce8, 0x3b682403c60da703,
0x4d9d109f63fee1d4, 0x432e276fb02808fa, // _0x4d9d109f63fee1d4
0x4669b3ed80f24b4e, 0xa801f23a1c1decfb, // _0x4669b3ed80f24b4e
0xd705740bb0a1cf4c, 0x12d3b4c76d4aab00, // has_player_been_spotted_in_stolen_vehicle
0x615d3925e87a3b26, 0xa2e9dc7424223e06, // _0x615d3925e87a3b26
0x26fb97d0a425f84, 0x189377bfbdc9127f, // set_cam_active
0x5f35f6732c3fbba0, 0x7a2208d1550e1dd9, // _0x5f35f6732c3fbba0
0xff287323b0e2c69a, 0x142d7de2bfbcfcf5, // _freeze_ped_camera_rotation
0x78dcdc15c9f116b4, 0x464516da815840a7, // is_named_rendertarget_registered
0x26143a59ef48b262, 0xbbaaad7e775c0793, // set_particle_fx_non_looped_colour
0x22d7275a79fe8215, 0x8fe805a2903f1c0a, // get_nth_closest_vehicle_node_id
0xe0031d3c8f36ab82, 0x40559e9a34d821c4, // set_entity_visible_in_cutscene
0x5473d4195058b2e4, 0x6e8e2b9ef176969, // stat_get_license_plate
0x280c7e3ac7f56e90, 0xc5e4a180d7650902, // _0x280c7e3ac7f56e90
0x33a60d8bdd6e508c, 0x7cb204b4f4a57d90, // _set_ped_can_play_injured_anims
0xcff869cbfa210d82, 0x2437cae892d2f387, // get_ped_nearby_vehicles
0x3a93ff1a2ca0864, 0xfa55f299e29534a,
0xb56bbbcc2955d9cb, 0xa812c1043fe92b58,
0x4164f227d052e293, 0xdc4b3eab8d3f281f, // _network_get_friend_name_from_index
0x1fc877464a04fc4f, 0x30e38d26fbf4fdda, // get_blip_sprite
0x993cbe59d350d225, 0xb552e3f8dddecf04, // _0x993cbe59d350d225
0x63ae2b2cc273588, 0xc7030ed910ca15a6, // _0x063ae2b2cc273588
0x7b30f65d7b710098, 0x804fd6b4274d3691,
0xc88156ebb786f8d5, 0xe5d585bfa89b603c,
0x452419cbd838065b, 0xb04aca0f9b8fd274, // task_shocking_event_react
0x29439776aaa00a62, 0x44f23580251ddb79, // get_vehicle_class
0xf79f9def0aade61a, 0xd1d52307a17e0b14, // _0xf79f9def0aade61a
0x68049aeff83d8f0a, 0x5b2b89f605560a5f,
0x3ed1438c1f5c6612, 0x935efe22d15a1591, // _0x3ed1438c1f5c6612
0x5dcf6c5cab2e9bf7, 0x3db36a480526eeda, // get_weapon_tint_count
0x95cf53b3d687f9fa, 0x5e828c19874c4eaa, // _0x95cf53b3d687f9fa
0x6fe601a64180d423, 0x8bf099444ed247fb, // set_dispatch_ideal_spawn_distance
0x5f6df3d92271e8a1, 0xdce40e302ae0d805, // set_particle_fx_blood_scale
0x5d35ecf3a81a0ee0, 0x14e82766bc2f1787, // get_time_since_player_hit_vehicle
0x898cc20ea75bacd8, 0x63a77907c209dc4, // get_ped_prop_index
0x9614b71f8adb982b, 0x4c103bb3cb028da4,
0x9c11908013ea4715, 0xe10a42fd595f1c7c, // _sound_vehicle_horn_this_frame
0x6b5c83ba3efe6a10, 0x2d50a0ddefbdde5, // network_is_transition_host_from_handle
0x21ffb63d8c615361, 0x9758acdbbf1a37b0, // ignore_next_restart
0xcada5a0d0702381e, 0x29d3f91dd834c52f, // _0xcada5a0d0702381e
0xa731f608ca104e3c, 0x8120ee2272397ce8, // set_driver_aggressiveness
0xeb8517dda73720da, 0xfc5869efa580f047, // task_set_decision_maker
0x7f2f4f13ac5257ef, 0x61ee20a8e9073516, // _0x7f2f4f13ac5257ef
0xf113e3aa9bc54613, 0x88ec239aa25ef0a7, // special_ability_charge_medium
0x3d10bc92a4db1d35, 0x20a28fae1c09250,
0x9d77056a530643f6, 0x495407ac2d466930, // end_text_command_print
0xd4b8e3d1917bc86b, 0xbfa3e70f1bcbbdde, // _0xd4b8e3d1917bc86b
0xf2bfa0430f0a0fcb, 0xf49ff7b4a27c1b94, // set_vehicle_door_control
0xf7ec25a3ebeec726, 0x30f7441d967fcc9c, // set_vehicle_is_wanted
0xa7b270912999b3c, 0x5a04e3bd0b5e7e49, // is_entity_a_mission_entity
0x648e7a5434af7969, 0x6cf87e482e0eb064, // _0x648e7a5434af7969
// 0x283b6062a2c01e9b, 0x0,
0x28d1a16553c51776, 0x764b44e3f1d8f88d, // set_entity_anim_speed
0x8530ad776cd72b12, 0x39b62cdd14cadbfa, // pause_scripted_conversation
0xa635c11b8c44afc2, 0xf40de7cf7c1d0bbb,
0x82352748437638ca, 0xdcc802bbcea5f607,
// 0x41062318f23ed854, 0x0, // set_vehicle_exclusive_driver
0xa98b8e3c088e5a31, 0xe9eee464f7d6cac, // does_scripted_cover_point_exist_at_coords
0x20510814175ea477, 0x7a01e62de63cf78d, // reset_ped_strafe_clipset
0xea1e2d93f6f75ed9, 0x767de8038adbf2a9, // _set_particle_fx_asset_old_to_new
0x48a59cf88d43df0e, 0xc9c4feabbb371ef, // network_clan_get_membership_valid
0xc54a08c85ae4d410, 0x328c7ecbdd7ff98d, // _0xc54a08c85ae4d410
0x577d1284d6873711, 0xd5cd4268ede6f40e, // set_game_paused
0xaa5f02db48d704b9, 0xd875615f72cd34a6, // set_max_wanted_level
0x32d49c5e359c847, 0xad332da9d17aa061, // set_anim_rate
0x5486a79d9fbd342d, 0x17614dcd379a756, // get_jack_target
0x9d6981dfc91a8604, 0xec9112c275763535, // network_am_i_muted_by_player
0x225b8b35c88029b3, 0xf77516d457a04f5, // get_pickup_coords
0x241e289b5c059edc, 0x5ccff716f011dc32, // set_entity_locally_visible
0x5622aebc33aca9, 0x7fb142fa09b8f3f2, // waypoint_recording_get_speed_at_point
0x675721c9f644d161, 0x6347054e990e9549,
0x5ee29b4d7d5df897, 0x274cca1a61c957a, // set_cam_dof_strength
0x28579d1b8f8aac80, 0xf79dcfde3d6f778, // start_shape_test_capsule
0xad73ce5a09e42d12, 0xed64a6a70c61241c, // _0xad73ce5a09e42d12
0xc45ccdaac9221ca8, 0x43c3aa6ee008fa3b, // is_tracked_point_visible
0x54c7c4a94367717e, 0xc3a483c3c1b1f104, // give_ped_helmet
0xe73468d085f745, 0x7f0b8b7a7914f8bd, // is_ped_using_action_mode
0xc30713a383bfbf0e, 0x4b2284d14be614c5, // leaderboards2_read_by_handle
0xa735353c77334ea0, 0xefbac08085a07570, // _0xa735353c77334ea0
0xfe99b66d079cf6bc, 0x3fd9339aa95e323f, // disable_control_action
0xd1110739eeadb592, 0x57448aa77832ea9d, // _network_set_this_script_is_network_script_2
0xf53e48461b71eecb, 0x1923118362ad177, // _0xf53e48461b71eecb
0x6ec47a344923e1ed, 0xbfe245904b30a6ed, // is_scripted_scenario_ped_using_conditional_anim
0x57ab4a3080f85143, 0x5896fa9b8fd8b022, // is_ped_using_any_scenario
0x5d511e3867c87139, 0x24b9147563567ec4,
0xb66064452270e8f1, 0x7de9096b7972e0fc, // load_movie_mesh_set
0x8098c8d6597aae18, 0x2ecfa9dda6c5ad92, // _0x8098c8d6597aae18
0x8a876a65283dd7d7, 0x9808d9be8cc3331b, // is_player_script_control_on
0x80ca6a8b6c094cc4, 0x4cd58afce9fc3575, // get_nth_closest_vehicle_node_with_heading
0x678b9bb8c3f58feb, 0xeebf939bc404d2be, // get_vehicle_tyres_can_burst
0x3bcf567485e1971c, 0x55bf47aba574b4ec, // set_transition_timecycle_modifier
0xf0eed5a6bc7b237a, 0x2c8ff0903b37b5ed, // _0xf0eed5a6bc7b237a
0xdbaa5ec848ba2d46, 0x59bf1bc3301dc810, // _0xdbaa5ec848ba2d46
0x3c891a251567dfce, 0x3f38b2c145787e16, // _0x3c891a251567dfce
0x33f2e3fe70eaae1d, 0xcd2e94f6c3101afc, // get_num_mod_kits
0x5c9b84bd7d31d908, 0xb225487e62b643ca, // set_drive_task_cruise_speed
0x56e3b78c5408d9f4, 0xde2aab4315882b3d, // clear_ped_blood_damage_by_zone
0xf6201b4daf662a9d, 0xd88b24c279c15ea1,
0xaf8a443ccc8018dc, 0x55b9ae8865784f30,
0x965791a9a488a062, 0xb470bf3a9f5da9a5, // task_open_vehicle_door
0xc32ea7a2f6ca7557, 0x6cd7e67b007584da,
// 0x397baa01068baa96, 0x0,
0x487912fd248efddf, 0x193476d1b02873c5, // _0x487912fd248efddf
0xd718a22995e2b4bc, 0x8f470523aa8d48af, // set_ped_dies_in_sinking_vehicle
// 0x2708fc083123f9ff, 0x0,
0x837765a25378f0bb, 0x4ae56ab92160a4ab, // get_gameplay_cam_rot
0xff56381874f82086, 0xf09d93ba157fe826, // _0xff56381874f82086
0xeaf0fa793d05c592, 0xe06b146db33ec729,
0x6009f9f1ae90d8a6, 0xd3b8030cb4e487c9, // _request_additional_text_2
0x32a6dba562c518, 0x2ef5dd41310f2175,
0x740e14fad5842351, 0x5c2ec74e2089e64d, // set_gravity_level
0x8bbacbf51da047a8, 0x84d6caf6abc1382e, // _0x8bbacbf51da047a8
0x9768cf648f54c804, 0x7cf3736ad815b009, // remove_pick_up_rope_for_cargobob
0x7ee64d51e8498728, 0x7c928ec245affd20, // get_hash_of_map_area_at_coords
0xe28e54788ce8f12d, 0x2f527e1a3238dc, // get_player_wanted_level
0x10fab35428ccc9d7, 0xb331fceb94eb05c8,
0xfdd85225b2dea55e, 0x867eb7121b02da3c,
0x1f1e9682483697c7, 0x6830e7c16b5065e3, // _0x1f1e9682483697c7
0xbed9f5693f34ed17, 0x25c350201085cb09, // _0xbed9f5693f34ed17
0xdc04fcaa7839d492, 0x550de863ee24cb3c, // vehicle_waypoint_playback_resume
0x2db492222fb21e26, 0xe248392f80e099f7, // set_ped_visual_field_min_angle
0x12995f2e53ffa601, 0xf6d06af7bb0e609a, // _0x12995f2e53ffa601
0xa41bcd7213805aac, 0x292c57dac0c7f32f, // _0xa41bcd7213805aac
0x7d7a2e43e74e2eb8, 0x58f0f30530159ebb, // _track_ped_visibility
0x6889498b3e19c797, 0xc813d32cec55c031, // _array_value_add_object
0xfee4f80ac44a726, 0xfaefdc919b6c4b85, // set_player_forced_aim
0xcef70aa5b3f89ba1, 0xc8ae1b3ba3c8edc9,
0x4683149ed1dde7a1, 0x1d029c42b04639bd, // _0x4683149ed1dde7a1
0x5333f526f6ab19aa, 0x71d489b4139ea15b, // is_entity_upright
0x1f2aa07f00b3217a, 0x520614ef43727019, // set_vehicle_mod_kit
0xd39d13c9febf0511, 0x45b8601b4d532792, // _0xd39d13c9febf0511
0x5009dfd741329729, 0xdfe3c414afeb7622, // _0x5009dfd741329729
0x52af537a0c5b8aad, 0xc0832b9258378f00, // _does_des_object_exist
0xa91c6f0ff7d16a13, 0xa7c01382daa3032d, // set_swim_multiplier_for_player
0x6c8065a3b780185b, 0x5464b9731013e08c, // set_ambient_voice_name
0x45c597097dd7cb81, 0xdddbe90daf7935b0, // add_cover_blocking_area
0xc64ded7ef0d2fe37, 0xc7032fd0ef785fe1, // _0xc64ded7ef0d2fe37
0xab58c27c2e6123c6, 0xf0508c5b5e0b2722, // _begin_scaleform_movie_method_n
0x1eae6dd17b7a5efa, 0xfc633dc5ae880914, // _0x1eae6dd17b7a5efa
// 0x2d2386f273ff7a25, 0x0, // task_plane_chase
0xdc16122c7a20c933, 0x29577d0c92766c53, // get_max_ammo
0x6e63860bbb190730, 0xcf0c62792d87215c, // set_playback_to_use_ai_try_to_revert_back_later
0xbbe5d803a5360cbf, 0x3f2f738660c191f2, // add_stunt_jump_angled
0xf04c1c27da35f6c8, 0x17de9572fa06bac0, // leaderboards_get_cache_time
0x1e8be90c74fb4c09, 0xf476b943caafb802, // remove_weapon_component_from_ped
0x241fca5b1aa14f75, 0x991820330f9f531d,
0x2107a3773771186d, 0x4e8dfd4c26b7cded,
0x8d8686b622b88120, 0xec95d37a139f1d5c, // play_sound_from_coord
0xd0837058ae2e4bee, 0x4a6dccdf973e702f, // _call_scaleform_movie_function_float_params
0xbac7fc81a75ec1a1, 0x61bedefe36c609a9,
0xbbe7648349b49be8, 0x6dc4b47c71cd89e9, // set_mission_train_as_no_longer_needed
0x1055ac3a667f09d9, 0x91718c94006c77f0, // set_weapon_animation_override
0x5ba652a0cd14df2f, 0x270d61366a3cf56, // add_armour_to_ped
0x3b390a939af0b5fc, 0x3d74c4f085e721b1, // get_current_ped_weapon_entity_index
0xe4dcec7fd5b739a5, 0xe900df0ff41d01eb, // _0xe4dcec7fd5b739a5
0x3c06b5c839b38f7b, 0xac6a512c64d9a9c0, // is_player_free_aiming_at_entity
0xefabc7722293da7c, 0xd3926bfcc4d5bc51,
// 0x9dba107b4937f809, 0x0, // _set_ped_cover_clipset_override
0x49010a6a396553d8, 0x392a2ae521fd8ce7,
0x2e648d16f6e308f3, 0xa0ff1c22e6e6368d, // break_entity_glass
0x530944f6f4b8a214, 0xd93cfe80d83e2106, // is_ped_stopped
0x6c93ed8c2f74859b, 0xa575565c55d5fe18, // get_forced_component
0x10fe3f1b79f9b071, 0xe35d1055b69473fb, // stat_get_bool_masked
0x7dd29d5e22763f1, 0x6b07d1385ebd4d32, // _0x07dd29d5e22763f1
0xbc0ed94165a48bc2, 0xbcc19b7cc61ae8cd, // set_ped_get_out_upside_down_vehicle
0x5891cac5d4acff74, 0xe214b9fcedf6364a, // is_ped_in_group
// 0xbcbfcd9d1dac19e2, 0x0, // _set_cargobob_pickup_magnet_strength
0xbcfc632db7673bf0, 0x158d05f17dd35dad, // _set_first_person_cam_pitch_range
0x26c10ecbda5d043b, 0xb3f2bf6da2894e40, // _get_boat_anchor
0xc0173d6bff4e0348, 0x8dbd7370d84f0d82, // _get_root_content_id
0xc8d667ee52114aba, 0x333f03e1338109de, // rope_set_update_pinverts
0x11fe353cf9733e6f, 0x7a97d58c33c44415, // request_scaleform_movie
0xf8b0f5a43e928c76, 0x1eaf4eae49dba3fe, // _array_value_add_boolean
0x74fb3e29e6d10fa9, 0x7156ed841b156fcd,
0x4c5e1f087cd10bb7, 0x6589eb017dfa6460, // is_ped_tracked
0x4a2a40c73395041, 0x22b02ec53152632c, // get_ped_index_from_entity_index
0x3a3d5568af297cd5, 0xd57160e015b0f9bf, // _0x3a3d5568af297cd5
0x5c0de367aa0d911c, 0xe4cebb4f4c9d0695, // clear_popschedule_override_vehicle_model
0x6e11f282f11863b6, 0x42760555333084d1, // get_variant_component
0x8517d4a6ca8513ed, 0xe0bdeeacbf0f7d82, // get_ped_desired_move_blend_ratio
0x621c6e4729388e41, 0x356a1e560568a9f2, // _0x621c6e4729388e41
0x2e8d9498c56dd0d1, 0xee32fb07b269cf4b, // set_blip_flashes_alternate
0xff1b8b4aa1c25dc8, 0xf1c2aa9472b34a78, // remove_waypoint_recording
0x397c38aa7b4a5f83, 0x53955c9afcbb9cc0, // apply_ped_damage_decal
0x79ab33f0fbfac40c, 0x26f20a5d10b3e40f, // playstats_acquired_hidden_package
0xa4819f5e23e2ffad, 0x3aa1513aaaf3e966,
0xd4d8636c0199a939, 0xaaca543197be4142, // is_move_blend_ratio_running
0xc01e93fac20c3346, 0x4acad2ecf42372ba, // _network_has_control_of_pavement_stats
0xf9800aa1a771b000, 0x162e5b814e5f91b3, // was_ped_killed_by_stealth
0xe7b80e2bf9d80bd6, 0x31ac230f174a387, // network_spent_hire_mercenary
0xb21b89501cfac79e, 0x86f9094d3da3e3aa, // network_spent_prostitutes
0x1dd1f58f493f1da5, 0x6944101bed1c1331,
// 0xf9e1ccae8ba4c281, 0x0, // _0xf9e1ccae8ba4c281
0x793ff272d5b365f4, 0xf919fa161b2d42f9,
0xa9575f812c6a7997, 0x80137b8283360529, // start_save_data
0x49a49bed12794d70, 0x157caec7aac6938b, // stat_delete_slot
0xf3ac26d3cc576528, 0x1b332ce6cbe4391, // remove_player_helmet
0x8b6a4dd0af9ce215, 0xb4dfb7bb0c38832, // _network_session_set_max_players
0xc12321827687fe4d, 0x5856b9bf2b4e98c4, // set_all_vehicle_generators_active_in_area
0x97a790315d3831fd, 0x6f7ea5187051f7ef, // set_ped_enable_weapon_blocking
0xb497f06b288dcfdf, 0x948a37b10533fa15, // is_vehicle_stuck_on_roof
0x74afef0d2e1e409b, 0xc2fdde313d5a5398, // does_particle_fx_looped_exist
0x1d6650420cec9d3b, 0x5f70d43cdb987564, // set_ambient_zone_state_persistent
0xa5342d390cda41d6, 0xff2ccdb3e04702ed, // _0xa5342d390cda41d6
0xb1d2bb1e1631f5b1, 0x771ce024c5b22d36,
0x4145a4c44ff3b5a6, 0x131feec352fdccf5, // set_cam_anim_current_phase
0x377906d8a31e5586, 0x8e12bb34260d7af0, // _start_shape_test_ray
0x2c015348cf19ca1d, 0x1c195030029a21ef, // _sc_inbox_message_pop
0x751b70c3d034e187, 0x335c0645074963fe, // is_entity_at_entity
0x5cae833b0ee0c500, 0x8bd4a973c75f58f4, // _0x5cae833b0ee0c500
0xd05bff0c0a12c68f, 0x719381aa15935fdc, // is_entity_waiting_for_world_collision
0x2910669969e9535e, 0xe36862b47cd70685,
0xa85a21582451e951, 0x6b6b6e95deb6d44d, // _0xa85a21582451e951
0x509d5878eb39e842, 0x7ca67831169e8aa6, // create_object
0xc42dd763159f3461, 0x750c6fb80c86abf6,
0xcc9aa18dcc7084f4, 0xf62cfab74efd291a, // is_scripted_speech_playing
0xa7862bc5ed1dfd7e, 0xaf9b8301cbab8dab, // _0xa7862bc5ed1dfd7e
0x6373d1349925a70e, 0x990a34f9da8e506d, // set_ped_can_play_ambient_anims
0xeb354e5376bc81a7, 0xa50260e689cecd84, // _show_weapon_wheel
0xa6e9c38db51d7748, 0x4527878b077dba42, // get_entity_script
0xd9d0e694c8282c96, 0x97058c2279c57fa3, // get_cam_spline_node_phase
0x5e569ec46ec21cae, 0x53dfe31ac3852382, // _0x5e569ec46ec21cae
0xd9f8455409b525e9, 0x4381c79571201852, // add_shocking_event_at_position
0x1c186837d0619335, 0x95fb4f650a03d477, // _get_achievement_progression
0xeaeb0db4b132399, 0xb0d69ec116526983, // does_navmesh_blocking_object_exist
0x85f01b8d5b90570e, 0x11ae7f6a404414c9, // has_scaleform_movie_loaded
0xf7d82b0d66777611, 0x8b729ae9631e5dc, // remove_weapon_component_from_weapon_object
0xa151a7394a214e65, 0x749954286b0f4936,
0x798fdeb5b1575088, 0xb6644959214ea00a, // set_playerpad_shakes_when_controller_disabled
0x2b4a15e44de0f478, 0x8d13ba3bb8f16771,
0xba3d65906822bed5, 0x20dfd19e2735bfcc, // _0xba3d65906822bed5
// 0xf92a014a634442d6, 0x0, // network_earn_from_import_export
0xf1a6c18b35bcade6, 0x3cee585b1ff540f3, // _0xf1a6c18b35bcade6
0x32a116663a4d5ac, 0x62f413d666c41be5, // _is_vehicle_radio_loud
// 0x7ac752103856fb20, 0x0, // _0x7ac752103856fb20
0x733adf241531e5c2, 0xd2bf3d156276b9d4, // _0x733adf241531e5c2
0x128f79edcece4fd5, 0x3753972018fac181, // can_ped_ragdoll
0x14fc5833464340a8, 0x6557759908327adf,
0x20746f7b1032a3c7, 0xe5e26871d8586417, // _0x20746f7b1032a3c7
// 0x73040398dff9a4a6, 0x0, // _get_rope_length
0x73e2b500410da5a2, 0xa3387dc3df4fee8e, // network_get_activity_player_num
0x83a169eabcdb10a2, 0xe5cdc4f6687dd752, // _0x83a169eabcdb10a2
// 0x593feae1f73392d4, 0x0,
0x920d853f3e17f1da, 0xb125c98526425ee5, // _0x920d853f3e17f1da
0x6f60e89a7b64ee1d, 0xbaba29fe992cd51c, // start_networked_particle_fx_looped_on_entity
0x4af9bd80eebeb453, 0xfb89d9b67066db2c, // is_vehicle_stolen
0xf2a9cdabcea04bd6, 0x785cac4d932dccdb, // override_underwater_stream
0x97dd4c5944cc2e6a, 0xa5e61ab6bc58f421, // _network_override_send_restrictions
0x66460deddd417254, 0x1b068a930d0ce3df, // set_ai_melee_weapon_damage_modifier
0x3d9acb1eb139e702, 0x7b37fd322f4d4188,
0x13e940f88470fa51, 0xae7f901888936f24, // remove_action_mode_asset
0x16ffe42ab2d2dc59, 0xc0e41b8d6350e70e, // get_ped_cause_of_death
0xa549131166868ed3, 0x8d26a75278799dbb, // set_ped_cower_hash
0xa43d5c6fe51adbef, 0x43f8f38320183a05, // set_override_weather
0x6ebfb22d646ffc18, 0x589d17e3b4ce4805, // _0x6ebfb22d646ffc18
0x23227df0b2115469, 0x6636072cccda2d00,
0x38ce16c96bd11344, 0x22c3124a898fb82a, // network_does_network_id_exist
0x6b7256074ae34680, 0x8e4fa1ff4e91fd23, // draw_line
0x6e192e33ad436366, 0x6a0b9d77546c8f62, // is_damage_tracker_active_on_network_id
0xdf6e5987d2b4d140, 0x4cb71e6644b31f97, // _has_hud_scaleform_loaded
0x2ffb6b224f4b2926, 0x174c48e9e544e9a8, // get_heading_from_vector_2d
0x5ad23d40115353ac, 0x11c4af4137f2a4b5, // task_turn_ped_to_face_entity
0x50eeaad86232ee55, 0x4e1693493f78fa8,
0x1279e861a329e73f, 0x1753fac57cd1b746, // lock_minimap_position
0xc4278f70131baa6d, 0x67110ab55548e699, // _0xc4278f70131baa6d
0x3d3d15af7bcaaf83, 0x27cd99369517ea2e, // _0x3d3d15af7bcaaf83
0x1bede233e6cd2a1f, 0x979c4b247e2bbb98, // get_first_blip_info_id
// 0x8bf907833be275de, 0x0, // _0x8bf907833be275de
0xeb0f4468467b4528, 0xc35db9af48c033c7, // set_wind_direction
0xeae6dcc7eee3db1d, 0x529be8358cad2513, // set_parked_vehicle_density_multiplier_this_frame
0x781b3d62bb013ef5, 0x65ee1e8c987cd1db, // set_vehicle_doors_shut
0xdc64d2c53493ed12, 0xc6c5852786df8af4, // _0xdc64d2c53493ed12
0x8fe22675a5a45817, 0x1708858936c6d23a, // clear_ped_blood_damage
0xaeef48cdf5b6ce7c, 0x61cf9d8dfe799c12, // _0xaeef48cdf5b6ce7c
0x160aa1b32f6139b8, 0x566e267835baf87e, // _0x160aa1b32f6139b8
0x3750146a28097a82, 0x5c307b2d58fcf9bc, // set_vehicle_can_be_targetted
0xe0af41401adf87e3, 0x3a62345be9f3a040, // get_ped_extracted_displacement
0x15d757606d170c3c, 0x36a6f2cc2a6e4ca, // get_entity_max_health
0xadb3f206518799e8, 0x5be6b8c7ea40c189, // set_ped_relationship_group_default_hash
0x6582aff74894c75, 0xcc3d42f1667d647, // _0x06582aff74894c75
0x75e7d505f2b15902, 0xd8bc1388fb0f7734, // set_player_forced_zoom
0xdde6df5ae89981d2, 0x9e08e12414bd4476, // does_entity_belong_to_this_script
0x5b6010b3cbc29095, 0xbfd876d540882feb, // _0x5b6010b3cbc29095
0xad6b3148a78ae9b6, 0x1819081e2d6040cb, // set_variable_on_sound
0x6cf598a2957c2bf8, 0xb94227c531a24a5c, // get_dlc_weapon_component_data
0x72d918c99bcacc54, 0xe9fd52a86479b22b, // _0x72d918c99bcacc54
0x772df77852c2e30, 0xc217d8ca7bd476ea, // _set_player_cash_change
0x866a4a5fae349510, 0x2c9868a56be2bf96, // get_entity_forward_y
0x8fbb6758b3b3e9ec, 0xdbe845b7cfb056ab, // task_play_phone_gesture_animation
0x305c8dcd79da8b0f, 0xc6fadce8d6467372, // is_disabled_control_just_released
0x93028f1db42bfd08, 0x2bed825667b3b474, // _is_sc_inbox_valid
// 0x97a770beef227e2b, 0x0, // _0x97a770beef227e2b
0xe659e47af827484b, 0x3f219400e5fe4b69, // is_entity_on_screen
0x1c8a4c2c19e68eec, 0x4278060e716e1226, // is_playback_going_on_for_vehicle
0xb57d8dd645cfa2cf, 0x725d99cb808a3b4a,
0x85bf80fa50a39d1, 0x4e0d0e09e5c64c27, // set_ped_move_rate_override
0xaa0008f3bbb8f416, 0xb9769e6563311806, // set_draw_origin
0x83fe8d7229593017, 0xb11a02744e3cfb3e,
// 0x2131046957f31b04, 0x0,
0x9ac9ccbfa8c29795, 0xa6c6049de34ce73b, // network_has_player_started_transition
0xace699c71ab9deb5, 0x4cdf0d2c93f8cca7, // remove_vehicle_asset
0x8117e09a19eef4d3, 0xaffdc9ec63ed327d, // _get_utc_time
0xce4e5d9b0a4ff560, 0x85ae424b3b299088, // network_get_entity_from_network_id
0x480142959d337d00, 0x21d56a8927f5a92a, // task_vehicle_drive_wander
0x2f9a292ad0a3bd89, 0x372667969df165e8,
0x62ecfcfdee7885d6, 0x56f45f672a617b00,
0x4759cc730f947c81, 0x69eaa10da1b594d6,
0x416dbd4cd6ed8dd2, 0x7fb656a6afe2a7a8, // fade_out_local_player
0xb215aac32d25d019, 0x93916b4639501b8, // get_display_name_from_vehicle_model
0x2d5dc831176d0114, 0xfa9a2fcd2dbf2fa7, // _0x2d5dc831176d0114
0x65042b9774c4435e, 0x1446c035db85daba, // network_get_transition_host
0x4c241e39b23df959, 0x91d5c8283d19af49, // is_vehicle_driveable
0x82cedc33687e1f50, 0x18edc109f14c8a98, // _0x82cedc33687e1f50
0x75262fd12d0a1c84, 0xf90274a2198d0169, // get_sound_id_from_network_id
0xdd100eb17a94ff65, 0x452acd8246646024, // is_scripted_hud_component_active
0xc8ede9bdbccba6d4, 0x45c6d73e1f3927e0, // _0xc8ede9bdbccba6d4
0x6a25241c340d3822, 0x83f68b89e3ea476, // shake_cam
0x206bc5dc9d1ac70a, 0xf751d7aced794c0a, // _0x206bc5dc9d1ac70a
0xeb2104e905c6f2e9, 0x59f9fc8012a11f5c,
0xac3a74e8384a9919, 0xd33e388ea8e25cb1, // set_wind
0xaf8a94ede7712bef, 0x511559f67646f1c0, // set_ped_movement_clipset
0x8e04fedd28d42462, 0xaeed0213982928ac, // _play_ambient_speech1
0x579cced0265d4896, 0x62b7a5c795cb453,
0x73b1189623049839, 0xc6ab41e840199a71, // draw_debug_cross
// 0x9911f4a24485f653, 0x0, // _0x9911f4a24485f653
0x16c090630df1f89, 0x3daed611aa1401d5,
0xf342546aa06fed5, 0x557a4f93d64c0146, // waypoint_playback_pause
0xe5173c163976e38, 0x8b0fc2d96203a498, // clear_ped_decorations
0x3f878f92b3a7a071, 0xccffba26c1726838, // start_playback_recorded_vehicle
0x1ac8f4ad40e22127, 0xa885765642d2bff6,
0x62ca17b74c435651, 0x79bea241e43fc2b3, // _0x62ca17b74c435651
0x932c2d096a2c3fff, 0x51ef94b008501da8, // is_ambient_speech_disabled
0x78321bea235fd8cd, 0xb79f09531aa23da5, // _0x78321bea235fd8cd
0x288df530c92dad6f, 0x1986d20e78b5ad52, // _0x288df530c92dad6f
0xb28eca15046ca8b9, 0xf0895a7452078524, // get_radio_station_name
0xf86aa3c56ba31381, 0xc1783ba6748cbb72, // _does_script_with_name_hash_exist
0x5a47b3b5e63e94c6, 0x943f19f96cc4ffb2, // get_entity_alpha
0xd80932d577274d40, 0xcf80c60f7d4be200, // get_synchronized_scene_rate
0x705a276ebff3133d, 0x345ef9962077d3c5,
0x6a98c2ecf57fa5d4, 0xd897be44c3bd9193, // _0x6a98c2ecf57fa5d4
0x867654cbc7606f2c, 0x29a0edea74b9e5a2, // shoot_single_bullet_between_coords
0x131bb5da15453acf, 0x6317e0d2a474f346, // network_earn_from_bounty
0x58f735290861e6b4, 0x96c88b03f5c58690,
0x908cbecc2caa3690, 0xe027064b1c47e424, // is_player_ready_for_cutscene
// 0x60e892ba4f5bdca4, 0x0,
0x5096fd9ccb49056d, 0x77812dda6e4d9fe2, // _0x5096fd9ccb49056d
0xb6b9ddc412fceee2, 0xad5cdcac1c763144, // _object_value_get_object
0x23f8f5fc7e8c4a6b, 0xb62da19846051096, // get_ped_nearby_peds
0x3364aa97340ca215, 0x568d314d73140729, // network_register_player_broadcast_variables
0xdc459cfa0cce245b, 0x1f07cd05d41d183b, // _0xdc459cfa0cce245b
0x4ef47fe21698a8b6, 0xa27bae67d4d9f1d2, // set_ped_defensive_area_attached_to_ped
0xb13c14f66a00d047, 0x63b608cd1957089e, // set_cam_fov
// 0xd2dccd8e16e20997, 0x0, // _0xd2dccd8e16e20997
0xe03b3f2d3dc59b64, 0xbc17b8529dadf0f8, // is_waypoint_playback_going_on_for_ped
0xed712ca327900c8a, 0x68673f1f33387a35, // set_weather_type_now_persist
0x49e50bdb8ba4dab2, 0x36e99b0eecfe7b6a, // _0x49e50bdb8ba4dab2
0x6e16bc2503ff1ff0, 0xe3adc76d6418297e, // get_safe_pickup_coords
0x211ab1dd8d0f363a, 0x84c2467d7f40d5fc, // _decor_set_float
0xf1c03a5352243a30, 0x7ca8ff5ba390419, // _0xf1c03a5352243a30
0x2cfba0c9e9275ce, 0x19f0f3434a101a56, // flash_ability_bar
0xa5efc3e847d60507, 0x7d6f4f4ee4799230, // _0xa5efc3e847d60507
0x84de3b5fb3e666f0, 0x3e8c637ce8a23e7d, // _0x84de3b5fb3e666f0
0x5ba7919bed300023, 0x262617de7f70a56d, // set_ped_dies_when_injured
0xa13e93403f26c812, 0x6fb61e0e6bcc8486, // _0xa13e93403f26c812
// 0xf98e4b3e56afc7b1, 0x0, // _0xf98e4b3e56afc7b1
0x299faebb108ae05b, 0x15fbe4622810d829, // lock_minimap_angle
0xf417c2502fffed43, 0xb84eb2b8d06f16d2, // _get_vehicle_model_max_speed
0x944f30dcb7096bde, 0x9270a1e407520471, // task_combat_ped_timed
0xc485e07e4f0b7958, 0x51904037794633ff, // _0xc485e07e4f0b7958
0xf6f5161f4534edff, 0xe9a805d36263fc10, // _get_entity_population_type
0xb08b85d860e7ba3c, 0xddb8885b4eca5362, // _0xb08b85d860e7ba3c
0xc02f4dbfb51d988b, 0x2775439f06235586, // set_text_centre
0x1c491717107431c7, 0x83cb74348d6228,
0x966dd84fb6a46017, 0x318e284cf983930f,
0xff059e1e4c01e63c, 0xd2fc3e8846422f96, // get_ped_type
0x57d9c12635e25ce3, 0x43937b909498729, // register_named_rendertarget
0x6ff8ff40b6357d45, 0x1b094ac15936b3db, // network_is_participant_active
0xf4ff020a08bc8863, 0xa857f5a3e7d1dbd8, // _0xf4ff020a08bc8863
0x3ac1f7b898f30c05, 0x15d619d1643be023, // reset_ped_visible_damage
0x7b226c785a52a0a9, 0xe01c88c9bda6ecaf,
0x6f43e5175eb6d96, 0x74a3f075a72d7a24, // has_preload_mods_finished
0x6e91b04e08773030, 0x3533a4cd9976d756, // _0x6e91b04e08773030
0x487a82c650eb7799, 0x3b5e90bfd644101, // custom_menu_coordinates
0xd79deefb53455eba, 0xd92171bc6c48db90, // stop_scripted_conversation
0x4e74e62e0a97e901, 0x713e47c722bd3943, // _0x4e74e62e0a97e901
0xa41a05b6cb741b85, 0xe980bafd70e8a4b3,
0x8974647ed222ea5f, 0xe27b5de53a86ce7c, // test_probe_against_all_water
0x9747292807126eda, 0x933f02bd6297a9c6,
0xa97f257d0151a6ab, 0x282ac7d53286da83, // _hide_map_object_this_frame
0xb282dc6ebd803c75, 0xe18bdd1e31c07544, // give_delayed_weapon_to_ped
0xcbbde6d335d6d496, 0x7d01de4c909b4391,
0x4dc9a62f844d9337, 0x9b027677a03aad64, // get_nearest_player_to_entity_on_team
0x924426bffd82e915, 0x17308af10d44fb4a,
0xeeed8fafec331a70, 0x22f1a4d7dd8e49a6, // _0xeeed8fafec331a70
0x37025b27d9b658b1, 0x4ff1af8fa372eaf, // _get_content_file_version
0x35f7dd45e8c0a16d, 0x802f1160a12fdac3, // _is_interior_prop_enabled
0x60dfd0691a170b88, 0xb5d4e8f757c24136, // is_ped_in_cover
0xc7397a83f7a2a462, 0xff494315b6be645d, // _0xc7397a83f7a2a462
0x450930e616475d0d, 0x19859cb72b1db4c, // reset_hud_component_values
0x3430676b11cdf21d, 0x31a38504765ec58f, // _highlight_placement_coords
0xde18220b1c183eda, 0xf08d9743c7dd27f8, // destroy_itemset
0xb7952076e444979d, 0x43f9cf21b883831a, // get_shop_ped_outfit
0xbe6b23ffa53fb442, 0x762f7a52b1325903, // set_text_colour
0x73518ece2485412b, 0xcac7e65b952c8814, // set_ped_can_leg_ik
0x9f243d3919f442fe, 0xf3e8c179636ed71e, // is_big_vehicle
0x5a43c76f7fc7ba5f, 0x1a9da684529224a0,
0xa1e5e0204a6fcc70, 0x70442b47688a466e,
0xc8bc6461e629beaa, 0xb5531a0d55065699, // is_incident_valid
0x302c91ab2d477f7e, 0x2c081bf66d28718b,
0x9663fe6b7a61eb00, 0x3d966cdf3760e956,
// 0xe36a98d8ab3d3c66, 0x0, // _0xe36a98d8ab3d3c66
0x57005c18827f3a28, 0x706a08d481aaff19, // network_is_friend_in_multiplayer
0x9b6e70c5ceef4eeb, 0xbb98a3bc7805ed64, // _0x9b6e70c5ceef4eeb
0xbb90e12cac1dab25, 0xbeaea267d8b7bbb1, // _0xbb90e12cac1dab25
0x38fe1ec73743793c, 0x9f992d8c67ac62d1, // set_ped_path_prefer_to_avoid_water
0x957e790ea1727b64, 0x817b4f2c156a62d,
0x76b02e21ed27a469, 0x9d34f024713b3952, // reserve_network_mission_vehicles
0x1216e0bfa72cc703, 0xd72905e002383cca, // _0x1216e0bfa72cc703
0xe7e11b8dcbed1058, 0x5d1d8f83b8ac0649, // get_mount
0x420bd37289eee162, 0x74d5c2c6e4d82bf7, // _disable_interior_prop
// 0xd16c2ad6b8e32854, 0x0, // _get_tupstat_int_hash
0x239528eacdc3e7de, 0xf23201c524e43f1c, // set_player_invincible
0xc3ac2fff9612ac81, 0x15787e9b74fd738b, // _start_recording
0xf9e56683ca8e11a5, 0x531d08bf9f31222e, // play_ped_ringtone
0xd5c12a75c7b9497f, 0xd911392442636b60, // add_cover_point
0x3b4bf5f0859204d9, 0x5678738367dd578f, // set_cutscene_audio_override
0xd76632d99e4966c8, 0xedf1007f28c40a18, // set_ped_to_ragdoll_with_fall
0xe6869becdd8f2403, 0xed1dd8380ad54bbe, // _0xe6869becdd8f2403
0x22cca434e368f03a, 0x6fe9f15aeb5f8019, // has_collision_for_model_loaded
0x55e1d2758f34e437, 0x7437b994d9f2a07a, // clear_vehicle_custom_primary_colour
0x583df8e3d4afbd98, 0x3ceb502494a47e20,
0x621873ece1178967, 0x656cc1e503e9c302, // _set_entity_coords_2
0xaba17d7ce615adbf, 0xcf8fb817b736462a, // _begin_text_command_busy_string
0x2ed7843f8f801023, 0x9457c7e9a5e2bc86, // _draw_notification
// 0xf8cc1ebe0b62e29f, 0x0, // _0xf8cc1ebe0b62e29f
0xa320ef046186fa3b, 0xcd6ac6518f0487de, // is_mounted_weapon_task_underneath_driving_task
// 0x198d161f458ecc7f, 0x0,
0xc968670bface42d9, 0x9ec5bdc006623c42, // has_force_cleanup_occurred
0xce86d8191b762107, 0x560e5dadb473d1fb, // network_get_primary_clan_data_start
0x523a590c1a3cc0d3, 0x9777431bf21e161b,
0x2da49c3b79856961, 0x4436dc94592033ff, // does_anim_dict_exist
0x25615540d894b814, 0x4caea6318c78ec53, // _0x25615540d894b814
0xa7a866d21cd2329b, 0x3039527f47b67213,
0x2632482fd6b9ab87, 0x8fc121bfd91cccdc,
0xa4ff579ac0e3aaae, 0x8acf6d19519697bd,
0x3e8c8727991a8a0b, 0xa155ccfa52a9a0c4, // set_vehicle_strong
0x64473aefdcf47dca, 0xbc85ca5ead2d2a92, // track_vehicle_visibility
0x181ec197daefe121, 0x3da7f51505ba3457, // enable_special_ability
0x7c9c0b1eeb1f9072, 0xc47fb6d9a97433f2, // _0x7c9c0b1eeb1f9072
0xd465a8599dff6814, 0x80bcef49b61e84c9, // set_player_can_use_cover
0xd7e3b9735c0f89d6, 0x6bb2785511e9f977, // get_object_index_from_entity_index
0x5ffbdeec3e8e2009, 0x2ab433faf38dc9b4, // clear_vehicle_custom_secondary_colour
0x54736aa40e271165, 0xfa97bc0260d58add, // is_entity_in_area
0xeb6fb9d48dde23ec, 0xf2a47bf35e77e415, // set_ped_steers_around_vehicles
0x372ef6699146a1e4, 0x61776b47a9daf491, // _0x372ef6699146a1e4
0x142a02425ff02bd9, 0xf6d940c3cf409665, // task_start_scenario_in_place
0xf1550c4bd22582e2, 0x425a73c52790195c, // set_ped_helmet_texture_index
0x761b0e69ac4d007e, 0x5d46f96af9cac09a, // has_closest_object_of_type_been_broken
0x584fdfda48805b86, 0x4951ee4bb7b6b4f7, // get_mobile_phone_position
0xce5aa445aba8dee0, 0x9797b2bc0c5e740e, // _0xce5aa445aba8dee0
0x63dab4ccb3273205, 0x742b30ca144c9d18, // reset_group_formation_default_spacing
0xa586fbeb32a53dbb, 0xe6cc4a277fb5cb21,
0xc3c221addde31a11, 0x3105d258dd7f0f96, // _0xc3c221addde31a11
0x1e2817a479a7f9b, 0x5b3ad7a02822334d, // is_ambient_zone_enabled
0x14832bf2aba53fc5, 0xbfcfb1538684ef55,
0x4a0c7c9bb10abb36, 0x376e9599f3b739be, // _0x4a0c7c9bb10abb36
0xc0e78d5c2ce3eb25, 0xed8ce0a4a49cd41b, // set_ped_helmet_flag
0x8abe8608576d9ce3, 0x954bb77db6263c48, // _0x8abe8608576d9ce3
0x8509b634fbe7da11, 0x37621d6689f9e3c3, // begin_text_command_display_help
0xbfe5756e7407064a, 0xdaae40d23c256135, // _shoot_single_bullet_between_coords_with_extra_params
0x61f95e5bb3e0a8c6, 0x1633a4504218296, // _0x61f95e5bb3e0a8c6
0xd9175f941610db54, 0xd69fa0316aaf0855, // cap_interior
// 0xb055a34527cb8fd7, 0x0, // _0xb055a34527cb8fd7
0x5b4f04f19376a0ba, 0xbaa868d36fbc748b,
0x2497c4717c8b881e, 0x9fabd0ab045a5d6e, // set_vehicle_engine_on
// 0xc8b46d7727d864aa, 0x0, // enable_laser_sight_rendering
0x88b588b41ff7868e, 0xe2b516a8e0e01cd4,
0xeee6eacbe8874fba, 0xdd530ac51a578470, // network_clan_player_get_desc
// 0xed481732dff7e997, 0x0, // special_ability_charge_continuous
0xa619b168b8a8570f, 0xe0df6e9b18d50168, // set_radio_to_station_index
0x16f46fb18c8009e4, 0x446bc6ebc42bafa8, // _0x16f46fb18c8009e4
// 0xed51733dc73aed51, 0x0, // player_attach_virtual_bound
// 0x74698374c45701d2, 0x0,
0x58c70cf3a41e4ae7, 0x656e3bb78935070e, // set_sequence_to_repeat
0x7345bdd95e62e0f2, 0x4f2c9a8d75a8bba9, // request_mission_audio_bank
0x34f9e9049454a7a0, 0xf84b1acda9dc2c16, // network_block_invites
0xd261ba3e7e998072, 0xb08cbfa9a14d6ff5, // _0xd261ba3e7e998072
0x9c8c6504b5b63d2c, 0x1b556376ad60a98d, // start_vehicle_horn
0x40aefd1a244741f2, 0xf47751306c33a16c, // _0x40aefd1a244741f2
0xe33ffa906ce74880, 0x3fcd3fcfafc3878c, // _0xe33ffa906ce74880
0x11ff1c80276097ed, 0x3bdfdf06b92df21c, // _0x11ff1c80276097ed
0x1aa8a837d2169d94, 0xc75e929aa37719df, // _0x1aa8a837d2169d94
0x1e314167f701dc3b, 0xe5af71214c7753f8, // get_blip_info_id_display
0x42cbe54462d92634, 0x27b93cf03b03ab8c, // set_ditch_police_models
0x89023fbbf9200e9f, 0x765ff3592ec81689,
0xb2798643312205c5, 0xa18c8f78a10d412, // _get_text_substring_safe
0x95914459a87eba28, 0xdb03ec449c340e55,
0x9f5e6bb6b34540da, 0x6284bb4f25685a89, // _0x9f5e6bb6b34540da
0xc2afffdabbdc2c5c, 0x6dd215a8a3129c26, // _set_achievement_progression
0x6726bdccc1932f0e, 0x5fc25a9f19eb39fa, // is_interior_ready
0x355ef116c4c97b2, 0xf2376062423b42b9, // start_alarm
0x79b258e397854d29, 0x60e18550f449bf9c, // task_exit_cover
0xc80a74ac829ddd92, 0x648a75d3f60e864, // set_ped_relationship_group_hash
0x5a504562485944dd, 0x98da32975e6e1dd8, // get_entity_height
0xd2a71e1a77418a49, 0x1fcb57e33cea24e8, // request_clip_set
0x72751156e7678833, 0x58674a048b20c3d4, // set_ignore_no_gps_flag
0x153973ab99fe8980, 0x7b1011a61f402324, // _dynamic_mixer_related_fn
0x441603240d202fa6, 0xb40aac1dd7d44e6, // set_text_edge
0xcc9f3371a7c28bc9, 0x30a0349b943616d5, // is_cinematic_shot_active
0x422f32cc7e56abad, 0xd0900a362ad1f7aa, // _0x422f32cc7e56abad
0x5fd1e1f011e76d7e, 0x68e7c703c4450f0f, // set_ped_ammo_by_type
0x207f1a47c0342f48, 0xcaf16e31a4d77f04, // set_anim_weight
0x11d5f725f0e780e0, 0xba85a9f236c12df4, // set_player_reset_flag_prefer_rear_seats
0xf4a0dadb70f57fa6, 0x583d21cbaa781171,
0xea16b69d93d71a45, 0xa4e4e6ec9e834a36, // _network_access_tunable_bool_hash
0x2206bf9a37b7f724, 0xb1f8038f56c12b7, // animpostfx_play
0xcca4318e1ab03f1f, 0xdcca82fdc3e5446d, // _0xcca4318e1ab03f1f
0x504d54df3f6f2247, 0x7c339d4328ca16c, // task_leave_any_vehicle
0xf1b84178f8674195, 0xf08220106f015ca, // _0xf1b84178f8674195
0x17fca7199a530203, 0xcd3a495f8c74a0b6,
0xb129e447a2eda4bf, 0xb771670e8335c073, // _0xb129e447a2eda4bf
0xd92c739ee34c9eba, 0x28b764a9a9c6c945, // get_weapon_hud_stats
0xba2c7db0c129449a, 0x87c08221f8c86442, // leaderboards2_read_by_rank
0x4f5f651accc9c4cf, 0x62c7929b22d80b4c, // set_ped_bounds_orientation
0xbeb3d46bb7f043c0, 0xaaed682d6d52ba35, // _0xbeb3d46bb7f043c0
0x3a618a217e5154f0, 0x5263ff82360ff7e2, // draw_rect
0xb6c49f8a5e295a5d, 0x5b56bdd0171d81e5, // set_synchronized_scene_rate
0xed74007ffb146bc2, 0x5d94f4d6fe7da516, // remove_ped_from_group
0x2a1f4f37f95bad08, 0xbcd21d2535e4a2c9, // toggle_vehicle_mod
0x5cec1a84620e7d5b, 0x5628ce9f91160050, // set_disable_breaking
0xe7e035450a7948d5, 0xa32050112c970b01, // _object_value_add_integer
0xcc6e963682533882, 0x3fb5fd739775d626, // _0xcc6e963682533882
0x1a992da297a4630c, 0xedc6570e9247907a, // add_stunt_jump
0x84d32b3bec531324, 0xb37a0ba7d41ea5e1, // task_seek_cover_from_ped
0x4d41783fb745e42e, 0xfa3130c046ac45a7, // set_cam_coord
0x84c8d7c2d30d3280, 0xfcf00d38871cb48b, // move_vehicle_decals
0x120c48c614909fa4, 0x859ef56d19b70b6, // clear_ambient_zone_list_state
0x5ccabffca31dde33, 0x9cfb460f67d07538,
0x7d41e9d2d17c5b2d, 0xd007040030f44ed2, // _0x7d41e9d2d17c5b2d
// 0xd3a6a0ef48823a8c, 0x0,
0xacee6f360fc1f6b6, 0x1a64dd706136470c, // set_particle_fx_cam_inside_nonplayer_vehicle
0x1121bfa1a1a522a8, 0x97ea1976bdb4a8ce,
0x33506883545ac0df, 0x19f91f1d1fa8cdf9, // _0x33506883545ac0df
0x2c40bf885c567b6, 0x3f2f21bcb3761848, // _network_convert_synchronised_scene_to_synchronized_scene
0x631dc5dff4b110e3, 0x630deff534fc5d1d, // _0x631dc5dff4b110e3
0xfa4efc79f69d4f07, 0xbfa5dcfce7bbe54, // task_start_scenario_at_position
0x388a47c51abdac8e, 0xe51f6afea84c2923, // is_player_being_arrested
0xc531ee8a1145a149, 0x248fd45578d37759, // is_door_closed
0xd45cb817d7e177d2, 0xce92232cb1e93c46, // network_handle_from_friend
0xb5c51b5502e85e83, 0x65a1ded6bfbff0e8, // _set_vehicle_exclusive_driver_2
// 0x4e52e752c76e7e7a, 0x0, // _0x4e52e752c76e7e7a
0xa67c35c56eb1bd9d, 0x956369c822a6ada4,
0xb812b3fd1c01cf27, 0xcceafd1c2aa17727, // set_cutscene_origin
0xfd75dabc0957bf33, 0x71709d18d48b6fd, // _0xfd75dabc0957bf33
0x749faddf97dfe930, 0xdb3aeb906ac134ab, // set_player_cloth_pin_frames
0x11e79cab7183b6f5, 0x5b8ed4ba3d7fd689, // stop_synchronized_map_entity_anim
0xf54bb7b61036f335, 0x2533be33c0943207, // reset_ped_audio_flags
0xfd00798dba7523dd, 0xdb53bc990585ab1,
0xfaa23f2cba159d67, 0x9e7e7ad61ed13108, // start_player_switch
0x238ffe5c7b0498a6, 0x92150016c06c431, // end_text_command_display_help
// 0x62ec273d00187dca, 0x0, // _create_synchronized_scene_2
0x5d7b620dae436138, 0x5704f3cd60ecc7c7, // _0x5d7b620dae436138
0x9eefb62eb27b5792, 0xbc6aa949398c551e, // request_waypoint_recording
0xca94551b50b4932c, 0x5e5d8524117d6bc3, // _0xca94551b50b4932c
0x80c527893080ccf3, 0x8533470bd0e6cd59, // set_reduce_vehicle_model_budget
0xfc545a9f0626e3b6, 0xfdb30a402f5578af, // _task_vehicle_follow
0xc429dceeb339e129, 0x78893508441ad74f, // task_vehicle_temp_action
0x56e0fe8534c2949, 0xf4197686ef83f52a, // set_all_random_peds_flee
0x50cad495a460b305, 0x1d05f456626eb273, // get_number_of_fires_in_range
0xcb2cf5148012c8d0, 0xb09ba22c73228b8c, // is_time_less_than
0xb9efd5c25018725a, 0xbdd4ee948c7b9bb5, // set_audio_flag
0x3d95ec8b6d940ac3, 0x54c02256417bd9ff, // attach_entities_to_rope
0x9049fe339d5f6f6f, 0x777432a66d6af95a,
0x9029b2f3da924928, 0xae71bea7bbbfb78f, // set_blip_display
0xc50ce861b55eab8b, 0xf7f07ca63e3deb66, // _0xc50ce861b55eab8b
0x79923cd21bece14e, 0x78b659f6f2c8960, // get_dlc_weapon_data
0x870ddfd5a4a796e4, 0x925d6df7da67635f, // network_request_control_of_door
0xffc24b988b938b38, 0x524b4aaa3328e253, // set_facial_idle_anim_override
0x2b5f9d2af1f1722d, 0x9ba79b5a36a430e8, // set_vehicle_has_been_owned_by_player
0xcb968b53fc7f916d, 0x29d71323e0eb9ce5, // _0xcb968b53fc7f916d
0x6c4d0409ba1a2bc2, 0xa2036691dd4d2db2, // get_ped_last_weapon_impact_coord
0xbd545d44cce70597, 0x72155b10ef51e401,
0x35ad299f50d91b24, 0x4c103520ba328022, // create_itemset
0x16754c556d2ede3d, 0x12bf789190d82474,
0xb542de8c3d1cb210, 0x4f02a396673713e1, // _0xb542de8c3d1cb210
0x218ba067d249dea, 0xe46048adbfeba46a,
0xac09ca973c564252, 0xeaf855a7dc28bc8d, // does_text_label_exist
0x7ad9e6ce657d69e3, 0xc830239084b3826c, // roll_down_window
0xcefa968912d0f78d, 0xaf1075be3d8a79f7,
0x34e710ff01247c5a, 0x26e0ffdb1ad22ac5, // set_vehicle_lights
0x1fee67db37f59b2, 0xa1248dead0b27b8e, // is_ped_on_foot
0xf3d78f59dfe18d79, 0x416d27f4210731da, // set_fade_in_after_load
0xf1b760881820c952, 0x16e00f066affea0d, // get_distance_between_coords
0xd7591b0065afaa7a, 0xde8c6b23d2ad294a, // reset_vehicle_stuck_timer
0xf731332072f5156c, 0x735057e6a0704a43, // get_is_ped_gadget_equipped
0x520f3282a53d26b7, 0xcd8500c3fbbe9684,
0x10655fab9915623d, 0x4ecb586d9fe1fbe4, // _0x10655fab9915623d
0x530071295899a8c6, 0xca57931f89e1d249, // set_ped_in_vehicle_context
// 0xa071e0ed98f91286, 0x0, // _0xa071e0ed98f91286
0xd4e8e24955024033, 0xaccda78123db57b0, // do_screen_fade_in
0x95eb9964ff5c5c65, 0x1145040fa5049e0e, // has_entity_been_damaged_by_any_object
0x596976b02b6b5700, 0x230c52d735799425, // set_ignore_low_priority_shocking_events
0x62d5ead4da2fa6a, 0x5c0f9d7de1172bb4,
0xbe197eaa669238f4, 0xb6d740402ab4e86e, // _0xbe197eaa669238f4
0xd821490579791273, 0xdbf10d69b1617012, // enable_clown_blood_vfx
0xff4fb7c8cdfa3da7, 0x27ec01588b39474b,
// 0x6636c535f6cc2725, 0x0, // _0x6636c535f6cc2725
0x2c83a9da6bffc4f9, 0x1bcda92ad0a7835b, // _get_number_of_instances_of_script_with_name_hash
// 0x61e111e323419e07, 0x0, // _get_pstat_int_hash
0xd2209be128b5418c, 0x59d520e31e26f67, // _0xd2209be128b5418c
0xf030907ccbb8a9fd, 0x625a8786a9ca5f9a, // get_length_of_literal_string
0x57af1f8e27483721, 0x413efef56d8d86ee, // network_is_player_blocked_by_me
0x36492c2f0d134c56, 0xb13a12e14a63d582, // _0x36492c2f0d134c56
// 0xa17bad153b51547e, 0x0, // _0xa17bad153b51547e
0x692d808c34a82143, 0x1a8f5d489f7f6bc8, // _0x692d808c34a82143
0xa2f952104fc6dd4b, 0xe636ddc246ad2fa, // _0xa2f952104fc6dd4b
0xfc04745fbe67c19a, 0x2fb2e628236e98e9, // does_script_exist
0x6178f68a87a4d3a0, 0x37ade0ec220acf87,
0xd9f692d349249528, 0x25bd868b00b485e9,
0x69ff13266d7296da, 0x4fc799e2f8cd561f, // stat_set_license_plate
// 0xaa5d6b1888e4db20, 0x0, // delete_child_rope
0x5b76b14ae875c795, 0xb011acf4e2879a2c, // delete_mission_train
0x6c38af3693a69a91, 0x607f78fe329ecf8e, // use_particle_fx_asset
0xb77d05ac8c78aadb, 0x3465486651f18fb8, // set_vehicle_body_health
0x6ea318c91c1a8786, 0x72ac5e9e5f31d086, // _network_earn_from_daily_objective
0xa132fb5370554db0, 0xab030a93c416dbae, // get_vehicle_max_traction
0x424d4687fa1e5652, 0xb59a1ce271cea093, // is_player_dead
0x701fda1e82076ba4, 0x249542cfceea091f,
0x5e9564d8246b909a, 0xf272a2699b521ce6, // is_player_playing
0x722f5d28b61c5ea8, 0xb5c79fa51f716996, // _0x722f5d28b61c5ea8
0xc313379af0fceda7, 0xc4536d8d97198f29, // set_parachute_task_target
0x36f97c908c2b52c, 0x6010b3cac53496c3, // is_cam_interpolating
0xc6d3d26810c8e0f9, 0x33c25588912d8d39,
0xe78503b10c4314e0, 0x81a0dcb9db801731,
0x2b2a2cc86778b619, 0xfdacb90fa44481df,
// 0x247acbc4abbc9d1c, 0x0, // _0x247acbc4abbc9d1c
0x25ecb9f8017d98e0, 0x6893a1c97a426d74, // does_vehicle_have_weapons
// 0x140e6a44870a11ce, 0x0,
0xacfb2463cc22bed2, 0xfdaf3d5c2e2300e8, // set_last_driven_vehicle
0x6e13fc662b882d1d, 0xa17da2aedf7e89fd, // set_vehicle_tyre_fixed
0x859ed1cea343fca8, 0x4017d4828b0228af, // network_show_profile_ui
0xb5074db804e28ce7, 0xbbbd97da4797e06a,
0xe63d7c6eececb66b, 0xf3cf7af110b44a1c, // _0xe63d7c6eececb66b
0xc6eb449e33977f0b, 0xcfbb6009aef8dfb9, // _start_particle_fx_looped_on_entity_bone
0x99ac7f0d8b9c893d, 0x8b4bc279e595561, // _0x99ac7f0d8b9c893d
0xdf729e8d20cf7327, 0x2694e4096d4c697c, // get_blip_colour
0x27501b9f3b407e, 0x78713c03966ed44f, // set_roads_back_to_original_in_angled_area
0xae51bc858f32ba66, 0x78b78f673af6f39a, // _0xae51bc858f32ba66
0x34616828cd07f1a1, 0x5dacf31d3ac5ed8d, // is_ped_shooting
0xacf57305b12af907, 0xd9d5df131c46ef, // set_emitter_radio_station
0x9aa47fff660cb932, 0xf57e2b149ab53b81, // _set_vertical_flight_phase
0x352a9f6bcf90081f, 0xa049c04187b6e28e, // get_closest_fire_pos
0x219c7b8d53e429fd, 0x4382260282c96ecd, // format_focus_heading
0xc45d23baf168aab8, 0x787cbb9db6ba1a49, // get_vehicle_engine_health
0x24cb2137731ffe89, 0x340117f85ac524d4, // get_vehicle_number_of_passengers
0xc6f5c0bcdc74d62d, 0xcab00e0f9eb1039d, // get_navmesh_route_distance_remaining
0xde0f6d7450d37351, 0x4132e5728a18cb78, // is_bullet_in_box
0x231c8f89d0539d8f, 0x8588ee3a8dc4ca1c, // _set_radar_bigmap_enabled
0x2d05ced3a38d0f3a, 0xc65888009006911b, // explode_ped_head
0x5c48a1d6e3b33179, 0x542a75ac9c3d0519, // _0x5c48a1d6e3b33179
0x4b5cfc83122df602, 0x57b157204414c766,
0x7ee3a3c5e4a40cc9, 0x3a3707c1ecabf993, // set_vehicle_extra
0xa7bab11e7c9c6c5a, 0x126a7d611059a7f2, // _get_content_category
0x703b9079823da4a, 0x9e280e42c0773a3a, // set_ped_target_loss_response
0xc5be134ec7ba96a0, 0x36f3aa9ffaaf8606, // _0xc5be134ec7ba96a0
0x54972adaf0294a93, 0x5a2c46836b4df5b3, // draw_scaleform_movie
0x5ea784d197556507, 0x564075e0bc0bcb8d,
0x37a4494483b9f5c9, 0x44020bf21dd2d485,
0x886913bbeaca68c1, 0xdd24d0735cfdaf27, // _0x886913bbeaca68c1
0xb302244a1839bdad, 0x8b096ed4bb378aa7, // add_decal
0x92da6e70ef249bd1, 0xd778ad0c895bdff5, // _0x92da6e70ef249bd1
0x349ce7b56dafd95c, 0x1c4f8bdba7cd3c71, // is_move_blend_ratio_still
0xb7ed70c49521a61d, 0x2f8dc37d0d6cba93, // _0xb7ed70c49521a61d
0xe1e65ca8ac9c00ed, 0xbc7f713a43dc55c7, // play_facial_anim
// 0xe95c8a1875a02ca4, 0x0, // _0xe95c8a1875a02ca4
0x706b5edcaa7fa663, 0x51fc7174df99bae5, // _set_custom_respawn_position
0xf4c8cf9e353afeca, 0xc2c1de3f1eeff7af, // _0xf4c8cf9e353afeca
0xe143fa2249364369, 0x68f833bfe3a28fea, // get_closest_object_of_type
0xde2ef5da284cc8df, 0x94d25d7cf519de77,
0xe111a7c0d200cbc5, 0x67fb0b588fad6e46, // _0xe111a7c0d200cbc5
0x419594e137637120, 0x99f042e8e820cf92, // network_set_in_spectator_mode_extended
0xcc97b29285b1dc3b, 0x97abe4ede9160310, // set_animal_mood
0xde4c184b2b9b071a, 0x1463b2c4e96cfb40, // is_ped_walking
0xdc2c5c242aac342b, 0xf74b05fb8108f9c, // set_ped_lod_multiplier
0x4d9ca1009afbd057, 0x34a51926277f67bc, // set_ped_combat_movement
0xe465d4ab7ca6ae72, 0x3012a80fced6f736, // get_collision_normal_of_last_hit_for_entity
0xd201f3ff917a506d, 0x42eb66bebe5b2242, // _set_minimap_attitude_indicator_level
0xbf29516833893561, 0x4ba4a8ef529320c3, // set_ped_enveff_scale
0xd0a484cb2f829fbe, 0x2bcae8fb01dfa1f3,
0xf33bdfe19b309b19, 0xfb6fed41db480f1c, // is_ped_wearing_helmet
0xb3ed1bfb4be636dc, 0x6598ba4640d7e61a, // get_vehicle_wheel_type
0xa46af8a78dc5e0a, 0x1fa21f836f14e62f,
0xfb199266061f820a, 0x921f85f539d907cf,
0x1b1e2a40a65b8521, 0xf0375d7cf3b53f77, // set_ai_weapon_damage_modifier
0x75773e11ba459e90, 0x2eb10fe45be326ae, // _0x75773e11ba459e90
0x4cd49b76338c7dee, 0x360e34ac1b6ddd00, // _object_value_add_vector3
0xc90d2dcacd56184c, 0x841080481716e87c, // set_script_as_no_longer_needed
0x40b62fa033eb0346, 0x329015f514a278c0, // override_cam_spline_velocity
0x16469284db8c62b5, 0xc8f2cb753b5e9422, // set_train_cruise_speed
0x2f8b4d1c595b11db, 0xd06834ff174edc89,
0xd313de83394af134, 0x87724672218c107c,
0x5c3d0a935f535c4c, 0x8f0ab58dbdb1297a, // get_last_material_hit_by_entity
0x40fdedb72f8293b2, 0xd45ddb32b5fade2e, // force_entity_ai_and_animation_update
0xe266ed23311f24d4, 0x81fa87c722a7bd74, // _0xe266ed23311f24d4
0x9bf438815f5d96ea, 0x5ffe98ca5c92bccd, // _0x9bf438815f5d96ea
0xa41b6a43642ac2cf, 0x3d3eb63b7fdf87a6, // start_networked_particle_fx_non_looped_on_ped_bone
0xae287c923d891715, 0x74ccccfc496fbdc7, // remove_cover_point
0x164ecbb3cf750cb0, 0x2136e753816c9b70, // set_tracked_point_info
0x589b5e791ce9b2b, 0xac584348b06672dd, // create_money_pickups
0x6874e2190b0c1972, 0x442dbf7783bc7709, // find_spawn_point_in_direction
0x115722b1b9c14c1c, 0x1a56d9c73ba20091, // set_vehicle_fixed
0x88bb3507ed41a240, 0x15de1642f0ee9f75,
// 0xdaf87174be7454ff, 0x0, // _0xdaf87174be7454ff
0xe7cf3c4f9f489f0c, 0xc16d1b065e3eea79, // is_vehicle_attached_to_trailer
0x9ac577f5a12ad8a9, 0x5bfa1f420ed32cff, // set_ped_firing_pattern
0x87e7f24270732cb1, 0xb29b4778a44b21a8, // open_bomb_bay_doors
0x2a74e1d5f2f00eec, 0xf7c907e9e8e2bb22, // is_ped_getting_up
0xa31fd15197b192bd, 0x5b3a8fc9a493198e,
0x4cebc1ed31e8925e, 0xc0e4da728edd8255, // _0x4cebc1ed31e8925e
0x13d2b8add79640f2, 0x7ea67bd818402745,
0x5e24341a7f92a74b, 0x1c73341ca47ddec8,
0x2e65248609523599, 0x584d57b6943af499, // _0x2e65248609523599
// 0x71fb0ebcd4915d56, 0x0, // network_do_transition_quickmatch
0xd127585f77030af, 0x733de09777d47cd6, // get_player_group
0x3c49c870e66f0a28, 0xa95696ccb1cafe6a, // give_player_ragdoll_control
0x8702416e512ec454, 0xa7f26e75de91ec1d, // has_named_ptfx_asset_loaded
0x2309595ad6145265, 0xa30f802a35094b6a,
0x5e3cf89c6bcca67d, 0x8e09c0735236f309, // create_camera
0x14e56bc5b5db6a19, 0x2efaceb7cc6076d0, // set_ped_ammo
0xef398beee4ef45f9, 0xbcdc495e812c1253, // _0xef398beee4ef45f9
0x3dbf2df0aeb7d289, 0xc0bd3c838bd70bed, // _0x3dbf2df0aeb7d289
0x6abfa3e16460f22d, 0xb1a92b63d6757eef, // create_camera_with_params
0x578c752848ecfa0c, 0x4d3271911874786f, // _set_weather_type_transition
0xd71649db0a545aa3, 0x910ff514d7bc5674, // is_ped_facing_ped
0xb919e1fb47cc4e0, 0x409068a2d37919a9, // _0x0b919e1fb47cc4e0
0x3e9b2f01c50df595, 0x7643bb59992a9e6e, // network_register_host_broadcast_variables
0x9e6b70061662ae5c, 0x9aa1574e00850065, // get_relationship_between_groups
0xaf66dcee6609b148, 0x4ac1eb89981afafd,
0x8026ff78f208978a, 0x1c0f962f35913f6e, // set_player_may_only_enter_this_vehicle
0xe135a9ff3f5d05d8, 0xcc6dfcfe9b9e68b0, // set_entity_locally_invisible
0x14f96aa50d6fbea7, 0x925d9b26fb4077e7, // get_next_blip_info_id
// 0xf4d8e7ac2a27758c, 0x0, // _0xf4d8e7ac2a27758c
0x4159c2762b5791d6, 0x4a16cfbfcd48aded, // get_entity_lod_dist
0x883d79c4071e18b3, 0xdb260a75edf2c76,
0x7284a47b3540e6cf, 0xe7e2dde41fae5574, // network_has_invited_gamer_to_transition
0xc59f528e9ab9f339, 0xc7d0a132a56d5fcb,
0x5f5d1665e352a839, 0x65575b2a90f35e4e, // _set_ped_decoration
0x39d55a620fcb6a3a, 0x36e897473e9398f4, // _0x39d55a620fcb6a3a
0xf0e4ba16d1db546c, 0x314f75cc468f3a10, // _0xf0e4ba16d1db546c
0xb782f8238512bad5, 0x1275bb7c5082a0e, // _0xb782f8238512bad5
0x38baaa5dd4c9d19f, 0x64f78b5052e4aa2e, // _0x38baaa5dd4c9d19f
// 0x9606148b6c71def, 0x0, // set_vehicle_rudder_broken
0x9088eb5a43ffb0a1, 0x177c85c6d06e7e04, // set_vehicle_number_plate_text_index
0x3bab9a4e4f2ff5c7, 0xf8267ae9c3b14a7,
0xd2b315b6689d537d, 0x164ed91aadc415e3, // _0xd2b315b6689d537d
0xc7420099936ce286, 0xdff23297022c8cf, // _network_access_tunable_bool_hash_fail_val
0x45a9187928f4b9e3, 0x444d956c7f94526e, // is_this_model_a_boat
0xc0c4e81e1ac60a0, 0x92539c2a7085b235,
0xf3929c2379b60cce, 0x18d92f5299e07379,
0x89d630cf5ea96d23, 0x3793be214881f17b, // _0x89d630cf5ea96d23
0xcbdd322a73d6d932, 0x24351f8f4b7d0fea, // set_mobile_phone_scale
0x1509c089adc208bf, 0xd8672e778d791be5, // set_ped_steers_around_objects
0xc7e7181c09f33b69, 0x5ea43d8915271fb4, // _0xc7e7181c09f33b69
0x78857fc65cadb909, 0x89d80fc214d65d3d, // _0x78857fc65cadb909
0x9b1e824ffbb7027a, 0xc866e59063cf2d94, // reset_entity_alpha
0x83e87508a2ca2ac6, 0x4f1c103ea0dcee22, // set_gameplay_object_hint
0xdf993ee5e90aba25, 0x1096811db3a77ec1, // set_ped_can_ragdoll_from_player_impact
0xa628a745e2275c5d, 0xb34a6e8d284a761e, // network_spent_buy_offtheradar
0x7167371e8ad747f7, 0x4dc3f82aca7c9bb9, // set_checkpoint_rgba
0xea47fe3719165b94, 0x108754262311d34f, // task_play_anim
0x2fb897405c90b361, 0xff6e5eab585aba6a, // waypoint_recording_get_coord
0x21c235bc64831e5a, 0xb82f64bee70ac7b, // _0x21c235bc64831e5a
0x437138b6a830166a, 0x5f5259320a206908,
// 0x525a2c2562f3cd4, 0x0, // _is_ped_lipstick_color_valid
0xbc4c9ea5391ecc0d, 0xb31f7b7798441cf3, // is_hud_component_active
0xce5f689cf5a0a49d, 0xac9a3f5142199335, // network_get_player_from_gamer_handle
0xef0912ddf7c4cb4b, 0x7a7e39c1a0c7651c,
0xbcedb009461da156, 0x56debe9615c7eb97,
0xa29177f7703b5644, 0x91efbaaed4f50f4d,
0xb071e27958ef4cf0, 0x8607bff573507eb6,
0x758f49c24925568a, 0xf644725d24c31b93, // preload_vehicle_mod
0x43d3807c077261e3, 0xc6bb9365c4a5f6e, // stop_synchronized_entity_anim
0x5e657ef1099edd65, 0x9237c2fc54146973, // _0x5e657ef1099edd65
0x1a5cd7752dd28cd3, 0x8f43120631965d85, // key_hud_colour
0x8e02d73914064223, 0x4194409a3224426f, // network_add_friend
0xd5a016bc3c09cf40, 0x3faef65de3bdb741, // get_player_reserve_parachute_tint_index
0xe01903c47c7ac89e, 0xbd2e6e84a2814185,
0xf39c4f538b5124c2, 0x651e809b08ac55e2, // set_convertible_roof
0x571feb383f629926, 0x26bb2c9a29f5c120, // _0x571feb383f629926
0x189e955a8313e298, 0xc94cf61bf93818c8, // set_gameplay_entity_hint
0xc70ddce56d0d3a99, 0xa4023e4bf223860c,
0xbaf6babf9e7ccc13, 0xfa103b6471084bd3, // _0xbaf6babf9e7ccc13
// 0xc2eae3fb8cdbed31, 0x0, // _0xc2eae3fb8cdbed31
0x6acf6b7225801cd7, 0x3e7ea351dbcb7e7a, // set_synchronized_scene_origin
0x5d6160275caec8dd, 0xca25f5f1e0708b9c, // get_hash_name_for_prop
0xeb4a0c2d56441717, 0x8baa729b3f120604, // _get_number_of_dispatched_units_for_player
0x3ae22deb5ba5a3e6, 0x26abae1d971ceacd, // set_object_as_no_longer_needed
0x26d83693ed99291c, 0x451a7f34db13317, // set_ped_helmet_prop_index
0xf9c1681347c8bd15, 0x389ed27d793d5f9a, // _0xf9c1681347c8bd15
0x2dacd605fc681475, 0x603fb090b12d0620, // get_position_in_recording
0x6d0858b8edfd2b7d, 0xd6eda274d82e8678, // set_gameplay_cam_relative_pitch
// 0x97e7e2c04245115b, 0x0, // _0x97e7e2c04245115b
0x729b5f1efbc0aaee, 0xd7bea9b57bcf07b6, // get_blip_hud_colour
0xdf47fc56c71569cf, 0x9b49c1ea66e0b669, // set_pause_menu_active
0xf3b9a78a178572b1, 0xfec326a8e632c9ae, // task_arrest_ped
0xc449eded9d73009c, 0xe58e54f90363a71d,
0xecb41ac6ab754401, 0xe3acddfb4b8fa5eb,
0x1d6a14f1f9a736fc, 0x6a41f53fe1128e10, // network_get_host_of_script
0xb87a37eeb7faa67d, 0xc9d26bbbee23407, // begin_text_command_print
0xfe07ff6495d52e2a, 0x3747827632ab674d, // _0xfe07ff6495d52e2a
0x312342e1a4874f3f, 0xc0c242325701ed15, // _0x312342e1a4874f3f
0x2b7e9a4eaaa93c89, 0x9734894b4bdc7e6a, // _set_notification_message
0xba63d9fe45412247, 0x91dd484182b17b3, // _0xba63d9fe45412247
0x75ba1cb3b7d40caf, 0xd850b8b8d1478aa4, // _0x75ba1cb3b7d40caf
0x36ad3e690da5aceb, 0xbaecf0e9fb36385b, // animpostfx_is_running
0xde81239437e8c5a8, 0x67b8f07aab9e043b,
0xdb283fde680fe72e, 0x32e141f52deeaf42, // stat_set_pos
0x88e32db8c1a4aa4b, 0xe2ee01e03b6da177, // _0x88e32db8c1a4aa4b
0x113750538fa31298, 0x9c23a9ec7e5de766, // is_named_rendertarget_linked
0x25fbb336df1804cb, 0xaa70163b3b48eee4, // begin_text_command_display_text
0xd46923fc481ca285, 0x2e4f269906bf5f41,
0xb3f64a6a91432477, 0xbe712af8e5fddca3,
0x5aa3f878a178c4fc, 0x9903ca15cea6aed8, // _get_vehicle_model_move_resistance
0xaea8fd591fad4106, 0x9dc577e2a517cc1e, // is_playback_using_ai_going_on_for_vehicle
0x9d292f73adbd9313, 0x1005b9e0c2b02a3b,
0x7d80fd645d4da346, 0x7f0796d48935f411, // start_playback_recorded_vehicle_with_flags
0xd7d22f5592aed8ba, 0x7af953b8fc2cc518, // _0xd7d22f5592aed8ba
0xeb6f1a9b5510a5d2, 0x750d1befbbffba9b, // _0xeb6f1a9b5510a5d2
0x222ff6a823d122e2, 0xc5441df30553fb3a, // set_vehicle_reduce_grip
0xa00efe4082c4056e, 0xe6e7499ba6cf626b, // sc_inbox_message_get_data_int
0xe36a25322dc35f42, 0xc716f4f9f7db8dd0, // get_time_since_player_hit_ped
0xd1065d68947e7b6e, 0x50e6a77f383ef7bf, // set_local_player_visible_in_cutscene
0x2d537ba194896636, 0xdf87b496dd409fb7, // _task_move_network
0x7bf1d73db2eca492, 0x9aeb736514e1e706, // network_spent_heli_pickup
0x5a353b8e6b1095b5, 0xad4efceb3014fc9e, // use_waypoint_recording_as_assisted_movement_route
0x7b7723747ccb55b6, 0x7230608484c92cfd, // _set_mp_gamer_tag_chatting
0xb35ce999e8ef317e, 0x576e0f1c74222fa3,
0xeb709a36958abe0d, 0x67c88e5b2abc7821, // _has_mp_gamer_tag_2
0x83a2ca4f2e573bd, 0xbe3b6483c2f0ae2f, // draw_debug_box
0x2047c02158d6405a, 0x24bcd8432fe6af77, // task_sweep_aim_entity
0x7e6946f68a38b74f, 0x6df02bf3f3ec27cc, // _0x7e6946f68a38b74f
0x2bf72ad5b41aa739, 0xe8cf5d413068e5ad,
0x16350528f93024b3, 0xa17b82621af7ab96, // remove_anim_set
0x81a15811460fab3a, 0x2d0fa45744c7540c, // request_vehicle_asset
0x9bae5ad2508df078, 0x70d75eb248087ae6, // _use_freemode_map_behavior
0x41f37c3427c75ae0, 0x7749193af003dc67, // refresh_interior
0x50c1b2874e50c114, 0xe5a11c0e6843a071, // _array_value_get_boolean
0x60bf608f1b8cd1b6, 0x40dfa7aaefc8f34c, // set_vehicle_livery
0xabc54de641dc0fc, 0xe6db95b79660d144, // _0x0abc54de641dc0fc
0x17008ccdad48503, 0x6985fc3098cca0eb, // get_time_offset
0x65faee425de637b0, 0x13d6cceb21406fd6, // _0x65faee425de637b0
0xd10f442036302d50, 0xea054cd9c165e128, // _0xd10f442036302d50
0x464d8e1427156fe4, 0x7d212a857aea88ca, // remove_door_from_system
0x8d74e26f54b4e5c3, 0x552edd983d22f0d5, // _0x8d74e26f54b4e5c3
0xf745b37630df176b, 0x432bbeff2af18f4, // force_cleanup_for_thread_with_this_id
0xbb03c38dd3fb7ffd, 0xbbb04df002bab732, // set_ped_as_cop
0x52b4829281364649, 0xd4b7989f7213f509, // delete_rope
0x9f343285a00b4bb6, 0x775925f8b8d6987, // set_auto_give_parachute_when_enter_plane
// 0x3cdc7136613284bd, 0x0, // register_world_point_script_brain
0x98cd1d2934b76cc1, 0x98be89bcf95de25b, // get_zone_from_name_id
0x772282ebeb95e682, 0xdd046da6fc945353, // fix_vehicle_window
0x40fce03e50e8dbe8, 0xf81b05c34b7e1d24, // _network_access_tunable_int_hash
// 0x1a330d297aac6bc1, 0x0, // _0x1a330d297aac6bc1
0x473151ebc762c6da, 0x56214633b95ff606,
0x661b5c8654add825, 0xf1ba00ced5460724, // _0x661b5c8654add825
0xc1f981a6f74f0c23, 0xbcb9a5d31a59a144, // _0xc1f981a6f74f0c23
0xedf7f927136c224b, 0x211b2cd54aecd495,
0x5d5caff661ddf6fc, 0x47f9b535e50ae911, // _0x5d5caff661ddf6fc
0xdfe8422b3b94e688, 0x7ced302277c0f3d3, // stop_audio_scene
0xad7e85fc227197c4, 0xc4fbef9b5d49046d, // get_vehicle_max_braking
0x433083750c5e064a, 0xa9e472293522522f, // set_ped_max_move_blend_ratio
0x7bbb1b54583ed410, 0x6668a708a3da7fb4, // stat_set_masked_int
0xfddc2b4ed3c69df0, 0x7c1fffbccf6db76c, // draw_tv_channel
0x1bbc135a4d25edde, 0xca39f350ba0a4fd5, // _0x1bbc135a4d25edde
// 0x96dec8d5430208b7, 0x0, // display_cash
0x6c34f1208b8923fd, 0xbdfcb927bb230a99, // _0x6c34f1208b8923fd
0xf4080490adc51c6f, 0x76b710d4ee37f82d, // process_entity_attachments
0x85f061da64ed2f67, 0x201339347519b9a8, // _end_text_command_get_width
// 0xe902ef951dce178f, 0x0, // get_player_rgb_colour
0xee01041d559983ea, 0x798b28a324675954, // set_ped_non_creation_area
0xf3b4d4e43177236, 0x6cc701b3d3b3492f, // _0x0f3b4d4e43177236
0x2fb19228983e832c, 0xa3d6a4accd4c7cbd, // leaderboards_read_successful
0x3523634255fc3318, 0xf0502d0584ccd9a6, // _play_ambient_speech_with_voice
0xeaabe8fdfa21274c, 0x4bf7869dae52ca15, // remove_all_shocking_events
0x157f93b036700462, 0xe35413546dc97620,
0x85deb493be80812, 0xae622e94466f4ace, // get_wanted_level_radius
0xa4efef9440a5b0ef, 0x930fe0cf611a60c5, // set_ped_ammo_to_drop
0xdc0f817884cdd856, 0xa53c1c92ee35ec0e, // enable_dispatch_service
0x5d517b27cf6ecd04, 0x852f5b36d5c7b363, // _0x5d517b27cf6ecd04
0x923dbf87dff735e, 0x34b15a9ee78403af, // _0x0923dbf87dff735e
0x8e0a582209a62695, 0xb8a3ac2a7b2465fd, // _set_vehicle_neon_lights_colour
0x521fb041d93dd0e4, 0x611ea72f39aad0dd, // _begin_text_command_line_count
0x4d02279c83be69fe, 0xdf1751fbd3e86b1a,
0xf814fec6a19fd6e0, 0xc9f6b087c55fc882,
0x1c4fc5752bcd8e48, 0xbe11fe74c8564168, // _0x1c4fc5752bcd8e48
0xc86d67d52a707cf8, 0x91bbd269506d61d2, // has_entity_been_damaged_by_entity
0x90a78ecaa4e78453, 0xf03a158be322efc5,
// 0x94538037ee44f5cf, 0x0, // _0x94538037ee44f5cf
0xe50384acc2c3db74, 0x62d28a6e47cc0f1f, // stat_get_string
0x2e2f4240b3f24647, 0xff29bda0b69ffaad, // set_ped_can_teleport_to_group_leader
0xd5bb406f4e04019f, 0xc26015b3b45b6cb5, // network_spent_no_cops
0x4859f1fc66a6278e, 0x71e0daa57fe7d5c7, // is_ped_in_combat
0x9de986fc9a87c474, 0xb4b29c6a8f481eea, // _network_is_player_equal_to_index
0x521638ada1ba0d18, 0xa43ac7614785d952, // network_apply_transition_parameter
0x1abce5e7cbda196, 0x24597b8ac553317f,
0xe023e8ac4ef7c117, 0x3867c4e23df607fe, // set_all_vehicles_spawn
0x70894bd0915c5bca, 0x990a2ab123fb5a99, // _0x70894bd0915c5bca
0xbe339365c863bd36, 0xcb795f691042d011, // add_blip_for_pickup
// 0x845ffc3a4feefa3e, 0x0,
0x3a214f2ec889b100, 0x53b80e3cfac2263f, // network_send_text_message
0x7619eee8c886757f, 0x425e187882f60326, // _get_vehicle_neon_lights_colour
0xc0aa53f866b3134d, 0x37ebf3e69b6d5122,
0x8aa464d4e0f6accd, 0x56b3d04da2352120,
0xed7f7efe9fabf340, 0x8a5f86362e03852b, // set_ped_can_switch_weapon
0xec6a202ee4960385, 0x3b1040723141568e, // set_vehicle_tyre_burst
// 0x685d5561680d088b, 0x0, // _0x685d5561680d088b
0xe3dd5f2a84b42281, 0x8069bbc84d092e17, // get_ped_palette_variation
0x5443438f033e29c3, 0x98c1605c20b2e0b9, // request_weapon_asset
0xefb55e7c25d3b3be, 0x709df5afe1cee908,
0x10d373323e5b9c0d, 0x3fe7249c0944db7b,
0x639b642facbe4edd, 0x2980ae5189b151e9, // set_task_vehicle_chase_ideal_pursuit_distance
// 0x5dc577201723960a, 0x0,
0x8290252fff36acb5, 0xe82ec3b1e15706f, // _0x8290252fff36acb5
0x80c2fd58d720c801, 0xf745ca12dc8836eb, // _0x80c2fd58d720c801
0x1374abb7c15bab92, 0x8bba6285e98709a6, // is_shocking_event_in_sphere
0xc95eb1db6e92113d, 0xbd1d0c5c03336a1f, // _start_networked_particle_fx_non_looped_on_entity
0xf0f77adb9f67e79d, 0x6c800f8d745d8088, // _unk_get_interior_at_coords
0x25d39b935a038a26, 0xdb4c79a9697e6a55, // is_synchronized_scene_running
0x67f6413d3220e18d, 0xa9e1e457b41d498b, // _0x67f6413d3220e18d
0xeea929141f699854, 0x8798cbf817ba887, // task_synchronized_scene
0x9d277b76d1d12222, 0xf8164c2295bd8280, // network_set_activity_spectator_max
0x2975c866e6713290, 0xdfd0acb809ad97c9, // get_entity_player_is_free_aiming_at
0xb8e181e559464527, 0x830b1d24ed3d5f55, // is_vehicle_door_damaged
0xfcd5c8e06e502f5a, 0x6e6eb18fdab9a074, // add_navmesh_blocking_object
0xc514825c507e3736, 0xfbbcb6f723d0a44a, // set_ped_can_peek_in_cover
// 0xf9c812cd7c46e817, 0x0, // network_refund_cash
0x1de37bbf9e9cc14a, 0x9c13a903ffbea446, // set_player_may_not_enter_any_vehicle
0xd75accf5e0fb5367, 0x92a2fafa76b7ec9b, // set_ped_using_action_mode
// 0x5702b917b99db1cd, 0x0, // _0x5702b917b99db1cd
0x2a7819605465fbce, 0x90b04b8897fc7460, // set_ped_as_group_leader
0x2202a3f42c8e5f79, 0x741e4eda851c8e52,
0xa794a5a57f8df91, 0xb969b7304d29679f, // get_entity_forward_vector
0xdace1be37d88af67, 0x17a17144af24c360, // set_drive_task_driving_style
0x27feb5254759cde3, 0x8260afc98d0d6cac, // _0x27feb5254759cde3
0x33a8f7f7d5f7f33c, 0x5f9955d3e93bcc84, // set_ped_hearing_range
0x9dc711bc69c548df, 0x941b4c548836797d, // terminate_all_scripts_with_this_name
// 0x9769f811d1785b03, 0x0, // _network_respawn_coords
0xaa08ef13f341c8fc, 0xde17a10bae2b2af6, // remove_weapon_asset
0x5b0316762afd4a64, 0x7a1370ffc0fc2567,
0x3e200c2bcf4164eb, 0x7eb82d55ab02865c, // _network_set_rich_presence_2
0x4862437a486f91b0, 0xe25139693ecaf448, // _0x4862437a486f91b0
0x40addcbafa1018a, 0x7c27680e399f6e69, // _sc_inbox_get_emails
0xa670b3662faffbd0, 0x254d3936da813a55, // network_request_control_of_network_id
// 0x109e99373f290687, 0x0, // update_navmesh_blocking_object
0x639431e895b9aa57, 0x782b99db55846c95, // _0x639431e895b9aa57
0x26324f33423f3cc3, 0x1cd56b54c956ef0b, // set_far_draw_vehicles
0x6b17c62c9635d2dc, 0xffaa917d84ba05ab, // start_script_conversation
0x7fcc39c46c3c03bd, 0x5aa1974cc79b10c3, // _0x7fcc39c46c3c03bd
0x1072f115dab0717e, 0xfabf46f0b9c98e4, // _0x1072f115dab0717e
0x57a995fd75d37f56, 0xb62afa96bef8e80a, // _array_value_add_float
0xbdcd95fc216a8b3e, 0xbb28786b7f552d0b, // net_to_ped
// 0xd009f759a723db1b, 0x0, // rope_force_length
0x8483e98e8b888ae2, 0xca784dd79b619ef2, // get_best_ped_weapon
0x289016ec778d60e0, 0x397e507bbf2cc708, // network_spent_cash_drop
0xea61ca8e80f09e4d, 0x8199bde44626cbf8, // get_rope_vertex_coord
0xd2c5aa0c0e8d0f1e, 0x2da006dbe79ed638, // set_enable_ped_enveff_scale
0x9def883114668116, 0x4ee7b001b335c831, // create_script_vehicle_generator
0x1821d91ad4b56108, 0x2a4c0027d3a9cfe5, // does_cargobob_have_pick_up_rope
0x4f5212c7ad880df8, 0xfbdf325a70ecddfc, // add_petrol_decal
0x7808619f31ff22db, 0x78c297cce2e788f9,
0x9d3151a373974804, 0xaf4482b584bbf3b8, // set_ped_sphere_defensive_area
0xf2e07819ef1a5289, 0x1c1a39b8013afa3f,
0x69240733738c19a0, 0xaf230c81e4013dcc,
0x31e11f3d447647e, 0xba29d5a53f3f8776, // network_is_player_talking
0xe95b0c7d5ba3b96b, 0x3fea8964af2c6948, // _0xe95b0c7d5ba3b96b
0xe54e209c35ffa18d, 0xc5c0303b0cff698, // is_point_obscured_by_a_mission_entity
0xd8f66a3a60c62153, 0x5487531db7da4ab5, // get_event_at_index
0x43feb945ee7f85b8, 0x6be952d89596ed03, // set_vehicle_mod_color_1
0x9040dfb09be75706, 0x767f5e4858e200eb, // _get_text_screen_line_count
0x15c86013127ce63f, 0xddffe9b31c0f258d, // task_boat_mission
0x3353d13f09307691, 0x49f527afadc7c0c0,
0xb1632e9a5f988d11, 0x47904e0914f5b5c6, // is_entity_attached_to_any_ped
0x43a66c31c68491c0, 0x378bd4b3881338c2, // get_player_ped
0xa0948ab42d7ba0de, 0x57d74362a8bd1490, // is_this_model_a_plane
0x7cf0448787b23758, 0x4fd6b1ac6e5ba4bd, // _get_content_description_hash
0x6a071245eb0d1882, 0x3c0f6044c54799a8, // task_go_to_entity
0x3903e216620488e8, 0x635cfe8f0e30dbaf, // draw_debug_text
0xfe02ffbed8ca9d99, 0xbe799439b122ca21, // request_ambient_audio_bank
0xb2c086cc1bf8f2bf, 0x6350c38edfd771ae, // is_ped_doing_driveby
0x22ef8ff8778030eb, 0x42e0c09f4bdf7390, // reset_ped_in_vehicle_context
0x687c0b594907d2e8, 0x7e75faea39c78c8e, // _0x687c0b594907d2e8
0xb5d7b26b45720e05, 0x44befffa3090b41c, // get_ideal_player_switch_type
0x4ba4e2553afedc2c, 0x50a5f05f60f8ed23, // get_blip_info_id_entity_index
0x74556e1420867eca, 0x990c71dd454c342f,
0xc0f97fce55094987, 0x576f51c1b491c31f, // is_vehicle_searchlight_on
0x7eec7e4f6984a16a, 0x31c783807ad338e7, // leaderboards2_read_by_score_int
0x48adc8a773564670, 0x818901b332d5541d,
0xc7622c0d36b2fda8, 0x52f5aaad4824b17e, // set_ped_combat_ability
// 0xbce595371a5fbaaf, 0x0, // _0xbce595371a5fbaaf
// 0x80054d7fcc70eec6, 0x0, // _0x80054d7fcc70eec6
0x7c6b0c22f9f40bbe, 0x35412823bbdf596c, // does_group_exist
0xc8e1071177a23be5, 0x70cdc0fe15fc6de2, // _0xc8e1071177a23be5
0xedb1232c5beae62f, 0x50db19661b7f2ccd, // register_text_label_to_save
0xf5a2c681787e579d, 0x4602263dc4a45e9, // _screen_draw_position_ratio
0x90d0622866e80445, 0x61f880f5a56792de, // playstats_quickfix_tool
0xb6997a7eb3f5c8c0, 0x8918ec905fc8975d,
// 0x23428fc53c60919c, 0x0, // disable_plane_aileron
0x9cfa4896c3a53cbb, 0xfe8019b3b424a189, // _set_bike_lean_angle
0x53952fd2baa19f17, 0xab5dccb91a88fd44, // _get_vehicle_suspension_height
0xbe22b26dd764c040, 0xf666cbf66a90975a, // get_anim_initial_offset_position
0xb138aab8a70d3c69, 0x29958b7eaa626220, // play_mission_complete_audio
0xa34cb6e6f0df4a0b, 0xcc097d60ad955e7e,
0xc6dc823253fbb366, 0x6a89a288a6eee36f,
0xa02e59562d711006, 0x7da7ed16b8787019, // network_session_end
0x7bf835bb9e2698c8, 0x77631bbb824df500, // task_combat_hated_targets_around_ped
0xb9bb18e2c40142ed, 0x439924b76ff96c1c, // leaderboards_cache_data_row
0xae4086104e067b1, 0x1636387c425efec6, // task_jump
0x6fddad856e36988a, 0xeebd730a0b9fd4b3, // _0x6fddad856e36988a
// 0xc90621d8a0ceecf2, 0x0, // is_cam_playing_anim
0x2b16a3bff1fbce49, 0xd09a1c8b934d92c9, // _is_ped_prop_valid
0xa3bb2e9555c05a8f, 0xcfba20230d6cdb6c, // draw_debug_text_2d
0xc6941b4a3a8fbbb9, 0x7c94b9cea026daff, // _play_ambient_speech2
0xa8ae43aec1a61314, 0xb74c1e760d44362,
0x92aefb5f6e294023, 0x861c6d8520e774ea, // _0x92aefb5f6e294023
0x7a86743f475d9e09, 0x3427206e004f448f, // request_cutscene
0xd972e4bd7aeb235f, 0x1b070f5104998ec6,
0x52f357a30698bcce, 0x8d9fd90a001d447c, // is_vehicle_a_convertible
// 0xf90125f1f79ecdf8, 0x0, // generate_directions_to_coord
0x648ee3e7f38877dd, 0xecfdab0882ff01af, // is_control_released
0x4215460b9b8b7fa0, 0x7b30760c871c12b3, // get_weapontype_slot
0x632a689bf42301b1, 0x867b6357bd17a8e5, // pause_playback_recorded_vehicle
0x950a154b8dab6185, 0x65e4765895b11589, // _set_synchronized_audio_event_position_this_frame
0xe05dd0e9707003a3, 0x9ec7265a9a5fa0e1, // _0xe05dd0e9707003a3
0x7ddab28d31fac363, 0x1c09cdaeb97f6354, // set_player_has_reserve_parachute
0x2720aaa75001e094, 0xbb5a94d71ceaa8d5, // get_ped_waypoint_progress
0x5ee2caff7f17770d, 0x3f764a23379472a8,
0x4c4d6b2644f458cb, 0xe8fde8c0e616a4c,
0xe7ffae5ebf23d890, 0x281206a3ed9b7b48, // draw_sprite
0x8b9f1fc6ae8166c0, 0x780bdd5b33015616, // get_ped_parachute_landing_type
0x808519373fd336a3, 0x9b7ff82f64826a40, // _set_director_mode
0x3f892caf67444ae7, 0x3a59853e7da8a5d8, // create_incident
0x769951e2455e2eb5, 0x7e51f258e3af30e,
// 0x6cc86e78358d5119, 0x0,
0xa6eb355ee14a2db, 0x6bd09afa46a11ca2, // are_player_stars_greyed_out
// 0x20ae33f3ac9c0033, 0x0, // make_ped_reload
0x5b9e023dc6ebedc0, 0xe8778e463e163071, // network_clan_download_membership_pending
0xf0077c797f66a355, 0x68642a60a49b0d2b, // network_buy_item
0x225798743970412b, 0x4c2d3d8c1cb4cb7c, // _0x225798743970412b
0x595b5178e412e199, 0x855f0610b8e14a7d, // add_trevor_random_modifier
0xdc20483cd3dd5201, 0x324d31b9334512e4, // set_gps_disabled_zone
0x59b9a7af4c95133c, 0xacb9c7db658ad99b,
0x234cdd44d996fd9a, 0x72b053d2059bdeaf, // set_blip_category
0xf4924635a19eb37d, 0xf0e2d155b834e176, // set_vehicle_siren
0xe12abe5e3a389a6c, 0x81dc8d98ef02df21, // _0xe12abe5e3a389a6c
0xb8feaeebcc127425, 0x95872cd818b1f57b, // remove_particle_fx_from_entity
0xeb3dac2c86001e5e, 0x765f6feeff39224f,
0x162f9d995753dc19, 0x8422ce67c0a53728,
0xf87683cdf73c3f6e, 0x9d148e7c7c25619b, // set_blip_rotation
0x262b14f48d29de80, 0x93aa93da1b137032, // set_ped_component_variation
0xf14878fc50bec6ee, 0xedf90b96bed57bce, // using_mission_creator
0x6087579e7aa85a9, 0x53ad50a74c299d11, // _0x06087579e7aa85a9
0x5f0c4b5b1c393be2, 0x15b6c143ec14bc55, // set_particle_fx_looped_evolution
0xc19a2925c34d2231, 0x708aaa79d977b46e, // playstats_mission_started
0xee4c0e6dbc6f2c6f, 0xa307370d89ea8c3,
0xb8dfd30d6973e135, 0xc4dea49c5b465481, // network_is_player_active
0x240a18690ae96513, 0x8e241517f0f541cc, // get_closest_vehicle_node
// 0xd4c4642cb7f50b5d, 0x0, // _0xd4c4642cb7f50b5d
0x9c14d30395a51a3c, 0x9dba3a488272c02a, // get_ped_enveff_scale
0x6e04f06094c87047, 0x203920eeee51069,
0xf7f203e31f96f6a1, 0x921cf90e06d53d3a, // _0xf7f203e31f96f6a1
0xc4e2813898c97a4b, 0x12555678f362d43b,
0xcd9cc7e200a52a6f, 0x420c13af06ea9dd9, // _dispose_synchronized_scene
0xab8e2eda0c0a5883, 0xa34c4fa4a49499a6, // skip_to_end_and_stop_playback_recorded_vehicle
0x5eaad83f8cfb4575, 0xab9272adfa3a9a6f, // _get_pickup_hash
0x3c7d42d58f770b54, 0x44c3e7deb0315cd4, // attach_vehicle_to_trailer
0x605f5a140f202491, 0x45ad2119a5b580cd, // has_entity_been_damaged_by_any_ped
0x4167efe0527d706e, 0x2029bc14bf024a9a,
0xf49e9a9716a04595, 0x15e8af8fbc9d0461, // _draw_light_with_range_and_shadow
0xa6a12939f16d85be, 0xfb3eafbc80ea7108, // _remove_stealth_kill
0x7c0a893088881d57, 0x15661f4ac08d433a,
0x86a652570e5f25dd, 0x1abdb383c83a336a, // remove_blip
0x79df7e806202ce01, 0xf563d0e25f1ea9ca, // _0x79df7e806202ce01
0xe37f721824571784, 0x3526e52020554e2f, // apply_impulse_to_cloth
0x63145d9c883a1a70, 0x1c500bb2e1897008, // set_text_wrap
0x8f993d26e0ca5e8e, 0xf550b7a8c2414c42, // _clamp_gameplay_cam_yaw
0x584770794d758c18, 0x3a2c98b06c4b0cad, // _0x584770794d758c18
0xce4ac0439f607045, 0xe0f832975f97a409,
0xcb9e1eb3be2af4e9, 0x53799d1caee0aab6, // set_vehicle_population_budget
0xaa51db313c010a7e, 0x4d83376a9df61f92, // set_blip_flash_interval
0xed3c76adfa6d07c4, 0x64f9fbe07cd1bce7, // _0xed3c76adfa6d07c4
0xcb0360efefb2580d, 0x225be5dd50283db0, // _0xcb0360efefb2580d
0xf154b8d1775b2dec, 0xdcb4ef3d1d19c4a4, // _0xf154b8d1775b2dec
0x1b9c0099cb942ac6, 0xe3040995362df6f7, // set_veh_radio_station
0x2c29bfb64f4fcbe4, 0x58e0e69f288a09e5, // stat_set_date
0x5063f92f07c2a316, 0xa4e619ad5b2a5668,
0xc33ab876a77f8164, 0x730fac2c24a116ec, // get_closest_ped
// 0xaad6d1acf08f4612, 0x0, // set_ped_pinned_down
0x7e2bd3ef6c205f09, 0x282034b93623bd9b, // _0x7e2bd3ef6c205f09
0xf5bc95857bd6d512, 0xbff0a910cb522774, // is_time_equal_to
0x4d982adb1978442d, 0xdb36a8f522cbc12d,
0xdf735600a4696daf, 0xa20c1de21f2f071c, // set_blip_sprite
0xdd2238f57b977751, 0x6a179b2a6e1e9cf8, // _0xdd2238f57b977751
0x50c7a99057a69748, 0xf7f6d188b25b7774, // get_local_time
0xbbcce00b381f8482, 0xd82cbcb7e04dda8a, // is_ped_fleeing
0xeb2d525b57f42b40, 0x818d1850be9e44a9,
0x36391f397731595d, 0xeddfb29174c308e3, // _0x36391f397731595d
0xae9fc9ef6a9fac79, 0xc51c58c963968740, // set_blip_priority
0x40c8656edaedd569, 0x66d6584f4e8c88ae,
0x8d2064e5b64a628a, 0xcd49aafb14f7860f, // _array_value_get_vector3
0x62522002e0c391ba, 0xdbebbe1f686e24ce, // is_synchronized_scene_looped
0xcef214315d276fd1, 0x2719a9ba43ae91c0, // _0xcef214315d276fd1
0x70ea8da57840f9be, 0x28dbc1b6ca612640, // _0x70ea8da57840f9be
0x7fd8f3be76f89422, 0xb2b786ac5c8c12a2, // add_shocking_event_for_entity
0x85796b0549dde156, 0xf77da7509e2742b9, // roll_down_windows
0x4a04de7cab2739a1, 0xf2fd56cca8bcb2ca, // set_vehicle_boost_active
0x742a637471bcecd9, 0x74e9d455686e1f3a, // network_add_ped_to_synchronised_scene
0x29b487c359e19889, 0x40ffed488ebe4055, // set_weather_type_now
0x80fe4f3ab4e1b62a, 0xa74ba5097e96a86f,
0xb1d200fe26aef3cb, 0xfa411175f279dc8c, // is_special_ability_enabled
0x11315ab3385b8ac0, 0x46f8a470fadaf002, // task_go_to_coord_while_aiming_at_coord
0xc52e0f855c58fc2e, 0x7968a636975affe2, // set_enable_bound_ankles
0xa3c0b359dcb848b6, 0x4419594f3933b31b, // show_number_on_blip
0x1f25887f3c104278, 0x6b385375ee24c167, // is_vehicle_high_detail
0xf4cc924cf8c7b21, 0xdd09a2eec51e6b61, // clear_player_parachute_variation_override
0xbef34b1d9624d5dd, 0x2dc5d56a3b5e69bb, // _0xbef34b1d9624d5dd
0xd51adcd2d8bc0fb3, 0xab2eab7dc12ec718, // set_gameplay_coord_hint
0x121f0593e0a431d7, 0x12cb839f3e3865f6, // vehicle_waypoint_playback_override_speed
0x39ff19c64ef7da5b, 0x98f04a4ffb4ad01c, // set_player_wanted_level
0x2eaf1fdb2fb55698, 0x6c389ed9c5a7e7d, // create_portable_pickup
0xee82280ab767b690, 0xcb68f86e41ce5197,
0xa41540e63c9ee17, 0xbad56a0e8bd109f2,
0xcf537fde4fbd4ce5, 0x3561e7bc11996636, // draw_scaleform_movie_fullscreen_masked
0x831e0242595560df, 0x582a50cde1f806ae, // get_entity_roll
0x9d3af56e94c9ae98, 0xca6505b7a2f46301, // _0x9d3af56e94c9ae98
0xd4b02a6b476e1fdc, 0x1b50498c6381aafb,
0xec5f66e459af3bb2, 0x7eabaa6f963bc011, // is_ped_on_specific_vehicle
0x1ca3e9eac9d93e5e, 0x90d5b6657dbfb5d,
0x827a5ba1a44aca6d, 0xab02cf5820cdce16, // network_earn_from_betting
0xd6a953c6d1492057, 0x111ae40e9c93af52, // special_ability_deactivate
// 0x42b2daa6b596f5f8, 0x0, // network_get_entity_killer_of_player
0x5ee02954a14c69db, 0xcb25f217d36bc6f2, // task_use_mobile_phone_timed
0x69fe6dc87bd2a5e9, 0x262dbf8f5206e1b0, // add_replay_stat_value
0xec92a1bf0857187, 0x3f8bc1240e6dcc1a,
0x203f1cfd823b27a4, 0x7497483d6c218cca,
0x36ced73bfed89754, 0x5aa2c10bc3876e75, // set_vehicle_custom_secondary_colour
0xf7b79a50b905a30d, 0x656bb209ffcee74a, // _0xf7b79a50b905a30d
0xa3d0e54541d9a5e5, 0x999972871f1f387, // set_player_parachute_tint_index
0xa69ac4ade82b57a4, 0x40795ade6f9eceae, // _0xa69ac4ade82b57a4
0x72433699b4e6dd64, 0xe7f1edb7bffb7f41,
0x1162ea8ae9d24eea, 0x9b5aabc3a6509350, // override_save_house
0xaa0bc91be0b796e3, 0x3231f10fd5ae3045, // set_train_speed
// 0xcdca26e80faecb8f, 0x0,
0xc50aa39a577af886, 0x614ee52a69097a4c,
0xc080ff658b2e41da, 0x80f2d264f646d35f, // network_get_primary_clan_data_new
0x295e3ccec879ccd7, 0x9ceb33f9f7fa9fe7, // ped_has_use_scenario_task
0x684a41975f077262, 0x56cfe3d20d862787,
0xb7c7f6ad6424304b, 0x253da8f31d78b6cd,
0xa8434f1dff41d6e7, 0x712df39a90f7cb61, // _0xa8434f1dff41d6e7
0xbc0ce682d4d05650, 0x6eb0c28713d672df, // _0xbc0ce682d4d05650
0x4a3dc7eccc321032, 0x8fbea7341c8ca3c5, // set_player_melee_weapon_damage_modifier
0x7e9dfe24ac1e58ef, 0xe5472b649a9e9734, // is_ped_shooting_in_area
0x5f7b268d15ba0739, 0x9319d64277459d29, // get_zone_scumminess
0xebb376779a760aa8, 0xd33dac8d0d70a78c,
0xf284ac67940c6812, 0x9e6bfbc79721fa29,
0x75d3f7a1b0d9b145, 0x58293d0a6a67a67f, // get_player_parachute_tint_index
0xf87d9f2301f7d206, 0x1598800af65ce4a5, // _0xf87d9f2301f7d206
0x4700a416e8324ef3, 0x194c9cd81c97b65b, // get_ped_max_health
0x2b486269acd548d3, 0x9eff450f614b201f, // set_gameplay_ped_hint
0xecb2fc7235a7d137, 0x894797e49cf22aa4, // get_entity_matrix
0x3cf48f6f96e749dc, 0xe24cccfcaa2ffac0, // set_cam_dof_planes
0xb2ebe8cbc58b90e9, 0x69f7b2df5fec36b0,
0x31698aa80e0223f8, 0x73edf34261c88b3c, // remove_mp_gamer_tag
0x92bac8acf88cec26, 0xd4d8fdf28013b971, // is_interior_capped
0xf2385935bffd4d92, 0x11d8f46c0e27fd41, // _0xf2385935bffd4d92
0xd78de0572d3969e, 0xcd8e89ebebd0a7a6, // is_ped_weapon_component_active
0x9f6e2821885caee2, 0x313b4d801832c286, // _0x9f6e2821885caee2
0xb7b0870eb531d08d, 0xd219e3573ca7427c, // special_ability_charge_absolute
0x5c8b2f450ee4328e, 0xf4029392e5d99302, // set_player_lockon
0x2057ef813397a772, 0x9ae6d6614c74407f, // get_ped_ragdoll_bone_index
0x27e32866e9a5c416, 0x198691468b824449, // _0x27e32866e9a5c416
0x3c8938d7d872211e, 0xe1b1b40a2910de2a,
// 0xcfd115b373c0df63, 0x0, // _0xcfd115b373c0df63
0x2e8aabfa40a84f8c, 0x20eed14fdeb7e36f, // set_disable_ambient_melee_move
0x16a304e6cb2bfab9, 0x6105a3cf3a0c0d88, // _0x16a304e6cb2bfab9
0xb3b1cb349ff9c75d, 0x372be95200dc93dd, // set_can_attack_friendly
0xbcf3026912a8647d, 0xb3a9fe72cfb2c51, // detach_rope_from_entity
0x170f541e1cadd1de, 0xa327c625224b4751, // _update_display_cash
0xf99f62004024d506, 0x907bea38455f5afe, // set_enable_scuba
0x4ae4ff911dfb61da, 0x85941c2a0e1abaf, // is_ped_jacking
0x68f64f2470f9656, 0x9650821087024d0f, // _set_vehicle_creates_money_pickups_when_exploded
0xa55547801eb331fc, 0x835fa169b1854514, // task_go_to_coord_and_aim_at_hated_entities_near_coord
0xe825f6b6cea7671d, 0x8b22cceb433f9c0f, // is_ped_component_variation_valid
0xd9efb6dbf7daaea3, 0x8212d7cc9733976c, // does_pickup_object_exist
0xf145f3be2efa9a3b, 0x9bb410ae40820b7a, // special_ability_unlock
0xdcca191df9980fd7, 0xe7a1e8f9e47de4a7, // _0xdcca191df9980fd7
0x7085228842b13a67, 0x47cd6ba404aee035, // is_pedheadshot_ready
0xe1c8709406f2c41c, 0xe9adafb29c5fa8cc,
0xec52c631a1831c03, 0x80e9fdf34770fa5c, // _0xec52c631a1831c03
0xe532ec1a63231b4f, 0x5e7ee95e1a259ad0, // _0xe532ec1a63231b4f
0x3fa36981311fa4ff, 0xc9d187021b6ef97a, // _0x3fa36981311fa4ff
0xbf1ca77833e58f2c, 0x78977e4c762868b0, // set_ped_can_be_targetted_by_team
0xbbb6ad006f1bbea3, 0xbee1320493f1883f,
0x125494b98a21aaf7, 0xa8320294a1b70c7e, // _create_portable_pickup_2
0xef26739bcd9907d5, 0x168107336918849c, // network_set_transition_creator_handle
0xdfb4138eefed7b81, 0x2aad009ec638eff7, // _get_projectile_near_ped_coords
0xad9710cee2f590f, 0xb66ab39ba5554305, // _0x0ad9710cee2f590f
// 0x2b4cdca6f07ff3da, 0x0, // _get_ngstat_int_hash
// 0x538d1179ec1aa9a9, 0x0, // start_rope_unwinding_front
0x78f0424c34306220, 0xaa4303e9d3d18d9e, // add_ammo_to_ped
0x551df99658db6ee8, 0x9739b0da6cc6989e, // _0x551df99658db6ee8
0xb4c94523f023419c, 0xa0edffb6cf5b314a, // veh_to_net
0x85a0ef54a500882c, 0x15cf1d9ab7f07743, // _0x85a0ef54a500882c
0xf6aa118530443fd2, 0xf152e000caf1ffff, // get_ped_alertness
0xcf2b696bbf945ae, 0x86cf3d110e5dd82f,
0xb25dc90bad56ca42, 0x8c12d452eeb914c9, // destroy_tracked_point
0xa8fdb297a8d25fba, 0x9f86aef7dc996029,
0x125bf4abfc536b09, 0x7b78a3dd8b3a8825, // is_point_on_road
0xaa74ec0cb0aaea2c, 0xeb5f94c785667633, // reset_ped_movement_clipset
0xbf09786a7fcab582, 0xdfa417de0d1c56bc, // _0xbf09786a7fcab582
0xadf692b254977c0c, 0x274c6068b660ffb4, // set_current_ped_weapon
0x8f5fb35d7e88fc70, 0x72b72ea288b11371, // raise_convertible_roof
0x7f4724035fdca1dd, 0x636ceda67977f07b, // _disable_input_group
0xa551be18c11a476d, 0x22fcd51b2821faff, // get_num_mod_colors
0xbfba3ba79cff7ebf, 0xaa201d57c44ffd3e, // _get_vehicle_model_hand_brake
0xd422fcc5f239a915, 0xeb62162d7ca7a4f4,
0x62d2916f56b9cd2d, 0xebdf932af07b55e2, // task_reload_weapon
0x2f0661c155aeeeaa, 0xc63fda82c66f1586, // _array_value_add_string
0x92523b76657a517d, 0x59e2c528a2675e72, // _0x92523b76657a517d
0xe65f427eb70ab1ed, 0xe9739440e5bf08ee, // play_sound_from_entity
0x2e1202248937775c, 0x26f707411c9db494, // get_ammo_in_clip
0x126ef75f1e17abe5, 0x1bbd70cd44b140d9, // task_scripted_animation
0x459fd2c8d0ab78bc, 0x5e20a87157588563,
0x59c16b79f53b3712, 0x37fcf2584ca47927, // load_stream_with_start_offset
0xfd8b834a8ba05048, 0x33532d1e20d7b54,
0xf2404d68cbc855fa, 0x3f0e98c9b9f44619, // network_add_entity_to_synchronised_scene
0x5b50abb1fe3746f4, 0x6ca72695a7de9e7,
0xa50e117cddf82f0c, 0xcfbbce2db19e1ca, // set_player_vehicle_damage_modifier
0xd00d76a7dfc9d852, 0x73844469ceb80ac8, // _0xd00d76a7dfc9d852
0x129466ed55140f8d, 0xba6145f0b26fef64, // _0x129466ed55140f8d
0xc2b82527ca77053e, 0xfec7d116b114088b,
0xb1906895227793f3, 0xeeb2427ae1e5830b, // set_player_targeting_mode
0xe1b13771a843c4f6, 0xae44886de0f3d443, // network_spent_buy_wantedlevel
0xafce529f69b21ff, 0xbf1e78444ad02a1,
0x53e0df1a2a3cf0ca, 0x838d66b8389ccabc, // set_team_pickup_object
0xfe26117a5841b2ff, 0x2ebf31f210b945f6, // _0xfe26117a5841b2ff
0xb195ffa8042fc5c3, 0xd5cfe7123dce05f, // set_driver_ability
0x89c8553dd3274aae, 0x3d60be5b65e8e43d, // _reset_particle_fx_asset_old_to_new
0x5c707a667df8b9fa, 0xd3a3d1e69ff89144, // _0x5c707a667df8b9fa
0xc7be335216b5ec7c, 0x264126c43e0aafd,
0x338e7ef52b6095a9, 0x1579d77e267228a1, // task_goto_entity_offset_xy
0xd220bdd222ac4a1e, 0x52886aee858a2180,
0xc6017f6a6cdfa694, 0xc5d35f50889a4332, // is_special_ability_unlocked
0x58cc181719256197, 0xbe67bf4ef46767f9, // _0x58cc181719256197
0x7f8f65877f88783b, 0xea3abfee23d6171c, // set_particle_fx_looped_colour
0x9cb0bfa7a9342c3d, 0xa09c701976529464, // _0x9cb0bfa7a9342c3d
0xc5a80a9e096d529, 0xc5a80a9e096d529, // _0x0c5a80a9e096d529
0xd8b9a8ac5608ff94, 0x5968f4d606df9df, // draw_debug_line_with_two_colours
0x95e8f73dc65efb9c, 0x63e238348058ff52, // is_player_climbing
0x1bb299305c3e8c13, 0x6f256ad8e8a72a29, // _0x1bb299305c3e8c13
0x82e4a58babc15ae7, 0xcedf153ec4bec19b, // _sc_get_check_string_status
0x4caca84440fa26f6, 0x9f82dbd63a3584d3, // _network_get_desroyer_of_entity
0x44b80abab9d80bd3, 0x25ae733b26be25a7,
0x7d304c1c955e3e12, 0xf165f9f874811603, // get_cam_rot
0x336511a34f2e5185, 0x5a5ced4a707a31f7, // _0x336511a34f2e5185
0x43d1680c6d19a8e9, 0x4e06a0f67e722434,
0x3054f114121c21ea, 0x4941d9ff16893e93, // _0x3054f114121c21ea
0x340f1415b68aeade, 0xe6794a225d718f56,
0xa52d5247a4227e14, 0x92fb5a418f30079b, // _0xa52d5247a4227e14
0x2aa720e4287bf269, 0xa7cd654bb1af9419, // _set_vehicle_neon_light_enabled
0x94dd7888c10a979e, 0x29080c7ab907bb3, // display_system_signin_ui
0xd0afaff5a51d72f7, 0xf3f3dc87d7163212,
0x8a4e6ac373666bc5, 0x1e3b5f05fa6cf48f, // vehicle_waypoint_playback_pause
0x2b3a8f7ca3a38fde, 0x254cda899abe9104,
0x7350823473013c02, 0x7b3767e83e6f888a, // _0x7350823473013c02
0xc505036a35afd01b, 0xee1a804b62e21653, // _0xc505036a35afd01b
0x52837721a854ec7, 0xc12254dc310c0df8, // start_shape_test_bounding_box
0x2432784aca090da4, 0x532174348d7abdb1, // _0x2432784aca090da4
0x462e0db9b137dc5f, 0xb83c26c286a4219f,
0xadd95c7005c4a197, 0x34df3e97feb33490, // calculate_travel_distance_between_points
0x386f6ce5baf6091c, 0x5e65439be0a05829, // get_random_vehicle_in_sphere
0x8879ee09268305d5, 0xe60db7aa1856455d, // unpause_playback_recorded_vehicle
0x3c08a8e30363b353, 0xf05d68ede15f4792, // task_vehicle_chase
0x6ef54ab721dc6242, 0xe8b45e36c80a40ff,
// 0x4c2330e61d3deb56, 0x0, // _0x4c2330e61d3deb56
0xdea2b8283baa3944, 0xd0ef0f935e742970, // set_mp_gamer_tag_name
0x632106cc96e82e91, 0x1cc9ea2bf425c3d0, // tan
0x1c073274e065c6d2, 0xbca0f59279c96043, // _0x1c073274e065c6d2
0xcd71a4ecab22709e, 0x31e1caa2f2e862ef, // _0xcd71a4ecab22709e
0x2f395d61f3a1f877, 0x59c3e6b446000466, // get_player_current_stealth_noise
0x7b21e0bb01e8224a, 0x4bfa8daed5e37b31, // _0x7b21e0bb01e8224a
0x741a3d8380319a81, 0x3b423a8b8d03c42c,
0x388eb2b86c73b6b3, 0xbc1b3d38c4bb38f4, // network_handle_from_player
0x4895bdea16e7c080, 0x9385a87d6175e3e2, // enable_deathblood_seethrough
0x1d610eb0fea716d9, 0xda43a3eccf779d35, // _0x1d610eb0fea716d9
0x48af36444b965238, 0x4ce1dd5cfc1f941e,
0xbc2042f090af6ad3, 0x3f99d2373794b210, // set_vehicle_interiorlight
// 0xef6212c2efef1a23, 0x0, // network_set_voice_channel
// 0xf78b803082d4386f, 0x0, // _0xf78b803082d4386f
0xaf04c87f5dc1df38, 0x3f6f458e1c5cf828, // set_player_reserve_parachute_tint_index
// 0x4665f51efed00034, 0x0, // network_do_transition_to_new_game
0xa18afb39081b6a1f, 0x5cab62f217f047c5, // flash_wanted_display
0xfc058f5121e54c32, 0xa6eec7520a5dc1b1, // get_vehicle_mod_kit_type
0xdea36202fc3382df, 0xe4671be5c854e5f0, // _0xdea36202fc3382df
0x1262d55792428154, 0x9e374b5f44a76ae2, // does_extra_exist
0xeaf4cd9ea3e7e922, 0xfbec827720f84540, // has_anim_event_fired
0xbed8ca5ff5e04113, 0xd5d2d9de08c77294, // _0xbed8ca5ff5e04113
0xed8286f71a819baa, 0xd1f946dd280a3b7, // _0xed8286f71a819baa
0x6d9f5faa7488ba46, 0x28c4f998cc33b00f, // is_ped_male
0xadb57e5b663cca8b, 0x5d67c97b3f42d8d7, // _0xadb57e5b663cca8b
0xa4822f1cf23f4810, 0xa266a7b6efd4fe4e, // _0xa4822f1cf23f4810
0x1ff6bf9a63e5757f, 0x4fdbb9202b510fdf,
0xe30cf56f1efa5f43, 0xfd9ab8bc92b9fb43, // _network_get_random_int_in_range
// 0x77758139ec9b66c7, 0x0, // _0x77758139ec9b66c7
0x445d79f995508307, 0x9fb2258432b82205, // release_preload_mods
0xc515fab3ff9ea92, 0xce3cff625bebaa04, // are_strings_equal
0x52923c4710dd9907, 0xa12a9545c2db2057, // force_room_for_entity
0xf813c7e63f9062a5, 0xefb81c76b9f62ea3, // is_navmesh_loaded_in_area
0x57c51e6bad752696, 0xbf98ce54bd141aff, // set_vehicle_window_tint
0x44d28d5ddfe5f68c, 0x7f8a5fb357e9307, // is_ped_trying_to_enter_a_locked_vehicle
// 0x9e6542f0ce8e70a3, 0x0, // _0x9e6542f0ce8e70a3
0x2ac28f3a01fa04a, 0xae342b0565c9653e, // _0x02ac28f3a01fa04a
0xdc53fd41b4ed944c, 0x2d1ac226385457ae, // get_vehicle_model_max_braking
0x92659b4ce1863cb3, 0x46f6e1d254a6b4a9, // get_player_max_armour
0xc59872a5134879c7, 0x89d40eedb52517b9, // _jitter_vehicle
0xd6ca79eeebd8ca3, 0x3f7b930c5e2acc,
0x336b3d200ab007cb, 0x7a607552722ec814, // _is_enemy_in_range
0x5ead2bf6484852e4, 0x88ad3d6552adc449,
0x18a47d074708fd68, 0x4f94f07dad382cda, // network_does_entity_exist_with_network_id
0x535e97e1f7fc0c6a, 0xc7c1f9eaa0c8491b, // set_exclusive_scenario_group
0x71e2a839de82d90, 0x454078694fe8c013, // _has_button_combination_just_been_entered
0xe2590bc29220cebb, 0xa935b6c4074f7a21, // set_blip_high_detail
0x74732c6ca90da2b4, 0xc95ae863ab260a58,
0x78015c9b4b3ecc9d, 0xf36a487a4d6275b7, // set_pickup_regeneration_time
// 0x59df79317f85a7e0, 0x0,
0xe5564483e407f914, 0x6d056ac3fcca974b, // set_audio_vehicle_priority
0xcb215c4b56a7fae7, 0x5ac0475d36815e75, // _0xcb215c4b56a7fae7
0xdfc252d8a3e15ab7, 0xdf31a51b5eb4d55d, // _toggle_pause_render_phases
0xa48931185f0536fe, 0xe208be5edcd25485,
0x4c9bf537be2634b2, 0x162506c338a20af7, // is_vehicle_siren_on
0xb61c8e878a4199ca, 0xfc05f8c42b023b2e, // get_safe_coord_for_ped
0xfb8794444a7d60fb, 0x9f67a98fe10212e5, // set_vehicle_burnout
0xfb8f2a6f3df08cbe, 0x74ebbdf5d138db5d,
0xf13fe2a80c05c561, 0xd361718f8c8ff30a,
0x8386bfb614d06749, 0x6ff8ef6dc21d25b9, // remove_vehicle_stuck_check
0x57dba049e110f217, 0x99ffda3c390a9838, // network_are_handles_the_same
0xcc665aac360d31e7, 0x11f57efdbe28d476, // set_task_vehicle_chase_behavior_flag
0xe1e258829a885245, 0x1df4a38f465971d0, // sitting_tv
0x95ab8b5c992c7b58, 0x1749f6302f2f8c4e,
0x2a893980e96b659a, 0x47be216aa5c280da, // _0x2a893980e96b659a
0xa049a5be0f04f2f8, 0x49c35a98a4c59b32,
0x299ef3c576773506, 0x2b78f109f3599cb,
0x9d8d44adbba61ef2, 0x4d885477e59754fa, // _0x9d8d44adbba61ef2
0x845333b3150583ab, 0xf275e19910928c6d, // is_ped_in_cover_facing_left
0xf3638dae8c4045e1, 0x71cd86755b8f5322, // set_ambient_zone_list_state_persistent
0xe1ef3c1216aff2cd, 0xed68cddde25a144e, // clear_ped_tasks
0x2d343d2219cd027a, 0x792d8d44cda437c2, // has_ped_been_damaged_by_weapon
0x4fc9381a7aee8968, 0x6eac27e1cb177752, // clear_decision_maker_event_response
0xffe5c16f402d851d, 0xda09fe416d03a4ec, // _sc_inbox_message_get_data_bool
// 0xff6be494c7987f34, 0x0, // _start_shape_test_surrounding_coords
0x75138790b4359a74, 0x44467d6a30f288ca, // network_set_activity_spectator
0xa571d46727e2b718, 0x5d79f3d06eb318a0, // _is_input_disabled
0x2c42340f916c5930, 0x4d1497fab387173, // _0x2c42340f916c5930
0xa72cd9ca74a5ecba, 0xd847d71d9e6142e, // clear_entity_last_damage_entity
0x418ef2a1bce56685, 0x87b31ab237df9c3a, // create_nm_message
0xb51b9ab9ef81868c, 0x3cdd064f4e34ed2d, // _0xb51b9ab9ef81868c
0x6e31b91145873922, 0x50358ffaf6307580, // _is_minimap_area_revealed
0x7c837f9a01c34c9, 0xc56fb1634fb1f447, // set_text_scale
0xbc9823ab80a3dcac, 0x3c28700239538cd2,
0x936e6168a9bcedb5, 0x3ae20f34fee6c258, // get_event_exists
0xef662d8d57e290b1, 0x6a6cdd58b3d445a1, // _call_scaleform_movie_function_mixed_params
0x59328eb08c5ceb2b, 0x54b5cc493fe892be,
0xe662c8b759d08f3c, 0x8a4aeb5ca3166d61, // leaderboards2_read_by_score_float
0x8c1dc7770c51dc8d, 0xe6dcbcf41189204, // set_cam_affects_aiming
0x75632c5ecd7ed843, 0x7bdae54ac242361, // _sc_start_check_string_task
0x28157d43cf600981, 0xc79ac4010c2279a0, // set_scenario_peds_spawn_in_sphere_area
0xfe43368d2aa4f2fc, 0xaadc92ba40861eaa, // set_new_waypoint
0xe124fa80a759019c, 0xa6dac1f822246de2, // begin_text_command_clear_print
0x3c06b8786dd94cd1, 0x790b9d2b23c4d214, // get_ped_defensive_area_position
// 0xa5c80d8e768a9e66, 0x0, // _0xa5c80d8e768a9e66
0x7022bd828fa0b082, 0xfbced64db25f18d6, // set_entity_only_damaged_by_relationship_group
0xe058175f8eafe79a, 0xe26ca8d5936df2ea, // _0xe058175f8eafe79a
0x8f7156a3142a6bad, 0x36ed000ffae4bdc3, // get_number_of_ped_texture_variations
0x9ab9c1cfc8862dfb, 0xcb262e6f54213bf7,
0x784ba7e0eceb4178, 0x24794947e27c3e6d, // _0x784ba7e0eceb4178
0x5f92a689a06620aa, 0x77babfd1d75aa582, // get_number_of_events
0xe1ca84ebf72e691d, 0x69ad82676ba55528, // _0xe1ca84ebf72e691d
// 0xac6d445b994df95e, 0x0, // remove_ped_elegantly
0x8ba6f76bc53a1493, 0x1c2b995ba5ade8ff, // set_vehicle_automatically_attaches
0x74881e6bcae2327c, 0xe572825b0073f870, // network_get_currently_selected_gamer_handle_from_invite_menu
0xa2ccbe62cd4c91a4, 0xab46782535b3097d, // _0xa2ccbe62cd4c91a4
0x9f7bba2ea6372500, 0x2c02423528813544, // set_player_cloth_package_index
0x5fcf4d7069b09026, 0xe3f7cbc28f745843,
0x77ed170667f50170, 0xb4f447a5639e2006, // release_named_script_audio_bank
0x4462658788425076, 0xae839cf49f5c596f, // register_pedheadshot
0x404a5aa9b9f0b746, 0x3f1ebcfed4923b07, // set_drive_task_max_cruise_speed
0xd24d37cc275948cc, 0x36163153849dfda1, // get_hash_key
0x8b7fd87f0ddb421e, 0xd86888c017f53f89, // set_vehicle_fullbeam
// 0xa60ef3b6461a4d43, 0x0, // _get_ped_head_overlay_value
0xe532d6811b3a4d2a, 0x547cb9e25eeeb60d, // network_x_affects_gamers
// 0x3bd3f52ba9b1e4e8, 0x0, // set_gps_active
0x18a3e9ee1297fd39, 0xc668ccbc1951ca1, // get_melee_target_for_ped
0x975d66a0bc17064c, 0x39af2860c6630613, // _0x975d66a0bc17064c
0xd9127e83abf7c631, 0x16b5c2ed58b77473, // get_itemset_size
0x957838aaf91bd12d, 0x9d7a6742bd658f9, // _clear_area_of_everything
0xec4b4b3b9908052a, 0xfc44e3bb2f5e95e8, // _0xec4b4b3b9908052a
0x75dbec174aeead10, 0x2ce0a5587e9f908f, // set_boat_anchor
0x14ba4ba137af6cec, 0x99304a001736bd91, // _get_ped_inside_explosion_area
0x497bf74a7b9cb952, 0xb113eeffaf4db51f, // _set_ped_head_overlay_color
0x20194d48eaec9a41, 0x4bcb2d884f9f5c7d, // process_cash_gift
0xdcd2a934d65cb497, 0xb593adb2d54f30e1, // set_ammo_in_clip
0x2107ba504071a6bb, 0x65f35477fead6f0f, // get_interior_from_entity
0xe870f9f1f7b4f1fa, 0xd0186d46bc377975,
0xe31c2c72b8692b64, 0xc30d5c4dcac8020a, // is_entity_occluded
0xa2f80b8d040727cc, 0x9d933dc08cbbec60, // set_vehicle_doors_locked_for_all_players
0xc593212475fae340, 0xcc2c88b9353caf70, // has_ped_got_weapon_component
0x49733e92263139d1, 0x1b2303f9dc2d90d5, // set_vehicle_on_ground_properly
0x54ce8ac98e120cab, 0xcae35308cc49f0cc, // _begin_text_command_width
0xbc5115a5a939dd15, 0x7cd49339861d878a, // is_interior_disabled
0x52dff8a10508090a, 0xe9164521d5c8f06e, // get_combat_float
0xd830567d88a1e873, 0x6223c0661ebe5349, // network_set_entity_can_blend
0x524ee43a37232c00, 0xd5d2a075973c3226, // network_spent_boat_pickup
0x5ceb25a7d2848963, 0x4aa9ff0306655b2e, // vehicle_waypoint_playback_use_default_speed
0xeb0585d15254740, 0xcbdee923f851f500, // set_ped_can_play_ambient_base_anims
0x9e23b1777a927dad, 0x48dd8e3533f524bd, // get_time_as_string
0x3bc861df703e5097, 0xea343c9350c9b1ab,
0x703123e5e7d429c2, 0x2119dc81e4edba78, // get_vehicle_node_position
0xbe2caccf5a8aa805, 0x30f6f0b876e12ad8, // set_streamed_texture_dict_as_no_longer_needed
0x91b87c55093de351, 0x7c524c4d606cca17,
0x9d728c1e12bf5518, 0xb0a641f421f4d8cb, // _0x9d728c1e12bf5518
0xd2cc78cd3d0b50f9, 0xf348b6bde99c4570, // _0xd2cc78cd3d0b50f9
0x367a09ded4e05b99, 0x7fc8fae3451a21ad, // is_scenario_group_enabled
0xbc74b4be25eb6c8a, 0x9c73eec367aa7609, // is_heli_part_broken
0x8cddf1e452babe11, 0xca29d24878d6f94a, // stat_set_user_id
0x8935624f8c5592cc, 0xa8d8b8c75983e4d9, // get_mod_text_label
0x6856ec3d35c81ea4, 0xdf05dcf4f35a9028,
0x95d2d383d5396b8a, 0x7952b5f52781e66e, // set_ped_is_drunk
// 0xbc7be5abc0879f74, 0x0, // can_use_weapon_on_parachute
0xfee4a5459472a9f8, 0x2c9aff5baf906cd4,
0xfb92a102f1c4dfa3, 0xe19223b3551f58b8, // is_ped_falling
0x748040460f8df5dc, 0x31b8854b474d50d7, // play_anim_on_running_scenario
0x17e0198b3882c2cb, 0xdda8b70221e685f3,
// 0xd2049635deb9c375, 0x0,
0xb9449845f73f5e9c, 0x5e8c17f77ddd134e, // _begin_scaleform_movie_method_v
0x6f72cd94f7b5b68c, 0xc22c88296da25b07,
0xb9ea40907c680580, 0xad3db344aac22bf7, // _set_checkpoint_icon_rgba
0xb69317bf5e782347, 0xa5f44ec021f96c6b, // network_request_control_of_entity
// 0xbd0be0bfc927eac1, 0x0,
0x1f2e4e06dea8992b, 0x2b2afc30de3fe922, // _0x1f2e4e06dea8992b
0x9b6786e4c03dd382, 0xec91c0eb0f842fd3, // get_blip_info_id_pickup_index
0xec5e3af5289dca81, 0xa29d824c081957a7, // bad_sport_player_left_detected
0xa4e8e696c532fbc7, 0x3991c5b2656181d9, // create_mobile_phone
0x2058206fbe79a8ad, 0xfd8a8892740fa169, // get_rotation_of_vehicle_recording_at_time
0xb70374a758007dfa, 0x12533a8ce4d9105b, // play_stream_from_vehicle
0x98215325a695e78a, 0xa4971144b6c2da45, // _0x98215325a695e78a
// 0x5fc472c501ccadb3, 0x0, // _0x5fc472c501ccadb3
0x82fde6a57ee4ee44, 0x523f36af20d6c821, // _get_projectile_near_ped
0xafbd61cc738d9eb9, 0x60b5c1fd066cb864, // get_entity_rotation
0xc4b5467a1886ea7e, 0x662913f6b16bafbc, // leaderboards_get_column_id
0x20b711662962b472, 0x3c3357f21cc55c2c, // has_entity_anim_finished
0xcfb0a0d8edd145a3, 0x8ae34e8b10270d31, // is_entity_in_water
0x1654f24a88a8e3fe, 0x926ba39ec589c43, // _0x1654f24a88a8e3fe
0xa08fe5e49bdc39dd, 0x371e5ab66dc2b32e, // _0xa08fe5e49bdc39dd
0x741b0129d4560f31, 0xcc591fd994f115fc, // create_cinematic_shot
0x21d2e5662c1f6fed, 0x1880c7d8a95087e4, // reset_vehicle_wheels
0x1b93e0107865dd40, 0xd8aa25d9a7615eee, // set_cam_debug_name
0x6f7794f28c6b2535, 0x8ec868f9d34264b, // _0x6f7794f28c6b2535
0xfa1e2bf8b10598f9, 0x1578197a616e70fa, // is_player_pressing_horn
0x10706dc6ad2d49c0, 0xb36d48cf008aa5fe, // restart_frontend_menu
0x9120e8dba3d69273, 0x258b5681b55833b9, // leaderboards_get_cache_data_row
0xfba08c503dd5fa58, 0x6413bf5f9b062200, // create_pickup
0x3eb1fe9e8e908e15, 0xe0345c3a81f4471a, // task_cower
0xf827589017d4e4a9, 0xa0ddb8aafd50adba, // set_weapon_object_tint_index
0xe7e4c198b0185900, 0xf56e8c0d662f8c55, // _0xe7e4c198b0185900
0x9e30e91fb03a2caf, 0x16265e4b4627360d, // _0x9e30e91fb03a2caf
// 0x70b8ec8fc108a634, 0x0, // _0x70b8ec8fc108a634
0x2d0fc594d1e9c107, 0xc3854c7f24979d7d, // is_in_itemset
0x66b59cffd78467af, 0x530dc7bb39d842fd,
0x1b0b4aeed5b9b41c, 0x8b51389a4cffacec, // _0x1b0b4aeed5b9b41c
0x7fb17ba2e7deca5b, 0x795fbb6aa607ee12, // set_ped_generates_dead_body_events
0x56eb5e94318d3fb6, 0x7cfc8cfae3ac948a, // _0x56eb5e94318d3fb6
0x34b973047a2268b9, 0x3a8d52ab8915d68b, // playstats_cloth_change
0x8f8c0e370ae62f5c, 0xca3ff712b8291e1c, // hint_ambient_audio_bank
0xa01b8075d8b92df4, 0x336b0a31fc08d5d7, // set_player_sprint
0x1eaf30fcfbf5af74, 0xe23e0c76e7f802f6, // is_vehicle_node_id_valid
0x8d32347d6d4c40a2, 0x3449ea232f9b8ead, // set_player_control
0x745711a75ab09277, 0x64b7f9f8020d2ebc, // set_frontend_active
0xbe73da6984a6e33, 0x8b881edf77941dc, // network_is_pending_friend
0xdb172424876553f4, 0xdf9905432e81dc6e, // set_dispatch_cops_for_player
0xb9d0dd990dc141dd, 0x4fdf3931f17bf1a7, // reset_wanted_level_difficulty
0xc15907d667f7cfb2, 0x58149359ca63fc4f, // _0xc15907d667f7cfb2
0x26d7399b9587fe89, 0xec4a8400f1dcf1d4, // _0x26d7399b9587fe89
0x6b1e8e2ed1335b71, 0x6767500a150cf86f, // decor_set_bool
0x9ec6603812c24710, 0xdd4ffaa17341d382, // int_to_participantindex
0x2c8e5b49848664e, 0x8411bdad24f96365, // set_scenario_group_enabled
0xdf0d54be7a776737, 0x3cd9e69d09fd9f9,
0xced08cbe8ebb97c7, 0x197aa05d0fed5d76, // _0xced08cbe8ebb97c7
0x44e44169ef70138e, 0xdfe49b71c087c2d8, // _set_phone_lean
0xca78cfa0366592fe, 0x28b04d56c190bd36, // _display_onscreen_keyboard_2
0x768ff8961ba904d6, 0xbfcc17d9792f43af, // _get_scaleform_movie_function_return_bool
0x69778e7564bade6d, 0xa107bb59f9a92498, // can_register_mission_entities
0x7572ef42fc6a9b6d, 0xd06638d8a797143d, // sc_inbox_message_get_data_string
0xce2f5fc3af7e8c1e, 0x696bd39fe549d312, // set_group_formation
// 0xf514621e8ea463d0, 0x0, // _network_earn_from_armour_truck
0x10d0a8f259e93ec9, 0x690b38059370adb1,
0x3ca58f6cb7cbd784, 0x982a72d771cf4fe1, // network_is_player_a_participant
0x5f28ecf5fc84772f, 0xf72c40745aa793f1, // set_mission_name
// 0x599e4fa1f87eb5ff, 0x0,
0x304ae42e357b8c7e, 0x38cd0cf7df213a81, // task_follow_to_offset_of_entity
0xd11fa52eb849d978, 0xac9d53cbba71e4be,
0x23083260dec3a551, 0x301705faf07cb0b2, // add_patrol_route_link
0x25e68244b0177686, 0x2e4e732842cf7f5, // remove_from_itemset
0x6448050e9c2a7207, 0x482d46b42779dc80, // get_nth_closest_vehicle_node_id_with_heading
0x853648fd1063a213, 0x1b3e16c485b8dd94, // begin_text_command_is_message_displayed
0xb2d0bde54f0e8e5a, 0x1b17215c8f14b10f, // _0xb2d0bde54f0e8e5a
0x7dcf7c708d292d55, 0xefc3f00126949bda, // override_cam_spline_motion_blur
0x2a25adc48f87841f, 0x2a10378c75942c86,
0x2dcf46cb1a4f0884, 0x58f14aab576a3c33,
0x7472bb270d7b4f3e, 0x83af8b1b51f18cd7,
0xfc8202efc642e6f2, 0xe77fa521699f639c,
0x35124302a556a325, 0xd1fca9100c399ba8, // _object_value_add_boolean
// 0x8217150e1217ebfd, 0x0, // has_scaleform_container_movie_loaded_into_parent
0x7d6f9a3ef26136a0, 0x1dcd5e4e6146beec, // _0x7d6f9a3ef26136a0
0xae73d8df3a762b2, 0x2a06b27d1473e9ed, // _0x0ae73d8df3a762b2
0x9de624d2fc4b603f, 0xe4e9c79867c15b1f,
0x60d6e96f8b8e48d, 0x11d8e875f068e371, // does_entity_have_drawable
0xf87e938bdf29d66, 0x388f31e87fde9e2a,
0x1dccacdcfc569362, 0xa919f27746977bf, // network_set_rich_presence
0xd242728aa6f0fba2, 0xeae7ad3a4765862d, // get_position_of_vehicle_recording_at_time
0x175b6bfc15cdd0c5, 0x10cdb55c8473f547, // set_debug_lines_and_spheres_drawing_active
0xdd564bdd0472c936, 0xc3e18e4c4b2a7cef, // pause_menu_activate_context
0x4127f1d84e347769, 0xb0bf2ee8377b92d7, // attach_vehicle_to_cargobob
0xbf4dc1784be94dfa, 0x593a0940a0c53509, // _0xbf4dc1784be94dfa
0x8fa9c42fc5d7c64b, 0x98db180d46a98f45, // _0x8fa9c42fc5d7c64b
0xec4cf9fcb29a4424, 0x9d41aec5dbec2d9, // get_interior_from_collision
0xea9960d07dadcf10, 0xb93ed94529b7a577, // _0xea9960d07dadcf10
0x470555300d10b2a5, 0x469bf85808505e83,
0x591ca673aa6ab736, 0x6c04c565e931d895, // set_mission_train_coords
0xb8721407ee9c3ff6, 0xb3235ff645c629cf, // _0xb8721407ee9c3ff6
0xa0fe76168a189ddb, 0xab923d8907c25634,
0x15c49a93e3e086e, 0x53f6de06dce23ebf, // _disable_phone_this_frame
0x8806cebfabd3ce05, 0x9b711f524a4e1658, // _0x8806cebfabd3ce05
0x1d4dc17c38feaff0, 0x51b77d646c690b42,
0xb3e6360dde733e82, 0xbf1002345a427078, // _0xb3e6360dde733e82
0xb2cbcd0930dfb420, 0x2442598ea366437f, // can_set_exit_state_for_camera
0x54354a99211eb96, 0x40863ebaea2f03d7,
0x406137f8ef90eaf5, 0x4cbc0b0c8471392b, // set_activate_object_physics_as_soon_as_it_is_unfrozen
0xa60017f841a54f2, 0x94ba8ad7ec448d4b, // _0x0a60017f841a54f2
0xa9010cfe1e3533, 0x24ca7139a01083be, // get_sequence_progress
0x46f917f6b4128fe4, 0xe62dd6141bef78d0, // playstats_award_xp
0x65287525d951f6be, 0xe7f42e784c2e4682, // _get_shape_test_result_ex
0xf56b8137df10135d, 0x856d1f5a79559589, // start_networked_particle_fx_non_looped_at_coord
// 0xff1bed81bfdc0fe0, 0x0, // set_explosive_melee_this_frame
0xc7db36c24634f52b, 0x7aba900a90ed55f,
0x2aed6301f67007d5, 0x2203a4dfb3c360eb, // _0x2aed6301f67007d5
0x2d03e13c460760d6, 0x80c1a175511337ef, // reset_player_arrest_state
0x7d3a583856f2c5ac, 0xec657569a3950cbd,
0x57a3bddad8e5aa0a, 0x72b85b341adbe9de,
0xfbe20329593dec9d, 0x73de193a69c3d683, // _0xfbe20329593dec9d
0xf3365489e0dd50f9, 0xb79caf8401a6825f, // _0xf3365489e0dd50f9
// 0xd0ef8a959b8a4cb9, 0x0, // get_street_name_from_hash_key
0xcf3a965906452031, 0x4c948f9025ce510, // get_num_reserved_mission_vehicles
0x9d74ae343db65533, 0x80c90b71b6e0e34b, // prepare_alarm
0xe6a877c64caf1bc5, 0x8e2fb25641b13cf6, // get_ped_waypoint_distance
0x5fbca48327b914df, 0xc9a95d9805586feb, // show_heading_indicator_on_blip
0xa079a6c51525dc4b, 0xcf50815becdf585d, // is_explosion_in_angled_area
0x22102c9abfcf125d, 0x2804106046848982, // delete_script_vehicle_generator
0x6d0de6a7b5da71f8, 0xeef8394db3d3dfa1, // get_player_name
0xaab11f6c4adbc2c1, 0xefd0728cddf9ba14, // network_clan_get_membership_count
0x97a28e63f0ba5631, 0x3ad1fd43ef012041, // task_use_nearest_scenario_chain_to_coord_warp
0x36c6984c3ed0c911, 0xedf822d08d0bdb33, // _0x36c6984c3ed0c911
0xf60165e1d2c5370b, 0xc4e960383676ebce, // _0xf60165e1d2c5370b
0xbf286c554784f3df, 0xe714e221a68af770, // set_mobile_phone_radio_state
0x91aef906bca88877, 0x5ebe50d55314cead, // is_disabled_control_just_pressed
0x98ab65b9ed9a9ec, 0xde4ba37d36ff0938, // _facebook_set_heist_complete
0x1c436fd11ffa692f, 0xae1118d77b7e29f, // network_spent_betting
0x8f08017f9d7c47bd, 0x60411fcc629bc96d, // _0x8f08017f9d7c47bd
0xf8c397922fc03f41, 0xdfea91a83c472035, // get_convertible_roof_state
0x37c8252a7c92d017, 0xc57b5d939ba8d715, // set_disable_vehicle_petrol_tank_damage
0x34d23450f028b0bf, 0x3f2ed75285027cf0,
0xbc72b5d7a1cbd54d, 0x56aec27a8be13c6,
0x46f2193b3ad1d891, 0xb9f0674ffc455e48, // set_ped_steers_around_peds
0xad973ca1e077b60, 0xa80d744a456f3f, // _is_tv_playlist_item_playing
0x50f457823ce6eb5f, 0x1668a4207e5c90c5, // _0x50f457823ce6eb5f
0x2cc848a861d01493, 0x7eb22dfcca3e0c52,
0x786a4eb67b01bf0b, 0x767d47ecf394c2f8, // explode_vehicle_in_cutscene
0xc19f6c8e7865a6ff, 0x3b17387402c37347, // _network_session_hosted
0x214cd562a939246a, 0xe4db8c9808f2ffde,
0xc514489cfb8af806, 0x9e4935aac82732ab, // request_scaleform_movie_instance
0xa6f312fcce9c1dfe, 0xb4bb8844c2d9547a, // reset_player_stamina
0xfa6e4b75f302400, 0x9be82a9a1e3a6df7, // task_vehicle_escort
0x31f924b53eaddf65, 0x2b4c632983b0a26a, // _0x31f924b53eaddf65
0x9641a9ff718e9c5e, 0x1e76b6e2b806ee0f, // set_store_enabled
0x2b6d467dab714e8d, 0x186981ae2ec1837f, // _set_blip_shrink
0x113d2c5dc57e1774, 0x72da74d655fea173, // set_tv_audio_frontend
0x9b0f3dca3db0f4cd, 0x6379daf3ad61121f, // get_landing_gear_state
0xfde8f069c542d126, 0x9d5f6d4e8a7a3188, // cell_cam_activate
0xaad68e1ab39da632, 0x65a0e70e3c94dbd7, // draw_debug_sphere
0x983765856f2564f9, 0xbca389843909eb28, // set_vehicle_engine_can_degrade
0xda66d2796ba33f12, 0x476cfecd9a50c6ec, // set_fade_in_after_death_arrest
0xe0a6138401bcb837, 0xc94e72b5f26d9e5b,
0xa67f9c46d612b6f1, 0x7356951f258a9148, // _set_mp_gamer_tag_icons
0x3fef770d40960d5a, 0xfbb1f99a825cab09, // get_entity_coords
0x609278246a29ca34, 0x4355c07879db90e6, // _0x609278246a29ca34
0xc819f3cbb62bf692, 0x3aaf29f17a3f9825, // _render_first_person_cam
0x318516e02de3ece2, 0xf6a58e47d9b7a686, // _0x318516e02de3ece2
// 0xba52ff538ed2bc71, 0x0, // _get_ngstat_bool_hash
0x3c606747b23e497b, 0x1e0350f1d7702d6a, // set_ped_combat_range
0x43f4dba69710e01e, 0xc72174447a3ac222,
0xe0e500246ff73d66, 0xf735d8162d93942e, // begin_replay_stats
0xaf50da1a3f8b1ba4, 0x613545eb27ee259c, // network_can_access_multiplayer
0xeea3b200a6feb65b, 0x39badeb7a41b445, // set_damping
0xb4df1fa60c0e664, 0x53d0ffb5907f46f, // show_hud_component_this_frame
0xe3d969d2785ffb5e, 0xc052b98994789931,
0xa06509a691d12be4, 0x75d5b32c7e168828,
0x7bf1a54ae67ac070, 0x8bf7edecb6c87d6e, // _0x7bf1a54ae67ac070
0x7285951dbf6b5a51, 0x7dcfbd169402e9d1, // task_throw_projectile
0xdfa2ef8e04127dd5, 0xa06defff267c21e, // request_streamed_texture_dict
0xa6dd8458ce24012c, 0x886b75403f0f31de, // network_spent_bull_shark
// 0x61326ee6df15b0ca, 0x0, // _network_earn_from_bend_job
0xc23de0e91c30b58c, 0xad16833367ac0879, // _request_cutscene_ex
0x7d395ea61622e116, 0x4c018f32afef26f9, // _0x7d395ea61622e116
0x85b6c850546fdde2, 0x1bc917f9cb2b42ef, // _0x85b6c850546fdde2
0x734292f4f0abf6d0, 0xdd450b93c16acea7, // set_synchronized_scene_phase
0x69f4be8c8cc4796c, 0xc4a347124f39d998, // task_look_at_entity
0x95c0a5bbdc189aa1, 0x58d27fb67c881d6e,
0x2a70bae8883e4c81, 0xc2f708de8ad68197, // is_point_in_angled_area
0x127de7b20c60a6a3, 0xc71e92d10d5db3ea, // set_blip_name_to_player_name
0x546524ade2e9723, 0xa3faf797b8885c09, // set_cutscene_ped_prop_variation
0x8a7a40100edfec58, 0x5c7450720c4689da, // _request_interior_room_by_name
0x35b9e0803292b641, 0xf237530c2def2576, // is_model_in_cdimage
0xb302540597885499, 0x117a9e054b0f10fb, // clear_player_wanted_level
0xdce4334788af94ea, 0x97e7778e3e162e8, // is_this_model_a_heli
0x5927f96a78577363, 0x3d258435016d9f74, // set_entity_lod_dist
0xc024869a53992f34, 0x60f5b36347629584, // is_ped_swimming_under_water
0xd3bd40951412fef6, 0x483d0035d6e46fd, // request_anim_dict
0xdcd51dd8f87aec5c, 0xf434cd9f35e6e118, // network_handle_from_user_id
0x1ccc708f0f850613, 0xb03bb0e0d109a9b0, // _set_hud_colours_switch
0x134f0835ab6bfcb, 0x253e2a687abb3993, // create_checkpoint
0x291e373d483e7ee7, 0x1b252eb99229f1c8, // _is_any_passenger_rappelling
0x873fa65c778ad970, 0x7177e24b80b556e6, // enable_movie_subtitles
0x190428512b240692, 0x10c4b80f25cee687, // _0x190428512b240692
0x568566acbb5dedc, 0xebe37e4c0f1f0b0b, // get_vehicle_node_properties
// 0xd6ade981781fca09, 0x0, // _0xd6ade981781fca09
0x941e5306bcd7c2c7, 0xe86c7171607ed2ef,
0x267c78c60e806b9a, 0xee754c403a7a99ce, // _0x267c78c60e806b9a
0x31b73d1ea9f01da2, 0x21675f65d589cace,
0xcfeb8af24fc1d0bb, 0x13487a9acb41636f, // _0xcfeb8af24fc1d0bb
0x6d38f1f04cbb37ea, 0xc94f9717aa77d4d0, // detach_synchronized_scene
0xa06c969b02a97298, 0xe48faa8a938257c9, // decor_get_int
0xe73092f4157cd126, 0x2fdc59e8a6312aca, // is_player_in_cutscene
0x7f96f23fa9b73327, 0xe0ca0d238d96c998, // _0x7f96f23fa9b73327
0x15e33297c3e8dc60, 0xdfc146d7b8ccc31e, // _0x15e33297c3e8dc60
0x4dfdd9eb705f8140, 0xdab0a5fc9a1656fc, // _0x4dfdd9eb705f8140
0x7fdfade676aa3cb0, 0x82ef7dcbee45753d, // draw_debug_line
0x6f6981d2253c208f, 0x98757942e2f9d44, // hide_ped_weapon_for_scripted_cutscene
0x9d7696d8f4fa6cb7, 0x63e7880af3d685be,
0x9bb01e3834671191, 0x731f434eafe6e9fe, // is_ped_group_member
0x2d83bc011ca14a3c, 0x3b36c543b2adb50e, // set_player_weapon_defense_modifier
0xd8122c407663b995, 0xee24a98ac0f916a8,
0xf2a1b2771a01dbd4, 0xc971b247bebb13d6, // draw_light_with_range
0x708bdd8cd795b043, 0x3320f94ce5e0322b,
0x8bb4ef4214e0e6d5, 0xc5f99a3f8797a55e, // get_entity_forward_x
0x10bddbfc529428dd, 0xa32c2c4df096c08a, // end_text_command_is_this_help_message_being_displayed
0x5ad3932daeb1e5d3, 0xb534cb51524596e7,
0xa8638be228d4751a, 0xce78d564bc829c9f,
0x4aacb96203d11a31, 0x5560135ea44157f4, // clear_player_has_damaged_at_least_one_non_animal_ped
0x1bb4d577d38bd9e, 0x9a7dd794c616d095, // _0x01bb4d577d38bd9e
0x7ff4944cc209192d, 0xb813515a6f4f80b9, // play_sound
0x3bc4245933a166f7, 0xeb9780f1db69ccb5, // get_vehicle_extra_colours
0xbf19721fa34d32c0, 0x30951c940424b7b, // task_plane_land
0x576594e8d64375e2, 0x671002c0d77133c6, // _0x576594e8d64375e2
0xbd6e84632dd4cb3f, 0x4144b586e7608178,
0x9e5b5e4d2ccd2259, 0x2c64d5082d2f968a, // smash_vehicle_window
0xcaa15f13ebd417ff, 0x5cb2eed2adf499cb, // set_number_of_parked_vehicles
0x8609c75ec438fb3b, 0x9a24838d46b52597, // add_cam_spline_node
0xa0682d67ef1fba3d, 0xcccd549ee402e8b, // network_suppress_invite
0x2faa3a30bec0f25d, 0x2491e9986ce036b, // is_next_weather_type
0x59bf8c3d52c92f66, 0x2f8a4df7d0dff0a8, // set_vehicle_can_break
0x6094ad011a2ea87d, 0x6ee765d5b613ab2a, // get_vehicle_ped_is_using
0xe4c749ff9de9cc4, 0x9454b3d676754d96, // add_text_component_formatted_integer
0x1670f8d05056f257, 0x6f352fa68bb8fad7, // _0x1670f8d05056f257
0x5d5479d115290c3f, 0x560a21df8aa58925, // is_tennis_mode
0xed1517d3af17c698, 0x53b7181bef7ecc1, // network_earn_from_pickup
0x63f58f7c80513aad, 0xf0be7cb40de62a2f, // set_ped_can_be_targetted
0x1095c95cd46b624, 0x4d156c265da4736d, // _0x01095c95cd46b624
0x1cefb61f193070ae, 0x5e10768f0f254fe4, // get_mobile_phone_rotation
// 0x3300b57fcac6ddb, 0x0, // _0x03300b57fcac6ddb
0xa1750ffafa181661, 0xaec6ca203db34c19, // stat_load_pending
0xb40ed49d7d6ff84, 0x79a4eb62913272c1,
// 0x90a6526cf0381030, 0x0, // _0x90a6526cf0381030
0x25223ca6b4d20b7f, 0x13348e86d5b8a052,
0x378c08504160d0d, 0xbfbb94581d72db56, // _0x0378c08504160d0d
0x90d2156198831d69, 0x976357e602648ddf, // task_set_blocking_of_non_temporary_events
0xe679e3e06e363892, 0x2da168143d0bd460, // network_override_clock_time
0x9c1556705f864230, 0x21494c699609b7e2,
0xdc54a7af8b3a14ef, 0xf6efdade5378a189,
0xb9854dfde0d833d6, 0x640f85e75f89503, // _0xb9854dfde0d833d6
0x135f9b7b7add2185, 0xd8081f9f1b6f1b80, // _0x135f9b7b7add2185
0x6f972c1ab75a1ed0, 0xd5ae919ed8631502, // is_ped_in_any_train
0xc56fbf2f228e1dac, 0xa46672349428483, // _0xc56fbf2f228e1dac
0x218dd44aaac964ff, 0xe9371347984387fa, // clear_ambient_zone_state
0xc927ec229934af60, 0x842da10988a63fc8,
0xcd018c591f94cb43, 0x4e72cea3e9006ff4, // _0xcd018c591f94cb43
0xbe5c1255a1830ff5, 0x4d606ea1940e249e, // _0xbe5c1255a1830ff5
0x5a50af38947eb8d, 0x35838b09fd45af58, // network_delete_character
0x8a97bca30a0ce478, 0x17d569f7c0516cdf, // create_model_hide
0x23ba6b0c2ad7b0d3, 0xdd1170557490e660, // _0x23ba6b0c2ad7b0d3
0xfdb423997fa30340, 0x68f7298cc6f16961,
// 0x6d28dc1671e334fd, 0x0,
0xa213b11dff526300, 0x64be0143697d1d03,
0xda1f1b7be1a8766f, 0xbcd00831244556bd, // set_ped_allowed_to_duck
0xaa76052dda9bfc3e, 0xc59dca651a00e33f, // _0xaa76052dda9bfc3e
0x225778816fdc28c, 0x91e6b282f48e0cbb, // _0x0225778816fdc28c
0x33e3c6c6f2f0b506, 0x506993ad40fe7cf1, // _0x33e3c6c6f2f0b506
0x8c95333cfc3340f3, 0x243eae2c2ab53805, // set_ped_population_budget
0x19a30c23f5827f8a, 0x7423db0e0eb9a561,
0x9133955f1a2da957, 0xcedafdae82811db2, // _set_north_yankton_map
0x876928dddfccc9cd, 0xf5a4ca9802b6e13,
0x72c1056d678bb7d8, 0x5b6554a003e467e5, // _0x72c1056d678bb7d8
0x2959f696ae390a99, 0x3dda36183b10570, // is_vehicle_stopped_at_traffic_lights
// 0x62a456aa4769ef34, 0x0, // play_vehicle_door_close_sound
0x90532edf0d2bdd86, 0xf563578be7349d56, // detach_vehicle_from_trailer
0x39dac362ee65fa28, 0x86a90eb179092418, // is_this_model_a_quadbike
0x44aca259d67651db, 0x7de053b6ad1b1f7b, // _0x44aca259d67651db
0x1600fd8cf72ebc12, 0x8f5d92727ff07aea, // _0x1600fd8cf72ebc12
0x70fda869f3317ea9, 0x1e67980b42842e37,
0x2e2eba0ee7ced0e0, 0x1041083d5bd8f51e, // is_explosion_in_area
0x9dfe13ecdc1ec196, 0x5237564f28aac0ba, // set_time_idle_drop
// 0x31125fd509d9043f, 0x0, // _0x31125fd509d9043f
0x3a17a27d75c74887, 0x6c5916bb7cb229de,
0xc5ef963405593646, 0x21d9c65be88395ff, // add_line_to_conversation
0xd0f64b265c8c8b33, 0x4878c772ee985241, // draw_spot_light
0x1db21a44b09e8ba3, 0xc8abdd7beb411f6b, // _set_text_chat_unk
0x95a6c46a31d1917d, 0xac48e370aba882d5, // task_clear_defensive_area
// 0x8214a4b5a7a33612, 0x0, // get_cgoffset
0xcea66dad478cd39b, 0x4b06b5746cbec99f, // set_flash_light_fade_distance
0x5d10b3795f3fc886, 0x4ba2474db2034ff1,
0x7767dd9d65e91319, 0x39ca729c8ccdfc07, // delete_patrol_route
0xba01e7b6deefbbc9, 0xbfd0f8e7b0df0a1b, // set_cutscene_ped_component_variation
0x39bbf623fc803eac, 0x75d3f9044123d4f9, // _set_notification_color_next
0xf796359a959df65d, 0x3754cdf254d9f523, // set_distant_cars_enabled
0xc396f5b86ff9febd, 0x375b5f798c2cc956, // set_ped_leg_ik_mode
0xdf649c4e9afdd788, 0x8a4882bfe94aaf0,
// 0x9eb6522ea68f22fe, 0x0,
0x991251afc3981f84, 0x15dfb209d94e0277,
0xda5f8727eb75b926, 0x6b0f82dae06a9949, // is_blip_short_range
0x921ce12c489c4c41, 0x5ad7cd8b9420f543, // _is_task_move_scripted_active
0xfb380a29641ec31a, 0x8e4c2bd2876d3c4c, // hint_script_audio_bank
0x12b37d54667db0b8, 0xfcd1cd4f8ac6d5d1, // set_player_invisible_locally
0xb65b60556e2a9225, 0x7c71681384076318, // is_audio_scene_active
0xadcde75e1c60f32d, 0xa58c083e829597f7, // is_position_occupied
0xdd9b9b385aac7f5b, 0xbae549a63f38dae8, // clear_area_of_objects
0xfb82563989cf4fb, 0x9723ab7c299f4a6, // _0x0fb82563989cf4fb
0xb33e291afa6bd03a, 0x3540062015a9edd6, // task_parachute_to_target
0x7cfba6a80bdf3874, 0xd7c89bb3bdf2384a, // set_entity_lights
0x77b5f9a36bf96710, 0x7e4afa4b2f43aece, // set_reduce_ped_model_budget
0x75f1d57402c93ba, 0xc5befb84fe17d098,
0x78ebe9809ccd637, 0x581ae7724acad410,
0xbd12c5eee184c337, 0x7ae3e4d676c8b253, // responding_as_temp
0xe11ebbb2a783fe8b, 0x7bf4e9f6e1fb7a03, // network_get_friend_name
// 0x5c41e6babc9e2112, 0x0, // _0x5c41e6babc9e2112
0x422d396f80a96547, 0xd56cd7c03ecc9cf7,
0xfcc75460aba29378, 0xffc12db0dd7f299e,
0x7afe8fdc10bc07d2, 0xc1421fe548096204, // task_sweep_aim_position
0xe6de0561d9232a64, 0x5663b1b2e6dade19,
0xa905192a6781c41b, 0xc44b42cc99839799, // _0xa905192a6781c41b
0x271c9d3aca5d6409, 0xb78c0f3c680477d1, // _0x271c9d3aca5d6409
0x84ed31191cc5d2c9, 0x352bc1ac0be886ce,
0x399685db942336bc, 0x2a5c37131a0177ec, // get_key_for_entity_in_room
0x9f3f689b814f2599, 0x8d54c34a115696e6, // _0x9f3f689b814f2599
0x694e00132f2823ed, 0x79fb014658220dab, // _set_used_by_player
0xff4803bc019852d9, 0x9904817151037d6c, // _0xff4803bc019852d9
0xbffeab45a9a9094a, 0xf2d53aa87148aced, // net_to_ent
0x855bc38818f6f684, 0x7dec10d4da1dcc2c,
0xf45352426ff3a4f0, 0x6bd9a45c73ea0684, // _0xf45352426ff3a4f0
0x91d6dd290888cbab, 0x8ad0fdc5de116e81,
0x46b05bcae43856b0, 0x13dd550e1339fc91, // _0x46b05bcae43856b0
0x53409b5163d5b846, 0x53d1b27eced11891, // _get_vehicle_model_down_force
// 0xa660faf550eb37e5, 0x0, // _0xa660faf550eb37e5
0xb44250aaa456492d, 0xc25e4f10960e9afd, // set_particle_fx_looped_scale
0xf2eac213d5ea0623, 0xe210dc4e1046d625,
0x7a42b2e236e71415, 0x254e082d8f6a79a6,
0x4ada3f19be4a6047, 0xef4300dea48d446b, // _set_ped_talk
0xc8b5c4a79cc18b94, 0x27f669948d79d729, // _0xc8b5c4a79cc18b94
0x387ead7ee42f6685, 0xbc4506127ec35620, // add_navmesh_required_region
0x13127ec3665e8ee1, 0x2faa2f0322c319fc, // set_blip_show_cone
0x944955fb2a3935c8, 0x13157a56158089d8,
0xcedabc5900a0bf97, 0x9af6f2ee6fc1f9e8, // is_ped_jumping
0xdbc631f109350b8c, 0x9e86fe28a241dcab, // _0xdbc631f109350b8c
0x2a8bec6fd9af660, 0xca24df9f825c8df9, // _0x02a8bec6fd9af660
0x9a665550f8da349b, 0xf552446245609ead, // _set_cargobob_pickup_magnet_active
0x2587a48bc88dfadf, 0x9f8b0970d1b05742, // _0x2587a48bc88dfadf
0xa56f01f3765b93a0, 0xce04ce961af41ab9, // clear_area
// 0xbf72910d0f26f025, 0x0,
0x1461c72c889e343e, 0x307338788940e900, // start_rope_winding
0xa19435f193e081ac, 0x344f2893fa037279, // get_vehicle_colours
0x53fa83401d9c07fe, 0xc4f7f214732f1731,
0x11b56fbbf7224868, 0xefd6224850ac6eff, // preload_cloud_hat
0x66b57b72e0836a76, 0x473718d558df176, // set_ped_can_be_targetted_by_player
0x968f270e39141eca, 0x404ca2534a5bc6ef,
0xe0130b41d3cf4574, 0xfff760d16659ca06,
0xab935175b22e822b, 0xffb467183fee27c4, // is_this_model_a_train
0xc5042cc6f5e3d450, 0xa80721fdc3bdccdb,
0x78f06f6b1fb5a80c, 0x82417430ec099aa3, // _object_value_get_integer
0x6c60394cb4f75e9a, 0x84a1867c71c35177, // set_ped_alternate_walk_anim
0xd04fe6765d990a06, 0xbad6437ef4293635, // task_ped_slide_to_coord
0xc32779c16fceecd9, 0xc87d718f567156be, // set_ik_target
0x1dd5897e2fa6e7c9, 0x45686374c0ee55d0,
0x1dbd58820fa61d71, 0x95bbe5c8d52fe24b, // is_entity_upsidedown
0x7524b431b2e6f7ee, 0xb1c9f0d3aac0d517, // network_remove_transition_invite
0xa9240a96c74cca13, 0x2157c7030f2dcaa6, // _0xa9240a96c74cca13
0x2982bf73f66e9ddc, 0xe1e76f5934c3ed99, // set_tv_volume
0x487eb90b98e9fb19, 0xf8c88c1292e1b089, // texture_download_release
0x20e330937c399d29, 0xe696cc9baf2a66f9, // waypoint_playback_start_aiming_at_ped
0x5e346d934122613f, 0xf9fb5255747dbe88,
0x47c2a06d4f5f424b, 0x90d54dcf679c0bbe, // get_room_key_from_entity
0x2b1813aba29016c5, 0x69c2098329a2f505, // _network_set_network_id_dynamic
0x6ba428c528d9e522, 0xad9448dc96710683, // set_ped_max_time_underwater
0x81592be4e3878728, 0xa60926b1795990f3, // get_vehicle_mod_color_2
// 0xeb078ca2b5e82add, 0x0, // _0xeb078ca2b5e82add
0xa01bc64dd4bfbbac, 0x96240a9234a47cf3, // _0xa01bc64dd4bfbbac
0x9541d3cf0d398f36, 0x99d60d17e2820498, // create_weapon_object
0xee68096f9f37341e, 0x6b7ee7681161bcab,
0x4b33c4243de0c432, 0x353711570a4fae35, // stat_set_bool
0xac26716048436851, 0x246c08f157259979, // draw_poly
0x77168d722c58b2fc, 0x89f3c8ab1fea591b, // set_particle_fx_non_looped_alpha
0xe98f88a24c5f4b8, 0xfb54ea4e40bd5e6b, // clear_ped_last_weapon_damage
// 0x9c4ab58491fdc98a, 0x0, // network_do_transition_quickmatch_with_group
0x3a52ae588830bf7f, 0xc51b09215c6f32b, // create_model_hide_excluding_script_objects
// 0xafe08b35ec0c9eae, 0x0, // network_pay_utility_bill
0xc141b8917e0017ec, 0xa419ef70d134b1e4,
0xba291848a0815ca9, 0xeed5625db4f88798, // is_vehicle_tyre_burst
0x650a08a280870af6, 0xa904e41046d3ad46, // network_buy_property
0xc38dc1e90d22547c, 0x87eb94eab987f34f, // _0xc38dc1e90d22547c
0xd8c3be3ee94caf2d, 0xfb8ef66c2f0b1429, // _0xd8c3be3ee94caf2d
0x46e571a0e20d01f1, 0x8f6c3dd0bb146ca3, // is_vehicle_window_intact
0xae540335b4abc4e2, 0xbeed7afe60b58174, // set_player_melee_weapon_defense_modifier
0xaabb1f56e2a17ced, 0x7049f65f85106838, // set_hud_component_position
0x8e2530aa8ada980e, 0x3c990c409b3845de, // set_entity_heading
0x9a3ff3de163034e8, 0xa46cf85a531f2e63,
0xbf25eb89375a37ad, 0xd2e80177f27fd43f, // set_relationship_between_groups
0x6d4cb481fac835e8, 0x680b21616000a5b2, // _0x6d4cb481fac835e8
0x6db47aa77fd94e09, 0x46c53b6318bb9a15, // set_run_sprint_multiplier_for_player
0x4b7620c47217126c, 0x36effac4b2670876, // set_weapon_smokegrenade_assigned
0x2f844a8b08d76685, 0x3c05a6d663ea1b6a, // request_script_audio_bank
0xf6e48914c7a8694e, 0xbb698266c5fdf0a7, // begin_scaleform_movie_method
0x8020a73847e0ca7d, 0x30f43a3b001cb8e4,
// 0xc74c33fca52856d5, 0x0, // network_session_host_single_player
0xca575c391fea25cc, 0x52a6660af6c1f79a, // _0xca575c391fea25cc
0x239a3351ac1da385, 0xc7c47d4054903839, // set_entity_coords_no_offset
0xd2936cab8b58fcbd, 0x6166312074d1874c, // _0xd2936cab8b58fcbd
0xc3330a45cccdb26a, 0xd06ed73433d0279b, // get_cam_fov
0xe625beabbaffdab9, 0x7e15d709e86eb560,
0x84a2dd9ac37c35c1, 0xbc2fc12ad0fbf72e, // is_ped_injured
0xdace671663f2f5db, 0x821d9c8ea372b2f8, // decor_get_bool
0x3548536485dd792b, 0x512e6ad7763520c1, // assisted_movement_remove_route
0xeb9dc3c7d8596c46, 0x4459178baf2918e1, // set_vehicle_tyres_can_burst
// 0x30785d90c956bf35, 0x0, // can_shuffle_seat
0x1017582bcd3832dc, 0xa1327c0b561cac70, // get_current_ped_vehicle_weapon
0x16160da74a8e74a2, 0xb375a00b7c2910a5, // texture_download_request
0x9ebc85ed0fffe51c, 0x91962ec406944b72, // _set_entity_collision_2
0x837155cd2f63da09, 0x5010bc506444793e, // set_blip_route_colour
// 0x96ef97daeb89bef5, 0x0, // set_particle_fx_shootout_boat
0xb2d06faede65b577, 0x6dd92cc717e9e506,
0xe842a9398079bd82, 0xf49ce76edd20927e, // _0xe842a9398079bd82
0x4202bbcb8684563d, 0x1c795e4cf66995ad,
0x21442f412e8de56b, 0x3b2688f6d3b4ebd8, // special_frontend_equal
0xf5846edb26a98a24, 0x90f10e76e550cc52, // _0xf5846edb26a98a24
0xa9f9c2e0fde11cbb, 0x46c89fd8e60d8a4d, // get_shop_ped_outfit_prop_variant
// 0x9245e81072704b8a, 0x0, // _0x9245e81072704b8a
0xaddd1c754e2e2914, 0xe2027c206547a60a, // _0xaddd1c754e2e2914
// 0xf083835b70ba9bfe, 0x0,
0xf92691aed837a5fc, 0x35364ef44beb123b, // set_exclusive_phone_relationships
0xc8f3aaf93d0600bf, 0x5018c4a66272ae1d, // _draw_notification_unlock_2
0xe48d1c262390950, 0x32442850d1ef7db6, // get_total_duration_of_vehicle_recording
0x3fc694ae06c5a20, 0x36296f11e96e764d,
0x95eed5a694951f9f, 0x67f8a06049221c80, // get_entity_upright_value
0xc84527e235fca219, 0x7f805ea2edc8412a, // _0xc84527e235fca219
0xa7e4e2d361c2627f, 0xeb889e34636010a2,
0x66e0276cc5f6b9da, 0xbed53673591d764e, // set_text_font
0x74d4e028107450a9, 0x57930a6a2feca598, // remove_ped_defensive_area
0x4e72bbdbca58a3db, 0x9fc6d31828023749,
0x9780f32bcaf72431, 0xd1711b2012ed60d8,
0x673966a0c0fd7171, 0x5a4d875d71edecde, // create_ambient_pickup
0xe5b302114d8162ee, 0x9d3043c4d175a55e, // set_driveby_task_target
0x6faacd625d80caa, 0xbbdd9a94445caf1f, // network_register_entity_as_networked
0x6d6840cee8845831, 0x9da092ca251805f3, // _0x6d6840cee8845831
0x8d4d46230b2c353a, 0xb813dcbd5002bc42,
0xb6fbfd079b8d0596, 0xf36d05ed31d89296, // get_object_fragment_damage_health
0x888d57e407e63624, 0x6521432f7beac16c, // get_screen_resolution
0xd972df67326f966e, 0xdaa167234fc5d7ef,
0xd8fa3908d7b86904, 0xd8757f664b50d622, // set_cgoffset
// 0xab3caa6b422164da, 0x0, // network_can_spend_money
0x8b3ca62b1ef19b62, 0xa16aa4452fec4d2,
0x7ce1ccb9b293020e, 0xd614ebcffd919d, // get_vehicle_number_plate_text
0xdc9274a7ef6b2867, 0x83817ba764835b61,
// 0x2be4bc731d039d5a, 0x0, // _0x2be4bc731d039d5a
0x1077788e268557c2, 0x43e505744a9b715d,
0x57715966069157ad, 0x1cda2a3f20e6793a, // set_ped_enabled_bike_ringtone
0x23c3eb807312f01a, 0xb6982ea4c72feed3, // _set_blip_friend
0xa24da3a41b718f5, 0x6d39881ca5436178, // begin_text_command_is_this_help_message_being_displayed
0x7c4bb33a8ced7324, 0x6b5b900b02d42c0f, // playstats_mission_over
0x8c338e0263e4fd19, 0xb6065365472c28ec, // task_chat_to_ped
0x1e982ac8716912c5, 0x318780eba3e142a0, // set_ped_desired_move_blend_ratio
0xfb71170b7e76acba, 0x89ddaae6eff42dd9, // get_entity_bone_index_by_name
0xfdd179eaf45b556c, 0xc223020d5be76715, // get_wanted_level_threshold
0x61b6775e83c0db6f, 0xfd03e22c0c160f75, // remove_forced_object
0x11e65974a982637c, 0x2d0598fbfd4d8a23, // get_disabled_control_normal
0x469f2ecdec046337, 0xa7b62842bd58b5d2, // _0x469f2ecdec046337
0x87e5c46c187fe0ae, 0x8c8c13581ec12057, // _0x87e5c46c187fe0ae
// 0x8abfb70c49cc43e2, 0x0, // has_object_been_broken
// 0xef49cf0270307cbe, 0x0,
0x77e2dd177910e1cf, 0x1466a087f0134e36, // _set_player_blip_position_this_frame
0x131d401334815e94, 0x3771def507bf2843, // has_entity_been_damaged_by_weapon
0x57b192b4d4ad23d5, 0x7376bf9bab2c5fe4, // _network_chat_mute
0xda024bdbd600f44a, 0xf7421b91084d18aa, // _0xda024bdbd600f44a
0xb51194800b257161, 0x392f736ba9c4a337, // create_cam_with_params
0xa5272ebedd4747f6, 0xfcff58a8aa41681b, // disable_stunt_jump_set
0x8421eb4da7e391b9, 0xc1cd838508970ab1, // set_ped_preferred_cover_set
0xd796cb5ba8f20e32, 0xa4b2b44cd064704, // is_entity_visible_to_script
0xf9034c136c9e00d3, 0xb98788b42580c4a8, // does_scenario_group_exist
0xe2c9439ed45dea60, 0x8adcd6a9e17a45c0,
0x92790862e36c2ada, 0xce123b46f240864f,
0xff300c7649724a0b, 0x808abfb69c8b397, // _0xff300c7649724a0b
0x2d34fc3bc4adb780, 0x612efca65ba8c250, // are_any_vehicle_seats_free
0x65d2ebb47e1cec21, 0x88b04627b159d024, // _0x65d2ebb47e1cec21
0xa8733668d1047b51, 0xfcc88bc8a5415476, // _0xa8733668d1047b51
0x29de5fa52d00428c, 0x383c10b853259113, // start_playback_recorded_vehicle_using_ai
0x4f7d8a9bfb0b43e9, 0x1c316779e36c1967, // set_blip_route
0x4805d2b1d8cf94a9, 0x43d8a2ccb19fe8a8, // get_entity_velocity
0x78c4e9961db3eb5b, 0x856e708144bcb2be, // _0x78c4e9961db3eb5b
// 0x68772db2b2526f9f, 0x0, // _0x68772db2b2526f9f
0xdba71115ed9941a6, 0x3309862cd9166e87, // set_ped_alertness
0xaeedad1420c65cc0, 0xfa5af2f07eb0bca4, // _set_force_ped_footsteps_tracks
0x762db2d380b48d04, 0xb3c900d83c30061f, // _0x762db2d380b48d04
0xba8d65c1c65702e5, 0xf90cef268073d76d, // _0xba8d65c1c65702e5
0x2595dd4236549ce3, 0x1f45b4626ac4a4c0, // set_ped_as_no_longer_needed
0x1a898d26e2333dd, 0x9b60f55261702f28, // set_ped_min_move_blend_ratio
0x1c7302e725259789, 0x1676debf1f768296, // does_text_block_exist
// 0xd0bc1c6fb18ee154, 0x0, // _0xd0bc1c6fb18ee154
0xd05d1a6c74da3498, 0x71dec55038caa420, // _0xd05d1a6c74da3498
0x487eb21cc7295ba1, 0x4ff8f6d30bfbb224, // set_vehicle_wheel_type
0xee08c992d238c5d1, 0xa5f1549010780d92, // stop_anim_playback
0x845bad77cc770633, 0x82d28e74add05e99, // attach_tv_audio_to_entity
0xc843060b5765dce7, 0x586d7fc3933035a3, // asin
0x423e8de37d934d89, 0xd470a4e16e9aae0e, // is_vehicle_model
0xb4c7a93837c91a1f, 0x3361fd929ddb3391, // get_livery_name
// 0x5389d48efa2f079a, 0x0, // rope_convert_to_simple
0x6ddbbdd98e2e9c25, 0x532ed5e669993a8a,
0xdfebd56d9bd1eb16, 0xcf33fe51707573db, // play_police_report
0x5ae99c571d5bbe5d, 0x9269a9cfc145847, // trigger_script_event
0xe57397b4a3429dd0, 0x342f0653a34c36a1, // network_session_get_inviter
0x8de69fe35ca09a45, 0x6e4dfdf8efb7ad50, // get_group_size
0x5b17a90291133da5, 0x33854b8151b6d8ec, // cancel_music_event
0x8e2a065abdae6994, 0xff10cbdb91edf5c7,
0xbb7454baff08fe25, 0x354fd6501f10a4e7, // _set_focus_area
0xc8b1b2425604cdd0, 0xe058a75bd0a36e9d,
0xae31e7df9b5b132e, 0x7ac4b5350a148805, // get_is_vehicle_engine_running
0x5debd9c4dc995692, 0xc1211e49c00d1c35,
0xe2a2aa2f659d77a7, 0x77c4189a8e5c57c2, // task_vehicle_drive_to_coord
0xcf61d4b4702ee9eb, 0x81457629db148f89,
0x9aa46badad0e27ed, 0x2b4b42c5c6db4ec5,
0x2b694afcf64e6994, 0xcd42674328240d82, // _0x2b694afcf64e6994
0x34ad89078831a4bc, 0x9f9b47d8ab616a7c,
0x690a61a6d13583f6, 0xea9515e911ee0b7d, // _0x690a61a6d13583f6
0x176852acaac173d1, 0xcef6f51659d2c82f, // playstats_shop_item
0x961777e64bdaf717, 0xed3f08f762aaa55a,
// 0xbd605b8e0e18b3bb, 0x0,
0x2cda538c44c6cce5, 0x6c6fe09e055d0855, // remove_shocking_event
0x84436ec293b1415f, 0xaa6e27cd97db9489, // set_random_boats
0x494e97c2ef27c470, 0xe6a7ce90720b9037,
0xeea5ac2eda7c33e8, 0xa4ee7d490eb4e0c9, // _are_coords_colliding_with_exterior
0xd0e9ce05a1e68cd8, 0x94424920fdb82b9a, // detach_vehicle_from_any_tow_truck
0xb6c987f9285a3814, 0x19e546f93eab3d29, // task_climb_ladder
// 0xffe1e5b792d92b34, 0x0,
0x90a43cc281ffab46, 0x32321d8034c7b162, // set_ped_alternate_movement_anim
0xb264c4d2f2b0a78b, 0x220d31ccc935fd25, // _0xb264c4d2f2b0a78b
0xfb680d403909dc70, 0xf4f81eb8e125e38, // _0xfb680d403909dc70
0xe4299c549f0d1f1, 0xfb1409eb89cb47f6, // _0x0e4299c549f0d1f1
0x774bd811f656a122, 0x75b136ce1e1ef4a5, // _0x774bd811f656a122
// 0xf1e22dc13f5eebad, 0x0, // _0xf1e22dc13f5eebad
0x524ff0aeff9c3973, 0xa2e38584d0f6a710, // _0x524ff0aeff9c3973
0xb98236caaecef897, 0xe5e1faca903fc02d, // set_this_script_can_remove_blips_created_by_any_script
0x9baddc94ef83b823, 0xcdd9b935b318821e,
0xbda07e5950085e46, 0xe4f4de6178ab3fc1, // set_ambient_zone_state
0x6f8838d03d1dc226, 0x1d8d48272a2b8f0f, // add_door_to_system
0xda488f299a5b164e, 0x2d2cbffe065b67ef, // get_posix_time
0xfc309e94546fcdb5, 0x7ce963225290425b, // _is_in_loading_screen
0x7eef65d5f153e26a, 0x4a83e23be6bca7b0, // is_cop_vehicle_in_area_3d
0xcd5003b097200f36, 0xb06f4a08bf57e69a, // get_dead_ped_pickup_coords
0x93e0db8440b73a7d, 0x5aa3fb798f8141cb, // get_random_vehicle_node
0x899ba936634a322e, 0x59aecbdfe1cc0576, // _get_des_object_state
0x35edd5b2e3ff01c0, 0xc2311fdc547e0372,
0x71862b1d855f32e1, 0x3976d3caa943b599, // playstats_random_mission_done
0xc7034807558ddfca, 0x1f9008563d0e9235,
0xb5d45264751b7df0, 0xa953eebeee013deb, // set_vehicle_indicator_lights
0x3e8d3d5f549087a, 0xfef5f9bb57ea2e8d, // get_model_dimensions
0x723538f61c647c5a, 0x7bb1c74d0db792e0, // update_ped_head_blend_data
0x1d408577d440e81e, 0xcbdc8bc7a589c76e, // set_time_scale
0xaf7b437918103b3, 0x5fd15d8c55c3753d, // _set_first_person_cam_near_clip
0x8c4f3bf23b6237db, 0x907b30ce344d8cf5, // _0x8c4f3bf23b6237db
0xdf7e3eeb29642c38, 0xea1fa7fa22741629, // _0xdf7e3eeb29642c38
0x2763bbaa72a7bcb9, 0x8c9a590a381d04d9, // network_is_activity_spectator_from_handle
0x3f9f16f8e65a7ed7, 0x9f008e72168604c, // get_player_sprint_stamina_remaining
0xdd79df9f4d26e1c9, 0x5e3e2bdd5b99ffe8,
0x7dce8bda0f1c1200, 0xd084701173607f29, // is_ped_in_parachute_free_fall
0xe8d65ca700c9a693, 0xdb9a1e6f325ed5f3, // get_vehicle_mod_color_1
0xb3cd58cca6cda852, 0x762685e29d15382e,
0x89221b16730234f0, 0xde2b6b8e125b5921, // task_perform_sequence_from_progress
0x237d5336a9a54108, 0xf75ca319d18511d7, // _0x237d5336a9a54108
0xa86911979638106f, 0x14e8777a5f3a98ee, // _end_text_command_timer
0xad9e8f87ff7c16f, 0xd47eb38f463b3441, // _0x0ad9e8f87ff7c16f
0x583049884a2eee3c, 0x4506dcab2b1e5d8c,
0x503f5920162365b2, 0x2bedf878822835ad, // _0x503f5920162365b2
0x4d86cd31e8976ece, 0x847bbefde097f8cd, // network_has_invited_gamer
0xfd325494792302d7, 0x2f13877185728a69, // set_time_exclusive_display_texture
0x478dcbd2a98b705a, 0x10e324db302f7e38, // network_attach_synchronised_scene_to_entity
0x8753997eb5f6ee3f, 0xa7af4a84db2c37c0, // clear_player_parachute_model_override
// 0xe6b7b0acd4e4b75e, 0x0,
0x729072355fa39ec9, 0x8b76d954998c9e96, // is_any_speech_playing
0xb0cc10720653f3b, 0x6e96652563265de1,
0x6f6f290102c02ab4, 0xbf11c8a43770c598, // set_blip_as_friendly
0x991549de4d64762, 0xfb2062b880af8075, // network_get_entity_is_local
0x92d6a88e64a94430, 0xbaae4edebaec4378, // stop_synchronized_audio_event
0xf488c566413b4232, 0x30b71495b533b7bd, // _0xf488c566413b4232
0x655185a06d9eeaab, 0xd6bb9b31765dfa24, // stat_get_masked_int
0x997abd671d25ca0b, 0xf0d230fb550cd6eb, // is_ped_in_any_vehicle
0x2a56c06ebef2b0d9, 0xee199bcffa2081a1, // _0x2a56c06ebef2b0d9
0xe9ea16d6e54cdca4, 0x8e33b3642a0875af, // _0xe9ea16d6e54cdca4
0x17df68d720aa77f8, 0x9a33c141339f9d94, // _0x17df68d720aa77f8
// 0xf1b9f16e89e2c93a, 0x0, // set_next_desired_move_state
// 0x8a694d7a68f8dc38, 0x0, // _0x8a694d7a68f8dc38
0x8aafd0814722bc3, 0x6f3022d928b0b88, // get_train_carriage
0xe37b76c387be28ed, 0x622bbdf1f6b8f65b, // set_interior_active
0x5407b7288d0478b7, 0xb6ac6399d9375c3a, // _0x5407b7288d0478b7
0x56b94c6d7127dfba, 0xa4f84151a1212156, // _0x56b94c6d7127dfba
0xa75e2b6733da5142, 0xff2b1628730ef8c,
0xbd04e29640c9c12, 0x66d2f163ea29bdee, // is_ped_in_any_police_vehicle
0xab0f816885b0e483, 0xca12322d8fbbdbee, // is_explosion_in_sphere
0x97c65887d4b37fa9, 0xca42ef25f6e69d76, // _set_ai_blip_max_distance
0xad2d28a1afdff131, 0xd68f932dc1c3a0b2, // set_plane_turbulence_multiplier
0xe33d59da70b58fdf, 0x73e7a21fd53144ab, // is_sphere_visible
0xe8854a4326b9e12b, 0x99414fb2d30425c1, // open_sequence_task
0x1e98817b311ae98a, 0x4ed237e217ca92b9, // _0x1e98817b311ae98a
0xe70ba7b90f8390dc, 0xb1d6a7531021f925, // _waypoint_playback_start_shooting_at_ped
// 0x5bd5f255321c4aaf, 0x0, // _0x5bd5f255321c4aaf
0xce07b9f7817aada3, 0xb76c47ac7538fba, // set_player_weapon_damage_modifier
0x18eb48cfc41f2ea0, 0xa6e32819044bbb6a, // _0x18eb48cfc41f2ea0
0x11b499c1e0ff8559, 0x25b654b37c646e7e, // was_ped_skeleton_updated
0xa13c11e1b5c06bfc, 0xf3a9252385b53547,
0x35e0654f4bad7971, 0x52122dc050bb832b, // _0x35e0654f4bad7971
0xdc7cabab1e9b67e, 0x43d47ad82da3c6ec, // set_entity_load_collision_flag
0xd6a86331a537a7b9, 0x96154df4e29a9998, // is_ped_prone
0x6b0e6172c9a4d902, 0xa0924848fcf7be0e, // _0x6b0e6172c9a4d902
0x4852fc386e2e1bb5, 0x1195572ace2c160a, // _get_hair_color
0xc361aa040d6637a8, 0x9482ffb62c51300, // _0xc361aa040d6637a8
0x109697e2ffbac8a1, 0x79613679eef99c5c,
0x83cdb10ea29b370b, 0x548feb9052c36ffd, // task_play_anim_advanced
0xa699957e60d80214, 0x2376c50ee90f7639, // network_has_ros_privilege
// 0xdb34e8d56fc13b08, 0x0, // _0xdb34e8d56fc13b08
0xaa135f9482c82cc3, 0xa3eb09120e78ba4, // is_ped_active_in_scenario
0x1c9adda3244a1fbf, 0xa1db7aa6d905e3c9, // start_cutscene_at_coords
0x90b6da738a9a25da, 0xa507cea9c07cb1dc, // _set_some_vehicle_density_multiplier_this_frame
0x6a320535f5f0248, 0xeb047c531c2e7710, // _0x06a320535f5f0248
0x88795f13facda88d, 0xa693a1607a2a2f1c, // set_initial_player_station
0xded51f703d0fa83d, 0x474234fd6a8029f8, // lower_convertible_roof
0xcf1ce768bb43480e, 0x9457fb44ee8803ca, // _get_num_head_overlay_values
0xbdb6f89c729cf388, 0xa1f7f10622ba6250,
0xc594b315edf2d4af, 0xff615fa3b69d748d, // _0xc594b315edf2d4af
0x11db3500f042a8aa, 0x739461708028c973, // clear_angled_area_of_vehicles
0x2f057596f2bd0061, 0x8d36507114090b9,
0x6683ab880e427778, 0xa36a8cd53dc38048, // set_playback_speed
0xfeddf04d62b8d790, 0xab3532f046984b00, // _get_anim_duration
0x48621c9fca3ebd28, 0xf68c9c9a191f2b68, // _0x48621c9fca3ebd28
0x598803e85e8448d9, 0x9bdb17209f68d32d, // set_taxi_lights
0x8da95e8298ae772, 0xb303ed4e12a5f06, // task_shoot_at_entity
0xe2587f8cbbd87b1d, 0x1caa347a3c84c225, // is_disabled_control_pressed
0x61631f5df50d1c34, 0x4f761f5902d04a47, // _0x61631f5df50d1c34
0xb2aff10216defa2f, 0x4e363ee6f9d07e3d, // _0xb2aff10216defa2f
0x1ee7063b80ffc77c, 0xf699e61158861d53, // set_roads_back_to_original
0x4c7028f78ffd3681, 0x6c175d3534d25075, // set_vehicle_can_be_visibly_damaged
0x632e831f382a0fa8, 0xe32e5ee0a68ebf7a, // get_navmesh_route_result
0xd0082607100d7193, 0x14fc2f005d5fac17,
0xc8f4131414c835a1, 0xe839cb54eef3fa03, // register_bool_to_save
0x5b4e4c817fcc2dfb, 0x8be3f20792f38feb, // _get_gameplay_cam_rot
0xbcc29f935ed07688, 0xd57b9d3438c77a62, // get_player_headset_sound_alternate
0x5721b434ad84d57a, 0x61dfe32fb87bc784, // is_vehicle_stopped
0x4bc2854478f3a749, 0xc435e0463a2419cc, // _0x4bc2854478f3a749
0xa49c426ed0ca4ab7, 0x6284c38f0a9a7077, // set_special_ability_multiplier
0x1bf60a500e28887, 0xa81fe3d92ae2ac9, // network_has_control_of_entity
0xf733f45fa4497d93, 0xe63987d92e14d433, // special_ability_charge_large
0x7db53b37a2f211a0, 0xf1c8f02c202ef0a4,
0x444cb7d7dbe6973d, 0x117e3af62e6d5427, // set_create_random_cops_on_scenarios
0x9fd90732f56403ce, 0x7feb44ab59784b47, // decor_register
0x1033371fc8e842a7, 0x55a131bbb37b58a1, // _remove_speed_zone
0x4102c7858cfee4e4, 0x2a4dff8bf4a53ea1, // set_group_separation_range
0x1cce141467ff42a2, 0xdd84db7a3ae9fb33, // set_ped_can_smash_glass
0xfa91550df9318b22, 0xc60c28d3a2893957, // network_accept_presence_invite
0x796a877e459b99ea, 0x1590f668b03a0ce5, // _0x796a877e459b99ea
0x1612c45f9e3e0d44, 0x1c36b4e307889664,
0x15c40837039ffaf7, 0x7c475fa8d877007f,
0x589f80b325cc82c5, 0x289064cb38b560aa, // _0x589f80b325cc82c5
0xf2bebcdfafdaa19e, 0x802c54aa1c22a317, // _0xf2bebcdfafdaa19e
0x5cce68dbd5fe93ec, 0xcfa186e482f32e90, // _get_ped_as_group_leader
0x103991d4a307d472, 0xd0f81bf65194609f, // _set_gameplay_cam_raw_yaw
0x4337511fa8221d36, 0x2bdc2b9c951f4beb, // network_earn_from_not_badsport
0x95e3d6257b166cf2, 0xc5565c10067f0e40, // set_ped_density_multiplier_this_frame
0x5a556b229a169402, 0x881163108fa45c61,
0x2f09f7976c512404, 0x4141de783fb62352, // _0x2f09f7976c512404
// 0x2cfc76e0d087c994, 0x0, // network_session_friend_matchmaking
0x36f6626459d91457, 0xfa368cef76576f21, // _0x36f6626459d91457
0x332b562eeda62399, 0xb1d22ef03f3c44fa, // set_ped_to_load_cover
0x3C5FD37B5499582E, 0x5787B31B4578002B, //UNK3::_NETWORK_SHOP_BEGIN_SERVICE
0x39BE7CEA8D9CC8E6, 0x64875ABCC43EF9A8, //UNK3::_NETWORK_SHOP_CHECKOUT_START
0x17695002fd8b2ae0, 0xc88dce211da92c17, // stat_set_gxt_label
0x21bb0fbd3e217c2d, 0x4f009c7e2f1629e3, // get_rope_last_vertex_coord
0x3001bef2feca3680, 0xac585aaabd649ed,
0xa6db27d19ecbb7da, 0xe38e3cf1625a4145, // does_blip_exist
0x800dd4721a8b008b, 0x4a1a4733bfe10244, // can_register_mission_objects
0x327edeeeac55c369, 0x6948208804e0997,
0x3f6167f351168730, 0xde956657835d8a15, // add_pickup_to_interior_room_by_name
0x1c6cd14a876ffe39, 0x40c1f3276801777f, // task_put_ped_directly_into_melee
0xeb119aa014e89183, 0x1ae762afca271e67, // release_movie_mesh_set
0x8aa9180de2fedd45, 0x3585f648a5dbb11d, // _0x8aa9180de2fedd45
0x3288d8acaecd2ab2, 0x40a22cf588a191a1, // remove_pickup
0x6d955f6a9e0295b1, 0x986ff020e31b0bb8, // _0x6d955f6a9e0295b1
0xb346476ef1a64897, 0x9f4718fd61b07058, // is_entity_attached
0x249e310b2d920699, 0xc7fe3ddcfbe343de, // get_shop_ped_query_component
0x7f8413b7fc2aa6b9, 0x63a666b5708422b3, // network_set_keep_focuspoint
0xf46a1e03e8755980, 0x1695c978f2c2e1e, // _0xf46a1e03e8755980
0xb4f47213df45a64c, 0x558558a7cc4a67f0, // _0xb4f47213df45a64c
0x9870acfb89a90995, 0xea8cefb1f41e5992, // has_bullet_impacted_in_area
0x12534c348c6cb68b, 0xe09156665ec2d83b, // is_ped_a_player
0x49e937f18f4020c, 0x7826a583d163d837, // is_ped_in_current_conversation
0x91a0bd635321f145, 0xed061dfff6e0dc78, // _0x91a0bd635321f145
0x78d0b67629d75856, 0x3736e60ba1444149, // set_ped_visual_field_max_elevation_angle
0x736a718577f39c7d, 0x87d16920e9af6268,
0x702bc4d605522539, 0xd61d42ebde25b52b, // _0x702bc4d605522539
0xbdeb86f4d5809204, 0x81fc7bd80974c6ba, // _0xbdeb86f4d5809204
0x4c61b39930d045da, 0x5c54404722c0e3bd, // _0x4c61b39930d045da
0x5bca583a583194db, 0x79579a124f8f6e60, // _draw_spot_light_with_shadow
0x242b5874f0a4e052, 0xd94209e92e4acabe, // set_cam_spline_phase
0xa2746eeae3e577cd, 0x1503005c985c77f3, // animated_shake_cam
0x3d87450e15d98694, 0x819b6e76423ae494, // get_shape_test_result
0xeef059fad016d209, 0xe80842d7b53f8525, // get_entity_health
0x4701832b739dce5, 0xa68e6113f0b09aa0, // task_go_to_entity_while_aiming_at_coord
0x19853b5b17d77bca, 0xe45ad664299f8768, // _0x19853b5b17d77bca
0xd1f8363dfad03848, 0x4f34fa95e899603f, // _0xd1f8363dfad03848
0x467c11ed88b7d28, 0xe9efd15fa687efe8,
0x8c18e0f9080add73, 0x38a6890195dd00d1, // create_synchronized_scene
0x87f395d957d4353d, 0x600d54aee4f6d508, // network_am_i_blocked_by_player
0xc09f246abedd82, 0xd36e854645ff8736, // _get_vehicle_class_max_speed
0xde45d1a1ef45ee61, 0x14f2f7deb29f39a9, // _0xde45d1a1ef45ee61
0x602e548f46e24d59, 0xe177bad6e8b3082, // roll_up_window
0x301a42153c9ad707, 0xf5e08abec1d02b0c, // network_explode_vehicle
0x5f0f0c783eb16c04, 0x854f5f1e3a6fea55, // has_script_with_name_hash_loaded
0x318234f4f3738af3, 0xcda107f8bee35f40, // has_clip_set_loaded
0x81fa173f170560d1, 0xdd11e2ad1d0dfe2c,
0x23d69e0465570028, 0x4595ab61b9e9ff72, // _begin_text_command_objective
// 0x2d4259f1feb81da9, 0x0, // _0x2d4259f1feb81da9
0xbe520d9761ff811f, 0xcaf83728e096f7a0, // set_cg_at_boundcenter
0xe404bfb981665bf0, 0x4513250203410d11, // network_spent_hire_mugger
0xdc80a4c2f18a2b64, 0x86ba755e9519ec72, // set_player_parachute_pack_model_override
0x35736ee65bd00c11, 0x5b78ee936879124f, // get_texture_resolution
0x171df6a0c07fb3dc, 0x171df6a0c07fb3dc, // _0x171df6a0c07fb3dc
// 0x375e7fc44f21c8ab, 0x0, // _get_vehicle_attached_to_entity
0x28a04b411933f8a6, 0xefb7ae0ebb75405e, // enable_tennis_mode
0x83f969aa1ee2a664, 0xdaf93a0e27ee6fc7, // get_last_ped_in_vehicle_seat
0x9cb5ce07a3968d5a, 0xcbe6e2953ed9652d, // special_ability_deactivate_fast
0xe3433eadaaf7ee40, 0xea7ceac893af46c2, // get_is_multiplayer_brief
0xf8155a7f03ddfc8e, 0x8ce0c96bc1ee28c1, // _0xf8155a7f03ddfc8e
0xad5fdf34b81bfe79, 0xcb65b553402fc64d,
0x98efa132a4117be1, 0xc6cdb5f78f0e3592, // set_ped_name_debug
0x25361a96e0f7e419, 0xaa48ed2b7bd17d19, // _0x25361a96e0f7e419
0xdad37f45428801ae, 0x6b59932722922b69,
0x61e360b7e040d12e, 0xdb9204af4ad363e9, // task_go_straight_to_coord_relative_to_entity
0x937c71165cf334b3, 0x5cd7d91a0946ece0, // is_weapon_valid
0xc3ead29ab273ece8, 0x91d58e6a781ba56d, // _0xc3ead29ab273ece8
0x5b440763a4c8d15b, 0x4000d05dea5f0328, // set_gps_flags
0x701375a7d43f01cb, 0x5fee418ce11e6dde, // waypoint_playback_get_is_paused
// 0x24a49beaf468dc90, 0x0, // _0x24a49beaf468dc90
0x1761dc5d8471cbaa, 0xd80d1f664b3644b, // _0x1761dc5d8471cbaa
0xeb0a2b758f7b850f, 0xc4707630c8de50cf, // init_shop_ped_prop
0x54833611c17abdea, 0x8d50b2bef003ab31, // stop_playback_recorded_vehicle
0x5f9532f3b5cc2551, 0xd62c4419a41f106a, // is_entity_dead
0x51455483cf23ed97, 0xc517890387f4ae4, // get_ped_as_group_member
0x6adaabd3068c5235, 0xf539e707734ebce5,
0x6647c5f6f5792496, 0x61d0e1067ee522fe, // _0x6647c5f6f5792496
0x79d3b596fe44ee8b, 0x62b7b895d641dc81, // set_vehicle_dirt_level
0xfbd96d87ac96d533, 0xf8600b0c544d4018, // call_scaleform_movie_method
0xa2716d40842eaf79, 0x803f8e0571f1c7cb,
0xc6b9db42c04dd8c3, 0xe7c84bae30b534e0, // _get_num_forced_components
0x66e49bf55b4b1874, 0x1bacaf4960590de1, // get_number_of_passenger_voice_variations
0xe791df1f73ed2c8b, 0xd4bc88afedfe0b01, // _0xe791df1f73ed2c8b
0xbe31fd6ce464ac59, 0x9c47e5cdfb45f474, // clear_area_of_peds
// 0x413c6c763a4affad, 0x0, // set_ped_defensive_area_direction
// 0x8416fe4e4629d7d7, 0x0, // _0x8416fe4e4629d7d7
0x1297a88e081430eb, 0x54597fcc2c99b4c2, // is_vehicle_in_burnout
0xee09ecedbabe47fc, 0x1f05c8353d145f77, // set_wind_speed
// 0x49da8145672b2725, 0x0,
0x81404f3dc124fe5b, 0xeb598431130e6913, // network_money_can_bet
0x1353f87e89946207, 0xa71a137e08393e8f,
0x8d67489793ff428b, 0x736b4e2fb1378f4f, // find_radio_station_index
0xad738c3085fe7e11, 0xd21e1fde062ed99, // set_entity_as_mission_entity
0x523c79aeefcc4a2a, 0x2927f8fd293eac6e, // clear_ped_damage_decal_by_zone
0x1899f328b0e12848, 0x2ca911e7569d12ea, // get_offset_from_entity_in_world_coords
0x452736765b31fc4b, 0x478c59459936fe7a, // add_police_restart
0xf11bc2dd9a3e7195, 0x4fd199dd0b583f5c, // get_vehicle_number_plate_text_index
0xcfc8be9a5e1fe575, 0x6b091f0028e6fe5f, // control_landing_gear
0x2302c0264ea58d31, 0xae5f29036a361832,
0x919b3c98ed8292f9, 0xc44d97db6e9ffd47, // _0x919b3c98ed8292f9
0xc8b189ed9138bcd4, 0xc695d6c525c63108, // terminate_thread
0x595f028698072dd9, 0x59d656dcc6383e85, // _0x595f028698072dd9
0x3998b1276a3300e5, 0xa0c0fec3ca7b61eb, // is_ped_aiming_from_cover
0xd7d0b00177485411, 0x4e33425bc2b33d57, // _0xd7d0b00177485411
// 0xebd0edba5be957cf, 0x0, // _0xebd0edba5be957cf
0xe952d6431689ad9a, 0x5b436f87d9030c6c, // clone_ped_to_target
0xb50eb4ccb29704ac, 0x42468a607e5743, // _0xb50eb4ccb29704ac
0x9a987297ed8bd838, 0x877efffa3185c8ef, // _switch_crime_type
0x742b58f723233ed9, 0x40909de15107fae6, // _0x742b58f723233ed9
0xf75497bb865f0803, 0xd66237e070521884, // point_cam_at_coord
0xd7c10c4a637992c9, 0x47cbea8fa1668fe7,
0x9346e14f2af74d46, 0xec48e56c631256c9, // network_pay_match_entry_fee
0xc5574e0aeb86ba68, 0x88c17bfd301f41fa, // get_random_vehicle_front_bumper_in_sphere
0xb5485e4907b53019, 0x586cb4f2dd231da3, // set_ped_wetness_enabled_this_frame
0x7fd2990af016795e, 0x7fd2990af016795e, // _0x7fd2990af016795e
0x46718aceedeafc84, 0x5a4fe84e6cf75d31,
0xde03620f8703a9df, 0x4b8ea98f4bb95102,
0xcde5e70c1ddb954c, 0x83ff9fa196577c82, // set_vehicle_alarm
0xd95e79e8686d2c27, 0xc6a1ec79d232d93c, // get_control_value
0xdedf1c8bd47c2200, 0x938726b4c904dce6, // get_vehicle_class_from_name
0x78c0d93253149435, 0x8727fd624a964290,
0x9c51349be6cdfe2c, 0xe804dc20cdee85bb, // leaderboards_get_cache_exists
0x5fbae526203990c9, 0xb4d430a4d2fdc831,
0x4455517b28441e60, 0x3c4f26adf3bee70b, // set_ped_path_avoid_fire
0x9dce1f0f78260875, 0xb95ed446e2876ea8, // enable_alien_blood_vfx
0x1098355a16064bb3, 0xa184a5d3685dbb01, // set_mobile_radio_enabled_during_gameplay
0x6f4c85acd641bcd2, 0x86349daf6ef60333, // get_seat_ped_is_trying_to_enter
0x2b3334bca57cd799, 0xed3f2982ca0d57fb, // _shape_test_result_entity
0x8d30f648014a92b5, 0x184d003abde76ad2,
0xcd17b554996a8d9e, 0x6401d6f51916495e, // set_ped_primary_lookat
0x8ee6b53ce13a9794, 0x4f8b8959fefc0f7c, // get_water_height_no_waves
0x963d27a58df860ac, 0xb815670c37e03cde, // request_model
0xd2b32be3fc1626c6, 0xd14ef308fda3c950,
0xc8ca9670b9d83b3b, 0x62b89f553d356402, // advance_clock_time_to
0x3f52e880aaf6c8ca, 0x8b625d97cdf31961, // _0x3f52e880aaf6c8ca
0x9fbda379383a52a4, 0x8eb023915ceedb99, // set_cam_active_with_interp
0x2735233a786b1bef, 0x8f9fc0bd5cef6da9, // _0x2735233a786b1bef
0x75ac2b60386d89f2, 0xfaa544973ee6769a, // task_seek_cover_from_pos
0xa0cefcea390aab9b, 0xc37de1faa4df0373, // _0xa0cefcea390aab9b
// 0x26f49bf3381d933d, 0x0, // is_mission_creator_blip
0xf71de29ab2258f1, 0x576726cfeb85bd19, // playstats_friend_activity
0xb28b1fe5bfadd7f5, 0xadf37ed1048e7d51, // _0xb28b1fe5bfadd7f5
0xa9c8960e8684c1b5, 0xf8e07c228a90e953, // set_ped_money
0x539e0ae3e6634b9f, 0xec26f4bfc9942a0c, // delete_object
0xadbf060e2b30c5bc, 0x65f173513f5ef79c, // has_this_additional_text_loaded
0x7cdc8c3b89f661b3, 0x2a9cc91e805ac802, // _0x7cdc8c3b89f661b3
0x9824cff8fc66e159, 0xd643dac6b8abab9e, // get_vehicle_waypoint_progress
0xf5bed327cea362b1, 0x9641b16cd71c5d05, // _0xf5bed327cea362b1
0x16da8172459434aa, 0x33fb28d990016403,
0x9b0bb33b04405e7a, 0xe2e9548b5ee8d23c, // set_wanted_level_difficulty
0xa6928482543022b4, 0xd1bd12e5b2c8de66, // set_network_id_visible_in_cutscene
0x57d158647a6bfabf, 0x52119e312e15db07,
0x9b4bd21d69b1e609, 0x40398c2046a819b,
0x1e77fa7a62ee6c4c, 0x647623ac7be9a663, // _0x1e77fa7a62ee6c4c
0x51bb2d88d31a914b, 0xc1b2760da83a4df8, // _0x51bb2d88d31a914b
0xb16fce9ddc7ba182, 0xbb5e373390a5f824,
0x68103e2247887242, 0xb07257c0473d813,
0xf33ab75780ba57de, 0xdac4560b151e04a6, // stop_cam_pointing
0xeba5ad3a0eaf7121, 0xded58ea0593e8e71, // get_relationship_between_peds
0xb8bec0ca6f0edb0f, 0x2918fc6bdebf9834, // stop_current_playing_ambient_speech
0x8605af0de8b3a5ac, 0x1d19dc9f88fa67ee, // task_aim_gun_scripted_with_target
0xa2e9fdb9a8c62f6, 0xabe4dafdc3d49507, // get_entity_index_of_cutscene_entity
0x56cef0ac79073bde, 0x139c6344b571f912, // set_ped_dies_in_water
0x7ac24eab6d74118d, 0xb7966b225ebeee27, // _0x7ac24eab6d74118d
0x58bb377bec7cd5f4, 0xd47c0ace358bedbf, // _0x58bb377bec7cd5f4
// 0xbe3e347a87aceb82, 0x0, // network_session_activity_quickmatch
0x716b6db9d1886106, 0xa75bbeb9b947c365, // fillout_pm_player_list_with_names
0x6b83617e04503888, 0xc16e03d1d784281d, // start_script_fire
0x3b3d11cd9ffcdfc9, 0x6ccf71851e99e10e,
0x3f1a106bda7dd3e, 0xe376ad55514f6438,
0xa549c3b37ea28131, 0xdb6b6ce908f7b7af, // set_playback_to_use_ai
0xf9c36251f6e48e33, 0xc5f700e2df762917, // _is_pickup_within_radius
0xc30338e8088e2e21, 0x8c40dc84edf05997,
0x25129531f77b9ed3, 0xce6951dbe6a6a68e, // start_particle_fx_non_looped_at_coord
0x66e7cb63c97b7d20, 0x6a1a9678078d5b48,
0x9465e683b12d3f6b, 0xa0c03c1f783ad4c4,
0xd76b57b44f1e6f8b, 0x2a25aecbd792a364, // task_go_straight_to_coord
// 0x600f8cb31c7aab6e, 0x0, // _0x600f8cb31c7aab6e
0x9693b0312f91649, 0xa740bda5d754e881, // task_rappel_from_heli
0x6fa46612594f7973, 0xae5b044aa2973e2a, // task_look_at_coord
0x971d38760fbc02ef, 0x897ef720254bbea3, // set_ped_keep_task
0x76a18844e743bf91, 0xe4c91efcc8e1c2ef, // has_weapon_got_weapon_component
0x24b100c68c645951, 0xd60c17a5a48843c0, // is_ped_reloading
0xcb2d4ab84a19aa7c, 0x1923af7aaae7d2b9, // stop_rope_winding
0x6a3524161c502ba, 0x77f30d3c41aee850, // _0x06a3524161c502ba
0xed640017ed337e45, 0xb3230ac005068086, // _play_ambient_speech_at_coords
// 0xae032f8bba959e90, 0x0, // task_stand_guard
0xd77a82dc2d0da59, 0xa4b20a2942656e26, // _0x0d77a82dc2d0da59
0x31d1d2b858d25e6b, 0xc19c84884be9ae4c, // network_send_transition_gamer_instruction
0x29a28f3f8cf6d854, 0xc6dbe47f33ad19b2, // set_ped_strafe_clipset
0x38c1f517d7fdcf8, 0xc8d3d8174e443454, // set_text_proportional
0x2a251aa48b2b46db, 0xf5da4906bdd739fc,
// 0x6b38ecb05a63a685, 0x0, // network_spent_cinema
0xb80d8756b4668ab6, 0x96e4b8740065f6d8, // request_named_ptfx_asset
0x6d6af961b72728ae, 0xc734f59a13d39aef, // _0x6d6af961b72728ae
0xa11700682f3ad45c, 0x8370e68a3deeb1d3, // network_get_network_id_from_entity
0x67fc09bc554a75e5, 0x54f5a97e4602d0d0,
0xe832d760399eb220, 0x98e288be8ed8bb76, // add_rope
0xae99fb955581844a, 0x27e510dc69ca08b6, // set_ped_to_ragdoll
0x654cd0a825161131, 0x55c6611ff8b993c, // has_ped_head_blend_finished
0xa9a41c1e940fb0e8, 0x167979048b7ce51d, // disable_ped_pain_audio
0xbae4f9b97cd43b30, 0xc5ece124d2d72f13, // _0xbae4f9b97cd43b30
0xdb57b41ec1db083, 0x70418c66cb4c3f79, // get_weapon_component_type_model
0x272e4723b56a3b96, 0x19cc0f2e313baf2e, // attach_synchronized_scene_to_entity
0x5501b7a5cdb79d37, 0x723aceb736c4b797, // _0x5501b7a5cdb79d37
0x9a2d0fb2e7852392, 0x9cf0ce01225e626b, // play_cam_anim
0xc6ad107ddc9054cc, 0x18c744e56cce7557, // _get_vehicle_model_max_knots
0x77a84429dd9f0a15, 0xe688a76ca2618d5,
0xa571991a7fe6cceb, 0x69da4fccb5511ba4,
0xbf0fd6e56c964fcb, 0x697eba5cf1a6ab57, // give_weapon_to_ped
0x6c0e2e0125610278, 0x5c7617a25d50aae9, // network_get_player_index_from_ped
0x788e7fd431bd67f1, 0xda62453241f6fcb7, // _0x788e7fd431bd67f1
0xf19d095e42d430cc, 0x6e2bcd7113a5332b, // set_vehicle_out_of_control
0xf6df6e90de7df90f, 0xc8ddebb5d6790797, // set_object_physics_params
0x5e62be5dc58e9e06, 0x511f5283143463d7,
0xa87e00932db4d85d, 0x206c946c7aa76ce3, // set_gameplay_cam_shake_amplitude
0x11b5e6d2ae73f48e, 0xf0a07f7b2faae06, // stat_get_bool
0x7ee53118c892b513, 0x1d819cc3ebbf0bfb, // get_ped_config_flag
0x6f259f82d873b8b8, 0x69c45ea80d17d80f,
0x425aecf167663f48, 0x5ac3af52f52eea94, // _0x425aecf167663f48
0x5a5f40fe637eb584, 0x91ec70aa37ce99e8, // string_to_int
0xfdbf4cdbc07e1706, 0x89f38c325d9e03e7, // _add_current_rise
// 0x8a7b3952dd64d2b5, 0x0, // network_buy_fairground_ride
0x6d14ccee1b40381a, 0x26353a2c5c495694,
0x44fa03975424a0ee, 0x89fc119e73d94c9c, // _draw_notification_2
0xadf7be450512c12f, 0x5e860729661881ff, // detach_vehicle_from_any_cargobob
0x45e816772e93a9db, 0x118a3ba5dade9e2b,
0x25bc98a59c2ea962, 0xaf60e30b2cc603b2, // get_vehicle_door_lock_status
0xa23e821fbdf8a5f2, 0x86d5aef7a355b4a7,
0xc1aa9f53ce982990, 0x71157ed7fa33e551, // set_radio_auto_unfreeze
0xf3bbe884a14bb413, 0x615e8cce4183dfb7, // _get_weather_type_transition
0x3f9990bf5f22759c, 0x8d6c70f0ed4a4289, // _0x3f9990bf5f22759c
0x961ac54bf0613f5d, 0x35f11a916fdfcf32, // detach_entity
0xea16670e7ba4743c, 0x1221eeb46d483418,
0x399d2d3b33f1b8eb, 0x37c9b4b0237ed18f, // set_static_emitter_enabled
0xf166e48407bac484, 0x277716e9e7cc0692, // task_combat_ped
0xb60feba45333d36f, 0x4f8cf72358604361, // reserve_network_mission_peds
// 0xa986918b102b448, 0x0, // set_ped_motion_blur
// 0x4dcdf92bf64236cd, 0x0, // _0x4dcdf92bf64236cd
0xfd5448be3111ed96, 0xb3bcea52bd1e281a, // does_rope_exist
// 0x25d990f8e0e3f13c, 0x0,
0x520e541a97a13354, 0x71139c839487a2f9, // set_player_wanted_centre_position
0x7f6db52eefc96df8, 0xc2e237744ba0026, // is_this_model_a_car
// 0x14e0b2d1ad1044e0, 0x0, // _0x14e0b2d1ad1044e0
0xe054346ca3a0f315, 0x126a03bd41622048, // task_wander_in_area
0x5234f9f10919eaba, 0xfcc829113de3375e,
0xa1b043ee79a916fb, 0x174a37a95809b72c,
0x32c62aa929c2da6a, 0x11d1216d8f205785, // set_police_ignore_player
0xf25d331dc2627bbc, 0x28d5f9ac3e7bc48b,
0xb0f7f8663821d9c3, 0x90d2e06562d440e1, // get_interior_at_coords
0xa7dcdf4ded40a8f4, 0xc2648762eb817fb3, // _0xa7dcdf4ded40a8f4
0x1fd09e7390a74d54, 0x902cc10ed3851ca2, // _set_vehicle_lights_mode
0xc0d2af00bcc234ca, 0xe51f0c4e4b6665fe,
0x15337c7c268a27b2, 0xe6f35ecd6f6bb112, // network_am_i_blocked_by_gamer
0xe80492a9ac099a93, 0xce689a8e8c42ed78, // clear_bit
0xfec9a3b1820f3331, 0x64f4d3adb0e54125, // _0xfec9a3b1820f3331
0x54f157e0336a3822, 0x7f03e5f7ebbc277e, // _0x54f157e0336a3822
0x35f0b98a8387274d, 0x10831cc31db5a98,
0x531b84e7da981fb6, 0x8bde1a74ec1045a9, // _set_notification_message_clan_tag_2
0xdddf64c91bfcf0aa, 0x5afd478cb0cd741f,
0x8f5ebab1f260cfce, 0xc368b29f8fe045c3, // _get_vehicle_owner
0x972bc203bbc4c4d5, 0xf81b05c34b7e1d24, // _network_access_tunable_float_hash
0x5b11728527ca6e5f, 0x1b4635c3e329c1c5, // _object_value_add_array
0x3aad8b2fca1e289f, 0x470136b0d27e1f75, // network_do_transition_to_freemode
0xaaa34f8a7cb32098, 0x31826ef4a8bc8e9f, // clear_ped_tasks_immediately
0xa4dede28b1814289, 0x7e30a23e12e202ba,
0x8dc39368bdd57755, 0xe4b835fdc8b9b086, // attach_portable_pickup_to_ped
0x1a358d9128b7a86, 0x7ef4467b7d9c31f5,
0x2369d5c8a51fdcf, 0xd3506c8cb54f8003, // _0x02369d5c8a51fdcf
0xd82cf8e64c8729d8, 0x36d8569a54bac634, // is_sphere_visible_to_another_machine
// 0x6524a2f114706f43, 0x0, // _decor_get_float
0x51bc1ed3cc44e8f7, 0xeace1aa0d5fbd13, // _call_scaleform_movie_function_string_params
0xdc518000e39dae1f, 0x28243090e3d289cf, // delete_stunt_jump
0xc11c18092c5530dc, 0x72aea192a08fde07, // set_ped_can_head_ik
0xa4a0065e39c9f25c, 0x2aac8da650dc7f8, // _0xa4a0065e39c9f25c
0x41ca5a33160ea4ab, 0xe8ea62f4e406315e,
0xce94aeba5d82908a, 0xd43a4279ae5f281, // _get_text_substring_slice
0x7dbdd04862d95f04, 0xc408cc95c7202d67, // get_ped_relationship_group_hash
0x1ee0f68a7c25dec6, 0x2300f9671409ece5, // get_phone_gesture_anim_total_time
0x223ca69a8c4417fd, 0xdb00e17d0b126330, // get_hud_component_position
0xdf1af8b5d56542fa, 0x62466e3e4f8249a4, // set_enable_handcuffs
0xe369a5783b866016, 0x616a13e62da55e60, // enable_stunt_jump_set
0x5a1fe504b7f2587, 0xc20669b357a7dab6, // is_special_ability_meter_full
0xb043eca801b8cbc1, 0x46dfbe6be64a00ab,
// 0x12ded8ca53d47ea5, 0x0, // _0x12ded8ca53d47ea5
0xc0416b061f2b7e5e, 0x136d6164f9eb407, // _0xc0416b061f2b7e5e
0x805d7cbb36fd6c4c, 0x8247f85cbeb7fbaa,
0xc27e1cc2d795105e, 0x16ab569f1166496e, // _object_value_add_float
0x7fead38b326b9f74, 0xce47cab83b87e4b, // get_ped_ammo_type_from_weapon
0xfd55e49555e017cf, 0x3597107e70b7871e, // shake_gameplay_cam
0x83b8201ed82a9a2d, 0xe42b2590ab299f4d, // _0x83b8201ed82a9a2d
0x1f471b79acc90bef, 0xe09a17b45c102327,
0xc488ff2356ea7791, 0x37fbc14b2f5d54db, // get_profile_setting
0x2c654b4943bddf7c, 0xd670551460a518c8, // _set_cam_dof_max_near_in_focus_distance_blend_level
0x13ede1a5dbf797c9, 0xc2bbc4dbb5d99f40, // get_player_target_entity
0xe163a4bce4de6f11, 0xe44d3fee07a9ef2c, // set_ped_model_is_suppressed
0xfff3a50779efbbb3, 0x5288afafa6220688, // stop_rope_unwinding_front
0x4a9923385bdb9dad, 0xfd411b1045595d7d,
0x9f1935ca1f724008, 0xcd5a71947543ebc,
0x44f7cbc1beb3327d, 0x1b28573aad069a19, // set_dispatch_time_between_spawn_attempts
0x5845066d8a1ea7f7, 0x36e2f9bc44a29a6f, // _0x5845066d8a1ea7f7
0xd55ddfb47991a294, 0x976f5b3012a75dd1, // has_player_left_the_world
0x594a1028fc2a3e85, 0x33cd235df1e6a94e, // get_scripted_cover_point_coords
0xb165ab7c248b2dc1, 0x53f48527d958ed8d, // unlock_mission_news_story
0x4055e40bd2dbec1d, 0xc4de350111884249, // pause_clock
0xf1620ecb50e01de7, 0xc20b4c8627f71c3f,
0x94cf4ac034c9c986, 0xe64d2cf940b1bda5, // add_text_component_substring_website
// 0x44a0bdc559b35f6e, 0x0,
0xf44a5456ac3f4f97, 0x910ba09073170fc2, // _0xf44a5456ac3f4f97
// 0xc7f2de41d102bfb4, 0x0, // playstats_rank_up
0xee6c5ad3ece0a82d, 0xca569b59b8b12d63, // remove_ipl
0x3e5f7fc85d854e15, 0xb73bbe22563e911a, // is_special_ability_active
0xd5b4883ac32f24c3, 0xc680be2016833edd, // network_set_team_only_chat
0xe40c1c56df95c2e8, 0xef6624a3aff02a02, // register_entity_for_cutscene
0x4ec12697209f2196, 0x2e3bfd58410f58d0, // is_player_riding_train
0x593570c289a77688, 0xe7784f64a622fce,
0x7c313f94746702c, 0xbc9f465e12815b03, // _0x07c313f94746702c
0x90370ebe0fee1a3d, 0x83fbeb2125f494fc, // create_group
0xcb4e8be8a0063c5d, 0xb6596c29f3179d0c, // get_is_waypoint_recording_loaded
0xa5b769058763e497, 0x57aadb985f82265d, // get_waypoint_distance_along_route
0xe26ccff8094d8c74, 0xa107c7163400bb87, // using_network_weapontype
0x54318c915d27e4ce, 0x5f26734e3288784f, // _0x54318c915d27e4ce
// 0x137bbd05230db22d, 0x0, // set_ped_blend_from_parents
0x228e5c6ad4d74bfd, 0x85b2951080203c53, // _0x228e5c6ad4d74bfd
0x8415d95b194a3aea, 0xc94027b99346140a,
// 0x324c5aa411da7737, 0x0,
0xf25e02cb9c5818f8, 0x8013ead850bfb276,
0x7a73d05a607734c7, 0xfa145fad9b58b8bb, // _set_ped_mute
0xb629a298081f876f, 0xd7bb6ec772196237, // waypoint_recording_get_closest_waypoint
0x7e782a910c362c25, 0xb3e500dc5fbdf332,
0x965fec691d55e9bf, 0x32d536ee44da1626, // task_plant_bomb
// 0x9fda1b3d7e7028b3, 0x0, // task_use_nearest_scenario_chain_to_coord
0x784002a632822099, 0x8a391080a847d9e1, // _0x784002a632822099
0x110f526ab784111f, 0x4607f48dd1b9b739, // _0x110f526ab784111f
0x7504c0f113ab50fc, 0xa22bb3f7ce1bfb3c, // is_taxi_light_on
0xa9cbfd40b3fa3010, 0xa692b06ea7807dc4,
0x4172393e6be1fece, 0x7cf15cbddf414ef0, // task_put_ped_directly_into_cover
0xf36199225d6d8c86, 0x7e08b97617de5b5e, // _set_cloud_hat_opacity
0x70a2d1137c8ed7c9, 0x33f6be48e356da27, // set_ped_flee_attributes
0x4c89fe2bdeb3f169, 0x87adc36665993886,
0xcf54f20de43879c, 0x1eba51cc041f41af, // _0x0cf54f20de43879c
0xaded7f5748acafe6, 0x4c1ac578b703f8fb,
0xde350f8651e4346c, 0x767441a2e27d3bf3, // is_time_more_than
0x2365c388e393bbe2, 0x361a6316385761c, // stat_get_user_id
// 0x6f3d4ed9bee4e61d, 0x0, // network_session_host
0x5bc9495f0b3b6fa6, 0x80fed416e7d78bd, // network_has_control_of_pickup
0xfb00ca71da386228, 0xe7909493d1ac4bc8,
0xb9cf1f793a9f1bf1, 0x5e1693f883c1371,
0xfe54b92a344583ca, 0xec2a86d26dca3f56, // _set_tow_truck_crane_height
0x91c8e617f64188ac, 0x74297b6e2665ed22, // is_tracked_ped_visible
// 0xba4b8d83bdc75551, 0x0, // _0xba4b8d83bdc75551
0x3a8cadc7d37aacc5, 0x373948935fa8ceb1, // get_clip_set_for_scripted_gun_task
0x84b233a8c8fc8ae7, 0x44dccce026da934a, // is_toggle_mod_on
0x8f5ea1c01d65a100, 0x1653b38729bc310d, // _0x8f5ea1c01d65a100
0x5f0f3f56635809ef, 0x8d0eae4aed63f187, // _0x5f0f3f56635809ef
0x65475a218ffaa93d, 0xe0eaa5c6ae73cd58,
0xac392c8483342ac2, 0xc2b9d281b336ba4c, // leaderboards_read_pending
0x65499865fca6e5ec, 0x66a61623d480db63, // _0x65499865fca6e5ec
0xf4fc6a6f67d8d856, 0x992fa065dd01d292, // disable_vehicle_weapon
// 0x46fb3ed415c7641c, 0x0, // get_player_stat_stars_visibility
0x1d5f595ccae2e238, 0x85291a534606eb75, // set_entity_icon_color
0x28477ec23d892089, 0xbe9d0fb56a2d798f, // draw_marker
0x1c7b9b38428aeb6, 0xb7350047030f7672, // clear_area_of_vehicles
0x4c8872d8cdbe1b8b, 0x47b5cf91ac5d5ffa, // disable_navmesh_in_area
0xa3ee4a07279bb9db, 0x10930b9cad4111c2, // is_ped_in_vehicle
0xf41b5d290c99a3d6, 0x353417bdf1265885, // _0xf41b5d290c99a3d6
// 0x77f16b447824da6c, 0x0, // _0x77f16b447824da6c
0xbbc08f6b4cb8ff0a, 0x49aa03bd6de82655,
0xcf708001e1e536dd, 0x2e38114179fc5f06, // clear_this_print
0x1718de8e3f2823ca, 0x76ce32e50f0c5270, // set_entity_dynamic
0x405425358a7d61fe, 0x333b87730ce53032, // get_num_dlc_weapon_components
0xc3287ee3050fb74c, 0xc996d6d89a97a11a, // get_weapontype_group
0xeb1774df12bb9f12, 0x2ebcbca1a952e76b,
0xa989044e70010abe, 0x100d9d48576d1090, // network_clan_download_membership
0x4f0c413926060b38, 0xe03d98b1fc2a0c4e, // _force_vehicle_engine_audio
0x815e5e3073da1d67, 0xe4549c64e01f3e49, // set_balance_add_machine
0xf0af20aa7731f8c3, 0x6ed1018181c54cfb, // task_vehicle_mission_coors_target
0x4060057271cebc89, 0x9eeb3df3a5750027,
0x7caec29ecb5dfebb, 0x834c4383aa796c6c, // register_float_to_save
0xe6b0e8cfc3633bf0, 0x21c61d60db40d785, // _0xe6b0e8cfc3633bf0
0xe23d5873c2394c61, 0x5022dab37a79143, // _has_player_teleport_finished
0x3b3cad6166916d87, 0x3d6aa36f63214904, // preload_script_conversation
0x176cecf6f920d707, 0x5ab47b112cf24ae, // clear_ped_secondary_task
0x8b0c2964ba471961, 0xd7afc0b30e3e758e,
0x444d8cf241ec25c5, 0xdfcf2335b2854e41, // object_decal_toggle
0xac253d7842768f48, 0xf5941306489b2c10, // set_follow_vehicle_cam_view_mode
0x94587f17e9c365d5, 0x6da4dba91f234052, // task_smart_flee_coord
0xd10282b6e3751ba0, 0x7a0bcf765db6e029,
0x544abdda3b409b6d, 0xccd95118ab42e155, // network_player_is_rockstar_dev
0xb5ba80f839791c0f, 0x4d394438e3492cce, // set_vehicle_tyre_smoke_color
// 0xca6b2f7ce32ab653, 0x0, // _0xca6b2f7ce32ab653
0xe3b05614dce1d014, 0x31957b192e4c7bd2, // _0xe3b05614dce1d014
0xa178472ebb8ae60d, 0x44d61a9d5b660538, // set_heli_blades_full_speed
0x5190796ed39c9b6d, 0xd93d2a8227cf21de, // task_vehicle_shoot_at_coord
0xc254481a4574cb2f, 0x352a1c032a91cead, // network_stop_synchronised_scene
0x274a1519dfc1094f, 0x61a4a27622d3bd9e, // _0x274a1519dfc1094f
0xb8a850f20a067eb6, 0x1382ac429d0ea2bb, // set_script_gfx_align
// 0x94bc51e9449d917f, 0x0, // network_session_crew_matchmaking
0x74513ea3e505181e, 0xc1886905dc1402e5, // show_tick_on_blip
0x4328652ae5769c71, 0xde7a4d008e186140, // set_ped_can_be_targeted_without_los
0xdb629ffd9285fa06, 0x1a9d653c54821efb,
0x7fb139b592fa687, 0x6cb3e644e3fbfef0, // _0x07fb139b592fa687
0xf7b38b8305f1fe8b, 0x2496a90a55756159, // set_tv_channel_playlist
// 0x17c3a7d31eae39f9, 0x0, // network_spent_taxi
0xab84296fed9cfc6, 0x2eddfad8b6a0f162, // set_flash
0xc35b5cdb2824cf69, 0xac5fa8cb0d54438e, // clear_driveby_task_underneath_driving_task
0x4eebc3694e49c572, 0x96c87c1787516612,
0x73d57cffdd12c355, 0x7eeca16e87982278, // absf
0x5835d9cd92e83184, 0x5e6d03d528d40f43, // _network_get_player_crew_emblem_txd_name
0x6610343e73b9727, 0x201778f7c3042536, // _object_value_get_float
0x14d6f5678d8f1b37, 0x69e12c716d4fb8bb,
0xe83d4f9ba2a38914, 0xc472e34c8fbec678, // get_entity_heading
0xfb5045b7c42b75bf, 0x10d261962c02be0e, // _set_weather_type_over_time
0x2ddff3fb9075d747, 0xd312663d1368330a, // is_entity_focus
0xb635392a4938b3c3, 0xba1f4fdfe2e12ffe, // get_vehicle_tyre_smoke_color
0x3fa00d4f4641bfae, 0x8af979fed220daa, // _task_stop_phone_gesture_animation
// 0x4750fc27570311ec, 0x0,
0xb1bb03742917a5d6, 0xf3a02bfed31c286, // _0xb1bb03742917a5d6
0x98edf76a7271e4f2, 0x7e910171d63b14d5,
0x211c4ef450086857, 0x9d4bbd51077c9b3b,
0x532cff637ef80148, 0xdcb53a8d9ae7eda2, // hide_number_on_blip
0x788756d73ac2e07c, 0xd7b3b880bc5e2681, // is_scenario_occupied
0x300504b23bd3b711, 0xaa636074b1e78f5d, // set_vehicle_can_be_used_by_fleeing_peds
0xb81656bc81fe24d1, 0xa445fd6a56c6831f, // _set_blip_friendly
0x395bf71085d1b1d9, 0xee605e506f16b009, // set_aggressive_horns
0x796d90efb19aa332, 0xeab9cd768b92b81f, // is_ped_in_model
0x7fa5d82b8f58ec06, 0x41f6f68358796449,
0x20f898a5d9782800, 0x9b43a382f7ef6edd,
0xcae55f48d3d7875c, 0xed2f133835f7278b, // _0xcae55f48d3d7875c
0x9d060b08cd63321a, 0x41e8db0ddb28d387, // network_join_transition
0xcb7553cdcef4a735, 0x444ed1ea342a4817, // set_ped_can_cower_in_cover
0xf3e31d16cbdcb304, 0x373178f67dd6d9b4, // _sc_inbox_message_get_string
0x7651bc64ae59e128, 0xe51e38223552e0b3, // set_player_force_skip_aim_intro
0x71eab450d86954a1, 0x81c7cac36260c702, // get_ped_decorations_state
0x9c30613d50a6adef, 0xc366c74ef211d744, // wash_decals_in_range
0x29b18b4fd460ca8f, 0xc0efe4a179bcb8fe, // set_vehicle_wheels_can_break
0x7543bb439f63792b, 0x68aeb9ab0499a8a, // _0x7543bb439f63792b
// 0x84fd40f56075e816, 0x0, // _set_car_high_speed_bump_severity_multiplier
0xc8391c309684595a, 0xb21695418d3335ed,
0xe45b7f222de47e09, 0xda4592e1dad70b3e, // is_ped_strafing
0xfaf2a78061fd9ef4, 0xcb3172224d9caba5, // _0xfaf2a78061fd9ef4
0xb9c54555ed30fbc4, 0x4f98b5b5fb4b649a, // play_synchronized_map_entity_anim
0x59e7b488451f4d3a, 0xe8581fd97ad63a9a, // _0x59e7b488451f4d3a
0x146df9ec4c4b9fd4, 0x221c953018491a32, // is_vehicle_attached_to_tow_truck
0xa4a79dd2d9600654, 0xe3ab1b3215857e80,
0xdf606929c105be1, 0xff524ae40fb6301a, // draw_scaleform_movie_fullscreen
0xde7465a27d403c06, 0x3b06c717b2793dbe, // can_player_start_mission
0xd83c2b94e7508980, 0x64fd995a31c98928,
0x4593cf82aa179706, 0x2f5568037759e107, // _get_vehicle_mod_data
// 0xc35a6d07c93802b2, 0x0,
0xffa5d878809819db, 0x934475e2c2780cd7, // test_probe_against_water
0x272acd84970869c5, 0x1b9a01a53920fd50,
0x816f6981c60bf53b, 0x9247930ce6a29bc3, // apply_ped_blood_damage_by_zone
0xa76359fc80b2438e, 0x4c086d44421d2d68, // _0xa76359fc80b2438e
0xdd2620b7b9d16ff1, 0x879b60fb32c3cd4e, // _is_player_within_test_capsule
0xd66c9e72b3cc4982, 0xdc2c9a6a33594251, // _0xd66c9e72b3cc4982
0x3658e8cd94fc121a, 0x8419b15de923b330, // network_get_num_script_participants
// 0xecf128344e9ff9f1, 0x0, // _0xecf128344e9ff9f1
0xeb0a72181d4aa4ad, 0xec932db68a43adf5, // stat_clear_slot_for_reload
0xfcdff7b72d23a1ac, 0x72f7fafd0710100c, // has_entity_clear_los_to_entity
0x6058665d72302d3f, 0xb8155d6650f8c5a1, // playstats_cheat_applied
0x5b84d09cec5209c5, 0x405a2f54470ccc35, // _0x5b84d09cec5209c5
0x877c1eaeac531023, 0xd1988343f7778ce5, // _set_cargobob_hook_position
0xb3c94a90d9fc9e62, 0xc043a1ca19ea599d,
0x74de2e8739086740, 0xec339b9dd07445ad,
// 0x466da42c89865553, 0x0, // _0x466da42c89865553
0x186fc4be848e1c92, 0x989a68339d9f80c4, // get_angle_between_2d_vectors
0xc1f7d49c39d2289, 0x7b4b2a869e3695d,
0xac0bfbdc3be00e14, 0xd31e8dfa81283624, // give_ped_to_pause_menu
0xfc4842a34657bfcb, 0x3a8a5929fa4d6472, // load_cloud_hat
0x265635150fb0d82e, 0xe0a7c30d6319271d,
0xf0f2103efaf8cba7, 0x961059e00c533b1a, // _0xf0f2103efaf8cba7
0x6f361b8889a792a3, 0xaba33353615d0cd5,
0x1e5185b72ef5158a, 0x7e2eac500c9b54e3, // prepare_music_event
0xbb106883f5201fc4, 0xc7eeebff0b13ad7d, // update_task_sweep_aim_position
0x952f06beecd775cc, 0x2f5f72c179cb8ff7, // _0x952f06beecd775cc
0xb72e26d81006005b, 0x320d9994786bca17, // add_vehicle_upsidedown_check
0x13e5cfc38cd5387, 0x397a5e18506d343d, // _get_lipstick_color
0x9689123e3f213aa5, 0x130efdef56eb4c27,
0x374706271354cb18, 0x89fb107c1ce283b0, // _0x374706271354cb18
0xc669eea5d031b7de, 0xc9457660ad66e532, // _set_cam_dof_focus_distance_bias
0x261cce7eed010641, 0x2f7bf094f3c2a257, // unpin_interior
0x9454528df15d657a, 0x48b8a6610eaa0c89, // task_vehicle_mission_ped_target
// 0xb4f90faf7670b16f, 0x0,
0x48f44967fa05cc1e, 0x8a25d77379e0ed, // set_ped_head_overlay
0x108be26959a9d9bb, 0xd1190ed5b78013cf, // _0x108be26959a9d9bb
0xc9bf75d28165ff77, 0xe677ccfd6117cce5, // set_save_menu_active
0xb8ebb1e9d3588c10, 0xa85a52215e78bf3f, // is_playing_phone_gesture_anim
0xee47635f352da367, 0xee9976e9d3881f89,
0xddc635d5b3262c56, 0x1a0c641ecb831c03, // _0xddc635d5b3262c56
0x2902843fcd2b2d79, 0x286a5f0670063839, // get_event_data
0x19cafa3c87f7c2ff, 0x7b9c4ceb6d33a226,
// 0xc4bb08ee7907471e, 0x0, // _get_tupstat_bool_hash
0x96ef57a0c999bba, 0xa06d7733f3953152, // set_radar_zoom
0xbbdf066252829606, 0xf60e07aed7283ddf, // _0xbbdf066252829606
0x5991a01434ce9677, 0x8b62d3f984ae5b6f, // _are_vehicle_wings_intact
0x87052fe446e07247, 0x40b290a01c59c66a, // set_ped_coords_no_gang
0x41b4893843bbdb74, 0x7e3b06742e797067, // request_ipl
0xbb0527ec6341496d, 0xba577f3d4bdff2aa,
0x971927086cfd2158, 0xdcce32451d4e5521, // set_random_event_flag
0x71e7b2e657449aad, 0x97deb010ae7b2e0e,
0x3a0014adb172a3c5, 0x349897b41cad0de8, // _array_value_get_type
// 0xfccae5b92a830878, 0x0, // _0xfccae5b92a830878
0x2f9d3834aeb9ef79, 0xf38179330f35acb0, // set_variable_on_stream
0xccc39339bef76cf5, 0xfee41843770ab969,
0x75c55983c2c39daa, 0xe9fb70ac1925c2b4, // set_current_ped_vehicle_weapon
0x5f68520888e69014, 0x21471ca300278599, // _add_text_component_scaleform
0x3c67506996001f5e, 0x6733602399899068,
0xa651443f437b1ce6, 0x3209f1356196d9dd, // stat_load
0xea14eef5b7cd2c30, 0x2e4ea424d03fbad9,
0x7c4fccd2e4deb394, 0x8e0b41f54511a04c,
0xef7d17bc6c85264c, 0xf9852a4091e9c08,
0x26903d9cd1175f2c, 0xbb14a618e3a9c9f9, // _0x26903d9cd1175f2c
0xfa7c7f0aadf25d09, 0xeb7a519f503ed01c, // get_blip_info_id_coord
0x7cd934010e115c2c, 0x4c87ff5632a97be5, // _0x7cd934010e115c2c
0x56176892826a4fe8, 0xd8e87ef121df74da, // _get_ai_blip
0xe4a310b1d7fa73cc, 0x4eddce9aae0fc976, // get_synchronized_scene_phase
0xb1577667c3708f9b, 0xdbe3777e2f3aa1b7,
0xcabdb751d86fe93b, 0x118a88dd3ca716d1, // _array_value_add_integer
0x33468edc08e371f6, 0xd78c9ff329d2c218, // get_dlc_vehicle_data
0x12103b9e0c9f92fb, 0x91601eb74de35803,
0xb4bbfd9cd8b3922b, 0x5ded13d62a972414, // _0xb4bbfd9cd8b3922b
0xacad101e1fb66689, 0x9282cf35c66bb0c4, // set_entity_always_prerender
0x9a497fe2df198913, 0x2e9a4ae2a5b4d8e8, // is_ped_being_jacked
0xa808aa1d79230fc2, 0xee984ed4e4a374be, // is_ped_sitting_in_vehicle
0xe8a169e666cbc541, 0xcf3f3a0063de75d9,
0xb22b17df858716a6, 0x8b49ef0df3e858ab, // get_cam_spline_node_index
0x2e0a74e1002380b1, 0xd2d756aab67e5cc2, // set_vehicle_timed_explosion
0x340e61de7f471565, 0x563d94e1bffd5cc6, // set_player_wanted_level_no_drop
0xb8f87ead7533b176, 0xc7e6a5d90ded6e0b, // _0xb8f87ead7533b176
0x6325d1a044ae510d, 0x7bf2203ba17719c8, // get_vehicle_mod_kit
0xefea18dcf10f8f75, 0xef78c7a52a320ddb, // get_entity_attached_to_tow_truck
0x9b128dc36c1e04cf, 0x457c8d55a1bb6b51, // get_peds_jacker
0xa0261aef7acfc51e, 0x468ca0b8ef974056, // request_menu_ped_model
0xc0e0d686ddfc6eae, 0xb081aa8ed4a6f1a0,
0x338d2e3477711050, 0x665ae8da54e5a29a,
0x3882114bde571ad4, 0x9611832841071b69, // set_entity_invincible
0x7196842cb375cdb3, 0xee09623f26b64f8b, // get_nearest_player_to_entity
0x260be8f09e326a20, 0xa4df1e31bcdf9978, // bring_vehicle_to_halt
0xb47bd05fa66b40cf, 0xf453db2d8f580045,
0x1708e8dd3ff8c65, 0x63976b42976f740d, // _0x01708e8dd3ff8c65
0xf25df915fa38c5f3, 0x141a3db3233829b3, // remove_all_ped_weapons
0xcfeb46dcd7d8d5eb, 0x7edeaeaed85bee4f, // _0xcfeb46dcd7d8d5eb
0xb3c641f3630bf6da, 0xaec12d896fe4df9c, // _0xb3c641f3630bf6da
0x80d9f74197ea47d9, 0x3f6a41f0b145e78c, // set_random_trains
0xefbe71898a993728, 0x5a4fb33f5b279a76, // is_entity_attached_to_entity
0xc9f98ac1884e73a2, 0x183ff89a1be94594, // disable_vehicle_distantlights
0x36f1b38855f2a8df, 0xd19e4d92930d6413, // _0x36f1b38855f2a8df
0x3fa4bf0a7ab7de2c, 0x60cd928a1fff43f7, // set_cam_near_dof
0x1d506dbbbc51e64b, 0x7a7595859448170e, // special_ability_deplete_meter
0x8be1146dfd5d4468, 0x43cf2d2feb2f9c0d, // network_access_tunable_int
0xc1670e958eee24e5, 0x7d1f395c3a7a37be, // set_ped_can_be_dragged_out
0x96a05e4fb321b1ba, 0x430f196fae54a824, // set_ped_shoots_at_coord
0xae3cbe5bf394c9c9, 0xfd5d4d96d91eeaad, // delete_entity
0x2e0bf682cc778d49, 0x353d4c7f623e0e4a, // _0x2e0bf682cc778d49
// 0xeb2db0cad13154b3, 0x0,
0x5bff36d6ed83e0ae, 0x4b63314b4dc339a0,
0x9b53bb6e8943af53, 0x4ddf5809b68aa635, // task_aim_gun_at_entity
0xa7a932170592b50e, 0x117daf3bf7232886, // does_cam_exist
0x5cbf7bade20db93e, 0x4fc15454294f5f26, // _set_notification_message_clan_tag
0x5b74ea8cfd5e3e7e, 0x5ae417e8ffe8f9ca,
0xf8c54a461c3e11dc, 0xf205c5c8b30b03d4, // _0xf8c54a461c3e11dc
0xd8295af639fd9cb8, 0x2f943966db6c54d9, // _switch_in_player
0x8ac862b0b32c5b80, 0xf5029120950e3101, // does_vehicle_have_roof
0x9c375c315099dde4, 0xb418ecf6d5c5c182, // playstats_race_checkpoint
0xa9d1795cd5043663, 0x303324ea56ae968c, // atan
0x5a4f9edf1673f704, 0xc4c7f808f6388eae, // set_follow_ped_cam_view_mode
0x192547247864dfdd, 0x17a7d0fc069931ea, // _0x192547247864dfdd
0x92d619e420858204, 0x230c57280e1ab399, // remove_vehicle_mod
0x2f7ceb6520288061, 0x8e4de954cbf9fdab, // _0x2f7ceb6520288061
0xf22b6c47c6eab066, 0x6d2e2622ca149402, // is_string_null
0xa736cf7fb7c5bff4, 0x4b8e0d691807920d, // _0xa736cf7fb7c5bff4
0x1ae42c1660fd6517, 0x36f0667378d07b9c, // start_particle_fx_looped_on_entity
0x6e0c692677008888, 0xc3ec3e91c3234aca, // set_streaming
0x8a75ce2956274add, 0x17b56cf2cb077a46,
// 0x7303e27cc6532080, 0x0, // _0x7303e27cc6532080
0xa1caddcd98415a41, 0x4ccf49fd38f157b1, // stop_alarm
0xa68d3d229f4f3b06, 0x9e3c335a8d3abb, // _0xa68d3d229f4f3b06
0xf10b44fd479d69f3, 0xfb383c09aa69a3c2, // _0xf10b44fd479d69f3
0x46a1e1a299ec4bba, 0x7f327d8d184fab7f, // remove_vehicles_from_generators_in_area
// 0x1a31fe0049e542f6, 0x0,
// 0x2272b0a1343129f4, 0x0,
0xccd892192c6d2bb9, 0x1fe7c4b10ccdf812, // set_mounted_weapon_target
0x6b9bbd38ab0796df, 0x2f0a6390d863d337, // attach_entity_to_entity
0xc7f29ca00f46350e, 0xbe7b73d344384b5c, // _0xc7f29ca00f46350e
0x919be13eed931959, 0x7d575fc8f42508d8, // task_stand_still
0x60d935d3981a275, 0x7e0c34f3d4b48a15, // _does_vehicle_have_decal
0x43e4111189e54f0e, 0x85731b98c6c759d5, // _get_length_of_string
0x5b8ed3db018927b1, 0x3ea799d8b8932e70, // _0x5b8ed3db018927b1
// 0xaaa6a3698a69e048, 0x0, // _0xaaa6a3698a69e048
0x1cdd6badc297830d, 0x13d6e1e301794440, // get_vehicle_trailer_vehicle
0x8b2fd4560e55dd2d, 0xcd2f9b1910503400, // play_synchronized_audio_event
0x271401846bd26e92, 0x3c445d5efa4cc20b, // _0x271401846bd26e92
// 0xaf42195a42c63bba, 0x0,
0xddf73e2b1fec5ab4, 0x7d81712f785243b7, // network_override_receive_restrictions
0x46cd3cb66e0825cc, 0x6fef0ae3e5b50a5a, // _object_value_get_vector3
// 0xbc80e22ded931e3d, 0x0, // playstats_match_started
0xb475f27c6a994d65, 0x4a3760846340dc2c,
0x5f4b6931816e599b, 0x6241dae4cb0be8a6, // disable_all_control_actions
0xf9904d11f1acbec3, 0xb16df8f914763a53, // _get_screen_coord_from_world_coord
0x5a34cd9c3c5bec44, 0xd886ac14357a1f58, // _0x5a34cd9c3c5bec44
0xb50807eabe20a8dc, 0xa1e193b8bed16fd4, // get_random_vehicle_back_bumper_in_sphere
0xa5f377b175a699c5, 0x671d054583dd5bfc, // _0xa5f377b175a699c5
0xab04325045427aae, 0xd5386cd3834c2895, // _0xab04325045427aae
0xb5349e36c546509a, 0x4ebedec1791e2255, // get_cam_spline_phase
0xd3d15555431ab793, 0x65cd0d9be7eab2fd,
0x16b5e274bde402f8, 0xed78911f695f5c7b, // _0x16b5e274bde402f8
0xaf12610c644a35c9, 0x1300552655da73de, // _0xaf12610c644a35c9
0xe73a266db0ca9042, 0x838f76c6c0ab6849, // task_pause
0x99ad4cccb128cbc9, 0x21d2538da953ea97, // add_vehicle_phone_explosive_device
0x4cf5f55dac3280a0, 0x5db34dcaa77e2381, // task_combat_hated_targets_in_area
0x24ac0137444f9fd5, 0x8fd4d644e6cd8c6, // set_blip_as_mission_creator_blip
// 0x604e810189ee3a59, 0x0, // _is_ped_blush_color_valid
0xdad029e187a2beb4, 0x9db29d916ef1bfb2, // task_heli_mission
0x425a44533437b64d, 0x7c62edb50a5055e5, // network_is_friend_online
0xeec4047028426510, 0xe6b908880fb8fdcf, // set_particle_fx_cam_inside_vehicle
0xa51c4b86b71652ae, 0x3159b498636848e6, // _0xa51c4b86b71652ae
0xdce214d9ed58f3cf, 0x56237baf00a8a544, // shake_cinematic_cam
0xe4723db6e736ccff, 0xac84ce374df7a3bb, // _0xe4723db6e736ccff
0x45ff974eee1c8734, 0xe447a1b9434714f3, // set_blip_alpha
0x5527b8246fef9b11, 0xe4018692d92041d, // is_ped_diving
0x66680a92700f43df, 0xac848ac3e66af97b, // _0x66680a92700f43df
0xc7b4d79b01fa7a5c, 0x7661a555c1463336,
0x97465886d35210e9, 0xba33e5509fa3f42c, // task_go_to_entity_while_aiming_at_entity
0xbf3b3bd47d79c08, 0x403a4762426ef1e8, // _0x0bf3b3bd47d79c08
0x2deaac8f8ea7fe7, 0x8522047e9581dc0f, // _0x02deaac8f8ea7fe7
0x33e6c8efd0cd93e9, 0xe19dc29954f60e67,
0x15d3a79d4e44b913, 0x7e268975af5ea74f, // task_follow_nav_mesh_to_coord
0x4e548c0d7ae39ff9, 0x37751637c985bed5, // _0x4e548c0d7ae39ff9
// 0x3441cad2f2231923, 0x0, // _0x3441cad2f2231923
0x6d645d59fb5f5ad3, 0x9cacb739844df501, // _detach_vehicle_windscreen
0x39b5d1b10383f0c8, 0x51ebf893ed085755,
0x2e0e1c2b4f6cb339, 0x21de39e28274c4c1, // is_ped_in_any_boat
0x4e096588b13ffeca, 0x5e831b95c8be4f09, // set_text_justification
0x9537097412cf75fe, 0xc692a86d0a8fd54c, // _is_this_model_a_jetski
0xae306f2a904bf86e, 0x31447c964d5b1a9b, // set_cam_far_clip
0xa2297e18f3e71c2e, 0x29a5573a0b81782b, // set_gameplay_vehicle_hint
0x2b9eedc07bd06b9f, 0x4a37fd3869b2d716, // get_ped_weapon_tint_index
0x3a6867b4845beda2, 0x34678a75251e1232,
0xc78e239ac5b2ddb9, 0x19371dd142b48b03, // _0xc78e239ac5b2ddb9
0xb104cd1babf302e2, 0x156573d1aadb54ed, // is_vehicle_on_all_wheels
0x33e179436c0b31db, 0x62ca5b6a29665f1, // give_weapon_component_to_weapon_object
0x45a83257ed02d9bc, 0xf81fce406e894010,
0xc9b18b4619f48f7b, 0x4e9f3b7eb8d8f7de, // _0xc9b18b4619f48f7b
0x1e34710ecd4ab0eb, 0xf75a0e8805b9ae6f, // compare_strings
0xad6daca4ba53e0a4, 0x75e8d03bbc787bad,
0x2201c576facaebe8, 0xf4fe99cb13b7b2e8, // _0x2201c576facaebe8
0xebefc2e77084f599, 0x4b337f61147cfc24, // _0xebefc2e77084f599
0x6ea47dae7fad0eed, 0xc5ac1209923d6240, // request_anim_set
0xea241bb04110f091, 0xb000e584ec5e965e, // set_player_angry
0xf6d733c32076ad03, 0x9b775396c505643,
0x6843da7060a026b, 0xbeadaf07d2339505, // set_entity_coords
0x74cd9a9327a282ea, 0x80007e8c84e0df9e, // set_vehicle_shoot_at_target
0x840f03e9041e2c9c, 0xb1df741666f11ba, // _get_lockon_range_of_current_ped_weapon
0x1bbe0523b8db9a21, 0x4ffb62f63d342b1b, // has_vehicle_asset_loaded
0x58c21165f6545892, 0x18391fe68fca7ba3, // _0x58c21165f6545892
0xe3945201f14637dd, 0xfd317e2a1dc2f6f0, // add_to_itemset
0xf06ebb91a81e09e3, 0x89a216a36b04a9d9, // _0xf06ebb91a81e09e3
0x7a276eb2c224d70f, 0x744ab1c83757a087, // set_ped_visual_field_min_elevation_angle
0xbf737600cddbeadd, 0x9994a0814906ad0d, // _start_save_struct
0x7a197e2521ee2bab, 0xce1b83fbe9303e3f, // get_indexed_item_in_itemset
0x3f428d08be5aae31, 0xfcaf61876d23d31d, // get_ped_bone_index
// 0xdd6bcf9e94425df9, 0x0,
0x3c028c636a414ed9, 0x6e43353a90d535e1, // set_ped_allow_vehicles_override
0x14d913b777dff5da, 0xb30421b1766c4fd2, // set_player_cloth_lock_counter
0x162c23ca83ed0a62, 0xa19b73f3c321db00, // _0x162c23ca83ed0a62
// 0x58f43ec59a8631a, 0x0,
0x2ad93716f184eda4, 0xa2ad91d40fccf9d2, // get_vehicle_model_number_of_seats
0x90e47239ea1980b8, 0x6ddffce14e4fccb, // is_garage_empty
0x23641afe870af385, 0x16e1a618a518a9d5,
0xd7c95d322ff57522, 0x9fdedb1ed09ca87a,
0x63b406d7884bfa95, 0x684681e8fa05615b,
0x767fbc2ac802ef3d, 0x75d54ed6c1ad1642, // stat_get_int
0xf297383aa91dca29, 0xdf201da86440289a, // can_ped_hear_player
0xe0e8beecca96ba31, 0xb0b5ea238605ab0c, // set_entity_icon_visibility
0xead42de3610d0721, 0x953c9e86327af8e0, // can_ped_in_combat_see_target
0x9489659372a81585, 0xd641e79859e75989,
0x48164dbb970ac3f0, 0xc68e64bbcee8c21c, // request_weapon_high_detail_model
0x1cf38d529d7441d9, 0xa1697b947a1613c0, // _set_vehicle_st
0x7912f7fc4f6264b6, 0xc2ecb90e2dfa5802, // is_player_targetting_entity
0x20b60995556d004f, 0x18fb647d79b09657, // is_entity_at_coord
0xa33cdccda663159e, 0xb2b616b1f434db30,
0x2485d34e50a22e84, 0x8466f9b1f2f91a16, // _0x2485d34e50a22e84
0x9a9112a0fe9a4713, 0xf2c96862595654b4, // get_vehicle_ped_is_in
0xfd4ccdbcc59941b7, 0x16ba85002e7063c6, // is_ped_performing_stealth_kill
0x53af99baa671ca47, 0x629d2d6c17b9b5e2, // _get_vehicle_max_speed
0x58a651cd201d89ad, 0x2b44613ff7e7986a, // _0x58a651cd201d89ad
0x2e397fd2ecd37c87, 0x5801f241f822a181, // is_player_free_aiming
0x66979acf5102fd2f, 0xf9b360778d4b7a7a, // _0x66979acf5102fd2f
0x186e5d252fa50e7d, 0x5e82627d2afefee1,
0x44b37cdcae765aae, 0x1ffd1644fb7183ea, // _0x44b37cdcae765aae
0xb118af58b5f332a1, 0xc405ca35cbe5b989,
0x371ea43692861cf1, 0x653ed9176ea96780, // network_get_respawn_result
0xf3e34e968ea374e, 0x19a39772525fa2cd, // task_vehicle_park
0xf2b7106d37947ce0, 0x401de60bad9086c7, // set_ped_can_torso_ik
0x817b86108eb94e51, 0x2b74b8468a37cf2a, // _0x817b86108eb94e51
0xa46413066687a328, 0xba45e8782d26db7b, // set_vehicle_ceiling_height
0xfe3f9c29f7b32bd5, 0xacba87310ed2513, // get_vehicle_door_angle_ratio
0xc0741a26499654cd, 0xdbe02f22ef4c0b4, // get_entity_index_of_registered_entity
0x638c03b0f9878f57, 0x83f9b3b112e951f, // set_ped_can_be_targeted_when_injured
0x48189fac643deee, 0x990eac59e2fe851a, // change_player_ped
0xafebb0d5d8f687d2, 0xdefa1de7a59b4a4d,
0x20ce80b0c2bf4acc, 0x7e8740f26d4cab87, // has_player_damaged_at_least_one_ped
0x731ec8a916bd11a1, 0xd678ee74d1f49f90, // is_an_entity
0x88cbb5ceb96b7bd2, 0xb5feff716515ef9e, // set_ped_stealth_movement
0xc5868a966e5be3ae, 0xd85ee53eecb30237,
0xf56dfb7b61be7276, 0x2b4316e171681b4f, // _0xf56dfb7b61be7276
0xd27058a1ca2b13ee, 0xdb70e89b17c1fb5f,
0xd37401d78a929a49, 0xadad7b4709951d1,
0x7e17be53e1aaabaf, 0xa883d79cd1311dfe, // _0x7e17be53e1aaabaf
0xf0d31ad191a74f87, 0xee14d9a9f531addc, // absi
0x72c896464915d1b1, 0xf0122fb9444d4bc7, // task_react_and_flee_ped
0x2f794a877add4c92, 0x77445494eec01ce5, // stop_all_alarms
0xebd76f2359f190ac, 0xe9220325b81b2901, // set_ped_suffers_critical_hits
0x4df7cfff471a7fb1, 0xe40ee4752202d0ce, // _0x4df7cfff471a7fb1
0x3d42b92563939375, 0xd6d4e1e1597d7bb6, // _0x3d42b92563939375
0xcf511840ceede0cc, 0x8248367ee2a51f1d, // is_entity_attached_to_any_object
0xa5a9653a8d2caf48, 0x7e67dea07db29899, // set_vehicle_door_latched
0x606e4d3e3cccf3eb, 0x7e70fddc8dae6400,
0x6d793f03a631fe56, 0x8b9b4da276fc8330, // get_shop_ped_query_outfit
0x30983ca930b692d, 0x7d66088af22dd38e, // set_ped_ducking
0x6e176f1b18bc0637, 0x6bfbb3b1e8744c7c, // network_spent_buy_reveal_players
0xb4a53e05f68b6fa1, 0x3fae00762e476267, // get_mobile_phone_render_id
0x26f07dd83a5f7f98, 0xab86e285ca06b2c,
0x6fb7bb3607d27fa2, 0x4371d1944ffa33f3,
0xac96609b9995edf8, 0x1f4e8d9514a80059, // task_toggle_duck
0xd801cc02177fa3f1, 0x5e33457a521f8109,
0xc54c95da968ec5b5, 0x9540378193f0b4e9, // set_player_simulate_aiming
0x5917bba32d06c230, 0x1f3934a4c07c1854, // set_scripted_anim_seat_offset
// 0x6d8eac07506291fb, 0x0, // _0x6d8eac07506291fb
0x649c97d52332341a, 0xccee3c2abf9bdbd4, // _0x649c97d52332341a
0xf2e1a7133dd356a6, 0x20e3d3ad191805b7, // _0xf2e1a7133dd356a6
0x2c8cbfe1ea5fc631, 0x19d0a2a2fb636869, // _0x2c8cbfe1ea5fc631
// 0x320d0e0d936a0e9b, 0x0, // set_gps_flashes
0x1fef0683b96ebcf2, 0xd855ece77a9f1f8b, // set_siren_with_no_driver
0xaa5dc05579d60bd9, 0xdcf38b56b2e55beb, // task_stealth_kill
0xc45c27ef50f36adc, 0x9d76bb975a1d5af8, // _0xc45c27ef50f36adc
0x2a30922c90c9b42c, 0xf3f785d3ff7859d4, // set_ped_dies_in_vehicle
0x1f73a131c18cd94, 0x80bcaff1fdcc7e85, // remove_clip_set
// 0xebd3205a207939ed, 0x0, // _0xebd3205a207939ed
0x1153fa02a659051c, 0xe6a5fbe0812ca469,
0xf3fbe2d50a6a8c28, 0x9fe26c6213850011, // _get_character_outfits_count
0xd1b0f412f109ea5d, 0xbaa621dd1913585a, // _0xd1b0f412f109ea5d
0x15e69e2802c24b8d, 0x5558c5907fa836d4, // _0x15e69e2802c24b8d
0x632b2940c67f4ea9, 0xb324e611dfd79a4, // _0x632b2940c67f4ea9
0x5d14d4154bfe7b2c, 0x3f0fe5a10f840ea1, // set_vehicle_allow_no_passengers_lockon
0x46818d79b1f7499a, 0x9b8c51ea76ffd393, // add_blip_for_radius
0xd53343aa4fb7dd28, 0x9ec3b269a34a2bee, // get_random_int_in_range
0x61e1dd6125a3eee6, 0x7e0147e36ef8d6ac, // is_any_vehicle_near_point
0x92ccc17a7a2285da, 0xe535894c7a01cd84,
0xc8a9481a01e63c28, 0xc475906893aeb995, // set_ped_random_component_variation
0xe6ca85e7259ce16b, 0x4743c7c0341d6cfe, // _0xe6ca85e7259ce16b
0xa9d14eea259f9248, 0x49fa017141d73e50,
0x2bb9230590da5e8a, 0xe84981c3fddc67c7, // get_vehicle_livery
0x704983df373b198f, 0x7d583f3146a40d01, // set_weather_type_persist
0x37deb0aa183fb6d8, 0x35cf1dd9f9af8e64,
0x7dd959874c1fd534, 0xe196503b36b6194b, // create_ped_inside_vehicle
0xac2890471901861c, 0xd055b2173ec7aa98, // _0xac2890471901861c
0x208a1888007fc0e6, 0x465b3afc81be6b6d, // set_ped_drops_inventory_weapon
0xc1805d05e6d4fe10, 0xe755263c67c53e1, // _set_vehicle_as_ambient_emmitter
0x2a8f319b392e7b3f, 0xff78a57c73dac294, // _0x2a8f319b392e7b3f
0xbbc72712e80257a1, 0x2c02caa9c4127339,
0x39d22031557946c1, 0x757d4e12d1de916, // get_ped_ammo_by_type
// 0xa74802fb8d0b7814, 0x0, // unload_cloud_hat
0x971da0055324d033, 0xcc7eceee8e8bc4b2, // _set_object_texture_variant
0xf7b2cfde5c9f700d, 0x9786ad249280bdab, // network_find_matched_gamers
0xcb6a7c3bb17a0c67, 0x5deac2a375eaf148, // set_noisinessoveride
0x8132c0eb8b2b3293, 0x586a529bb3352393,
0xe4b5f4bf2cb24e65, 0x7dfcdba7b83179f9, // has_action_mode_asset_loaded
0xa61b4df533dcb56e, 0x642585888a1136cb, // is_area_occupied
0x1dd55701034110e5, 0x6edaf915c19eb69, // get_entity_height_above_ground
0xcb7cc0d58405ad41, 0xeb50c0fc248ec57d, // _set_radar_zoom_level_this_frame
0x93b0fb27c9a04060, 0xb3739b780df92eed, // set_player_parachute_pack_tint_index
0x30d779de7c4f6dd3, 0xc7b227bf170dfa81, // _set_desired_vertical_flight_phase
0x4cc7f0fea5283fe0, 0x63b2da7a88ad3c5f, // _set_force_vehicle_trails // no just try
0x34f060f4bf92e018, 0x252f9ce6a90b6b86, // set_ped_paths_in_area
0x1ba3aed21c16cfb, 0xba219be38c61c8a6, // set_disable_frag_damage
0x8decb02f88f428bc, 0xeaf6e82c7bde5a4c, // has_ped_got_weapon
0x7f0dd2ebbb651aff, 0x8e908fa8974bbb9c, // stop_entity_fire
0xb8ef61207c2393a9, 0x17d9ab0f4b269bc2, // _get_vehicle_body_health_2
0xb14552383d39ce3e, 0xe734bc61706d976, // set_blip_flashes
0x6e08bf5b3722bac9, 0xf80cdd882a43941, // _does_cargobob_have_pickup_magnet
0xdcfe42068fe0135a, 0x10a241c3bedff110, // control_mounted_weapon
0xb162dc95c0a3317b, 0x349ed8a03cd3f71f, // network_spent_ammo_drop
0x9a4cf4f48ad77302, 0xb16bc34f6cb4a57a,
0x67b2c79aa7ff5738, 0x2d5a67427544788c, // set_vehicle_is_stolen
0xc520a34dafbf24b1, 0xe07a09e6f4c19192, // get_cam_near_clip
0x6a842d197f845d56, 0x253452860052b191, // get_vehicle_colour_combination
0x5ed0356a0ce3a34f, 0x87b896947b69fb1d,
0x9748fa4de50cce3e, 0x1a669370061633bf, // set_ambient_zone_list_state
0x4f8fc8fcf58f88d, 0x88246b349fcc2454, // clear_area_of_cops
0x48b3886c1358d0d5, 0x61ae8e2b7bb7d8ba, // set_pad_shake
0xbfd8727aea3cceba, 0x2aafdb86f2cbfb67, // set_cam_params
0x33e8cd3322e2fe31, 0xd6d2420f0051065a, // set_vehicle_colour_combination
0x8bfceb5ea1b161b6, 0x3755019f750a4797,
// 0x6f1554b0cc2089fa, 0x0, // _0x6f1554b0cc2089fa
0x92c47782fda8b2a3, 0x6a71a9a295c36777, // create_model_swap
// 0xe88da0751c22a2ad, 0x0, // set_ped_reserve_parachute_tint_index
0x7a1adeef01740a24, 0xed8ca182944fbfea, // network_get_destroyer_of_network_id
0x3dec726c25a11bac, 0xd0d0fca79b01107, // _0x3dec726c25a11bac
0xd43d95c7a869447f, 0xd5a8566031a832bb, // task_seek_cover_to_cover_point
0xfb3272229a82c759, 0x6683266de0f97612,
0x9219857d21f0e842, 0xf8f38926b8afe0d6, // remove_stealth_mode_asset
0xcbad6729f7b1f4fc, 0xcdec8161be712395,
0x53158863fcc0893a, 0xa8b379916562fd8e, // get_bits_in_range
0xb604a2942aded0ee, 0xf759ba8cfed9e6f7, // set_decision_maker
0xc401503dfe8d53cf, 0x9b7505f11567f76, // remove_particle_fx
0xb1cc1b9ec3007a2a, 0x71145c9c6157526a, // network_earn_from_crate_drop
0x3dc52677769b4ae0, 0xff3a77caa9ff583e, // is_ped_running_arrest_task
0xc17ad0e5752becda, 0x9065b39957655c54, // _get_variants_for_component_count
0x2b6747faa9db9d6b, 0x23f395cf89089eb2, // _0x2b6747faa9db9d6b
0x2170813d3dd8661b, 0x98af80eef7419e0d,
0x8d11e61a4abf49cc, 0xc8fd82ee1f791377,
// 0x4e3cd0ef8a489541, 0x0,
0xc9b43a33d09cada7, 0x133df6bcee33f671, // _0xc9b43a33d09cada7
0x613ed644950626ae, 0xb1a2c129294d80a7, // set_mp_gamer_tag_colour
0x56105e599cab0efa, 0xf2fc35b3d4664d2a, // _0x56105e599cab0efa
0xd5b35bea41919acb, 0x18d0d3a283cc9fb3, // _task_move_network_advancedcover_to_cover_point
0xfb3272229a82c759, 0x6683266de0f97612,
0x9219857d21f0e842, 0xf8f38926b8afe0d6, // remove_stealth_mode_asset
0xcbad6729f7b1f4fc, 0xcdec8161be712395,
0x53158863fcc0893a, 0xa8b379916562fd8e, // get_bits_in_range
0xb604a2942aded0ee, 0xf759ba8cfed9e6f7, // set_decision_maker
0xc401503dfe8d53cf, 0x9b7505f11567f76, // remove_particle_fx
0xb1cc1b9ec3007a2a, 0x71145c9c6157526a, // network_earn_from_crate_drop
0x3dc52677769b4ae0, 0xff3a77caa9ff583e, // is_ped_running_arrest_task
0xc17ad0e5752becda, 0x9065b39957655c54, // _get_variants_for_component_count
0x2b6747faa9db9d6b, 0x23f395cf89089eb2, // _0x2b6747faa9db9d6b
0x2170813d3dd8661b, 0x98af80eef7419e0d,
0x8d11e61a4abf49cc, 0xc8fd82ee1f7913,
0x3C5FD37B5499582E, 0x5787B31B4578002B, //UNK3::_NETWORK_SHOP_BEGIN_SERVICE
0x39BE7CEA8D9CC8E6, 0x64875ABCC43EF9A8, //UNK3::_NETWORK_SHOP_CHECKOUT_START
0x00DC833F2568DBF6, 0x8362FFA61BB1BC36, //DISPLAY_ONSCREEN_KEYBOARD
};
/*
void CrossMapping::initNativeMap() {
static int init = 0;
struct twoQwords {
uint64_t first;
uint64_t second;
} *p2q;

if (init) {
DEBUGMSG("Already init, nativeHashMap has %lli members", nativeHashMap.size());
return;
}

p2q = reinterpret_cast<twoQwords *>(__HASHMAPDATA);
//DEBUG_OUT("p2q: %p", p2q);
//DEBUG_OUT("p2q->first: %llx", p2q->first);
//DEBUG_OUT("p2q->second: %llx", p2q->second);
while (p2q->first) {
//DEBUG_OUT("initNHM: %llx, %llx", p2q->first, p2q->second);
nativeHashMap.emplace(p2q->first, p2q->second);
//DEBUG_OUT("nativeHashMap now has %lli members", nativeHashMap.size());
++p2q;
}
init = 1;
DEBUGMSG("nativeHashMap has %lli members", nativeHashMap.size());


std::ofstream file;
file.open("EntryPoints.txt");
for (int i = 0; i < sizeof(__HASHMAPDATA) / sizeof(*__HASHMAPDATA); i += 2) {
auto addr = Hooking::GetNativeHandler(__HASHMAPDATA[i]);
file << std::hex << "0x" << __HASHMAPDATA[i] << " : " << "0x" << addr << std::endl;
}
file.close();
}*/

void CrossMapping::initNativeMap()
{
	static int init = 0;
	struct twoQwords
	{
		uint64_t first;
		uint64_t second;
	} *p2q;

	if (init) {
		//DEBUGMSG("Already init, nativeHashMap has %lli members", nativeHashMap.size());
		return;
	}

	p2q = reinterpret_cast<twoQwords *>(__HASHMAPDATA);
	//DEBUG_OUT("p2q: %p", p2q);
	//DEBUG_OUT("p2q->first: %llx", p2q->first);
	//DEBUG_OUT("p2q->second: %llx", p2q->second);

	//loops through all items in the hash array, inserts into hash map if unique
	while (p2q->first)
	{
		//DEBUG_OUT("initNHM: %llx, %llx", p2q->first, p2q->second);
		nativeHashMap.emplace(p2q->first, p2q->second);
		//DEBUG_OUT("nativeHashMap now has %lli members", nativeHashMap.size());
		++p2q;
	}
	init = 1;
	//DEBUGMSG("nativeHashMap has %lli members", nativeHashMap.size());
}
/*##################################################################################################*/

static nMap nativeCache;

bool CrossMapping::searchMap(nMap map, uint64_t inNative, uint64_t *outNative)
{
	bool found = false;
	//LOG_DEBUG("inNative 0x%016llx", inNative);
	for (nMap::const_iterator it = map.begin(); it != map.end(); ++it)
	{
		found = (inNative == it->first);
		if (found) {
			*outNative = it->second;
			//LOG_DEBUG("outNative 0x%016llx", outNative);
			break;
		}
	}

	return found;

}

uint64_t CrossMapping::MapNative(uint64_t inNative)
{
	uint64_t currentNative, outNative;
	bool found = false;

	currentNative = inNative;
	found = searchMap(nativeCache, currentNative, &outNative);
	if (found) return outNative;
	found = searchMap(nativeHashMap, currentNative, &outNative);
	if (found) {
		nativeCache[inNative] = outNative;
		return outNative;
	}

	// Fail safe to prevent LOG_ERROR spam due to ontick run failed natives
	found = std::find(nativeFailedVec.begin(), nativeFailedVec.end(), inNative) != nativeFailedVec.end();
	if (found) {
		return NULL;
	}
	else nativeFailedVec.push_back(inNative);
	//Log::Error("Failed to find new hash for 0x%p", inNative);
	return NULL;
}

void CrossMapping::dumpNativeMappingCache()
{
	// read the mapping table
	/*FILE *file;
	int file_exists;
	char filename[0x400];
	snprintf(filename, sizeof(filename), "native_cache.log");
	//first check if the file exists...
	fopen_s(&file, filename, "r");
	if (file == NULL) file_exists = 0;
	else { file_exists = 1; fclose(file); }

	//...then open it in the appropriate way
	if (file_exists == 1)
	{
	fopen_s(&file, filename, "r+b");
	}
	else
	{
	fopen_s(&file, filename, "w+b");
	}

	if (file != NULL)
	{
	char buffer[50];
	for (nMap::const_iterator it = nativeCache.begin(); it != nativeCache.end(); ++it)
	{
	sprintf_s(buffer, "{ 0x%llx, 0x%llx },\n", it->first, it->second);
	fputs(buffer, file);
	}

	PlaySound(L"C:\\WINDOWS\\Media\\tada.wav", NULL, SND_ASYNC);

	fclose(file);
	}*/
}