#include <iostream>
using namespace std;
#include"ExTree.h"
int main()
{
expression_tree T1;
     node *r;
     int choice;
      do
      {
     cout<<"\n\t Expression Tree Operations :: ";
     cout<<"\n\t 1. Tree Creation() \n\t 2. Recursive Traversal \n\t 3. Non Recursive  Traversal";


     cout<<"\n\t\n\t 4. Exit () \n\t\t Enter Your Choice :: ";

     cout<<"\n";
     cin>>choice;
     switch(choice)
     {
        case 1: //Creation of Expresson Tree
                          r= T1.creation();
                          break;
        case 2: //Recursive Traversals
        		   cout<<"\n\t postorder traversal is";
                    T1. postorder(r);
                   cout<<"\n\t inorder traversal is";
                   T1.inorder(r);
                   cout<<"\n\t preorder traversal is";
                   T1.preorder(r);
                   break;
        case 3:  //Non Recursive Traversal ::
        	       cout<<"\n\t inorder traversal is";
        	        T1.NR_inorder();
        	        cout<<"\n\t preorder traversal is";
        	       T1.NR_preorder();
        	        cout<<"\n\t postorder traversal is";
        	        T1. NR_postorder();

        	        break;
        case 4: return 0;
        default : // invalid choice
	       cout<<"\n\t Please enter the valid choice ";

          }
      }while(1);
	return 0;
}

