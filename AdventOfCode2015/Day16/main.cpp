#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

bool valid(map<string, int> &ticker, map<string, int> &aunt)
{
	for (pair<const string, int> &p : aunt)
	{
		if((p.first == "cats" || p.first == "trees"))
		{
			if(p.second <= ticker[p.first])
				return false;
		}
		else if((p.first == "pomeranians" || p.first == "goldfish"))
		{
			if(p.second >= ticker[p.first])
				return false;
		}
		else if(p.second != ticker[p.first])
			return false;
	}
	return true;
}

void main()
{
	fstream input {"input.txt",ios::in};
	string line;
	map<string, int> ticker =
	{
		{"children",3},
		{"cats",7},
		{"samoyeds",2},
		{"pomeranians",3},
		{"akitas",0},
		{"vizslas",0},
		{"goldfish",5},
		{"trees",3},
		{"cars",2},
		{"perfumes",1}
	};

	int auntNum = 0;
	while (getline(input, line))
	{
		map<string,int> aunt;
		auntNum++;
		int p1 = line.find_first_of(':',0)+2;
		int p2;
		string key = line.substr(p1,(p2 = line.find_first_of(':',p1))-p1); p2+=2;
		int val = stoi(line.substr(p2,(p1 = line.find_first_of(',',p2))-p2)); p1+=2;
		aunt[key] = val;
		key = line.substr(p1, (p2 = line.find_first_of(':', p1)) - p1); p2 += 2;
		val = stoi(line.substr(p2, (p1 = line.find_first_of(',', p2)) - p2)); p1 += 2;
		aunt[key] = val;
		key = line.substr(p1, (p2 = line.find_first_of(':', p1)) - p1); p2 += 2;
		val = stoi(line.substr(p2, line.length()));
		aunt[key] = val;

		if(valid(ticker, aunt))
			cout << auntNum << endl;
	}

	char c; cin >> c;
}