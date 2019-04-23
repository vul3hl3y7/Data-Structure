/*
*	Execrise A : The d-neighbors serch
*
*		Give some POI ( points of interest) and query-set, analysis their relationship.
*
*	Date : 2013/10/10
*
*	Writer : Meng Tseng Tsai
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define d_max 60000
#define min 0
#define max 1000000

typedef struct point	// POI(x,y)
{	
	int x;
	int y;

	int grid;
} point;

typedef struct query	// query set(x,y)
{	
	int x;
	int y;
} query;


// void grid(point *P, int n, query *Q, int m, int d);	// find d-neighbor

int main(int argc, char *argv[])
{
	FILE *fp;
	char filename[20];

	if(argc == 2)
	{
		fp = fopen(argv[1], "r");		
	}
	else
	{
		printf("Read file name ?\n");
		scanf("%s", filename);
		fp = fopen(filename, "r");
	}

	if(fp == NULL)
	{
		printf("File no found !\n");
		return 0;
	}

	int number;
	int n = 0; //  number of POI
	int m = 0; //  number of query set 
	int d = 0; //  distance of query set
	int i = 0;

	double start = (double)clock();

	fscanf(fp, "%d", &number);
	
			n = number; // number of POI
			point *P;
			query *Q;
			P = (point *)malloc(n * sizeof(point));

			for(i = 0; i < n; i++)
			{
				fscanf(fp, "%d %d", &P[i].x, &P[i].y);	// POI (x,y)
				P[i].grid = cell;
			}

			qsort(P, n, sizeof(point), cmp);

			fscanf(fp, "%d %d", &m, &d);
			Q = (query *)malloc(m * sizeof(point));

			while( m != 0 || d != 0)	// end point
			{
				for(i = 0; i < m; i++)
				{
					fscanf(fp, "%d %d", &Q[i].x, &Q[i].y);		
				}
				grid(P, n, Q, m, d);	// find d-neighbor
				free(Q);				// free query set for next set
				fscanf(fp, "%d %d", &m, &d);	// number and distance of next query set
				Q = (query *)malloc(m * sizeof(point));	// next query set
			}
		double end = (double) clock();
		printf("%f\n", (end - start)/CLOCKS_PER_SEC);
	return 0;
}

void grid(point *P, int n, query *Q, int m, int d)
{
	int i;
	int j;
	int fx;
	int fy;
	int cx;
	int cy;
	int count = 0;


	for(i = 0; i < m; i++)
	{	
		//fx = Q[i].x / b;
		//fy = Q[i].y / b;
		fx = Q[i].x;
		fy = Q[i].y;
//		printf("fx : %d, fy: %d\n", fx, fy);

		for(j = 0; j < n; j++)
		{
			//cx = P[j].x / b;
			//cy = P[j].y / b;
			cx = P[j].x;
			cy = P[j].y;
//		printf("cx : %d, cy: %d\n", cx, cy);

		//	if (fx - cx <= d && fy - cy <= d )	// grid |x2 - x1| <= d && |y2 - y1| <= d
		//	if (cx - fx >= -d && cy - fy >= -d)
		//	{
				int a;
				int b;

				a = cx - fx;
				b = cy - fy;

				if((a * a) + (b * b) <= d * d)	// real distance
				{
					count++;
				}
		//	}
		}
	}	
		printf("%d\n", count);
		count = 0;
}
