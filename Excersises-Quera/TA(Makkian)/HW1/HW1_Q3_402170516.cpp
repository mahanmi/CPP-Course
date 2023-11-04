#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  double m1, m2, x1, x2, y1, y2, c1, c2, X, Y;
  std::cout << setprecision(2) << fixed << std::endl;
  cin >> m1 >> x1 >> y1;
  cin >> m2 >> x2 >> y2;
  c1 = y1 - x1 * m1;
  c2 = y2 - x2 * m2; // m1-m2*x +  =  + c2 - c1
  X = (c2 - c1) / (m1 - m2);
  Y = m1 * X + c1;
  std::cout << X << std::endl
            << Y << endl;
  return 0;
}
