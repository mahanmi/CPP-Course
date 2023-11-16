#include <iostream>
int main()
// 3x + 7y = quantity
{
  long long quantity, r7, r3, x, y;
  std::cin >> quantity;
  r7 = quantity % 7;
  r3 = quantity % 3;
  x = (quantity - (7 * r3)) / 3;
  if (x >= 0)
  {
    std::cout << "YES" << std::endl;
  }
  else
  {
    std::cout << "NO" << std::endl;
  }
  return 0;
}
