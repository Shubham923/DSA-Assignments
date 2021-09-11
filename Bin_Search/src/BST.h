#ifndef BTREE_H_
#define BTREE_H_
typedef struct tnode//TREE STRUCTURE
{
	int data;
	tnode * lchild, * rchild;
}tnode;
class btree
{
	tnode * root;
public:
	btree();
	tnode * insert(tnode * , int);
	void BSTLevelorder(tnode * root);
	tnode * rinsert(tnode * , int);
	void rinorder(tnode * );
	tnode * rsearch(tnode * , int);
	int rheight(tnode *);
	tnode * search(tnode * , int);
	void rpreorder(tnode *);
	void rmirror(tnode *);
	tnode *deleteNode(tnode*, int);
	tnode* minimum(tnode* );
	void printlevelorder(tnode*);
	int height(tnode* node)	;
	void printGivenLevel(tnode* , int);
	void rpostorder(tnode *);
	tnode * rootret();
	int NRHeight(tnode * );
	tnode * NRMirror(tnode * root);
	virtual ~btree();
};
#endif /* BTREE_H_ */
