#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAXNITEMS 96969696	

int nitems;
int arrT[3];
int arrC[8];

struct {
	sem_t muG, muC,comn;
	//int tBuff[MAXNITEMS];
	int tBuff;
	//int cBuff[MAXNITEMS];
	int cBuff;
} common;

void *Gen(void *);
void *Cont(void *);

int main (int argc, char *argv[])
{
	int i, countG[3],countC[8];
	pthread_t tid_gen[3], tid_cont[8];

	if (argc != 2) 
	{
		fprintf(stderr, "Usage: mutexes #items #threads\n");
		exit(1);
	}

	if ((nitems = atoi (argv[1])) > MAXNITEMS)
		nitems = MAXNITEMS;

	sem_init (&common.muC, 0, 1);
	sem_init (&common.muG, 0, 1);
	sem_init (&common.comn, 0, 0);

	for (i=0; i<3; i++) 
	{
		arrT[i] = 0;
		pthread_create(&tid_gen[i], NULL, Gen, &arrT[i]);
	}

	for (i=0; i<8; i++) 
	{
		arrC[i] = 0;
		pthread_create(&tid_cont[i], NULL, Cont, &arrC[i]);
	}

	for (i=0; i<3; i++) 
	{
		pthread_join(tid_gen[i], NULL);
		printf("Token[%d] = %d\n", i, arrT[i]);
	}

	for (i=0; i<8; i++) 
	{
		pthread_join(tid_cont[i], NULL);
		printf("Counter[%d] = %d\n", i, arrC[i]);
	}

	sem_destroy (&common.muG);
	sem_destroy (&common.muC);
	sem_destroy (&common.comn);
	exit(0);
}

void *Gen(void *argpro)
{
	for ( ; ; ) 
	{
		sem_wait (&common.muG);
		if (common.tBuff >= nitems) 
		{
			sem_post(&common.muG);
			sem_post(&common.comn);
			return (NULL);
		}

		printf("Token no. %d generated @ %u\n",common.tBuff, (unsigned int)pthread_self());
		(common.tBuff)++;

		sem_post(&common.muG); 
		sem_post(&common.comn);
		*((int *) argpro) += 1;
	}
}

void *Cont(void *argcon)
{
	int i;
	//printf("\n\nin consume\n\n");
	for (i=0; i<nitems; i++) 
	{
		sem_wait(&common.comn);
		sem_wait (&common.muC);

		if (common.cBuff > common.tBuff)
		{
			sem_post(&common.muC);
			sem_post(&common.comn);
			return (NULL);
		}
		else
		{
			printf("Token no. %d consumed @ %u\n",common.cBuff, (unsigned int)pthread_self());
			(common.cBuff)++;
			sem_post(&common.muC);
			sem_post(&common.comn);
		}

		*((int *) argcon) += 1;		
	}

}
