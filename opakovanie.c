#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define D 50

int main(){
	srand(time(NULL));
	int i=0, j=0, z=0, n=0, found=0, origin[D], copy[D];
	for(i=0;i<D;i++)
	{
		origin[i]=rand()%30+1;
		printf("%d ", origin[i]);	
	}
	for(i=0;i<D;i++)
	{
		z = origin[i];
		found =0;
		for(j=0; j < n; j++)
		{
			if(n==0)
			{
				copy[n]=z;
				n++;
				break;
			}
			else if(z == copy[j])
			{
				found ++;
				printf("\n zhoda %d", z);
				break;
			}
			
		}
		if(found == 0)
		{
			copy[j] = z;
			n++;
		}
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ", copy[i]);
	}
	
return 0;
}
