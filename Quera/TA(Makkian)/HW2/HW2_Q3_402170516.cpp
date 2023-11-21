#include <iostream>
#include <string>
using namespace std;
int main()
{
  long number;
  cin >> number;
  string strNumber = to_string(number), reversedNumber(strNumber.rbegin(), strNumber.rend());
  if (strNumber == reversedNumber)
  {
    std::cout << "YES" << std::endl;
  }
  else
  {
    std::cout << "NO" << std::endl;
  }

  return 0;
}
