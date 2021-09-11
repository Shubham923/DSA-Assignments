
#include "Fb.h"
#include<iostream>
#include<string>
#include <queue>
#include<stack>
using namespace std;
graph::graph()		//constructor
{
	Vertices=0;
	head=NULL;
}
Gnode* graph::createNode(int i)	//get details of user
{
	Gnode* temp=new Gnode;
	cout<<"\n\tVertex:";
	cout<<"\n\tEnter name:: ";
	cin>>temp->u2.name;
	cout<<"\n\tEnter DOB::\n\tDate::";
	cin>>temp->u1.dob.date;
	cout<<"\n\tEnter Month::";
	cin>>temp->u1.dob.month;
	cout<<"\n\tEnter Year::";
	cin>>temp->u1.dob.year;
	temp->next=NULL;
	temp->down=NULL;
	return temp;
}
void graph::insertVertex()	//get disconnected users
{
	cout<<"\n\tEnter number of Friends!!::";
	cin>>Vertices;
	Gnode* temp;
	head=createNode(1);
	temp=head;
	for(int i=1;i<Vertices;i++)
	{
		temp->down=createNode(i+1);
		temp=temp->down;
	}
}
void graph::insertEdge()	//connect the disconnected users
{
	Gnode* temp1,*temp;
	temp1=head;					//traverse will point to the very first vertex in adjacency list
	int edges;
	for(int i=0;i<Vertices;i++)
	{
		cout<<"\n\tEnter no. of edges incident on vertex "<<i+1<<":: ";
		cin>>edges;
		temp=temp1;
		for(int j=0;j<edges;j++)
		{
			temp->next=new Gnode;
			temp=temp->next;
			cout<<"\n\tEnter the end of the edge::";
			cin>>temp->u2.vid;
			cout<<"\n\tEnter no. of comments::";
			cin>>temp->u1.comments;
		}
		temp->next=NULL;
		temp1=temp1->down;
	}
}
void graph::BFS()	//breadth first search
{
	int i=0,max=-1;
	int *visited=new int[Vertices];
	for(int m=0;m<Vertices;m++)
		visited[m]=0;
	string maxname;	//string to store the users name who has maximum friends
	queue <Gnode*> q;
	Gnode* temp2,*temp,*temp1;		//temp1 node is used for traversing the adj list in downward direction
									//TEMP2 WILL BE USED TO TRAVERSE THE LIST HORIZONTALLY
	q.push(head);					//push the starting vertex on the queue and make the visited flag equal to 1;
	visited[0]=1;
	cout<<"\n\tBFS Traversal:: ";
	while(!q.empty())		//traverse till the queue is empty
	{
		i=0;
		temp=q.front();
			q.pop();	   //delete the element from the queue
		cout<<temp->u2.name<<"->";					//print the popped element from queue
		for(temp2=temp->next;temp2!=NULL;temp2=temp2->next)	//traverse the adjacency list
		{
			if(visited[temp2->u2.vid-1]==0)	//if not visited
			{
				int n=temp2->u2.vid-1;		//for directly jumping to particular node in adj list using temp1;
				temp1=head;
				while(n!=0)	//traverse the head nodes till the current ode in adjacency list not found
				{
					temp1=temp1->down;
					n--;
				}
				q.push(temp1);	//add to queue if not visited
				visited[temp2->u2.vid-1]=1;
			}
			i++;
			if(max<i)	//to find max friends
			{
				max=i;
				maxname=temp->u2.name;
			}
		}
	}
	cout<<"\n\t"<<maxname<<" has maximum number of friends: "<<max;
}
void graph::Comments(int i,int comments[],string name[])
{
	i--;
	int max=-1,min=32677;
	string maxcomm,mincomm;
	while(i>=0)
	{
		if(comments[i]>max)
		{
			max=comments[i];
			maxcomm=name[i];
		}
		if(comments[i]<min)
		{
			min=comments[i];
			mincomm=name[i];
		}
		i--;
	}
	cout<<"\n\tMaximum Comments "<<maxcomm<<": "<<max;
	cout<<"\n\tMinimum Comments "<<mincomm<<": "<<min;
}
void graph::DFS(int flag)
{
	int bday=0,month=0;
	if(!flag)
	{
		cout<<"\n\tEnter month: ";
		cin>>month;
	}
	int *visited=new int[Vertices];
		for(int m=0;m<Vertices;m++)
			visited[m]=0;			//initialize visited vertex array with 0

	stack <Gnode*> s;				//standard template library syntax
	string name[30],op;
	int comments[30]={0};
	Gnode* temp,*tdown;
	s.push(head);
	op="\n\tDFS Traversal::";
	visited[0]=1;
	int i=0;
	while(!s.empty())
	{
		temp=s.top();
	    s.pop();			//pop the element from top of stack
		op.append(temp->u2.name);	//keep appending popped element
		op.append("->");
		name[i]=temp->u2.name;
		if(temp->u1.dob.month==month)		//for finding no of births in user selected month
			bday++;
		temp=temp->next;
		while(temp!=NULL)
		{
			comments[i]+=temp->u1.comments;
			if(!visited[temp->u2.vid-1])
			{
				visited[temp->u2.vid-1]=1;
				int n=temp->u2.vid-1;
				tdown=head;
				while(n!=0)
				{
					tdown=tdown->down;		//for jumping to non visited vertex directly in adjacency list
					n--;
				}
				s.push(tdown);				//&push that non visited vertex
			}
			temp=temp->next;
		}
		i++;
	}
	cout<<op;
	if(flag)
		Comments(i,comments,name);
	else
	{
				cout<<"\n\tBirthdays in month "<<month<<" are: "<<bday;
	}
}
void graph::display()
{
	Gnode* temp1,*temp2;
	temp1=head;
	for(int i=0;i<Vertices;i++)
	{
		cout<<"\n\t"<<temp1->u2.name<<"->->";
		temp2=temp1->next;
		while(temp2!=NULL)
		{
			cout<<temp2->u2.vid<<"|"<<temp2->u1.comments<<"->";
			temp2=temp2->next;
		}
		cout<<endl;
		temp1=temp1->down;
	}
}
void graph::displayUsers()
{
	Gnode* traverse;
	traverse=head;
	cout<<"\n\tNAME\tDOB\tVERTEX ID\n";
	for(int i=0;i<Vertices;i++)
	{
		cout<<"\n\t"<<traverse->u2.name<<"\t"<<traverse->u1.dob.date<<"/"<<traverse->u1.dob.month<<"/"<<traverse->u1.dob.year<<"\t"<<i+1<<endl;
		traverse=traverse->down;
	}
}
graph::~graph()
{
	// TODO Auto-generated destructor stub
}


