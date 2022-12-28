#include"Floor.h"

class PowerCriteria
{
	Floor *f;
	int mCriteria;
	public:
	PowerCriteria(Floor *pF)
	{
		f = pF;
	}

	void calculatePowerCriteria()
	{
		int mainCorridorSize = f->getAllMainCorridor().size();
		int subCorridorSize = f->getAllSubCorridor().size();
		mCriteria = (mainCorridorSize*15) + (subCorridorSize*10);

	}

	bool isPowerCriteriaExceed(Floor *f)
	{
		vector<MainCorridor *> mc = f->getAllMainCorridor();
		vector<SubCorridor *> sc = f->getAllSubCorridor();
		int acNum = 0;
		int lightNum = 0;
	/*	if(mc[0])
        {
            int acNum = mc[0]->getAllAC().size();
            int lightNum = mc[0]->getAllLight().size();
        } */

        int mcSize = mc.size();

		for(int i=0;i<mcSize;i++)
		{
		    if(!mc[i])
                continue;
			vector<Light *> light = mc[i]->getAllLight();
			vector<AirConditioner *> ac = mc[i]->getAllAC();

			int eSize = light.size();

			for(int j=0;j < eSize; j++)
			{
			    if(!light[j])
                    continue;
				if(light[j]->getSwitchState())
					lightNum++;
			}

			eSize = ac.size();

			for(int j=0; j < eSize; j++)
			{
			    if(!ac[j])
                    continue;
				if(ac[j]->getSwitchState())
					acNum++;
			}
		}


		for( int i=0; i<sc.size(); i++)
		{
		    if(!sc[i])
                continue;
			vector<Light *> light = sc[i]->getAllLight();
			vector<AirConditioner *> ac = sc[i]->getAllAC();

			int eSize = light.size();

			for(int j = 0;j < eSize;j++)
			{
			    if(!light[j])
                    continue;
				if(light[j]->getSwitchState())
					lightNum++;
			}

			eSize = ac.size();

			for(int j = 0;j < eSize;j++)
			{
			     if(!ac[j])
                    continue;
				if(ac[j]->getSwitchState())
					acNum++;
			}
		}


		int powerOnEachFloor = 5*lightNum + 10*acNum;

		if( powerOnEachFloor > mCriteria)
			return true;

		return false;


	}



};
