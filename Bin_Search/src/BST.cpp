#include "BST.h"
#include "Queue.h"
#include<iostream>
using namespace std;
btree::btree()
{ // TODO Auto-generated constructor stub
	root=NULL;
}
tnode * btree::rootret()
{
	return root;//WILL RETURN ROOT
}
tnode * makenode(int x)//Makes a Node
{
	tnode *temp = new (tnode);
	temp->lchild =NULL;
	temp->rchild=NULL;
	temp->data=x;//ASSIGNS X TO DATA PART
	return temp;//Will return a node
}
void btree::printlevelorder(tnode* root)
{
	int h = height(root);
	for (int i=1; i<=h; i++)
		printGivenLevel(root, i);
}
int btree::height(tnode* node)
{
	if (node==NULL)
		return 0;
	else
	{
		/* compute the height of each subtree */
		int lheight = height(node->lchild);
		int rheight = height(node->rchild);
		/* use the larger one */
		if (lheight > rheight)
			return(lheight+1);
		else return(rheight+1);
	}//END ELSE
}
void btree::printGivenLevel(tnode* root, int level)
{
	if (root == NULL)
		return;

	if (level == 1)
		cout<<"\t"<<root->data;
	else if (level > 1)
	{
		printGivenLevel(root->lchild, level-1);//GO TO LEFT SUBTREE
		printGivenLevel(root->rchild, level-1);//GO TO RIGHT SUBTREE
	}
}
int btree::NRHeight(tnode * root)
{
// Base Case
	tnode * r=rootret();
	if (root == NULL)
		return 0;
// Create an empty queue for level order traversal
	queue q;//OBJECT OF QUEUE
	q.enqueue(root);// Enqueue Root and initialize height
	static int height = 0;
	while(1)
	{
		// nodeCount (queue size) indicates number of nodes at current level.
		int nodeCount = q.size();
		if (nodeCount == 0)
			return height;
		height++;//INCREMENT HEIGHT
		// Dequeue all nodes of current level and Enqueue all nodes of next level
		while (nodeCount > 0)
		{
			tnode * temp=q.dequeue();//DEQUEUE THE FRONT
			if (temp->lchild != NULL)
				q.enqueue(temp->lchild);//ENQUEUE LEFT CHILD
			if (temp->rchild != NULL)
				q.enqueue(temp->rchild);//ENQUEUE RIGHT CHILD
			nodeCount--;
		}//End Inner while
	}//End Outer While
	return height;
}
tnode * btree::insert(tnode * root, int data)
{
	tnode *p, *q;
	if(root==NULL)
	{
		root=makenode(data);//CREATE ROOT NODE
		return root;
	}//END IF
	else
	{
		p=q=root;//COPY ROOT IN P, Q
		while(q!=NULL&&data!=p->data)
		{
			p=q;
			if(data<p->data)
				q=p->lchild;
			else if(data>p->data)
				q=p->rchild;

		}//End while
		if(data==p->data)//CHECK FOR DUPLICATES
		{
			cout<<"\n\tDuplicate Elements are Not Allowed";
			return root;
		}//End if
		if(data<p->data)
			p->lchild=makenode(data);//ASSIGN DATA TO LEFT CHILD
		else
			p->rchild=makenode(data);//ASSIGN DATA TO RIGHT CHILD
		return root;
	}//End of Else
}//End Function

void btree:: rinorder(tnode * r)//RECURSIVE INORDER FUNCTION
{
	if(r!=NULL)
	{
		rinorder(r->lchild);
		cout<<" - " << r->data;
		rinorder(r->rchild);
	}
}
void btree::BSTLevelorder(tnode * root)
{
	int count=0;
	queue b;//OBJECT OF QUEUE
	tnode *v;
	v=root;//COPY ROOT IN V
	b.enqueue(v);//ENQUEUE V IN QUEUE
	while(!b.isempty())//WHILE QUEUE IS NOT EMPTY
	{
		if(count==0)
		{
			cout<<"\n\t";
			count=b.size();//GET SIZE OF QUEUE
		}//END IF
		v=b.dequeue();//DEQUEUE FRONT
		cout<<"\t"<<v->data<<" | ";//DISPLAY DATA
		if(v->lchild!=NULL)
			b.enqueue(v->lchild);//ENQUEUE LEFT CHILD
		if(v->rchild!=NULL)
			b.enqueue(v->rchild);//ENQUEUE RIGHT CHILD
		count--;
	}//End While
}
tnode * btree::rinsert(tnode * root, int data)
{//RECURSIVE INSERT
	tnode * q;
	if(root==NULL)
	{
		root=makenode(data);//MAKE ROOT NODE
		return root;
	}//END IF
	else
	{
		q=root;//COPY ROOT IN Q
		if(data<q->data)
		{
			if(q->lchild==NULL)
				q->lchild=rinsert(q->lchild, data);//Move to LEFT Subtree
			else
				rinsert(q->lchild, data);//Insert as lLEFT child

		}//END IF
		else if(data>q->data)
		{
			if(q->rchild==NULL)
				q->rchild=rinsert(q->rchild, data);//MOVE TO RIGHT SUBTREE
			else
				rinsert(q->rchild, data);//MOVE TO RIGHT SUBTREE

		}//END ELSE IF
		else
		{
			cout<<"\n\tDuplicate Elements are not allowed";
			return root;
		}//END ELSE
	}//END OUTER ELSE
	return q;
}
tnode * btree::search(tnode * root,int data)
{
	tnode * p;
	if(root==NULL)

	{
		cout<<"\n\tTree is Empty";
	}
	else
	{
		while(root!=NULL)
		{
			if(data==root->data)//IF KEY FOUND AT ROOT
				return root;
			if(data>root->data)
				root=root->rchild;//MOVE TO LEFT
			else
				root=root->lchild;//MOVE TO RIGHT

		}//End while
	}//End Else
	return NULL;
}
tnode * btree::rsearch(tnode * root, int data)
{
	tnode * p;
	if(root==NULL)
		return NULL;
	if(data>root->data)
		return(rsearch(root->rchild, data));//SEARCH IN RIGHT SUBTREE
	if(data==root->data)//COMPARE ROOT AND KEY
		return root;
	return (rsearch(root->lchild, data));//SEARCH IN LEFT SUBTREE
}
void btree::rmirror(tnode *root)
{//RECURSIVE MIRROR
	tnode * temp;
	if(root)
	{
		/*SWAP ROOT->LEFT AND ROOT->RIGHT*/
		temp=root->rchild;
		root->rchild=root->lchild;
		root->lchild=temp;
		rmirror(root->lchild);
		rmirror(root->rchild);
	}//END IF
}
void btree:: rpostorder( tnode * r)//RECURSIVE POSTORDER FUNCTION
{
	if(r!=NULL)
	{
		rpostorder(r->lchild);
		rpostorder(r->rchild);
		cout<<" - " << r->data;
	}//END IF
}
void btree::rpreorder(tnode * r)//RECURSIVE PREORDER FUNCTION
{
	if(r!=NULL)
	{
		cout<<" - "<<r->data;
		rpreorder(r->lchild);
		rpreorder(r->rchild);
	}//END IF
}
tnode * btree::NRMirror(tnode * root)
{
	queue q;
	if(root==NULL)//IF TREE IS NULL
		return root;
	else
	{
		q.enqueue(root);//ENQUEUE ROOT
		while(!(q.isempty()))//WHILE ROOT IS NOT EMPTY
		{

			tnode * t=q.dequeue();
			if(t->lchild==NULL &&t->rchild==NULL)
				continue;
			if(t->lchild!=NULL&&t->rchild!=NULL)
			{
				tnode * temp=t->lchild;
				t->lchild=t->rchild;
				t->rchild=temp;//SWAP LEFT AND RIGHT CHILD
				q.enqueue(t->lchild);//ENQUEUE LEFT CHILD
				q.enqueue(t->rchild);//ENQUEUE RIGHT CHILD
			}//END IF
			else if(t->lchild==NULL)
			{
				t->lchild=t->rchild;
				t->rchild=NULL;
				q.enqueue(t->lchild);//ENQUEUE LEFT CHILD
			}//END ELSE IF
			else
			{
				t->rchild=t->lchild;
				t->lchild=NULL;
				q.enqueue(t->rchild);//ENQUEUE RIGHT CHILD
			}//END ELSE
		}//END WHILE
	}//END ELSE
}
tnode *btree:: minimum(tnode* t)
{
	tnode* current = t;
	/* loop down to find the leftmost leaf */
	while (current->lchild != NULL)
		current = current->lchild;
	return current;//RETURN MIN
}
tnode *btree:: deleteNode(tnode* root, int data)
{
// base case
	if (root == NULL)
		return root;
/*If the data to be deleted is smaller than the root's data, then it lies in
left subtree*/
	if (data < root->data)
		root->lchild = deleteNode(root->lchild, data);
	/* If the data to be deleted is greater than the root's data, then it lies in
	right subtree*/
	else if (data > root->data)
		root->rchild = deleteNode(root->rchild, data);
	/*If data is same as root's data, then This is the node to be deleted*/
	else
	{
		// node with only one child or no child
		if (root->lchild == NULL)
		{
			tnode *temp = root->rchild;
			delete(root);
			return temp;
		}
		else if (root->rchild == NULL)
		{
			tnode *temp = root->lchild;
			delete(root);
			return temp;
		}
		/* node with two children: Get the In-order successor (smallest in the right
subtree)*/
		tnode* temp = minimum(root->rchild);
		/* Copy the in-order successor's content to this node*/
		root->data = temp->data;
		// Delete the in-order successor

		root->rchild = deleteNode(root->rchild, temp->data);
	}
	return root;
}
btree::~btree() {
// TODO Auto-generated destructor stub
}
