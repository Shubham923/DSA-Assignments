
#include <iostream>
#include"Graph1.h"
using namespace std;

int main()
{
   int ch,src1,dest1;
   Graph G1;
	do {
	cout<< "\n\n\t**DIJIKSTRAS ALGORITHM** ::  \n\t 1. CREATE GRAPH \n\t 2. SINGLE TO MULTIPLE \n\t 3. SINGLE TO MULTIPLE \n\t 4. MULTIPLE TO MULTIPLE\n\t 5. EXIT \n\t";

	cin >> ch;



	switch(ch)
	{

	case 1 : cout << "\n\t Pelase enter the graph data :: \n\t ";

	          G1.input();

	           G1.display();
	           break;
	case 2:   // dijiktras algorithm
		      cout<< "\n\t Single Sourece to Multiple destination";

		      cout << "\n\tGraph is :: \n\t ----------------------------------------------------------\n\t  ";
		      G1.display();
              cout<<"\n\t Please  Enter the source node  :: ";
              cin >>src1;
		      G1.s_to_m(src1);


		    break;

	case 3 :cout<<"\\n\t Single source to single destination ";
		    cout << "\n\tGraph is :: \n\t ----------------------------------------------------------\n\t  ";
		    G1.display();
		    cout <<"\n\t Please  Enter the souece node  :: ";
		    cin >> src1;
		    cout<<"\n\t Please  Enter the destinaiton node  :: ";
		    cin >> dest1;
		 	G1.s_to_s(src1,dest1);

		   break;

	case 4: cout<<"\\n\t All sourece to all  destination ";
    	    cout << "\n\tGraph is :: \n\t ----------------------------------------------------------\n\t  ";
    	    G1.display();
    	   G1.m_to_m();
    		break;


	case 5: return 0;
	}
}while(1);
}

