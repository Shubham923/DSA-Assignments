#include<iostream>
using namespace std;
#include "stack1.h"
#include"ExTree.h"
void expression_tree:: NR_inorder()
{    stack1 stk;
	node *Temp=root;
	if(Temp == NULL)
	    cout<< "Tree is Empty";
 node *P = Temp;

  do
	  {
	    while (P!= NULL)
	    {   //travel down left branches as far as possible
	       //saving pointers to nodes passed
	             stk. push(P);
	             P=P->llink;

	    } // end of while (p!=NULL)
	 // check if finished
	   if (!stk.isempty())
	   {
		   //at this point the left subtree is empty
		    P = stk.pop();
		    cout<<P->data; //visitthe root
		    P = P->rlink;
       } // end of if
       } while(P!=NULL ||!stk.isempty() );

   }
void expression_tree:: NR_preorder()
{
	     stack1 stk;
		 node *Temp=root,*P=NULL;
		 if(Temp == NULL)
		    cout<< "Tree is Empty";
		 else
		 {
			 stk.push(Temp);
		     do
		     { P= stk.pop(); // visit the  stored address and branch left.
		        //write(pdata)
		        while(P!=NULL)
		        {
		           cout<< P->data;
		          if(P->rlink != NULL) // store address of nonempty right subtree
		                stk.push(P->rlink);
		           P=P->llink;
		       }
		     // end of while
		     } while(!stk.isempty()) ;
		 }//end of else
}
void expression_tree:: NR_postorder()
{
	stack1 stk;
	node *P=NULL,*previous=NULL;
    node *Temp=root;
            if(Temp == NULL)
                cout<< "Tree is Empty";
           stk.push(Temp);
           while(!stk.isempty())
            {
                P = stk.pop();

                if(((P->rlink == NULL)&&(P->llink == NULL )))
                {
            	    previous = P;
                    cout<<P->data;
                }
                else if(((previous ==P->rlink)||(previous ==P->llink)))
                 {
                	     previous = P;
                         cout<<P->data ;
                 }
                else
                {
                	stk.push( P);
                   if(P->rlink)
                    stk.push(P->rlink);
                   if(P->llink)
                     stk.push(P->llink);
                }
               //} //end of else

         }
    //end postorder
}
void expression_tree:: postorder(node * root)
{
     node *w =root;
	    if (w != NULL)
	    {

	        postorder(w->llink);

	        postorder(w->rlink);

	        cout<<w->data;

	    }


}
void expression_tree:: preorder(node *root)
{node *w = root;

	    if (w != NULL)

	    {
	    	 cout<<w->data;

	        preorder(w->llink);

	        preorder(w->rlink);


	    }

}
void expression_tree:: inorder(node *root)
{
	 node *w =root ;

	    if (w != NULL)

	    {

	        inorder(w->llink);
	        cout<<w->data;
	        inorder(w->rlink);



	    }

}
node * expression_tree::  creation()
{

	 stack1 stk;
	 string str1;
	      cout<<"\n\t Enter the Valid Postfix expression ::  ";
	      cin>> str1;
	      int i=0;
	      cout<<"\n\t Post fix Expression is :: ";
	      while((str1[i])!='\0')
	           {
	         	cout<<str1[i++];

	           }
	          i=0;
	          while((str1[i])!='\0')
	           {
	         	  char token =str1[i];
	         	              if(isalnum(token))
	                 	      {
	                 	      node *temp=new(node);
	                           temp->data=token;
	                	       temp->llink=NULL;
	                	        temp->rlink=NULL;
	                 	   stk.push(temp);
	                 	   stk.display1();
	                 	   i++;
	                 	     }

	                 else
	                 {
	                 	node * temp =new(node);
	                 	temp->data=token;
	                 	temp->llink=NULL;
	                 	temp->rlink=NULL;

	                 	temp->rlink=stk.pop();
	                 	temp->llink=stk.pop();
	                 	stk.push(temp);
	                 	stk.display1();
	                 	i++;
	                 }
	          }


	           root =stk.pop();
	           return root;

}
