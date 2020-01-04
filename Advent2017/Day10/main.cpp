#include <iostream>

#include "AGStringLib/AGStringLib.h"

using namespace std;

int main()
{
	// input
	string line = "31,2,85,1,80,109,35,63,98,255,0,13,105,254,128,33";
	const int CIRCLE_SIZE = 256;
	
	// parse input
	//vector<string> iterStrs = AGStringLib::split(line, ",");
	vector<int> iters;
	//for (string& iterStr : iterStrs)
		//iters.push_back(atoi(iterStr.c_str()));
	for (char& c : line)
		iters.push_back(int(c));
	iters.push_back(17);
	iters.push_back(31);
	iters.push_back(73);
	iters.push_back(47);
	iters.push_back(23);

	// set up vars
	vector<int> cir(CIRCLE_SIZE);
	for (int i = 0; i < cir.size(); ++i)
		cir[i] = i;
	int skip = 0;
	int pos = 0;

	// iterate
	for(int i=0; i<64; ++i)
		for (int& iter : iters)
		{
			// Reverse selection
			for (int selPos = pos, selEnd = pos + iter - 1; selPos < selEnd; ++selPos, --selEnd)
				swap(cir[selPos%cir.size()], cir[selEnd%cir.size()]);

			// Advance with skip
			pos += iter + skip++;
		}

	string hexResult;
	for (int i = 0; i < cir.size();)
	{
		int xorResult = 0;
		for (int j = 0; j < 16; ++j, ++i)
		{
			xorResult ^= cir[i];
		}

		int hexValue = xorResult / 16;
		char c = hexValue < 10 ? '0' + hexValue : 'a' + hexValue - 10;
		hexResult.push_back(c);
		hexValue = xorResult % 16;
		c = hexValue < 10 ? '0' + hexValue : 'a' + hexValue - 10;
		hexResult.push_back(c);
	}

	// answer
	cout << hexResult << " " << cir[0] * cir[1] << endl;
	cin >> line;
}