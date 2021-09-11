/*
 * ADTLL.h
 *
 *  Created on: 21-Dec-2017
 *      Author: g2960
 */

#ifndef ADTLL_H_
#define ADTLL_H_
using namespace std;
template<class T>
struct node
{
	T data;
	struct node<T> *next;

};
template<class T>
class ADTLL
{

public:
	struct node<T> *head;
	ADTLL();
	virtual ~ADTLL();
	struct node<T> *getnode(T);
	void insertend(int);
	void insert_f(T);
	T delete_f();
	void display();
	//struct node<T>  *returnhead();
};

#endif /* ADTLL_H_ */
