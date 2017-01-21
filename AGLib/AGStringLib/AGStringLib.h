// AGStringLib.h
// arcanumghost String Lib

#pragma once

#include <string>
#include <vector>

using namespace std;

namespace AGStringLib
{
	vector<string> split(const string &input, char const* delim);
}