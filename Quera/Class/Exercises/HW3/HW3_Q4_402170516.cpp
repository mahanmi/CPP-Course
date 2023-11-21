#include <iostream>
using namespace std;
void hashtag_printer(int n);
void line_printer(int h, int n);
void line_printer_inverse(int h, int n);
int main()
{
  int n, h, x = 0;
  cin >> n >> h;
  int line_count = (n * (h - 1) + 1);
  for (int i = 0; i < line_count; i++)
  {
    if (i % (h - 1) == 0)
    {
      hashtag_printer(line_count);
    }
    else if (x == 0)
    {
      x++;
      for (int j = 1; j < (h - 1); j++, i++)
      {
        line_printer(h, n);
      }
      i--;
    }
    else
    {
      x--;
      for (int j = 1; j < (h - 1); j++, i++)
      {
        line_printer_inverse(h, n);
      }
      i--;
    }
  }
  return 0;
}
void hashtag_printer(int n)
{
  for (int i = 0; i < n; i++)
    if (i != (n - 1))
    {
      cout << "# ";
    }
    else
    {
      cout << "#";
    }

  cout << endl;
}
void line_printer(int h, int n)
{
  for (int i = 0; i < n / 2; i++)
  {
    for (int j = 0; j < h; j++)
    {
      cout << "# ";
    }
    for (int j = 0; j < h - 2; j++)
    {
      cout << "  ";
    }
  }
  if (n % 2 == 0)
  {
    cout << "#" << endl;
  }
  else
  {
    for (int j = 0; j < h; j++)
    {
      cout << "# ";
    }
    cout << endl;
  }
}
void line_printer_inverse(int h, int n)
{
  cout << "# ";
  for (int i = 0; i < n / 2; i++)
  {
    for (int j = 0; j < h - 2; j++)
    {
      cout << "  ";
    }
    for (int j = 0; j < h; j++)
    {
      cout << "# ";
    }
  }
  if (n % 2 != 0)
  {
    for (int j = 0; j < h - 2; j++)
    {
      cout << "  ";
    }
    cout << "#";
  }

  cout << endl;
}
