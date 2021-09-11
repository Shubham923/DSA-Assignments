
#ifndef STACK1_H_
#define STACK1_H_
typedef struct node
{
	char data;
	struct node *llink,*rlink;
}node;
typedef struct stnode
{
	node *p;
	struct stnode *next;
}stnode;
class stack1 {
	stnode *head=NULL;
public :
	stnode* push(node *);
	node * pop();
	int isempty();
	stnode *peep();
	void display1();
	//stack1();
	//virtual ~stack1();
};

#endif /* STACK1_H_ */

