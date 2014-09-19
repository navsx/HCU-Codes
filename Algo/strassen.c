/*
Thank you Shrinivas,your malloc,add and sub functions really came handy.

Strassen’s algorithm is based on the following observation:
C11 =P5 + P4 − P2 + P6 
C12 =P1 + P2
C21 =P3 + P4 
C22 =P1 + P5 − P3 − P7

where

P1 = A11 (B12 − B22)
P2 = (A11 + A12 )B22
P3 = (A21 + A22 )B11
P4 = A22 (B21 − B11)
P5 = (A11 + A22)(B11 + B22)
P6 = (A12 − A22)(B21 + B22)
P7 = (A11 − A21)(B11 + B12)

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define asize 128

int **multi(int **,int **,int );
int **add(int **,int **,int );
int **sub(int **,int **,int );

int main()
{
	int **A,**B,**C;
	int n=asize,i,j;

	A=(int **)malloc(sizeof(int *)*asize);
	B=(int **)malloc(sizeof(int *)*asize);
	C=(int **)malloc(sizeof(int *)*asize);

	for(i=0;i<n;i++)
	{
		A[i]=(int *)malloc(sizeof(int )*asize);
		B[i]=(int *)malloc(sizeof(int )*asize);
		C[i]=(int *)malloc(sizeof(int )*asize);
	}

	printf("\nA is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			srand(13);
			printf("%d ",A[i][j]=(rand()%3)+1);
		}
	}
	printf("\nB is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			srand(31);
			printf("%d ",B[i][j]=(rand()%3));
		}
	}

	C=multi(A,B,n);
	printf("\nC is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",C[i][j]);
		}
	}
	printf("\n\n");

	return 0;
}


int ** multi(int **A,int **B,int n)
{
	int **A11,**A12,**A21,**A22,**B11,**B12,**B21,**B22;
	int **x1,**x2,**x3,**x4,**x5,**x6,**x7,**x8;
	int **c11,**c12,**c21,**c22;
	int **temp;
	int i=0,j=0,k=0,l=0;

	temp=(int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
	{
		temp[i]=(int *)malloc(sizeof(int)*n);
	}


	if(n==1)
	{
		printf("\nInside Chunnu matrix\n");
		temp[0][0]=A[0][0]*B[0][0];
		return temp;
	}

	printf("\nInside big matrix\n With N='%d' \n",n);
	A11=(int **)malloc(sizeof(int *)*(n/2));
	A12=(int **)malloc(sizeof(int *)*(n/2));
	A21=(int **)malloc(sizeof(int *)*(n/2));
	A22=(int **)malloc(sizeof(int *)*(n/2));
	B11=(int **)malloc(sizeof(int *)*(n/2));
	B12=(int **)malloc(sizeof(int *)*(n/2));
	B21=(int **)malloc(sizeof(int *)*(n/2));
	B22=(int **)malloc(sizeof(int *)*(n/2));

	for(i=0;i<n/2;i++)
	{
		A11[i]=(int *)malloc(sizeof(int)*(n/2));
		A12[i]=(int *)malloc(sizeof(int)*(n/2));
		A21[i]=(int *)malloc(sizeof(int)*(n/2));
		A22[i]=(int *)malloc(sizeof(int)*(n/2));

		B11[i]=(int *)malloc(sizeof(int)*(n/2));
		B12[i]=(int *)malloc(sizeof(int)*(n/2));
		B21[i]=(int *)malloc(sizeof(int)*(n/2));
		B22[i]=(int *)malloc(sizeof(int)*(n/2));
	}

	printf("\nA11 is\n");
	for(i=0;i<n/2;i++)
	{
		for(j=0;j<n/2;j++)
		{
			A11[i][j]=A[i][j];
			printf("%d ",A11[i][j]);
		}
	}

	printf("\nA21 is\n");
	for(k=0,i=(n/2);i<n,k<(n/2);i++,k++)
	{
		for(j=0;j<n/2;j++)
		{
			A21[k][j]=A[i][j];
			printf("%d ",A21[k][j]);
		}
	}

	printf("\nA12 is\n");
	for(i=0;i<n/2;i++)
	{
		for(l=0,j=(n/2);j<(n/2),l<(n/2);j++,l++)
		{
			A12[i][l]=A[i][j];
			printf("%d ",A12[i][l]);
		}
	}

	printf("\nA22 is\n");
	for(k=0,i=(n/2);i<n,k<(n/2);i++,k++)
	{
		for(l=0,j=(n/2);l<(n/2),j<n;j++,l++)
		{
			A22[k][l]=A[i][j];
			printf("%d ",A22[k][l]);
		}
	}

	printf("B11 is\n");
	for(i=0;i<n/2;i++)
	{
		for(j=0;j<n/2;j++)
		{
			B11[i][j]=B[i][j];
			printf("%d ",B11[i][j]);				
		}
	}
	printf("\nB21 is\n");
	for(k=0,i=(n/2);i<n,k<(n/2);i++,k++)
	{
		for(j=0;j<n/2;j++)
		{
			B21[k][j]=B[i][j];
			printf("%d ",B21[k][j]);
		}
	}
	printf("\nB12 is\n");
	for(i=0;i<n/2;i++)
	{
		for(l=0,j=(n/2);j<(n/2),l<(n/2);j++,l++)
		{
			B12[i][l]=B[i][j];
			printf("%d ",B12[i][l]);				
		}
	}

	printf("\nB22 is\n");
	for(k=0,i=(n/2);i<n,k<(n/2);i++,k++)
	{
		for(l=0,j=(n/2);l<(n/2),j<n;j++,l++)
		{
			B22[k][l]=B[i][j];
			printf("%d ",B22[k][l]);
		}
	}

	x1=multi(A11,sub(B12,B22,n/2),n/2); //A11*(B12 − B22)
	x2=multi(B22,add(A11,A12,n/2),n/2); //(A11 + A12)*B22
	x3=multi(B11,add(A21,A22,n/2),n/2); //(A21 + A22)*B11
	x4=multi(A22,sub(B21,B11,n/2),n/2); //A22*(B21 − B11)

	x5=multi(add(A11,A22,n/2),add(B11,B22,n/2),n/2); //(A11 + A22 )*(B11 + B22)
	x6=multi(sub(A12,A22,n/2),add(B21,B22,n/2),n/2); //(A12 − A22)*(B21 + B22)
	x7=multi(sub(A11,A21,n/2),add(B11,B12,n/2),n/2); //(A11 − A21)*(B11 + B12)

	c11=(int **)malloc(sizeof(int *)*n/2);
	c12=(int **)malloc(sizeof(int *)*n/2);
	c21=(int **)malloc(sizeof(int *)*n/2);
	c22=(int **)malloc(sizeof(int *)*n/2);

	for(i=0;i<(n/2);i++)
	{
		c11[i]=(int *)malloc(sizeof(int)*n/2);
		c12[i]=(int *)malloc(sizeof(int)*n/2);
		c21[i]=(int *)malloc(sizeof(int)*n/2);
		c22[i]=(int *)malloc(sizeof(int)*n/2);
	}

	c11=add(add(x5,sub(x4,x2,n/2),n/2),x6,n/2); //P5 + P4 − P2 + P6 
	c12=add(x1,x2,n/2); 			    //P1 + P2
	c21=add(x3,x4,n/2); 			    //P3 + P4
	c22=add(x1,sub(x5,add(x3,x7,n/2),n/2),n/2); //P1 + P5 − P3 − P7

	/*		temp=(int **)malloc(sizeof(int *)*n);
			for(i=0;i<n;i++)
			{
			temp[i]=(int *)malloc(sizeof(int)*n);
			}

	 */
	for(i=0;i<n/2;i++)
	{
		for(j=0;j<n/2;j++)
		{
			temp[i][j]=c11[i][j];
		}
	}

	for(i=0;i<n/2;i++)
	{
		for(l=0,j=n/2;j<n,l<(n/2);j++,l++)
		{
			temp[i][j]=c12[i][l];
		}
	}

	for(k=0,i=n/2;i<n,k<(n/2);i++,k++)
	{
		for(j=0;j<n/2;j++)
		{
			temp[i][j]=c21[k][j];
		}
	}

	for(k=0,i=n/2;i<n,k<(n/2);i++,k++)
	{
		for(l=0,j=n/2;j<n,l<(n/2);j++,l++)
		{
			temp[i][j]=c22[k][l];
		}
	}

	return temp;

	//c11=x1+x2;
	//c12=x3+x4;
	//c21=x5+x6;
	//c22=x7+x8;

}

int **add(int **a,int **b,int n)
{
	int i,j;
	int **temp2;

	temp2=(int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
	{
		temp2[i]=(int *)malloc(sizeof(int)*n);
	}



	printf("temp2 is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			temp2[i][j]=a[i][j]+b[i][j];
			printf("%d ",temp2[i][j]);
		}
	}
	return temp2;
}


int **sub(int **a,int **b,int n)
{

	int i,j;
	int **temp3;

	temp3=(int **)malloc(sizeof(int *)*n);
	
	printf("temp3 is\n");
	for(i=0;i<n;i++)
	{
		temp3[i]=(int *)malloc(sizeof(int)*n);
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			temp3[i][j]=a[i][j]-b[i][j];
			printf("%d ",temp3[i][j]);
		}
	}
	return temp3;

}

/*
   void array_function(int m, int n, float a[m][n])
   {
   for (int i = 0; i < m; i++)
   for (int j = 0; j < n; j++)
   a[i][j] = 0.0;
   }


   void another_function(void)
   {
   float a1[10][20];
   float a2[15][15];
   array_function(10, 20, a1);
   array_function(15, 15, a2);
   }

 */
