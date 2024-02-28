// Question link : https://codeforces.com/problemset/problem/1879/F

#include <iostream>
using namespace std;
int findX(int n, int armor[]);
void defineArrays(int n, int health[], int initialHealth[], int armor[], int initialArmor[], int points[]);
void game(int n, int health[], int initialHealth[], int armor[], int initialArmor[], int damage, int points[]);

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int n;
    cin >> n;
    int health[n], initialHealth[n], armor[n], initialArmor[n], points[n];
    defineArrays(n, health, initialHealth, armor, initialArmor, points);
    int xMax = findX(n, armor);
    for (int x = 1; x <= xMax; x++)
    {
      game(n, health, initialHealth, armor, initialArmor, x, points);
    }
    for (int j = 0; j < n; j++)
    {
      cout << points[j] << " ";
    }
    cout << endl;
  }
  return 0;
}

int findX(int n, int armor[])
{
  int max = 0;
  for (int i = 0; i < n; i++)
  {
    if ((armor[i]) > max)
    {
      max = (armor[i]);
    }
  }
  return max;
}

void defineArrays(int n, int health[], int initialHealth[], int armor[], int initialArmor[], int points[])
{
  int input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    health[i] = input;
    initialHealth[i] = input;
    points[i] = 0;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    armor[i] = input;
    initialArmor[i] = input;
  }
}

void resetGame(int n, int health[], int initialHealth[], int armor[], int initialArmor[])
{
  for (int i = 0; i < n; i++)
  {
    armor[i] = initialArmor[i];
    health[i] = initialHealth[i];
  }
}

void game(int n, int health[], int initalHealth[], int armor[], int initialArmor[], int damage, int points[])
{
  int winner_count = 0;
  bool isEnded = false;
  while (true)
  {
    int alive = 0, i_winner;
    for (int i = 0; (i < n) && (alive < 2); i++)
    {
      if (health[i] > 0)
      {
        alive++;
        i_winner = i;
      }
    }
    if (alive == 1)
    {
      winner_count++;
    }
    else if (alive == 0)
    {
      if (winner_count > 0)
      {
        if (winner_count > points[i_winner])
        {
          points[i_winner] = winner_count;
        }
      }
      resetGame(n, health, initalHealth, armor, initialArmor);
      break;
    }
    for (int i = 0; i < n; i++)
    {
      if (health[i] > 0)
      {
        if (armor[i] <= damage)
        {
          armor[i] = initialArmor[i];
          health[i]--;
        }
        else
        {
          armor[i] -= damage;
        }
      }
    }
  }
}
