#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define M 22
#define N 22

int main(int argc, char const *argv[])
{
	int m, n, matrix[M][N], i=0, j=0, k=0, swap=0;
	int m_row[55], m_col[55], m_diag[55];
	for (m = 0; m < M; ++m)
	{
		for (n = 0; n < N; ++n)
		{
			matrix[m][n]=rand()%100;
			printf(" %2d ", matrix[m][n]);
		}
		printf("\n");
	}
	i=0;
	j=0;
	k=0;
	for (m = 0; m < M; ++m)
	{
		for (n = 0; n < N; ++n)
		{
		//	m_col==0;
		//	m_row==0;
			if(m == 2)
			{
				 m_row[i] = matrix[m][n];
				 i++;
			}
			else{
			}
			if(n == 2)
			{
				m_col[j] = matrix[m][n];
				j++;
			}
			else{
			}
			if(m == n){
				m_diag[k]=matrix[m][n];
				k++;
			}
			else{
			}
			
		//	m_diag
		//	m_row
	    }
	}
	printf("\n\n");
	//swap=j;
	for(swap = 0 ; swap < i; swap++)
	{
		printf(" %2d ", m_row[swap]);
	}
	//j = swap;
	//swap = i;
	printf("\n\n");
		for(swap = 0 ; swap < j; swap++)
	{
		printf(" %2d ", m_col[swap]);
	}
	//i=swap;
	//swap=j;
	printf("\n\n");
	for(swap = 0; swap < k; swap++)
	{
		printf(" %2d ", m_diag[swap]);
	}
	return 0;
}
