#include <iostream>
using namespace std;
int main()
{
  int products, questions, answer = 0;
  cin >> products >> questions;
  int answers[100000] = {0};
  bool isDifferent[100000];
  int productID[products];
  for (int i = 0; i < products; i++)
  {
    cin >> productID[i];
  }
  for (int i = products - 1; i >= 0; i--)
  {
    if (!(isDifferent[productID[i] - 1]))
    {
      isDifferent[productID[i] - 1] = true;
      answer++;
    }
    answers[i] = answer;
  }
  for (int i = 0; i < questions; i++)
  {
    int input;
    cin >> input;
    cout << answers[input - 1] << endl;
  }
  return 0;
}
