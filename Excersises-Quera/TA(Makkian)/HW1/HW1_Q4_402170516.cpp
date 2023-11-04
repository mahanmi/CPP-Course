#include <iostream>
#include <iomanip>
using namespace std;
float inverse(float a, float det)
{
  return (1 / det) * a;
}
int main()
{
  float a11, a12, a21, a22, det;
  cin >> a11 >> a12;
  cin >> a21 >> a22;
  det = a11 * a22 - a12 * a21;
  cout << setprecision(2) << fixed << endl;
  cout << inverse(a22, det) << " " << inverse(-a12, det) << endl;
  cout << inverse(-a21, det) << " " << inverse(a11, det) << endl;
  return 0;
}
