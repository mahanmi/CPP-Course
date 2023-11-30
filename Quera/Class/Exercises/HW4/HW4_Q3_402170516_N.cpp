#include <iostream>
#define IoFast                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
// #include </Users/mahan/Documents/VS Code/C++/Library/myheader.h>
using namespace std;

void calcAnswer(int productID[], int answers[], int input, int quantity, int max, int ans)
{
  int productID_check[1000000] = {0};
  for (int j = (input - 1); j < quantity; j++)
  {
    if (productID_check[productID[j] - 1] == productID[j])
    {
      ans--;
    }
    else
    {
      productID_check[productID[j] - 1] = productID[j];
    }
  }
  answers[input - 1] = ans;
}

int main()
{
  IoFast;
  int quantity, questions, max = 0, iAns = 0;
  cin >> quantity >> questions;
  int productID[100000];
  int answers[100000] = {0};
  int *productID_check = new int[1000000000];
  int finalPrint[questions];
  for (int i = 0; i < quantity; i++)
  {
    int input;
    cin >> input;
    // productID[i] = input;
    if (productID_check[input - 1] != input)
    {
      productID_check[input - 1] = input;
      for (int j = 0; j <= i; j++)
      {
        answers[j]++;
      }
    }
    else
    {
      answers[i]++;
    }
  }
  for (int i = 0; i < questions; i++)
  {
    int n;
    cin >> n;
    cout << answers[n - 1] << endl;
  }

  // timer(start);
  /*  for (int j = 0; j < questions; j++)
   {
     int input, ans;
     cin >> input;

     ans = quantity - input + 1;
     if (answers[input - 1] == 0)
     {
       calcAnswer(productID, answers, input, quantity, max, ans);
     }
     finalPrint[iAns] = input - 1;
     iAns++;
   }
   for (int i = 0; (i < questions) && !(quantity > 1e2 || questions > 1e2); i++)
   {
     cout << answers[finalPrint[i]] << endl;
   } */
  // timer(stop);
  // cout << "Time taken by function: " << Duration(start, stop) << " milliseconds" << endl;
  return 0;
}
