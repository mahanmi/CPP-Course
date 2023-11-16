#include <iostream>
#include <sstream>

bool get_args(int &n, int &m, int &k)
{
  std::string args;
  getline(std::cin, args);
  std::istringstream nmk(args);
  nmk >> n >> m >> k;
  return (1 <= m && m <= 1e9 && 1 <= n && n <= 1e9 && 1 <= k && k <= 1e9);
}

int get_ans(int n, int m, int k)
{
  int quantity_x = (n + k - 1) / k; // Round up division for x
  int quantity_y = (m + k - 1) / k; // Round up division for y

  return quantity_x * quantity_y;
}

int main()
{
  int n, m, k;
  if (!get_args(n, m, k))
  {
    std::cout << "Invalid Input" << std::endl;
    return 1;
  }
  else
  {
    std::cout << get_ans(n, m, k) << std::endl;
  }
  return 0;
}
