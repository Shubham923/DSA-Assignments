
#include <iostream>
#include"Graph.h"
using namespace std;

int main() {

Graph2 g;
int ch;
do{
cout<<"\nMENU\n1:CREATE GRAPH\n2:MINIMUM SPANNING TREE\n\nENTER YOUR CHOICE:";
cin>>ch;
switch(ch)
{
case 1:
		g.create_graph();
		g.display();
		break;

case 2:
		g.Kruskal();
		break;

default:
		cout<<"Wrong choice";
		break;
}
}while(1);
	return 0;
}
