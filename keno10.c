#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define D 20

int main(){
	srand(time(NULL));
	int arr[D], a=0, b=0, zhoda=0;
	for(a = 0; a < D; a++)
	{
		arr[a] = rand()%80+1;
		for(b = 0; b < a; b++)
		{
			if(arr[a] == arr[b])
			{
				do
				{
					arr[a] = rand()%80+1;
					zhoda++;
				}while(arr[a] == arr[b]);
			}
		}
		printf("\n %d ", arr[a]);
		
	}
	printf("\n\n %d times used regen", zhoda);
}

