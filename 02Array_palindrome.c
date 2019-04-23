#include <stdio.h>
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

// A function to check if a string str is palindrome
void isPalindrome(char str[])
{

    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = strlen(str) - 1;

    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
      //      printf("%s is Not Palindromen", str);
            printf("F");
            return;
        }
    }
 //   printf("%s is palindromen", str);
    printf("T");
}

// Driver program to test above function
int main()
{
    int n;
    char line[max];
//    char test[] = "Abba";
 //   islo(test);
    scanf("%d", &n);

    while(n !=0)
    {
        scanf("%s", line);
    islo(line);
        isPalindrome(line);
        n--;
        printf("\n");
    }

 //   isPalindrome(test);

 //   isPalindrome("abbccbba");
//    isPalindrome("geeks");
    return 0;
}
