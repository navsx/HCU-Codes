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

	int d1,d2;
	FILE *ifile,*ofile;
	char *s[100]=NULL;
	int nodeArr[maxnodes]={0};
	list *ptr=NULL;
	list *first=NULL;
	
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
                        	if(nodeArr[d1]==0)
                        	{
                        		ptr=(list *)malloc(sizeof(list));
                        		ptr->data=d2;
                        		ptr->link=NULL;
                        		nodeArr[d1]=ptr;
                        	}
                        	else
                        	{
                        		ptr=nodeArr[d1];
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
			ptr=nodeArr[i];
			printf("node %d is connected to : /n",nodeArr[i]);
			while(ptr!=NULL)
			{
				printf(" %d ",ptr->data);
			}
			printf("\n");
		}

	return 0;
}
