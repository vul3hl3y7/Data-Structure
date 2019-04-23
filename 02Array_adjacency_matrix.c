#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int a,b,u,v,n,i,j,ne;
    int visited[10]={0},min,mincost,cost[10][10];
	printf("\nEnter the number of nodes:");

	while(scanf("%d",&n) != EOF)
    {
    ne=1;
    mincost=0;

    for(i = 0;i <10;i++)
    visited[i] = 0;

    memset(cost,0,sizeof(cost));

	printf("\nEnter the adjacency matrix:\n");

	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{

		scanf("%d",&cost[i][j]);

		if(cost[i][j]==0)

			cost[i][j]=999;

	}

	visited[1]=1;

	while(ne < n)

	{

		for(i=1,min=999;i<=n;i++)

		for(j=1;j<=n;j++)

		if(cost[i][j]< min)

		if(visited[i]!=0)

		{

			min=cost[i][j];

			a=u=i;

			b=v=j;

		}

		if(visited[u]==0 || visited[v]==0)

		{

		//	printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
            printf("\n%d %d %d %d",ne++,a,b,min);
			mincost+=min;

			visited[b]=1;

		}

		cost[a][b]=cost[b][a]=999;

	}

//	printf("\n Minimun cost=%d",mincost);
    printf("\nEnter the number of nodes:");
    }
    return 0;
}
