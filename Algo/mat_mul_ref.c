#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define MAX 5
int **matrix_multi(int **,int **,int n);
int **sub(int **a,int **b,int n);
int **add(int **a,int **b,int n); 
int **res;
int t1,t2,t3,t4,t5,t6,t7;
int **a,**b;
int main()
{
int i,j;
int k,l,m,n;

printf("enter n value \n");
scanf("%d",&n);
//int a[MAX][MAX],b[MAX][MAX];

/*int new_m,new_n,new_k,new_l;

printf("enter index values  for first matrix \n");
scanf("%d%d",&m,&n);

printf("enter index values for second matrix \n");
scanf("%d%d",&k,&l);



if(n>m){
		new_n=1;
		while(n>new_n)
		new_n=2*new_n;
		new_m=new_n;
	}else {
		new_m=1;
		while(m>new_m)
		new_m=2*new_m;
		new_n=new_m;
		}
	if(k>l){
		new_k=1;
		while(k>new_k)
		new_k=new_k*2;
		new_l=new_k;
	}else{
		new_l=1;
		while(l>new_l)
		new_l=new_l*2;
		new_k=new_l;
		}

*/

a=(int **)malloc(sizeof(int *)*n);
b=(int **)malloc(sizeof(int *)*n);

for(i=0;i<n;i++)
{
a[i]=(int *)malloc(sizeof(int )*n);
b[i]=(int *)malloc(sizeof(int )*n);
}

printf("enter values into array\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
printf("enter second matrix \n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&b[i][j]);


res=matrix_multi(a,b,n-1);

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%5d",res[i][j]);
}
printf("\n");
}
return 0;
}

int ** matrix_multi(int **a,int **b,int n)
{

int i,j,k,l;
int **temp;

if(n<=1)
{
printf("last case iteration \n");
temp=(int **)malloc(sizeof(int *)*(n+1));
for(i=0;i<=n;i++)
temp[i]=(int *)malloc(sizeof(int)*(n+1));




t1=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);

t2=(a[1][0]+a[1][1])*(b[0][0]);

t3=(a[0][0])*(b[0][1]-b[1][1]);

t4=(a[1][1])*(b[1][0]-b[0][0]);

t5=(a[0][0]+a[0][1])*(b[1][1]);

t6=(a[1][0]-a[0][0])*(b[0][0]+b[0][1]);

t7=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
temp[0][0]=t1+t4-t5+t7;
temp[0][1]=t3+t5;
temp[1][0]=t2+t4;
temp[1][1]=t1+t3-t2+t6;

return (int **)temp;
}


int **A,**B,**C,**D,**E,**F,**G,**H;
int **p,**q,**r,**s,**t,**u,**v;
int **R1,**R2,**R3,**R4;
int **result;


A=(int **)malloc(sizeof(int *)*((n/2)+1)); //A11
B=(int **)malloc(sizeof(int *)*((n/2)+1));//A12
C=(int **)malloc(sizeof(int *)*((n/2)+1));//A21
D=(int **)malloc(sizeof(int *)*((n/2)+1));//A22

E=(int **)malloc(sizeof(int *)*((n/2)+1));//B11
F=(int **)malloc(sizeof(int *)*((n/2)+1));//B12
G=(int **)malloc(sizeof(int *)*((n/2)+1));//B21
H=(int **)malloc(sizeof(int *)*((n/2)+1));//B22


result=(int **)malloc(sizeof(int *)*(n+1));

for(i=0;i<=n/2;i++)
{
A[i]=(int *)malloc(sizeof(int)*((n/2)+1));
B[i]=(int *)malloc(sizeof(int)*((n/2)+1));
C[i]=(int *)malloc(sizeof(int)*((n/2)+1));
D[i]=(int *)malloc(sizeof(int)*((n/2)+1));

E[i]=(int *)malloc(sizeof(int)*((n/2)+1));
F[i]=(int *)malloc(sizeof(int)*((n/2)+1));
G[i]=(int *)malloc(sizeof(int)*((n/2)+1));
H[i]=(int *)malloc(sizeof(int)*((n/2)+1));



}

for(i=0;i<=n;i++)
result[i]=(int *)malloc(sizeof(int)*(n+1));


for(i=0,k=0;i<(n/2)+1;i++,k++)
{
for(j=0,l=0;j<(n/2)+1;j++,l++)
{
A[i][j]=a[i][j];
E[i][j]=b[i][j];
}
}



for(i=0,k=0;i<=n/2;i++,k++)
{
printf("for ::::\n");
for(j=n/2+1,l=0;j<=n;j++,l++)
{
B[k][l]=a[i][j];
F[k][l]=b[i][j];
}
}


for(i=n/2+1,k=0;i<=n;i++,k++)
{
for(j=0,l=0;j<=n/2;j++,l++)
{
C[k][l]=a[i][j];
G[k][l]=b[i][j];
}
}

for(i=n/2+1,k=0;i<=n;i++,k++)
{
for(j=n/2+1,l=0;j<=n;j++,l++)
{
D[k][l]=a[i][j];
H[k][l]=b[i][j];
}
}

//A11 A  B11 E
//A12 B  B12 F
//A21 C	 B21 G
//A22 D	 B22 H
p=matrix_multi(add(A,D,n/2),add(E,H,n/2),n/2);

q=matrix_multi(add(C,D,n/2),E,n/2);

r=matrix_multi(A,sub(F,H,n/2),n/2);

s=matrix_multi(D,sub(G,E,n/2),n/2);

t=matrix_multi(add(A,B,n/2),H,n/2);

u=matrix_multi(sub(C,A,n/2),add(E,F,n/2),n/2);

v=matrix_multi(sub(B,D,n/2),add(G,H,n/2),n/2);

R1=sub(add(p,s,n/2),sub(t,v,n/2),n/2);

R2=add(r,t,n/2);

R3=add(q,s,n/2);

R4=sub(add(p,r,n/2),sub(q,u,n/2),n/2);

for(i=0;i<=n/2;i++)
for(j=0;j<=n/2;j++)
{
result[i][j]=R1[i][j];
}


printf("caliculating final result  :1\n");
for(i=0,k=0;i<=n/2;i++,k++)
for(l=0,j=n/2+1;j<=n;j++,l++)
result[i][j]=R2[k][l];

printf("caliculating final result :2\n");
for(i=(n/2)+1,k=0;i<=n;i++,k++)
for(j=0,l=0;j<=n/2;j++,l++)
result[i][j]=R3[k][l];
printf("caliculating final result :3\n");

for(i=n/2+1,k=0;i<=n;i++,k++)
for(j=n/2+1,l=0;j<=n;j++,l++)
result[i][j]=R4[k][l];

printf("caliculating final result :4\n");

for(i=0;i<=n/2;i++)
{
for(j=0;j<=n/2;j++)
{
printf("%5d %5d %5d %5d",R1[i][j],R2[i][j],R3[i][j],R4[i][j]);

}
printf("\n");
}
return result;
}


int **add (int **a,int **b,int n)
{
int i,j;
int **c;
c=(int **)malloc(sizeof(int *)*n);
for(i=0;i<=n;i++)
c[i]=(int *)malloc(sizeof(int)*n);


for(i=0;i<=n;i++)
for(j=0;j<=n;j++)
c[i][j]=a[i][j]+b[i][j];

return c;

}


int **sub(int **a,int **b,int n)
{

int i,j;
int **c;
c=(int **)malloc(sizeof(int *)*n);
for(i=0;i<=n;i++)
c[i]=(int *)malloc(sizeof(int)*n);


for(i=0;i<=n;i++)
for(j=0;j<=n;j++)
c[i][j]=a[i][j]-b[i][j];

return c;

}



