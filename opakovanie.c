#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define D 30

int main(){
	srand(time(NULL));
	int i=0, j=0, k=0, z=0, n=0, n2=0, found=0, found2=0, origin[D], copy[D], zhodne[D];
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
				printf("\n nasla sa zhoda zhoda %d", z);
				found2=0;
				for(k=0;k<n2;k++){
					if(z == zhodne[k])
					{
						found2++;
						printf(" - zhoda v poli zhodnych cisel");
						break;
					}
				}
				if(found2==0)
					{
						zhodne[n2] = z;
						n2++;
					}
				break;
			}
			
		}
		if(found == 0)
		{
			copy[j] = z;
			n++;
		}
	}
	printf("\n\n pole jedinecnych cisel: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ", copy[i]);
	}
	printf("\n\n pole zhodnych cisel: \n");
	for(i=0;i<n2;i++)
	{
		printf("%d ", zhodne[i]);
	}
	printf("\n");
return 0;
}
