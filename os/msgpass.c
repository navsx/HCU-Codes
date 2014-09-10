#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//I am passing "./<filename> sleep <some value> <output file name>" as runtime argument
                       // Ex. ./msgpass sleep 3 sharefile.txt

int main(int argc,char *argv[])
{
	int sum =0,i,slen,pid,stid;
	time_t t1,t2;
	float f,f1;
	FILE *ifile,*ofile;
	
		ofile=fopen(argv[3],"w");
		if(ofile==0)
		{
			printf("in parent: File can't be opened/n");
			//exit(1);
		}
		else
		{
			printf("in parent: init file with 1.0 for testing /n");
			fprintf(ofile,"%f",1.0);
			fclose(ofile);
		}

	for(i=1; i<argc-1; i++) 
	{
		slen = strlen(argv[i]);
		sum+=slen;
	}

	char* s = malloc(sizeof(char) * (sum + 2));
	strcpy(s,argv[1]);
	strcat(s," ");
	strcat(s,argv[2]);


	time(&t1);

	if ((pid = fork()) == 0) 
	{
		printf("Child will execute- %s\n",s);
		system(s);
		time(&t2);
		f1 = difftime(t2,t1);
		
		printf("Time taken to execute %s is = %f\n",s,f1);

		ofile=fopen(argv[3],"w");
		if(ofile==0)
		{
			printf("in child:File can't be opened/n");
			exit(1);
		}
		else
		{
			fprintf(ofile,"%f",f1);
			fclose(ofile);
		}
	}
	else
	{	waitpid(pid,NULL);
		printf("Parent is executing now \n");	 

		ifile=fopen(argv[3],"r");
		if(ifile==0)
		{
			printf("agian in parent:File can't be opened/n");
			exit(1);
		}
		else
		{
			fscanf(ifile,"%f",&f);
			if(f==1.0)
			{
				printf("Child has not written a value yet\n");
				fclose(ifile);
			}
			else
			{
				printf("My Child process took %f seconds,I am so happy!\n...but it could've been less\n",f);
				fclose(ifile);
			}
		}
	}

	return 0;
}
