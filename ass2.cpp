#include<iostream>
using namespace std;
typedef enum {SERIOUS =1, MEDIUM_ILLNESS=2, GENERAL=3} Priority;

string enumtoString(Priority p){
	switch(p){
		case 1:return "SERIOUS";
		case 2:return "MEDIUM_ILLNESS";
		case 3:return "GENERAL";
	}
}

template<typename T>
class node{
public:
	T data;
	node *next;
	Priority priority;
	node(){
		next=NULL;
	}
};


template<typename T>
class PriorityQueue{
	node<T> *start;
public:
	PriorityQueue(){
		start = NULL;
	}
	~PriorityQueue(){
		node<T> *p = start;
		while(p->next!=NULL)
		{
			start=start->next;
			delete(p);
			p=start;
		}
		delete(p);
	}

	void enqueue()
	{
		node<T> *new_node = new node<T>;
		int choice;
		cout<<"Enter data:";
		cin>>new_node->data;
		cout<<"1. SERIOUS"<<endl;
		cout<<"2. MEDIUM_ILLNESS"<<endl;
		cout<<"3. GENERAL"<<endl;
		cout<<"Enter priority:";
		cin>>choice;
		switch(choice){
			case 1 : new_node->priority = SERIOUS;
						break;

			case 2 : new_node->priority = MEDIUM_ILLNESS;
						break;

			case 3 : new_node->priority = GENERAL;
						break;
			default : cout<<"Incorrect Input, Default priority GENERAL set"<<endl;
						new_node->priority = GENERAL;
		}

		if(start==NULL)
			start = new_node;
		else
		{
			node<T> *p = start;
			if(p->priority > new_node->priority)
			{	
				new_node->next = p;
				start = new_node;
				cout<<"Enqueue SuccessFull";
				return;
			}
			while(p->next!=NULL)
			{	if(p->next->priority >new_node->priority)
				break;
				p=p->next;
			}new_node->next=p->next;
			p->next = new_node; 
		}

				cout<<"Enqueue SuccessFull";
	}

	T dequeue(){
		node<T> *p = start;
		start = start->next;
		T data = p->data;
		delete(p);
		return data;
	}

	void display(){
		node<T> *p = start;
		cout<<"The Complete Priority Queue"<<endl;
		if(start == NULL){
			cout<<"The Queue is empty"<<endl;
			return;
		}
		cout<<"Data\tPriority"<<endl;
		while(p!=NULL)
		{
			cout<<p->data<<'\t'<<enumtoString(p->priority)<<endl;
			p=p->next;
		}
	}
};

int main(){
	PriorityQueue<int> priorityQueue;
	int choice;

	while(true)
	{
		cout<<"------------------------------------------------------------------------------"<<endl;
		cout<<"1. Enqueue"<<endl;
		cout<<"2. Dequeue"<<endl;
		cout<<"3. Display PriorityQueue"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>choice;
		cout<<"------------------------------------------------------------------------------"<<endl;
		switch(choice)
		{
			case 1 : priorityQueue.enqueue();
						break;
			case 2 : cout<<"Dequeue item = "<<priorityQueue.dequeue()<<endl;
						break;
			case 3 : priorityQueue.display();
						break;
			case 4 : return 0;

		}

	}
}