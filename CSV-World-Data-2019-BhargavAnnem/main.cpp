#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct record{
	string area;
	double year;
	void print(int i){
		cout << i << " " << area << " " << year << "\n";
	}
};
bool cmp(record a, record b){
	return a.year < b.year;
}
int main() {
	ifstream fin("WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv", ios::in|ios::out|ios::ate);
	vector<record> v;
	if(fin.is_open()){
		fin.seekg(1120, ios::beg);
		string line, token;
		while(getline(fin, line)){
			int itr = 0;
			record r;
			bool instring = false;
			int which = 0, from = 0;
			for(int i = 0; i < line.length(); i++){
				if(line[i] == '"'){
					instring = !instring;
				}
				else if(line[i] == ',' && !instring){
					if(itr == 2){
						r.area = line.substr(from + 1, i - 2 - from);
					}
					else if(itr == 15){
						r.year = stod(line.substr(from, i - from));
					}
					itr++;
					from = i + 1;
				}
			}
			v.push_back(r);
		}
	}

	sort(v.rbegin(), v.rend(), cmp);
	
	// for(int i = 0; i < v.size(); i++){
	// 	v[i].print(i + 1);
	// }

	vector<string> top40 = {
		"Norway",
		"Switzerland",
		"Ireland",
		"China, Hong Kong SAR",
		"Iceland",
		"Germany",
		"Sweden",
		"Australia",
		"Netherlands",
		"Denmark",
		"Singapore",
		"Finland",
		"United Kingdom",
		"New Zealand",
		"Belgium",
		"Canada",	
		"Austria",
		"Liechtenstein",	
		"Japan",
		"Israel",
		"Slovenia",
		"Luxembourg",
		"Republic of Korea",
		"Spain",
		"France",
		"Czechia",
		"Malta",
		"Italy",
		"Estonia",
		"United Arab Emirates",
		"Greece",
		"Cyprus",
		"Lithuania",
		"Poland",
		"Andorra",
		"Latvia",
		"Portugal",
		"Slovakia",
		"Saudi Arabia"
	};
	int more_developed_region_rank = 1, overall_rank = 1;
	bool flag = 1;
	for(int i = 0; i < v.size() && flag; i++){
		if(v[i].area == "United States of America"){
			flag = 0;
		}
		else if(flag){
			if(find(top40.begin(), top40.end(), v[i].area) != top40.end()){
				more_developed_region_rank++;
			}
			overall_rank++;
		}
	}
	printf("More Developed Region Rank: %d\n", more_developed_region_rank);
	printf("Overall Rank: %d\n", overall_rank);
	return 0;
}