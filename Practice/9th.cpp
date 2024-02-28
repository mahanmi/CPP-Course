#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
  int n;
  cout << "Enter the size of the array: ";
  cin >> n;

  int array[n];
  cout << "Enter " << n << " elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> array[i];
  }

  int array0[] = array[];

  cout << "Array elements: ";
  for (int i = 0; i < n; i++)
  {
    cout << array0[i] << " ";
  }

  return 0;
}
