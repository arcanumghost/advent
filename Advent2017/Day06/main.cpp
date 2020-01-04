#include <iostream>
#include <vector>
#include <string>

using namespace std;

void main()
{
	// Let's do this the Seth way for once ;D
	const char* numberString = "4	1	15	12	0	9	9	5	5	8	7	3	14	5	12	3";
	//const char* numberString = "0 2 7 0";
	vector<int> buckets;
	string value;
	for (const char* c = numberString; *c; ++c)
	{
		if (*c >= '0' && *c <= '9')
		{
			value.push_back(*c);
		}
		else
		{
			buckets.push_back(atoi(value.c_str()));
			value.clear();
		}
	}
	buckets.push_back(atoi(value.c_str()));

	vector<vector<int>> previousStates;
	int iterations = 0;
	int firstRepeatedInstance = 0;
	bool bSeenBefore = false;
	while (!bSeenBefore)
	{
		// Find largest bucket index
		int largestNumber = 0;
		for (int num : buckets)
			if (num > largestNumber)
				largestNumber = num;
		int bucketIndex = 0;
		for (; bucketIndex < buckets.size(); ++bucketIndex)
			if (buckets[bucketIndex] == largestNumber)
				break;

		// redistribute
		buckets[bucketIndex] = 0;
		while (largestNumber--)
			buckets[(++bucketIndex) % buckets.size()]++;

		iterations++;

		// evaluate for copy
		for (int i = 0; i < previousStates.size(); ++i)
		{
			vector<int>& previousState = previousStates[i];
			if (previousState == buckets)
			{
				bSeenBefore = true;
				firstRepeatedInstance = i + 1;
			}
		}
		previousStates.push_back(buckets);
	}

	cout << iterations << endl;
	cout << iterations - firstRepeatedInstance;

	cin >> value;
}