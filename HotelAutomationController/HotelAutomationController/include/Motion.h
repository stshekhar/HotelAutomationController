#ifndef _MOTION_H
#define _MOTION_H


#include<list>
#include<algorithm>
#include<iterator>
//class ControllerObserver;
#include"PowerController.h"
using namespace std;

class ControllerObserver;


class MotionSubject
{
	public:
			virtual void Attach(ControllerObserver *o);
			virtual void Detach(ControllerObserver *o);
			virtual void Notify();
			virtual int getFloorNumber()=0;
			virtual int getSubCorridorNumber()=0;
			virtual bool getMotionDetected()=0;
			virtual int setMotionDetails(int floorNumber,int subCorriderNumber)=0;
			list<ControllerObserver *> ControllerObserverList;

};


class Motion : public MotionSubject
{

    bool isMotionDetected;

    int floorNumber;

    int subCorridorNumber;

public:


	Motion();

	bool getMotionDetected();

	void setMotionDetected(bool pMotion);

	void Notify(bool isMotionDetected);

    void Detach(ControllerObserver *co);
    void Attach(ControllerObserver *co);
    int getFloorNumber();
    int getSubCorridorNumber();
    int setMotionDetails(int floorNumber,int subCorriderNumber);

   // bool getMotionDetected();




};
#endif // _MOTION_H
