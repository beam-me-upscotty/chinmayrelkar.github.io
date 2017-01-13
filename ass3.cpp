/**
 * Created by chinmay on 11/1/17.
 * Copyright 2016, Chinmay Relkar
 */#include<iostream>
#include<math.h>
using namespace std;

template<typename T>
class node{
	/**
 * Created by chinmay on 11/1/17.
 * Copyright 2016, Chinmay Relkar
 */
public:
	T data;
	node *left;
	node *right;
	node(){
		left=NULL;
		right=NULL;
	}
};

template<typename T>
class QueueNode{
public:
	node<T> *treeNode;
	QueueNode *next;
	QueueNode(){
		treeNode = NULL;
		next = NULL;
	}
	void getdata(node<T> *treeNode){
		this->treeNode = treeNode;
	}
};

template<typename T>
class Queue{
	/**
 * Created by chinmay on 11/12/16.
 * Copyright 2016, Chinmay Relkar
 */
	QueueNode<T> *start, *rear;
	public:
	Queue(){
		start = NULL;
		rear = NULL;
	}
	void enQueue(node<T> *treeNode){
		QueueNode<T> *queueNode = new QueueNode<T>;
		queueNode->getdata(treeNode);
		
		queueNode->next = NULL;
		if(rear == NULL)
			rear = queueNode;
		else
		{	
			rear->next = queueNode;
			rear = queueNode;
		}
		if(start == NULL)
			start = queueNode;
		
	}
	
	node<T>* deQueue()
	{
		QueueNode<T> *queueNode = start;
		if(start ==NULL)
		{	cout<<"Queue Empty";
			return NULL;
		}
		if(start == rear)
			rear = NULL;
		start = start->next;
		return (queueNode->treeNode);

	}
	bool is_empty(){
		if(start==NULL)
			return true;
		else return false;
	}
};
template<typename T>
class BinaryTree
{
	node<T> *root;
public:
	BinaryTree(){
		root=NULL;
	}

	void createTree(){
		root = createTreeNode();
	}

	node<T>* createTreeNode()
	{
		node<T> *new_node = new node<T>;
		int choice;
		cout<<"Enter data";
		cin>>new_node->data;
		
		cout<<"Want to add left node to "<<new_node->data<<"?(1/0) : ";
		cin>>choice;
		if(choice == 1)
			new_node->left = createTreeNode();
		
		cout<<"Want to add right node to "<<new_node->data<<"?(1/0) : ";
		cin>>choice;
		if(choice == 1)
			new_node->right = createTreeNode();

		return new_node;
	}

	void display()
	{
		int choice;
		while(true)
		{
			cout<<"\n-------------------------------------------------------------------------";
			cout<<"\n\t1. PreOrder"<<endl;
			cout<<"\t2. InOrder"<<endl;
			cout<<"\t3. PostOrder"<<endl;
			cout<<"\t4. Display Leafs"<<endl;
			cout<<"\t5. Display BFT Format"<<endl;
			cout<<"\t6. Exit"<<endl;
			cout<<"\tEnter choice";
			cin>>choice;
			switch(choice)
			{
				case 1: displayPrefix(root);break;
				case 2: displayInfix(root);break;
				case 3: displayPostfix(root);break;
				case 4: displayleaf(root);break;
				case 5: displayBFT();break;				
				case 6: return;
				default: cout<<"Incorrect Choice"<<endl;
			}
		}
	}

	void displayPrefix(node<T> *nod )
	{
		if(nod!=NULL)
		{
			cout<<"["<<nod->data<<"]\t";
			displayPrefix(nod->left);
			displayPrefix(nod->right);
		}
		else
			return;
	}

	void displayInfix(node<T> *nod)
	{
		if(nod!=NULL)
		{
			displayInfix(nod->left);
			cout<<"["<<nod->data<<"]\t";
			displayInfix(nod->right);
		}
		else
			return;
	}
	void displayPostfix(node<T> *nod)
	{
		if(nod!=NULL)
		{
			displayPostfix(nod->left);
			displayPostfix(nod->right);
			cout<<"["<<nod->data<<"]\t";
		}
		else
			return;
	}
	void displayleaf(node<T> *nod){
		if(nod!=NULL)
		if(nod->left==NULL)
			if( nod->right == NULL)
				cout<<"["<<nod->data<<"]\t";
			else
				displayleaf(nod->right);
		else
		{
			displayleaf(nod->left);
			displayleaf(nod->right);
		}
	}
	void displayBFT(){
		Queue<T> queue;
		node<T> *nod;

		if(root!=NULL){
			queue.enQueue(root);
			while(!queue.is_empty())			
			{
				nod = queue.deQueue();
				cout<<"["<<nod->data<<"]\t";
				if(nod->left!=NULL)				
				queue.enQueue(nod->left);
				if(nod->right!=NULL)
				queue.enQueue(nod->right);
			}
		}		
	}
	void Height(){
		cout<<"The Height of the tree="<<height(root)<<endl;
	}
	
	int height(node<T> *nod)
	{
		if(nod!=NULL)
		{	
			if(nod->left!=NULL)
			{	if( nod->right != NULL)
					return  max(height(nod->left),height(nod->right))+1;
				else
					return  height(nod->left)+1;
			}
			else if(nod->right!=NULL)
				return height(nod->right)+1;
		}
		return 1;
	}

};


int main()
{
	BinaryTree<int> binaryTree;
	int choice;		
	while(true)
	{
		cout<<"\n-------------------------------------------------------------------------"<<endl;
		cout<<"1. Create Tree"<<endl;
		cout<<"2. Display Options"<<endl;
		cout<<"3. Height"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Enter Choice";
		cin>>choice;
		cout<<"\n-------------------------------------------------------------------------"<<endl;
			
		switch(choice)
		{
		
			case 1:	binaryTree.createTree();break;
			case 2:	binaryTree.display();break;
			case 3:	binaryTree.Height();break;
			case 4:	return 0 ;		
		}
	}
}
