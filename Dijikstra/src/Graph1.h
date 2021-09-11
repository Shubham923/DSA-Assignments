/*
 * Graph1.h
 *
 *  Created on: 28-Mar-2018
 *      Author: shubham
 */

#ifndef GRAPH1_H_
#define GRAPH1_H_


#include <iostream>
using namespace std;

class Graph;
class ver_name
{   friend class  Graph;
	string name;
};

class  Graph
{   ver_name GNode[10];
	int weight_mat[10][10];
	int Vertex, Edges;
public:
	void input();
	void s_to_m(int );
	void s_to_s( int  , int);
	void m_to_m();
	void findPath2(int dist[], int src, int dest, int parent[]);
	void minPath(int [], int);
	int findPath(int dist[], int n,int, int parent[]);
	void display();
	void initialize();
	int minDistance(int[], bool []);
};


#endif /* GRAPH1_H_ */
