#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{

	int d1,d2;
	FILE *ifile,*ofile;
	
		ifile=fopen(argv[1],"r");
		if(ifile==0)
		{
			printf("agian in parent:File can't be opened/n");
			exit(1);
		}
		else
		{
			while(fgets(s,100,ifile)!=0)
                       {
                        fscanf(ifile,"%d,%d",&d1,&d2);
                       }
				fclose(ifile);
		}

	return 0;
}
