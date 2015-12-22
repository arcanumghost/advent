#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	fstream input {"cryan.txt", ios::in};

	string line;
	int totalPaper = 0;
	int totalRibbon = 0;
	while(getline(input, line))
	{
		// Split in to strings
		int x = line.find_first_of('x');
		int x2 = line.find_last_of('x');
		string dimString[3];
		dimString[0] = line.substr(0,x);
		dimString[1] = line.substr(x+1,x2-x-1);
		dimString[2] = line.substr(x2+1,line.length()-x2-1);

		// Convert to int
		int dim[3];
		for (int i : {0, 1, 2})
			dim[i] = atoi(dimString[i].c_str());

		// Build areas
		int areas[3];
		areas[0] = dim[0]*dim[1];
		areas[1] = dim[1]*dim[2];
		areas[2] = dim[2]*dim[0];

		// Total ribbon
		int skipDim = dim[0] > dim[1] ? 0 : 1;
		if(dim[skipDim] < dim[2]) skipDim = 2;
		for(int i : {0,1,2})
			if(i != skipDim)
				totalRibbon += 2*dim[i];
		totalRibbon += areas[0]*dim[2];

		// Total
		totalPaper += 2*(areas[0]+areas[1]+areas[2]);
		totalPaper += min(areas[0],min(areas[1],areas[2]));
	}
	// Display answer
	cout << totalPaper << endl;
	cout << totalRibbon << endl;

	// Wait
	char c; cin >> c;

	return 0;
}