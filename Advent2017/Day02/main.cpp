#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "AGStringLib\AGStringLib.h"

using namespace std;

void main()
{
	fstream input{ "input.txt", ios::in };

	string line;
	int checksum = 0;
	while (getline(input, line))
	{
		vector<string> stringNumbers = AGStringLib::split(line, "\t");
		vector<int> intNumbers;
		for (string& sNum : stringNumbers)
			intNumbers.push_back(atoi(sNum.c_str()));

		for (int i = 0; i<intNumbers.size()-1; ++i)
			for (int j = i+1; j<intNumbers.size(); ++j)
			{
				int highNum = intNumbers[i];
				int lowNum = intNumbers[j];
				if (highNum < lowNum)
					swap(lowNum, highNum);

				if (highNum % lowNum == 0)
					checksum += highNum / lowNum;
			}
	}

	cout << checksum;
	cin >> line;

}