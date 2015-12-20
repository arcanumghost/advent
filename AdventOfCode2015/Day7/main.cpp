#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<string,string> instructions;
map<string,unsigned short> solved;

unsigned short run(string &wire);

unsigned short value(string &val)
{
	// With this cache, <1s
	// Without cache... it's over 8hrs
	if(solved.find(val) != solved.end())
		return solved[val];
	
	if(instructions.find(val) != instructions.end())
	{
		solved[val] = run(val);
		return solved[val];
	}
	return stoi(val);
}

unsigned short run(string &wire)
{
	string inst = instructions[wire];

	//cout << wire << " <- " << inst << endl;

	// Parse instruction
	int p1 = inst.find_first_of(' ');
	int p2 = inst.find_last_of(' ');
	
	if(p1 == string::npos)		// Raw value
		return value(inst);
	else if(p1 == p2)			// NOT
		return ~value(inst.substr(p1+1,inst.length()-p1-1));
	else						// AND/OR/LSHIFT/RSHIFT
	{
		string left = inst.substr(0,p1);
		string mid = inst.substr(p1+1,p2-p1-1);
		string right = inst.substr(p2+1,inst.length()-p1-1);

		if(mid == "AND")
			return value(left) & value(right);
		if(mid == "OR")
			return value(left) | value(right);
		if(mid == "LSHIFT")
			return value(left) << value(right);
		if(mid == "RSHIFT")
			return value(left) >> value(right);
	}

	
	return 0;
}

int main()
{
	fstream input {"input.txt", ios::in};

	string line;
	// Build map
	while (getline(input, line))
	{
		// Put in to instructions map via <output, input> mapping
		int pos;
		string inst = line.substr(0,pos = line.find_first_of('-')-1);
		string wire = line.substr(pos+4,line.length()-pos-3);
		instructions[wire] = inst;
	}

	// Recursively process
	string start {"a"};
	int result1 = run(start);
	cout << result1 << endl;

	solved.clear();
	solved["b"] = result1;
	int result2 = run(start);
	cout << result2 << endl;

	// Stop
	char c;
	cin >> c;

	return 1;
}