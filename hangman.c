#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  char secret[30], guess[30], unused[60], print[30], swap[30], single, singleup, singledown;
  strcpy(secret, "brandenburg");
  strcpy(guess, "");
  strcpy(unused, "A B C D E F G H I J K L M N O P Q R S T U W X Y Z");
  int won = 0, try = 1;
  int len = strlen(secret);
  int i = 0, right = 0;
  for ( i = 0; i < len; i++) {
    print[i] = '_';
    print[i+1] = '\0';
  }
  int j;
  int pokus = 10;
  char some;
  do {
    printf("\n%s\n", print);
    //printf("Unused letters: %s\n", unused);
    printf("\n%s", "Your guess: ");
    scanf("%s", swap);
    if (strcmp(secret, swap) == 0) {
        printf("%s\n", "Yes!");
        printf("Answer is: %s\n", "secret");
        return 0;
    }
     single = swap[0];
     singleup = toupper(single);
     singledown = tolower(single);
     //printf(" %c %c ", singleup, singledown);
     right = 0;
     for(j = 0; j < len; j++)
     {
     	some = secret[j];
     	if(singleup == some || singledown == some)
     	{
     		print[j] = singleup;
     		right++;
     	}
     	else
     	{}
     }
     if(right == 0)
     {try++;
        pokus--;
     }
    if (strcmp(print, secret)) {
      won = 1;
    }
    if (strcmp(secret, swap) == 0) {
        printf("%s\n", "Yes!");
        printf("Answer is: %s\n", "secret");
        return 0;
    }

    printf("%s %d %s\n", "ostava ti", pokus, "pokusov");
  } while(won == 0 || try < 11);
  return 0;
}
