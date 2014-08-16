#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

main (int argc,char *argv[])
{
	int atmp[5];
	char strtmp[100]="\0";
	char lstr[100]="\0";
	int getnum=0,i=0;

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

			printf("\nNow looping:\n");

			while(fgets(lstr,100,ifile)!=NULL)   //get numbers upto end of file
			{	
				printf("in while\n");
				sscanf(lstr,"%d",&getnum);
				//printf("after scanf\n");
				if(isdigit(getnum)==0)
				{
					printf("entering in arr\n");
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

		for(i=0;i<5;i++)
		{
			printf("[%d]\n",atmp[i]);
		}
	}

}	
