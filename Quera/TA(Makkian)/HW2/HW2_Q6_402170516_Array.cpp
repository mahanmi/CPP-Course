#include <iostream>
using namespace std;
int main()
{
  int n, a = 1, j = 0, removedCandidates = 0;
  bool mirj = true;
  cin >> n;
  int Candidate[n];
  for (int i = 0; i < n; i++)
  {
    Candidate[i] = (i + 1);
    //  cout << Candidate[i] << " ";
  }
  while (removedCandidates < (n - 1))
  {
    a = a % n;
    if (Candidate[a] == 0)
    {
      a += 1;
    }
    else
    {
      if (mirj)
      {
         cout << Candidate[a] << "Got Removed" << endl;
        Candidate[a] = 0;
        removedCandidates++;
        mirj = false;
        a += 1;
      }
      else
      {
        mirj = true;
        a += 1;
      }
    }
  }
  while (Candidate[j] == 0)
  {
    j += 1;
  }
  cout << Candidate[j];
  return 0;
}
