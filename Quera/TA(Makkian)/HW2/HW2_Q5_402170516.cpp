#include <iostream>
using namespace std;
unsigned long long factorial(int n)
{
  unsigned long long answer = 1;
  for (int i = 1; i <= n; i++)
  {
    answer *= i;
  }
  return answer;
}
unsigned long long comb3(int a, int b, int c, int d)
{
  unsigned long long answer = 1;
  int max = 0;
  if (b > max)
    max = b;
  if (c > max)
    max = c;
  if (d > max)
    max = d;
  for (int i = a; i > max; i--)
  {
    answer *= i;
  }
  if (max == b)
  {
    answer /= (factorial(c) * factorial(d));
  }
  else if (max == c)
  {
    answer /= (factorial(b) * factorial(d));
  }
  else
  {
    answer /= (factorial(b) * factorial(c));
  }
  return answer;
}
int main()
{
  long long number, ans = 0;
  cin >> number;
  for (long long i = 0; i <= number; i += 5)
  {
    for (long long j = 0; j <= number; j += 2)
    {
      long long k = number - (i + j);
      if (k < 0)
      {
        break;
      }
      ans += comb3((i / 5 + j / 2 + k), k, (j / 2), (i / 5));
      int count = comb3((i / 5 + j / 2 + k), k, (j / 2), (i / 5));
      // cout << "i = " << i << " j = " << j << " k = " << k << " , " << count << " cases" << endl;
    }
  }
  cout << ans;
  return 0;
}
