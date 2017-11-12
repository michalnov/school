#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define D 24

void itoaA(int abc, char string[])
{
  int a = strlen(string), x = abc;
  if (abc < 10) {
    string[0] = x+48 ;
    string[1] = '\0';
  }
  else
  {
    string[0] = (x/10)+48 ;
    string[1] = (x%10)+48 ;
    string[2] = '\0';
  }
}

int main(int argc, char const *argv[]) {

  int len=0;
  char bankCode[5], prefix[7];
  char accountNumber[12], country[3];
  char copy[30];
  copy[0] = '\0';
  int i = 0;
  strcpy(country, "SK");
  strcpy(bankCode, "0000");
  strcpy(prefix, "000000");
  strcpy(accountNumber, "0000000000");

  printf("%s\n%s\n", "(Bank Code need to be at least one digit)", "Other positions will be filled with '0'");
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
  len = strlen(bankCode);
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
  printf("\n%s\n%s\n", "(Account prefix need to be at least one digit)", "For account without prefix enter '0'");
  printf("%s", "Account prefix: ");
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
  printf("\n%s\n%s\n", "(Account Number need to be at least 2 digits)", "Other positions will be filled with '0'");
  printf("%s", "Account Number: ");
  scanf("%s", accountNumber);
  printf("\n");
  if (strlen(accountNumber) > 10 || atoi(accountNumber) == 0 || strlen(accountNumber) < 2 || atoi(accountNumber) <= 9) {
    printf("%s\n", "Wrong Input");
    return  1;
  }
  else
  {
    len = strlen(accountNumber);
    while (len < 10) {
      for (i = 10; i >= 0; i--) {
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
  //printf("%s\n", copy);
  char postfix[9];
  char iban[30];
  strcpy(iban, "SK00");
  strcat(iban, copy);
                                                      //START CALCULATING
  char todivide[5], swap[4], decimal[15], full[30];
  strcpy(full, "");
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
    swap[0] = copy[a];
    swap[1] = '\0';
    a++;

    strcat(todivide, swap);
    //printf("%s\n", todivide);
  } while(atoi(todivide) < 97);
  toCalc = atoi(todivide);
  residuum = toCalc / 97;
  res = toCalc - ((int)residuum*97);
  //printf("toCalc %d residuum %lf res %d\n", toCalc, residuum, res);
  itoaA((int)residuum, swap);
  strcat(full, swap);
  itoaA(res, todivide);
  do {
    if (a <= len) {
      swap[0] = copy[a];
      swap[1] = '\0';
      a++;
      //printf("%s\n", todivide);
      strcat(todivide, swap);
      //printf("%s\n", todivide);
    }
    else
    {
      swap[0] = '0';
      swap[1] = '\0';
      //printf("%s\n", todivide);
      strcat(todivide, swap);
    }
    toCalc = atoi(todivide);
    residuum = toCalc / 97;
    res = toCalc - ((int)residuum*97);
    //printf("toCalc %d residuum %lf res %d\n", toCalc, residuum, res);
    if (a <= len) {
      itoaA((int)residuum, swap);
      strcat(full, swap);
      itoaA(res, todivide);
    }
    else
    {
      itoaA((int)residuum, swap);
      //printf("decimal %d %s\n", b, decimal);
      strcat(decimal, swap);
      b++;
      swap[0] = '0';
      swap[1] = '\0';
      itoaA(res, todivide);
    }
  } while(b < 11);
  for (i = 2; i < strlen(decimal); i++) {
    decimal[i] = decimal[i+1];
  }
  decimal[12] = '\0';
  result = (double)atof(decimal);
  //printf("%s %s\n", full, decimal);
  toCalc = 97 * result;
  res = 98 - toCalc;
  if (res < 0) {
    res = res * (-1);
  }
  //printf("%d\n", res);
  itoaA(res, todivide);
  if (res == 0) {
    iban[2] = '0';
    iban[3] = '0';
    printf("IBAN is: %s\n", iban);
    return 0;
  }
  else if (res <= 10) {
    res = res - 1;
    itoaA(res, todivide);
    iban[2] = '0';
    iban[3] = todivide[0];
    printf("IBAN is: %s\n", iban);
    return 0;

  }
  else
  {
    iban[2] = todivide[0];
    iban[3] = todivide[1];
  }
  res = res - 1;
  itoaA(res, todivide);
  //res = res - 1;
  //printf("%s\n", todivide);
  iban[2] = todivide[0];
  iban[3] = todivide[1];
  printf("IBAN is: %s\n", iban);
  return 0;
}
