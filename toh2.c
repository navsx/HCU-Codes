#include <stdio.h>
#include <stdlib.h>
#define nval -9
typedef struct stack
{
	int cap;
	int size;
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
	for(i=0;i<noe;i++)
	{
		display();
	}
	printf("\n\nand now the result\n\n");
	tower(noe);

	for(i=0;i<noe;i++)
	{
		display();
	}
}
int crtstk(int noe)
{
	s1=(st *)malloc(sizeof(st *));
	s1->pstack=(int *)malloc(sizeof(int)* noe);
	s1->size=0;
	s1->cap=noe-1;
	s2=(st *)malloc(sizeof(st *));
	s2->pstack=(int *)malloc(sizeof(int)* noe);
	s2->size=0;
	s2->cap=noe-1;
	s3=(st *)malloc(sizeof(st *));
	s3->pstack=(int *)malloc(sizeof(int)* noe);
	s3->size=0;
	s3->cap=noe-1;
	return 0;
}
int pushstk(int ele)
{
	if(s1->size==s1->cap)
	{
		//s1->size=0;
		printf("stack1 is full\n");
		(s1->size)++;	
	}
	else
	{
		s1->pstack[s1->size]=ele;
		printf("s1 ele is %d\n",(s1->pstack[s1->size]));
		(s1->size)++;
	}
	if(s2->size==s2->cap)
	{
	//	s2->size=0;
		s2->pstack[s2->size]=nval;
		(s2->size)++;
		printf("stack2 is full\n");
	}
	else
	{
		s2->pstack[s2->size]=nval;
		printf("s2 ele is %d\n",(s2->pstack[s2->size]));
		(s2->size)++;
	}
	if(s3->size==s3->cap)
	{
	//	s3->size=0;
		s2->pstack[s2->size]=nval;
		printf("stack3 is full %d\n");
		(s3->size)++;
	}
	else
	{
		s3->pstack[s3->size]=nval;
		printf("s3 ele is %d\n",(s3->pstack[s3->size]));
		(s3->size)++;
	}
	return 0;
}
int popstk()
{
	if(s1->size==0)
	{
		printf("Stack is empty now, last element is %d\n",s1->pstack[s1->size]);
	}
	else
	{
		s1->size--;
		printf("Popping : %d,size is :%d\n",s1->pstack[s1->size],s1->size);
	}
	return 0;
}
int tower(int noe)
{
	int instk1();
	int instk2();
	int instk3();
	int element=(s1->pstack[s1->size]);
	int flag=-5;
	int s1t=100,s2t=100,s3t=100;
	s2->size=0;
	s3->size=0;
	while(s1->size!=0 && s3->size!=s3->cap)
	{
		element=(s1->pstack[s1->size]);
		while(flag!=element)
		{
			if(element%2!=0 && element<s3t)
			{
				s3->pstack[s3->size]=element;
				s3t=(s3->pstack[s3->size]);
				s3->size++;
				flag=element;
				s1->pstack[s1->size]=nval;
				s1->size--;
				s1t=(s1->pstack[s1->size]);
				element=(s1->pstack[s1->size]);
			}
			else if(element<s2t)
			{
				s2->pstack[s2->size]=element;
				s2t=(s2->pstack[s2->size]);
				s2->size++;
				flag=element;
				s1->pstack[s1->size]=nval;
				s1->size--;
				element=(s1->pstack[s1->size]);
				s1t=(s3->pstack[s3->size]);
			}
		}
		flag=-5;
		element=(s2->pstack[s2->size]);
		while(flag!=element)
		{
			if(element%2!=0 && element<s1t)
			{
				s1->pstack[s1->size]=element;
				s1t=(s1->pstack[s1->size]);
				s1->size++;
				flag=element;
				s2->pstack[s2->size]=nval;
				s2->size--;
				s2t=(s2->pstack[s2->size]);
				element=(s2->pstack[s2->size]);
			}
			else if(element<s3t)
			{
				s3->pstack[s3->size]=element;
				s3t=(s3->pstack[s3->size]);
				s3->size++;
				flag=element;
				s2->pstack[s2->size]=nval;
				s2->size--;
				element=(s2->pstack[s2->size]);
				s2t=(s2->pstack[s2->size]);
			}
		}
		flag=-5;
		element=(s3->pstack[s3->size]);
		while(flag!=element)
		{
			if(element%2!=0 && element<s2t)
			{
				s2->pstack[s2->size]=element;
				s2t=(s2->pstack[s2->size]);
				s2->size++;
				flag=element;
				s3->pstack[s3->size]=nval;
				s3->size--;
				s3t=(s3->pstack[s3->size]);
				element=(s3->pstack[s3->size]);
			}
			else if(element<s1t)
			{
				s1->pstack[s1->size]=element;
				s1t=(s1->pstack[s1->size]);
				s1->size++;
				flag=element;
				s3->pstack[s3->size]=nval;
				s3->size--;
				element=(s3->pstack[s3->size]);
				s3t=(s3->pstack[s3->size]);
			}
		}
		flag=-5;
		element=(s1->pstack[s1->size]);
	}
	return 0;
}
int display()
{
	if(s1->size==0 && s2->size==0 && s3->size==0)
	{
		printf("%d\t:%d\t:%d\n",s1->pstack[s1->size],s2->pstack[s2->size],s3->pstack[s3->size]);
	}
	else
	{
		s1->size--;
		s2->size--;
		s3->size--;
		printf("%d\t:%d\t:%d\n",s1->pstack[s1->size],s2->pstack[s2->size],s3->pstack[s3->size]);	
	}
	return 0;
}
