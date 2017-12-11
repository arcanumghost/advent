// AGStringLib
// Arcanum Ghost String Library

#include "AGStringLib.h"
#include <iostream>

using namespace std;

namespace AGStringLib
{
	vector<string> split(const string &input, char const* delim)
	{
		vector<string> output;
		
		// Copy to temporary
		char* tempInput = new char[input.length() + 1];
		strcpy_s(tempInput, input.length()+1, input.c_str());

		// Tokenize and store
		while(char* token = strtok_s(nullptr, delim, &tempInput))
			output.push_back(token);

		return output;
	}

	void strip(string &input, char const* delim)
	{
		string::size_type loc;
		while(loc = input.find(delim), loc != string::npos)
			input.erase(loc,1);
	}
}