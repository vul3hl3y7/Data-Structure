#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ispri(int n)
{
    int b = 0 ;
    int i;
    bool isPrime = true;

  for(i = 2; i <= n / 2; ++i)
  {
      if(n % i == 0)
      {
          isPrime = false;
          break;
      }
  }
    if (isPrime)
        b = 1;

    return b;
}

int main()
{
  int n, i;
    int result;
  int b = 0;

 // printf( "Enter a positive integer: ");
    while(n != 0)
    {
    result = 0;
    scanf("%d", &n);

  for(i = 2; i < n; i++)
  {
    b = ispri(i);
    if(b == 1)
    result++;

    }
    if(n !=0)
    {
    printf("%d", result);
    printf("\n");
    }
}
  return 0;
}
