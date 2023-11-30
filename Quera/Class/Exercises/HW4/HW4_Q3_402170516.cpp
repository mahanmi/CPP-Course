#include <iostream>
#define IoFast                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#include </Users/mahan/Documents/VS Code/C++/Library/myheader.h>
using namespace std;
/* void sortArray(int a[], int from, int to)
{
  bool changed = true;
  for (int i = to - 1; (i > 0) && (changed); i--)
  {
    changed = false;
    for (int j = (from - 1); j < i; j++)
      if (a[j] > a[j + 1])
      {
        swap(a[j], a[j + 1]);
        changed = true;
      }
  }
} */
int main()
{
  IoFast;
  int quantity, questions, iAns = 0;
  cin >> quantity >> questions;
  int *productID = new int[quantity];
  int *productID_sorted = new int[quantity];
  int *answers = new int[questions];
  //// int productID[quantity], productID_sorted[quantity], answers[questions];
  for (int i = 0; i < quantity; i++)
  {
    int input;
    cin >> input;
    productID[i] = input;
    productID_sorted[i] = input;
  }
  timer(start);
  for (int j = 0; j < questions; j++)
  {
    int i, ans = 1;
    cin >> i;
    sortArray(productID_sorted, i, quantity);
    for (int j = (i - 1); j < quantity; j++)
    {
      if (productID_sorted[j] < productID_sorted[j + 1])
      {
        ans++;
      }
    }
    answers[iAns] = ans;
    iAns++;
    //// memcpy(productID_sorted, productID, quantity * sizeof(int));
    for (int j = (i - 1); j < quantity; j++)
    {
      productID_sorted[j] = productID[j];
    }
  }
  for (int i = 0; i < questions; i++)
  {
    cout << answers[i] << endl;
  }

  timer(stop);
  cout << "Time taken by function: " << Duration(start, stop) << " milliseconds" << endl;
  return 0;
}
