#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  int input, x, y;
  float total, n;
  n = 0;
  total = 0;
  while (input != 0)
  {
    cin >> input;
    if (input == 0)
    {
      std::cout << setprecision(2) << fixed << std::endl;
      std::cout << total / n << std::endl;
    }
    else
    {
      n += 1;
      x = input;
      total = x + total;
    }
  }
  return 0;
}
