#pragma once

#include <string>
#include <vector>

using namespace std;

struct PasswordEntry
{
	PasswordEntry(string line);

	int min;
	int max;
	char letter;
	string password;

	bool valid();
	bool tobogganValid();
};

class Day02
{
	vector<PasswordEntry> PasswordDatabase;

public:
	Day02();
	void part1();
	void part2();
};