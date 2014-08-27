#include <stdio.h>

typedef struct node
        {
		int data;
		struct node *f;
		struct node *b;
	}nd; 


main (int argc,char *argv[])
{

	void inBetween(struct node *ptr);

	if(argc!=3)
	{
		printf("\n\tPlease use input file and output files"); //print WARNING MESSAGE IF ARGUMENTS ARE NOT 3
		//exit(0);
	}	
	else
	{
		        nd *first=NULL;
			first =(nd *)malloc(sizeof(nd)); 
			first->f=NULL;
			first->b=NULL;

			nd *last=NULL;		
			last=first;

                        nd *ptr=NULL;
		        ptr=first;

			nd *temp=NULL;
				
				                                              
		FILE *ifile=fopen(argv[1],"r"); //open file in read only mode
		
		if(ifile==0)
		{
			printf("\n\tFile can't be opened"); //give warning if file is not opening
			//exit(0);
		}
		else
		{
			int getnumber;
			char s[100];
			printf("\nThese were the numbers in the input file:");

			while(fgets(s,10,ifile)!=NULL)
			{
				getnumber=atoi(s);
				printf("\n\t\t%d",getnumber);

				if(ptr->f==NULL)   //Insert first value
				{
					ptr->data=getnumber;
					ptr->f=ptr;
					ptr->b=ptr;
				}
				else
				{
					temp=(nd *)malloc(sizeof(nd));
					temp->data=getnumber;
					ptr->f=temp;
					temp->f=first;
					last=temp;
					temp->b=ptr;
					ptr=ptr->f;
				}
			}			

			fclose(ifile);

			ptr=first;
			printf("Circular Doubly Linked List is : \n");
			while(ptr->f!=first)
			{
				printf("%d \n",ptr->data);
				ptr=ptr->f;
			}
			printf("%d \n",ptr->data);
		}

	}

}
