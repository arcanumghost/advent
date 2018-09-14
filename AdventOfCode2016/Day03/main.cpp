#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "AGStringLib/AGStringLib.h"

using namespace std;

bool possibleTriangle(int s[3])
{
	int largestIndex = s[0] > s[1] && s[0] > s[2] ? 0 : s[1] > s[2] ? 1 : 2;
	int smallerSum = 0;

	for (int i = 0; i < 3; ++i)
		smallerSum += largestIndex != i ? s[i] : 0;

	return s[largestIndex] < smallerSum;
}

struct trio
{
	int x[3];
};

void main(int argc, char** argv)
{
	fstream input{ "input.txt" };
	
	vector<string> triangles;
	vector<trio> parsedTris;
	string line;

	while (getline(input, line))
		triangles.push_back(line);

	int possibleTriangles = 0;
	for (string triangle : triangles)
	{
		vector<string> sideStrings = AGStringLib::split(triangle, " ");
		parsedTris.push_back({ atoi(sideStrings[0].c_str()), atoi(sideStrings[1].c_str()), atoi(sideStrings[2].c_str()) });
	}

	for(int i=0; i<parsedTris.size(); i+=3)
	{
		for (int j = 0; j < 3; ++j)
		{
			int sides[] = { parsedTris[i].x[j],parsedTris[i + 1].x[j],parsedTris[i + 2].x[j] };

			if (possibleTriangle(sides))
				possibleTriangles++;
		}
	}

	cout << possibleTriangles << endl;

	string dummy;
	cin >> dummy;
}