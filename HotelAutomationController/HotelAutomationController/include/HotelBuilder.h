#include "Hotel.h"

class HotelBuilder
{
   Hotel *hotel;
public:
   HotelBuilder(string name)
   {
	hotel = new Hotel(name);
   }

   void addFloor(int floorCount)
   {

		for(int i=0;i<floorCount;i++)
		{
		    Floor *floor = new Floor();
			floor->setFloorNumber(i+1);
			hotel->addFloor(floor);
		}

   }

   void addMainCorridor(int corridorCount)
   {
	vector<Floor *> floors = hotel->getFloor();

	int floorCount = floors.size();

		for(int i = 0;i<floorCount;i++)
		{
			Floor *floor = floors[i];
			//CorridorFactory *cf = new CorridorFactory();
			for(int j=0;j<corridorCount;j++)
			{
				MainCorridor *mc = new MainCorridor(j+1);
				if(floor)
                    floor->addMainCorridor(mc);
			}

		}
   	}


  void addSubCorridor(int corridorCount)
   {

	int floorCount = (hotel->getFloor()).size();

		for(int i = 0;i<floorCount;i++)
		{
			Floor *floor = (hotel->getFloor())[i];
			//CorridorFactory *cf = new CorridorFactory();

			for(int j=0;j<corridorCount;j++)
			{
				SubCorridor *sc = new SubCorridor(j+1);
				floor->addSubCorridor(sc);
			}
		}

	}


	Hotel*  getHotel()
	{
		return hotel;
	}

  };
