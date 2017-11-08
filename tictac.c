#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define D 8

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void printMatrix(int res, int matrix[][D]);
//int checkRange(int res, int pos, int matrix[][D]);

int testRow(int toWin, int posR, int posC, int matrix[][D], int res);
int testCol(int toWin, int posR, int posC, int matrix[][D], int res);
int testDiagLeft(int toWin, int posR, int posC, int matrix[][D], int res);
int testDiagRight(int toWin, int posR, int posC, int matrix[][D], int res);

int main(int argc, char const *argv[]) {
  int matrix[D][D], swap = 0, vinPlayer0 = 0, vinPlayer1 = 0, i = 0, j = 0, toWin = 0;
  int resolution = 0, copy[D][D], posR = 0, posC = 0, element=0;
  srand(time(NULL));
  printf("%s\n", "Enter the resolution of matrix:");
  do
  {
    scanf("%d", &resolution);
  } while(resolution < 3 || resolution > D);
  printf("%s\n", "Enter number of elements needed to win:");
  do
  {
    scanf("%d", &toWin);
  } while(toWin < 0 || toWin > resolution);
  for (i = 0; i < D ; i++) {
    for (j = 0; j < D ; j++) {
      matrix[i][j]=3;
    }
  }
  for (i = 0; i < resolution; i++) {
    for (j = 0; j < resolution; j++) {
      matrix[i][j] = rand()%2;
      copy[i][j] = matrix[i][j];
    }
  }
  printMatrix(resolution, matrix);
  for (i = 0; i < resolution; i++)
  {
    for (j = 0; j < resolution; j++)
    {
      printf("\n %d / %d \n", i, j);
      printMatrix(resolution, matrix);
      posR = i;
      posC = j;
      element = copy[i][j];

      if (posR+toWin-1 <= resolution) //START testing row
      {
        if (testRow(toWin, posR, posC, matrix, resolution)==0)
        {
          if (element == 0)
          {
            vinPlayer0++;
            for (swap = 0; swap < toWin; swap++)
            {
              copy[i][j+swap] = 7;
            }
          }
          else
          {
            vinPlayer1++;
            for (swap = 0; swap < toWin; swap++)
            {
              copy[i][j+swap] = 8;
            }
          }
        }
        else
        {}
      }
      else{}   //END testing row
/*
      if (posC+toWin-1 <= resolution) //START testing col
      {
        if (testCol(toWin, i, j, matrix, resolution))
        {
          if (element == 0)
          {
            vinPlayer0++;
            for (swap = 0; swap < toWin; swap++)
            {
              copy[i+swap][j] = 7;
            }
          }
          else
          {
            vinPlayer1++;
            for (swap = 0; swap < toWin; swap++)
            {
              copy[i+swap][j] = 8;
            }
          }
        }
        else
        {}
        }
        else{}   //END testing col

          if (posR+toWin-1 <= resolution && posC+toWin-1 <= resolution) //START testing LEFT DIAGONAL
          {
            if (testDiagLeft(toWin, i, j, matrix, resolution))
            {
              if (element == 0)
              {
                vinPlayer0++;
                for (swap = 0; swap < toWin; swap++)
                {
                  copy[i+swap][j+swap] = 7;
                }
              }
              else
              {
                vinPlayer1++;
                for (swap = 0; swap < toWin; swap++)
                {
                  copy[i+swap][j+swap] = 8;
                }
              }
            }
            else
            {}
          }
          else{}   //END testing LEFT DIAGONAL

          if (posR+toWin-1 <= resolution && posC-toWin+1 <= 0) //START testing RIGHT DIAGONAL
          {
            if (testDiagLeft(toWin, i, j, matrix, resolution))
            {
              if (element == 0)
              {
                vinPlayer0++;
                for (swap = 0; swap < toWin; swap++)
                {
                  copy[i-swap][j-swap] = 7;
                }
              }
              else
              {
                vinPlayer1++;
                for (swap = 0; swap < toWin; swap++)
                {
                  copy[i-swap][j-swap] = 8;
                }
              }
            }
            else
            {}
          }
          else{}   //END testing RIGHT DIAGONAL
          */
        }
    }
    printf("player 0 have: %d points\n player 1 have: %d points \n", vinPlayer0, vinPlayer1);
    printMatrix(resolution, copy);
  return 0;
}


void printMatrix(int res, int matrix[][D])
{
  int i = 0, j = 0;
  for (i = 0; i < 2*res+3; i++)
  {
    printf("#");
  }
  for (i = 0; i < res; i++)
  {
    printf("\n# ");
    for (j = 0; j < res; j++)
    {
      if (matrix[i][j] < 2)
      {
        printf("%d ", matrix[i][j]);
      }
      else if (matrix[i][j] == 7)
      {
        printf(ANSI_COLOR_RED "%d " ANSI_COLOR_RESET , matrix[i][j]);
      }
      else if (matrix[i][j] == 8)
      {
        printf(ANSI_COLOR_GREEN "%d " ANSI_COLOR_RESET , matrix[i][j]);
      }
    }
    printf("#");
  }
  printf("\n");
  for (i = 0; i < 2*res+3; i++)
  {
    printf("#");
  }
  printf("\n");
}
int checkRange(int res, int pos, int matrix[][D])
{
  return 0;
}

int testRow(int toWin, int posR, int posC, int matrix[][D], int res)
{
  int result = 1, i = 0;
  for (i = 0; i < toWin-1; i++)
  {
    if (matrix[posR][posC] != matrix[posR][posC+1+i])
    {
      return 1;
    }
  }
  return 0;
}



int testCol(int toWin, int posR, int posC, int matrix[][D], int res)
{
  int result = 1, i = 0;
  for (i = 0; i < toWin; i++)
  {
    if (matrix[posR][posC] != matrix[posR+1+i][posC])
    {
      return 1;
    }
  }
  return 0;
}

int testDiagLeft(int toWin, int posR, int posC, int matrix[][D], int res)
{
  int result = 1, i = 0;
  for (i = 0; i < toWin; i++)
  {
    if (matrix[posR][posC] != matrix[posR+1+i][posC+1+i])
    {
      return 1;
    }
  }
  return 0;
}

int testDiagRight(int toWin, int posR, int posC, int matrix[][D], int res)
{
  int result = 1, i = 0;
  for (i = 0; i < toWin; i++)
  {
    if (matrix[posR][posC] != matrix[posR-1-i][posC-1-i])
    {
      return 1;
    }
  }
  return 0;
}
