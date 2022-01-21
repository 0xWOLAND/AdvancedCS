#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"

using namespace std;

void toh_util(Stack* t1, Stack* t2, Stack* t3, int i){
        if(i % 3 == 0){
            // 1 -> 3
            if(t1->top() != nullptr && (t3->top() == nullptr || ((Disc*) (t1->top()))->getSize() < ((Disc *)(t3->top()))->getSize())){
                t3->push( t1->pop());
            }
            else{
                t1->push( t3->pop());
            }
        }
        if(i % 3 == 1){
            // 1 -> 2
            if(t1->top() != nullptr && (t2->top() == nullptr || ((Disc*) (t1->top()))->getSize() < ((Disc *)(t2->top()))->getSize())){
                t2->push( t1->pop());
            }
            else{
                t1->push( t2->pop());
            }
        }
        if(i % 3 == 2){
           if(t2->top() != nullptr && (t3->top() == nullptr || ((Disc*) (t2->top()))->getSize() < ((Disc *)(t3->top()))->getSize())){
                t3->push( t2->pop());
            }
            else{
                t2->push( t3->pop());
            }
    
    }
}
void toh(int n)
{
    int i, x;
	Disc* a;
	Disc* b;
	Stack* t1 = new Stack();
	Stack* t2 = new Stack();
	Stack* t3 = new Stack();
	

    for (i = n; i >= 1; i--)
    {
		//d.setSize(i);
		Disc* d = new Disc(i);
		cout << d->toString();
        t1->push(d);
    }

	// ****  Your Tower of Hanoi solution!
    for(int i = 0; i < (1<<n) - 1; i++){
        if(n & 1){
            toh_util(t1, t2, t3, i);
        }
        else{
            toh_util(t1, t3, t2, i);
        }

        cout << "________________________________\n";
        printf("T1\n");
        t1->display();
        printf("T2\n");
        t2->display();
        printf("T3\n");
        t3->display();
    }
	delete t1; delete t2; delete t3;
}
int main()
{
    int n;
    cout<<"enter the number of disksn";
    cin>>n;
    toh(n);
    return 0;
}