
#include <iostream>
#include "Hashing.h"
using namespace std;

int main() {
	int ch;
	Hashing H;
	long int key;
	cout<<"\n\tHash Table";

	H.initialise();
	do
	{
		cout<<"\n\t1.INSERT(WITHOUT REPLACEMENT)\n\t2.INSERT(WITH REPLACEMENT)\n\t3.DISPLAY\n\t4.SEARCH\n\t5.DELETE\n\t6.EXIT";
		cout<<"\n\tEnter your Choice!!";
		cin>>ch;

	switch(ch)
	{
	case 1 :
		H.insert(0);
		break;
	case 2:
		H.insert(1);
		break;
	case 3:
		H.display();
	break;
	case 4:

		cout<<"\n\tEnter the Key you want to Search!!";
		cin>>key;
		H.search(key);
		break;
	case 5:
		int check;

				cout<<"\n\tEnter the Key you want to DELETE!!";
				cin>>key;
				check=H.search(key);
				if(check<10)
					H.Delete(key,check);
				break;
	case 6:
		return 0;
	}
	}while(1);
	return 0;
}
