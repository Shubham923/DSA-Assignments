//============================================================================
// Name        : BIn_Tree.cpp
// Author      : Shubham
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include"BinTree.h"
#include <iostream>
using namespace std;
BinTree b1;
struct node *T;
int main()
{
	int ch,ch1,ch2,no;

	do
	{
	cout<<"\n\t##Enter Your Choice##";
	cout<<"\n\t1.Insert\n\t2.Display\n\t3.Depth of Tree\n\t4.Display Leaves\n\t5.Copy of Tree";
	cin>>ch;
	switch(ch)
	{
	case 1:

		T=b1.insert(T);

		break;
	case 2:
		cout<<"\n\t1.Pre-Order\n\t2.In-order\n\t3.Post-Order!!";
		cin>>ch1;
		switch(ch1)
		{
		case 1:
			b1.preOrder(T);
			break;
		case 2:
			b1.inOrder(T);
			break;

		case 3:
			b1.postOrder(T);
		break;
		}

		break;
	case 3:
		no=b1.count(T);
		cout<<no;


		break;

	}



	}while(ch!=6);



	return 0;


}

