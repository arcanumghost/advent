#include <iostream>
#include <string>

using namespace std;

bool valid(const string &password);
void next(string &password);

int main()
{
	string password {"hepxcrrq"};

	do 
	{
		next(password);
	} while (!valid(password));

	cout << password << endl;

	do 
	{
		next(password);
	} while (!valid(password));

	cout << password << endl;

	// Stop
	char c;
	cin >> c;
}

void next(string &password)
{
	password[7]++;
	for (int i = 7; password[i] == 123; i--)
	{
		password[i] = 'a';
		password[i-1]++;
	}
}

bool valid(const string &password)
{
	bool hasStraight = false;
	bool badChar = false;
	int firstPair = -1;
	bool twoPair = false;

	for (int i = 0; i < password.length(); ++i)
	{
		if (i >= 2 &&
			password[i] == (password[i - 1] + 1) && password[i] == (password[i - 2] + 2))
		{
			hasStraight = true;
		}

		if(i > 1 && password[i] == password[i-1])
		{
			if(firstPair == -1)
				firstPair = i;
			else if(firstPair < i-1 && password[firstPair] != password[i])
				twoPair = true;
		}

		if(password[i] == 'i' || password[i] == 'o' || password[i] == 'l')
			badChar = true;
	}

	return hasStraight && !badChar && twoPair;
}