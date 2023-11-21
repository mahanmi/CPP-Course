#include <iostream>
using namespace std;
bool isPrime(int n)
{
  for (int i = 2; i < n; i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}
int main()
{
  int a, b;
  bool isFound = false;
  cin >> a >> b;
  for (int i = (a + 1); i < b; i++)
  {
    if (isPrime(i))
    {
      if (isFound)
      {
        cout << "," << i;
      }
      else
      {
        cout << i;
        isFound = true;
      }
    }
  }

  return 0;
}
