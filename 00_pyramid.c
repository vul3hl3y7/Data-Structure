#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 1024

int pra(int n,char M[48][48])
{
        int t = 0;
        char sp[] = {" "};
        char st[] = {"* "};
        int rows, star, spaces;
        int number_of_stars = n;
        int number_of_rows = number_of_stars;
        t = number_of_rows + number_of_stars;

        for (rows=1; rows <= number_of_rows; rows++) {
                for (spaces=1; spaces <= number_of_stars; spaces++) {
                        printf(" ");
                }
                for (star=1; star <= rows; star++) {
                        printf("*");
                        printf(" ");
                }
                printf("\n");
                number_of_stars = number_of_stars - 1;
        }
    return t;
}

int main(){

       char M[48][48];

       int n;
       int t;
       int s = 0;
       printf("½Ð¿é¤J¼Æ¦r:");
       scanf("%d",&n);
        t = n;
       while(n != 0)
       {
            s += pra(n,M);
            n--;
       }
       printf("%d\n", s);

       int i,j;
       for(i = 0; n < t; n++)
       {
            for(j = 0; j < s; j++)
            {
                printf("%c", M[i][j]);
            }
            printf("\n");
       }

       return 0;
       }
