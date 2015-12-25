#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct character
{
	int hp;
	int atk;
	int def;

	void attack(character &defender)
	{
		if(defender.def > atk)
		{
			defender.hp--;
		}
		else
		{
			defender.hp -= (atk-defender.def);
		}
	}
};
struct item
{
	int cost;
	int atk;
	int def;
};
bool battle(character &hero, character &boss)
{
	while (boss.hp > 0 && hero.hp > 0)
	{
		hero.attack(boss);
		if (boss.hp > 0)
			boss.attack(hero);
	}
	return boss.hp > 0;
}

int main()
{
	vector<item> weapons
	{
		{8,4,0},
		{10,5,0},
		{25,6,0},
		{40,7,0},
		{74,8,0}
	};
	vector<item> armors
	{
		{0,0,0},
		{13,0,1},
		{31,0,2},
		{53,0,3},
		{75,0,4},
		{102,0,5}
	};
	vector<item> rings
	{
		{0,0,0},
		{0,0,0},
		{25,1,0},
		{50,2,0},
		{100,3,0},
		{20,0,1},
		{40,0,2},
		{80,0,3}
	};

	const character heroTemplate{ 100,0,0 };
	const character bossTemplate{ 103,9,2 };

	int highCost = INT_MIN;
	character hero;
	character boss;
	for(item &weapon : weapons)
		for(item &armor : armors)
			for(item &leftRing : rings)
				for (item &rightRing : rings)
				{
					if(&leftRing == &rightRing)
						continue;
					int cost = weapon.cost + armor.cost + leftRing.cost + rightRing.cost;
					hero = heroTemplate;
					hero.atk = weapon.atk + leftRing.atk + rightRing.atk;
					hero.def = armor.def + leftRing.def + rightRing.def;
					boss = bossTemplate;

					// Print
					if (battle(hero, boss))
					{
						cout << "Hero HP: " << hero.hp << " Boss HP: " << boss.hp << endl;
						cout << "Weapon: " << weapon.cost << ' ' << weapon.atk << ' ' << weapon.def << endl;
						cout << "Armor: " << armor.cost << ' ' << armor.atk << ' ' << armor.def << endl;
						cout << "LRing: " << leftRing.cost << ' ' << leftRing.atk << ' ' << leftRing.def << endl;
						cout << "RRing: " << rightRing.cost << ' ' << rightRing.atk << ' ' << rightRing.def << endl;
						cout << "Total cost: " << cost << endl;
						cout << endl;
						if(cost > highCost)
							highCost = cost;
					}
				}

	cout << "Lowest cost: " << highCost;

	char c; cin >> c;
}
