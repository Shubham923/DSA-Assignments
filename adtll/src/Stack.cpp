/*
 * Stack.cpp
 *
 *  Created on: 22-Dec-2017
 *      Author: g2960
 */
#include<iostream>
#include "Stack.h"
#include "ADTLL.h"
#include "ADTLL.cpp"
using namespace std;
template<class T>
Stack<T>::Stack() {
	// TODO Auto-generated constructor stub

	l.head=0;


}
template<class T>
void Stack<T>::push(T x)
{
l.insert_f(x);

}
template<class T>
T Stack<T>::pop()
{
T x;
x=l.delete_f();
return x;


}
template<class T>
void Stack<T>::display()
{
l.display();

}
template<class T>
int Stack<T>::isempty()
{
if(l.head==NULL)
	return 1;
else
	return 0;

}
template<class T>
T Stack<T>::peep()
{
	T x;
	x=l.head->data;
	return x;

}
template<class T>
Stack<T>::~Stack()
{
	// TODO Auto-generated destructor stub
}
