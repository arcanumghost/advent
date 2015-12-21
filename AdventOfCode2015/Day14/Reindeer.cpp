#include "Reindeer.h"

Reindeer::Reindeer(int speed, int endurance, int recharge)
	: mSpeed (speed), mEndurance (endurance), mRecharge (recharge),
		bFlying (true), time(mEndurance), mPosition(0)
{}

void Reindeer::run()
{
	if(bFlying)
		mPosition += mSpeed;

	time--;
	if (!time)
	{
		bFlying = !bFlying;
		time = bFlying ? mRecharge : mEndurance;
	}
}
