#include<stdio.h>
#include<stdlib.h>

#define asize 4

int **multi(int **,int **,int );
int **A,**B,**C;
int **add(int **,int **,int );

int main()
{
	n=asize;
	A=(int **)malloc(sizeof(int *)*asize);
	B=(int **)malloc(sizeof(int *)*asize);
	C=(int **)malloc(sizeof(int *)*asize);

	for(i=0;i<n;i++)
	{
		A[i]=(int *)malloc(sizeof(int )*asize);
		B[i]=(int *)malloc(sizeof(int )*asize);
		C[i]=(int *)malloc(sizeof(int )*asize);
	}

	A[][asize]={1,2,3,2,1,2,3,2,2,1,2,1,2,4,2,3};
	B[][asize]={1,2,3,2,1,2,3,2,2,1,2,1,2,4,2,3};

	C=multi(A,B,n);
		printf("C is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",C[i][j]);
		}
	}

return 0;
}


int ** multi(int **A,int **B,int n)
{
	int **A11,**A12,**A21,**A22,**B11,**B12,**B21,**B22;
	int **x1,**x2,**x3,**x4,**x5,**x6,**x7,**x8;
	int **C11,**C12,**C21,**C22;
	int **temp;
	
	while(n>1)
	{

	A11=(int **)malloc(sizeof(int *)*(n/2));
	A12=(int **)malloc(sizeof(int *)*(n/2));
	A21=(int **)malloc(sizeof(int *)*(n/2));
	A22=(int **)malloc(sizeof(int *)*(n/2));
	B11=(int **)malloc(sizeof(int *)*(n/2));
	B12=(int **)malloc(sizeof(int *)*(n/2));
	B21=(int **)malloc(sizeof(int *)*(n/2));
	B22=(int **)malloc(sizeof(int *)*(n/2));

	for(i=0;i<=n/2;i++)
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

	

	A11[n/2][n/2]={0};
	A12[n/2][n/2]={0};
	A21[n/2][n/2]={0};
	A22[n/2][n/2]={0};
	
	B11[n/2][n/2]={0};
	B12[n/2][n/2]={0};
	B21[n/2][n/2]={0};
	B22[n/2][n/2]={0};
	
	printf("A11 is\n");
	for(int i=0;i<n/2;i++)
	{
	for(int j=0;j<n/2;i++)
	{
		A11[i][j]=A[i][j];
		printf("%d ",A11[i][j]);
	}
	}
	
	for(int i=(n/2);i<n;i++)
	{
	for(int j=0;j<n/2;i++)
	{
		A21[i][j]=A[i][j];
	}
	}
	
	for(int i=0;i<n/2;i++)
	{
	for(int j=(n/2);j<n/2;i++)
	{
		A12[i][j]=A[i][j];
	}
	}
	
	for(int i=(n/2);i<n;i++)
	{
	for(int j=(n/2);j<n;i++)
	{
		A22[i][j]=A[i][j];
	}
	}
	
	for(int i=0;i<n/2;i++)
	{
	for(int j=0;j<n/2;i++)
	{
		B11[i][j]=B[i][j];
	}
	}
	
	for(int i=(n/2);i<n;i++)
	{
	for(int j=0;j<n/2;i++)
	{
		B21[i][j]=B[i][j];
	}
	}
	
	for(int i=(n/2);i<n;i++)
	{
	for(int j=0;j<n/2;i++)
	{
		B12[i][j]=B[i][j];
	}
	}
	
	for(int i=(n/2);i<n;i++)
	{
	for(int j=(n/2);j<n;i++)
	{
		B22[i][j]=B[i][j];
	}
	}


	x1=multi(A11,B11,n/2); //A11*B11
	x2=multi(A12,B21,n/2); //A12*B21
	x3=multi(A11,B12,n/2); //A11*B12
	x4=multi(A12,B22,n/2); //A12*B22
	x5=multi(A21,B11,n/2); //A21*B11
	x6=multi(A22,B21,n/2); //A22*B21
	x7=multi(A21,B12,n/2); //A21*B12
	x8=multi(A22,B22,n/2); //A22*B22

	c11=(int **)malloc(sizeof(int *)*n/2);
	c12=(int **)malloc(sizeof(int *)*n/2);
	c21=(int **)malloc(sizeof(int *)*n/2);
	c22=(int **)malloc(sizeof(int *)*n/2);

	for(i=0;i<n/2;i++)
	{
		c11[i]=(int *)malloc(sizeof(int)*n/2);
		c12[i]=(int *)malloc(sizeof(int)*n/2);
		c21[i]=(int *)malloc(sizeof(int)*n/2);
		c22[i]=(int *)malloc(sizeof(int)*n/2);
	}

	c11=add(x1,x2,n/2);
	c12=add(x3,x4,n/2);
	c21=add(x5,x6,n/2);
	c22=add(x7,x8,n/2);
	
	temp=(int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
	{
		temp[i]=(int *)malloc(sizeof(int)*n);
	}
	
	for(i=0;i<n/2;i++)
	{
	for(j=0;j<n/2;j++)
	{
	temp[i][j]=c11[i][j];
	}
	}
	
	for(i=0;i<n/2;i++)
	{
	for(j=n/2;j<n;j++)
	{
	temp[i][j]=c12[i][j];
	}
	}

	for(i=n/2;i<n;i++)
	{
	for(j=0;j<n/2;j++)
	{
	temp[i][j]=c21[i][j];
	}
	}

	for(i=n/2;i<n;i++)
	{
	for(j=n/2;j<n;j++)
	{
	temp[i][j]=c22[i][j];
	}
	}

	return temp;

}

	if(n==1)
	{
		return A[i][j]*B[i][j];
	}
	
//c11=x1+x2;
//c12=x3+x4;
//c21=x5+x6;
//c22=x7+x8;
						
}

int **add(int **a,int **b,int n);
{
	int i,j;
	int **temp2;
	temp2=(int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
	{
		temp2=(int *)malloc(sizeof(int)*n);
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
