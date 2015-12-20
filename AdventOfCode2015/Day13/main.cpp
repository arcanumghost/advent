#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

void main()
{
	set<string> peopleSet;
	map<pair<string,string>,int> happiness;

	// Parse
	fstream input {"input.txt", ios::in};
	string line;
	while (getline(input, line))
	{
		string n1 = line.substr(0,line.find_first_of(' '));
		int p = line.find_last_of(' ');
		string n2 = line.substr(p+1,line.length()-p-2);
		p = line.find_first_of("0192837465");
		int h = stoi(line.substr(p,line.find_first_of(' ',p)-p));

		if(line.find("lose") != string::npos)
			h *= -1;

		peopleSet.insert(n1);
		peopleSet.insert(n2);
		happiness[pair<string,string>(n1,n2)] = h;
	}

	// Permute
	vector<string> people(peopleSet.begin(),peopleSet.end());
	people.push_back("you");
	sort(people.begin(),people.end());
	int mostHappiness = INT_MIN;
	do 
	{
		int currentHappiness = 0;
		for (int i = 0; i < people.size(); ++i)
		{
			int j = (i+1)%people.size();
			if(people[i] == "you" || people[j] == "you")
				continue;
			currentHappiness += happiness[pair<string,string>(people[i],people[j])];
			currentHappiness += happiness[pair<string,string>(people[j],people[i])];
		}

		if(currentHappiness > mostHappiness)
			mostHappiness = currentHappiness;
	} while (next_permutation(people.begin(),people.end()));

	// Profit
	cout << mostHappiness;

	char c;
	cin >> c;
}