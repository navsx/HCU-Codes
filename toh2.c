#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define nval -9
typedef struct stack
{
	int cap;
	int index;
	int *pstack;
}st;
int crtstk(int);
int pushstk(int);
int popstk();
int tower(int);
int display();
st *s1=NULL;
st *s2=NULL;
st *s3=NULL;
int *top=NULL;
//int flag,element;


/*-------------------------------------------------***************************************-------------------------------------------*/


int main()
{
	int noe,i=0;
	printf("How many disc do you want?\n Just eneter a number between 3 and 10\n");
	scanf("%d",&noe);
	if(getchar())
	crtstk(noe);
	for(i=noe-1;i>=0;i--)
	{
		pushstk(i);
	}
	/*for(i=0;i<noe;i++)
	  {
	  popstk();
	  }*/
	for(i=noe-1;i>=0;i--)
	{
		display();
	}
	printf("\n\nand now the result\n\n");
	
	tower(noe);

	for(i=noe-1;i>=0;i--)
	{
		display();
	}
}


/*-------------------------------------------------***************************************-------------------------------------------*/

int crtstk(int noe)
{
	s1=(st *)malloc(sizeof(st *));
	s1->pstack=(int *)malloc(sizeof(int)* noe);
	s1->index=0;
	s1->cap=noe-1;
	s2=(st *)malloc(sizeof(st *));
	s2->pstack=(int *)malloc(sizeof(int)* noe);
	s2->index=0;
	s2->cap=noe-1;
	s3=(st *)malloc(sizeof(st *));
	s3->pstack=(int *)malloc(sizeof(int)* noe);
	s3->index=0;
	s3->cap=noe-1;
	return 0;
}


/*-------------------------------------------------***************************************-------------------------------------------*/


int pushstk(int ele)
{
	if(s1->index==s1->cap)
	{
		//s1->index=0;
		printf("stack1 is full\n");
		(s1->index)++;	
	}
	else
	{
		s1->pstack[s1->index]=ele;
		printf("s1 ele is %d index= %d\n",(s1->pstack[s1->index]),(s1->index));
		(s1->index)++;
	}
	if(s2->index==s2->cap)
	{
	//	s2->index=0;
		s2->pstack[s2->index]=nval;
		(s2->index)++;
		printf("stack2 is full\n");
	}
	else
	{
		s2->pstack[s2->index]=nval;
		printf("s2 ele is %d\n",(s2->pstack[s2->index]));
		(s2->index)++;
	}

	if(s3->index==s3->cap)
	{
	//	s2->index=0;
		s3->pstack[s3->index]=nval;
		(s3->index)++;
		printf("stack3 is full\n");
	}
	else
	{
		s3->pstack[s3->index]=nval;
		printf("s3 ele is %d\n",(s3->pstack[s3->index]));
		(s3->index)++;
	}
	return 0;

}


/*-------------------------------------------------***************************************-------------------------------------------*/

int popstk()
{
	if(s1->index==0)
	{
		printf("Stack is empty now, last element is %d\n",s1->pstack[s1->index]);
	}
	else
	{
		s1->index--;
		printf("Popping : %d,index is :%d\n",s1->pstack[s1->index],s1->index);
	}
	return 0;
}

/*-------------------------------------------------***************************************-------------------------------------------*/

int tower(int noe)
{
	printf("In the tower\n");
	int instk1();
	int instk2();
	int instk3();
	int flag=-5;
	int s1t=100,s2t=100,s3t=100;
	s1->index=noe-1;
	s2->index=-1;
	s3->index=-1;
	printf("s1 ka ele:%d\t s1:%d \ts3:%d \ts3 cap:%d \n",(s1->pstack[s1->index]),(s1->index),(s3->index),(s3->cap));
	int count=0;
	int element=(s1->pstack[s1->index]);

	//double numboele=(double)noe;
	//while((s1->index)>=0 && (s3->index)<=((s3->cap)-1))
	while(count<=(pow(2,noe)-1));
	{

//		printf("Going to process stack1\n");

		while(s1t!=flag && (element<s3t || element<s2t))
		{
			if(s1t!=flag && element%2!=0 && element<s3t)
			{
				s3->index++;
				s3->pstack[s3->index]=element;
				printf("s3 mein =%d\n",(s3->pstack[s3->index]));
				s3t=(s3->pstack[s3->index]);
				printf("s3t=%d\n",s3t);

				flag=s3t;
				printf("flag=%d\n",flag);

				s1->pstack[s1->index]=nval;
				s1->index--;

				if(s1->index<0)
				{
					s1t=100;
					break;
				}
				else
				{
					s1t=(s1->pstack[s1->index]);
					printf("s1t=%d\n",s1t);

					element=(s1->pstack[s1->index]);
					printf("element=%d\n",element);

					count++;
					printf("count=%d\n",count);
				}
			}
			else if(s1t!=flag && element%2==0 && element<s2t)
			{
				s2->index++;
				s2->pstack[s2->index]=element;
				printf("s2 mein =%d\n",(s2->pstack[s2->index]));
				s2t=(s2->pstack[s2->index]);
				printf("s2t=%d\n",s2t);

				flag=s2t;
				printf("flag=%d\n",flag);

				s1->pstack[s1->index]=nval;
				s1->index--;

				if(s1->index<0)
				{
					s1t=100;
					break;
				}
				else
				{
					s1t=(s1->pstack[s1->index]);
					printf("s1t=%d\n",s1t);

					element=(s1->pstack[s1->index]);
					printf("element=%d\n",element);

					count++;
					printf("count=%d\n",count);
				}
			}
		}

/*--------------------------------------------------------------------------------------*/
		element=(s2->pstack[s2->index]);
//		printf("Going to process stack2\n");

		while(s2t!=flag && (element<s3t || element<s1t) && (s2->index)>=0)
		{
			if(s2t!=flag && element%2!=0 && element<s1t)
			{
				s1->index++;
				s1->pstack[s1->index]=element;
				printf("s1 mein =%d\n",(s1->pstack[s1->index]));
				s1t=(s1->pstack[s1->index]);
				printf("s1t=%d\n",s1t);

				flag=s1t;
				printf("flag=%d\n",flag);

				s2->pstack[s2->index]=nval;
				s2->index--;

				if(s2->index<0)
				{
					s2t=100;
					break;
				}
				else
				{
					s2t=(s2->pstack[s2->index]);
					printf("s2t=%d\n",s2t);

					element=(s2->pstack[s2->index]);
					printf("element=%d\n",element);

					count++;
					printf("count=%d\n",count);
				}
			}
			else if(s2t!=flag && element%2==0 && element<s3t)
			{
				s3->index++;
				s3->pstack[s3->index]=element;
				printf("s3 mein =%d\n",(s3->pstack[s3->index]));
				s3t=(s3->pstack[s3->index]);
				printf("s3t=%d\n",s3t);

				flag=s3t;
				printf("flag=%d\n",flag);

				s2->pstack[s2->index]=nval;
				s2->index--;
				if(s2->index<0)
				{
					s2t=100;
					break;
				}
				else
				{
					s2t=(s2->pstack[s2->index]);
					printf("s2t=%d\n",s2t);

					element=(s2->pstack[s2->index]);
					printf("element=%d\n",element);

					count++;
					printf("count=%d\n",count);
				}
			}
		}


/*--------------------------------------------------------------------------------------*/
//		printf("Going to process stack3\n");
		element=(s3->pstack[s3->index]);

		while(s3t!=flag && (element<s1t || element<s2t) && (s2->index)>=0)
		{
			if(s3t!=flag && element%2!=0 && element<s2t)
			{
				s2->index++;
				s2->pstack[s2->index]=element;
				printf("s2 mein =%d\n",(s2->pstack[s2->index]));
				s2t=(s2->pstack[s2->index]);
				printf("s2t=%d\n",s2t);

				flag=s2t;
				printf("flag=%d\n",flag);

				s3->pstack[s3->index]=nval;
				s3->index--;

				if(s3->index<0)
				{
					s3t=100;
					break;
				}
				else
				{
					s3t=(s3->pstack[s3->index]);
					printf("s3t=%d\n",s3t);

					element=(s3->pstack[s3->index]);
					printf("element=%d\n",element);

					count++;
					printf("count=%d\n",count);
				}
			}
			else if(s3t!=flag && element%2==0 && element<s1t)
			{
				s1->index++;
				s1->pstack[s1->index]=element;
				printf("s1 mein =%d\n",(s1->pstack[s1->index]));
				s1t=(s1->pstack[s1->index]);
				printf("s1t=%d\n",s1t);

				flag=s1t;
				printf("flag=%d\n",flag);

				s3->pstack[s3->index]=nval;
				s3->index--;

				if(s3->index<0)
				{
					s3t=100;
					break;
				}
				else
				{
					s3t=(s3->pstack[s3->index]);
					printf("s3t=%d\n",s3t);

					element=(s3->pstack[s3->index]);
					printf("element=%d\n",element);

					count++;
					printf("count=%d\n",count);
				}
			}
		}
		
		element=(s1->pstack[s1->index]);
	}
	return 0;
}


/*-------------------------------------------------***************************************-------------------------------------------*/

int display()
{
	if(s1->index==0 && s2->index==0 && s3->index==0)
	{
		printf("%d\t:%d\t:%d\n",s1->pstack[s1->index],s2->pstack[s2->index],s3->pstack[s3->index]);
	}
	else
	{
		s1->index--;
		s2->index--;
		s3->index--;
		printf("%d\t:%d\t:%d\n",s1->pstack[s1->index],s2->pstack[s2->index],s3->pstack[s3->index]);	
	}
	return 0;
}
