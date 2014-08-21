#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int cap;
	int size;
	int *pstack;
}st;

int crtstk(int);
int pushstk(int);
int popstk();

st *s=NULL;
int *top=NULL;

int main()
{
	//st *s;
	int noe,i=0;
	printf("How many disc do you want?\n Just eneter a number between 3 and 10\n");
	//if(getchar())
	scanf("%d",&noe);
	//if(isdigit(noe)==0|| noe<3 || noe>10)
	//{
	//	printf("Enter a valid number");
	//	exit(0);
	//}
	//else
	//{
	if(getchar())
		crtstk(noe);
	for(i=0;i<noe;i++)
	{
		pushstk(i);
	}

		for(i=0;i<noe;i++)
		{
		popstk();
		}
	//}
}

int crtstk(int noe)
{

	s=(st *)malloc(sizeof(st *));
	s->pstack=(int *)malloc(sizeof(int)* noe);
	s->size=0;
	s->cap=noe;
	top=s->pstack;
	printf("top is pinting to,and address is: %d , %d\n",*top,top);
	return 0;

}

int pushstk(int ele)
{
	if(s->size==s->cap)
	{
		printf("stack is full now,have to pop\n");
	}
	else
	{
		s->pstack[s->size]=ele;
		//s->pstack[s->(size++)] = ele;
		printf("ele is %d in the address field %d\n",(s->pstack[s->size]),&(s->pstack[s->size]));
		s->size++;
		//top=&(s->pstack[s->size]);
		//printf("Checking the top: %d\n",*top);
	}
	return 0;
}

int popstk()
{
	if(s->size==0)
	{
		printf("Stack is empty now, last element is %d\n",s->pstack[s->size]);

	}
	else
	{
		s->size--;
		printf("Popping : %d,size is :%d\n",s->pstack[s->size],s->size);
		//s->size--;
	}
	return 0;
}
