#include "Queue.h"
#include "BST.h"
#include<iostream>
#include<string.h>
namespace std {
queue::queue()
{// TODO Auto-generated constructor stub
	front=rear=-1;
}
int queue::isempty()
{
	if(front==-1)
		return 1;
	return 0;
}
int queue::full()
{
	if(rear>=19)
		return 1;
	return 0;

}
int queue::size()
{
	int i,count=0;
	if(!isempty())
	{
		for(i=front;i<=rear;i++)
			count++;

	}
	return count;
}
void queue::enqueue(tnode * x)
{
	if(isempty())
		rear=front=0;
	else
		rear=rear+1;
	Q[rear]=x;//ASSIGN X TO REAR
}
tnode * queue::dequeue()
{
	tnode *x=NULL;
	if(!isempty())
	{
		x=Q[front];
		front++;
		if(front>rear)
			front=rear=-1;
	}//END IF
	return x;//RETURN DELETED ELEMENT
}
void queue::display()
{
	int i;
	for(i=front;i<=rear;i++)
		cout<<" | "<<Q[i]->data;

}
queue::~queue() {
// TODO Auto-generated destructor stub
}
} /* namespace std */
