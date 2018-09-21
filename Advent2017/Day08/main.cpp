#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "AGStringLib/AGStringLib.h"

using namespace std;

enum Inequality
{
	LT,
	LTE,
	GT,
	GTE,
	E,
	NE
};

struct instruction
{
	instruction(vector<string>& parsedInst)
		: condReg(parsedInst[4])
		, condValue(atoi(parsedInst[6].c_str()))
		, instReg(parsedInst[0])
		, instValue(atoi(parsedInst[2].c_str()))
	{
		instMod = parsedInst[1] == "inc" ? 1 : -1;
		string& ineq = parsedInst[5];
		if (ineq == "==")
			condInequality = E;
		else if (ineq == "<=")
			condInequality = LTE;
		else if (ineq == ">=")
			condInequality = GTE;
		else if (ineq == "<")
			condInequality = LT;
		else if (ineq == ">")
			condInequality = GT;
		else
			condInequality = NE;
	}

	bool processCondition(int condRegValue)
	{
		if (condInequality == E)
			return condRegValue == condValue;
		else if (condInequality == NE)
			return condRegValue != condValue;
		else if (condInequality == LT)
			return condRegValue < condValue;
		else if (condInequality == LTE)
			return condRegValue <= condValue;
		else if (condInequality == GT)
			return condRegValue > condValue;
		else if (condInequality == GTE)
			return condRegValue >= condValue;
		return false;
	}

	// if reg inequality value
	string condReg;
	Inequality condInequality;
	int condValue;

	// then reg +=/-= value
	string instReg;
	int instMod;
	int instValue;
};

int main()
{
	fstream inputFile{ "input.txt" };

	// parse instructions from file
	string line;
	vector<instruction> instructions;
	map<string, int> registers;
	while (getline(inputFile, line))
	{
		vector<string> inst = AGStringLib::split(line, " ");
		// dtf inc 304 if nwg >= -1974
		registers[inst[0]] = 0;
		registers[inst[4]] = 0;
		instructions.push_back(inst);
	}

	inputFile.close();

	int largest = INT_MIN;

	// process instructions on registers
	for (instruction& inst : instructions)
	{
		if (inst.processCondition(registers[inst.condReg]))
			registers[inst.instReg] += inst.instMod * inst.instValue;

		// now... what was the question again?
		for (pair<string, int> reg : registers)
			if (reg.second > largest)
				largest = reg.second;
	}

	// now... what was the question again?
	for (pair<string, int> reg : registers)
		if (reg.second > largest)
			largest = reg.second;

	cout << largest;
	cin >> line;
}
