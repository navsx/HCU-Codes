#include <stdio.h>
#include <stdlib.h>

typedef struct tnode  //Tree Node with node ID,parent ID,number of nodes and parent address
{
	int nodeId;
	int pID;
	int numOfNodes;
	struct tnode *pAddress;
}tn;

int findR(tn**,int );
void unionT(tn**,tn**,int ,int );

main()
{
	//printf("Just after main\n");
	int i,j;
	int cell[9]={1,2,3,4,5,6,7,8,9}; //A set of cells
	printf("Cells are \n");
	for(i=0;i<9;i++)
	{
		printf("%d ",cell[i]);
	}
	int edge[12]={14,23,45,56,78,89,69,25,36,47,58,12}; //A set of Edges
	printf("\n Edges are : \n");
	for(j=0;j<12;j++)
	{
		printf("%d ",edge[j]);
	}
	//printf("Empty Maze \n");
	int maze[70]={0}; //A maze set currently empty
/*	for(i=0;i<70;i++)
	{
		printf("%d:%d ",maze[i],i);
	}
*/	
	printf("\n");
	
	int countOfCell=9;
	int randomNum=0,edgePicker,edge1,edge2,U,V;

	tn **node=malloc(10*sizeof(tn *));
	
	tn *temp;
	temp=NULL;

	for(i=0;i<10;i++)
	{
		
		node[i]=malloc(sizeof(tn));
		(node[i])->nodeId=i;
		(node[i])->pID=0;
		(node[i])->numOfNodes=1;
		(node[i])->pAddress=NULL;
		printf("node id=%d  pid=%d  nodes=%d \n",(node[i])->nodeId,(node[i])->pID,(node[i])->numOfNodes);
	}	
	//printfi("\nJust before while\n");

	while(countOfCell>1)   //Loop until set is empty
	{
		//randomNum=rand()%11;

		edgePicker=edge[randomNum];
		printf("Edge %d ->corresponding to random no %d is\n",edgePicker,randomNum);
		if(edge[randomNum]!=0)
		{
			edge[randomNum]=0;
			printf("EdgePicker is= %d\n",edgePicker);
			edge1=edgePicker%10;
			edge2=edgePicker/10;
			U=findR(&node[edge1],edge1);
			printf("U val for %d is=%d \n",edge1,U);
			V=findR(&node[edge2],edge2);
			printf("V val for %d is=%d \n",edge2,V);
			if(U!=V)
			{
				unionT(&node[U],&node[V],U,V);
				countOfCell--;
			}
			else
			{
				maze[edgePicker]=edgePicker;
			}
		}
		else
		{
			printf("Edge already taken \n");
		}
		randomNum++;
	}
	printf("\n Edges are :\n");

	for(i=0;i<12;i++)
	{
		if(edge[i]!=0)
		{
			printf("\t%d",edge[i]);
		}
	}

	printf("\n Maze set are :\n");

	for(i=0;i<70;i++)
	{
		if(maze[i]!=0)
		{
			printf("\t%d",maze[i]);
		}
	}
}

int findR(tn **node,int edgeP)
{
	int j;
	j=edgeP;
	printf("Finding root of %d with NID=%d and PID=%d \n",j,(*(node[j])).nodeId,(*(node[j])).pID);
	while(((*(node[j])).pID)>0)
	{
		j=(*node[j]).pID;
	}
	return j;
}

void unionT(tn **node,tn **node1,int u,int v)
{
	int x;
	x=(*node[u]).numOfNodes+(*node1[v]).numOfNodes;
	printf("x val for u:%d and v:%d is= %d \n",u,v,x);
	if((*node[u]).numOfNodes > (*node1[v]).numOfNodes)
	{
		(*node1[v]).pID=u;
		printf("PID of node %d is %d\n",v,u);
		(*node1[v]).pAddress=node[u];
		(*node[u]).numOfNodes=x;
	}
	else
	{
		(*node[u]).pID=v;
		printf("PID of node %d is %d\n",u,v);
		(*node[u]).pAddress=node1[v];
		(*node1[v]).numOfNodes=x;		
	}
}


/*

omaze: malloc.c:2451: sYSMALLOc: Assertion `(old_top == (((mbinptr) (((char *) &((av)->bins[((1) - 1) * 2])) - __builtin_offsetof (struct malloc_chunk, fd)))) && old_size == 0) || ((unsigned long) (old_size) >= (unsigned long)((((__builtin_offsetof (struct malloc_chunk, fd_nextsize))+((2 * (sizeof(size_t))) - 1)) & ~((2 * (sizeof(size_t))) - 1))) && ((old_top)->size & 0x1) && ((unsigned long)old_end & pagemask) == 0)' failed.
Aborted (core dumped)


*/

