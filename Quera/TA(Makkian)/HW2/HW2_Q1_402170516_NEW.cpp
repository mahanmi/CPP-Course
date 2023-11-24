#include <iostream>
using namespace std;

void printMin(int m, int s);
void printMax(int m, int s);

int main()
{
  // while (true)
  {
    int m, s;
    cin >> m >> s;
    if ((s <= (m * 9)) && (s > 0))
    {
      printMin(m, s);
      cout << " ";
      printMax(m, s);
    }
    else if (s == 0 && m == 1)
    {
      cout << "0 0";
    }
    else
    {
      cout << "-1 -1";
    }
    cout << endl;
  }
  return 0;
}

void printMin(int m, int s)
{
  int left, between = -1, zero;
  int nines = (s - 1) / 9;
  if ((m - nines) == 1)
  {
    left = s - (nines * 9);
    zero = 0;
  }
  else
  {
    between = (s - 1) % 9;
    left = 1;
    zero = m - (nines + 2);
  }
  cout << left;
  for (int i = 0; i < zero; i++)
  {
    cout << "0";
  }
  if (between >= 0)
  {
    cout << between;
  }
  for (int i = 0; i < nines; i++)
  {
    cout << "9";
  }
}

void printMax(int m, int s)
{
  int between = 0, zero;
  int nines = (s - 1) / 9;
  if ((m - nines) == 1)
  {
    between = s - (nines * 9);
    zero = 0;
  }
  else
  {
    between = (s) % 9;
    zero = m - (nines + 1);
  }
  for (int i = 0; i < nines; i++)
  {
    cout << "9";
  }
  if (between != 0)
  {
    cout << between;
  }
  for (int i = 0; i < zero; i++)
  {
    cout << "0";
  }
}