#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])  //I am passing "./<filename> sleep <some value>" as runtime argument
                                // Ex. ./msgpass sleep 3
{
	int sum =0;
	int i;
	for(i=1; i<argc; i++) 
	{
		int len = strlen(argv[i]);
		sum+=len;
	}
	
	char* buffer = malloc(sizeof(char) * (sum + 2));
	buffer[0] = 0; // The string is now seen as empty.
	strcpy(buffer,argv[1]);
	strcat(buffer," ");
	strcat(buffer,argv[2]);
        
	int pid,stid;
	time_t t1,t2;
	float c1,c2;

	time(&t1);

	if ((pid = fork()) == 0) 
	{
		printf("In child\n");
		system(buffer);
                printf("In child after sleep\n");
		time(&t2);
		//printf("end time = %ld",t2);
		c2 = difftime(t2,t1);
		printf("Ending time was: %.1f\n",c2);
	}
	else
	{	waitpid(pid,&stid,0);
		printf("Parent\n");	
		c1 = difftime(t1,0); 
		printf("starting time was: %f\n",c1);
		//printf("\n");

	}

	return 0;
}
