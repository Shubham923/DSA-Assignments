/*
 * Graph2.h
 *
 *  Created on: Feb 24, 2018
 *      Author: DELL
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include <iostream>
using namespace std;
struct edge
{
	union
		{

			 int vid;

		}u1;
	union
	{

		 int weight;

	}u2;

   struct edge * next,*dlink;
};


class Graph2
{    int  vertex;
     edge *hp;

    public:
	   Graph2();
	    void head_list();
	    void create_graph();
	    void display();
	    void Kruskal();
	    void Union(int arr[],int ,int);

	   virtual ~Graph2();
};

#endif /* GRAPH_H_ */
