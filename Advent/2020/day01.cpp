#include "day01.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Day01::Day01()
{
	fstream input {"day01.txt"};
	string line;
	while(getline(input, line))
	{
		values.push_back(atoi(line.c_str()));
	}
}

void Day01::part1()
{
	for (int val : values)
	{
		for (int val2 : values)
		{
			if (val + val2 == 2020)
			{
				cout << val << " and " << val2 << " multiply to " << val*val2 << endl;
			}
		}
	}
}

void Day01::part2()
{
	for (int val : values)
	{
		for (int val2 : values)
		{
			for (int val3 : values)
			{
				if (val + val2 + val3 == 2020)
				{
					cout << val << ", " << val2 << ", and " << val2 << " multiply to " << val*val2*val3<< endl;
				}
			}
		}
	}
}