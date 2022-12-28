	#include "Floor.h"
	#include<iostream>
    using namespace std;

	//Floor Class definition.

	Floor::Floor()
	{


	}

	void Floor::addMainCorridor(MainCorridor *&pCorridor)
	{
		mMainCorridor.push_back(pCorridor);

	}

	void Floor::addSubCorridor(SubCorridor *&pSubCorridor)
	{
		mSubCorridor.push_back(pSubCorridor);

	}



	vector<MainCorridor *> Floor::getAllMainCorridor()
	{
		return mMainCorridor;

	}

	vector<SubCorridor *> Floor::getAllSubCorridor()
	{
		return mSubCorridor;

	}

	void setFloorNumber(int pFloorNumber);

	int getFloorNumber();

