#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 100

typedef struct node
{
	int a,b,c;
	char shahar[max];
	struct node *baen;
	struct node *daen;
	struct node *par;
}soochi;

int insertkd(int ,int ,char *shahar,soochi **,soochi **);

int main(int argc,char *argv[])
{

	int x,y,i;
	FILE *ifile,*ofile;
	char s[max],city[max];
	soochi *ptr=NULL;
	soochi *first=NULL;
	
	first=(soochi *)malloc(sizeof(soochi));

	ifile=fopen(argv[1],"r");
	if(ifile==0)
	{
		printf("agian in parent:File can't be opened/n");
		exit(1);
	}
	else
	{
		printf("File opened succ :) \n");
		while(fgets(s,100,ifile)!=NULL)
		{
			sscanf(s,"%d,%d:%[^\n]",&x,&y,city);
			printf("x,y,city = %d,%d,%s \n",x,y,city);
			if(ptr==NULL)
			{
				ptr=(soochi *)malloc(sizeof(soochi));
				ptr->a=x;
				ptr->b=y;
				ptr->c=0;
				strcpy(ptr->shahar,city);
				ptr->baen=NULL;
				ptr->daen=NULL;
				ptr->par=NULL;
				first=ptr;
				printf("First Node info: \n X=%d Y=%d Name=%s\n",first->a,first->b,first->shahar);
			}
			else
			{
				printf("Calling insert func\n");
				insertkd(x,y,city,&ptr,&first);
			}

		}
		fclose(ifile);
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
	}
*/

	return 0;
}

int insertkd(int x,int y,char *city,soochi **ptr,soochi **pptr)
{

soochi *temp=NULL;	
temp=(soochi *)malloc(sizeof(soochi));

soochi *bp=NULL;	
bp=(soochi *)malloc(sizeof(soochi));
bp=*(pptr);

temp=*(ptr);
int x1=x;int y1=y;char cname[100];
strcpy(cname,city);

printf("Inside insert\n trying to insert x-> %d , y-> %d , city-> %s \n",x1,y1,cname);
	
	while(temp!=NULL)
	{
		if((temp->c)%2==0)
		{
			if((temp->a)<x1)
			{
				bp=temp;
				temp=temp->baen;
				insertkd(x1,y1,cname,&temp,&bp);
			}
			else
			{
				bp=temp;
				temp=temp->daen;
				insertkd(x1,y1,cname,&temp,&bp);
			}			
		}
		else if((temp->c)%2==1)
		{
			if((temp->a)<y1)
			{
				bp=temp;
				temp=temp->baen;
				insertkd(x1,y1,cname,&temp,&bp);
			}
			else
			{
				bp=temp;
				temp=temp->daen;
				insertkd(x1,y1,cname,&temp,&bp);
			}
		}
	}

		if(((*pptr)->c)%2==0)
		{
			printf("Inside last iteration\n");
			if(((*pptr)->a)<x1)
			{
				//insert @right
				printf("X cmp and right\n");
				temp->a=x1;
				temp->b=y1;
				strcpy(temp->shahar,cname);
				temp->par=*pptr;
				temp->baen=NULL;
				temp->daen=NULL;
				temp->c=((*pptr)->c)+1;
				(*pptr)->daen=temp;
			}
			else
			{
				//insert @left
				printf("X cmp and left\n");
				temp->a=x1;
				temp->b=y1;
				strcpy(temp->shahar,cname);
				temp->par=*pptr;
				temp->baen=NULL;
				temp->daen=NULL;
				temp->c=((*pptr)->c)+1;
				(*pptr)->baen=temp;
			}			
		}
		else if((temp->c)%2==1)
		{
			if((temp->a)<y1)
			{
				//insert @right
				printf("Y cmp and right\n");
				temp->a=x1;
				temp->b=y1;
				strcpy(temp->shahar,cname);
				temp->par=*pptr;
				temp->baen=NULL;
				temp->daen=NULL;
				temp->c=((*pptr)->c)+1;
				(*pptr)->daen=temp;
			}
			else
			{
				//insert @left
				printf("Y cmp and left\n");
				temp->a=x1;
				temp->b=y1;
				strcpy(temp->shahar,cname);
				temp->par=*pptr;
				temp->baen=NULL;
				temp->daen=NULL;
				temp->c=((*pptr)->c)+1;
				(*pptr)->baen=temp;
			}
		}
return 0;
}

int display(soochi **first)
{
	soochi* temp=*first;
	printf("[ ");
	while(temp->baen!=NULL && temp->daen!=NULL)
	{
		printf("%s \n",temp->shahar);
		temp=temp->baen;
		printf("%s \n",temp->shahar);
		display(&temp);
		temp=temp->daen;
		printf("%s \n",temp->shahar);
		display(&temp);
	}
	
	if(temp->baen==NULL && temp->daen!=NULL)
	{
		temp=temp->daen;
		printf("%s \n",temp->shahar);		
		display(&temp);
	}
	
	if(temp->daen==NULL && temp->baen!=NULL)
	{
		temp=temp->baen;
		printf("%s \n",temp->shahar);
		display(&temp);	
	}
	printf(" ]");
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
