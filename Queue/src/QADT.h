/*
 * QADT.h
 *
 *  Created on: 05-Jan-2018
 *      Author: g2960
 */

#ifndef QADT_H_
#define QADT_H_
struct pdata
{
	char name[50],addr[50];
	int priority;

};
struct node
{

	struct pdata pa ;
	struct node *next;

};
class QADT {
public:
	struct node *front=NULL ,*rear=NULL;
	//QADT();
//	virtual ~QADT();
	void enqueue(pdata);
	void dequeue();
	void display();
	struct node *getnode(pdata);
};

#endif /* QADT_H_ */
