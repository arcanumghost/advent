#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

// off to on if 3 adjacent. on to on if 2 or 3 adjacent.
// off otherwise
bool newSwitch(int x, int y, bool *past)
{
	int adj = 0;
	for(int i=max(0,x-1);i<min(100,x+1);++i)
		for(int j=max(0,y-1);j<min(100,y+1);++j)
			if(i!=x && j!=y)
				adj += past[i*100 + j];
	if(past[y*100 + x] && (adj == 2 || adj == 3))
		return true;
	if(!past[y*100] + x] && adj == )
}

int main()
{
	// Read
	fstream input {"test.txt",ios::in};
	string line;
	bool *switches = new bool[100*100];
	bool *buffer = new bool[100*100];
	while (getline(input, line))
	{
		
	}
	input.close();

	// Simulate

	// Print
	int nSwitches = 0;
	for(int x=0;x<100;x++)
		for(int y=0;y<100;y++)
			if(switches[x + y*100])
				nSwitches++;
	cout << nSwitches << endl;
	char c; cin >> c;
}