#include <iostream>
#include <math.h>
using namespace std;
int main()
{
  long long n, x1, x2, a, b, c, temp;
  cin >> n >> x1 >> x2;
  if (x2 < x1)
  {
    temp = x2, x2 = x1, x1 = temp;
  }
  a = x1, b = x2 - x1, c = n - x2;
  if ((abs(c - a) < b && b < abs(c + a)) && (abs(b - a) < c && c < abs(b + a)) && (abs(c - b) < a && a < abs(c + b)))
  {
    std::cout << "YES" << std::endl;
  }
  else
  {
    std::cout << "NO" << std::endl;
  }
  return 0;
}
