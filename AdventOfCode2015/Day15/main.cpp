#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

union ingredient
{
	struct props
	{
		int capacity;
		int durability;
		int flavor;
		int texture;
		int calories;
	}props;
	int m[4];
};

int score(vector<ingredient> &ing, vector<int> &amt)
{
	ingredient total {0,0,0,0};
	for(int i=0;i<amt.size();++i)
		for(int j=0; j<4;++j)
			total.m[j] += ing[i].m[j]*amt[i];
	return total.m[0]*total.m[1]*total.m[2]*total.m[3];
}
int calories(vector<ingredient> &ing, vector<int> &amt)
{
	int cal = 0;
	for(int i=0; i<amt.size(); ++i)
		cal += ing[i].props.calories*amt[i];
	return cal;
}
int nextNum(string &line, int &startpos)
{
	int p1 = line.find_first_of("-0123456789", startpos);
	int p2 = line.find_first_of(',', p1);
	if(p2 == -1) p2 = line.length();
	int val = stoi(line.substr(p1,p2-p1));
	startpos = p2;
	return val;
}

void main()
{
	// Read the ingredients
	fstream input{"input.txt",ios::in};
	string line;
	vector<ingredient> ings;
	while (getline(input, line))
	{
		int pos = 0;
		ingredient ing;
		for (int i = 0; i < 4; ++i)
			ing.m[i] = nextNum(line, pos);
		ing.props.calories = nextNum(line, pos);
		ings.push_back(ing);
	}

	vector<int> amt {30,30,20,20}; // Started with head-guessed 500 cal.
	int bestScore = score(ings,amt);
	int time = 0;
	for (int i = 0; i < 1000; ++i)
	{
		// Organically move from center to better solutions
		int from = rand()%amt.size();
		int to = from; while(from == to) to = rand()%amt.size();
		amt[from]--;
		amt[to]++;
		int thisScore = score(ings,amt);
		if(thisScore > bestScore && calories(ings, amt) == 500)
		{
			bestScore = thisScore;
			time = 0;
		}
		else
		{
			time++;
			amt[from]++;
			amt[to]--;
		}
	}


	cout << score(ings, amt) << ' ' << time <<  endl;

	char c;
	cin >> c;
}