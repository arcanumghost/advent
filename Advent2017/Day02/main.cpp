#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "AGStringLib\AGStringLib.h"

using namespace std;

void main()
{
	fstream input{ "input.txt", ios::in };

	string line;
	while (getline(input, line))
	{
		vector<string> numbers = AGStringLib::split(line, "\t");
		for (string number : numbers)
			cout << number << '\n';
	}

	cin >> line;

}