#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct node
{
	int data;
	struct node *link;
}Q;

Q *first=*last=*ptrf=*ptrl=NULL;
first=(Q*)malloc(sizeof(Q));
first->link=NULL;
ptrf=ptrl=last=first;


int entinQ(int);
int delfQ();
int display();

int main()
{
/*	Q *first=*last=*ptrf=*ptrl=NULL;
	first=(Q*)malloc(sizeof(Q));
	first->link=NULL;
	ptrf=ptrl=last=first; */
	int i=0,num=0;

	printf("These numbers will be added to the queue\n");
	printf("[ ");
	for(i=0;i<=7;i++)
	{
		num=rand()%100;
		printf("%d ",num);
		entinQ(num);
	}
	printf(" ]");

	printf("Queue after insertion is\n");
	display();
	
	num=(rand()%8)+1;

	printf("These numbers will be deleted from the queue\n");
	printf("[ ");
	for(i=0;i<num;i++)
	{
		delfQ();
	}
	printf(" ]");

	printf("Queue after insertion is\n");
	display();

	return 0;
}

int entinQ(int num)
{
	if(ptrl->link==NULL)
	{
		ptrl->data=num;
	}
	else
	{
		ptrl->link=(Q*)malloc(sizeof(Q));
		ptrl=ptrl->link;
		ptrl->data=num;
		ptrl->link=NULL;
		last=ptrl;
	}
	return 0;
}

int delfQ()
{
	if(first==last && first!=NULL)
	{
		printf("Deleting Last element\n");
		first=NULL;
		ptrf=ptrl=last=NULL;
	}
	else if(first==NULL)
	{
		printf("Nothing left to delete\n");
	}
	else
	{

	}

	return 0;
}
int display()
{
	return 0;
}
