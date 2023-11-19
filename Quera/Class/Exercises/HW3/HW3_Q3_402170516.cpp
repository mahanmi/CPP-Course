#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(long long number);
bool hasExtremum(long long number);
long sum3(long a, long b, long c);
void reset(long long &a, long long &b, long long &c);
int main()
{
  long long n, number, P_count = 0, E_count = 0, longest = 0, both = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> number;
    if (hasExtremum(number) || isPalindrome(number))
    {
      if (hasExtremum(number) && isPalindrome(number))
      {
        both++;
      }
      else if (hasExtremum(number))
      {
        E_count++;
      }
      else
      {
        P_count++;
      }
    }
    if ((sum3(P_count, E_count, both) > longest) && ((P_count > 0 && E_count > 0) || both > 0))
    {
      longest = sum3(P_count, E_count, both);
    }
    if (!(hasExtremum(number) || isPalindrome(number)))
    {
      reset(P_count, E_count, both);
    }
  }
  cout << longest;
  return 0;
}
long countDigits(long long number)
{
  string strNumber = to_string(number);
  long long digitCount = strNumber.length();
  return digitCount;
}
bool isPalindrome(long long number)
{
  string strNumber = to_string(number);
  string reversedNumber(strNumber.rbegin(), strNumber.rend());
  if (strNumber == reversedNumber)
  {
    return true;
  }
  return false;
}
bool hasMax(long long number)
{
  long long max = 0;
  string strNumber = to_string(number);
  long long count = countDigits(number);
  for (long i = 0; i < count - 1; i++)
  {
    if (strNumber[i + 1] >= strNumber[i])
    {
      max = i + 1;
    }
    else
    {
      break;
    }
  }
  for (long i = max; i < count - 1; i++)
  {
    if (strNumber[i + 1] > strNumber[i])
    {
      return false;
    }
  }
  return true;
}
bool hasMin(long long number)
{
  long long min = 0;
  string strNumber = to_string(number);
  long long count = countDigits(number);
  for (long i = 0; i < count - 1; i++)
  {
    if (strNumber[i + 1] <= strNumber[i])
    {
      min = i + 1;
    }
    else
    {
      break;
    }
  }
  for (long i = min; i < count - 1; i++)
  {
    if (strNumber[i + 1] < strNumber[i])
    {
      return false;
    }
  }
  return true;
}
bool hasExtremum(long long number)
{
  if (hasMin(number) || hasMax(number))
  {
    return true;
  }
  return false;
}
long sum3(long a, long b, long c)
{
  return a + b + c;
}
void reset(long long &a, long long &b, long long &c)
{
  a = 0, b = 0, c = 0;
}