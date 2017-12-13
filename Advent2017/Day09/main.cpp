#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "AGStringLib/AGStringLib.h"

using namespace std;

int main()
{
	fstream inputFile{ "input.txt" };

	string line;// = "{{<!!>},{<!!>},{<!!>},{<!!>}}";
	getline(inputFile, line);
	inputFile.close();

	// Process !. to --
	for (int i = 0; i < line.length(); ++i)
		if (line[i] == '!')
		{
			line.erase(i, 2);
			--i;
		}

	// Process <.*> to -*
	bool bInGarbage = false;
	int garbage = 0;
	for (int i = 0; i < line.length(); ++i)
	{
		if (line[i] == '<' && !bInGarbage)
		{
			bInGarbage = true;
			line[i] = '-';
		}
		else if (line[i] == '>' && bInGarbage)
		{
			bInGarbage = false;
			line[i] = '-';
		}
		else if (bInGarbage)
		{
			line[i] = '-';
			garbage++;
		}
	}
	cout << garbage << endl;

	// Strip
	AGStringLib::strip(line, "-");
	AGStringLib::strip(line, ",");
	//cout << line << endl;

	// Get their values
	int depth = 0;
	int value = 0;
	for (int i = 0; i < line.length(); ++i)
	{
		if (line[i] == '{')
			depth++;
		if (line[i] == '}')
		{
			value += depth;
			depth--;
		}
	}

	cout << value << endl;
	cin >> line;
}
