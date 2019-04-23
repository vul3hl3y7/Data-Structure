/*
*                                  
* Homework : Big number calculator 
*                                  
* Writer : Tasi Meng Tseng         
*                                  
* Number : 400410024               
                                  

1. Keyin 'make' to use Makefile open the program.
2. You will see menu below :

What do you want to do ?
1) Read numbers from a file
2) Show the input numbers
3) Write numbers to a file
4) Calculate the big numbers
0) Exit

1-Open the file to read
2-Show the numbers in (1)'s file, if you don't open file before will show error message.
3-Write new data after (1)'s file, if you don't open file before will show error message.

3. When you choose no.4 will see another menu below : 

============================================
=                                          =
= Which operators do you want to choose ?  =
= (+) Addition                             =
= (-) Subtraction                          =
= (*) Multiplication                       =
= (/) Division                             =
= (q) Quit                                 =
=                                          =
============================================

============================================
=                                          =
= Which items do you want to choose ?      =
= (1) Load the existing numbers by ID      =
= (2) Input two numbers to calculate       =
= (0) Quit                                 =
=                                          =
============================================

If you don't open file before, cannot use (1) in second menu.

4. All calculate resulst will output to the "result.txt".

Unit :

1. Use char array to record big number. (in line 54)
2. Use malloc integer array to change char type to calculate. (in calculate function)
   If the number has scientific notation, I try "myatoi" to make a extended big number.
3. Addition :Use carry bit and shift ( in line 202, 203)
4. Subtraction : Use borrow (in line 250, 251) and need to compare number 1 or number 2 which is bigger one.
   When number 2 is bigger, I change two number's site to subtract, and bring negative sign symbol front of answer.
5. Multuplication : According to direct calculation, calculator need a register to store result. ( in line 296) and add them to the final answer.

*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 1024

struct line{ // read file
	int id;
	char arr1[MAX];
	char arr2[MAX];
}data[MAX];
/*
struct bignum{
	int arr[MAX];
	size_t digit;
	bool flag;
	
};
*/

int len = 0;

void calculate(char c, char arr1[MAX], char arr2[MAX]);

int *myatof(char s[], int l)
{
	int *tmp;
	tmp = malloc(MAX * sizeof(int));

	int i;
	int j = 0;
	int p1 = -1; // .
	int p2; // E
	int p3; // +
	int e; // ._E

	char pow[MAX]; // E+__
	int val; 

	for(i = 0; i < l; i++)
	{
		if(s[i] == '.' && (s[i + 1] != 'E' && s[i + 1] != 'e'))
		{
			tmp[i] = s[i + 1] - '0';
			p1 = i;
		}
		else tmp[i] = s[i] - '0';
		if(s[i] == 'E' || s[i] == 'e') p2 = i;
		if(s[i] == '+') p3 = i;
	}

	if(p1 == -1) //_E
	e = s[p2 - 1] - '0';
	else
	e = s[p1 + 1] - '0';

//	printf("e : %d\n", e);

/*	printf("tmp : ");
	for(i = 0; i < p2; i++)	// dedect
	printf("%d", tmp[i]);
	printf("\np1. : %d", p1);
	printf("\np2e : %d", p2);
	printf("\np3+ : %d", p3);
*/
	for(i = p3 + 1; i < len; i++)
	{
		pow[j] = s[i];
		j++;
//	printf("pow %d : %c\n", i, pow[i]);
	}
	val = atoi(pow);
//	printf("\npow : %d\n", val);

	j = p2 - 1;
	for(i = 0; i < val - (p2 - p1); i++)
	{
		tmp[j] = e;
		j++;
	}
/*	printf("\ntmp : ");
	for(i = 0; i < val; i++)	// dedect
	printf("%d", tmp[i]);*/
	len = val;
//	printf("\nlen : %d\n", len);
	
	return tmp;
}

int main(void)
{
	int flag = 1;
	{
		while(flag)
		{
		printf("\n\nWhat do you want to do ?\n\t1) Read number from a file\n\t2) Show the input numbers\n\t3) Write numbers to a file\n\t4) Calculate the big numbers\n\t0) Exit\n\n");

	int num;
	scanf("%d", &num);

	FILE *fp; // open file
	char filename[48];
//	fp = fopen("test.csv", "r");

	char f1[48], f2[48], f3[48];
	int i;
	int m;

	switch(num)
	{
		case 1 :
		{
		printf("Please input the file name : \n");
		scanf("%s", filename);
		fp = fopen(filename, "r");
			if (fp != NULL) 
			{
				printf("%s open successful.\n", filename);
				fscanf(fp, "%s\t%s\t%s\n", f1, f2, f3);
				i = 1;
				while((fscanf(fp, "%d\t%s\t%s\n", &data[i].id, data[i].arr1, data[i].arr2) != EOF))
				{
					i++;
				}
				m = i;
			}
		fclose(fp);
		}	
		break;
		case 2 :
		{
			printf("\t%s\t%s\t%s\n", f1, f2, f3);
				for(i = 1; i < m; i++)
				{
					printf("\t%d\t%s\t%s\n", data[i].id, data[i].arr1, data[i].arr2);
				}
		}
		break;
		case 3 :
		{
			char n1[MAX];
			char n2[MAX];
			FILE *fw;
			fw = fopen(filename, "a"); // after file end
			if (fw != NULL)
			{
				printf("\nNO.%d\n", m);
				printf("Number 1: ");
				scanf("%s", n1);
				printf("Number 2: ");
				scanf("%s", n2);
				fprintf(fw, "%d\t%s\t%s\n", m, n1, n2);
			} else printf("Must read csv file first !\n");			
		fclose(fw);
		}
		break;
		case 4 :
		{
			char c;
			int f;
			printf("===========================================\n");
			printf("=                                         =\n");
			printf("= Which operators do you want to choose ? =\n");
			printf("= (+) Addition                            =\n");
			printf("= (-) Subtraction                         =\n");
			printf("= (*) Multiplication                      =\n");
			printf("= (/) Division                            =\n");
			printf("= (q) Quit                                =\n");
			printf("=                                         =\n");
			printf("==========================================\n");
			scanf(" %c", &c);
	//		menu2(c);
			printf("===========================================\n");
			printf("=                                         =\n");
			printf("= Which items do you want to choose ?     =\n");
			printf("= (1) Load the existing numbers by ID     =\n");
			printf("= (2) Input two numbers to calculast      =\n");
			printf("= (0) Quit                                =\n");
			printf("=                                         =\n");
			printf("==========================================\n");
			scanf("%d", &f);
			int index;
			if(f == 1)
			{
				printf("What index do you want to read ?\n");
				scanf("%d", &index);
				if (index < m)  // Already read .csv
				{
		//		printf("First number : %s\n", data[index].arr1);
		//		printf("Second number : %s\n", data[index].arr2);
				calculate(c, data[index].arr1, data[index].arr2);
				} else printf("Must read csv file first !\n");
			}
			else if(f == 2)
			{
				char c1[MAX];
				char c2[MAX];
				printf("First number\t: ");
				scanf("%s", c1);
				printf("Second number\t: ");
				scanf("%s", c2);
				calculate(c, c1, c2);
			}
		}
		break;
		case 0 :
		{
		flag = 0;
		}
	}
		}
	}
	return 0;
}

void calculate(char c, char arr1[MAX], char arr2[MAX])
{
//	printf("First number : %s\n", arr1);
//	printf("Second number : %s\n", arr2);

	FILE *fr;
	fr = fopen("result.txt", "a");

	int i;
	int j;

	char temp[MAX];

	int *a;
	int *b;
	int *s;
	a = malloc(MAX * sizeof(int));
	b = malloc(MAX * sizeof(int));
	s = malloc(MAX * sizeof(int));

	int sign = 0; // postive
	int l1 = strlen(arr1);
	int l2 = strlen(arr2);
	if (l1 < l2)

	if (l1 < l2 || (l1 == l2 && strncmp(arr1, arr2, l2) < 0) ) // a < b
	{
		strcpy(temp, arr1);
		strcpy(arr1, arr2);
		strcpy(arr2, temp);
		l1 = strlen(arr1);
		l2 = strlen(arr2);
		sign = -1; // negative
	}
	len = l1;
//	printf("l1 : %d\n", len);

	for(i = 0; i < len; i++) // char to int
	{
		if(arr1[i] == 'e' || arr1[i] == 'E')
		a = myatof(arr1, l1); // printf("l1a : %d\n", len);
		else
		a[l1 - i - 1] = arr1[i] - '0';
	}
	for(i = 0; i < len; i++) // char to int
	{
		if(arr2[i] == 'e' || arr2[i] == 'E')
		b = myatof(arr2, l2);
		else
		b[l1 - i - 1] = arr2[i] - '0';
	}

	switch(c)
	{
		case '+' :
		{
		printf("SUM : ");
			for(i = 0; i < len; i++)
        		{
				s[i] = a[i] + b[i];
			}
			for (i = 0; i < len; i++)
			{
				s[i + 1] = s[i] / 10 + s[i + 1]; // carry
				s[i] = s[i] % 10;
			}
			if(s[len] != 0)
			{
				for(i = len; i >= 0; i--)
				printf("%d", s[i]);
				fprintf(fr, "%d", s[i]);
			}
			else
			{
				for(i = len - 1; i >= 0; i--)
				printf("%d", s[i]);
				fprintf(fr, "%d", s[i]);
			}
		printf("\n");
		}
		break;
		case '-' :
		{
		printf("SUM: ");

			if (sign != 0)
			{
				printf("-");
				fprintf(fr, "-");
			}

			for(i = 0; i < l1; i++)
			{
				a[i] = a[i] - b[i];
				if(a[i] < 0)
				{
					a[i] += 10;
					a[i + 1]--; // borrow
				}
			}
			i = l1 - 1l;
			while(a[i] == 0)
			{
				i--;
			}
			for(; i >= 0; i--)
			{
				printf("%d", a[i]);
				fprintf(fr, "%d", a[i]);
			}
			printf("\n");	
			fprintf(fr, "\n");	
		}
		break;
		case '*' :
		{
		printf("SUM : ");
			for(i = 0; i < l2; i++)
			{
				for(j = 0; j < l1; j++)
				{
					s[i + j] = a[j] * b [i] + s[i + j];
				}
			}
			for(i = 0; i < 2* l1; i++)
			{
				if(s[i] >= 10)
				{
					s[i + 1] = s[i + 1] + s[i] / 10;
					s[i] = s[i] % 10;
				}
			}
			i = 2 * l1;
			while(s[i] == 0)
			{
				i--; // jump
			}
			if(i < 0)
			{
				printf("0\n");
				fprintf(fr, "0\n");
			}
			else
			{
				for(; i >= 0; i--)
				{
					printf("%d", s[i]);
					fprintf(fr, "%d", s[i]);
				}
				printf("\n");
				fprintf(fr, "\n");
			}
		}
		break;
		case '/' :
		{
		printf("SUM: ");
	//		int p = 0;
			if (l1 < l2 || (l1 == l2 && strncmp(arr1, arr2, l2) < 0) ) // a < b
			{
				printf("0\n");
			}
	/*		while(1)
			{
				while(strncmp(arr1, arr2, l2) >= 0)
				{
					i = 0;
					while(1)
					{
						if(arr1[i] == '0') i++;
						else
						{
							j = i;
							break;
						}
					}
					for(; i < l2; i++)
					{
						arr1[i] = arr1[i] - arr2[i] + '0';
					}
					for(i = l2 - 1; i > j; i--) // detect < 0
					{
						if(arr1[i] < '0')
						{
							arr1[i] += 10; // borrow
							arr1[i - 1]--;
						}
					}

				}
			}*/
			printf("I give up QAQ !!\n");
		}
		break;
		case 'q' :
		{
			
		}
		break;
	}
}
