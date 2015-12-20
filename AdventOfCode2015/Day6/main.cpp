#include <iostream>
#include <fstream>
#include <string>
#include <functional>

using namespace std;

void runCommand(int *lights, int x1, int y1, int x2, int y2, function<void(int &)> lightfunc)
{
	for(int x=x1; x<=x2; ++x)
		for(int y=y1; y<=y2; ++y)
			lightfunc(lights[x+y*1000]);
}

int main()
{
	fstream input {"input.txt", ios::in};

	// initialize lights
	int *lights = new int[1000*1000];
	memset(lights,0,1000*1000);

	string line;
	while (getline(input, line))
	//line = "turn on 3,3 through 5,5";
	{
		// Parse command
		int pos = 0;
		int pos2 = 0;
		string command = line.substr(0, pos = line.find_first_of("123456789"));
		string s1, s2;
		int x1 = stoi(line.substr(pos,(pos2 = line.find_first_of(',',pos))-pos));
		int y1 = stoi(line.substr(pos2+1,(pos = line.find_first_of(' ',pos2+1))-pos2-1));
		pos += 8; // through and a space
		int x2 = stoi(line.substr(pos,(pos2 = line.find_first_of(',',pos))-pos));
		int y2 = stoi(line.substr(pos2+1,line.length()-pos2-1));

		// Run command
		if(command == "turn off ")
			runCommand(lights, x1, y1, x2, y2, [&](int &b){ b--; if(b < 0) b = 0; });
		else if(command == "turn on ")
			runCommand(lights, x1, y1, x2, y2, [&](int &b){ b++; });
		else if(command == "toggle ")
			runCommand(lights, x1, y1, x2, y2, [&](int &b){ b+=2; });
	}

	input.close();

	// Interpret lights
	int lit = 0;
	for(int i=0; i<1000*1000; ++i)
		lit += lights[i];

	cout << lit << endl;

	// Stop
	char c;
	cin >> c;

	return 0;
}