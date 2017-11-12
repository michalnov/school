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
  char copy[29];
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
  char postfix[9];
  char iban[30];
  strcpy(iban, "SK00");
  strcat(iban, copy);
                          //START CALCULATING
  char todivide[5], swap[4], decimal[12];
  strcpy(decimal, "0.");
  strcpy(todivide, "0");
  strcpy(postfix,"282000");
  strcat(copy, postfix);
  double residuum = 0.00, r = 0.00;
  int a = 0, res = 0, b = 0, toCalc = 0;
  double result = 0;
  len = strlen(copy);
                          //dividing
  do {
    if (a < len) {
      swap[0] = copy[a];
      swap[1] = '\0';
      a++;
    }
    else
    {
      swap[0] = '0';
      swap[1] = '\0';
    }
    strcat(todivide, swap);
    toCalc = atoi(todivide);
    residuum = toCalc / 97;
    res = toCalc - ((int)residuum*97);
    if (a < len) {
      itoa(res, todivide, 10);
    }
    else
    {
      itoa((int)residuum, swap, 10);
      strcat(decimal, swap);
      b++;
      swap[0] = '0';
      swap[1] = '\0';
    }
  } while(b < 8);
  result = (double)atof(decimal);
  toCalc = 97 * result;
  res = 98 - toCalc;
  if (res < 0) {
    res = res * (-1);
  }
  itoa(res, todivide, 10);
  printf("%s\n", todivide);
  iban[2] = todivide[0];
  iban[3] = todivide[1];
  printf("%s\n", iban);
  return 0;
}
