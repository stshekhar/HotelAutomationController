#ifndef _FLOOR_H
#define _FLOOR_H


#include "Corridor.h"


class Floor
{
	int mFloorNumber;
	vector<MainCorridor *> mMainCorridor;
	vector<SubCorridor *> mSubCorridor;

public:
	void addMainCorridor(MainCorridor *&pMainCorridor);

	void addSubCorridor(SubCorridor *&pSubCorridor);

    vector<MainCorridor *> getAllMainCorridor();
    vector<SubCorridor *> getAllSubCorridor();

	//vector<Corridor *>& getCorridor();

    Floor();

	void setFloorNumber(int pFloorNumber)
	{
		mFloorNumber = 	pFloorNumber;
	}

	int getFloorNumber()
	{
		return mFloorNumber;
	}



};
#endif // _FLOOR_H
