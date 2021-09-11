/*
 * BinTree.cpp
 *
 *  Created on: 10-Feb-2018
 *      Author: shubham
 */

#include "BinTree.h"
#include<iostream>
using namespace std;
BinTree::BinTree()
{
	// TODO Auto-generated constructor stub

}

BinTree::~BinTree() {
	// TODO Auto-generated destructor stub
}
Node *makenode(Node *X)
{
	int no;
	cout<<"\n\tEnter the Data";
	cin>>no;
			X=new Node;
			X->data=no;
			X->Left=NULL;
			X->Right=NULL;
			return X;

}
Node *BinTree::insert(Node *T)
{
Node *X,*Q=NULL;
int ch;

if(T==NULL)
{
T=makenode(X);
return T;
}
else
{		Q=T;
	do
	{

	cout<<"#Where do you want to Enter the Data#\n\tLeft=1\Right=2";
	cin>>ch;
	if(ch==1)				//choice 1 for inserting node in Left..
	{
		if(Q->Left==NULL)
			{
			Q->Left=makenode(X);
		//	return T;
			}

		else
		{
			Q=Q->Left;

		}
	}

		else if(ch==2)			//Right side
		{
			if(Q->Right==NULL)
						{
						Q->Right=makenode(X);
				//		return T;
						}

					else
					{
						Q=Q->Right;

					}



		}
	}while(ch!=3);
}
return T;

}
void BinTree::inOrder(Node *T)
{
	if(T!=NULL)
	{
inOrder(T->Left);
cout<<T->data;
inOrder(T->Right);

	}

}
void BinTree::preOrder(Node *T)
{
	if(T!=NULL)
		{
cout<<T->data;
preOrder(T->Left);
preOrder(T->Right);
		}


}

void BinTree::postOrder(Node *T)
{

	if(T!=NULL)
		{
	postOrder(T->Left);

postOrder(T->Right);

cout<<T->data;
		}

}
int BinTree::count(Node *T)
{
	int i;
	if(T==NULL)
		return 0;

		if(T->Left==NULL && T->Right==NULL)
			return 1;





	i=count(T->Left)+count(T->Right);
	return i;

}


int BinTree::height(Node *T)
{
int ldepth, rdepth;

if(T==NULL)
return 0;

ldepth=height(T->Left);
rdepth=height(T->Right);

if(ldepth<rdepth)
	return rdepth;
else
	return ldepth;
}
/*Node *BinTree::copy(Node *T)
{
Node *Q;
Q=new Node;
if(T==NULL)
	Q=T;
while(T!=NULL)
{

Q->Left=T->Left;
Q->Right=T->Right;
Q->data=T->data;

}
*/



