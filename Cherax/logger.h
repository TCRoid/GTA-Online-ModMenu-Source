#pragma once
#include "common.h"

class Logger
{
public:
	explicit Logger();
	~Logger();

private:
	FILE* fp;
};

inline Logger* g_logger{};