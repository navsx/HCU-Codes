#include <stdio.h>
#include <stdlib.h>

 struct node    //A node structure is initialized
        {
		int data;
		struct node *link;
	}; 
	
void printList(struct node*);
void inBetween(struct node*,int getnumber,struct node*);


main (int argc,char *argv[])
{
	int getnumber;

	if(argc!=3)
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
		//struct node *temp=NULL;	//Another temp pointer to use in the insertion in the middle			                                              
		FILE *ifile=fopen(argv[1],"r"); //open file in read only mode
		
		if(ifile==0)
		{
			printf("\n\tFile can't be opened"); //give warning if file is not opening
			//exit(0);
		}
		else
		{
			//int getnumber;
			char s[100];
			printf("\nThese were the numbers in the input file:");

			while(fgets(s,10,ifile)!=NULL)   //get numbers upto end of file
			{
				getnumber=atoi(s);  //use atoi function to convert sting into the integer
				printf("\n\t\t%d",getnumber); //Printing the numbers
				//printf(" : \t\t%s",s); //Printing the string as it is

				if(ptr==NULL)   //Insert first value
				{

                                ptr=first;				
                                ptr->data=getnumber;
				}

				else if(ptr->data > getnumber)    //If the new number is less then first node => Insert @first
				{
					struct node *temp2=NULL;
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
							printf("\n I am in insert at last\n");
							exit;
						}
						else if(ptr->link!=NULL && ptr->link->data>getnumber)	//Insert @ the middle
						{
							struct node *temp=NULL;
							temp=(struct node *)malloc(sizeof(struct node));
							temp->data=getnumber;
							temp->link=ptr->link;
							ptr->link=temp;
							//temp=NULL;
							printf("\nI am in the insert in the middle\n");
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


/* void inBetween(struct node *next,int num,struct node *prev)	//Traverse the list
{

	printf("\n I am in function calling \n");

	if(next==NULL)			//Insert @ last
	{
		next=(struct node *)malloc(sizeof(struct node));
		next->data=num;
		next->link=NULL;
		printf("\n I am in insert at last\n");
		return;
	}
	else if(next!=NULL && next->data>num)	//Insert @ the middle
	{
		struct node *temp=NULL;
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=num;
		temp->link=next;
		prev=temp;
		//temp=NULL;
		printf("\nI am in the insert in the middle\n");
		return;
	}
	else
	{
		printf("\nRecursion is called\n");
		inBetween(next->link,num,prev->link);
	}
	return;
} */
					
					
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
