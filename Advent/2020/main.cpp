#include <iostream>
#include <fstream>
#include "day03.h"

using namespace std;

void pause()
{
	string dummy;
	cin >> dummy;
}

int main(int argc, char** argv)
{
	Day03 day;

	day.part1();
	day.part2();

	pause();

	return 0;
}