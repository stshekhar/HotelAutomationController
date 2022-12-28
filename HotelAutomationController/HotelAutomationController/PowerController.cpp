#include "PowerController.h"

PowerController::PowerController()
{



}

void PowerController::SetDetails(MotionSubject *m,Hotel *h)
{
    mMotion = m;
	mHotel = h;
	mMotion->Attach(this);
}

 ControllerObserver::~ControllerObserver(){}

PowerController::~PowerController()
{

	mMotion->Detach(this);

}


void PowerController::switchACOnAtSubCorridor(SubCorridor *subCorridor) {
		subCorridor->getAllAC()[0]->setSwitchState(true);
	}


void PowerController::switchACOffAtSubCorridor(SubCorridor *subCorridor) {
		subCorridor->getAllAC()[0]->setSwitchState(false);
	}



void PowerController::switchLightOnAtSubCorridor(SubCorridor *subCorridor) {
		subCorridor->getAllLight()[0]->setSwitchState(true);
	}


void PowerController::switchLightOffAtSubCorridor(SubCorridor *subCorridor) {
		subCorridor->getAllLight()[0]->setSwitchState(false);
	}



bool PowerController::isLightBulbSwitchedOnAtSubCorridor(SubCorridor *subCorridor) {
		return subCorridor->getAllLight()[0]->getSwitchState();
	}


Floor* PowerController::getMatchingfloorNumber()
		{
			if(mHotel->getFloor().size() >= mMotion->getFloorNumber())
				return mHotel->getFloor()[mMotion->getFloorNumber()-1];
			else
                return null;
		}


SubCorridor* PowerController::getMatchingSubCorridorNumber(Floor *floor)
		{
		    vector<SubCorridor *> sb = floor->getAllSubCorridor();
		    int sbSize = sb.size();
		    int mSize = mMotion->getSubCorridorNumber();
			if( mSize <= sbSize )
				return sb[mSize - 1];
			else
				return null;
    	}


void PowerController::Update(MotionSubject *theChangedSubject,bool isMotion)
{
//	if(*theChangedSubject == *mMotion)
//	{
		//if(isMotion)
			toggleLights(isMotion);
//	}
}

void PowerController::toggleLights(bool isMotion)
{
	Floor *f = getMatchingfloorNumber();
	if(!f)
    {
        cout<<"Non Matching Floor Number Found. Please see hotel details below."<<endl;
        return;

    }
	mPC = new PowerCriteria(f);
	mPC->calculatePowerCriteria();

	vector<SubCorridor *> sc = f->getAllSubCorridor();
	SubCorridor *otherSubCorridor;
	//so = sc[0];


	SubCorridor *s = getMatchingSubCorridorNumber(f);
	if(!s)
    {
        cout<<"Non Matching SubCorridor Number Found. Please see hotel details below. "<<endl;
        return;

    }
	if(isMotion)
	{
		if( !isLightBulbSwitchedOnAtSubCorridor(s) )
		{
			switchLightOnAtSubCorridor(s);
		}
	}
	else
	{
		if( isLightBulbSwitchedOnAtSubCorridor(s) )
		{
			switchLightOffAtSubCorridor(s);
		}

	}

	if( mPC->isPowerCriteriaExceed(f) )
	{

		for(int i=0;i<sc.size();i++)
		{
			if(sc[i]->getCorridorNumber() != s->getCorridorNumber())
			{
				otherSubCorridor = sc[i];
				break;
			}
		}
		switchACOffAtSubCorridor(otherSubCorridor);
		lastToggleSubCorridor.insert(pair<SubCorridor *,SubCorridor *>(s,otherSubCorridor) );
		//lastToggleSubCorridor[s] = otherSubCorridor;//store toggle subcorridor which was switched off and corresponding subcorridor which was switched on.
	}
	else
	{
		//Floor *f ;//= lastToggleSubCorridor[s];
		//lastToggleFloor.pop();
		//vector<SubCorridor *> scf = f->getAllSubCorridor();
		map<SubCorridor *,SubCorridor *>::iterator it = lastToggleSubCorridor.find(s);
		if (it != lastToggleSubCorridor.end())
        {
            switchACOnAtSubCorridor(it->second);

        }
        else
        {
            switchACOnAtSubCorridor(s);

        }
/*
		for(int i=0;i<sc.size();i++)
		{
			if(scf[i]->getAllAC()[0]->getSwitchState() == false)
			{
				scf[i]->getAllAC()[0]->setSwitchState(true);
			}
		}
	*/
	}


}

