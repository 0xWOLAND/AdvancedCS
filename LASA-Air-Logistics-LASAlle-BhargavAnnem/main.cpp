//

//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array. 
 *	
 */


#include <iostream>
#include <fstream>
#include <cmath>
#include "slist.h"
#include <string>
#include <sstream>
#include "airport.h"
using namespace std;



void simpleSortTotal(slist *arr, Airport ref);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[10] ;
    int   airportCount;
    Airport* a[13500];
	slist airportArr;
    infile.open ("/Users/bhargavannem/Downloads/LASA-Air-Logistics-LASAlle-BhargavAnnem/airport-codes_US.csv", ifstream::in);
	int   c=0;
    if (infile.is_open())
    {
		while(infile.good()){
			Airport cur;
			string line = "";
			getline(infile, line);
			if(i == 0){
				i++;
				continue;
			}
			stringstream ss(line);
			string token;
			int idx = 0;
            bool flag = 1;
			while(idx <= 4 && getline(ss, token, ',')){
				try {
                    if(!token.length()){
                        flag = 0;
                    }
					if(idx == 0){
						cur.code = token;
					}
					else if(idx == 1){
						cur.type = token;
					}
					else if(idx == 2){
						cur.name = token;
					}
					else if(idx == 3){
						cur.longitude = stof(token);
					}
					else if(idx == 4){
						cur.latitude = stof(token);
					}
					idx++;
				}
				catch (const exception& err){

				}
			}
            if(flag){
                airportArr.add(cur);
                i++ ;
                c++;
            }
		}
        airportCount = c-1;
        infile.close();
//        cout << airportArr.toString();
        Airport ref = airportArr.find("KAUS");
        simpleSortTotal(&airportArr, ref);
        cout << airportArr.toString();

        airportArr.clear();

    }
    else
    {
        cout << "Error opening file";
    }
 


    
}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}


/*
	Provide sort routine on linked list
*/
bool cmp(Airport a, Airport b, Airport ref){
    return distanceEarth(a.latitude, a.longitude, ref.latitude, ref.longitude) < distanceEarth(b.latitude, b.longitude, ref.latitude, ref.longitude);
}
void simpleSortTotal(slist *arr, Airport ref)
{
    int n = arr->size();
    while(1){
        bool flag = 0;
        for(int i = 0; i < n - 1; i++){
            if(cmp(arr->get(i)->a, arr->get(i + 1)->a, ref)){
                arr->exchg(i, i + 1);
                flag = 1;
            }
        }
        if(!flag){
            return;
        }
    }
}

