#include <iostream>
#include <string>
using namespace std;

void sortString(string &str)
{
  int n = str.length();
  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
    {
      if (str[j] < str[minIndex])
      {
        minIndex = j;
      }
    }
    swap(str[i], str[minIndex]);
  }
}

void reverseString(string &str, int start, int end)
{
  while (start < end)
  {
    swap(str[start], str[end]);
    start++;
    end--;
  }
}

bool notFinished(string &str)
{
  int n = str.length();
  int i = n - 2;
  while (i >= 0 && str[i] >= str[i + 1])
  {
    i--;
  }
  if (i < 0)
  {
    return false;
  }
  int j = n - 1;
  while (str[j] <= str[i])
  {
    j--;
  }
  swap(str[i], str[j]);
  reverseString(str, i + 1, n - 1);
  return true;
}

void generateWords(string letters, int k, int n)
{
  int i = 1;
  string prevWord = "";
  while (notFinished(letters))
  {
    string currentWord = letters.substr(0, k);
    if (currentWord != prevWord)
    {
      if (n == i)
      {
        cout << currentWord << endl;
        break;
      }
      prevWord = currentWord;
      i++;
    }
  }
}

int main()
{
  string letters, newLetters = "";
  cin >> letters;
  int k;
  long long int n;
  cin >> k >> n;
  sortString(letters);

  for (int i = 0; i < letters.length(); i++)
  {
    for (int j = 0; j < k; j++)
    {
      newLetters += letters[i];
    }
  }

  generateWords(newLetters, k, n);

  return 0;
}
