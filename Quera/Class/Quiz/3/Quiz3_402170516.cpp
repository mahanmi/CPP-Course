#include <iostream>
#include <cmath>
using namespace std;

void swap(double &a, double &b)
{
  double temp;
  temp = a;
  a = b;
  b = temp;
}
void sort(double &a, double &b, double &c)
{
  for (int i = 0; i < 2; i++)
  {
    if (a > b)
    {
      swap(a, b);
    }
    if (c < b)
    {
      swap(b, c);
    }
  }
}
void sortInverse(double &a, double &b, double &c)
{
  for (int i = 0; i < 2; i++)
  {
    if (a < b)
    {
      swap(a, b);
    }
    if (c > b)
    {
      swap(b, c);
    }
  }
}
bool areEqual(double r1, double r2, double r3)
{
  if (r1 == r2 || r2 == r3)
  {
    return true;
  }
  return false;
}
int calculateScore(long long int x, long long int y, double r1, double r2, double r3, int score1, int score2, int score3)
{
  int score = 0;
  if (sqrt(x * x + y * y) <= r1)
  {
    score += score1;
  }
  else if (sqrt(x * x + y * y) <= r2)
  {
    score += score2;
  }
  else if (sqrt(x * x + y * y) <= r3)
  {
    score += score3;
  }
  return score;
}

int main()
{
  double r1, r2, r3, k, score1, score2, score3;
  int n;
  long long int finalScore = 0;
  cin >> r1 >> r2 >> r3;
  sort(r1, r2, r3);
  cin >> score1 >> score2 >> score3;
  sortInverse(score1, score2, score3);
  cin >> k;
  k /= r1;
  r1 *= k, r2 *= k, r3 *= k;
  // cout << r1 << " " << r2 << " " << r3 << endl;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    long long int x, y;
    cin >> x >> y;
    finalScore += calculateScore(x, y, r1, r2, r3, score1, score2, score3);
  }
  if (areEqual(r1, r2, r3))
  {
    cout << "error";
    return 0;
  }
  else
  {
    cout << finalScore;
  }
  return 0;
}
