#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define D 8

void printMatrix(int res, int matrix[][D]);
int checkRange(int res, int pos, int matrix[][D]);

int main(int argc, char const *argv[]) {
  int matrix[D][D], swap = 0, vinPlayer0 = 0, vinPlayer1 = 0, i = 0, j = 0;
  int resolution = 0;
  srand(time(NULL));
  printf("%s\n", "Enter the resolution of matrix:");
  do {
    scanf("%d", &resolution);
  } while(resolution < 3 || resolution > D);
  for (i = 0; i < resolution; i++) {
    for (j = 0; j < resolution; j++) {
      matrix[i][j] = rand()%2;
    }
  }
  printMatrix(resolution, matrix);
  for (i = 0; i < resolution; i++) {
    checkRange(i, matrix);
  }
  return 0;
}


void printMatrix(int res, int matrix[][D])
{
  int i = 0, j = 0;
  for (i = 0; i < 2*res+3; i++) {
    printf("#");
  }
  for (i = 0; i < res; i++) {
    printf("\n# ");
    for (j = 0; j < res; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("#");
  }
  printf("\n");
  for (i = 0; i < 2*res+3; i++) {
    printf("#");
  }
  printf("\n");
}
int checkRange(int res, int pos, int matrix[][D])
{

}
