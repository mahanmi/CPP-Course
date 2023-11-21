#include <iostream>
#include <math.h>
using namespace std;
int num_length(int n);
int sum_number(int n);
int main()
{
  int m, s, min = 1e9, max = 0;
  bool isFound = false;
  cin >> m >> s;
  for (int i = pow(10, (m - 1)); i < pow(10, m); i++)
  {
    if (sum_number(i) == s)
    {
      isFound = true;
      if (i > max)
        max = i;
      if (i < min)
        min = i;
    }
  }
  if (isFound)
    cout << min << " " << max << endl;
  else
    cout << "-1 -1" << endl;
  return 0;
}

int num_length(int n)
{
  int length = log10(n) + 1;
  return length;
}

int sum_number(int n)
{
  int sum = 0;
  while (n > 0)
  {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}