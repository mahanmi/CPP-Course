#include <iostream>
#include <sstream>
using namespace std;

int main()
{
  string input;
  double ans, num1, num2, num3;
  getline(cin, input);
  std::cout << "START" << std::endl;
  istringstream numbers(input);
  numbers >> num1 >> num2 >> num3;
  if (numbers.fail())
  {
    std::cout << "Invalid input" << std::endl;
  }
  else
  {
    ans = num1 + num2 + num3;
    std::cout << ans << std::endl;
  }
  std::cout << "end" << std::endl;
  return 0;
}