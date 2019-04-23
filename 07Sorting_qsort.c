#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 1024

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void quickSort(int data[], int left, int right,int n)
{
    int k,c = 0;
    int record[max];
    for(k = 0; k < n;k++)
    record[k] = data[k];

    if(left < right){
        int i = left + 1, j = right, splitting = data[left], temp;
        do{
            while(i < right && data[i] <= splitting) i++;   // Note the "<" and "<="
            while(j > left && data[j] > splitting) j--;
            if(i < j){
            temp = data[i]; data[i] = data[j]; data[j] = temp;   // Note this line, swap data[i + 1] and data[i]
        for(k = 0; k < n;k++)
        {
            if(record[k] != data[k])
            c = 1;
        }
        if(c == 1)
        {
        printArray(data,n);

            for(k = 0; k < n;k++)
            record[k] = data[k];
        }
            }
        }while(i < j);
        temp = data[j]; data[j] = data[left]; data[left] = temp;   // Note this line, swap data[j] and the data[left] (splitting)

        for(k = 0; k < n;k++)
        {
            if(record[k] != data[k])
            c = 2;
        }
        if(c == 2) printArray(data,n);

        quickSort(data,left, j - 1,n);
        quickSort(data,j + 1, right,n);
    }
}

// Driver program to test above functions
int main()
{
    int n = 0;
    char d[max];
    char *pch;

    int data[max];

    while(fgets(d,max,stdin) != NULL )
    {
        pch = strtok(d," \n");
        while(pch != NULL)
        {
            data[n] = atoi(pch);
            n++;
            pch = strtok(NULL," \n");
        }
    quickSort(data, 0, n-1, n);

    n = 0;
    }
    return 0;
}
