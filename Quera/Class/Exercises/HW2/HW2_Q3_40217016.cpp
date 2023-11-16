#include <iostream>
using namespace std;
int main()
{
  long count, day = 0, a, page = 0;
  cin >> count;
  for (size_t i = 1; i <= count; i++)
  {
    cin >> a;
    if (a > page)
    {
      if (page >= i)
      {
        page = a;
      }
      else
      {
        page = a, day++;
      }
    }
  }
  cout << day << endl;
  return 0;
}
