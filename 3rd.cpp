#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
  int a = 5;
  int b = 6;
  int tmp = a;
  a = b;
  b = tmp;
  cout << "a = " << a << endl;
  return 0;
}