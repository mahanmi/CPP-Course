#include <iostream>
#include <string>
#include <cmath>
#include "SDL_Headers.h"
using namespace std;
void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void rect(SDL_Renderer *Renderer, int x, int y, int w, int h, int R, int G, int B, bool fill);
void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, bool fill);
void my_line(SDL_Renderer *Renderer, int x_1, int y_1, int L, double theta, int width, int R, int G, int B);
int main()
{
  // I have put this comments by my self to understand what this parts do
  int W = 960; // window width
  int L = 960; // window length
  Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER;
  Uint32 WND_flags = SDL_WINDOW_SHOWN; //| SDL_WINDOW_FULL_SCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
  SDL_Window *m_window;
  SDL_Renderer *m_renderer;
  SDL_Init(SDL_flags);
  SDL_CreateWindowAndRenderer(L, W, WND_flags, &m_window, &m_renderer);
  // Pass the focus to the drawing window
  SDL_RaiseWindow(m_window);
  // Get screen resolution
  SDL_DisplayMode DM;
  SDL_GetCurrentDisplayMode(0, &DM);
  // end of initialization
  int n, L_rect;
  cin >> n >> L_rect;
  window_color(m_renderer, 255, 255, 255);
  SDL_Event *event = new SDL_Event();
  for (int i = 0; i < n; i++)
  {
    ellipse(m_renderer, W / 2, L / 2, (L_rect / 2) / pow(sqrt(2), i), (L_rect / 2) / pow(sqrt(2), i), 0, 0, 0, 0);
    if (i % 2 == 0)
    {
      rect(m_renderer, (W / 2) - ((L_rect / 2) / pow(sqrt(2), i)), (L / 2) - ((L_rect / 2) / pow(sqrt(2), i)), L_rect / pow(2, i / 2), L_rect / pow(2, i / 2), 0, 0, 0, 0);
    }
    else
    {
      my_line(m_renderer, L / 2, W / 2 + (L_rect / 2) / pow(sqrt(2), i - 1), L_rect / pow(sqrt(2), (i)), M_PI / 4, 1, 0, 0, 0);
      my_line(m_renderer, L / 2, W / 2 + (L_rect / 2) / pow(sqrt(2), i - 1), L_rect / pow(sqrt(2), (i)), M_PI * 3 / 4, 1, 0, 0, 0);
      my_line(m_renderer, L / 2, W / 2 - (L_rect / 2) / pow(sqrt(2), i - 1), L_rect / pow(sqrt(2), (i)), M_PI * 5 / 4, 1, 0, 0, 0);
      my_line(m_renderer, L / 2, W / 2 - (L_rect / 2) / pow(sqrt(2), i - 1), L_rect / pow(sqrt(2), (i)), M_PI * 7 / 4, 1, 0, 0, 0);
    }
  }
  SDL_RenderPresent(m_renderer);
  while (true)
  {
    while (SDL_PollEvent(event))
    {
      if (event->type == SDL_KEYDOWN)
      {
        int key = event->key.keysym.sym;
        SDL_HideWindow(m_window);
        cout << "Key " << key << " ('" << static_cast<char>(key) << "') was pressed.\n";
        SDL_ShowWindow(m_window);
        if (key == SDLK_ESCAPE)
          return 0;
      }
    }
  }
  return 0;
}

void my_line(SDL_Renderer *Renderer, int x_1, int y_1, int L, double theta, int width, int R, int G, int B)

{

  int x_2 = x_1 + L * cos(theta);

  int y_2 = y_1 - L * sin(theta);

  thickLineRGBA(Renderer, x_1, y_1, x_2, y_2, width, R, G, B, 255);

  //  SDL_RenderPresent(Renderer);
}

void rect(SDL_Renderer *Renderer, int x, int y, int w, int h, int R, int G, int B, bool fill)
{
  SDL_Rect rectangle;

  rectangle.x = x;
  rectangle.y = y;
  rectangle.w = w;
  rectangle.h = h;

  SDL_SetRenderDrawColor(Renderer, R, G, B, 255);

  if (fill)
  {
    SDL_RenderFillRect(Renderer, &rectangle);
  }
  SDL_RenderDrawRect(Renderer, &rectangle);
  // SDL_RenderPresent(Renderer);
}

void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, bool fill)
{
  if (fill)
  {
    filledEllipseRGBA(Renderer, x, y, Radius1, Radius2, R, G, B, 255);
  }
  else
  {
    ellipseRGBA(Renderer, x, y, Radius1, Radius2, R, G, B, 255);
  }
  // SDL_RenderPresent(Renderer);
}

void window_color(SDL_Renderer *Renderer, int R, int G, int B)
{
  SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
  SDL_RenderClear(Renderer);
  // Show the window
  // SDL_RenderPresent( Renderer );
}