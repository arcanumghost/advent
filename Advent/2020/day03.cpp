#include "day03.h"

Day03::Day03
{
	fstream input{ "day03.txt" };
	string line;
	while (getline(input, line))
	{
		PasswordDatabase.push_back(PasswordEntry(line.c_str()));
	}
}

void Day03::part1()
{

}


void Day03::part2()
{

}
