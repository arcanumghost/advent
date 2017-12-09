#include <iostream>
#include <fstream>
#include <string>

#include "AGStringLib/AGStringLib.h"

using namespace std;

void main()
{
	fstream inputFile{ "input.txt" };

	string line;
	int validPhrases = 0;
	while (getline(inputFile, line))
	//line = "oiii ioii iioi iiio";
	{
		vector<string> words = AGStringLib::split(line, " ");
		bool bValid = true;
		for (int i = 0; i < words.size() - 1; ++i)
			for (int j = i + 1; j < words.size(); ++j)
			{
				vector<int> letters(26, 0);
				bool bValidPair = false;
				for (char c : words[i])
					letters[c - 'a']++;
				for (char c : words[j])
					letters[c - 'a']--;
				for (int numC : letters)
					if (numC)
						bValidPair = true;

				if (!bValidPair)
					bValid = false;
			}
				// first star
				//if (words[i] == words[j])
					//bInvalid = true;

		if (bValid)
			validPhrases++;
	}

	cout << validPhrases << endl;

	cin >> line;
}