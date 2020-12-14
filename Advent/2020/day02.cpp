#include <iostream>
#include <fstream>
#include "AGStringLib.h"
#include "day02.h"

using namespace std;

PasswordEntry::PasswordEntry(string line)
{
	vector<string> parts = AGStringLib::split(line, "- :");
	min = atoi(parts[0].c_str());
	max = atoi(parts[1].c_str());
	letter = parts[2][0];
	password = parts[3];
}

bool PasswordEntry::valid()
{
	int num = 0;
	for (char c : password)
	{
		if (c == letter)
		{
			num++;
		}
	}
	return num >= min && num <= max;
}

bool PasswordEntry::tobogganValid()
{
	bool minTest = password[min - 1] == letter;
	bool maxTest = password[max - 1] == letter;
	return minTest != maxTest;
}

Day02::Day02()
{
	fstream input{ "day02.txt" };
	string line;
	while (getline(input, line))
	{
		PasswordDatabase.push_back(PasswordEntry(line.c_str()));
	}
}

void Day02::part1()
{
	int passwordcount = 0;
	for (PasswordEntry& entry : PasswordDatabase)
		if (entry.valid())
			passwordcount++;
	cout << passwordcount << endl;
}

void Day02::part2()
{
	int passwordcount = 0;
	for (PasswordEntry& entry : PasswordDatabase)
		if (entry.tobogganValid())
			passwordcount++;
	cout << passwordcount << endl;
}