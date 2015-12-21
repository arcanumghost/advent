#pragma once

class Reindeer
{
	int mSpeed;		// km/s while flying
	int mEndurance;	// s flying before resting
	int mRecharge;	// s resting before flying again

	bool bFlying;	// State
	int time;		// Time remaining in state

	int mPosition;	// Distance traveled

public:
	Reindeer(int speed, int endurance, int recharge);
	void run();
	int position() { return mPosition; }
};