#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void main()
{
	fstream inputFile{ "input.txt" };

	string line;
	vector<int> instructions;
	while (getline(inputFile, line))
	{
		instructions.push_back(atoi(line.c_str()));
	}

	//instructions = { 0, 3, 0, 1, -3 };

	int nJumps = 0;
	int pInst = 0;
	for (;;)
	{
		if (pInst < 0 || pInst >= instructions.size())
			break;
		int offset = instructions[pInst];
		if (offset >= 3)
			instructions[pInst]--;
		else
			instructions[pInst]++;
		pInst += offset;
		nJumps++;
	}

	cout << nJumps;

	cin >> line;
}