#include <iostream>
using namespace std;
#include "Graph.h"
int main()
{
	int choice;
	graph g;
do
{
	cout<<"\n\t*****Main Menu*****\n\t1.Enter Cities\n\t2.Enter Distances\n\t3.Find Minimum cost\n\t4.Display\n\t0.Exit\n\tEnter Your Choice::";

cin>>choice;
	switch(choice)
	{
		case 1:
			g.create();
			break;
		case 2:
			g.createg();
			break;
		case 3:
			g.prims();
			break;
		case 4:
			g.display();
			break;
		case 0:
			return 0;
	}//End Switch
	}while(1);//End Do while
return 0;
}//End Main
