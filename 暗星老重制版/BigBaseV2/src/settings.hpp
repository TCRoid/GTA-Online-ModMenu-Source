#pragma once
#include "common.hpp"
#include "gta/player.hpp"
#include "player_struct.hpp"
#include "gta/enums.hpp"
struct myCar
{
	std::string VehicleName;
	std::string VehiclelabelName;
};
namespace big
{
	class settings
	{
	public:
		explicit settings() = default;
		~settings() = default;

		nlohmann::json options;
		nlohmann::json default_settings =
			R"({
			"language":"Chinese.json",
			"god bool": false,
			"cargod bool": false,
			"anquandai": false,
			"wuxiandanqi": false,
			"jiaosudu": false,
			"caihongzaiju": false,
			"flycar": false,
			"spwancargod": false,
			"spwancarmax": false,
			"spwancarin": false,
			"spwancardel": false,
			"xianshiwanjia": false,
			"2dbox": false,
			"3dbox": false,
			"Skeleton": false,
			"Health bar": false,
			"nameesp": false,
			"Tracers": false,
			"esp_fps": false,
			"crosshair": false,
			"hgod bool": false,
			"Never Wanted bool": false,
			"renjianzhengfa": false,
			"plwushi bool": false,
			"notili bool": false,
			"nobo": false,
			"chaojitiao": false,
			"yinshen": false,
			"afk": false,
			"notili": false,
			"chuanqiang": false,
			"ziyoucam": false,
			"chaorentiao": false,
			"qzzou": false,
			"superrun": false,
			"baozhazidan": false,
			"dckunnan": false,
			"kuaishe": false,
			"miaosha": false,
			"wuxianzidan": false,
			"pedgun": false,
			"delgun": false,
			"tpgun": false,
			"Paintgun": false,
			"rainbowgun": false,
			"cargun": false,
			"Gravitygun": false,
			"wuxianzidan": false,
			"BlockSCIDJoins": false,
			"autotp": false,
			"spwancardel_mod": false,

			"demo bool": false,
			"demo int": 1,
			"demo double": 1.0,
			"demo combo": 0,
			"demo bitset": 62678480396171113
		})"_json;
		struct debug {
			bool script_event_logging = false;
		};

		struct tunables {
			bool disable_phone = false;
			bool no_idle_kick = false;
		};

		struct player {
			int character_slot = 1;
			int set_level = 130;
			bool spectating = false;
		};

		struct protections {
			bool freemode_terminated = false;
			struct script_events {
				bool bounty = true;
				bool ceo_ban = true;
				bool ceo_kick = true;
				bool ceo_money = true;
				bool clear_wanted_level = true;
				bool fake_deposit = true;
				bool force_mission = true;
				bool force_teleport = true;
				bool gta_banner = true;
				bool personal_vehicle_destroyed = true;
				bool remote_off_radar = true;
				bool send_to_cutscene = true;
				bool send_to_island = true;
				bool sound_spam = true;
				bool spectate = true;
				bool transaction_error = true;
				bool vehicle_kick = true;
			};

			script_events script_events{};
		};

		struct self {
			struct frame_flags {
				bool explosive_ammo = false;
				bool explosive_melee = false;
				bool fire_ammo = false;
				bool super_jump = false;
			};

			bool godmode = false;
			bool free_cam = false;
			bool off_radar = false;
			bool never_wanted = false;
			bool noclip = false;
			bool no_ragdoll = false;
			bool super_run = false;
			bool force_wanted_level = false;
			int wanted_level = 0;

			frame_flags frame_flags{};
		};

		struct spoofing
		{
			bool spoof_username = false;
			std::string username = "";

			bool spoof_ip = false;
			int ip_address[4] = { 1, 1, 1, 1 };

			bool spoof_rockstar_id = false;
			uint64_t rockstar_id = 0;
		};

		struct vehicle {
			struct speedo_meter {
				float x = .9f;
				float y = .72f;

				bool left_side = false;
			};

			bool god_mode = false;
			bool horn_boost = false;
			speedo_meter speedo_meter{};
		};

		struct weapons {
			char vehicle_gun_model[12] = "bus";
		};

		struct window {
			bool debug = false;
			bool handling = false;
			bool log = false;
			bool main = true;
			bool users = true;
			bool player = false;

			bool _login = true;
			bool loginstyle = false;

			int x;
			int y;
		};

		int friend_count = 0;
		int god_count = 0;
		int player_count = 0;
		CPlayer players[32];
		CPlayer selected_player;
		Player SelectedPlayer;
		Ped SelectedPed;

		debug debug{};
		tunables tunables{};
		player player{};
		protections protections{};
		self self{};
		spoofing spoofing{};
		vehicle vehicle{};

		std::vector<std::string> themeList;
		std::string currenttheme = "";

		std::vector<std::string> HeadImgList;
		std::string currentHeadImgList = "";

		float custom_x{};
		float custom_y{};
		float custom_z{};
		std::vector<std::string> XmlCarList;
		bool _small_ = true;
		std::string currentiniveh = "";
		std::string currentxmlveh = "";
		std::vector<std::string> IniCarList;
		std::vector<std::string> IniSmallCarList;
		std::vector<myCar> CarList;
		std::vector<std::string> AsiList;
		std::string asiname{};

		char* list_VehicleName = "ADDER";
		char* list_VehiclelabelName = "";

		weapons weapons{};
		window window{};
		rage::scriptHandlerNetComponent* mgr{};
		bool save()
		{
			std::string settings_file = std::string(MENU_PATH) + "\\settings.json";

			std::ofstream file(settings_file, std::ios::out | std::ios::trunc);
			file << options.dump(4);
			file.close();
			return true;
		}

		bool load()
		{
			std::string settings_file = std::string(MENU_PATH) + "\\settings.json";
			std::ifstream file(settings_file);

			if (!file.is_open())
			{
				write_default_config();
				file.open(settings_file);
			}

			file >> options;

			bool should_save = false;
			for (auto& e : default_settings.items())
			{
				if (options.count(e.key()) == 0)
				{
					should_save = true;
					options[e.key()] = e.value();
				}
			}

			if (should_save)
			{
				LOG(INFO) << "Updating settings.";
				save();
			}

			return true;
		}

	private:
		bool write_default_config()
		{
			std::string settings_file = std::string(MENU_PATH) + "\\settings.json";

			std::ofstream file(settings_file, std::ios::out);
			file << default_settings.dump(4);
			file.close();

			options.clear();
			options = default_settings;

			return true;
		}
	};

	inline settings g_settings;
}