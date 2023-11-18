#include <iostream>
using namespace std;
int main()
{
  long long a1, a2, a3, max = 0, min = 0, i;
  cin >> a1 >> a2;
  while (true)
  {
    cin >> a3;
    if (a3 == (-1))
    {
      cout << min << " " << max << endl;
      return 0;
    }
    if (a2 > a1 && a2 >= a3)
    {
      if (a2 > a3)
      {
        max++;
      }
      else
      {
        i = 2;
        while (true)
        {
          cin >> a3;
          if (a3 == (-1))
          {
            cout << min << " " << max << endl;
            return 0;
          }
          else if (a3 == a2)
          {
            i++;
          }
          else if (a3 < a2)
          {
            max += i;
            break;
          }
          else
          {
            break;
          }
        }
      }
    }
    if (a2 < a1 && a2 <= a3)
    {
      if (a2 < a3)
      {
        min++;
      }
      else
      {
        i = 2;
        while (true)
        {
          cin >> a3;
          if (a3 == (-1))
          {
            cout << min << " " << max << endl;
            return 0;
          }
          else if (a3 == a2)
          {
            i++;
          }
          else if (a3 > a2)
          {
            min += i;
            break;
          }
          else
          {
            break;
          }
        }
      }
    }
    a1 = a2, a2 = a3;
  }
  return 0;
}
