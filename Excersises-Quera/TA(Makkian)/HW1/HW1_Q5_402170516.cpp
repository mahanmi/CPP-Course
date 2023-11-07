#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  long input, x, y;
  double total, n;
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
      total = input + total;
    }
  }
  return 0;
}
