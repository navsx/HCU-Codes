#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxnodes 100

typedef struct node
{
	int a,b,c;
	char shahar[];
	struct node *baen;
	struct node *daen;
	struct node *par;
}soochi;

int main(int argc,char *argv[])
{

	int x,y,i;
	FILE *ifile,*ofile;
	char s[100],city[100];
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
		while(fgets(s,100,ifile)!=NULL)
		{
			sscanf(s,"%d,%d:%s",&x,&y,&city);
			
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
			}
			else
			{
				if((ptr->c)%2==0)
				{
						
				}
				else if((ptr->c)%2)==1)
				{
					
				}
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
