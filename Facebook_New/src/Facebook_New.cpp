
#include <iostream>
#include"Fb.h"
using namespace std;

int main()
{
	graph G;
	int ch;
	/*Create the isolated node first and then ask for friends, if any. */
	cout<<"\n\t#FACEBOOK#";
	G.insertVertex();
	G.insertEdge();
	do
	{
		cout<<"\n\n\tMAIN MENU\n\t1.DISPLAY\n\t2.MAX FRINEDS(BFS)\n\t3.MAX & MIN COMMENTS(DFS)\n\t4.BIRTHDAY IN MONTH\n\t0.EXIT\n\tENTER YOUR CHOICE::";
		cin>>ch;
		switch(ch)
		{
		case 1://Display graph
			G.displayUsers();
			G.display();
			break;
		case 2://Max Friends
			G.BFS();
			break;
		case 3://Count of comments
			G.DFS(1);
			break;
		case 4://Birthday
			G.DFS(0);
			break;
		case 0://Exit
			cout<<"\n\tExit Successful";
			return 0;
		default:
			cout<<"\n\tInvalid Choice";
		}//End Switch Case
	}while(1);//End Do While
	return 0;
}//End Main

