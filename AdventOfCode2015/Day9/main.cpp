#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main()
{
	// Read cities and map distances
	map<pair<string,string>,int> distances;

	fstream input {"input.txt", ios::in};
	string line;
	set<string> citySet;
	while (getline(input, line))
	{
		int sp = line.find_first_of(' ');
		int eq = line.find_first_of('=');

		string c1 = line.substr(0,sp);
		string c2 = line.substr(sp+4,eq-sp-5);
		int dist = stoi(line.substr(eq+2,line.length()-eq-2));

		citySet.insert(c1);
		citySet.insert(c2);
		distances[pair<string,string>(c2,c1)] = dist;
		distances[pair<string,string>(c1,c2)] = dist;
	}
	input.close();
	
	vector<string> cities(citySet.begin(), citySet.end());
	sort(cities.begin(), cities.end());
	// 40320 permutations to try, just do it.
	int hiDist = 0;
	do 
	{
		int thisDist = 0;
		// Travel
		for (int i = 0; i < cities.size()-1; ++i)
		{
			thisDist += distances[pair<string,string>(cities[i],cities[i+1])];
		}
		if(thisDist > hiDist)
			hiDist = thisDist;
	} while(next_permutation(cities.begin(), cities.end()));

	cout << hiDist << endl;

	// Stop
	char c;
	cin >> c;
}