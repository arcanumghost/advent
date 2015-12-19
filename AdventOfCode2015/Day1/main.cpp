#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	// Gotta find something cleaner...

	// Attempt to open input file
	fstream inputFile;
	inputFile.open("input.txt", ios::in | ios::binary | ios::beg );
	if(!inputFile.is_open()) return -1;

	// Find the size
	streampos streamPos = inputFile.tellg();
	inputFile.seekg(0,ios::end);
	streampos streamEnd = inputFile.tellg();

	// Read file
	char *fileContents = new char[streamEnd - streamPos];	// Don't print this, no terminator :)
	inputFile.seekg(0,ios::beg);
	inputFile.read(fileContents, streamEnd);
	inputFile.close();

	// Analyze contents
	int floor = 0;
	for (int i=0; streamPos != streamEnd; ++i, streamPos+=1)
		fileContents[i] == '(' ? floor++ : floor--;

	// Result
	cout << floor << endl;

	// Stop! I can't read that fast!
	char dummy;
	cin >> dummy;
	return 0;
}