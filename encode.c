#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main (int argc,char *argv[])
{

	char tempChar,readChar,readLine[100];
	int getnumber,i;
	FILE *ifile=NULL,*ofile=NULL;
	if(argc!=3)
	{
		printf("\n\tPlease use input file and output files"); //print WARNING MESSAGE IF ARGUMENTS ARE NOT 3
		exit(0);
	}	
	else
	{		
				                                              
		ifile=fopen(argv[1],"r"); //open file in read only mode
		ofile=fopen(argv[2],"w"); //open output file in write mode
		
		if(ifile==0 || ofile==0)
		{
			printf("\n\tFiles can't be opened"); //give warning if file is not opening
			exit(0);
		}
		else
		{
			//int getnumber,i;
			//char readLine[100];
			//char readChar;
			//printf("\nThese were the numbers in the input file:");

			while(fgets(readLine,10,ifile)!=NULL)   //get numbers upto end of file
			{
				for(i=0;i<=strlen(readLine);i++)
				{
					readChar=readLine[i];
				/*	if(isspace(readChar))
					{
						//readChar='\n';
						fputc(readChar,ofile);
						//printf("\n");
					} */

					if(isupper(readChar))
					{
						tempChar=readChar;
						//tempChar=tempChar+32;
						tempChar=tempChar+4;
						if(tempChar>90)
						{
							tempChar=(tempChar%90)+64;
						}
						fputc(tempChar,ofile);
					}

					else if(islower(readChar))
					{
						tempChar=readChar;
						//tempChar=tempChar-32;
						tempChar=tempChar+4;
						if(tempChar>122)
						{
							tempChar=(tempChar%122)+96;
						}
						fputc(tempChar,ofile);
						//putchar(readChar);
					}
					else
					{
						fputc(readChar,ofile);
					}
			
				}
			}			

			fclose(ifile);
			fclose(ofile);
		}

	}

}
