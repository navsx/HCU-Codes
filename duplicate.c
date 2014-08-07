#include <stdio.h>

main()
{

	int count=0,num=0,Array[5],i=0,j=0,k=0;
	char choice;

	printf("Enter 5 numbers from 10 to 100\n\n");

	for(count=1;count<=5;)
	{
		scanf("%d",&num);

		if(num>=10 && num<=100)
		{
			printf("%d.) : %d\n",count,num);
			Array[count-1]=num;
			count++;
		}
		else
		{
			printf("\n--> Enter a number between 10 to 100\n");
		}
	}

	for(i=0;i<=4;i++)
	{
		for(j=0;j<=4;j++)
		{
			if(Array[i]==Array[j] && i!=j)
				Array[j]=Array[j]-200;
		}

	}

	if(count==6)
	{
	printf("Tell me if you want to print all numbers,including duplicates\n");
	printf("\n enter y or n \n");
	if(getchar())
	scanf("%c",&choice);
	//puts("\n");
	printf("chioce=%c\n",choice);

	if((choice=='y')  || (choice=='n'))
	{
		if(choice=='y')
		{

			for(k=0;k<=4;k++)
			{
				if(Array[k]>=10)
				{	
				printf("[%d]\n",Array[k]);
				}
			}
		}
		else
		{
			for(k=0;k<=4;k++)
			{
				if(Array[k]<10)
					printf("[%d]\n",Array[k]+200);
				else
					printf("[%d]\n",Array[k]);
			}

		}
	}
	else
	{
		printf("\nmake a choice anna y or n\n");
	}

	}

}
