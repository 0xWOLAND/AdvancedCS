#ifndef _Stack_H_
#define _Stack_H_
#include "disc.h"
using namespace std;

class Stack
{
	struct Node
	{
		void* data;
	};

	
	int pTop;
	Node st[10000000];
	int size;


	public:
		Stack();
		~Stack();					// Construct stack
		void push(void* inData);	// Add element to top of stack
		void* pop();				// Return element at top of stack and remove from top
		void* top();				// Return element at top of stack
		bool empty();
		void display();

};

using namespace std;



Stack::Stack()
{
	pTop = 0;
	memset(st, 0, sizeof(st));
}

Stack::~Stack()
{
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
	void* t = new Disc();
	t = st[pTop].data;
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
	for(int p1 = pTop - 1; p1 >= 0; p1--){
		cout<< ((Disc*)(st[p1].data))->toString()<<"\t";
	}
	cout<<endl;
}


#endif 		//_Stack_H_

