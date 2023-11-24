#include <iostream>
using namespace std;
int main()
{
  int n, count, max = 0, iMax, temp;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> temp;
    if (temp > max)
    {
      max = temp, iMax = i;
    }
    else if (temp == max)
    {
      cout << "full";
      return 0;
    }
  }
  cout << iMax;
  return 0;
}
