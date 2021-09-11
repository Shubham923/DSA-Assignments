
#include "Graph.h"
#include <queue>
#include <stack>
#include<iostream>
#include<string.h>
using namespace std;

Graph2::Graph2() {
	// TODO Auto-generated constructor stub

hp=NULL;
vertex=0;
}

Graph2::~Graph2() {
	// TODO Auto-generated destructor stub
}



void  Graph2 :: create_graph()
{
	 int  i,j,edge_list1;

	 edge *temp1,*temp,*temp2,*temp3;
	 cout<<"Enter number of vertex:";
	 cin>>vertex;
	 temp2=new edge;
	 temp2->next=NULL;
	 hp=temp2;

	     for(i=0;i<vertex;i++)
	     {
	       cout<<"\nEnter the edges incident on vertex "  << i << ":";
	       cin>>edge_list1;
	       temp1=temp2;

	       for(j=0;j<edge_list1;j++)
	       {
		    cout<<"\nDestination:";

		    temp=new edge;

		    cin>>temp->u1.vid;
		    cout<<"\nEnter weight of this edge:";
		    cin>>temp->u2.weight;
		   temp->next=NULL;


		   if(temp1->next==NULL)
		  	 {temp1->next=temp;}

		    else
		     {
			 while(temp1->next!=NULL)
				 {temp1=temp1->next;}

			 	 temp1->next=temp;
		     }
	       }
	       temp3=new edge;
	       temp2->dlink=temp3;
	       temp2=temp2->dlink;
	       temp2->next=NULL;
	  }
}


void Graph2 ::Kruskal()
{
	edge* temp,*temp1;
	int sparse[vertex*vertex][3],k=0;
	temp=hp;

	for(int i=0;i<vertex;i++)
	{
		for(temp1=temp->next;temp1!=NULL;temp1=temp1->next)
		{
			if(temp1->u1.vid>i)
			{ sparse[k][0]=i;
			  sparse[k][1]=temp1->u1.vid;
			  sparse[k][2]=temp1->u2.weight;
			  k++;
			}
		}
		temp=temp->dlink;
	}

	int a0;
	for(int i=0;i<k;i++)
{
	for(int j=i;j<k;j++)
	{
		if(sparse[i][2]>sparse[j][2])
		{
			for(int x=0;x<3;x++)
			{
			a0=sparse[i][x];

			sparse[i][x]=sparse[j][x];

			sparse[j][x]=a0;
			}
	    }
	}
}
cout<<"\n..........Sorted sparse matrix for all the edges..........\nv1\t v2\t weight";

	for(int i=0;i<k;i++)
{
	cout<<"\n";
	for(int j=0;j<3;j++)
	cout<<sparse[i][j]<<"\t ";
}

	int array[k],wt=0,ed1,ed2;

	for(int i=0;i<vertex;i++)
	array[i]=i;

cout<<"\n\n........Minimum spanning tree......\nv1\t v2\t weight\n";
	for(int i=0;i<k;i++)
{
	ed1=array[sparse[i][0]];
	ed2=array[sparse[i][1]];

	if(ed1!=ed2)
	{
		cout<<sparse[i][0]<<"\t"<<sparse[i][1]<<"\t"<<sparse[i][2]<<"\n";
		Union(array,ed1,ed2);
		wt+=sparse[i][2];



	}
}

	cout<<"\nMINIMUM WEIGHT OF SPANNING TREE IS ="<<wt<<"\n\n";
}

void Graph2 ::Union(int *arr,int ed1,int ed2)
{
	for(int i=0;i<vertex;i++)
	{
		if(arr[i]==ed2)
			arr[i]=ed1;
	}
}


void Graph2 ::display()
{
   int i;
   edge *temp,*temp1=hp;

   for(i=0;i<vertex;i++)
   { 	cout<<"\nV-"<<i<< "\t-------------> ";
	 for(temp=temp1->next; temp!=NULL;temp=temp->next)
		 cout<<"|V-"<<temp->u1.vid << ",Wt-" << temp->u2.weight<<"|--->";
	 cout<<"NULL";
	 temp1=temp1->dlink;
    }

   cout<<"\n\n";
}
