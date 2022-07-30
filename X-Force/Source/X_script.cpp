#include "stdafx.h"

std::string prefix[3] = { "$", "%", "&" };
std::string commands[999] = { "godmode()", "weather(int)", "explosion(Vector3)", "moneyrain()", "stealth(int)" };
std::string hooks[999] = { "is_shooting(Player)", "localplayer()", "key(int)" };

std::string fp = "X-Folder/scripts/";
std::string last = ".txt";
std::string XScript::file = "";
std::string script = fp + XScript::file + last;

std::string sel_pl[] = { "@p", "@e", "@s" };
std::string tse_ev[] = { "KICK", "CEOKICK", "INVITE", "TELEPORT", "ERROR", "VEHICLEKICK", "ROTATE" };
std::string weather_id[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15" };

std::string c_money = "moneyrain()";
std::string h_shooting = "is_shooting(";
std::string h_shooting2 = "is_shooting(" + sel_pl[1] + ")";
std::string h_shooting3 = "is_shooting(" + sel_pl[2] + ")";
std::string c_stealth = "stealth(";
std::string p_test = "test(";
std::string c_tse = "trigger_script_event(";
std::string c_weather = "set_weather(";
std::string c_kick = "kick(";
std::string c_error = "error(";
std::string c_tp = "teleport(";

int keyss[] = { VK_KEY_0, VK_KEY_1, VK_KEY_2, VK_KEY_3, VK_KEY_4, VK_KEY_5, VK_KEY_6, VK_KEY_7, VK_KEY_8, VK_KEY_9, VK_KEY_A, VK_KEY_B, VK_KEY_C, VK_KEY_D, VK_KEY_E, VK_KEY_F, VK_KEY_G, VK_KEY_H, VK_KEY_I, VK_KEY_J, VK_KEY_K, VK_KEY_L, VK_KEY_M, VK_KEY_N, VK_KEY_O, VK_KEY_P, VK_KEY_Q, VK_KEY_R, VK_KEY_S, VK_KEY_T, VK_KEY_U, VK_KEY_V, VK_KEY_W, VK_KEY_X, VK_KEY_Y, VK_KEY_Z };
std::string keycodes[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
std::string h_key = "key_pressed(+)";

bool XScript::getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs)
{

	// Open the File
	std::ifstream in(fileName.c_str());

	// Check if object is valid
	if (!in)
	{
		std::cerr << "Cannot open the File : " << fileName << std::endl;
		return false;
	}

	std::string str;
	// Read the next line from File untill it reaches the end.
	while (std::getline(in, str))
	{
		// Line contains string of length > 0 then save it in vector
		if (str.size() > 0)
			vecOfStrs.push_back(str);
	}
	//Close The File
	in.close();
	return true;
}

int XScript::getLines(std::string f) {
	return Features::countLines(f);
}

std::string XScript::readLine(std::string f, int n) {
	return Features::readLine(f, n);
}

bool XScript::checkCommand(std::string cmd, int line) {
		if (readLine(script, line) == cmd) {
			return true;
		}
		else {
			return false;
		}
}

void XScript::executeCommand(int line, std::string cmd, std::function<void()> function) {
	if (readLine(script, line) == cmd) {
		function();
	}
}

void XScript::hookCommand(bool condition, std::string thiscmd, std::string cmd, std::function<void()> function) {
	int lineFound = 0;
	for (int i = 0; i < getLines(script); i++) {
		if (checkCommand(prefix[0] + thiscmd, i) && condition) {
			lineFound = i;
			executeCommand(lineFound + 1, prefix[1] + cmd, function);
		}
	}
}

void XScript::normalCommand(std::string thiscmd, std::function<void()> function) {
	int lineFound = 0;
	for (int i = 0; i < getLines(script); i++) {
		if (checkCommand(prefix[2] + thiscmd, i)) {
			lineFound = i;
			function();
		}
	}
}


std::string XScript::getParam(std::string cmd) {
	for (int i = 0; i < getLines(script); i++) {
		if (checkCommand(prefix[2] + cmd, i)) {
			//TO DO: do it!
		}
	}
	return "";
}




void XScript::keypressed(int key, std::string key2) {
	bool b00l = GetAsyncKeyState(key);
	hookCommand(b00l, h_key, c_money, [] { Features::customDropBool2 = !Features::customDropBool2; });
	hookCommand(b00l, h_key, c_stealth, [] {});
	std::string params[10] = { "10000000", "9000000", "8000000", "7000000", "6000000", "5000000", "4000000", "3000000", "2000000", "1000000" };
	for (int i = 0; i < ARRAYSIZE(params); i++) {
		hookCommand(b00l, h_key, c_stealth + params[i] + ")", [i] { std::string params2[10] = { "10000000", "9000000", "8000000", "7000000", "6000000", "5000000", "4000000", "3000000", "2000000", "1000000" }; Any var0 = INT_MAX; UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, 312105838, 1445302971, stoi(params2[i]), 4); UNK3::_NETWORK_SHOP_CHECKOUT_START(var0); });
	}
	/*for (int i = 0; i < ARRAYSIZE(sel_pl); i++) {
		for (int j = 0; j < ARRAYSIZE(tse_ev); j++) {
			hookCommand(b00l, h_shooting, c_tse + sel_pl[i] + ", " + tse_ev[j] + ")", [i, j] { cmdSE(i, j); });
		}
	}*/
	for (int i = 0; i < ARRAYSIZE(weather_id); i++) {
		hookCommand(b00l, h_key, c_weather + weather_id[i] + ")", [i] { Hooking::set_session_weather(1, stoi(weather_id[i]), 76, 0); });
	}
	for (int i = 0; i < ARRAYSIZE(sel_pl); i++) {
		hookCommand(b00l, h_key, c_kick + sel_pl[i] + ")", [i] {
			if (i == 0) {
				unsigned int Bit = (1 << PLAYER::PLAYER_ID());
				uint64_t args[3] = { -120668417, PLAYER::PLAYER_PED_ID(), 48 };
				Hooking::trigger_script_event(1, args, 3, Bit);
			}
			else if (i == 1) {
				for (int i = 0; i < 33; i++) {
					unsigned int Bit = (1 << i);
					uint64_t args[3] = { -120668417, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 48 };
					Hooking::trigger_script_event(1, args, 3, Bit);
				}
			}
			else {
				unsigned int Bit = (1 << Features::Online::selectedPlayer);
				uint64_t args[3] = { -120668417, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 48 };
				Hooking::trigger_script_event(1, args, 3, Bit);
			}
		});
	}
	for (int i = 0; i < ARRAYSIZE(sel_pl); i++) {
		hookCommand(b00l, h_key, c_tp + sel_pl[i] + ")", [i] {
			if (i == 0) {
				unsigned int Bit = (1 << PLAYER::PLAYER_ID());
				uint64_t args[9] = { 1000837481, PLAYER::PLAYER_PED_ID(), 0, -1, 1, 1, 0, 0, 0 };
				Hooking::trigger_script_event(1, args, 9, Bit);
			}
			else if (i == 1) {
				for (int i = 0; i < 33; i++) {
					unsigned int Bit = (1 << i);
					uint64_t args[9] = { 1000837481, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0, -1, 1, 1, 0, 0, 0 };
					Hooking::trigger_script_event(1, args, 9, Bit);
				}
			}
			else {
				unsigned int Bit = (1 << Features::Online::selectedPlayer);
				uint64_t args[9] = { 1000837481, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0, -1, 1, 1, 0, 0, 0 };
				Hooking::trigger_script_event(1, args, 9, Bit);
			}
		});
	}
	for (int i = 0; i < ARRAYSIZE(sel_pl); i++) {
		hookCommand(b00l, h_key, c_error + sel_pl[i] + ")", [i] {
			if (i == 0) {
				unsigned int Bit = (1 << PLAYER::PLAYER_ID());
				auto var0 = globalHandle(1625435 + 1 + PLAYER::PLAYER_ID() * 560 + 491).As<std::uint64_t>();
				auto var1 = globalHandle(1643357 + 9).As<std::uint64_t>();
				uint64_t args[8] = { 1000837481, PLAYER::PLAYER_PED_ID(), 10000, 0, 0, var0, var1, var1 };
				Hooking::trigger_script_event(1, args, 8, Bit);
			}
			else if (i == 1) {
				for (int i = 0; i < 33; i++) {
					unsigned int Bit = (1 << i);
					auto var0 = globalHandle(1625435 + 1 + i * 560 + 491).As<std::uint64_t>();
					auto var1 = globalHandle(1643357 + 9).As<std::uint64_t>();
					uint64_t args[8] = { 1000837481, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 10000, 0, 0, var0, var1, var1 };
					Hooking::trigger_script_event(1, args, 8, Bit);
				}
			}
			else {
				unsigned int Bit = (1 << Features::Online::selectedPlayer);
				auto var0 = globalHandle(1625435 + 1 + Features::Online::selectedPlayer * 560 + 491).As<std::uint64_t>();
				auto var1 = globalHandle(1643357 + 9).As<std::uint64_t>();
				uint64_t args[8] = { 1000837481, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 10000, 0, 0, var0, var1, var1 };
				Hooking::trigger_script_event(1, args, 8, Bit);
			}
		});
	}
}

void XScript::shooting1(std::string mode) {
	Player ppp;
	if (mode == sel_pl[0]) {
		ppp = PLAYER::PLAYER_PED_ID();
	}
	else if (mode == sel_pl[1]) {
		for (int lmao = 0; lmao < 33; lmao++) {
			ppp = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(lmao);
		}
	}
	else if (mode == sel_pl[2]) {
		ppp = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
	}
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(ppp, 1);
	bool b00l = PED::IS_PED_SHOOTING_IN_AREA(ppp, coords.x, coords.y, coords.z, coords.x, coords.y, coords.z, true, true);
	hookCommand(b00l, h_shooting + mode + ")", c_money, [] { Features::customDropBool2 = !Features::customDropBool2; });
	hookCommand(b00l, h_shooting + mode + ")", c_stealth, [] {});
	std::string params[10] = { "10000000", "9000000", "8000000", "7000000", "6000000", "5000000", "4000000", "3000000", "2000000", "1000000" };
	for (int i = 0; i < ARRAYSIZE(params); i++) {
		hookCommand(b00l, h_shooting + mode + ")", c_stealth + params[i] + ")", [i] { std::string params2[10] = { "10000000", "9000000", "8000000", "7000000", "6000000", "5000000", "4000000", "3000000", "2000000", "1000000" }; Any var0 = INT_MAX; UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, 312105838, 1445302971, stoi(params2[i]), 4); UNK3::_NETWORK_SHOP_CHECKOUT_START(var0); });
	}
	/*for (int i = 0; i < ARRAYSIZE(sel_pl); i++) {
		for (int j = 0; j < ARRAYSIZE(tse_ev); j++) {
			hookCommand(b00l, h_shooting, c_tse + sel_pl[i] + ", " + tse_ev[j] + ")", [i, j] { cmdSE(i, j); });
		}
	}*/
	for (int i = 0; i < ARRAYSIZE(weather_id); i++) {
		hookCommand(b00l, h_shooting + mode + ")", c_weather + weather_id[i] + ")", [i] { Hooking::set_session_weather(1, stoi(weather_id[i]), 76, 0); });
	}
	for (int i = 0; i < ARRAYSIZE(sel_pl); i++) {
		hookCommand(b00l, h_shooting + mode + ")", c_kick + sel_pl[i] + ")", [i] {
			if (i == 0) {
				unsigned int Bit = (1 << PLAYER::PLAYER_ID());
				uint64_t args[3] = { -120668417, PLAYER::PLAYER_PED_ID(), 48 };
				Hooking::trigger_script_event(1, args, 3, Bit);
			}
			else if (i == 1) {
				for (int i = 0; i < 33; i++) {
					unsigned int Bit = (1 << i);
					uint64_t args[3] = { -120668417, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 48 };
					Hooking::trigger_script_event(1, args, 3, Bit);
				}
			}
			else {
				unsigned int Bit = (1 << Features::Online::selectedPlayer);
				uint64_t args[3] = { -120668417, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 48 };
				Hooking::trigger_script_event(1, args, 3, Bit);
			}
		});
	}
	for (int i = 0; i < ARRAYSIZE(sel_pl); i++) {
		hookCommand(b00l, h_shooting + mode + ")", c_tp + sel_pl[i] + ")", [i] {
			if (i == 0) {
				unsigned int Bit = (1 << PLAYER::PLAYER_ID());
				uint64_t args[9] = { 1000837481, PLAYER::PLAYER_PED_ID(), 0, -1, 1, 1, 0, 0, 0 };
				Hooking::trigger_script_event(1, args, 9, Bit);
			}
			else if (i == 1) {
				for (int i = 0; i < 33; i++) {
					unsigned int Bit = (1 << i);
					uint64_t args[9] = { 1000837481, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0, -1, 1, 1, 0, 0, 0 };
					Hooking::trigger_script_event(1, args, 9, Bit);
				}
			}
			else {
				unsigned int Bit = (1 << Features::Online::selectedPlayer);
				uint64_t args[9] = { 1000837481, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0, -1, 1, 1, 0, 0, 0 };
				Hooking::trigger_script_event(1, args, 9, Bit);
			}
		});
	}
	for (int i = 0; i < ARRAYSIZE(sel_pl); i++) {
		hookCommand(b00l, h_shooting + mode + ")", c_error + sel_pl[i] + ")", [i] {
			if (i == 0) {
				unsigned int Bit = (1 << PLAYER::PLAYER_ID());
				auto var0 = globalHandle(1625435 + 1 + PLAYER::PLAYER_ID() * 560 + 491).As<std::uint64_t>();
				auto var1 = globalHandle(1643357 + 9).As<std::uint64_t>();
				uint64_t args[8] = { 1000837481, PLAYER::PLAYER_PED_ID(), 10000, 0, 0, var0, var1, var1 };
				Hooking::trigger_script_event(1, args, 8, Bit);
			}
			else if (i == 1) {
				for (int i = 0; i < 33; i++) {
					unsigned int Bit = (1 << i);
					auto var0 = globalHandle(1625435 + 1 + i * 560 + 491).As<std::uint64_t>();
					auto var1 = globalHandle(1643357 + 9).As<std::uint64_t>();
					uint64_t args[8] = { 1000837481, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 10000, 0, 0, var0, var1, var1 };
					Hooking::trigger_script_event(1, args, 8, Bit);
				}
			}
			else {
				unsigned int Bit = (1 << Features::Online::selectedPlayer);
				auto var0 = globalHandle(1625435 + 1 + Features::Online::selectedPlayer * 560 + 491).As<std::uint64_t>();
				auto var1 = globalHandle(1643357 + 9).As<std::uint64_t>();
				uint64_t args[8] = { 1000837481, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 10000, 0, 0, var0, var1, var1 };
				Hooking::trigger_script_event(1, args, 8, Bit);
			}
		});
	}
}

void XScript::moneydrop() {
	normalCommand(c_money, [] { Features::customDropBool2 = !Features::customDropBool2; });
}

void XScript::stealth() {
	std::string params[10] = { "10000000", "9000000", "8000000", "7000000", "6000000", "5000000", "4000000", "3000000", "2000000", "1000000" };
	for (int i = 0; i < ARRAYSIZE(params); i++) {
		normalCommand(c_stealth + params[i] + ")", [i] { std::string params2[10] = { "10000000", "9000000", "8000000", "7000000", "6000000", "5000000", "4000000", "3000000", "2000000", "1000000" }; Any var0 = INT_MAX; UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, 312105838, 1445302971, stoi(params2[i]), 4); UNK3::_NETWORK_SHOP_CHECKOUT_START(var0); });
	}
}

void XScript::cmdSE(int playermode, int id) {
	unsigned int Bit;
	Player ply;
	Player pl2;
	if (playermode == 0) {
		ply = PLAYER::PLAYER_PED_ID();
		pl2 = PLAYER::PLAYER_ID();
		Bit = (1 << pl2);	
		uint64_t* args;
		if (id == 0) {
			args[0] = -120668417;
			args[1] = ply;
			args[2] = 48;
			Hooking::trigger_script_event(1, args, 3, Bit);
		}
		else if (id == 1) {
			args[0] = -1190833098;
			args[1] = ply;
			args[2] = 0;
			args[3] = 6;
			Hooking::trigger_script_event(1, args, 4, Bit);
		}
		else if (id == 2) {
			args[0] = 4119492672;
			args[1] = ply;
			args[2] = 0;
			args[3] = 1;
			Hooking::trigger_script_event(1, args, 4, Bit);
		}
		else if (id == 3) {
			args[0] = 1000837481;
			args[1] = ply;
			args[2] = 0;
			args[3] = -1;
			args[4] = 1;
			args[5] = 1;
			args[6] = 0;
			args[7] = 0;
			args[8] = 0;
			Hooking::trigger_script_event(1, args, 9, Bit);
		}
		else if (id == 4) {
			auto var0 = globalHandle(1625435 + 1 + pl2 * 560 + 491).As<std::uint64_t>();
			auto var1 = globalHandle(1643357 + 9).As<std::uint64_t>();
			args[0] = -1920290846;
			args[1] = ply;
			args[2] = 10000;
			args[3] = 0;
			args[4] = 0;
			args[5] = var0;
			args[6] = var1;
			args[7] = var1;
			Hooking::trigger_script_event(1, args, 8, Bit);
		}
		else if (id == 5) {
			args[0] = 713068249;
			args[1] = ply;
			args[2] = -1432462772;
			args[3] = 1000000;
			Hooking::trigger_script_event(1, args, 4, Bit);
		}
		else if (id == 6) {
			args[0] = 325218053;
			args[1] = ply;
			Hooking::trigger_script_event(1, args, 2, Bit);
		}
		else if (id == 7) {
			args[0] = 566035618;
			args[1] = ply;
			args[2] = -1432407380;
			Hooking::trigger_script_event(1, args, 3, Bit);
		}
	}
	else if (playermode == 1) {
		for (int lmao = 0; lmao < 33; lmao++) {
			ply = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(lmao);
			pl2 = lmao;
			Bit = (1 << pl2);
			uint64_t* args;
			if (id == 0) {
				args[0] = -120668417;
				args[1] = ply;
				args[2] = 48;
				Hooking::trigger_script_event(1, args, 3, Bit);
			}
			else if (id == 1) {
				args[0] = -1190833098;
				args[1] = ply;
				args[2] = 0;
				args[3] = 6;
				Hooking::trigger_script_event(1, args, 4, Bit);
			}
			else if (id == 2) {
				args[0] = 4119492672;
				args[1] = ply;
				args[2] = 0;
				args[3] = 1;
				Hooking::trigger_script_event(1, args, 4, Bit);
			}
			else if (id == 3) {
				args[0] = 1000837481;
				args[1] = ply;
				args[2] = 0;
				args[3] = -1;
				args[4] = 1;
				args[5] = 1;
				args[6] = 0;
				args[7] = 0;
				args[8] = 0;
				Hooking::trigger_script_event(1, args, 9, Bit);
			}
			else if (id == 4) {
				auto var0 = globalHandle(1625435 + 1 + pl2 * 560 + 491).As<std::uint64_t>();
				auto var1 = globalHandle(1643357 + 9).As<std::uint64_t>();
				args[0] = -1920290846;
				args[1] = ply;
				args[2] = 10000;
				args[3] = 0;
				args[4] = 0;
				args[5] = var0;
				args[6] = var1;
				args[7] = var1;
				Hooking::trigger_script_event(1, args, 8, Bit);
			}
			else if (id == 5) {
				args[0] = 713068249;
				args[1] = ply;
				args[2] = -1432462772;
				args[3] = 1000000;
				Hooking::trigger_script_event(1, args, 4, Bit);
			}
			else if (id == 6) {
				args[0] = 325218053;
				args[1] = ply;
				Hooking::trigger_script_event(1, args, 2, Bit);
			}
			else if (id == 7) {
				args[0] = 566035618;
				args[1] = ply;
				args[2] = -1432407380;
				Hooking::trigger_script_event(1, args, 3, Bit);
			}
		}
	}
	else if (playermode == 2) {
		ply = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
		pl2 = Features::Online::selectedPlayer;
		Bit = (1 << pl2);
		uint64_t* args;
		if (id == 0) {
			args[0] = -120668417;
			args[1] = ply;
			args[2] = 48;
			Hooking::trigger_script_event(1, args, 3, Bit);
		}
		else if (id == 1) {
			args[0] = -1190833098;
			args[1] = ply;
			args[2] = 0;
			args[3] = 6;
			Hooking::trigger_script_event(1, args, 4, Bit);
		}
		else if (id == 2) {
			args[0] = 4119492672;
			args[1] = ply;
			args[2] = 0;
			args[3] = 1;
			Hooking::trigger_script_event(1, args, 4, Bit);
		}
		else if (id == 3) {
			args[0] = 1000837481;
			args[1] = ply;
			args[2] = 0;
			args[3] = -1;
			args[4] = 1;
			args[5] = 1;
			args[6] = 0;
			args[7] = 0;
			args[8] = 0;
			Hooking::trigger_script_event(1, args, 9, Bit);
		}
		else if (id == 4) {
			auto var0 = globalHandle(1625435 + 1 + pl2 * 560 + 491).As<std::uint64_t>();
			auto var1 = globalHandle(1643357 + 9).As<std::uint64_t>();
			args[0] = -1920290846;
			args[1] = ply;
			args[2] = 10000;
			args[3] = 0;
			args[4] = 0;
			args[5] = var0;
			args[6] = var1;
			args[7] = var1;
			Hooking::trigger_script_event(1, args, 8, Bit);
		}
		else if (id == 5) {
			args[0] = 713068249;
			args[1] = ply;
			args[2] = -1432462772;
			args[3] = 1000000;
			Hooking::trigger_script_event(1, args, 4, Bit);
		}
		else if (id == 6) {
			args[0] = 325218053;
			args[1] = ply;
			Hooking::trigger_script_event(1, args, 2, Bit);
		}
		else if (id == 7) {
			args[0] = 566035618;
			args[1] = ply;
			args[2] = -1432407380;
			Hooking::trigger_script_event(1, args, 3, Bit);
		}
	}
}

void XScript::tse() {
	for (int i = 0; i < ARRAYSIZE(sel_pl); i++) {
		for(int j = 0; j < ARRAYSIZE(tse_ev); j++){
			normalCommand(c_tse + sel_pl[i] + ", " + tse_ev[j] + ")", [i, j] { cmdSE(i, j); });
		}
	}
}

void XScript::weather() {
	for (int i = 0; i < ARRAYSIZE(weather_id); i++) {
		normalCommand(c_weather + weather_id[i] + ")", [i] { Hooking::set_session_weather(1, stoi(weather_id[i]), 76, 0); });
	}
}

void XScript::kick() {
	for (int i = 0; i < ARRAYSIZE(sel_pl); i++) {
		normalCommand(c_kick + sel_pl[i] + ")", [i] {
			if (i == 0) {
				unsigned int Bit = (1 << PLAYER::PLAYER_ID());
				uint64_t args[3] = { -120668417, PLAYER::PLAYER_PED_ID(), 48 };
				Hooking::trigger_script_event(1, args, 3, Bit);
			}
			else if (i == 1) {
				for (int i = 0; i < 33; i++) {
					unsigned int Bit = (1 << i);
					uint64_t args[3] = { -120668417, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 48 };
					Hooking::trigger_script_event(1, args, 3, Bit);
				}
			}
			else {
				unsigned int Bit = (1 << Features::Online::selectedPlayer);
				uint64_t args[3] = { -120668417, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 48 };
				Hooking::trigger_script_event(1, args, 3, Bit);
			}
		});
	}
}

void XScript::tp() {
	for (int i = 0; i < ARRAYSIZE(sel_pl); i++) {
		normalCommand(c_tp + sel_pl[i] + ")", [i] {
			if (i == 0) {
				unsigned int Bit = (1 << PLAYER::PLAYER_ID());
				uint64_t args[9] = { 1000837481, PLAYER::PLAYER_PED_ID(), 0, -1, 1, 1, 0, 0, 0 };
				Hooking::trigger_script_event(1, args, 9, Bit);
			}
			else if (i == 1) {
				for (int i = 0; i < 33; i++) {
					unsigned int Bit = (1 << i);
					uint64_t args[9] = { 1000837481, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0, -1, 1, 1, 0, 0, 0 };
					Hooking::trigger_script_event(1, args, 9, Bit);
				}
			}
			else {
				unsigned int Bit = (1 << Features::Online::selectedPlayer);
				uint64_t args[9] = { 1000837481, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0, -1, 1, 1, 0, 0, 0 };
				Hooking::trigger_script_event(1, args, 9, Bit);
			}
		});
	}
}

void XScript::transaction() {
	for (int i = 0; i < ARRAYSIZE(sel_pl); i++) {
		normalCommand(c_error + sel_pl[i] + ")", [i] {
			if (i == 0) {
				unsigned int Bit = (1 << PLAYER::PLAYER_ID());
				auto var0 = globalHandle(1625435 + 1 + PLAYER::PLAYER_ID() * 560 + 491).As<std::uint64_t>();
				auto var1 = globalHandle(1643357 + 9).As<std::uint64_t>();
				uint64_t args[8] = { 1000837481, PLAYER::PLAYER_PED_ID(), 10000, 0, 0, var0, var1, var1 };
				Hooking::trigger_script_event(1, args, 8, Bit);
			}
			else if (i == 1) {
				for (int i = 0; i < 33; i++) {
					unsigned int Bit = (1 << i);
					auto var0 = globalHandle(1625435 + 1 + i * 560 + 491).As<std::uint64_t>();
					auto var1 = globalHandle(1643357 + 9).As<std::uint64_t>();
					uint64_t args[8] = { 1000837481, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 10000, 0, 0, var0, var1, var1 };
					Hooking::trigger_script_event(1, args, 8, Bit);
				}
			}
			else {
				unsigned int Bit = (1 << Features::Online::selectedPlayer);
				auto var0 = globalHandle(1625435 + 1 + Features::Online::selectedPlayer * 560 + 491).As<std::uint64_t>();
				auto var1 = globalHandle(1643357 + 9).As<std::uint64_t>();
				uint64_t args[8] = { 1000837481, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 10000, 0, 0, var0, var1, var1 };
				Hooking::trigger_script_event(1, args, 8, Bit);
			}
		});
	}
}




void XScript::XscriptMain() {
	script = fp + XScript::file + last;
	moneydrop();
	stealth();
	//tse();
	weather();
	kick();
	tp();
	transaction();
	for (int i = 0; i < getLines(script); i++) {
		if (checkCommand(prefix[0] + h_key, i)) {
			keypressed(0x6B, "+");
		}
	}
	for (int i = 0; i < getLines(script); i++) {
		if (checkCommand(prefix[0] + h_shooting + sel_pl[0] + ")", i)) {
			shooting1(sel_pl[0]);
		}
	}
	for (int i = 0; i < getLines(script); i++) {
		if (checkCommand(prefix[0] + h_shooting + sel_pl[1] + ")", i)) {
			shooting1(sel_pl[1]);
		}
	}
	for (int i = 0; i < getLines(script); i++) {
		if (checkCommand(prefix[0] + h_shooting + sel_pl[2] + ")", i)) {
			shooting1(sel_pl[2]);
		}
	}
}