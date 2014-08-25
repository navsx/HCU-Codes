#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

main (int argc,char *argv[])
{
	int atmp[100]={ [0 ... 99] = -1 };
	char strtmp[100]="\0";
	char lstr[100]="\0";
	int getnum=0,i=0;
	int count=0;
	int j,k,item;

	if(argc!=3)
	{
		printf("\n\t Please enter all file names"); //print WARNING MESSAGE IF ARGUMENTS ARE NOT 3
		//exit(0);
	}
	else
	{
		FILE *ifile=fopen(argv[1],"r"); //open file in read only mode

		if(ifile==0)
		{
			printf("\n\tFile can't be opened"); //give warning if file is not opening
			//exit(0);
		}
		else
		{


			while(fgets(lstr,100,ifile)!=NULL)   //get numbers upto end of file
			{	
				sscanf(lstr,"%d",&getnum);
				if(isdigit(getnum)==0)
				{
					atmp[i]=getnum;
					i++;

				}
				else
				{

					printf("white spaces\n");
				}
			}
		}
		fclose(ifile);
		
		printf("\nUnsorted Array : \n");
		printf("[ ");
		for(i=0;i<100;i++)
		{
			if(atmp[i]>=0)
			{
				printf("%d ",atmp[i]);
				count++;
			}
		}
		
		printf(" ]");
		
		for(i=0;i<=count;i++)
		{
			k=i;
			j=i/2;
			item=atmp[i];
			while((j>0)&&(atmp[j]<item))
			{
				atmp[k]=atmp[j];
				k=j;
				j=j/2;
			}
			atmp[k]=item;
		}
		
		printf("\n\nSorted Array : \n");
		printf("[ ");

		for(i=0;i<=count;i++)
		{
			if(atmp[i]>=0)
			{
				printf(" %d ",atmp[i]);
				//count++;
			}
		}
		printf(" ]");
			
	}
}
