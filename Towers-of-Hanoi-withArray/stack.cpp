#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"
using namespace std;



Stack::Stack()
{
	pTop = 0;
	memset(st, 0, sizeof(st));
}

Stack::~Stack()
{
	free(st);
}


void Stack::push(void* inData)
{
	Disc *tmp = (Disc*)(inData);
	printf("PUSHING %d\n", tmp->getSize());
	st[pTop++].data = inData;
}
void* Stack::pop()
{
	if(pTop == 0) return nullptr;

	pTop--;
	void* t = st[pTop].data;
	st[pTop].data = 0;
	// printf("POPPING %d\n", (Disc*)(t)->getSize());
	return t;
}

void* Stack::top()
{
	// your code
	if(pTop == 0) return nullptr;
	return st[pTop - 1].data;
}

bool Stack::empty()
{
	// your code
	return pTop == 0;
}

void Stack::display()
{
	//cout<<endl;
	for(int p1 = pTop; p1 >= 0; p1--){
		cout<< ((Disc*)(st[p1].data))->toString()<<"\t";
	}
	cout<<endl;
}

