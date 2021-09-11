#ifndef GRAPH_H_
#define GRAPH_H_
#include<iostream>
using namespace std;

typedef struct city
{
	string name;
	int id;
}city;
class graph
{
private:
	int vertex;
	city c[15];
	int g[15][15]={{0}};
public:
	graph();
	void create();
	void createg();
	void prims();

	void display();
	virtual ~graph();
};
#endif /* GRAPH_H_ */
