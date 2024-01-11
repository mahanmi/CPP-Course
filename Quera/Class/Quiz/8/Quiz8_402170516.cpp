#include <iostream>
using namespace std;

unsigned long long int fibonacci(unsigned long long int n)
{
  if (n <= 1)
  {
    return n;
  }
  else
  {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

unsigned long long int factorial(unsigned long long int n)
{
  if (n == 0)
  {
    return 1;
  }
  else
  {
    return fibonacci(n) * factorial(n - 1);
  }
}

int main()
{
  int n;
  cin >> n;
  cout << factorial(n) << endl;
  return 0;
}
