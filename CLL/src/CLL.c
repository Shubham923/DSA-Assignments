#include<stdio.h>
#include<stdlib.h>
//Structure declaration
typedef struct poly
{
	int p,c;
	struct polynomial *next;
}poly;
//Function Prototypes
poly * create(int n);
poly * getnode();
void display(poly *h);
poly * add(poly *p1,poly *p2);
poly * multiply(poly *p1,poly * p2);
poly * mult(poly *,poly *);
//Main Function
int main()
{
	int choice,n1,n2,n3,value;  //n1->  number of terms in polynomial 1 and n2-> number of terms in polynomial 2
	poly * p1=NULL,*p2=NULL,*p3=NULL;
	//insert the first polynomial

	do{
	printf("\n\tEnter 1st polynomial\n\tEnter number of terms in polynomial(int)");
	scanf("%d",&n1);
	if(n1>0)
		break;
	else
		printf("\n\tEnter proper degree\n");
	}while(1);
	p1=create(n1);

	//insert the second polynomial

	do{
	printf("\n\tEnter 2nd polynomial\n\tEnter number of terms in polynomial(int)");
	scanf("%d",&n2);
	if(n2>0)
		break;
	else
		printf("\n\tEnter proper degree\n");
	}while(1);
	p2=create(n2);

	printf("\n\tThe first polynomial is\n\t");
	display(p1);
	printf("\n\tThe second polynomial is\n\t");
	display(p2);

	do{
		printf("\n\tMain MENU\n\t3:\tAddition\n\t4:\tMultiplication\n\t5:\tEvaluation\n\t6:Exit\n\tplease enter the proper choice\n");
		scanf("%d",&choice);  //Enter the choice
		switch(choice)
		{
			case 3:  //Addition of two polynomials
				printf("\n\tThe first matrix is \n\t");
				display(p1);
				printf("\n\tThe second matrix is \n\t");
				display(p2);
				p3=add(p1,p2);  //calls the addition function and returns the head pointer of the final polynomial
				printf("\n\t The final matrix is \n\t");
				display(p3);
				break;
			case 4://multiplication of two polynomials
				printf("\n\tThe first matrix is \n\t");
				display(p1);
				printf("\n\tThe second matrix is \n\t");
				display(p2);
				p3=multiply(p1,p2);   //Calls the multiplication function and returns the head pointer of the final polynomial
				printf("\n\t The final matrix is \n\t");
				display(p3);
				break;
			case 5://Evaluation of a polynomial
				printf("\n\tThe first polynomial is\n");
				display(p1);
				value=evaluation(p1);  //calls the evaluation function and returns the value of the polynomial
				printf("\n\tThe value is=%d",value);
				printf("\n\tThe second polynomial is\n");
				display(p2);
				value=evaluation(p2);  //Calls the evaluation function and returns the value of the polynomial
				printf("\n\tThe value is=%d",value);
				break;
			case 6:  //Exit
				return 0;
				break;
			default:  //Default case
				printf("\n\tplease enter the proper choice\n");
		}
	}while(1);
}
//Create the linked list of the polynomial
poly * create(int n)
{
	int i;
	poly * q,*h;
	h=(poly *)malloc(sizeof(poly));
	h->c=h->p=-1;
	h->next=NULL;
	q=h;
	for(i=0;i<n;i++)
	{
		q->next=getnode();
		q=q->next;
	}
	q->next=h;
	return h;
}
//Creates the node and returns the address of the node
poly * getnode()
{
	poly *q;
	q=(poly *)malloc(sizeof(poly));
	printf("\n\tEnter power");
	scanf("%d",&(q->p));
	printf("\n\tEnter coefficient");
	scanf("%d",&(q->c));
	q->next=NULL;
	return q;
}
//Displays the polynomial
void display(poly *h)
{
	poly *q;
	q=h->next;
	while(q!=h)
	{
		printf("     %dx^%d    ",(q->c),(q->p));
		q=q->next;
		if(q!=h)
		{
			printf("+");
		}
	}

}
//Adds the two polynomial
poly * add(poly *p1,poly *p2)
{
	poly * p3=NULL;poly *r3=NULL,*h1,*h2;
	h1=p1;
	h2=p2;
	r3=p3=(poly *)malloc(sizeof(poly));
	p3->c=p3->p=-1;
	p3->next=NULL;
	p1=p1->next;
	p2=p2->next;
	while(p1!=h1 && p2!=h2)
	{
			p3->next=(poly *)malloc(sizeof(poly));
			p3=p3->next;
		if(p1->p>p2->p)
		{
			p3->p=p1->p;
			p3->c=p1->c;
			p1=p1->next;
		}
		else if((p1->p)<(p2->p))
		{
				p3->p=p2->p;
				p3->c=p2->c;
				p2=p2->next;
		}
		else
			{
				p3->p=p1->p;
				p3->c=(p1->c)+(p2->c);
				p1=p1->next;
				p2=p2->next;
			}
	}
	while(p1!=h1)
	{
			p3->next=(poly *)malloc(sizeof(poly));
			p3=p3->next;
		p3->p=p1->p;
		p3->c=p1->c;
		p1=p1->next;
	}
	while(p2!=h2)
	{
		p3->next=(poly *)malloc(sizeof(poly));
		p3=p3->next;
		p3->p=p2->p;
		p3->c=p2->c;
		p2=p2->next;
	}
	p3->next=r3;

	return r3;
}
//Multiplies the two polynomial
poly * multiply(poly *p1,poly * p2)
{
	poly *h2,*p3,*temp;
	p3=(poly *)malloc(sizeof(poly));
	p3->p=p3->c=-1;
	p3->next=p3;
	h2=p2;
	p2=p2->next;
	while(p2!=h2)
	{
		temp=mult(p1,p2);//multiplies p1 polynomial with each term of p2 and returns the final polynomial
		p3=add(p3,temp); //adds the temp and p3 polynomial and forms the p3 polynomial
		p2=p2->next;
	}
	return p3;
}
//multiplies p1 polynomial with each term of p2 and returns the final polynomial
poly * mult(poly *p1,poly *x)
{
	poly * p3,*r3,*h1=p1;
	p3=r3=(poly *)malloc(sizeof(poly));
	p3->c=p3->p=-1;
	p3->next=p3;
	p1=p1->next;
	while(p1!=h1)
	{
		p3->next=(poly *)malloc(sizeof(poly));
		p3=p3->next;
		p3->p=(p1->p)+(x->p);
		p3->c=(p1->c)*(x->c);
		p1=p1->next;
	}
	p3->next=r3;
	return r3;
}
//Evaluates the value of the polynomial and retruns the value of the polynomial
int evaluation(poly *p1)
{
	poly *h1;
	int x;
	printf("\n\tEnter value for x\n");
	scanf("%d",&x);
	int value=0;
	h1=p1;
	p1=p1->next;
	while(p1!=h1)
	{
//		value=value+(p1->c)*(pow(x,(p1->p)));
		p1=p1->next;
	}
	return value;

}
