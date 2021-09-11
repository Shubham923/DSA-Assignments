/*
 * Stack.h
 *
 *  Created on: 22-Dec-2017
 *      Author: g2960
 */

#ifndef STACK_H_
#define STACK_H_
#include "ADTLL.h"
template <class T>
class Stack {
public:
	//struct node<T> *head;
	ADTLL<T> l;
	Stack();
	void push(T);
	T pop();
	int isempty();
	void display();
	T peep();
	virtual ~Stack();
};

#endif /* STACK_H_ */
