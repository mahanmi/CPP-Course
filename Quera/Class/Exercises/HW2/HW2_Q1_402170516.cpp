#include <iostream>
using namespace std;
int main()
{
  long n, a1 = 1, a2 = 1, a3;
  cin >> n;
  if (n < 3)
  {
    if (n > 0)
    {
      cout << 1 << endl;
    }
    else
    {
      cout << 0 << endl;
    }
    return 0;
  }
  for (size_t i = 2; i < n; i++)
  {
    a3 = a1 + a2;
    a1 = a2;
    a2 = a3;
  }
  cout << a3 << endl;
  return 0;
}
