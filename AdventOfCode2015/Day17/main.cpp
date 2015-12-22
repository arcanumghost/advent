#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Returns number of containers in solution
int valid(vector<int> &buckets, int mask)
{
	int total = 0;
	int nBuckets = 0;
	for (int i = 0; i < buckets.size(); ++i)
		if(mask>>i&1)
		{
			total += buckets[i];
			nBuckets++;
		}

	if(total != 150)
		nBuckets = 0;

	return nBuckets;
}

int main()
{
	// Read buckets
	fstream input {"input.txt", ios::in};
	string line;
	vector<int> buckets;
	while (getline(input, line))
	{
		buckets.push_back(stoi(line));
	}
	input.close();

	// Create bitset
	int mask = 0;
	for(int i=0; i<buckets.size(); ++i)
		mask = (mask<<1) + 1;
	mask++;

	// Test all combinations
	int solutions = 0;
	int minBuckets = 20;
	int thisBuckets = 0;
	while(--mask)
		if(thisBuckets = valid(buckets,mask))
		{
			if(thisBuckets < minBuckets)
			{
				minBuckets = thisBuckets;
				solutions = 0;
			}
			if(thisBuckets == minBuckets)
				solutions++;
		}

	// Display
	cout << solutions << endl;
	char c; cin >> c;
}