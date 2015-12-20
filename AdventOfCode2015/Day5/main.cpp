#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool nice1(const string &testWord);
bool nice2(const string &testWord);

int main()
{
	fstream input{"input.txt", ios::in | ios::binary};
	
	string line;
	int niceWords = 0;
	while (getline(input, line))
	{
		if(nice2(line))	niceWords++;
	}

	input.close();

	cout << niceWords << endl;

	// Stop
	char c;
	cin >> c;

	return 0;
}

bool nice1(const string &testWord)
{
	// nice if 3 vowels
	int vowels = 0;
	// does not contain ab, cd, pq, or xy
	bool naughtypair = false;
	// one letter repeats
	bool nicepair = false;

	// Collect data
	for (int i = 0; i < testWord.length(); ++i)
	{
		switch (testWord[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				vowels++;
		}

		if (i)
		{
			string charPair = testWord.substr(i-1,2);
			if(charPair == "ab" || charPair == "cd" || charPair == "pq" || charPair == "xy")
				naughtypair = true;

			if(charPair[0] == charPair[1])
				nicepair = true;
		}
	}

	// Evaluate word
	return vowels >= 3 && nicepair && !naughtypair;
}

bool nice2(const string &testWord)
{
	// nice if doubled pair
	bool doubledPair = false;
	// nice if sandwich
	bool letterSandwich = false;

	for (int i = 0; i < testWord.length(); ++i)
	{
		if (i)
		{
			string testPair = testWord.substr(i-1,2);
			if(testWord.find(testPair,i+1) != string::npos)
				doubledPair = true;
		}

		if (i >= 2 && testWord[i] == testWord[i-2])
			letterSandwich = true;
	}

	return letterSandwich && doubledPair;
}
