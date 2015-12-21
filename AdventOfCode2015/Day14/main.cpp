#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "Reindeer.h"

int main()
{
	// Parse and initialize
	fstream input{"input.txt",ios::in};
	string line;
	vector<Reindeer> reindeer;
	while (getline(input, line))
	{
		// All positive numbers, all we need
		int p1 = line.find_first_of("123456789");
		int p2;
		int speed = stoi(line.substr(p1, (p2 = line.find_first_of(' ', p1)) - p1));
		p1 = line.find_first_of("123456789", p2);
		int time = stoi(line.substr(p1, (p2 = line.find_first_of(' ', p1)) - p1));
		p1 = line.find_first_of("123456789", p2);
		int rest = stoi(line.substr(p1, (p2 = line.find_first_of(' ', p1)) - p1));

		reindeer.push_back(Reindeer(speed,time,rest));
	}

	// Run
	for (int i = 0; i < 2503; ++i)
	{
		for(int r = 0; r < reindeer.size(); ++r)
			reindeer[r].run();
	}

	// Analyze
	int farthest = 0;
	for (int i = 0; i < reindeer.size(); ++i)
	{
		if(reindeer[i].position() > farthest)
			farthest = reindeer[i].position();
	}

	cout << farthest << endl;

	char c;
	cin >> c;
}