#include <iostream>
using namespace std;

bool isQueenSafe(int n, int x, int y, int queen, int board[][10])
{
  if (queen == 0)
  {
    return true;
  }
  for (int i = 0; i < n; i++)
  {
    if (board[x][i] == 1)
      return false;
    if (board[i][y] == 1)
      return false;
  }
  for (int i = 0; i < n; i++)
  {
    if (x + i < n && y + i < n)
      if (board[x + i][y + i] == 1)
        return false;
    if (x - i >= 0 && y - i >= 0)
      if (board[x - i][y - i] == 1)
        return false;
    if (x + i < n && y - i >= 0)
      if (board[x + i][y - i] == 1)
        return false;
    if (x - i >= 0 && y + i < n)
      if (board[x - i][y + i] == 1)
        return false;
  }
  return true;
}

bool QueenCounter(int n, int queen, int board[][10], int &count)
{
  if (queen == 0)
  {
    return true;
  }
  for (int i = 0; i < n; i++)
  {
    if (isQueenSafe(n, i, queen - 1, queen, board))
    {
      board[i][queen - 1] = 1;
      if (QueenCounter(n, queen - 1, board, count))
      {
        cout << "===================" << endl;
        for (int iB = 0; iB < n; iB++)
        {
          for (int jB = 0; jB < n; jB++)
          {
            cout << board[iB][jB] << " ";
          }
          cout << endl;
        }
        count++;
      }
      board[i][queen - 1] = 0;
    }
  }
  return false;
}

int main()
{
  int n, count = 0;
  cin >> n;
  int board[10][10] = {0};
  QueenCounter(n, n, board, count);
  cout << "===================" << endl
       << count << endl;
  return 0;
}