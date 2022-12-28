#ifndef _HOTEL_H
#define _HOTEL_H

#include "Floor.h"
#include<string>
#include<iostream>
#define null 0

class Hotel
{
   string mName;
   vector<Floor *> mFloor;
public:
	Hotel(string pName);


	void addFloor(Floor *pFloor);

	vector<Floor *> getFloor();

	string getName();

    friend ostream &operator<<( ostream &output,
         const Hotel &H ) {

        int floorSize = H.mFloor.size();

          for(int i=0;i<floorSize;i++)
          {
              if(H.mFloor[i] == null)
              {
                  cout<<"Floor "<<i+1<<"does not exist."<<endl;
                  continue;

              }
              vector<MainCorridor *> mainCorridor = H.mFloor[i]->getAllMainCorridor();
              vector<SubCorridor *> subCorridor = H.mFloor[i]->getAllSubCorridor();
              int mainSize = mainCorridor.size();
              int subSize = subCorridor.size();

              cout<<"Floor "<<i+1<<endl;
//MainCorridor
              for(int j=0;j<mainSize;j++)
              {
                  cout<<"\t"<<"MainCorridor "<<j+1<<endl;

                  vector<Light *> light = mainCorridor[j]->getAllLight();
                  int lSize = light.size();

                  for(int k=0;k<lSize;k++)
                  {
                      cout<<"\t"<<"\t";
                      string state = light[k]->getSwitchState()?"ON":"OFF";
                      cout<<"Light "<<k+1<<" "<<state<<endl;
                  }

                  vector<AirConditioner *> ac = mainCorridor[j]->getAllAC();
                  int aSize = ac.size();

                  for(int k=0;k<aSize;k++)
                  {
                      cout<<"\t"<<"\t";
                      string state = ac[k]->getSwitchState()?"ON":"OFF";
                      cout<<"AC "<<k+1<<" "<<state<<endl;

                  }

              }

//SubCorridor

              for(int j=0;j<subSize;j++)
              {
                  cout<<"\t"<<"SubCorridor "<<j+1<<endl;

                  vector<Light *> light = subCorridor[j]->getAllLight();
                  int lSize = light.size();

                  for(int k=0;k<lSize;k++)
                  {
                      cout<<"\t"<<"\t";
                      string state = light[k]->getSwitchState()?"ON":"OFF";
                      cout<<"Light "<<k+1<<" "<<state<<endl;
                  }

                  vector<AirConditioner *> ac = subCorridor[j]->getAllAC();
                  int aSize = ac.size();

                  for(int k=0;k<aSize;k++)
                  {
                      cout<<"\t"<<"\t";
                      string state = ac[k]->getSwitchState()?"ON":"OFF";
                      cout<<"AC "<<k+1<<" "<<state<<endl;

                  }

              }

          }

      //   output << "F : " << D.feet << " I : " << D.inches;
         return output;
      }
};
#endif
