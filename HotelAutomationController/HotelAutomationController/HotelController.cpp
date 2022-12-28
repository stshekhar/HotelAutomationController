#include "HotelBuilder.h"
#include "Motion.h"
#include<cstring>


int main()
{
    int count1;
    string name;

	cout<<"Enter Name of the Hotel: ";
	cin>>name;
	HotelBuilder *builder = new HotelBuilder(name);




	cout<<"Enter Number of floor: ";
	cin>>count1;
	builder->addFloor(count1);

	cout<<"Enter Number of Main corridor: ";
    cin>>count1;
	builder->addMainCorridor(count1);

	cout<<"Enter Number of Subcorridor: ";
    cin>>count1;
	builder->addSubCorridor(count1);

	Hotel *hotel = builder->getHotel();

	cout<< *hotel;

	bool bContinue = true;
	bool bMovement = false;
	int bInput = 0;
	string input;

	Motion m;
    PowerController pc;
    pc.SetDetails(&m,hotel);


	while(bContinue)
	{


		cout<<"Do you want to continue?Y/N: ";

		cin>>input;
		if( !strcasecmp(input.c_str(),"YES") || !strcasecmp(input.c_str(),"Y") )
			bContinue = true;
		else
			bContinue = false;

		if(!bContinue)
		{
			cout<<"Exiting Program."<<endl;
			return 1;
		}

		cout<<"Is there any movement in floor & corresponding subCorridor in one minute? Enter 0 for No or any number for Yes(1): ";
		cin>>bInput;

        bMovement = false;
		if(bInput)
            bMovement = true;

		int floorNumber,subCorridorNumber;
		cout<<"Enter  floor Number and corresponding subCorridor Number:" <<endl;
		cin>>floorNumber;
		cin>>subCorridorNumber;


        m.setMotionDetails(floorNumber,subCorridorNumber);
        m.setMotionDetected(bMovement);

        cout<<*hotel;


	}

	return 0;

}
