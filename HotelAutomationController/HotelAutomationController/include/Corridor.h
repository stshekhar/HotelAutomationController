#ifndef _CORRIDOR_H
#define _CORRIDOR_H


#include "Equipment.h"
#include "util.h"

#include<vector>


/*
class Corridor
{
	public:
		virtual int getPowerConsumption()=0;
		virtual CorridorType getCorridorType() = 0;
		virtual void setCorridorType(CorridorType type) = 0;
		virtual void AddLight(Light *&light)=0;
		//virtual RemoveLight(Light &light)=0;
		virtual void AddAC(AirConditioner *&AC)=0;
		//virtual RemoveAC(AirConditioner &AC)=0;
		virtual void setCorridorNumber(int num)=0;

};
*/
class MainCorridor//:public Corridor
{
	vector<Light *> mLight;
	vector<AirConditioner *> mAC;
	int mNumber;
	CorridorType  mType;

public:
    MainCorridor(int number);
	int getPowerConsumption();
	CorridorType getCorridorType();
	void setCorridorType(CorridorType type);
	void AddLight(Light *&light);
	void AddAC(AirConditioner *&AC);
	int getCorridorNumber();
	void setCorridorNumber(int number);
	vector<Light *> getAllLight();
	vector<AirConditioner *> getAllAC();

};

class SubCorridor//:public Corridor
{
	vector<Light *> mLight;
	vector<AirConditioner *> mAC;
	int mNumber;
	CorridorType  mType;
	bool bMotion;

public:
    SubCorridor(int number);
	int getPowerConsumption();
	CorridorType getCorridorType();
	void setCorridorType(CorridorType type);
	void AddLight(Light *&light);
	void AddAC(AirConditioner *&AC);
	void setMotion(bool pIsMotion);
	bool getMotion();
	int getCorridorNumber();
	void setCorridorNumber(int number);
	vector<Light *> getAllLight();
	vector<AirConditioner *> getAllAC();

};

#endif // _CORRIDOR_H
/*
class CorridorFactory:public Corridor
{
	Corridor *corridor;
	public:
		Corridor *getCorridor(CorridorType pType,int pNumber);



};
*/
