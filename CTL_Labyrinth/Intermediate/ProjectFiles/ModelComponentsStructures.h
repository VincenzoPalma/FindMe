#pragma once

#include <map>
#include <string>

struct State
{
	int id;
	std::map<std::string, bool> Properties;
};

struct Transition {
	State* From;
	State* To;
};