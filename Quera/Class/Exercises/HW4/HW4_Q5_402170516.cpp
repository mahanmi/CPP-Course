#include <iostream>
using namespace std;
int main()
{
  int n, honest, negative = 0, criminal = 0, temp;
  cin >> n >> honest;
  int list[100000], suspects[100000];
  bool isCriminal[100000];
  for (int i = 0; i < n; i++)
  {
    suspects[i] = 0;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    list[i] = temp;
    if (temp < 0)
    {
      negative++;
      suspects[abs(temp) - 1]--;
    }
    else
    {
      suspects[temp - 1]++;
    }
  }
  for (int i = 0; i < n; i++)
  {
    suspects[i] += negative;
    if (suspects[i] == honest)
    {
      isCriminal[i] = true;
      criminal++;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (list[i] > 0)
    {
      if (isCriminal[list[i] - 1])
      {
        if (criminal == 1)
        {
          cout << "Truth" << endl;
        }
        else
        {
          cout << "Not defined" << endl;
        }
      }
      else
      {
        cout << "Lie" << endl;
      }
    }
    else
    {
      if (isCriminal[abs(list[i]) - 1])
      {
        if (criminal == 1)
        {
          cout << "Lie" << endl;
        }
        else
        {
          cout << "Not defined" << endl;
        }
      }
      else
      {
        cout << "Truth" << endl;
      }
    }
  }
  return 0;
}
