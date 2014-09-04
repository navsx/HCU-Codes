#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct node    //A node structure is initialized
        {
		int pr;
		int name;
		int at;
		int ct;
		struct node *link;
	}; 
	
void printList(struct node*);


main (int argc,char *argv[])
{
	int atmp[4]={};
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
					for(l=0;l<4;l++)
					{				
				       		//printf("%s\n",ptoken);
						sscanf(ptoken, "%d", &stoi);
						//printf("Hi");
						atmp[l]=stoi;
						//printf("%d\n",atmp[l]);
			                	ptoken=strtok(NULL,delim);
					}
			       	}
				printf("just before i at first");

				if(ptr==NULL)   //Insert first value
				{

					printf("i at first");
					ptr=first;				
					ptr->pr=atmp[0];
					ptr->name=atmp[1];
					ptr->at=atmp[2];
					ptr->ct=atmp[3];
				}

				else if(ptr->pr > atmp[0])    //If the new number is less then first node => Insert 
				{
					//struct node *temp2=NULL;
					temp2=(struct node *)malloc(sizeof(struct node));
					temp2->pr=atmp[0];
	                                temp2->name=atmp[1];
	                                temp2->at=atmp[2];
	                                temp2->ct=atmp[3];
					temp2->link=ptr;
					first=temp2;
					//ptr->link=NULL;
					ptr=first;
				}
				else 
				{
					//inBetween(ptr->link,getnumber,ptr);
					while(ptr->pr < atmp[0])
					{
						if(ptr->link==NULL)			//Insert @ last
						{
							ptr->link=(struct node *)malloc(sizeof(struct node));
							ptr->link->pr=atmp[0];
							ptr->link->name=atmp[1];
							ptr->link->at=atmp[2];
							ptr->link->ct=atmp[3];
							ptr->link->link=NULL;
							//printf("\n I am in insert at last\n");
							exit;
						}
						else if(ptr->link!=NULL && ptr->link->pr>atmp[0])	//Insert @ the middle
						{
							//struct node *temp=NULL;
							temp=(struct node *)malloc(sizeof(struct node));
							temp->pr=atmp[0];
							temp->name=atmp[0];
							temp->at=atmp[0];
							temp->ct=atmp[0];
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
	printf("Priority\tpID\tA.T.\tC.T. : \n");
	while(temp3!=NULL)
	{
		printf("%d\t,%d\t,%d\t,%d \n",temp3->pr,temp3->name,temp3->at,temp3->ct);
		temp3=temp3->link;	
	}
}	
