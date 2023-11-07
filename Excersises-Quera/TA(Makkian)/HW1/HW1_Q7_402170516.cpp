#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  double g1, g2, g3, g4, g5, a1, a2, a3, a4, a5;
  double w1, w2, w3, w4, w5, GPA;
  cin >> g1 >> g2 >> g3 >> g4 >> w1 >> w2 >> w3 >> w4 >> w5 >> GPA;
  a1 = g1 * w1;
  a2 = g2 * w2;
  a3 = g3 * w3;
  a4 = g4 * w4;
  g5 = (GPA * (w1 + w2 + w3 + w4 + w5) - (a1 + a2 + a3 + a4)) / w5;
  cout << setprecision(1) << fixed << endl;
  if (g5 <= 20 && g5 > 0)
  {
    cout << g5 << endl;
  }
  else if (g5 > 20)
  {
    cout << "Sorry! Ishala terme baad!" << endl;
  }
  else if (g5 <= 0)
  {
    cout << "Afarin! Darskhoone ki boodi to?" << endl;
  }

  return 0;
}
