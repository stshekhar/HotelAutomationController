
/*
class Equipment
{

  public:
	virtual void setPowerUnit(int pPowerUnit)=0;
	virtual void setSwitchState(bool pSwitch)=0;
	virtual bool getSwitchState()=0;
	virtual int  getPowerUnit()=0;

};

*/
#ifndef _EQUIP_H
#define _EQUIP_H


class AirConditioner//:public Equipment
{
	int powerUnit;
	bool mSwitch;
public:
	AirConditioner(int pPowerUnit,bool pSwitch);

	void setPowerUnit(int pPowerUnit);

	void setSwitchState(bool pSwitch);

	bool getSwitchState();

	int  getPowerUnit();


};

class Light//:public Equipment
{
	int powerUnit;
	bool mSwitch;
public:
	Light(int pPowerUnit,bool pSwitch);

	void setPowerUnit(int pPowerUnit);

	void setSwitchState(bool pSwitch);

	bool getSwitchState();

	int  getPowerUnit();


};

#endif // _EQUIP_H
/*
class EquipmentFactory
{
	Equipment *equip;
	public:
		Equipment * getEquipment(EquipmentType pType);



};*/



