#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	// Attempt to open input file
	fstream inputFile {"input.txt", ios::in | ios::binary};

	// Analyze contents
	int floor = 0;
	int count = 0;
	char c;
	bool bFirstBasement {true};
	while (++count, inputFile >> c)
	{
		// There are no tricky characters
		if(c == '(')
			floor++;
		else
		{
			floor--;
			// Stop to record the first character that sends Santa to the basement.
			if (floor == -1 && bFirstBasement)
			{
				bFirstBasement = false;
				cout << count << endl;
			}
		}
	}

	// Result
	cout << floor << endl;

	// Stop! I can't read that fast!
	char dummy;
	cin >> dummy;
	return 0;
}