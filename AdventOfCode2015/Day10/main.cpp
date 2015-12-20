#include <iostream>
#include <string>

using namespace std;

void main()
{
	string input {"1113122113"};
	string output;

	for (int i = 0; i < 50; ++i)
	{
		// Read and interpret runs
		for (int j = 0; j < input.length();)
		{
			char val = input[j];
			int quantity = 0;

			while (input[j] == val)
			{
				quantity++;
				j++;
			}

			output.append(to_string(quantity) + val);
		}

		swap(input,output);
		output.clear();
	}

	//cout << input << endl; // Actually, don't print that long ass-string
	cout << input.length() << endl;

	// Stop
	char c;
	cin >> c;
}