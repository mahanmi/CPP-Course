#include "iostream"
int main(int argc, char const *argv[])
{
  double x = 10;
  double y = 5;
  double z = (x + 10) / (3 * y);
  std::cout << "x = " << x << " ";
  std::cout << "y = " << y << std::endl;
  std::cout << "z = " << z << std::endl;
  return 0;
}
