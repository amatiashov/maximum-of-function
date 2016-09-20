#include <stdio.h>
#include <iostream>

const int maxSize=10;

void data_input(int &n, float A[][maxSize], float B[]);

int main()
{
  float sum, zero;
  int n;
  //float A[maxSize][maxSize], B[maxSize];
  //data_input(n, A, B);
// ----------------------------------------------------------
  n = 4;
  float A[5][5] = {
    {0,0,0,0,0},
    {0,2,4,-4,6},
    {0,1,4,2,1},
    {0,3,8,1,1},
    {0,2,5,0,5}
  };
  float B[5] = {0,8,-4,-5,2};
  // решение X = {1, -1, -1, 1}
// ----------------------------------------------------------
  for (int j = 2; j <= n; j++)
    A[1][j] /= A[1][1];

  A[1][1] = A[1][1];
  for (int k = 2; k <= (n-1); k++)
  {
    for (int i = k; i <= n; i++)
    {
      sum = 0;
      for (int m = 1; m <= (k-1); m++)
        sum += A[i][m] * A[m][k];
      A[i][k] -= sum;
    }
    for (int j = (k+1); j <= n; j++)
    {
      sum = 0;
      for (int m = 1; m <= (k-1); m++)
        sum += A[k][m] * A[m][j];
      A[k][j] = (A[k][j] - sum) / A[k][k];
    }
  }

  sum = 0;
  for (int m = 1; m <= (n-1); m++)
    sum += A[n][m] * A[m][n];
  A[n][n] -= sum;


  B[1] /= A[1][1];
  for (int i = 2; i <= n; i++)
  {
    sum = 0;
    for (int j = 1; j <= (i-1); j++)
      sum += A[i][j] * B[j];
    B[i] = (B[i] - sum) / A[i][i];
  }

  for (int i =(n-1); i>=1; i--)
  {
    sum = 0;
    for (int j = (i+1); j <= n; j++)
      sum += A[i][j] * B[j];
    B[i] -= sum;
  }

//---------------------------------------------------------
    printf("----------------\n");
    printf("LU-матрица\n");
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
        printf("%f ", A[i][j]);
        printf("\n");
    }
    printf("L-матрица\n");
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++) {
        if (j <= i) {
          printf("%f ", A[i][j]);
        }
        else
        {
          float t = 0;
          printf("%f ", t);
        }
      }
      printf("\n");
    }
    printf("U-матрица\n");
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++) {
        if (j > i) {
          printf("%f ", A[i][j]);
        }
        else
          printf("%f ", zero);
      }
      printf("\n");
    }
    printf("----------------\n");
    printf("Ответ: ");
    for (int i = 1; i <= n; i++)
      printf("%f ", B[i]);
    printf("\n");
    printf("----------------\n");
//---------------------------------------------------------
}

void data_input(int &n, float A[][maxSize], float B[])
{
  printf("%s\n", "Введите размер матрицы: ");
  scanf("%d", &n);

  printf("%s\n", "Введите матрицу коэффициентов (А): ");
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <=n; j++)
      scanf("%f", &A[i][j]);

  printf("%s\n", "Введите столбец свободных членов (В): ");
  for (int i = 1; i <= n; i++)
    scanf("%f", &B[i]);

  printf("%s\n", "Введена матрица:");
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      printf("%f ", A[i][j]);
      printf("\n");
  }
}
