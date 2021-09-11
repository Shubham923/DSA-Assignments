#include<stdio.h>
struct student
{
	int roll;
	char name[20];
	float per;

};//struct student ends here.,,,
int input(struct student []);
void display(struct student [],int);
void selection(struct student [],int);
void insertion(int[],int);
void bubble(struct student [],int);
void binary(struct student s[],int);
int binaryR(struct student s[],int ,int,int);
int min(struct student [],int,int,int*);
int main()
{
	int m,ch,*comp,beg,end,key,res;
	struct student s[10];
	m=input(s);
	display(s,m);
	printf("\n\tEnter Your Choice!!\n\t1.Selection\n\t2.Insertion\n\t3.Bubble\n\t4.Binary Search");
	do
		{scanf("%d",&ch);
	switch(ch)
	{
		case 1://this is for selection
			selection(s,m);
			display(s,m);
			break;
		case 2:
			insertion(s,m);
			display(s,m);
			break;
		case 3:
			bubble(s,m);
			display(s,m);
			break;
		case 4:
			binary(s,m);
			break;
		case 5:
			bubble(s,m);
			beg=0,end=m;
			printf("\n\tEnter the Element you want to Search");
			scanf("%d",&key);
			res=binaryR(s,key,beg,end);//beg represents starting position and end represents last element!!

			if(res==1)
				printf("\n\tSearch Succesful!!");
			else
				printf("\n\tSearch Unsuccessful");
			break;
		case 0:
			exit(1);
			break;




		}//switch ends here...
		}while(1);
	return 0;

}//int main ends here...
int input(struct student s[10])
{
	int i,n,m;
	printf("\n\tEnter Number of Elements!!");
	scanf("%d",&n);
	printf("\n\tEnter the Elements!!");
	for(i=0;i<n;i++)

	{
		printf("\n\tEnter Roll Number::");
		scanf("%d",&s[i].roll);
		printf("\n\tEnter Name");
		scanf("%s",s[i].name);
		printf("\n\tEnter Percentage!!");
		scanf("%f",&s[i].per);
		m++;


	}//for ends here
	return m;
}//input fun ends here...
void display(struct student s[10],int n)
{
	int i;
	printf("\n\tRoll\tName");
	printf("\n\t...................................................");
	for(i=0;i<n;i++)
	{
		printf("\n");
		printf("\t%d",s[i].roll);
		printf("\t%s",s[i].name);
		printf("\t%f",s[i].per);
		printf("\n");

	}
}//display ends here
void selection(struct student s[10],int m)
{
	struct student s1;
	char temp1[10];
	float temp2;

	printf("Swaps\tComp\ttrack\n.........................................................");
	int i,j,loc,temp,*comp,swap=0,totswap=0,totcomp=0;

	for(i=0;i<m;i++)
	{
		comp=0,swap=0;
		loc=min(s,i,m,&comp);//this is for finding minimum from given no of elements!!

    if(loc!=i)
    {	swap++;
    	s1=s[loc];			//swapping min element with the current running ith element!!
    	s[loc]=s[i];
    	s[i]=s1;


    	printf("\n%d\t%d",swap,comp);

        for(j=0;j<m;j++)
        	printf("\t%s",s[j].name);	//for showing passwise op with eac pass

    }//if ends here...


    	totswap+=swap;		//totswap for counting no.of swaps hence used for finding best avg and worst case!!
    	totcomp+=comp;

	}//for ends here...

		printf("\n\tTotal Number of Swaps=%d",totswap);
		printf("\n\tTotal Number of Comp=%d",totcomp);
		printf("\n\tAnalysis 		  :: Worst Case");

}//selection ends here,
int min(struct student s[10],int lb,int ub,int *comp)/*Function is used for finding minimum from given elements*/
{
	int temp=0;		//temp is used for finding no of comparisons!!
		*comp=0;

	int min=lb;
	while(lb<ub)
	{

		if(strcmp(s[lb].name,s[min].name)<0)//comparing names alphabetically

		{
				min=lb;		//this statement is for assigning lowerbound value to min variable!!

		}
		temp++;
		lb++;
	}

	*comp=temp;
	return min;

}//min ends here...
void insertion(int a[10],int m)
{

	int i,j,temp=0;
	for(i=0;i<m;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0;j--)

			if(a[j]>temp)

				a[j+1]=a[j];



			else
				break;
			a[j+1]=temp;
			printf("\n");
			display(a,m);
}


}//insertion ends here...
void bubble(struct student a[10],int m)
{	struct student s1;
	 printf("Swaps\tComp\ttrack\n.........................................................");
	 int i,j,k,temp,comp=0,swap=0,totswap=0,totcomp=0;


	 for(i=0;i<m-1;i++)
	 {
		comp=0,swap=0;			//restoring swaps and counts to zero after single swap!!
		for(j=0;j<m-1-i;j++)
		{
			comp++;

			if(a[j].roll>a[j+1].roll)
			{	swap++;
				s1=a[j+1];		//swapping n+1 th element with nth element!!
				a[j+1]=a[j];
				a[j]=s1;
			}


		}

		printf("\n%d\t%d",swap,comp);
		for(k=0;k<m;k++)
		printf("\t%d",a[k].roll);
		totswap+=swap;		//statement is used to count total no.of swaps and comparisons!!
		totcomp+=comp;
	}
	 	 printf("\n\tNo of Swaps=%d",totswap);
	 	 printf("\n\tNo of Comp=%d",totcomp);
	 	 if(totcomp==m-1)
	 		 printf("Best Case!!");
	 	 else if(totcomp>m-1&&((m^2)+m)/2)
	 		 printf("Average Case!!");
	 	 else
	 		 printf("Worst Case!!");

}//bubble ends here...
void binary(struct student s[],int m)
{
	bubble(s,m);
	display(s,m);
	int low,mid,high,no,i;
	low=0;
	high=m;
	mid=(low+high)/2;			//this formula is required to find out mid position
	printf("mid=%d",mid);
	printf("\n\tEnter the Element you want to Search");
	scanf("%d",&no);

	for(i=0;i<m;i++)
	{
	if(s[mid].roll==no)
	printf("Search Successful at position !!");		//comparing the key with roll numbers...


	else
	printf("\n\tSearch Unsuccesful!!");

	if(s[mid].roll<no)
		low=mid+1;
	if(s[mid].roll>no)
		high=mid-1;

	mid=(low+high)/2;

	}//for ends here...
}//binary ends here.....
int binaryR(struct student s[],int key,int beg,int end )
{

	int mid;
	mid=(beg+end)/2;		//this formula is used to find out the mid element from given array..

	if(s[mid].roll==key)
		{
			return 1;

		}
	if(s[mid].roll<key)
		{
			beg=mid+1;
			return binaryR(s,key,beg,end);

		}
	if(s[mid].roll>key)
		{
			end=mid-1;
		return binaryR(s,key,beg,end);



		}


}
