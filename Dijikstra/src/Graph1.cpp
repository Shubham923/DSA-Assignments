#include <iostream>
#include"Graph1.h"
using namespace std;


void  Graph :: initialize()
{   int i,j;
for(i=0;i<Vertex;i++)
	for(j=0;j<Vertex;j++)
		weight_mat[i][j]=0;
for(i=0;i<Vertex;i++)
{
	 cout<<"\n\tEnter the Name for vertices"<< i;
		 cin>>GNode[i].name;
}
}

void  Graph:: input()
{
	int n, i,j,start,end;

	cout<<"\n\t Enter the no of vertex";		//for creating adjacency matrix we are directly taking no of edges
	cin>>Vertex;
	cout<<"\n\t Enter the no of edges::";
	cin>>Edges;
	initialize();
	for(i=0;i<Edges;i++)
	{
		cout<<"\n\t Enter the edge's  :: "<< i;
		cout<<"\n\t Start vertex :: ";
		cin>>start;
		cout<<"\n\t End Vertex   :: ";
		cin>>end;
		if((weight_mat[start][end] ==0 )||( weight_mat[end][start]==0))
		{
			cout<<"\n\t Weight of edge :: "<<start<<end;
			cin>>weight_mat[start][end];
			weight_mat[end][start]=weight_mat[start][end];
		}
		else
		{	cout<<" Edge is already present";
		i--;
		}
	}

}
void  Graph::display()			//for displaying adjacency matrix
{
	int i,j;
	cout<<"\n\t Graph IS ::";
	cout<<"\n \t-------------------------------------------------------------\n    ";
	for(i=0;i<Vertex;i++)
		cout<<"   "<<GNode[i].name<<"  ";
     cout<<"\n\t ---------------------------------------------------------------\n\t";
	for(i=0;i<Vertex;i++)
	{   cout<<"\n" << GNode[i].name << " |\t ";
	for(j=0;j<Vertex;j++)
		cout<<"  "<<weight_mat[i][j] <<"  \t ";
	cout<<"      |";
	}


}
void  Graph :: minPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j]==-1)
        return;

    minPath(parent, parent[j]);

    cout<< "\t"<< GNode[j].name<<"\t";
}

void  Graph:: findPath2(int dist[], int src, int dest, int parent[])
{
	cout<<"\n\t  Source \t Destination\t  Distance  |  \tPath    \n\t ===================================================\n\t" ;
	cout <<"\n\t "<< GNode[src].name <<"\t          " <<   GNode[dest].name << "\t " <<  dist[dest] << "       |\t"  <<GNode[src].name <<"-> " ;
	       minPath(parent, dest);
}


int  Graph ::findPath(int dist[], int n,int src, int parent[])
{

    cout<<"\n\t  Source \t Destination\t  Distance  |  \tPath    \n\t ===================================================\n\t" ;
    for (int i = 0; i < n; i++)
    {  if(i!=src)				//for avoiding distaces 0
        { cout <<"\n\t "<< GNode[src].name <<"\t          " <<   GNode[i].name << "\t " <<  dist[i] << "       |\t"  <<GNode[src].name <<"-> " ;
          minPath(parent, i);
        }
    }
}

void Graph:: s_to_m( int src)
{
	int i,j,k,min;
    bool  visited[10]; 				//spt set to keep track on vertex inclusion in the path
	int distance[10];
	int  parent[Vertex];

	for(i=0;i<Vertex;i++)
	{   visited[i]=false;
	    distance[i]=99;				//initialize distances to ijnfinity i.e 99
	    parent[i]=-1;
	}
	int current=0;
	visited[current]=1;
	distance[src]=0; 				//distance from source to source is  0
	int totv=0;
	while(totv!=Vertex)
	{
		min=99;

	 for(i=0;i<Vertex;i++)
	  {
		  if(visited[i]==0 && distance[i]<min)
	      {
		     min=distance[i];
		    current=i;
	       }
	  }

	  visited[current]=1;
	  totv++;

	  for (int v = 0; v <Vertex; v++)
	  { 																						// Update dist[v] only if is not in sptSet, there is an edge from
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  // u to v, and total weight of path from src to  v through u is
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  // smaller than current value of dist[v]
      if((visited[v]==false && weight_mat[current][v]) && ((distance[current] !=99) &&((distance[current]+weight_mat[current][v])<distance[v])))
      {
    	  	  	  distance[v] = distance[current] + weight_mat[current][v];
	              parent[v]= current; }
	  }

	}//end while

	findPath( distance, Vertex,src,parent);
}

void Graph:: s_to_s( int src  , int dest)
{
		int i,j,k,min;
	    bool  visited[10]; //spt set to keep track on vertex inclusion in the path
		int distance[10];
		int  parent[Vertex];

		for(i=0;i<Vertex;i++)
		{   visited[i]=false;
		    distance[i]=99;
		    parent[i]=-1;
		}
		int current=0;
		visited[current]=1;
		distance[src]=0; //distance from source to source is  0
		int totv=0;
		while(totv!=Vertex && current !=dest)
		{
			min=99;

		 for(i=0;i<Vertex;i++)
		  {
			  if(visited[i]==0 && distance[i]<min)
		      {
			     min=distance[i];
			    current=i;
		       }
		  }

		  visited[current]=1;
		  totv++;

		  for (int v = 0; v < Vertex; v++)
		  { // Update dist[v] only if is not in sptSet, there is an edge from
		  // u to v, and total weight of path from src to  v through u is
		  // smaller than current value of dist[v]
	      if((visited[v]==false && weight_mat[current][v]) && ((distance[current] !=99) &&((distance[current]+weight_mat[current][v])<distance[v])))
	    	        {distance[v] = distance[current] + weight_mat[current][v];
		            parent[v]= current; }
		  }

		}//end while

		findPath2( distance, src,dest,parent);
	}

void  Graph:: m_to_m( )
{
	int i,j,k,min;
    bool  visited[10];						 //spt set to keep track on vertex inclusion in the path
	int distance[10];

	for(k=0;k<Vertex;k++)
	{
	int  parent[Vertex];

	for(i=0;i<Vertex;i++)
	{   visited[i]=false;
	    distance[i]=99;
	    parent[i]=-1;
	}
	int current=k;
	visited[current]=1;
	distance[k]=0; //distance from source to source is  0
	int totv=0;
	while(totv!=Vertex)
	{
		min=99;

	 for(i=0;i<Vertex;i++)
	  {
		  if(visited[i]==0 && distance[i]<min)
	      {
		     min=distance[i];
		    current=i;
	       }
	  }

	  visited[current]=1;
	  totv++;

	  for (int v = 0; v < Vertex; v++)
	  { // Update dist[v] only if is not in sptSet, there is an edge from
	  // u to v, and total weight of path from src to  v through u is
	  // smaller than current value of dist[v]
      if((visited[v]==false && weight_mat[current][v]) && ((distance[current] !=99) &&((distance[current]+weight_mat[current][v])<distance[v])))
    	        {distance[v] = distance[current] + weight_mat[current][v];
	            parent[v]= current; }
	  }

	}//end while


	findPath( distance, Vertex,k,parent);
	}
	}
