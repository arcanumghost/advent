#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include "AGStringLib\AGStringLib.h"

using namespace std;

bool containsSubString(string fullString, string substr)
{
	return fullString.find(substr.c_str()) != string::npos;
}

class ParsedRoom
{
	string name;
	int id;
	string checksum;
	
public:
	ParsedRoom(string encryptedName);
	bool isReal();
	int getID();
	string rotatedName();
};

void main(int argc, char** argv)
{
	//fstream input {"input.txt"};
	fstream input {"keaton.txt"};
	string line;
	int roomSum = 0;
	while (getline(input, line))
	{
		ParsedRoom x(line);
		if (x.isReal())
		{
			roomSum += x.getID();
			if(containsSubString(x.rotatedName(), "orth"))
				cout << x.rotatedName() << ' ' << x.getID() << endl;
		}
	}

	cout << roomSum << endl;

	string dummy;
	cin >> dummy;

	return;
}

ParsedRoom::ParsedRoom(string encryptedName)
{
	vector<string> checksumSplit = AGStringLib::split(encryptedName, "[]");
	string& code = checksumSplit[0];

	name = code.substr(0, code.length()-3);
	id = atoi(code.substr(code.length()-3).c_str());
	checksum = checksumSplit[1];
}

bool ParsedRoom::isReal()
{
	map<char, int> charSums;
	string strippedName = name;
	AGStringLib::strip(strippedName, "-");

	for (char letter : strippedName)
		if(charSums.find(letter) == charSums.end())
			charSums[letter] = 1;
		else
			charSums[letter]++;

	vector<pair<char,int>> orderedSums(charSums.begin(), charSums.end());

	sort(orderedSums.begin(), orderedSums.end(), [&](pair<char, int> a, pair<char, int> b) -> bool
	{
		return a.second != b.second ? a.second > b.second : a.first < b.first;
	});

	string result;
	for(int i=0; i<5; ++i)
		result.push_back(orderedSums[i].first);
	return result == checksum;
}

int ParsedRoom::getID()
{
	return id;
}

string ParsedRoom::rotatedName()
{
	string rotatedName;

	int netRotation = id % 26;
	for (unsigned char letter : name)
	{
		if (letter == '-')
			letter = ' ';
		else
		{
			letter += netRotation;
			if(letter > 'z')
				letter -= 26;
		}

		rotatedName += letter;
	}
	return rotatedName;
}