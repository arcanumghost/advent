#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "AGStringLib\AGStringLib.h"
#include <set>

using namespace std;

// Directional enum
enum Dir
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};
Dir operator++(Dir& d, int)
{
	if (d == Dir::WEST)
		return d = Dir::NORTH;
	return d = static_cast<Dir>(d + 1);
}
Dir operator--(Dir& d, int)
{
	if (d == Dir::NORTH)
		return d = Dir::WEST;
	return d = static_cast<Dir>(d - 1);
}

// Coordinates 
typedef pair<int, int> coord;
// Function to display coordinates
map<Dir, coord> Headings = 
{ 
	{NORTH,	{0,1}},
	{EAST,	{1,0}},
	{SOUTH, {0,-1}},
	{WEST,	{-1,0}}
};

void main(int argc, char** argv)
{
	fstream input{ "input.txt" };
	string inputString;
	getline(input, inputString);
	vector<string> instructions = AGStringLib::split(inputString, ", ");
	set<coord> PreviousLocations;

	coord myLocation {0, 0};
	Dir facing = NORTH;
	for (string &inst : instructions)
	{
		inst[0] == 'R' ? facing++ : facing--;
		int distance = atoi(inst.substr(1).c_str());

		for (;distance--;)
		{
			myLocation.first += Headings[facing].first;
			myLocation.second += Headings[facing].second;

			if (PreviousLocations.find(myLocation) != PreviousLocations.end())
			{
				cout << '(' << myLocation.first << ',' << myLocation.second << ")\n";

				string dummy;
				cin >> dummy;
			}
			else
				PreviousLocations.insert(myLocation);
		}

		cout << inst << " leads to (" << myLocation.first << ',' << myLocation.second << ")\n";
	}
}