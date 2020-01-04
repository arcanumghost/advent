#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "AGStringLib/AGStringLib.h"

using namespace std;

struct program;

struct programLink
{
	string name;
	program* pProgram = nullptr;
	bool bResolved = false;

	programLink(string& _name)
		: name(_name)
	{}
};

struct program  
{
	string name;
	int weight;
	vector<programLink> links;
	program* parent = nullptr;

	program(vector<string>& values)
		: name(values[0])
		, weight(atoi(values[1].c_str()))
	{
		for (int i = 2; i < values.size(); ++i)
			links.push_back(values[i]);
	}

	int getTotalWeight()
	{
		int totalWeight = weight;
		for (programLink pL : links)
			totalWeight += pL.pProgram->getTotalWeight();
		return totalWeight;
	}

	bool isBalanced()
	{
		int correctWeight = 0;
		for (programLink pL : links)
			if (correctWeight == 0)
				correctWeight = pL.pProgram->getTotalWeight();
			else if (correctWeight != pL.pProgram->getTotalWeight())
				return false;
		return true;
	}

	void findUnbalanced(program*& pUnbalancedProgram)
	{
		if (!links.size())
			return;

		for (programLink pL : links)
		{
			if (!pL.pProgram->isBalanced())
			{
				pL.pProgram->findUnbalanced(pUnbalancedProgram);
			}
			if (pUnbalancedProgram)
				return;
		}

		int correctWeight = links[0].pProgram->getTotalWeight();
		bool bLink0IsUnbalanced = true;
		program* pUnbalancedProgramCandidate = nullptr;
		for (int i=1; i<links.size(); ++i)
		{
			int candidateWeight = links[i].pProgram->getTotalWeight();
			if (candidateWeight == correctWeight)
				bLink0IsUnbalanced = false;
			else
				pUnbalancedProgramCandidate = links[i].pProgram;
		}

		if (bLink0IsUnbalanced)
			pUnbalancedProgram = links[0].pProgram;
		else if (pUnbalancedProgramCandidate)
			pUnbalancedProgram = pUnbalancedProgramCandidate;
	}
};

void main()
{
	fstream inputFile { "input.txt" };

	string line;
	vector<program> programs;
	while (getline(inputFile, line))
	{
		vector<string> values = AGStringLib::split(line, " ()->,");
		programs.push_back(values);
	}

	for (program& p : programs)
		for(programLink& pL : p.links)
			for(program& p2 : programs)
				if (p2.name == pL.name)
				{
					pL.pProgram = &p2;
					p2.parent = &p;
				}

	program* headProgram = &programs[0];
	while (headProgram->parent)
		headProgram = headProgram->parent;

	// part 1
	cout << headProgram->name << endl;

	program* unbalancedProgram = nullptr;
	headProgram->findUnbalanced(unbalancedProgram);

	int expectedWeight = unbalancedProgram->parent->links[0].pProgram->getTotalWeight();
	int expectedWeight2 = unbalancedProgram->parent->links[1].pProgram->getTotalWeight();
	if (expectedWeight == unbalancedProgram->getTotalWeight())
		expectedWeight = expectedWeight2;
	for (programLink pL : unbalancedProgram->links)
		expectedWeight -= pL.pProgram->getTotalWeight();

	cout << expectedWeight << endl;

	cin >> line;
}
