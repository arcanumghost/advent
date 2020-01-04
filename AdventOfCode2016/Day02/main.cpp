#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

char buttons[5][5] = 
{ 
	{' ',' ','1',' ',' '},
	{' ','2','3','4',' '},
	{'5','6','7','8','9'},
	{' ','A','B','C',' '},
	{' ',' ','D',' ',' '}
};

map<char, pair<int, int>> direction =
{
	{'U',{-1,0}},
	{'D',{1,0}},
	{'L',{0,-1}},
	{'R',{0,1}}
};

int clamp(const int& _Val, const int& _Min_val, const int& _Max_val)
{
	if (_Val < _Min_val)
		return _Min_val;
	else if (_Val > _Max_val)
		return _Max_val;
	return _Val;
}

void main(int argc, char** argv)
{
	fstream input{ "input.txt" };
	vector<string> instructions;
	string inst;
	while (getline(input, inst))
		instructions.push_back(inst);

	pair<int, int> here = { 2, 0 }; // Location of '5'
	pair<int, int> target = { 0,0 };

	for (string inst : instructions)
	{
		for (char shift : inst)
		{
			target.first = here.first + direction[shift].first;
			target.second = here.second + direction[shift].second;
			target.first = clamp(target.first, 0, 4);
			target.second = clamp(target.second, 0, 4);
			if (buttons[target.first][target.second] != ' ')
			{
				here.first = target.first;
				here.second = target.second;
			}
		}
		cout << buttons[here.first][here.second];
	}

	string dummy;
	cin >> dummy;
}