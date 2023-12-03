#include <iostream>
using namespace std;
int main()
{
  int n, count, temp;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> count;
    int zeroCount = 0, oneCount = 0;
    for (int j = 0; j < count; j++)
    {
      cin >> temp;
      if (temp == 1)
      {
        oneCount++;
      }
    }
    zeroCount = count - oneCount;
    if (zeroCount >= oneCount)
    {
      cout << ((count + 1) / 2) << endl;
      for (int j = 0; j < ((count + 1) / 2); j++)
      {
        cout << "0 ";
      }
    }
    else
    {
      if (count % 4 != 0)
      {
        cout << ((count + 3) / 2) << endl
             << "1 ";
      }
      else
      {
        cout << ((count + 1) / 2) << endl;
      }
      for (int j = 0; j < ((count + 1) / 2); j++)
      {
        cout << "1 ";
      }
    }
    cout << endl;
  }

  return 0;
}
