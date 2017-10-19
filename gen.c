#include<stdio.h>
#include<string.h>

int main(){
	char name[20];
	int num[33], a=0, i=1;
	//printf("enter number of output: ");
	//scanf("%d", &num[0]);
	printf("enter all states of output separated by space\n");
	for(a=1;a<17;a++){
		scanf("%d", &num[a]);
	}
	//printf("\nTable for: Y%d", num[0]);
	printf("\n A | B | C | D || Y");
	i=1;
	printf("\n --|---|---|---||---");
	for(int a=0;a<2;a++)
	{
		for(int b=0;b<2;b++)
		{
			for(int c=0;c<2;c++)
			{
				for(int d=0;d<2;d++)
				{
					printf("\n %d | %d | %d | %d || %d", a, b, c, d, num[i]);
					i++;
				}
			}
		}
	}
				
	a = i;
	printf("\n\n");
	printf("\n             d   ");
	printf("\n         c  ---- ");
	printf("\n         ----    ");
	printf("\n      %d  %d  %d  %d ", num[1], num[3], num[4], num[2]);
	printf("\n  b | %d  %d  %d  %d ", num[5], num[7], num[8], num[6]);
	printf("\n   || %d  %d  %d  %d ", num[13], num[15], num[16], num[14]);
	printf("\n a |  %d  %d  %d  %d ", num[9], num[11], num[12], num[10]);
	printf("\n\n");
	//printf(" Y%d =", num[0]);
	printf("\n\n");

}
