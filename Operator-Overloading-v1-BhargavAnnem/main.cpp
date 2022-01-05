#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

string cNum ;
// struct SALESREC
// {
// 	char     date;
// 	char     region;
// 	char     rep;
// 	char     item;
// 	int      units;
// 	float    unitCost;
// 	float    Total;
// };



class SALESREC {

	ostream& operator <<(ostream lhs){
		lhs << date << " " << rep << " " << item << "\n";
		return lhs;
	}
	friend SALESREC* operator +(SALESREC &, SALESREC &);
	private:
		string     date;
		string     region;
		string     rep;
		string     item;
		int      units;
		float    unitCost;
		bool dup;
	protected:
		string trim(string s){
			const char* WhiteSpace = " \t\v\r\n";
			int start = s.find_first_not_of(WhiteSpace);
			int end = s.find_last_not_of(WhiteSpace);
			return s.substr(start, end - start + 1);
		}
	public:
		bool operator ==(const SALESREC b){
			return(
				date == b.date &&
				rep == b.rep &&
				item == b.item
				);
		}
		float total(){
			return units * unitCost;
		}
		bool getDup(){
			return dup;
		}
		bool setDup(bool b){
			dup = b;
		}
		void print(){
			cout
			<< this->date <<"," 
			<< this->region << "," 
			<< this->rep << "," 
			<< this->item << "," << this->units << "," << this->unitCost << "," << total() << endl;
		}
		SALESREC(){
			date = region = rep = item = "";
			units = 0;
			unitCost = 0.0;
			dup = 0;
		}
		SALESREC(string date, string region, string rep, string item, int units, float unitCost){
			this->date = trim(date);
			this->region = trim(region);
			this->rep = trim(rep);
			this->item = trim(item);
			this->units = units;
			this->unitCost = unitCost;

		}

	
};

bool cmp(SALESREC a, SALESREC b){
	return a.total() > b.total();
}

	
SALESREC* operator +(SALESREC &a, SALESREC &b){
	a.units += b.units;
	return &a;
}


void simpleSortTotal(SALESREC* s[40], int c){
	for(int i = 0; i < c; i++){
		for(int j = i + 1; j < c; j++){
			if(s[i]->total() > s[j]->total()){
				SALESREC* tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
		}
	}
}

int main()
{
	ifstream infile;
	int i=0;
	SALESREC salesArr[40];
	int   salesArrayCount = 0;
	SALESREC* s[40];
	bool used[40];
	memset(used, 0, sizeof(used));
	vector<SALESREC> v;
	string date, region, rep, item;
	int units;
	float unitCost;
	string extra;
//   cout << "start\n";
		infile.open ("SalesDataP5.csv", ifstream::in);
		if (infile.is_open())
		{
		int   c=0;
		getline(infile,extra);
		while (infile.good())
		{
			string inp, s;
			getline(infile, inp);
			stringstream ss(inp);
			int cur = 0;
			while(getline(ss, s, ',')){
				switch(cur){
					case 0:
						date = s;
						break;
					case 1:
						region = s;
						break;
					case 2:
						rep = s;
						break;
					case 3:
						item = s;
						break;
					case 4:
						units = stoi(s);
						break;
					case 5:
						unitCost = stof(s);
						break;
				}
				cur++;
			}
			salesArr[i] = SALESREC(date, region, rep, item, units, unitCost);
			i++ ;
			c++;
		}
		salesArrayCount = c-1;
		infile.close();
	}
	else
	{
		cout << "Error opening file";
	}
	
	for(int i = 0; i < salesArrayCount; i++){
		s[i] = &salesArr[i];
	}
	simpleSortTotal (s, salesArrayCount);
	for(int i = 0; i < salesArrayCount; i++){
		if(used[i]) continue;
		for(int j = i + 1; j < salesArrayCount; j++){
			if(*s[i] == *s[j]){
				s[i] = *s[j] + *s[i];
				used[j] = 1;
			}
		}
		v.push_back(*s[i]);
	}
	sort(v.begin(), v.end(), cmp);
	printf("OrderDate,Region,Rep,Item,Units,UnitCost,Total\n");
	for (int i = 0; i < v.size() ; i++){
		v[i].print();
	}
}
 

