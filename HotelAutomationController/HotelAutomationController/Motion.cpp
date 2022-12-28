
#include "Motion.h"


void MotionSubject::Attach(ControllerObserver *co)
{
	ControllerObserverList.push_back(co);

}

void MotionSubject::Detach(ControllerObserver *co)
{
	ControllerObserverList.remove(co);

}

void MotionSubject::Notify()
{
/*	list<ControllerObserver *>::iterator it = ControllerObserverList.begin();
	for( ; it != ControllerObserverList.end(); it++ )
	{
		(*it)->Update(this);
	} */
}


Motion::Motion():MotionSubject()
	{

	}

	bool Motion::getMotionDetected()
	{
		return isMotionDetected;
	}

	void Motion::setMotionDetected(bool pMotion)
	{
		isMotionDetected = pMotion;
		//if( isMotionDetected == true)
			Notify(isMotionDetected);
	}

	void Motion::Notify(bool isMotionDetected)
	{
		list<ControllerObserver *>::iterator it = ControllerObserverList.begin();

		for( ; it != ControllerObserverList.end(); it++ )
        {
            (*it)->Update(this,isMotionDetected);
        }


	}

    void Motion::Detach(ControllerObserver *co)
    {
        ControllerObserverList.remove(co);

    }

    void Motion::Attach(ControllerObserver *co)
    {
        ControllerObserverList.push_back(co);

    }

    int Motion::getFloorNumber()
    {
        return floorNumber;

    }
    int Motion::getSubCorridorNumber()
    {
        return subCorridorNumber;

    }

    int Motion::setMotionDetails(int floorN,int subCorridorN)
    {
        floorNumber = floorN;
        subCorridorNumber = subCorridorN;
    }



