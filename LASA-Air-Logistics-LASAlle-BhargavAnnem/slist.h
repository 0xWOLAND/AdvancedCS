// #include <string>
#include "airport.h"
using namespace std;
/*
Class Library File
*/

class Node {
	public:
		Airport a;
		Node* next;
		Node(){
            next = NULL;
        }
		Node(Airport b) {
			a = b;
		}
		bool operator ==(Node *b){
			return a == b->a;
		}
};

class slist {

private:
	Node *head;
// Constructor
public:
	slist(){
		head = nullptr;
	}
	slist(Airport a) {
		// ident, type, name, longitude, latitude ,elevation_ft, continent, iso_country, iso_region, municipality, gps_code, iata_code, local_code
		head = new Node(a);
	}
// Destructor
	~slist() {
		clear();
	}
// add(value)				//Adds a new value to the end of this list.
	void add(Airport a){
		Node *ptr = new Node(a);
		ptr->next = NULL;
		if(head == nullptr){
			head = ptr;
		}
		else{
			Node *current = get(size() - 1);
			current->next = ptr;
		}
	}
// clear()					//Removes all elements from this list.
	void clear(){
		Node *next;
		while(head != nullptr){
			next = head->next;
			delete head;
			head = next;
		}
	}
// equals(list)				//Returns true if the two lists contain the same elements in the same order.
	bool equals(slist b){
		Node *cur = head;
		Node *bcur = b.head;
		while(cur == bcur && cur != nullptr && bcur != nullptr){
			cur = cur->next;
			bcur = bcur->next;
		}
		return (cur == nullptr && bcur == nullptr);
	}
//get(index)				//Returns the element at the specified index in this list.
	Node* get(int index){
		Node *ret = head;
		while(index--){
			if(ret == nullptr){
				return nullptr;
			}
			else{
				ret = ret->next;
			}
		}
		return ret;
	}
//    Return Airport object with given code
    Airport find(string code){
        Node *cur = head;
        while(cur != NULL){
            if(cur->a.code == code){
                return cur->a;
            }
            cur = cur->next;
        }
        return Airport();
    }
//insert(index, value)		//Inserts the element into this list before the specified index.
	void insert(int index, Airport a){
		Node value(a);
		Node *ptr = &value;
		Node *cur = head;
		if(index + 1 == size()){
			add(a);
		}
		else{
			cur = get(index);
			if(index == 0){
				ptr->next = cur;
				head = &value;
			}
			else{
				Node *prev = get(index - 1);
				prev->next = &value;
				ptr->next = cur;
			}
		}
	}
//exchg(index1, index2)		//Switches the payload data of specified indexex.
	void exchg(int idxa, int idxb){
		Node *a = get(idxa);
		Node *b = get(idxb);
		Airport tmp = a->a;
		a->a = b->a;
		b->a = tmp;	
	}
//swap(index1,index2)		//Swaps node located at index1 with node at index2
	void swap(int idxa, int idxb){
		if(idxa > idxb){
			int u = idxa;
			idxa = idxb;
			idxb = u;
		}
		if(idxa == 0){
			Node *cura = get(idxa);
			Node *curb = get(idxb);
			if(cura == nullptr || curb == nullptr) return;
			Node *tmp;
			tmp = cura;
			cura->next = curb->next;
			curb->next = tmp->next;
		}
		else{
			Node *cura = get(idxa);
			Node *curb = get(idxb);
			Node *tmp;
			if(cura == nullptr || curb == nullptr) return;
			// 12   34
			tmp = cura;
			cura->next = curb->next;
			curb->next = tmp->next;
		}
	}
// isEmpty()				//Returns true if this list contains no elements.
	bool isEmpty() {
		return head == nullptr;
	}
// remove(index)			//Removes the element at the specified index from this list.
	void remove(int index){
		if(!(0 <= index && index < size())) return;

		if(index == 0){
			head = head->next;
		}
		else if(index == size() - 1) {
			Node *cur = get(index - 1);
			cur->next = nullptr;
		}
		else{
			Node *cur = get(index - 1);
			Node *next = get(index + 1);
			cur->next = next;
		}
	}
// set(index, value)		//Replaces the element at the specified index in this list with a new value.
	void set(int index, Airport a){
		if(!(0 <= index && index < size())) return;

		Node *cur = get(index);
		cur->a = a;
	}
// size()					//Returns the number of elements in this list.
	int size(){
		Node *cur = head;
		int ans = 0;
		while(cur != NULL){
			cur = cur->next;
			ans++;
		}
		return ans;
	}
// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
	slist subList(int start, int length){
		int len = size();
		slist *ret = new slist();
		if((!(0 <= start && start < len)) || (start + length >= len)) return *ret;

		Node * cur = get(start);
		for(int i = 0; i < length; i++){
			ret->add(cur->a);
		}
		return *ret;

	}
// toString()				//Converts the list to a printable string representation.
	string toString(){
		Node *cur = head;
		string ret;
		while(cur->next != nullptr){
			ret += cur->a.toString();
			cur = cur->next;
		}
		return ret;
	}
};
// };