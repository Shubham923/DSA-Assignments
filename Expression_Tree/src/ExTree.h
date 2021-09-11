/*
 * ExTree.h
 *
 *  Created on: 23-Mar-2018
 *      Author: shubham
 */

#ifndef EXTREE_H_
#define EXTREE_H_
#include"stack1.h"
class expression_tree
{
public :
	node *root;

	// expression_tree(){ root= 0;}
	void postorder(node*);
	void preorder(node*);
	void inorder(node*);
	void NR_inorder();
	void NR_preorder();
	void NR_postorder();

	node *  creation();

};

#endif /* EXTREE_H_ */
