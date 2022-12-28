#include "Corridor.h"
#define null 0

MainCorridor::MainCorridor(int pNumber)
{
	mType = MAIN;
	mNumber = pNumber;
	Light *light = new Light(POWER_MAIN_CORRIDOR_LIGHT,SWITCH_ON);
	AirConditioner *ac = new AirConditioner(POWER_MAIN_CORRIDOR_AC,SWITCH_ON);
	AddLight(light);
	AddAC(ac);
}


int MainCorridor::getPowerConsumption()
{
	//Add the logic for power consumption here.
	return 0;
}


void MainCorridor::AddLight(Light *&pLight)
{
	mLight.push_back(pLight);
}

void MainCorridor::AddAC(AirConditioner *&pAC)
{
	mAC.push_back(pAC);
}

CorridorType MainCorridor::getCorridorType()
{
	return mType;
}

int MainCorridor::getCorridorNumber()
{
	return mNumber;
}


void MainCorridor::setCorridorNumber(int pNumber)
{
	mNumber = pNumber;
}

vector<Light *> MainCorridor::getAllLight()
{
	return mLight;
}

vector<AirConditioner *> MainCorridor::getAllAC()
{
	return mAC;
}



//SubCorridor

SubCorridor::SubCorridor(int pNumber)
{
	mType = SUB;
	mNumber = pNumber;
	Light *light = new Light(POWER_SUB_CORRIDOR_LIGHT,SWITCH_OFF);
	AirConditioner *ac = new AirConditioner(POWER_SUB_CORRIDOR_AC,SWITCH_ON);
    AddLight(light);
	AddAC(ac);
}


int SubCorridor::getPowerConsumption()
{
	//Add the logic for power consumption here.
	return 0;
}

void SubCorridor::AddLight(Light *&pLight)
{
	mLight.push_back(pLight);
}

void SubCorridor::AddAC(AirConditioner *&pAC)
{
	mAC.push_back(pAC);
}

CorridorType SubCorridor::getCorridorType()
{
	return mType;
}

int SubCorridor::getCorridorNumber()
{
	return mNumber;
}


void SubCorridor::setCorridorNumber(int pNumber)
{
	mNumber = pNumber;
}

vector<Light *> SubCorridor::getAllLight()
{
	return mLight;
}

vector<AirConditioner *> SubCorridor::getAllAC()
{
	return mAC;
}


/*
Corridor* CorridorFactory::getCorridor(CorridorType pType,int pNumber)
	{
		Corridor *corridor;

		if(pType == MAIN)
			corridor = new MainCorridor(pNumber);
		else if(pType == SUB)
			corridor = new SubCorridor(pNumber);
		else
			corridor =  null;

		return corridor;

	}

*/
