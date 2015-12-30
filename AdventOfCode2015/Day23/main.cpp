#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum InstType {JMP, JONE, JEVEN, INC, TRIP, HALF};
struct Instruction
{
	InstType inst;
	bool reg;
	int val;

	Instruction(string s)
	{
		string command {s.substr(0,3)};
		if (command == "jio")		inst = JONE;
		else if (command == "jie")	inst = JEVEN;
		else if (command == "jmp")	inst = JMP;
		else if (command == "inc")	inst = INC;
		else if (command == "tpl")	inst = TRIP;
		else if (command == "hlf")	inst = HALF;

		reg = (s[4] == 'b');
		if(s.find_first_of("+-") != string::npos)
			val = stoi(s.substr(s.find_first_of("+-") + 1));
		if(s.find_first_of('-') != string::npos)
			val *= -1;
	}
	void run(int &a, int &b, int &ip)
	{
		int &t = reg ? b : a;
		switch (inst)
		{
			case JMP:
				ip += val;
				break;
			case JONE:
				if(t == 1)
					ip += val;
				else
					ip++;
				break;
			case JEVEN:
				if(!(t%2))
					ip += val;
				else
					ip++;
				break;
			case INC:
				++t;
				break;
			case TRIP:
				t*=3;
				break;
			case HALF:
				t>>=1;
				break;
		}
		if (inst > JEVEN)
			ip++;
	}
};

int main()
{
	fstream input {"input.txt", ios::in};
	string line;

	// Read
	vector<Instruction> insts;
	while (getline(input, line))
		insts.push_back(Instruction(line));

	// Run
	int regA {1}, regB {0}, ip {0};
	do 
	{
		insts[ip].run(regA, regB, ip);
	} while (ip >= 0 && ip < insts.size());

	cout << regB << endl;
	char c; cin >> c;
}