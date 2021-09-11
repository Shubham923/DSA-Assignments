
//============================================================================
// Name        : adtll.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ADTLL.h"
#include "Stack.h"

#include "Stack.cpp"
#include<string.h>
using namespace std;
Stack <char> s1;


class conversion
{
public:
	conversion infix_postfix(char [],char []);
	conversion infix_prefix(char [],char []);

	int precedence(char);
	int is_operator(char);
	int associativity(char);
	int evaluation(char []);


};
int conversion::evaluation(char postfix1[20])
{
	int i=0,result;
	char x;

	int val1,val2,val;

while(postfix1[i]!=NULL)
{
	x=postfix1[i];
	if(isdigit(x))
	{
		s1.push(x-48);										//characters are passed as ascii code
															//so subtracting ascii 0 value from x i.e 48

	}
	else
	{

		val1=s1.pop();											//val1 is the value from top of stack
		val2=s1.pop();
		if(x=='+')
			val=val1 + val2;									//perform corresponding arithmetic operation according to incoming value..
		else if(x=='-')
			val=val1 - val2;
		else if(x=='*')
			val=val1*val2;
		else if(x=='/')
			val=val1/val2;
		s1.push(val);



	}




	i++;
}

		result=s1.pop();
		cout<<"\n\tEvaluation="<<result;
}
conversion conversion::infix_prefix(char infix[20],char prefix[20])
{
	conversion c;
	char item,x,y,op[20];
	int i=0,j=0,test,k=0;
	int length=strlen(infix);

	i=strlen(infix);

while(i>=0)
{
	x=infix[i];

	if(x==')')		//push function to stack with zero priority!!	//directly push to stack with zero  priority
		{
			s1.push(x);
			cout<<"\n\tDisplay Stack!";
			s1.display();
		}

	else if(isalpha(x))							//if incoming character is operand directly push it to op string
	{
		prefix[j]=x;
		j++;
	}

	else if(x=='(')
		{
			while(s1.peep()!=')')			//pop() the stack until ')' character is encountered
			{
				x=s1.pop();

				prefix[j]=x;
				j++;
			}
			s1.pop();					//pop() ')' from stack

		}




	else if(is_operator(x))
	{			if(!s1.isempty())
					y=s1.peep();								//obtaining top value from stack without pop() function i.e without deleting the element

				if(s1.isempty() || y=='(')
				{
					s1.push(x);									//push the operator if stack is empty or having character with zero priority

				}
				else if(c.precedence(x)<c.precedence(y))		//for this condition push x onto stack and pop stack element to op string
				{
					item=s1.pop();
					prefix[j]=item;

					j++;
					if(!s1.isempty())
					y=s1.peep();

				if(c.precedence(x)<c.precedence(y))
					continue;

				s1.push(x);
				}
				else if(c.precedence(x)>c.precedence(y))		//for this condition push() element on stack irrespective of ant other op on stack
				{
					s1.push(x);

				}
				else if(c.precedence(x)==c.precedence(y))		//if precedence of both the operator is same then
				{												//go for the condition of associativity i.e left to right or right to left
					test=c.associativity(x);
				if(test==1)
				{

					s1.push(x);

				}
				else
				{
					item=s1.pop();
					prefix[j]=item;
					j++;
					s1.push(x);
				}


			}



		}//

i--;
}



while(!s1.isempty())
	{								//pop the stack element until the stack is empty..
		item=s1.pop();
		prefix[j]=item;
		j++;
	}
prefix[j]='\0';


//cout<<prefix;
while(length>=0)
{
	op[k]=prefix[length-1];
	length--;
	k++;

}

cout<<"\n\tPrefix::";
cout<<op;

}
conversion conversion::infix_postfix(char infix[20],char postfix[20])
{
	conversion c;
	char x,y,item;
	int i=0,j=0,test;
	//x=infix[0];
while(infix[i]!='\0')
{	x=infix[i];
	if(x=='(')		//push function to stack with zero priority!!
	{

		s1.push(x);
		cout<<"\n\tDisplay Stack!";
		s1.display();
	}


	else if(isalpha(x)||isdigit(x))							//if incoming character is operand directly push it to op string
	{

		postfix[j]=x;
		j++;


	}

	else if(x==')')											//pop() the stack until ')' character is encountered
	{
		while(s1.peep()!='(')
		{
			x=s1.pop();

			postfix[j]=x;
			j++;
		}
		s1.pop();												//pop() ')' from stack


	}
	else if(is_operator(x))
	{	if(!s1.isempty())
		y=s1.peep();											//obtaining top value from stack without pop() function i.e without deleting the element

		if(s1.isempty() || y=='(')
		{
			s1.push(x);											//push the operator if stack is empty or having character with zero priority

		}
		else if(c.precedence(x)<c.precedence(y))
		{
			item=s1.pop();
			postfix[j]=item;

			j++;

			if(!s1.isempty())
			y=s1.peep();
			 if(c.precedence(x)<c.precedence(y))				//for this condition push x onto stack and pop stack element to op string
				 continue;
			 s1.push(x);


		}
		else if(c.precedence(x)>c.precedence(y))				//for this condition push() element on stack irrespective of ant other op on stack
		{
			s1.push(x);

		}
		else if(c.precedence(x)==c.precedence(y))				//if precedence of both the operator is same then
		{														//go for the condition of associativity i.e left to right or right to left
			test=c.associativity(x);
			if(test==1)
			{
				item=s1.pop();
				postfix[j]=item;
				j++;
				s1.push(x);
			}
			else
			{

				s1.push(x);
			}


		}



	}//

		i++;

}//while

while(!s1.isempty())
	{																//pop the stack element until the stack is empty..
		item=s1.pop();
		postfix[j]=item;
		j++;
	}
postfix[j]='\0';
cout<<"Postfix String::";
	cout<<postfix;
}//conversion function..
int conversion::precedence(char x)								//setting precedence for the operators..
{
	if(x=='^')
			return 3;
		else if(x=='*' || x=='/')
			return 2;
		else if(x=='+' || x=='-')
			return 1;
		else
			return 0;



}
int conversion::is_operator(char x)							//checking whether incoming character is operator or not
{
	if(x=='+' || x=='-' || x=='/' || x=='*' || x=='^')
		return 1;
	else
		return 0;

}
int conversion::associativity(char x)						//getting associativity for equal precedence..
{
	//conversion c1;

	if(x=='+' || x=='-' || x=='/' || x=='*')
		return 1;
	else return 0;

}

int main()
{
	int ch;
	char infix[20],postfix[20],prefix[20];
	conversion c1,c2;
	cout<<"\n\tEnter the Expression!!";
	cin.getline(infix,20);

do
{
	cout<<"\n\tEnter Your Choice!!\n\t1.Infix to Postfix\n\t2.Infix to Prefix\n\t3.Evaluation!!";
	cin>>ch;
	switch(ch)
	{

	case 1:
	c1.infix_postfix(infix,postfix);
	break;
	case 2:
		c2.infix_prefix(infix,prefix);
	break;
	case 3:
		c1.infix_postfix(infix,postfix);
		c1.evaluation(postfix);
		break;

	}


}while(ch!=4);


	return 0;
}

