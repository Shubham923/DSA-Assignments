#ifndef HASHING_H_
#define HASHING_H_
#define MAX 10
#include<iostream>
using namespace std;
#include<string.h>
typedef struct
{
string name;
long int phone;
}info;
typedef struct
{
	info inf[MAX];
	int chain[MAX],visited[MAX],replacement[MAX];
	int tableSize;

}Table;
class Hashing {
	Table T;
public:
	Hashing();
	void insert(int);
	void display();
	void initialise();
	int search(long int);
	void Delete(long int,int);
	virtual ~Hashing();
};

#endif /* HASHING_H_ */
