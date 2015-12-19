#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
	map<pair<int, int>,int> houses;
	fstream input {"input.txt", ios::in | ios::binary};

	char c;
	pair<int, int> santa = {0,0};
	pair<int, int> roboSanta = {0,0};
	houses[santa] = 2;
	while (input >> c)
	{
		// Update location
		switch (c)
		{
			case '^':
				santa.first++;
				break;
			case 'v':
				santa.first--;
				break;
			case '>':
				santa.second++;
				break;
			case '<':
				santa.second--;
				break;
		}

		houses.find(santa) == houses.end() ? houses[santa] = 0 : houses[santa]++;

		swap(santa, roboSanta);
	}

	cout << houses.size();

	// Stop
	char x;
	cin >> x;

	return 0;
}