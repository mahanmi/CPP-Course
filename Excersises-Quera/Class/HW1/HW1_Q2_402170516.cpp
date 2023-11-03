#include <iostream>
using namespace std;
int main()
{
  int distance, ans;
  cin >> distance;
  if (distance % 5 == 0)
  {
    ans = distance / 5;
  }
  else
  {
    ans = (distance / 5) + 1;
  }
  std::cout << ans << std::endl;
  return 0;
}
