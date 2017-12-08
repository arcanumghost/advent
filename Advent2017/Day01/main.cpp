#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void main()
{
	fstream input{ "input.txt", ios::in };

	string line;
	getline(input, line);

	int total = 0;
	int diff = line.length() / 2;
	for (int i = 0; i < line.length(); ++i)
		total += line[i] == line[(i + diff) % line.length()] ? line[i] - '0' : 0;

	cout << total << endl;

	cin >> line;

}