#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *getnode();
struct node * insertend( struct node *head)
{
      struct node *temp=NULL;
      if(head==NULL)
      {
          head=getnode();
      }
      else
      {
          temp=head;
          while(temp->next!=NULL)//run the while loop upto the end of link i.e equal to temp->next
          temp=temp->next;
          temp->next=getnode();//and add another node just next to previous one..
      }
    return head;
}

struct node * insertfirst( struct node *head)
{
      struct node *temp=NULL;
      if(head==NULL)
      {
          head=getnode();	//if head is null initially the allocate some memory by calling getnode function...
      }
      else
      {
        temp=getnode();
       temp->next=head;
        head=temp;
      }
    return head;
}
struct node *insertpos(head)		//inserting at any requird position
{
	int key;
	printf("\n\tEnter the Position(among Inserted Elements) where you want to add Node");
	scanf("%d",&key);		//key is data which is stored in any node
	struct node *temp=NULL,*temp1=NULL,*t=NULL;
	temp=head;
	t=getnode();
	while(temp->data==key)
	temp=temp->next;		//Incrementing temp pointer..

	temp1=temp->next;		//here we are inserting node t in betwwen temp and temp1..
	temp->next = t;
	t->next=temp1;
	return head;


}//insert function ends here...

struct node *deletepos( struct node *head)		//deleting at any required position
{ int i=1,position;
	printf("\n\tInsert Position!!");
	scanf("%d",&position);		//here we have taken postion as the postion of node
	struct node *temp1=NULL;
	struct node *temp=head;		//temp is pointing the node which is pointed by head
	while(temp->next!=NULL)
	{
		temp1=temp;
		temp=temp->next;	//here temp1 is the previous node of temp node..

		if(i==position-1)
		{
		temp1->next=temp->next;		//previous nod(temp1) is pointing to node after its immediate node
        free(temp);				//freeing the temp node..
        break;
    }
    i++;
	}
	return head;		//starting position is retained..
}

struct node *deletelast(head)
{
	struct node *temp,*temp1;
	temp=head;
	if(head==NULL)
		printf("\n\tList is Empty!!");
	else
	{
	while(temp->next!=NULL)
		{
		temp1=temp;			//temp1 is the previous node while temp is current node
		temp=temp->next;	//Incrementing pointer


		}
		temp1->next=NULL;		//storing null at second last pointer and freeing the memory of last pointer
		free(temp);
	}
	return head;
}//delete function ends here
struct node *deletefirst(struct node *head)
{
	if(head==NULL)		//checking whether link is empty or not
	printf("\n\tList is Empty!!");
	else
	{
		struct node *temp;
		temp=head;
		head=temp->next;
		free(temp);
	}

	return head;
}//delete function ends here

void  display(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("\t%d -> ", temp->data);
        temp=temp->next;		//will continue to display the list upto the null....

    }
}

struct node * getnode()
{   struct node *temp;		//function will allocate memory dynamically to the  required node

    temp= ( struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    printf("\n\tEnter The Data::");	//take data in node and store it in data part..
    scanf("%d", &temp->data);
    return temp;
}

void reverse(struct node* head)
{
    if(head!=NULL)
    {
        reverse(head->next);
        printf("\t %d ->", head->data);
    }
}
int revert(struct node *head)
{
		struct node *current, *temp, *result;
	    temp=NULL;
	    result=NULL;
	    current=head;
	    if(head->next==NULL)
	        return head;
	    while(current!=NULL)
	    {
	        temp=current->next;
	        current->next=result;
	        result=current;
	        current=temp;
	    }
	    head=result;
	    return head;





}

int main()
{
    int choice,ch,ch1;

    struct node *head=NULL;//CREATE EMPTY NODE
    do
        {
    printf("\n\t*****Main Menu*****\n\t1.Insert\n\t2.Deletion\n\t3.Reverse\n\t0.Exit\n\tEnter Your Choice::");
    printf("\n\t.............................................................................................");
    scanf("%d", &choice);

switch(choice)
{
case 1://this is for inserting node at end
	printf("\n\t1.At End\n\t2.At first\n\t3.At Specific Position!!");
	 scanf("%d", &ch);
	switch(ch)
	{
	case 1:
    head= insertend(head);
    display(head);
    break;
	case 2:


	    head=insertfirst(head);

	    display(head);
		break;
	case 3:
		head=insertpos(head);
	    display(head);
	}
	break;
case 2://this is for inserting node at first
printf("\n\t1.At End\n\t2.At Start\n\t3.At Specific Position!!");
scanf("%d",&ch1);
switch(ch1)
	{
case 1:

	head= deletelast(head);
	 display(head);
	break;
case 2:
	head=deletefirst(head);
	 display(head);
	 break;
case 3:
	head=deletepos(head);
	display(head);
break;
	}
break;
case 3:
reverse(head);
break;
case 4:
	head=revert(head);
	display(head);
	break;

}
    }while(choice!=5);
    return 0;

}
