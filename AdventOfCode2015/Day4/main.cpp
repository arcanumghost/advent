#include <iostream>
#include <fstream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#include "md5.h"

using namespace std;

int main()
{
	string secretkey {"ckczppom"};
	bool foundHash = false;
	for (int i = 0; !foundHash; ++i)
	{
		// Hash
		string hash = md5(secretkey + to_string(i));

		// Check
		if(hash.substr(0,6) == "000000")
		{
			cout << i << ' ' << hash << endl;
			foundHash = true;
		}
	}

	// Stop
	char c;
	cin >> c;

	return 0;
}