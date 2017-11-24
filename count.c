#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

#define D 20

int main(int argc, char const *argv[]) {
  FILE *fr;
  srand(time(NULL));
  fr = fopen("cisla.dat", "r");
  if(fr==NULL)
		{
			printf("File error");
			return 1;
		}
  int i = 0, arr[500], max, min;
  int c, d, swap, copy1[550], copy2[550];
  char that[20];
  while((fscanf(fr,"%s", that)) != EOF)
  {
  	if(i == 1)
  	{
  		max = arr[0];
  		min = arr[0];
  	}
  	arr[i] = atoi(that);
  	if(max < arr[i])
  	{
  		max = arr[i];
  	}
  	else if(min > arr[i])
  	{
  	min = arr[i];
	} 
	copy1[i] = arr[i]; 	
	copy2[i] = arr[i]; 
  	i++;
  } 
  int n = i - 1;
  printf("%d   %d    %d\n", i, max, min);
  
  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (copy1[d] > copy1[d+1]) /* For decreasing order use < */
      {
        swap       = copy1[d];
        copy1[d]   = copy1[d+1];
        copy1[d+1] = swap;
      }
      else{}
      if (copy2[d] < copy2[d+1]) /* For oposite order use < */
      {
        swap       = copy2[d];
        copy2[d]   = copy2[d+1];
        copy2[d+1] = swap;
      }
    }
  }
  for(d = 0; d < n; d++)
  {
  	printf(" %d ", copy1[d]);
  }
  printf("\n \n \n");
  for(d = 0; d < n ; d++)
  {
  	printf(" %d ", copy2[d]);
  }
 }
