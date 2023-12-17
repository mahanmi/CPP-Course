#include <iostream>
using namespace std;

int mod = 1e9 + 7;

void matrixMultiply(long long int matrix1[][50], long long int matrix2[][50], int n)
{
  long long int result[50][50];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      result[i][j] = 0;
      for (int k = 0; k < n; k++)
      {
        result[i][j] += ((matrix1[i][k] % mod) * (matrix2[k][j] % mod) % mod);
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      matrix1[i][j] = result[i][j];
    }
  }
}

int main()
{
  int n, k;
  cin >> n >> k;
  long long int matrix1[50][50], matrix2[50][50];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> matrix1[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> matrix2[i][j];
    }
  }
  matrixMultiply(matrix1, matrix2, n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      matrix2[i][j] = matrix1[i][j];
    }
  }
  for (int i = 1; i < k; i++)
  {
    matrixMultiply(matrix1, matrix2, n);
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matrix1[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}