#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}qu;

/*qu *first=NULL;
qu *last=NULL;
qu *ptrl=NULL;
qu *ptrf=NULL;
qu *prev=NULL;

first=malloc(sizeof(qu)); 
first->next=NULL;
first->prev=NULL;
ptrf=ptrl=last=first; */


int entinQ(int,qu *,qu *,qu *,qu *);
int delfQ(qu *,qu *,qu *,qu *);
int display(qu *,qu *);

int main()
{
/*	Q *first=*last=*ptrl=NULL;
	first=(Q*)malloc(sizeof(Q));
	first->next=NULL;
	ptrl=last=first; */

	qu *first=NULL;
	qu *last=NULL;
	qu *ptrl=(qu *)malloc(sizeof(qu));
	ptrl->data = 0;
	qu *ptrf=NULL;

	first=(qu *)malloc(sizeof(qu));
	first->next=NULL;
	first->prev=NULL;
	ptrf=first;
	last=first;


	int i=0,num=0;

	printf("These numbers will be added to the queue\n");
	printf("[ ");
	for(i=0;i<=7;i++)
	{
		num=rand()%100;
		printf("%d ",num);
		entinQ(num,ptrf,ptrl,last,first);
	}
	printf(" ]");

	printf("Queue after insertion is\n");
	display(ptrf,last);
	
	num=(rand()%8)+1;

	printf("These numbers will be deleted from the queue\n");
	printf("[ ");
	for(i=0;i<num;i++)
	{
		delfQ(ptrf,ptrl,last,first);
	}
	printf(" ]");

	printf("Queue after insertion is\n");
	display(ptrf,last);

	return 0;
}

int entinQ(int num,qu *ptrf,qu *ptrl,qu *last,qu *first)
{     
	//printf("hello");
	if(ptrl->data == 0)
	{
		printf("%d\n",ptrl->data);
		ptrl = first;
		ptrl->data=num;
		printf("1st Num ins is =%d\n",ptrl->data);
		//ptrl->next=(qu *)malloc(sizeof(qu));
	}
	else
	{
		ptrl->next=(qu *)malloc(sizeof(qu));
		ptrl->next->data=num;
		//ptrl->next->next=(qu *)malloc(sizeof(qu));
		ptrl->next->prev=ptrl;
		ptrl=ptrl->next;
		ptrl->next=NULL;
		last=ptrl;
		printf("other Num ins is =%d\n",ptrl->data);
	}
	return 0;
}

int delfQ(qu *ptrf,qu *ptrl,qu *last,qu *first)
{
	if(first==last && first!=NULL)
	{
		printf("Deleting Last element\n");
		first=NULL;
		ptrl=NULL;
		last=NULL;
	}
	else if(first==last && first==NULL)
	{
		printf("Nothing left to delete\n");
	}
	else
	{
		printf("Deleting..\n");
		last=last->prev;
		last->next=NULL;
		ptrl=last;
	}

	return 0;
}
int display(qu *ptrf,qu *last)
{
	printf("[ ");
	while(ptrf!=last)
	{
		printf("%d ",ptrf->data);
		ptrf=ptrf->next;
	}
	printf(" ]");
	return 0;
}
