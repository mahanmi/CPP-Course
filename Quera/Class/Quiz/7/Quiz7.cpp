#include <iostream>
using namespace std;

int main()
{
  int m, n;
  cin >> n >> m;
  int array[m][n];
  for (int j = 0; j < n; j++)
  {
    for (int i = 0; i < m; i++)
    {
      cin >> array[i][j];
    }
  }
  int rowSum[500] = {0};
  int colSum[500] = {0};
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (array[i][j] == 1)
      {
        rowSum[i]++;
        colSum[j]++;
      }
    }
  }
  unsigned long long count = 0;
  for (int j = 0; j < n; j++)
  {
    for (int i = 0; i < m; i++)
    {
      if (array[i][j] == 1)
      {
        count += (rowSum[i] - 1) * (colSum[j] - 1);
      }
    }
  }
  cout << count << endl;
  return 0;
}
