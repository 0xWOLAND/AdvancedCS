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
	private:
		string     date;
		string     region;
		string     rep;
		string     item;
		int      units;
		float    unitCost;
	protected:
		string trim(string s){
			const char* WhiteSpace = " \t\v\r\n";
			int start = s.find_first_not_of(WhiteSpace);
			int end = s.find_last_not_of(WhiteSpace);
			return s.substr(start, end - start + 1);
		}
	public:
		float total();
		void print(){
			cout
			<< "Record: "
			<< this->date <<", " 
			<< this->region << ", " 
			<< this->rep << ", " 
			<< this->item << ", " << this->units << ", " << this->unitCost << ", " << total() << endl;
		}
		SALESREC(string date, string region, string rep, string item, int units, float unitCost){
			this->date = trim(date);
			this->region = trim(region);
			this->rep = trim(rep);
			this->item = trim(item);
			this->units = units;
			this->unitCost = unitCost;

		}
		SALESREC(){
			date = region = rep = item = "";
			units = 0;
			unitCost = 0.0;
		}
		
	
};

float SALESREC::total(){
	return units * unitCost;
}


	


void simpleSortTotal(SALESREC* s[30], int c){
	for(int i = 0; i < c; i++){
		for(int j = i + 1; j < c; j++){
			if(s[i]->total() < s[j]->total()){
				swap(s[i], s[j]);
			}
		}
	}
}

int main()
{
	ifstream infile;
	int i=0;
	SALESREC **salesArr;
	salesArr = (SALESREC**) calloc(30, sizeof(SALESREC));
	int   salesArrayCount = 0;
	string date, region, rep, item;
	int units;
	float unitCost;
	string extra;
//   cout << "start\n";
		infile.open ("SalesDataDyn.csv", ifstream::in);
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
			SALESREC * buffer;
			buffer = new SALESREC(date, region, rep, item, units, unitCost);
			salesArr[i] = buffer;
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
	
	
	simpleSortTotal (salesArr, salesArrayCount);
	printf("Record: OrderDate, Region, Rep, Item, 0, 0, 0\n");
	for (int i=salesArrayCount - 1; i >= 0; i--)
		salesArr[i]->print(); 
		free(salesArr[i]);
	delete[] salesArr;
}
 

