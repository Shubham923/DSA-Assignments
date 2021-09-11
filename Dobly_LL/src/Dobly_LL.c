#include<stdio.h>
struct node
{
	int data;
	struct node *next,*pre;

};
struct node *insertfirst(struct node *head);
struct node *insertend(struct node *head);
struct node *insertmid(struct node *);
struct node* deleteend(struct node *);
struct node *deletefirst(struct node *head);
struct node *deletemid(struct node *head);
int main()
{
	int ch;
	struct node *head;
	do
	{
		printf("\n\tEnter Your Choice!!\n\t1.Insert End\n\t2.Insert First\n\t3.Insert Mid\n\t4.Delete End\n\t5.Delete First\n\t6.Delete Mid\n\t7.Reverse\n\t8.Revert!!");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			head=insertend(head);
			display(head);
			break;
		case 2:
			head=insertfirst(head);
			display(head);
			break;
		case 3:
			head=insertmid(head);
			display(head);
			break;
		case 4:
			head=deleteend(head);
			display(head);
			break;
		case 5:
			head=deletefirst(head);
			display(head);
			break;
		case 6:
			head=deletemid(head);
			display(head);

		}
	}while(1);
return 0;

}
struct node *getnode()
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));

printf("\n\tEnter the Data");
scanf("%d",&temp->data);
return temp;

}
struct node *insertend(struct node *head)
{
struct node *temp,*t;
t=getnode();
if(head==NULL)
{
	head=t;
	t->next=NULL;
	t->pre=NULL;

}
else
{
temp=head;
while(temp->next!=NULL)
temp=temp->next;

temp->next=t;
t->next=NULL;
t->pre=temp;

}
return head;
}
struct node *insertfirst(struct node *head)
{
	struct node *temp,*t;
	t=getnode();
	if(head==NULL)
	{
		head=t;
		t->next=NULL;
		t->pre=NULL;

	}
	else
	{
	temp=head;
	t->next=temp;
	t->pre=NULL;
	head=t;

	}
	return head;

}
void display(struct node *temp)
{
while(temp!=NULL)
{
printf("%d->",temp->data);
temp=temp->next;
}
}

struct node *insertmid(struct node *head)
{	struct node *temp=NULL,*t=NULL,*temp1;
	t=getnode();
	int i=1,position;
	if(head==NULL)
	{
			head=t;
			t->next=NULL;
			t->pre=NULL;

	}
	else
	{

		printf("\n\tEnter the Position you want to enter the data!!");
		scanf("%d",&position);
temp=head;
		while(temp->next!=NULL)
		{	temp1=temp;
			temp=temp->next;

			if(i==position-1)
			{
			temp1->next=t;
			t->next=temp;
			t->pre=temp1;


			}
i++;




		}

	}

return head;


}
struct node *deleteend(struct node *head)
{
	struct node *temp=NULL,*temp1=NULL;
	if(head==NULL)
printf("List is Empty!!");
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{	temp1=temp;
			temp=temp->next;}
		temp1->next=NULL;
		free(temp);





	}

return head;
}
struct node *deletefirst(struct node *head)
{
	struct node *temp=NULL,*temp1=NULL;
		if(head==NULL)
	printf("List is Empty!!");
		else
		{
			temp=head;
			temp1=temp->next;
			temp1->pre=NULL;
			head=temp1;


		}

return head;
}
struct node *deletemid(struct node *head)
{	int i=1,position;
	struct node *temp=NULL,*temp1=NULL;
			if(head==NULL)
		printf("List is Empty!!");
			else
			{
				temp=head;

				printf("Position?");
				scanf("%d",&position);
				while(temp->next!=NULL)
				{
				temp1=temp;
				temp=temp->next;
				printf(".");
				if(i==position-1)
				{
					temp1->next=temp->next;
					free(temp);


				}
				i++;

				}
			}

return head;
}
