#include <iostream>
#include <string>
using namespace std;

int main()
{
  string w;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cin >> w;
    int count = 0;
    int erase = 0;
    for (int j = w.length() - 1; j >= 0; j--)
    {
      if (w[j] == 'b')
      {
        erase++;
        w[j] = '0';
      }
      else if (erase > 0)
      {
        erase--;
        w[j] = '0';
      }
    }
    for (int j = 0; j < w.length(); j++)
    {
      if (w[j] != '0')
        cout << w[j];
    }
    cout << endl;
  }
  return 0;
}
