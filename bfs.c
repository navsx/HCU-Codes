#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxnodes 100

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}qu;

int entinQ(int,qu **,qu **,qu **,qu **);
int delfQ(qu **,qu **,qu **,qu **);

typedef struct ls
{
	int data;
	struct ls *link;
	int visited;
	int explored;

}list;

int main(int argc,char *argv[])
{

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

	int d1,d2,i,p,catch;
	FILE *ifile,*ofile;
	char s[100];
	int nodeArr[maxnodes]={0};
	list *ptr=NULL;
	int arrv[maxnodes]={0};
	int arre[maxnodes]={0};
	list *arr[maxnodes];

	for (i=0; i<maxnodes; i++) arr[i] = NULL;

	ifile=fopen(argv[1],"r");
	if(ifile==0)
	{
		printf("agian in parent:File can't be opened/n");
		exit(1);
	}
	else
	{
		while(fgets(s,100,ifile)!=NULL)
		{
			sscanf(s,"(%d,%d)",&d1,&d2);
			ptr=arr[d1];
			if(ptr==NULL)
			{
				ptr=(list *)malloc(sizeof(list));
				ptr->data=d1;
				ptr->visited=0;
				ptr->explored=0;

				ptr->link=(list *)malloc(sizeof(list));
				ptr->link->data=d2;
				ptr->link->visited=0;
				ptr->link->explored=0;
				ptr->link->link=NULL;
				//arr[d1]=ptr;
			}
			else
			{
				while(ptr->link=NULL)
				{
					ptr=ptr->link;
				}
				ptr->link=(list *)malloc(sizeof(list));
				ptr->link->data=d2;
				ptr->visited=0;
				ptr->explored=0;
				ptr->link->link=NULL;
			}

			ptr=arr[d2];
			if(ptr==NULL)
			{
				ptr=(list *)malloc(sizeof(list));
				ptr->data=d1;
				ptr->link=NULL;
				arr[d2]=ptr;
			}
			else
			{
				while(ptr->link=NULL)
				{
					ptr=ptr->link;
				}
				ptr->link=(list *)malloc(sizeof(list));
				ptr->link->data=d1;
				ptr->link->link=NULL;
			}
		}
		fclose(ifile);
	}


	for(i=1;i<=8;i++)
	{
		ptr=arr[i];
		printf("node %d is connected to : /n",i);
		while(ptr!=NULL)
		{
			printf(" %d ",ptr->data);
			ptr=ptr->link;
		}
		printf("\n");
	}


	printf("Pick one edge to start traversal with from 1 to 8\n");
	scanf("%d",&p);

	ptr=arr[p];
	ptr->explored=1;
	arrv[p]=1;
	arre[p]=1;
	printf("First node explored is %d\n",ptr->data);
	
	while(ptr)
	{
		ptr->visited=1;
		arrv[ptr->data]=1;
		//arrv[ptr->data]=1;
		entinQ(ptr->data,&ptrf,&ptrl,&last,&first);
		ptr=ptr->link;
	}

	printf("Other nodes are \n");

	while((catch=delfQ(&ptrf,&ptrl,&last,&first))!=-1)
	{
		ptr=arr[catch];
		//ptr->explored=1;
		arre[catch]=1;

		printf("%d\n",catch);

		while(ptr)
		{
			if(arrv[ptr->data]==1)
			{
				ptr=ptr->link;
			}
			else
			{
				//ptr->visited=1;
				arrv[ptr->data]=1;
				entinQ(ptr->data,&ptrf,&ptrl,&last,&first);
				ptr=ptr->link;
			}
		}

	}

	/*	for(i=1;i<=8;i++)
		{
		ptr=arr[i];
		printf("node %d is connected to : /n",i);
		while(ptr!=NULL)
		{
		printf(" %d ",ptr->data);
		ptr=ptr->link;
		}
		printf("\n");
		} */

	return 0;
}

/*
   (1,3)
   (2,4)
   (3,5)
   (4,2)
   (5,6)
   (6,3)
   (7,8)
   (8,1)
   */

int entinQ(int num,qu **ptrf,qu **ptrl,qu **last,qu **first)
{     
	//printf("hello");
	if((*ptrl)->data == 0)
	{
		//printf("%d\n",(*ptrl)->data);
		*ptrl = *first;
		(*ptrl)->data=num;
		printf("1st Num ins is =%d\n",(*ptrl)->data);
		//ptrl->next=(qu *)malloc(sizeof(qu));
	}
	else
	{
		(*ptrl)->next=(qu *)malloc(sizeof(qu));
		(*ptrl)->next->data=num;
		//ptrl->next->next=(qu *)malloc(sizeof(qu));
		(*ptrl)->next->prev=*ptrl;
		*ptrl=(*ptrl)->next;
		(*ptrl)->next=NULL;
		*last=*ptrl;
		printf("other Num ins is =%d\n",(*ptrl)->data);
	}
	return 0;
}

int delfQ(qu **ptrf,qu **ptrl,qu **last,qu **first)
{
	int val;
	if(*first==*last && *first!=NULL)
	{
		printf("Deleting Last element\n");
		val = (*first)->data;
		*first=NULL;
		*ptrl=NULL;
		*last=NULL;
		return val;
	}
	else if(*first==*last && *first==NULL)
	{
		printf("Nothing left to delete\n");
		return -1;
	}
	else
	{
		printf("Deleting..\n");
		/*           *ptrl=(*ptrl)->prev;
			     (*ptrl)->next=NULL;
		 *last=*ptrl;*/

		printf("%d",(*ptrf)->data);

		val = (*first)->data;

		*ptrf=(*ptrf)->next;
		(*ptrf)->prev=NULL;
		*first=*ptrf;

		return val;
	}

}
