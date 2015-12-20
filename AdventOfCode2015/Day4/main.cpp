#include <iostream>
#include <fstream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#include "md5.h"

using namespace std;

int main()
{
	//string secretkey {"abcdef"};
	string secretkey {"ckczppom"};
	bool foundHash = false;
	for (int i = 0; !foundHash && i < 1000000; ++i)
	{
		char buffer[100];
		string num = to_string(i);
		string hash = md5(secretkey + num);

		if(hash.substr(0,5) == "00000")
		{
			cout << num << ' ' << hash << endl;
			foundHash = true;
		}
	}

	// Stop
	char c;
	cin >> c;

	return 0;
}