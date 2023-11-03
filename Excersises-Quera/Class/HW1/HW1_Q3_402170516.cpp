#include <iostream>
using namespace std;
int main()
{
  long a, n, k, total, ans;
  cin >> k >> n >> a;
  total = ((a + 1) * (a)) / 2 * k;
  ans = total - n;
  if (ans < 0)
  {
    std::cout << "0" << std::endl;
  }
  else
  {
    std::cout << ans << std::endl;
  }
  return 0;
}
