#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 1024

void islo(char str[])
{
    int i;
    int len = strlen(str);

    for(i = 0; i <= len; i++)
    {
        if(islower(str[i]) != 0)
            str[i] = toupper(str[i]);
    }
    return ;
}

int sa(char s1[], char s2[])
{
    int i,j;
    int len = strlen(s1);
    int cur = 0;
    int c = 0;
    int len2 = 0;

    for(i = 0; i < len; i++)
    {
        for(j = 0; j < len; j++)
        {
            if(s1[i] == s1[j])
            len2++;
        }
    }

    for(i = 0; i < len; i++)
    {
        for(j = 0; j < len; j++)
        {
            if(s1[i] == s2[j])
            cur++;
        }
    }
    printf("correct : %d len : %d", cur, len2);
    if(cur == len2)
    c = 1;

    return c;
}

int main()
{
    char tar[max];
    int n;
    int c;
    char set[max];
    char set2[max];

    scanf("%s", tar);
    scanf("%d", &n);
    islo(tar);

    while(n!=0)
    {
        scanf("%s", set);
        strcpy(set2,set);
        islo(set);
        c = sa(tar,set);
        if(c == 1) printf("%s\n", set2);
        n--;
    }


    return 0;
}
