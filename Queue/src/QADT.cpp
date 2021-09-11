/*
 * QADT.cpp
 *
 *  Created on: 05-Jan-2018
 *      Author: g2960
 */
#include<iostream>
#include "QADT.h"
#include<string.h>
using namespace std;
/*QADT::QADT() {
	// TODO Auto-generated constructor stub

}*/

/*QADT::~QADT() {
	// TODO Auto-generated destructor stub
}*/

struct node *QADT::getnode(pdata x)
{
	struct node *temp=NULL;
	temp=new struct node;
	temp->pa.priority=x.priority;

	strcpy(temp->pa.name,x.name);
	strcpy(temp->pa.addr,x.addr);
	temp->next=NULL;
	return temp;

}
void QADT::enqueue(pdata x)
{
struct node *temp=NULL;

if(front==NULL)
{

	front=getnode(x);

}
else
{
	struct node *t;
//temp=getnode();
t=front;

while(t->next!=NULL)
	t=t->next;

rear=t;
temp=getnode(x);
t->next=temp;
temp->next=NULL;

rear=temp;

}




}

void QADT::dequeue()
{
if(front==NULL)
	cout<<"Queue is Empty!!";
else
{

struct node *temp;
temp=front;

front=temp->next;
delete temp;


}

}

void QADT::display()
{
struct pdata pa;
struct node *t;
t=front;
while(t!=NULL)
{

//cout<<"->"<<"|"<<t->pa.name<<"-"<<t->pa.addr<<"|";
cout<<"\n\t"<<t->pa.name<<"\t\t"<<t->pa.addr<<"\t"<<t->pa.priority;
t=t->next;

}

}
