#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	fstream input {"input.txt", ios::in};

	string line;
	int codeChars = 0;
	while (getline(input, line))
	{
		codeChars += 2;
		for (int i = 0; i < line.length(); ++i)
			if(line[i] == '\\' || line[i] == '\"')
				codeChars++;
	}

	/* Star 1
	{
		codeChars += 2; // beginning and ending double quotes
		for (int i = 1; i < line.length()-1; ++i)
		{
			if (line[i] == '\\')
			{
				codeChars++;
				i++;
				if (line[i] == 'x')
				{
					codeChars+=2;
					i+=2;
				}
			}
		}
	}*/


	cout << codeChars << endl;

	// Stop
	char c;
	cin >> c;

	return 0;
}