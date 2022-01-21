#ifndef DISC_H
#define DISC_H
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

class Disc
{
	int size;
	
public:
	Disc();
	Disc(int);
	~Disc();
	int getSize();
	bool setSize(int);
	std::string toString();

};


Disc::Disc()
{
}

Disc::Disc(int s)
{
	size = s;
}

Disc::~Disc()
{
}

int Disc::getSize()
{
	return size;
}

bool Disc::setSize(int s)
{
	size = s;
	return true;
}

std::string Disc::toString()
{
	return std::to_string(size);
	//return 
}


#endif // DISC_H
