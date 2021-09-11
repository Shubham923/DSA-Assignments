#include "Hashing.h"
#include<string>
#include<iostream>
using namespace std;


Hashing::Hashing() {


}
void Hashing::initialise()				//Initailize all the parameters according to program requirements
{
	int i;
	T.tableSize=10;
	for(i=0;i<10;i++)
	{
		T.chain[i]=-1;
		T.inf[i].phone=0;
		T.inf[i].name='-';
		T.visited[i]=0;
		T.replacement[i]=0;

	}
}
int findKey(long int no)
{
	int key=no % 10;						//mod 10 represents table length or table size
	return key;
}
Table getdata(Table T)
{ 	long int no;
	string s1;
	char choice;
	cout<<"\n\tEnter Name of Student!!";
	cin>>s1;
	cout<<"\n\tEnter Phone Number!!";
	cin>>no;
	int start=findKey(no),record,storeRecord=-1;
	static int previous,count,cnt;			//replacement array will be used to  check whether the given position of record i
	if(T.visited[start]!=1)				// is right or wrong or the record is pure or not
	{
		T.inf[start].name=s1;
		T.inf[start].phone=no;
		T.visited[start]=1;
		T.replacement[start]=1;
		count=0;
		cnt++;
	}
	else if(T.visited[start]==1 && T.replacement[start]==1 )

	{
			previous=start;			//store the old value of record which will be included in collision..hence it will be used in chaining purpose

	 while(T.visited[start]!=0)		//traverse the table unless we find the next vacant slot after the collision
		{
			start++;
			start=(start%10);
		}
		T.visited[start]=1;			//after insertion set the visited slot as visited i.e 1

		T.inf[start].name=s1;
		T.inf[start].phone=no;
		cnt++;
		if(T.chain[previous]==-1)		//after collision give the address of placed the record
			count=previous;
		else
		{
			while(T.chain[previous]!=-1)
			previous=T.chain[previous];
			count=previous;
		}
		T.chain[count]=start;
	}


	else
	{
		previous=start;
		while(T.visited[start]!=0)
		{
			start++;
			start=(start%10);
			if(findKey(T.inf[start].phone)==previous)
			{
				record=start;
				if(T.chain[record]==-1)
				{
					storeRecord=record;
				}
				else
				{
					while(T.chain[record]!=-1)
					{
						storeRecord=record;
						record=T.chain[record];
					}

				}


			}


		}
		T.visited[start]=1;
		T.inf[start].name=s1;
		T.inf[start].phone=no;
		cnt++;
		if(storeRecord!=-1)
		T.chain[storeRecord]=start;
	}
	if(cnt>9)
		cout<<"\n\***Table is Full!!***";

		return T;


}
Table getdata1(Table T)					//with replacement..
{
	long int no;
		string s1;
		static int previous,count;
		cout<<"\n\tEnter name of Student!!";
		cin>>s1;
		cout<<"\n\tEnter Phone Number!!";
		cin>>no;
		int start=findKey(no);

		if(T.visited[start]!=1)				// is right or wrong
			{

				T.inf[start].name=s1;
				T.inf[start].phone=no;
				T.visited[start]=1;
				//replacement[start]=1;
				T.replacement[start]=1;
			}
		else if(T.visited[start]==1 && T.replacement[start]==1 ) 	//when key collides with the pure key,it just slides down 	without replacing the position of original record
		{
			previous=start;

				 while(T.visited[start]!=0)
					{
						start++;
						start=(start%10);
					}
					T.visited[start]=1;
					T.inf[start].name=s1;
					T.inf[start].phone=no;
					if(T.chain[previous]==-1)
						count=previous;
					else
					{
						while(T.chain[previous]!=-1)
						previous=T.chain[previous];
						count=previous;
					}
					T.chain[count]=start;


		}
		else if(T.visited[start]==1 && T.replacement[start]!=1)		//while replacing non pure key with pure one
		{
						T.replacement[start]=1;		//making the current record so further records will not get disturbed
						int oldLink,i=0;
						oldLink=start;				//keeping the old position of record before replacement..
						previous=start;
						int temp,temp3;
						string temp1;
						long int temp2;
						temp1=T.inf[start].name;
						temp2=T.inf[start].phone;
						temp3=T.chain[start];
						T.inf[start].name=s1;
						T.inf[start].phone=no;
						while(T.visited[start]!=0)
						{
							start++;
							start=(start%10);
						}
						temp=start;
						T.inf[temp].name=temp1;
						T.inf[temp].phone=temp2;
						T.chain[temp]=temp3;
						T.visited[start]=1;


						/* AFTER  REPLACEMENT.., FOR ADJUSTING THE CHAIN LINK CORRESPONDING TO EACH RECORD*/
						T.chain[previous]=-1;
						while(T.chain[i]!=oldLink)
						i++;
						T.chain[i]=start;

		}
		else
			{
				while(T.visited[start]!=0)
					{
					start++;
					start=(start%10);
					}
				T.visited[start]=1;
				T.inf[start].name=s1;
				T.inf[start].phone=no;
			}



return T;

}
void Hashing::insert(int k)
{
	if(k==0)
		T=getdata(T);
	else
		T=getdata1(T);

}

void Hashing::display()
{
	cout<<"SR\t\tNAME\t\tPHONE NUMBER\t\tCHAIN";
	for(int i=0;i<T.tableSize;i++)
	{
		cout<<"\n"<<i;
		cout<<"\t\t"<<T.inf[i].name;
		cout<<"\t\t"<<T.inf[i].phone;
		cout<<"\t"<<T.chain[i];

	}
}
int Hashing::search(long int key)
{
	int start,prev,linSearch=0;
	start=findKey(key);
	while(T.inf[start].phone!=key)
	{
		start=T.chain[start];
		if(start==-1)
		{
			/*
			 * Here Concept of Hashing will get Violated*/
			cout<<"\n\tPerforming Linear Search....";
			cout<<"\n\tComplexity in this case would be 0(n)";
			while(T.inf[linSearch].phone!=key)
			{
				linSearch++;
				start=linSearch;
				if(linSearch>9)
				{
					cout<<"\n\tRecord Not Found!!";
					return 10;
				}
			}

		}
	}
			cout<<"\n\tRECORD FOUND AT "<<start;
			cout<<"\n"<<start;
			cout<<"\t\t"<<T.inf[start].name;
			cout<<"\t\t"<<T.inf[start].phone;
			cout<<"\t"<<T.chain[start];
			return start;


}

void Hashing::Delete(long int key,int start)
{
	int oldLink;
	//start=findKey(key);
		while(T.chain[start]!=-1)
		{
		oldLink=start;
		start=T.chain[start];
		T.inf[oldLink].name=T.inf[start].name;
		T.inf[oldLink].phone=T.inf[start].phone;
		T.chain[oldLink]=start;
		T.inf[start].name="-";
		T.inf[start].phone=0;
		}

		T.chain[oldLink]=-1;

}
Hashing::~Hashing() {
	// TODO Auto-generated destructor stub
}
