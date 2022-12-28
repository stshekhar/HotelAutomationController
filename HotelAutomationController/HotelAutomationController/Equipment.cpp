	#include "Equipment.h"

	AirConditioner::AirConditioner(int pPowerUnit,bool pSwitch)
	{
		powerUnit = pPowerUnit;
		mSwitch = pSwitch;
	}
	void AirConditioner::setPowerUnit(int pPowerUnit)
	{
		powerUnit = pPowerUnit;
	}
	void AirConditioner::setSwitchState(bool pSwitch)
	{
		mSwitch = pSwitch;
	}
	bool AirConditioner::getSwitchState()
	{
		return mSwitch;
	}
	int  AirConditioner::getPowerUnit()
	{
		return powerUnit;
	}


	//Light Class definition.

	Light::Light(int pPowerUnit,bool pSwitch)
	{
		powerUnit = pPowerUnit;
		mSwitch = pSwitch;
	}
	void Light::setPowerUnit(int pPowerUnit)
	{
		powerUnit = pPowerUnit;
	}
	void Light::setSwitchState(bool pSwitch)
	{
		mSwitch = pSwitch;
	}
	bool Light::getSwitchState()
	{
		return mSwitch;
	}
	int  Light::getPowerUnit()
	{
		return powerUnit;
	}
/*
	Equipment * EquipmentFactory::getEquipment(EquipmentType pType)
	{

		Equipment *equip;
		if(pType == LIGHT)
			equip = new Light();
		else if(pType == AC)
			equip = new AC();
		else
			equip =  null;

		return equip;

	}
*/
