
#ifndef GRAPH_H_
#define GRAPH_H_
#include<iostream>
using namespace std;
typedef struct DOB		//structure for storing date of birth
{
	int date,month,year;
}DOB;

typedef struct Gnode		//structure for storing graph node
{
	union
	{
		int comments;
		DOB dob;
	}u1;
	union
	{
		int vid;
		char name[30];
	}u2;
	struct Gnode* next,*down;		//link to right element in adjacency list		//down link to next node
}Gnode;
class graph
{
	int Vertices;		//stores the no. of vertices in the graph
	Gnode* head;
public:
	graph();				//default constructor
	Gnode* createNode(int);	//creates an empty graph node
	void insertVertex();	//inserts a vertex
	void insertEdge();		//inserts an edge
	void BFS();				//breadth first search
	void DFS(int);			//depth first search
	void Comments(int i,int comments[],string name[]);//find max,min comments
	void display();			//display the adjacency list
	void displayUsers();	//display users
	virtual ~graph();		//destructor
};

#endif /* GRAPH_H_ */

