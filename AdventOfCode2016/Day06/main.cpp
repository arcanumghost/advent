#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int lettertotals[8][26];

void PrintMostFrequentLetter(int totals[26])
{
	int lowestIndex = 0;
	int highVal = 100000;
	for (int i = 0; i < 26; ++i)
	{
		if (totals[i] < highVal && totals[i])
		{
			lowestIndex = i;
			highVal = totals[i];
		}
	}
	cout << char('a'+ lowestIndex);
}

int main()
{
	fstream input {"chazinput.txt"};
	string line;

	// Init values
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			lettertotals[i][j] = 0;
		}
	}

	while (getline(input, line))
	{
		for (int i=0; i<line.size(); ++i)
		{
			lettertotals[i][line[i]-'a']++;
		}
	}

	for (int i = 0; i < 8; ++i)
	{
		PrintMostFrequentLetter(lettertotals[i]);
	}	
}