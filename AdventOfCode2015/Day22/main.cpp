#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

enum SpellType
{
	MAGIC_MISSILE,
	DRAIN,
	SHIELD,
	POISON,
	RECHARGE
};
struct character
{
	int hp;
	int mp;
	int atk;
	int def;

	int turnsPoisoned;
	int turnsCharging;
	int turnsShielded;

	int totalMP;

	character(int _hp, int _mp, int _atk)
		: hp(_hp), mp(_mp), atk(_atk), def(0), totalMP(0),
			turnsPoisoned(0),turnsCharging(0),turnsShielded(0)
	{}
	void attack(character &defender)
	{
		if (defender.def > atk)
		{
			defender.hp--;
		}
		else
		{
			defender.hp -= (atk - defender.def);
		}
	}
	void tick()
	{
		if (turnsCharging)
		{
			turnsCharging--;
			mp+=101;
		}
		if (turnsPoisoned)
		{
			turnsPoisoned--;
			hp-=3;
		}
		if (turnsShielded)
		{
			turnsShielded--;
		}
		else
		{
			def = 0;
		}
	}
	void cast(SpellType spell, character &defender)
	{
		switch (spell)
		{
			case MAGIC_MISSILE:
				mp-=53;
				totalMP += 53;
				if(mp<0) break;
				defender.hp-=4;
				break;
			case DRAIN:
				mp-=73;
				totalMP += 73;
				if (mp<0) break;
				defender.hp-=2;
				hp+=2;
				break;
			case SHIELD:
				mp-=113;
				totalMP += 113;
				if (mp<0) break;
				turnsShielded=6;
				def=7;
				break;
			case POISON:
				mp-=173;
				totalMP += 173;
				if (mp<0) break;
				defender.turnsPoisoned=6;
				break;
			case RECHARGE:
				mp-=229;
				totalMP += 229;
				if (mp<0) break;
				turnsCharging=5;
				break;
		}
	}
};

int main()
{
	const character heroTemplate( 50,500,0 );
	const character bossTemplate{ 71,0,10 };
	vector<SpellType> spellOrder;
	// Ex 1:
	//vector<SpellType> spellOrder {POISON,MAGIC_MISSILE};
	//const character heroTemplate{10,250,0};
	//const character bossTemplate{13,0,8};
	// Ex 2:
	//vector<SpellType> spellOrder {RECHARGE,SHIELD,DRAIN,POISON,MAGIC_MISSILE};
	//const character heroTemplate{ 10,250,0 };
	//const character bossTemplate{14,0,8};

	for(int i=0;i<5;++i)
		for(int j=0;j<10;++j)
			spellOrder.push_back(SpellType(i));

	int lowCost = INT_MAX;

	for(int j=0; j<1000000000; ++j)
	{
		int i = 0;
		character hero(heroTemplate);
		character boss(bossTemplate);
		// battle
		while (boss.hp > 0 && hero.hp > 0 && hero.mp > 0)
		{
			hero.hp--;
			if(hero.hp > 0)
			{
				hero.tick(); boss.tick();
				hero.cast(SpellType(rand()%5), boss);
			}
			if(hero.mp < 0 || hero.hp < 0)
				continue;
			if (hero.hp > 0 && boss.hp > 0)
			{
				hero.tick(); boss.tick();
			}
			if(hero.hp > 0 && boss.hp > 0)
			{
				boss.attack(hero);
			}
			++i;
		}
		if(boss.hp <= 0)
			cout << "Won! MP spent: " << hero.totalMP << endl;
		if(boss.hp <= 0 && hero.totalMP < lowCost)
		{
			lowCost = hero.totalMP;
		}
		else
		{
			//cout << "Hero: (" << hero.hp << ',' << hero.mp << ") Boss: (" << boss.hp << ") MP Used: " << hero.totalMP << endl;
		}
	}

	cout << "Lowest cost: " << lowCost;

	char c; cin >> c;
}
