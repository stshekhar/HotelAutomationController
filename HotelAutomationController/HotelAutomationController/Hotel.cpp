	#include "Hotel.h"

	Hotel::Hotel(string pName)
	{
	  mName = pName;
	}


	void Hotel::addFloor(Floor *pFloor)
	{
		mFloor.push_back(pFloor);
	}

	vector<Floor *> Hotel::getFloor()
	{
	 return mFloor;
	}

	string Hotel::getName()
	{
	 return mName;
	}
