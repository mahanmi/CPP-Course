#include <iostream>
#include <vector>
using namespace std;

bool hamilton(int matrix[][10], int count, int n, vector<int> &path, bool inPath[])
{
  if (path.size() == count)
  {
    if (matrix[path[0] - 1][path[count - 1] - 1] == 1)
    {
      return true;
    }
    else
      return false;
  }
  for (int i = 0; i < count; i++)
  {
    if (matrix[i][n - 1] == 1 && !inPath[i])
    {
      path.push_back(i + 1);
      inPath[i] = true;
      if (hamilton(matrix, count, i + 1, path, inPath))
        return true;
      path.pop_back();
      inPath[i] = false;
    }
  }
  return false;
}

int main()
{
  int n, m;
  vector<int> path;
  bool inPath[10] = {0};
  cin >> n >> m;
  int matrix[10][10] = {0}, count = n;
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    matrix[a - 1][b - 1] = 1;
    matrix[b - 1][a - 1] = 1;
  }
  if (hamilton(matrix, count, n, path, inPath))
  {
    for (int i = 0; i < n; i++)
    {
      cout << path[i] << " ";
    }
  }
  else
  {
    cout << "NO ";
  }
  return 0;
}
