#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  bool isNew[100000] = {false};
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    if (isNew[temp] == false)
    {
      isNew[temp] = true;
      cout << temp << " ";
    }
  }

  return 0;
}
