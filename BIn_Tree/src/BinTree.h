/*
 * BinTree.h
 *
 *  Created on: 10-Feb-2018
 *      Author: shubham
 */

#ifndef BINTREE_H_
#define BINTREE_H_
struct node
{
	int data;
	struct node *Left,*Right;


};
typedef struct node Node;
class BinTree {
public:
	BinTree();
	virtual ~BinTree();
	struct node *insert(struct node*);
	void inOrder(struct node*);
	void preOrder(struct node*);
	void postOrder(struct node*);
	int count(Node *);
	int height(Node *);
	Node *copy(Node *);
};

#endif /* BINTREE_H_ */
