#include <iostream>
#define IoFast                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
using namespace std;
int main()
{
  IoFast;
  int products, questions;
  cin >> products >> questions;
  int answers[100000] = {0};
  int productID[100000];
  int finalPrint[questions];
  for (int i = 0; i < products; i++)
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
    int input;
    cin >> input;
    cout << answers[input - 1] << endl;
  }
  return 0;
}
