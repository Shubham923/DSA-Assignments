//============================================================================
// Name        : Queue.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "QADT.h"
#include<string.h>
//#include "QADT.cpp"
using namespace std;

QADT q1;
struct node x;

class priority
{
public:
	struct pdata getdata();
	int priority_dequeue(pdata);
	int swap(struct node*,struct node*);


};
struct pdata priority::getdata()
{
	pdata x;
cout<<"Enter name of Patient!!";
cin>>x.name;
cout<<"\n\tEnter Address !!";
cin>>x.addr;
cout<<"\n\tEnter Priority!!";
cin>>x.priority;
return x;
}
struct node *prioritycheck()
{
	struct node *temp1=q1.front->next,*temp2=q1.front,*temp=q1.front;

	while(temp1!=NULL)
	{

		if((temp1->pa.priority)<(temp->pa.priority))
		{


			temp=temp1;
		}
		temp1=temp1->next;
	}
		if(temp!=q1.front)
		{
			while(temp2->next!=temp)
			{

				temp2=temp2->next;


			}

			temp2->next=temp2->next->next;
			temp->next=q1.front;
			q1.front=temp;
			return temp;
		}
		else
		{
			return q1.front;

		}





}
int main() {

	int ch;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	priority p1;
	pdata pat;
	/*q1.enqueue();
	q1.enqueue();
	q1.enqueue();
	q1.enqueue();
	q1.dequeue();
	q1.display();*/

	//struct node *getnode(pat);

do
{
	cout<<"\n\tEnter Your Choice!!";

cout<<"\n\t1.Add Patient\n\t2.Display Queue\n\t3.Remove!!";
	cin>>ch;

	switch(ch)
	{

	case 1://case is for adding data
		pat=p1.getdata();
		q1.enqueue(pat);
		//p1.priority_dequeue(q1);
		break;

	case 2:
		cout<<"\n\tName\t\tAddress\tPriority";
		q1.display();
		break;
	case 3:
		q1.dequeue();
		break;
	case 4:
		q1.front=prioritycheck();
		q1.dequeue();
		q1.display();
		break;

	}
}while(ch!=5);

return 0;
}
