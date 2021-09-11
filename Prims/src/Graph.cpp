#include<iostream>
#include "Graph.h"
using namespace std;
graph::graph() {
// TODO Auto-generated constructor stub
	vertex=0;
}
void graph::create()
{
	cout<<"\n\tEnter number of cities ::";
	cin>>vertex;
	for(int i=0;i<vertex;i++)
	{
		cout<<"\n\tEnter the vertex ID :: ";
		cin>>c[i].id;
		cout<<"\n\tEnter the name of the city :: ";
		cin>>c[i].name;
	}
}
void graph::createg()
{
//it simply adds the edges to the graph between vertices

	int i=0,j=0,num,distance,vt;
	for(i=0;i<vertex;i++)
	{
		//this takes the input of no of edges for ith vertex
		cout<<"\n\tEnter for Vertex "<<c[i].id<<"( "<<c[i].name<<") : ";
		cout<<"\n\n\tEnter the number of cities to be connected through phone lines : ";

		cin>>num;
		for(j=0;j<num;j++)
		{
			//it connects the i'th vertex to the vertex taken from user by adding the weight (distance) to the matrix

			cout<<"\n\n\tEnter the vertex ID : ";
			cin>>vt;
			if(g[i][vt]==0)
			{
				cout<<"\n\tEnter the distance (in km) : ";
				cin>>distance;
				g[i][vt]=distance;
				g[vt][i]=distance;
			}
			else
				{cout<<"\n\tThe distance is already entered...";
			}

		}
}
}
void graph::prims()
{
	//
	//distance keeps track of the weights of different vertices
	//parent will keep track of the vertex from where distance is being calculated
	int mincost=0,current=0,visited[10]={0},parent[10]={0},distance[10];
	int i=0,j=0,totv=0;
	for(i=0;i<vertex;i++) //initialising distance array to max value
		distance[i]=32761;
	while(totv!=vertex) //loop while not all vertices are visited
	{
		current=totv;
		for(i=0;i<vertex;i++)
		{
			if(visited[i]==0 && g[current][i]!=0 ) //finds the minimum edge of a particular vertex from a no of edges and stores the wts in distance array

			{
				if(g[current][i]<distance[i])
				{
						distance[i]=g[current][i];
						parent[i]=current;
				}
			}
		}
		for(i=0;i<vertex;i++)
			//it compares the distances with minimum cost
		{
			if(visited[i]==0 && distance[i]<=mincost )
			{
				mincost=distance[i];
				current=i;
			}
		}
		//for pass wise o/p
		cout<<"\n\n\tPass : "<<totv<<endl;
		cout<<"\nVisited: ";
		for(j=0;j<vertex;j++)

			cout<<"\t"<<visited[j]<<"\t";
		cout<<"\nDistance : ";
		for(j=0;j<vertex;j++)
			cout<<"\t"<<distance[j]<<"\t";
		cout<<"\nParent : ";
		for(j=0;j<vertex;j++)
			cout<<"\t"<<parent[j]<<"\t";
		visited[current]=1;
		totv++;
	}
	mincost=0;
	for(i=0;i<vertex;i++)
	{
		//adding the distances to get minimum cost
		if(distance[i]!=32761)
			mincost = mincost + distance[i];

	}
	cout<<"\n\tMincost::"<<mincost;
}
void graph::display()
{
			int i=0,j=0;
			cout<<"\n\n";
			for(i=0;i<vertex;i++)
			cout<<"\t\t"<<c[i].name;
			for(i=0;i<vertex;i++)
			{
				cout<<"\n\t"<<c[i].name<<"\t";
				for(j=0;j<vertex;j++)
				{
					cout<<g[i][j]<<"\t\t";
				}
			}
		}
graph::~graph() {
// TODO Auto-generated destructor stub
}
