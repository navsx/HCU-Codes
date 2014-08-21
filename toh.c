#include <stdio.h>
#include <stdlib.h>

#define nval -5

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
	for(i=0;i<noe;i++)
	{
		pushstk(i);
	}

	/*for(i=0;i<noe;i++)
	{
		popstk();
	}*/
	tower(noe);
}

int crtstk(int noe)
{

	s1=(st *)malloc(sizeof(st *));
	s1->pstack=(int *)malloc(sizeof(int)* noe);
	s1->size=0;
	s1->cap=noe;

	s2=(st *)malloc(sizeof(st *));
	s2->pstack=(int *)malloc(sizeof(int)* noe);
	s2->size=0;
	s2->cap=noe;

	s3=(st *)malloc(sizeof(st *));
	s3->pstack=(int *)malloc(sizeof(int)* noe);
	s3->size=0;
	s3->cap=noe;

	return 0;

}

int pushstk(int ele)
{
	if(s1->size==s1->cap)
	{
		printf("stack is full now,have to pop\n");
	}
	else
	{
		s1->pstack[s1->size]=ele;
		printf("ele is %d in the address field %d\n",(s1->pstack[s1->size]),&(s1->pstack[s1->size]));
		s1->size++;
	}

	if(s2->size==s2->cap)
	{
		//printf("stack is full now,have to pop\n");
		s2->size=0;
	}
	else
	{
		s2->pstack[s2->size]=nval;
		//printf("ele is %d\n",(s2->pstack[s2->size]));
		s2->size++;
	}

	if(s3->size==s3->cap)
	{
		//printf("stack is full now,have to pop\n");
		s3->size=0;
	}
	else
	{
		s3->pstack[s3->size]=nval;
		//printf("ele is %d\n",(s3->pstack[s3->size]));
		s3->size++;
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

	while(s1->size!=0 && s3->size!=s3->cap)
	{
		instk1();
	}

	int instk1()
	{
		while(falg!=element)
		{
			if(element%2!=0)
			{
				while(flag!=element && element>(s3->pstack[s3->size]))
				{
					s3->pstack[s3->size]=element;
					s3->size++;
					flag=element;
					s1->pstack[s1->size]=nval;
					s1->size--;
					element=(s1->pstack[s1->size]);
				}
				instk2();
			}
			else
			{
				while(element>(s2->pstack[s2->size]))
				{
					s2->pstack[s2->size]=element;
					s2->size++;
					flag=element;
					s1->pstack[s1->size]=nval;
					s1->size--;
					element=(s1->pstack[s1->size]);
				}
				instk2();
			}
		}
	}
}
