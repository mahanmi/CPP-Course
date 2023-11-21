#include <iostream>
#include <math.h>
using namespace std;
int sumDigits(long long number)
{
  int sum = 0;
  while (number > 0)
  {
    sum += (number % 10);
    number /= 10;
  }
  return sum;
}
int main()
{
  long long m, s, min = 1e18, max = 0;
  bool isMinFound = false, isMaxFound = false;
  cin >> m >> s;
  long long from = pow(10, (m - 1)), to = pow(10, m);
  for (long long i = from - 1; i < to; i++)
  {
    if (sumDigits(i) == s)
    {
      cout << i << " ";
      isMinFound = true;
      break;
    }
  }
  for (long long i = (to - 1); i >= from - 1; i--)
  {
    if (sumDigits(i) == s)
    {
      cout << i;
      isMaxFound = true;
      break;
    }
  }
  if (!(isMinFound || isMaxFound))
    cout << "-1 -1";
  return 0;
}
