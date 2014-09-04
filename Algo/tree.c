#include <stdio.h>
#include <stdlib.h>

struct tnode  //Tree Node with node ID,parent ID,number of nodes and parent address
{
	int nodeId;
	int pID;
	int numOfNodes;
	struct tnode *pAddress;
};

int findR(struct tnode**,int edgeP);
void unionT(struct tnode**,struct tnode**,int u,int v);

main()
{
	int i;
	int cell[]={1,2,3,4,5,6,7,8,9}; //A set of cells
	int edge[]={12,23,45,56,78,89,14,25,36,47,58,69}; //A set of Edges
	int maze[9]; //A maze set currently empty
	for(i=0;i<70;i++)
	{
		maze[i]=0;
	}
	int countOfCell=9;
	int randomNum,edgePicker,edge1,edge2,U,V;

	struct tnode *node[9];
        for(i=0;i<9;i++)
	{
		node[i]=(struct tnode *)malloc(sizeof(struct tnode *));
		node[i]->nodeId=i+1;
		node[i]->pID=0;
		node[i]->numOfNodes=1;
		node[i]->pAddress=NULL;
	}	

	while(countOfCell>1)   //Loop until set is empty
	{
		randomNum=rand()%11;
		edgePicker=edge[randomNum];
		edge[randomNum]=0;
		edge1=edgePicker%10;
		edge2=edgePicker/10;
		U=findR(&node[edge1-1],edge1-1);
		V=findR(&node[edge2-1],edge2-1);
		if(U!=V)
		{
			unionT(&node[U],&node[V],U,V);
		}
		else
		{
			maze[edgePicker-1]=edgePicker;
		}
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

int findR(struct tnode **node,int edgeP)
{
	int j;
	j=edgeP;
	while(((*(node[j])).pID)>0)
	{
		j=(*node[j]).pID;
	}
	return j;
}

void unionT(struct tnode **node,struct tnode **node1,int u,int v)
{
	int x;
	x=(*node[u]).numOfNodes+(*node1[v]).numOfNodes;
	if((*node[u]).numOfNodes > (*node1[v]).numOfNodes)
	{
		(*node1[v]).pID=u;
		(*node1[v]).pAddress=node[u];
		(*node[u]).numOfNodes=x;
	}
	else
	{
                (*node[u]).pID=v;
                (*node[u]).pAddress=node1[v];
                (*node1[v]).numOfNodes=x;		
	}
}




