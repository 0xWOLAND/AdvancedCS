#include <string>
#include <cmath>
#pragma once

using namespace std;
class Airport
{
public:
	string code;
	string type;
	string name;
    double   longitude;
    double   latitude;
    Airport(){
        code = type = name = "";
        longitude = latitude = 0;
    }
    bool operator ==(Airport a){
		return code == a.code && type == a.type && abs(longitude - a.longitude) < 1e-5 && abs(latitude - a.latitude) < 1e-5;
	}
	string toString(){
		return "[" + code + ", " + type + ", " + name + ", (" + to_string(longitude) + ", " + to_string(latitude) + ")]\n";
	}
};
