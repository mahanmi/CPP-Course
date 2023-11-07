#include <iostream>
using namespace std;
int main()
{
  long amount, a, b, c, n_peak = 0, n_valley = 0;
  cin >> amount >> a >> b;
  for (int i = 3; i <= amount; i++)
  {
    cin >> c;
    if (b > a && b > c)
    {
      if (n_valley != 0 || n_peak != 0)
      {
        n_peak = i - 2;
        std::cout << "      " << n_peak;
      }
      else
      {
        n_peak = i - 2;
        std::cout << n_peak;
      }
    }
    else if (b < a && b < c)
    {

      if (n_valley != 0 || n_peak != 0)
      {
        n_valley = i - 2;
        std::cout << "      " << n_valley;
      }
      else
      {
        n_valley = i - 2;
        std::cout << n_valley;
      }
    }
    a = b, b = c;
  }
  if (n_valley == 0 && n_peak == 0)
  {
    cout << "Null";
  }
  return 0;
}
