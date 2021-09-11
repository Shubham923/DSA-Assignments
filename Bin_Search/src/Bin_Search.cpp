#include <iostream>
#include "BST.h"
#include "Queue.h"
using namespace std;
int main()
{
	tnode * root=NULL, *p=NULL;
	int data, choice, n,key, ch,h;
	btree b;//OBJECT OF BINARY SEARCH TREE
	queue q;//OBJECT OF QUEUE
	do
	{
		cout<<"\n\n\t*****Main Menu*****\n\t1.Creation of Binary SearchTree\n\t2.Recursive Traversals\n\t3.Recursive Search\n\t4.IterativeSearch\n\t5.Insert a Node\n\t6.Mirror Image\n\t7.Level Order(Using Recursion)""\n\t8.Height of Tree\n\t9.Delete a Node\n\t10.Level Order Traversal (UsingQueue)""\n\t11.Non Recursive Height\n\t12.Non RecursiveMirror\n\t0.Exit\n\tEnter Your Choice::";
		cin>>choice;//Get the choice
		switch(choice)//START OF SWITCH CASE
		{
		case 1://Create/Insert
			cout<<"\n\t1.Non-Recursive\n\t2.Recursive\n\tEnter Your Choice::";
			cin>>ch;
			if(ch==1)//Non recursive
			{
				cout<<"\n\tNon-Recursive Insert\n\tHow Many Nodes Do You Want to Insert?::";
				cin>>n;
				for(int i=0;i<n;i++)
				{
					cout<<"\n\tEnter Data::";
					cin>>data;
					root=b.insert(root, data);
				}
				cout<<"\n\tInorder Traversal::";
				b.rinorder(root);
			}
			else if(ch==2)//RECURSIVE CREATION
			{
				cout<<"\n\tHow Many Nodes Do You Want to Insert?::";
				cin>>n;//GET COUNT
				for(int i=0;i<n;i++)
				{
					cout<<"\n\tEnter Data::";
					cin>>data;
					root=b.rinsert(root, data);//CALL TO RECURSIVE INSERT
				}//END FOR LOOP
				cout<<"\n\tInorder Traversal::";
				b.rinorder(root);
			}//END ELSE IF
			break;
		case 2://Recursive Traversals
			cout<<"\n\tInorder ::";
			b.rinorder(root);
			cout<<"\n\tPostorder ::";
			b.rpostorder(root);
			cout<<"\n\tPreorder ::";
			b.rpreorder(root);
			break;
		case 3://Search Recursive
			cout<<"\n\tEnter Key To be Searched::";
			cin>>key;

			p=b.rsearch(root, key);
			if(p!=NULL)
				cout<<"\n\tElement Found::"<<p->data;
			else if(p==NULL)
				cout<<"\n\tRequested Key Not Found";
			cout<<"\n\tInorder Traversal:";
			b.rinorder(root);
			break;
		case 4://Search Iterative
			cout<<"\n\tEnter Key To be Searched::";
			cin>>key;
			p=b.search(root, key);
			if(p!=NULL)
				cout<<"\n\tElement Found::"<<p->data;
			else if(p==NULL)
				cout<<"\n\tRequested Key Not Found";
			cout<<"\n\tInorder Traversal:";
			b.rinorder(root);
			break;
		case 5://Insert a Node
			cout<<"\n\tInserting a Single Node";
			cout<<"\n\tEnter data::";
			cin>>data;
			root=b.insert(root, data);
			cout<<"\n\tInorder::";
			b.rinorder(root);
			break;
		case 6://Mirror Recursive
			cout<<"\n\tMirror Recursive";
			cout<<"\n\tInorder Traversal of Given Tree::";
			b.rinorder(root);
			b.rmirror(root);
			cout<<"\n\tInorder Traversal of Mirror Image::";
			b.rinorder(root);
			break;
		case 7://Level Order
			cout<<"\n\tLevel Order Using Recursion";
			b.printlevelorder(root);
			break;
		case 8://Height Recursive
			int h;
			cout<<"\n\tRecursive Height";
			h=b.height(root);
			cout<<"\n\tHeight of Tree ::"<<h;
			break;
		case 9://Delete
			cout<<"\n\tInorder Traversal of Given Tree::";
			b.rinorder(root);
			cout<<"\n\tEnter Key To be Deleted::";
			cin>>key;
			p=b.search(root, key);
			if(p!=NULL)
			{
				cout<<"\n\tElement Found::"<<p->data;
				p=b.deleteNode(root, key);
				cout<<"\n\tNode deleted";
				cout<<"\n\tInorder Traversal::";
				b.rinorder(p);
			}//END IF
			else if(p==NULL)
				cout<<"\n\tRequested Key Not Found";
			break;
		case 10://Level Order Traversal using Queue
			cout<<"\n\tLevel order Traversal";
			b.BSTLevelorder(root);
			break;
		case 11://Non Recursive Height
			cout<<"\n\tNon-Recursive Height";
			h=b.NRHeight(root);

			cout<<"\n\tHeight of Tree::"<<h;
			break;
		case 12://Non Recursive Mirror
			cout<<"\n\tNon Recursive Mirror";
			cout<<"\n\tInorder Traversal of Given Tree::";
			b.rinorder(root);
			b.NRMirror(root);
			cout<<"\n\tInorder Traversal of Mirror Image::";
			b.rinorder(root);
			break;
		case 0://Exit
			cout<<"\n\tExit Successful";
			return 0;
		}//Switch Case END
	}while(1);//End Do while
	return 0;
	}//END MAIN

