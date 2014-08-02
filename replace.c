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

		if(readLine[i]=='s'&& readLine[i+1]=='t' && readLine[i+2]=='u' && readLine[i+3]=='d' && readLine[i+4]=='e' && readLine[i+5]=='n' && readLine[i+6]=='t'){
						//printf("I am looking for t now");
						//if(readLine[i+1]=='t' && readLine[i+2]=='u' && readLine[i+3]=='d' && readLine[i+4]=='e'
						//		      && readLine[i+5]=='n' && readLine[i+6]=='t')
						//{
							fputs("graduate",ofile);//put string here
							//fputc('g',ofile);
							//fputc('r',ofile);
							//fputc('a',ofile);
							//fputc('d',ofile);

							printf("Looks like I have fount word student");
							i=i+7;
						//}
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
