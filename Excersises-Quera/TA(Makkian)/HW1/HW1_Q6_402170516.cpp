#include <iostream>
using namespace std;
int main()
{
  int amount, a, b, c, peak = 0, valley = 0;
  cin >> amount;
  cin >> a >> b;
  for (int i = 2; i < amount; i++)
  {
    cin >> c;
    if (b > a && b > c)
    {
      if (peak == 0 && valley == 0)
      {
        peak = i - 1;
        cout << peak;
      }
      else
      {
        peak = i - 1;
        cout << "       " << peak;
      }
    }
    else if (b < a && b < c)
    {
      if (peak == 0 && valley == 0)
      {
        valley = i - 1;
        cout << valley;
      }
      else
      {
        valley = i - 1;
        cout << "       " << valley;
      }
    }
    a = b, b = c;
  }
  if (valley == 0 && peak == 0)
  {
    std::cout << "Null" << std::endl;
  }
  return 0;
}
