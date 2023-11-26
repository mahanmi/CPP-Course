#include <iostream>
using namespace std;
int main()
{
  int lamp, sticks;
  cin >> lamp >> sticks;
  int lampArray[lamp];
  for (int i = 0; i < (lamp); i++)
  {
    lampArray[i] = 0;
  }
  for (int i = 0; i < sticks; i++)
  {
    int input;
    cin >> input;
    for (int i = (input - 1); i < lamp; i++)
    {
      if (lampArray[i] == 0)
      {
        lampArray[i] = input;
      }
    }
  }
  for (int i = 0; i < (lamp); i++)
  {
    cout << lampArray[i] << " ";
  }

  return 0;
}
