/*
 ============================================================================
 Name        : CLL_Poly.c
 Author      : Shubham
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<math.h>
struct poly
{
int p,c;
struct node *next;

};
struct poly *create(int);
struct poly *getnode();
void display(struct poly*);
struct poly *add(struct poly*,struct poly*);
struct poly *multiply(struct poly *,struct poly *);
struct poly *mult(struct poly *,struct poly*);
int evaluation(struct poly*);
int main()
{

int ch,no,val;
struct poly *p1,*p2,*p3=NULL;
do
{
	printf("\n\tEnter Your Choice!!\n\t1.input\n\t2.Addition\n\t3.Multiplication\n\t4.Evaluation!!");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		printf("\n\tEnter no of Terms!!");
		scanf("%d",&no);
		p1=create(no);
		display(p1);
		printf("\n\tEnter no of Terms!!");
				scanf("%d",&no);
				p2=create(no);
				display(p2);
				printf("check");
		break;
	case 2:

		p3=add(p1,p2);
		display(p3);
		break;
	case 3:
		p3=multiply(p1,p2);
	display(p3);
		break;
	case 4:
		val=evaluation(p2);
		printf("%d",val);






	}
}while(ch!=8);

}
struct poly *getnode()
{
struct poly *temp;
temp=(struct poly*)malloc(sizeof(struct poly));
printf("\n\tEnter Co Efficient");
scanf("%d",&temp->c);
printf("\n\tEnter Power");
scanf("%d",&temp->p);
temp->next=temp;
return temp;
}
struct poly *create(int no)
{
int i;
struct poly *p3,*r3;
p3=r3=(struct poly*)malloc(sizeof(struct poly));
p3->c=p3->p=-1;

for(i=0;i<no;i++)
{
	p3->next=getnode();
	p3=p3->next;

}
printf("Here");
p3->next=r3;

return r3;

}
void display(struct poly *p3)
{
struct poly *h3;
h3=p3;
p3=p3->next;

while(p3!=h3)
{
	printf("%dx^%d",p3->c,p3->p);
	p3=p3->next;
	if(p3!=h3)
		printf("+");

}


}
struct poly *add(struct poly *p1,struct poly *p2)
{

struct poly *h1,*h2,*r3=NULL,*p3=NULL;
p3=r3=(struct poly*)malloc(sizeof(struct poly));
p3->c=p3->p=-1;
p3->next=NULL;


h1=p1;
h2=p2;
p1=p1->next;
p2=p2->next;
while(p1!=h1 && p2!=h2)
{

	p3->next=(struct poly*)malloc(sizeof(struct poly));
	p3=p3->next;


	 if((p1->p)>(p2->p))
	{

		p3->p=p1->p;
		p3->c=p1->c;
		p1=p1->next;
		//p3=p3->next;

	}
	else if((p1->p)<(p2->p))
		{

			p3->p=p2->p;
			p3->c=p2->c;
			p2=p2->next;
			//p3=p3->next;

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
	p3->next=(struct poly*)malloc(sizeof(struct poly));
	p3=p3->next;
	p3->p=p1->p;
			p3->c=p1->c;
			p1=p1->next;
			//p3=(struct poly*)malloc(sizeof(struct poly));


}
while(p2!=h2)
{	p3->next=(struct poly*)malloc(sizeof(struct poly));
p3=p3->next;

	p3->p=p2->p;
			p3->c=p2->c;
			p2=p2->next;
			//p3=p3->next;


}
p3->next=r3;
return r3;


}
struct poly * multiply(struct poly *p1,struct poly * p2)
{
	struct poly *h2,*p3,*temp;
	p3=(struct poly *)malloc(sizeof(struct poly));
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
struct poly * mult(struct poly *p1,struct poly *x)
{
	struct poly * p3,*r3,*h1=p1;
	p3=r3=(struct poly *)malloc(sizeof(struct poly));
	p3->c=p3->p=-1;
	p3->next=p3;
	p1=p1->next;
	while(p1!=h1)
	{
		p3->next=(struct poly *)malloc(sizeof(struct poly));
		p3=p3->next;
		p3->p=(p1->p)+(x->p);
		p3->c=(p1->c)*(x->c);
		p1=p1->next;
	}
	p3->next=r3;
	return r3;
}
int evaluation(struct poly *p1)
{
/*struct poly *h1;
int value=0,x;
int a,b;

printf("\n\tEnter X:-");
scanf("%d",&x);
a=x;
b=p1->p;
h1=p1;
printf("b=%d",h1->p);
h1=p1;
p1=p1->next;
while(p1!=h1)
{
printf("\n%d",p1->p);
value=value+((p1->c)*pow(x,h1->p));
p1=p1->next;
}*/
	int value=0,x,b;
	struct poly *h1;
	h1=p1;
	h1 = h1->next;
	while(h1!=p1)
	{
		b = h1->p;
		value = value + (h1->c)*pow(x,b);
		h1 = h1->next;
	}
return  value;

}
