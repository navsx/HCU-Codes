#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define in Insert
//#define del Delete

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
			printf("\nThese were the numbers in the input file:");

			while(fgets(s,10,ifile)!=NULL)
			{
				token = strtok(s,lstr);

				if(strcmp(subsd,s)==0)
				{
					token = strtok(NULL, s);
					getnumber=atoi(token);
					printf("Delete: \n\t\t%d\n",getnumber);

					if(ptri->f==NULL) 
					{
						printf("List is empty,can't delete anything\n");
					}
					else
					{
						while(ptrd!=last)
						{
							//printf("ptrd->data");
							
							if(ptrd->data!=getnumber)
							{
							printf("ptrd:%d num:%d\n",ptrd->data,getnumber);
								ptrd=ptrd->f;
								//printf("mv f");
							}							else if(ptrd->data==getnumber && first->data!=getnumber)
							{
								printf("nd found");
								ptrd->b->f=ptrd->f;
								ptrd->f->b=ptrd->b;
								ptrd=first;

							}
							else
							{
								printf("frst nd delted");
								first=ptrd->f;
								ptrd->f->b=first;
								last->f=first;
								ptrd=first;
							}
						}
					}

				}
				else if(strcmp(subsi,s)==0)
				{
					token = strtok(NULL, s);
					getnumber=atoi(token);
					printf("Insert:\n\t\t%d\n",getnumber);

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

/*				if(ptr->f==NULL)   //Insert first value
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
				}*/
			}			

			fclose(ifile);

			ptri=first;
			printf("Circular Doubly Linked List is : \n");
			while(ptri->f!=first)
			{
				printf("%d \n",ptri->data);
				ptri=ptri->f;
			}
			printf("%d \n",ptri->data);
		}

	}

}
