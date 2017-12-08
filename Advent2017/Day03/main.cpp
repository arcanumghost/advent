#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

// size of a ring side is 2r+1
// number of items in a ring is 8r
// number of items total through ring... integral? 4rr? not correct...
// (2r+1)^2 is correct, just the area... duh...

int numInRing(int ring)
{
	return 8 * ring;
}

int totalAtRing(int ring)
{
	int side = 2 * ring + 1;
	return side*side;
}

int ring(int squareIndex)
{
	return ceil((sqrt(squareIndex) - 1)*.5);
}

pair<int, int> getCoords(int squareIndex)
{
	pair<int, int> squareCoords;

	int r = ring(squareIndex);
	int indexInRing = squareIndex - totalAtRing(r - 1);

	int upperRight = 2 * r;
	int upperLeft = upperRight + 2 * r;
	int lowerLeft = upperLeft + 2 * r;
	int lowerRight = lowerLeft + 2 * r;

	if (indexInRing < upperRight)
	{
		squareCoords.first = r;
		squareCoords.second = indexInRing - r;
	}
	else if (indexInRing < upperLeft)
	{
		squareCoords.first = upperRight + r - indexInRing;
		squareCoords.second = r;
	}
	else if (indexInRing < lowerLeft)
	{
		squareCoords.first = -r;
		squareCoords.second = upperLeft + r - indexInRing;
	}
	else if (indexInRing < lowerRight)
	{
		squareCoords.first = indexInRing - r - lowerLeft;
		squareCoords.second = -r;
	}
	else
	{
		squareCoords.first = r;
		squareCoords.second = indexInRing - r - lowerRight;
	}

	return squareCoords;
}

int getIndexAtCoords(int x, int y)
{
	int r = max(abs(x), abs(y));

	if (y == r*-1)
		return (x + r) + (6 * r) + totalAtRing(r - 1);
	if (x == r*-1)
		return (r - y) + (4 * r) + totalAtRing(r - 1);
	if (y == r)
		return (r - x) + (2 * r) + totalAtRing(r - 1);
	return (y + r) + totalAtRing(r - 1);
}

int getValueAtCoords(int xIn, int yIn)
{
	if (xIn == 0 && yIn == 0)
		return 1;
	int i = getIndexAtCoords(xIn, yIn);
	int totalValue = 0;
	for (int x = -1; x <= 1; ++x)
		for (int y = -1; y <= 1; ++y)
			if (getIndexAtCoords(xIn+x, yIn+y) < i)
				totalValue += getValueAtCoords(xIn + x, yIn + y);
	return totalValue;
}

void main()
{
	// star 1 is way simpler...
	//pair<int, int> coords = getCoords(265149);
	//cout << abs(coords.first) + abs(coords.second);

	for (int i = 0; i < 1000; ++i)
	{
		pair<int, int> coords = getCoords(i);
		int value = getValueAtCoords(coords.first, coords.second);

		cout << i << "  (" << coords.first << ", " << coords.second << ")  " << value << '\n';
		if (value > 265149)
		{
			cout << "Answer is " << i << " at (" << coords.first << ", " << coords.second << ")\n";
			break;
		}

	}

	string dummy;
	cin >> dummy;
}