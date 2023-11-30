#include <iostream>
#define IoFast                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
using namespace std;
int main()
{
  IoFast;

  int quantity, questions;
  cin >> quantity >> questions;
  int answers[100000] = {0};
  int productID[100000];
  int productID_check[1000000];
  int finalPrint[questions];
  for (int i = 0; i < quantity; i++)
  {
    int input;
    cin >> input;
    productID[i] = input;
    answers[i]++;
    int j = i - 1;
    while ((productID[j] != input) && (j >= 0))
    {
      answers[j]++;
      j--;
    }
  }
  for (int i = 0; i < questions; i++)
  {
    cin >> finalPrint[i];
  }
  for (int i = 0; i < questions; i++)
  {
    cout << answers[finalPrint[i] - 1] << endl;
  }
  return 0;
}
