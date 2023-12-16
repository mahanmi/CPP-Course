#include <iostream>
using namespace std;
int main()
{
  int size, k;
  cin >> size >> k;
  int matrix[size][size];
  int matrixN[size][size];
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
    {
      cin >> matrix[i][j];
      matrixN[i][j] = matrix[i][j];
    }
  for (int z = 0; z < k; z++)
  {
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        double temp = 0, count = 0;
        if (i - 1 >= 0 && j - 1 >= 0 && i - 1 < size && j - 1 < size)
        {
          temp += matrix[i - 1][j - 1], count++;
        }
        if (i - 1 >= 0 && j >= 0 && i - 1 < size && j < size)
        {
          temp += matrix[i - 1][j], count++;
        }
        if (i - 1 >= 0 && j + 1 >= 0 && i - 1 < size && j + 1 < size)
        {
          temp += matrix[i - 1][j + 1], count++;
        }
        if (i >= 0 && j - 1 >= 0 && i < size && j - 1 < size)
        {
          temp += matrix[i][j - 1], count++;
        }
        if (i >= 0 && j + 1 >= 0 && i < size && j + 1 < size)
        {
          temp += matrix[i][j + 1], count++;
        }
        if (i + 1 >= 0 && j - 1 >= 0 && i + 1 < size && j - 1 < size)
        {
          temp += matrix[i + 1][j - 1], count++;
        }
        if (i + 1 >= 0 && j >= 0 && i + 1 < size && j < size)
        {
          temp += matrix[i + 1][j], count++;
        }
        if (i + 1 >= 0 && j + 1 >= 0 && i + 1 < size && j + 1 < size)
        {
          temp += matrix[i + 1][j + 1], count++;
        }
        int zero, one;
        zero = count - temp;
        one = temp;
        if (one > zero)
        {
          matrixN[i][j] = 1;
        }
        else if (one < zero)
        {
          matrixN[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        matrix[i][j] = matrixN[i][j];
  }
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
  return 0;
}
