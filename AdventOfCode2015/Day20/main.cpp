#include <iostream>
#include <string>

using namespace std;

// input 3600000

// Find sum of factors (not prime)

int main()
{
	int house = 831600; // Start at previous input
	int total = 0;
	for (; total <= 36000000; ++house)
	{
		total = 0;
		for (int i = 1; i <= house; ++i)
		{
			if(house%i == 0 && house <= i*50)
				total += i*11;
		}
		if(total > 33000000) cout << house << ':' << total << endl;
	}

	cout << house << ' ' << total << endl;
	char c; cin >> c;
}