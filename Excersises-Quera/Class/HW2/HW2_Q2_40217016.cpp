#include <iostream>
using namespace std;
int main()
{
  int n, temp, police = 0, crime = 0;
  cin >> n;
  for (size_t i = 0; i < n; i++)
  {
    cin >> temp;
    if (temp > 0)
    {
      police += temp;
    }
    else if (police > 0)
    {
      police--;
    }
    else
    {
      crime++;
    }
  }
  cout << crime << endl;

  return 0;
}