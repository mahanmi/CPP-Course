#include <iostream>
#include <sstream>
#include <cmath>

bool get_coordinate(int &x, int &y)
{
  std::string input;
  getline(std::cin, input);
  std::istringstream coordinate(input);
  if (coordinate.fail())
  {
    return false;
  }
  else
  {
    coordinate >> x;
    coordinate >> y;
    if (1 <= x && x <= 100000 && 1 <= y && y <= 100000)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}
void calculate_side(int x1, int y1, int x2, int y2, float &side)
{
  side = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
int main()
{
  int x1, y1, x2, y2, x3, y3;
  float s, a1, a2, a3, p;
  if (get_coordinate(x1, y1) == false || get_coordinate(x2, y2) == false || get_coordinate(x3, y3) == false)
  {
    std::cout << "Invalid Input" << std::endl;
    return 0;
  }
  calculate_side(x1, y1, x2, y2, a1);
  calculate_side(x2, y2, x3, y3, a2);
  calculate_side(x1, y1, x3, y3, a3);
  p = (a1 + a2 + a3) / 2;
  s = sqrt(p * (p - a1) * (p - a2) * (p - a3));
  std::cout << s << std::endl;
  return 0;
}
