#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>


int overenie();
int mince();
int mena();
int reverse();
int cifSucet();
int mselect();
int parnost();
int klad_zapor();
int BMI();
int minimum();
int sorting();
int palindrom();
int obdobie();
int diamond();
int triangle();
int help();


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(int argc, char const *argv[])
{

	srand(time(NULL));
	int run=0;
	system("clear");
	do{
		printf(ANSI_COLOR_RED     "\nNUMERO CODE"     ANSI_COLOR_RESET "\n");
		if (mselect())
		{
			return 0;
		};

	}while(run == 0);
	


	
}


int klad_zapor(){
	int i=0;
	printf("Please enter a number:\n");
	scanf("%dn", &i);
	if (i==0)
	{
		printf("Number is NULL\n");
	}
	else if (i>0)
	{
		printf("Number %dn is positive\n", i);
	}
	else 
	{
		printf("Number %dn is negative\n", i);
	}
}

int parnost(){

	int m=0;
	printf("zadaj vstup\n");
	scanf("%dn", &m);
	if (m%2 == 0)
	{
		printf("cislo %dn je parne\n", m);
	}
	else
	{
		printf("cislo %dn je neparne\n", m);
	}
}

int mselect()
{
	char use[10]={0, 0, 0, 0, 0, 0, 0, 0, 0};
	scanf("%s", &use[0]);
	if (strcmp(use, "overenie")==0)
	{
		overenie();
		return 0;
		}
	else if (strcmp(use, "reverse")==0)
		{
		reverse();
		return 0;
		}
	else if (strcmp(use, "mince")==0)
		{
		mince();
		return 0;
		}
	else if (strcmp(use, "mena")==0)
		{
		mena();
		return 0;
		}
	else if (strcmp(use, "cifSucet")==0)
		{
		cifSucet();
		return 0;
		}
	else if (strcmp(use, "exit")==0)
		{
		return 1;
		}
	else if (strcmp(use, "parnost")==0)
		{
		parnost();
		return 0;
		}
	else if (strcmp(use, "klad_zapor")==0)
		{
		klad_zapor();
		return 0;
		}
	else if (strcmp(use, "BMI")==0)
		{
		BMI();
		}
	else if (strcmp(use, "sorting") == 0)
		{
		sorting();
		}
	else if (strcmp(use, "minimum")==0)
		{
		minimum();
		return 0;
		}
	else if (strcmp(use, "palindrom")==0)
		{
		palindrom();
		return 0;
		}
	else if (strcmp(use, "diamond")==0)
		{
		diamond();
		return 0;
		}
	else if (strcmp(use, "triangle")==0)
		{
		triangle();
		return 0;
		}
	else if (strcmp(use, "obdobie")==0)
		{
		obdobie();
		return 0;
		}
	else
	{
		help();
		return 0;
	}
};

int	help()
{
	printf(ANSI_COLOR_YELLOW     "\nDostupne moznosti:"     ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW     "overenie 		jednoducha bezpecnostna otazka"     ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW     "reverse 		vypisanie cisla (retazca) ozadu"     ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW     "mince 			test ktora zo stiroch minci je falosna"     ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW     "mena 			prepocet sumy v eurach na tri ine meny"     ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW     "cifSucet 		ciferny sucet zadaneho cisla"     ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW     "parnost 		overenie ci je cislo parne"     ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW     "klad_zapor 		overenie ci je cislo kaldne zaporne alebo nula"     ANSI_COLOR_RESET "\n");
	printf(ANSI_COLOR_YELLOW     "exit 			ukoncenie programu"     ANSI_COLOR_RESET "\n");

};

int mince(){

	int i_minca1 = 0, i_minca2 = 0, i_minca3 = 0, i_minca4 = 0;
	int i_pom = 1;

	do
	{
		scanf(" %d %d %d %d", &i_minca1, &i_minca2, &i_minca3, &i_minca4);
		if ((i_minca1 > 0) && (i_minca2 > 0) && (i_minca3 > 0) && (i_minca4 > 0))
		{
			i_pom = 0;
		}
		else 
		{
			printf("zadaj 4 kladne cele cisla\n");
		}
	}while(i_pom == 1);



int diamond(){
	int i, j,z=0,m;
    
    printf("Enter the  triangle height: ");
  	scanf("%dn",&m);
     
    
    for(i = 1; i <= m; i++) 
	{
        
        for(j = 1; j <= m-i; j++) {
           printf(" ");
        }
        
        while(z < (2*i - 1)) {
            printf("*");
            z++;;
        }
        z=0;
        
        printf("\n");
    }
    m--;
    
    for(i = m;i >= 1; i--) 
	{
        
        for(j = 0; j <= m-i; j++) {
           printf(" ");
        }
        
        z = 0;
        while(z < (2*i - 1)) {
            printf("*");
            z++;
        }
        printf("\n");
    }
 
    return 0;
}


int triangle(){
		int m,i=0,j=0,n,h;
	char z;
	
   	printf("Enter the  triangle height: ");
  	scanf("%dn",&m);
//  printf("Enter the numbers of col: ");
// 	scanf("%dn",&n);
  	getchar();
//  printf("Enter the character: ");
// 	scanf("%c",&z);
  		
  	for(i=1;i<=m;i++)
  	{
  	
		for(j=1;j<=m-i;j++)
  		{
  			printf("  ");		
	  	}
	  	
	  	h=0;
	  	
//		while(h != 2*i-1)
        while(h<(2*i-1))
	  	{
            h++;
			printf("* ");
           
        }
	  	
	  	
	  printf("\n");	
}
}


	

	if (i_minca1 != i_minca2)
	{
		if (i_minca2 != i_minca3)
		{
			printf("minca 2 je falošná\n");
		}
		else
		{
			printf("minca 1 je falošná\n");
		}
	}
	else
	{
		if (i_minca3 != i_minca2)
		{
			printf("minca 3 je falošná\n");
		}
		else
		{
			printf("minca 4 je falošná\n");
		}
	}
};

int overenie(){
	int i_pokus = 3, i_cislo1 = 0, i_cislo2 = 0, i_odpoved = 0, i_spravna = 0;

	do{

		i_cislo1 = (rand() %30) + 1;
		i_cislo2 = (rand() %30) + 1;
		i_spravna = i_cislo1 + i_cislo2;
		

		printf("how many is : %dn * %dn", i_cislo1, i_cislo2 );
		scanf("%dn", &i_odpoved);

		if (i_odpoved == i_spravna)
		{
			printf("Right \n");
			return 1;	
		}
		else if (i_pokus > 0)
		{
			i_pokus --;
			printf(" :( NO %dn \n",i_spravna);
			printf("You may try it %dn more times\n", i_pokus);
			//printf("%dn", i_spravna);
		}
		else {
			printf("NO! get out of here\n");
			return 0;
		}

	}
	while(1);

	return 0;
};

int mena(){
	float eur=0;
	printf("Zadaj pozadovanu sumu:");
	scanf("%f", &eur);
	printf("%1.2f EUR = %1.2f USD\n", eur ,(eur*1.1905));
	printf("%1.2f EUR = %1.2f HUF\n",eur ,(eur*310.61));
	printf("%1.2f EUR = %1.2f CZK\n",eur ,(eur*26.083));
};

int reverse(){

	char in[50];
	int i=0;
	scanf("%s", in);
	i = strlen(in);
	i--;
	do
	{
		printf("%c", in[i]);
		i--;
	} while (i>=0);
	printf("\n");
	return 0;
};

int cifSucet(){
	int cislo=0, sucet=0, i=0;
	
		scanf("%dn", &cislo);
		while(cislo > 0)
		{
			sucet = sucet + (cislo % 10);
			cislo = cislo / 10;
		}
		printf("sucet je %dn", sucet);
		return 0;
};

int BMI()
{
		float m=0,v=0,bmi=0;
	do{
		printf("zadaj hmotnost v kg (min 20kg) \n");
		scanf("%f", &m);
		printf("zadaj vysku v m (min 0.6m) \n ");
		scanf("%f", &v);
	}while((m <= 20) || (v <= 0.6));
	bmi = (m / (v*v));
	printf("vase bmi je: %1.2f \n", bmi);
	if(bmi <= 20){printf("podvaha \n");}
	else if(bmi <= 25) {printf("normal \n");}
	else if(bmi <= 30) {printf("nadvaha \n");}
	else {printf("obezita \n");}
	return 0;
}

int minimum()
{
	float c1=0, c2=0, c3=0;
	scanf("%f %f %f", &c1, &c2, &c3);

	if ((c1 == c2) && (c1 == c3))
	{
		printf("NUMBERS ARE EQUAL\n");
		return 0;
	}

	if ((c1 < c2) && (c1 < c3))
	{
		printf("c1 is smallest number with value %1.2f\n", c1);
		if (c2 > c3)
		{
			printf("c2 is biggest with value: %1.2f\n", c2);
			printf("and middle number is c3 with value: %1.2f\n",c3);
			printf("%1.2f %1.2f %1.2f\n", c1, c3, c2);
		}
		else 
		{
			printf("c3 is biggest with value: %1.2f\n", c3);
			printf("and middle number is c2 with value: %1.2f\n",c2);
			printf("%1.2f %1.2f %1.2f\n", c1, c2, c3);
		}
	}
	else if ((c2 < c1) && (c2 < c3))
	{
		printf("c2 is smallest number with value %1.2f\n", c2);
		if (c1 > c3)
		{
			printf("c1 is biggest with value: %1.2f\n", c1);
			printf("and middle number is c3 with value: %1.2f\n",c3);
			printf("%1.2f %1.2f %1.2f\n", c2, c3, c1);
		}
		else 
		{
			printf("c3 is biggest with value: %1.2f\n", c3);
			printf("and middle number is c1 with value: %1.2f\n",c1);
			printf("%1.2f %1.2f %1.2f\n", c2, c1, c3);
		}
	}
	else if ((c3 < c2) && (c3 < c1))
	{
		printf("c3 is smallest number with value %1.2f\n", c3);
		if (c2 > c1)
		{
			printf("c2 is biggest with value: %1.2f\n", c2);
			printf("and middle number is c1 with value: %1.2f\n",c1);
			printf("%1.2f %1.2f %1.2f\n", c3, c1, c2);
		}
		else 
		{
			printf("c1 is biggest with value: %1.2f\n", c1);
			printf("and middle number is c2 with value: %1.2f\n",c2);
			printf("%1.2f %1.2f %1.2f\n", c3, c2, c1);
		}
	}
	return 0;
}


int sorting(){
	printf("Enter numbers that have to be sorted\n");

	int num=0, i=0, j=0, swap=0, run=1;
	do
	{
		scanf("%dn", &num);
	} while ((num < 0) || (num > 254));
	float digit = 0;
	float *some = malloc(num * sizeof(float));
	if (some == NULL)
	{
		printf("malloc failed\n");
		return 0;
	}
	do
	{
		scanf("%f", &digit);
		some[i] = digit;
		printf("zadane %f\n", some[i]);
		 
	} while (i < num);
	
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; +j++)
		{
			if (some[i] < some[j])
			{
				swap = some[i];
				some[i] = some[j];
				some[j] = swap;
			}
		}
	}
	return 0;
}


int palindrom()
{
	printf("enter thee digit number\n");
	int x=0;
	scanf("%dn", &x);
	if ((x<1000) && (x>99))
	{
		int z=0, y=0;
		z = (x / 100);
		y = (x % 10);
		if (z == y)
		{
			printf("number  IS PALINDROME\n");
		}
		else
		{
			printf("number IS NOT PALINDROME\n");
		}
	}
	else
	{
		printf("wrong number\n");
	}
}

int obdobie()
{
	int mesiac=0;
	printf("Enter moon number:\n");
	scanf("%dn", &mesiac);
	if ((mesiac > 12) || (mesiac < 1) )
	{
		printf("Wrong number\n");
	}
	else
	{
		if ((mesiac < 3) || (mesiac == 12))
		{
			printf("it is WINTER\n");
		}
		else if ((mesiac <= 5))
		{
			printf("it is SPRING\n");
		}
		else if (mesiac <= 8)
		{
			printf("it is SUMMER\n");
		}
		else 
		{
			printf("it is AUTUMN\n");
		}
	}
}

/*int abc()
{
	int a = 4, b = 5, c = 0;
	do
	{
	
	} while ((scanf()));
}*/
