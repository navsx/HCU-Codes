#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxnodes 100

typedef struct node
{
	int data;
	struct node *link;
}list;

int main(int argc,char *argv[])
{

	int d1,d2,i;
	FILE *ifile,*ofile;
	char s[100];
	int nodeArr[maxnodes]={0};
	list *ptr=NULL;
	list *first=NULL;
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
				ptr->data=d2;
				ptr->link=NULL;
				arr[d1]=ptr;
			}
			else
			{
				while(ptr->link=NULL)
				{
					ptr=ptr->link;
				}
				ptr->link=(list *)malloc(sizeof(list));
				ptr->link->data=d2;
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
