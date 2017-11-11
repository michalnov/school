#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define D 24

int main(int argc, char const *argv[]) {

  char bankCode[5], prefix[7];
  char accountNumber[11], country[3];
  char iban[26], copy[26];
  int i = 0;
  strcpy(country, "SK");
  strcpy(bankCode, "0000");
  strcpy(prefix, "000000");
  strcpy(accountNumber, "0000000000");
  printf("\n%s", "Bank code: ");
  scanf("%s", bankCode);
  if (atoi(bankCode)==0) {
    printf("%s\n", "Wrong Input");
    return  1;
  }
  if (strlen(bankCode) > 4) {
    printf("%s\n", "Wrong Input");
    return  1;
  }
  int len = strlen(bankCode);
  while (len < 4) {
    for (i = 4; i >= 0; i--) {
      if (i == 0) {
        bankCode[0] = '0';
      }
      else
      {
        bankCode[i] = bankCode[i-1];
      }
      len = strlen(bankCode);
    }
  }
  printf("%s", "prefix: ");
  scanf("%s", prefix);
  if (atoi(prefix)==0)
  {
    strcpy(prefix,"000000");
  }
  else if(strlen(prefix) > 6)
  {
    printf("%s\n", "Wrong Input");
    return  1;
  }
  else
  {
    len = strlen(prefix);
    while (len < 6) {
      for (i = 6; i >= 0; i--) {
        if (i == 0) {
          prefix[0] = '0';
        }
        else
        {
          prefix[i] = prefix[i-1];
        }
        len = strlen(prefix);
      }
    }
  }
  printf("%s", "Account Number: ");
  scanf("%s", accountNumber);
  if (strlen(accountNumber) > 9 || atoi(accountNumber) == 0) {
    printf("%s\n", "Wrong Input");
    return  1;
  }
  else
  {
    len = strlen(accountNumber);
    while (len < 9) {
      for (i = 9; i >= 0; i--) {
        if (i == 0) {
          accountNumber[0] = '0';
        }
        else
        {
          accountNumber[i] = accountNumber[i-1];
        }
        len = strlen(accountNumber);
      }
    }
  }
  strcat(copy, bankCode);
  strcat(copy, prefix);
  strcat(copy, accountNumber);
  printf("%s\n", copy);

  return 0;
}
