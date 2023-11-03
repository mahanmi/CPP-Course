#include <iostream>
#include <sstream>
using namespace std;
int main()
{
  int n, m, k;
  string args;
  getline(cin, args);
  istringstream nmk(args);
  nmk >> n >> m >> k;
  int quantity_x = (n + k - 1) / k; // Round up division for x
  int quantity_y = (m + k - 1) / k; // Round up division for y
  cout << quantity_x * quantity_y << endl;
  return 0;
}
