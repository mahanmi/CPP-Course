#include <iostream>
#include "SDL_Headers.h"
using namespace std;

void drawLine(SDL_Renderer *Renderer, double &x, double &y, int L, int angle, int width, int R, int G, int B)
{
  double theta = angle * M_PI / 180;
  double x_2 = x + L * cos(theta), y_2 = y + L * sin(theta);
  thickLineRGBA(Renderer, x, y, x_2, y_2, width, R, G, B, 255);
  x = x_2, y = y_2;
}

string fractal(int n)
{
  if (n <= 1)
  {
    string axiom = "F- -F- -F";
    return axiom;
  }
  else
  {
    string d = "F+F- -F+F";
    string result = fractal(n - 1);
    for (int i = 0; i < result.length(); i++)
    {
      if (result[i] == 'F')
      {
        result.replace(i, 1, d);
        i += d.length();
      }
    }
    return result;
  }
}

int main(int argc, char const *argv[])
{
  int WIDTH = 960, HEIGHT = 960;
  // Initialize SDL
  SDL_Window *window = SDL_CreateWindow(
      "HW7_Q1",                // Window title
      SDL_WINDOWPOS_UNDEFINED, // Initial x position
      SDL_WINDOWPOS_UNDEFINED, // Initial y position
      WIDTH,                   // Width, in pixels
      HEIGHT,                  // Height, in pixels
      SDL_WINDOW_SHOWN         // Flags
  );
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_Event event;
  // End of initialization
  int n;
  double angle = 0, x = WIDTH / 8, y = HEIGHT * 3 / 4;
  cin >> n;
  double L = (50 / pow(2, n - 1)) + 1, W = 5 / n + 1;
  string ANS = fractal(n);

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);

  for (size_t i = 0; i < ANS.length(); i++)
  {
    switch (ANS[i])
    {
    case ' ':
      break;

    case 'F':
      drawLine(renderer, x, y, L, angle, W, 0, 0, 0);
      break;

    case '+':
      angle += 60;
      break;

    case '-':
      angle -= 60;
      break;
    }
  }
  SDL_RenderPresent(renderer);
  bool running = true;
  while (running)
  {
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
        running = false;
      }
      if (event.type == SDL_KEYDOWN)
      {
        int key = event.key.keysym.sym;
        if (key == SDLK_ESCAPE)
          running = false;
      }
    }
  }
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  return 0;
}