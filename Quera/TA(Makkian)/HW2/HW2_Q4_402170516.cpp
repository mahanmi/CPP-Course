#include <iostream>
using namespace std;
int Fibonacci(int n)
{
  int a1 = 1, a2 = 1;
  for (int i = 1; i < n; i++)
  {
    int temp = a2;
    a2 += a1, a1 = temp;
  }
  return a2;
}
int main()
{
  int number;
  cin >> number;
  for (int i = 1; number != 0; i++)
  {
    if (Fibonacci(i) > number)
    {
      number -= Fibonacci(i - 1);
      cout << (i - 1) << " ";
      i = 1;
    }
  }
  return 0;
}
