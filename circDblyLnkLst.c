#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
  {
    	int data;
    	struct node *f;
    	struct node *b;
	}nd; 


main (int argc,char *argv[])
{

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

      nd *ptri=NULL;
		  ptri=first;

			nd *ptrd=NULL;
			ptrd=first;

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
			char subsi[]="Insert";
			char subsd[]="Delete";
			char lstr[2]=":";
			char *token;
			printf("\nThese were the numbers in the input file:\n");

			while(fgets(s,100,ifile)!=NULL)
			{
				token = strtok(s,lstr);

				if(strcmp(subsd,s)==0)
				{
					token = strtok(NULL, s);
					getnumber=atoi(token);
					printf("Delete: \t\t%d\n",getnumber);

					if(ptri->f==NULL) 
					{
						printf("List is empty,can't delete anything\n");
					}
					else
					{
						while(ptrd!=last)
						{	
							if(ptrd->data!=getnumber)
							{
								//printf("ptrd:%d num:%d\n",ptrd->data,getnumber);
								ptrd=ptrd->f;
							}
							else if(ptrd->data==getnumber && first->data!=getnumber)
							{
								printf("node found\n");
								ptrd->b->f=ptrd->f;
								ptrd->f->b=ptrd->b;
								ptrd=first;

							}
							else if(first->data==getnumber)
							{
								printf("first node delted\n");
								first=ptrd->f;
								ptrd->f->b=first;
								last->f=first;
								ptrd=first;
							}
						}

						if(ptrd->data==getnumber && first!=last)
						{
							printf("Last node deleted\n");
							last=ptrd->b;
							ptri=last;
							ptrd=first;
						}
						else if(ptrd->data==getnumber && first==last)
						{
							printf("Last node deleted and nothing left in the list\n");
							first=(nd *)malloc(sizeof(nd));
							first->f=first->b=NULL;
							ptri=ptrd=last=first;
						}
						else
						{
							printf("List is already empty\n");
						}
					}

				}
				else if(strcmp(subsi,s)==0)
				{
					token = strtok(NULL, s);
					getnumber=atoi(token);
					printf("Insert:\t\t%d\n",getnumber);

					if(ptri->f==NULL)   //Insert first value
					{
						ptri->data=getnumber;
						ptri->f=ptri;
						ptri->b=ptri;
					}
					else
					{
						temp=(nd *)malloc(sizeof(nd));
						temp->data=getnumber;
						ptri->f=temp;
						temp->f=first;
						last=temp;
						temp->b=ptri;
						ptri=ptri->f;
					}

				}

			}			

			fclose(ifile);
			
			if(first->f!=NULL)
			{
				ptri=first;
				printf("Circular Doubly Linked List is : \n");
				while(ptri->f!=first)
				{
					printf("%d \n",ptri->data);
					ptri=ptri->f;
				}
				printf("%d \n",ptri->data);
			}
			else
			{
				printf("Nothing left to display\n");
			}
		}

	}

}
