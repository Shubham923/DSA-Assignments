#include<stdio.h>
static int count;
typedef struct
{
    int row;
    int col;
    int val;

}sparse;
int input(sparse a[])
{
	int i,j,m,n,key;
	int k=1;
	printf("\n\tEnter No. of Rows and Column!!");
	scanf("%d%d",&m,&n);

	a[0].row=m;
	a[0].col=n;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&key);
				if(key==0)
				continue;
				a[k].val=key;		//writing only non zero elemenrs!!
				a[k].row=i;
				a[k].col=j;
				k++;

			}//for j ends here..
		}//for i ends here
	a[0].val=k-1;

}//input function ends here...

void display(sparse a[],int limit)
{
	int k,i,j;
	printf("\n\tHere's Your Sparse Matrix!!");
	printf("\n\tRow\tColumn\tValue");
	for(i=0;i<=limit;i++)
	{

		if(a[i].val!=0)		//displaying only non zero elements!!
		{
			printf("\n\t%d",a[i].row);
			printf("\t%d",a[i].col);
			printf("\t%d",a[i].val);

		}
	}//for ends here..




}//display function ends here..
void fast_trans(sparse a[],sparse b[])
{
    int i,j;
    int rowterms[20],startpos[20];//startpos array is used to find the starting position of each element!!
    								//rowterms is used for counting no of times elements repeated!!
    int numterms=a[0].val;
    int numcols=a[0].col;
    b[0].row=numcols;
    b[0].col=a[0].row;
    b[0].val=a[0].val;

    for(i=0;i<numcols;i++)			//initially making all elements zero to avoid garbage value!!
        rowterms[i]=0;
    for(i=1;i<numterms;i++)
    rowterms[a[i].col]++;			//for counting no of times elements repeated!!
    startpos[0]=1;					//initiating 1st element with 1.
    for(i=1;i<numcols;i++)
        startpos[i]=rowterms[i-1]+startpos[i-1];
    for(i=1;i<=numterms;i++)
    {
    j=startpos[a[i].col]++;
    b[j].col=a[i].row;
    b[j].row=a[i].col;
    b[j].val=a[i].val;




    }//for i ends here...


}//fast transpose ends here....

void addition(sparse a[],sparse b[],sparse c[])

{	input(b);
	display(b,b[0].val);

	int i,j,t;		//sparse c in the resultant matrix...
	i=1,j=1,t=1;

	int c1,c2,r1,r2;			//where c1 and c2 are no of columns in matrix 1 and matrix 2..

	c1=a[0].col;			//assigning value of no of columns to c1;
	c2=b[0].col;
	r1=a[0].row;			//r1 and r2 are nothing but the number of rows in matrixn 1 and 2
	r2=b[0].row;

	while(i<=c1&&j<=c2)
	{

		if(a[i].row==b[j].row&&a[i].col==b[j].col)		//if the rows and columns are equal
		{

			c[i].row=a[i].row;
			c[j].col=b[j].col;
			c[t].val=a[i].val+b[j].val;
			t++;
			i++;
			j++;

		}

		else if(a[i].row<b[j].row)//arranging in asecending order...
		{

			c[t].row=a[i].row;
			c[t].col=a[i].col;
			c[t].val=a[i].val;
			t++;
			i++;

		}

		else if(a[i].row>b[j].row)
		{

			c[t].col=b[j].col;
			c[t].row=b[j].row;
			c[t].val=b[j].val;
			t++;
			j++;


		}

		else if(a[i].row==b[j].row&&a[i].col<b[j].col)//for sequence if rows of both matrices are equal then sequence is decided by no of columns
		{

			  c[t].row=a[i].row;
			            c[t].col=a[i].col;
			            c[t].val=a[i].val;
			            t++;
			            i++;


		}
		else if(a[i].row==b[j].row&&a[i].col>b[j].col)
			{

				  c[t].row=b[j].row;
				            c[t].col=b[j].col;
				            c[t].val=b[j].val;
				            t++;
				            j++;


			}

		 while(i<=c1)
		    {
		        c[t].row=a[i].row;//printing remaining values from first sparse matrix
		        c[t].col=a[i].col;
		        c[t].val=a[i].val;
		        t++;
		        i++;
		    }
		    while(j<=c2)
		    {
		        c[t].row=b[j].row;//printing remaining values from second sparse matrix
		        c[t].col=b[j].col;
		        c[t].val=b[j].val;
		        t++;
		        j++;
		    }

}//final while ends here...

	    c[0].row=r1;
	    c[0].col=c1;
	    c[0].val=t-2;

}//void addition ends here....

void trans(sparse a[],sparse c[])
{
	int i,j;
	c[0].row=a[0].row;
		c[0].col=a[0].col;
		c[0].val=a[0].val;
		int k=1;
		if(a[0].val>0)//taking elements greater than zero...
		{
		for(i=0;i<a[0].col;i++)
		{
			for(j=1;j<=a[0].val;j++)
			{
				if(a[j].col==i)
				{
					c[k].row=a[j].col;
					c[k].col=a[j].row;
					c[k].val=a[j].val;
					k++;
				}
			}
		}


		}

}
int main()
{
    int n,ch;
    sparse a[100],b[100],c[100];


     do
     {

    	 printf("\n\tEnter Your Choice!!\n\t1.Input(Sparse A)\n\t2.Display\n\t3.Fast Transpose\n\t4.Addition\n\t5.Normal Transpose\n\tExit!!");
    	 scanf("%d",&ch);
    	 switch(ch)
    	 {
    	 	 case 1:

    	 		 input(a);
    	 		 display(a,a[0].val);
    	 		 break;
    	 	 case 2:
    	 	    display(a,a[0].val);
    	 		display(b,b[0].val);
    	 		 break;
    	 	 case 3:
    	 		 fast_trans(a,b);
    	 		 display(b,b[0].val);
    	 		 break;
    	 	 case 4:
    	 		 printf("\n\tEnter Sparse B");
    	 		 addition(a,b,c);
    	 		 display(c,c[0].val);
 		 //display(c,c[0].val-1);

    	 		 break;
    	 	 case 5:
    	 		 trans(a,c);
    	 		 display(c,c[0].val-1);
    	 }
     }while(ch!=6);
    return 0;
}//mainn ends here
