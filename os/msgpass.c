#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//I am passing "./<filename> sleep <some value>" as runtime argument
                       // Ex. ./msgpass sleep 3

int main(int argc,char *argv[])
{
	int sum =0,i,slen,pid,stid;
	time_t t1,t2;
	float c1,c2;
	FILE *ifile,*ofile;

	for(i=1; i<argc; i++) 
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
		c2 = difftime(t2,t1);
		
		printf("Time taken to execute %s is = %f\n",s,c2);

		f1=fopen("file.txt","w");
		if(f1==0)
		{
			printf("File can't be opened/n");
			exit(1);
		}
		else
		{
			fprintf(f1,"%f",c2);
			fclose(f1);

			printf("Ending time was: %.1f\n",c2);
		}
	}
	else
	{	waitpid(pid,&stid,0);
		printf("Parent\n");	
		c1 = difftime(t1,0); 
	//	printf("starting time was: %f\n",c1);
		//printf("\n");

		f2=fopen("file.txt","r");
		if(f2==0)
		{
			printf("File can't be opened/n");
			exit(1);
		}
		else
		{
			fscanf(f2,"%f",&c2);
			fclose(f2);
			printf("Child took %f seconds,Happy!\n",c2);
		}
	}

	return 0;
}

