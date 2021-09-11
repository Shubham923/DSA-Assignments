#include<stdio.h>
#include<string.h>
 typedef struct student
{
	int id;
	char name[20];
	long mobile;


};
int input(struct student s[]);
void display(struct student s[],int);
void quick(struct student s[10],int,int);
void quick1(struct student s[10],int,int);
int main()
{
	int i,no,m;
	struct student s[30];
	int ch;

	do
	{
	printf("\n\tEnter Your Choice\n\t1.Input\n\t2.Display\n\t3.Sort by Name!!\n\t4.Sort by Phone\n\t5.Exit!!");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			m=input(s);
			break;
		case 2:
			display(s,m);
			break;
		case 3:
			printf("\n\tSwap\tComp\tTrack");
			quick(s,0,m-1);
			display(s,m);
			break;
		case 4:
			quick1(s,0,m-1);
			display(s,m);
			break;
		case 5:
			exit(1);




	}//switch ends here..

	}while(ch!=0);




	return 0;
}//main ends here...
int input(struct student s[30])
{

	int i, m;
	printf("\n\tEnter No.of Records");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("\n\tEnter Identity Number");
		scanf("%d",&s[i].id);
		printf("\n\tEnter Name of Customer");
		scanf("%s",s[i].name);
		printf("\n\tEnter MObile Number!!");
		scanf("%d",&s[i].mobile);



	}


return m;

}

void display(struct student s[30],int m)
{

	int i;
		printf("\n\tROLL\t\NAME\tMobile");		//dispalying records in tabular format!!
		for(i=0;i<m;i++)
		{

		printf("\n\t%d",s[i].id);
		printf("\t%s",s[i].name);
		printf("\t%d",s[i].mobile);

		}




}
void quick(struct student s[10],int left,int right)
{
	struct student s1;			//temporary object to swap to records
	int i,j,pivot,temp,swap=0,comp=0;
	char temp1[30],temp3[30];
	long temp2;

		if(left<right)
		{

			i=left,j=right;
			pivot=left;							//setting pivot value as left most element among the elements...
			while(i<j)
			{


			if(strcmp(s[pivot].name,s[i].name)<0)	//compares two strings alphabetically

				{i++;comp++;
				}

			if(strcmp(s[pivot].name,s[j].name)>0)
					{j--;

					}
			if(i<j)
			{
				s1=s[i];		/*swaping two objects in order to swap their record*/
				s[i]=s[j];
				s[j]=s1;
				swap++;

			}//if ends here


			}//if ends here....

			swap++;
			s1=s[pivot];
			s[pivot]=s[j];
			s[j]=s1;
			quick(s,left,j-1);
			quick(s,j+1,right);
		}


}//void quick ends here...
void quick1(struct student s[],int left,int right)
{
	struct student temp;
	int i,j;
	int pivot,temp1;
	if(left<right)
	{
		i=left,j=right;
		pivot=left;
		while(i<j)
		{
			if(s[pivot].mobile<s[i].mobile)		//it will keep imcreamenting i unless pivot greater than ith element
				i++;
			if(s[pivot].mobile>s[j].mobile)
				j--;
			if(i<j)
			{

				temp=s[i];						//swapping ith and j th object...
				s[i]=s[j];
				s[j]=temp;



			}



		}

			temp1=s[pivot].mobile;
			s[pivot].mobile=s[j].mobile;
			s[j].mobile=temp1;
			quick1(s,left,j-1);			//partionning the given array again calling the same function
			quick1(s,j+1,right);




	}//if ends  here...

}
