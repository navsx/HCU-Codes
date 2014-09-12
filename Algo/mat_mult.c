#include<stdio.h>
#include<stdlib.h>

int main()
{
	int A[4][4]={1,2,3,2,1,2,3,2,2,1,2,1,2,4,2,3};
	int B[4][4]={1,2,3,2,1,2,3,2,2,1,2,1,2,4,2,3};
	int c[4][4];
}

//int multi(int A[][n],int B[][n],int C[][n],int ialow,int jalow,int iahigh,int jahigh,int iblow,int jblow,int ibhigh,int jbhigh,int n)
int multi(int A[][n],int B[][n],int n)
{
	while(n!=1)
	{
	int A11[n/2][n/2]={0};
	int A12[n/2][n/2]={0};
	int A21[n/2][n/2]={0};
	int A22[n/2][n/2]={0};
	
	int B11[n/2][n/2]={0};
	int B12[n/2][n/2]={0};
	int B21[n/2][n/2]={0};
	int B22[n/2][n/2]={0};
	
	for(int i=0;i<=n/2;i++)
	{
	for(int j=0;j<=n/2;i++)
	{
		A11[i][j]=A[i][j];
	}
	}
	
	for(int i=(n/2)+1;i<=n;i++)
	{
	for(int j=0;j<=n/2;i++)
	{
		A21[i][j]=A[i][j];
	}
	}
	
	for(int i=0;i<=n/2;i++)
	{
	for(int j=(n/2)+1;j<=n/2;i++)
	{
		A12[i][j]=A[i][j];
	}
	}
	
	for(int i=(n/2)+1;i<=n;i++)
	{
	for(int j=(n/2)+1;j<=n;i++)
	{
		A22[i][j]=A[i][j];
	}
	}
	
	for(int i=0;i<=n/2;i++)
	{
	for(int j=0;j<=n/2;i++)
	{
		B11[i][j]=B[i][j];
	}
	}
	
	for(int i=(n/2)+1;i<=n;i++)
	{
	for(int j=0;j<=n/2;i++)
	{
		B21[i][j]=B[i][j];
	}
	}
	
	for(int i=(n/2)+1;i<=n;i++)
	{
	for(int j=0;j<=n/2;i++)
	{
		B12[i][j]=B[i][j];
	}
	}
	
	for(int i=(n/2)+1;i<=n;i++)
	{
	for(int j=(n/2)+1;j<=n;i++)
	{
		B22[i][j]=B[i][j];
	}
	}
/*x1=multi(A,B,0,0,n/2,n/2,0,0,n/2,n/2,n/2); //A11*B11
x2=multi(A,B,0,(n/2)+1,n/2,n,(n/2)+1,0,n,n/2,n/2); //A12*B21
x3=multi(A,B,0,0,n/2,n/2,0,n/2,n/2,n,n/2); //A11*B12
x4=multi(A,B,0,n/2,n/2,n,n/2,n/2,n,n,n/2); //A12*B22
x5=multi(A,B,n/2,0,n,n/2,0,0,n/2,n/2,n/2); //A21*B11
x6=multi(A,B,n/2,n/2,n,n,n/2,0,n,n/2,n/2); //A22*B21
x7=multi(A,B,n/2,0,n,n/2,0,n/2,n/2,n,n/2); //A21*B12
x8=multi(A,B,n/2,n/2,n,n,n/2,n,n/2,n,n/2); //A22*B22 */

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
