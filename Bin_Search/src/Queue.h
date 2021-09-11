
/*QUEUE.H*/
#ifndef QUEUE_H_
#define QUEUE_H_
#include "BST.h"
namespace std {
class queue
{
public:
	int front , rear;
	tnode *Q[20];
	queue();
	int isempty();
	int full();
	int size();
	void enqueue(tnode * );
	tnode * dequeue();
	void display();
	virtual ~queue();
	};
} /* namespace std */
#endif /* QUEUE_H_ */
