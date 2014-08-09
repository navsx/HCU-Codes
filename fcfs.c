#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct node    //A node structure is initialized
        {
		int prio;
		int name;
		int atime;
		int ctime;
		struct node *link;
	}; 
	
void printList(struct node*);


main (int argc,char *argv[])
{
	int atmp[5]={};
	char strtmp[100]="\0";
	char lstr[100]="\0";
	char delim[]=",";
	char *ptoken=NULL;
	int stoi=0,l=0;

	if(argc!=2)
	{
		printf("\n\t Please enter all file names"); //print WARNING MESSAGE IF ARGUMENTS ARE NOT 3
		//exit(0);
	}
	else
	{
		struct node *first=NULL;
		first =(struct node *)malloc(sizeof(struct node)); //allocating memory of size node
				
	        first->link=NULL;               //First pointer pointing to an empty node with link portion having null value
				
		struct node *ptr=NULL;  //A temprory pointer to traverse the linked list		        
		struct node *temp=NULL;	//Another temp pointer to use in the insertion in the middle
		struct node *temp2=NULL;

		FILE *ifile=fopen(argv[1],"r"); //open file in read only mode
		
		if(ifile==0)
		{
			printf("\n\tFile can't be opened"); //give warning if file is not opening
			//exit(0);
		}
		else
		{
			printf("\nThese were the numbers in the input file:");

			while(fgets(lstr,100,ifile)!=NULL)   //get numbers upto end of file
			{	
				strcpy(strtmp,lstr);
				ptoken=strtok(lstr,delim);
				l=0;

			        while(ptoken!=NULL)
				{	
					for(l=0;l<5;l++)
					{				
				       		//printf("%s\n",ptoken);
						sscanf(ptoken, "%d", &stoi);
						atmp[l]=stoi;
			                	ptoken=strtok(NULL,delim);
					}
			       	}


				if(ptr==NULL)   //Insert first value
				{

					ptr=first;				
                                ptr->data=getnumber;
				}

				else if(ptr->data > getnumber)    //If the new number is less then first node => Insert @first
				{
					//struct node *temp2=NULL;
					temp2=(struct node *)malloc(sizeof(struct node));
					temp2->data=getnumber;
					temp2->link=ptr;
					first=temp2;
					//ptr->link=NULL;
					ptr=first;
				}
				else 
				{
					//inBetween(ptr->link,getnumber,ptr);
					while(ptr->data < getnumber)
					{
						if(ptr->link==NULL)			//Insert @ last
						{
							ptr->link=(struct node *)malloc(sizeof(struct node));
							ptr->link->data=getnumber;
							ptr->link->link=NULL;
							//printf("\n I am in insert at last\n");
							exit;
						}
						else if(ptr->link!=NULL && ptr->link->data>getnumber)	//Insert @ the middle
						{
							//struct node *temp=NULL;
							temp=(struct node *)malloc(sizeof(struct node));
							temp->data=getnumber;
							temp->link=ptr->link;
							ptr->link=temp;
							//temp=NULL;
							//printf("\nI am in the insert in the middle\n");
							exit;
						}
						else
						{
							ptr=ptr->link;
						}


					}
					ptr=first;
				}
			}
			
			fclose(ifile);
			
			printList(first);
			
		}

	}
	
}


void printList(struct node *ptr)
{
	struct node *temp3=NULL;
	temp3=ptr;
	printf("The contents of the list are : \n");
	while(temp3!=NULL)
	{
		printf("%d \n",temp3->data);
		temp3=temp3->link;	
	}
}	
