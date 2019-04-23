# include <stdio.h>
# include <stdlib.h>
# include <conio.h>

int n,a[10][10],p[10][10];

void path()
{
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            p[i][j]=a[i][j];

    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(p[i][k]==1 && p[k][j]==1)
                p[i][j]=1;

}
int main()
{
int i,j;
printf("Enter the number of nodes:");
while(scanf("%d",&n) != EOF)
{
printf("\nEnter the adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    path();
printf("\nThe path matrix is shown below\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",p[i][j]);
        printf("\n");
    }
    printf("Enter the number of nodes:");
}
return 0;
}
