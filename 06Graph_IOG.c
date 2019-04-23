#include <stdio.h>
#include <stdlib.h>

int main()
{
    int adj_mat[50][50];
    int n;

    int in_deg, out_deg, i, j;

    printf("\n How Many Vertices ? : ");

    while(scanf("%d", &n) != EOF)
{
    for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		scanf("%d",&adj_mat[i][j]);
	}

//    printf("\n Vertex \t In_Degree \t Out_Degree \t Total_Degree ");

    for (i = 1; i <= n ; i++ )
    {
        in_deg = out_deg = 0;
        for ( j = 1 ; j <= n ; j++ )
        {
            if ( adj_mat[j][i] == 1 )
                in_deg++;
        }
        for ( j = 1 ; j <= n ; j++ )
            if (adj_mat[i][j] == 1 )
                out_deg++;
            printf("%d %d %d\n",i,in_deg,out_deg);
        }
        printf("\n How Many Vertices ? : ");
}
    return 0;
}
