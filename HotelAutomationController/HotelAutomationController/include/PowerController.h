#ifndef _PC_H
#define _PC_H

#include "Motion.h"
#include "PowerCriteria.h"
#include "Hotel.h"
#include<map>

using namespace std;

class MotionSubject;
//class Motion;


class ControllerObserver
{
public:
	virtual ~ControllerObserver();
	virtual void Update(MotionSubject* theChangedSubject,bool isMotion) = 0;
	//ControllerObserver();

};


class PowerController:public ControllerObserver
{
    Hotel *mHotel;
    PowerCriteria *mPC;
	MotionSubject *mMotion;
public:
	map<SubCorridor *,SubCorridor *> lastToggleSubCorridor;
	PowerController();
	virtual ~PowerController();
	virtual void Update(MotionSubject *m,bool isMotion);
	void toggleLights(bool isMotion);
	void switchACOnAtSubCorridor(SubCorridor *subCorridor);
	void switchACOffAtSubCorridor(SubCorridor *subCorridor);
	void switchLightOnAtSubCorridor(SubCorridor *subCorridor);
	void switchLightOffAtSubCorridor(SubCorridor *subCorridor);
    bool isLightBulbSwitchedOnAtSubCorridor(SubCorridor *subCorridor);
    Floor *getMatchingfloorNumber();
    SubCorridor *getMatchingSubCorridorNumber(Floor *f);
    void SetDetails(MotionSubject *m,Hotel *h);

};






#endif // _PC_H
