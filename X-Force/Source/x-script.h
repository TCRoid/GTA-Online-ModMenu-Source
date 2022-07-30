#pragma once

namespace XScript
{
	bool getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs);
	extern std::string file;
	void XscriptMain();
	int getLines(std::string f);
	std::string readLine(std::string f, int n);
	bool checkCommand(std::string cmd, int line);
	void executeCommand(int line, std::string cmd, std::function<void()> function);
	void shooting1(std::string mode);
	void moneydrop();
	void hookCommand(bool condition, std::string thiscmd, std::string cmd, std::function<void()> function);
	void normalCommand(std::string thiscmd, std::function<void()> function);
	std::string getParam(std::string cmd);
	void tse();
	void cmdSE(int playermode, int id);
	void weather();
	void stealth();
	void kick();
	void tp();
	void keypressed(int key, std::string key2);
	void transaction();
};