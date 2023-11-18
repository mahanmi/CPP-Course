#include <iostream>
using namespace std;
void string_multiply(int n, string ch);
int main()
{
  string l1 = "__________  ", l2 = "|        |  ", l3 = "|  ____  |  ", l4 = "|  |  |  |  ", l5 = "|  |  |__|  ", l6 = "|  |        ", l7 = "|  |________";
  long n;
  cin >> n;
  string_multiply(n, l1);
  string_multiply(n, l2);
  string_multiply(n, l3);
  string_multiply(n, l4);
  string_multiply(n, l5);
  string_multiply(n, l6);
  string_multiply(n, l7);
  return 0;
}
void string_multiply(int n, string ch)
{
  for (size_t i = 0; i < n; i++)
  {
    cout << ch;
  }
  cout << endl;
}
