
/*
 * stack1.cpp
 *
 *  Created on: 23-Dec-2014
 *      Author: pict
 */
#include<iostream>
#include "stack1.h"


using namespace std;
stnode *getnode(node *x)
{

	stnode * temp=new stnode;
	temp->p=x;
	temp->next=NULL;
	return temp;

}
int stack1::isempty()
{
	if(head==NULL)
		return 1;
	return 0;
}
stnode* stack1::push(node *x)
{
	//l.insert_f(x);
	if(head==NULL)
	{

		head=getnode(x);
	}
	else
	{
	stnode *temp;
	temp=head;
	while(temp!=NULL)
		temp=temp->next;
	temp=getnode(x);
	head=temp;
	}
	return head;

}
node *  stack1::pop()
{
	node  *x;
	if(!isempty())
	{
	  // x=l.delete_f();
		stnode *temp,*temp1;
		temp=head;
		while(temp!=NULL)
		{
			temp1=temp;
			temp=temp->next;
		}
		temp1->next=NULL;
		delete temp;

	}
	return x;
}

stnode*  stack1 ::peep()
{  if(!isempty())
	 return head;
}
/*void stack1::display1()
{ cout<<"\n\t Stack Is :: ";
   if(!isempty())
	   l.display();
}*/
void stack1::display1()
{
stnode *temp;
temp=head;
while(temp!=NULL)
{
	cout<<"\t"<<temp->p->data<<"->";
	temp=temp->next;
}

}
