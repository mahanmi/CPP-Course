#include <iostream>
#include <string>
using namespace std;

int main()
{
  int k, words[26] = {0};
  string s, result = "";
  cin >> k >> s;
  for (int i = 0; i < s.length(); i++)
  {
    words[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
  {
    if (words[i] % k != 0)
    {
      cout << "-1";
      return 0;
    }
    else
    {
      words[i] /= k;
    }
  }
  for (int i = 0; i < 26; i++)
  {
    char c = static_cast<char>(i + 'a');
    for (int j = 0; j < words[i]; j++)
    {
      result += c;
    }
  }
  for (int i = 0; i < k; i++)
  {
    cout << result;
  }

  return 0;
}