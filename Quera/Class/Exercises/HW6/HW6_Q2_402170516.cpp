#include <iostream>
#include <string>
#include <cmath>
#include "SDL_Headers.h"
using namespace std;
void draw_line(SDL_Renderer *Renderer, int x_1, int y_1, int x_2, int y_2, int width, int R, int G, int B);
void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void rect(SDL_Renderer *Renderer, int x, int y, int w, int h, int R, int G, int B, bool fill);
void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, bool fill);
void my_line(SDL_Renderer *Renderer, int x_1, int y_1, int L, double theta, int width, int R, int G, int B);
int main()
{
  // I have put this comments by my self to understand what this parts do
  int W = 800;  // window width
  int L = 1200; // window length
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
  window_color(m_renderer, 255, 255, 255);
  SDL_Event *event = new SDL_Event();
  // backends
  int lineWidth = 5, lineColor = 0, n;
  int X[4], Y[4];
  cout << "Enter the coordinates (x1 y1 x2 y2 x3 y3 x4 y4):";
  cin >> X[0] >> Y[0] >> X[1] >> Y[1] >> X[2] >> Y[2] >> X[3] >> Y[3];
  cout << endl;
  bool changed = true;
  for (int i = 3; (i > 0) && (changed); i--)
  {
    changed = false;
    for (int j = 0; j < i; j++)
      if (Y[j] > Y[j + 1])
      {
        swap(X[j], X[j + 1]);
        swap(Y[j], Y[j + 1]);
        changed = true;
      }
  }
  if (X[1] > X[2])
  {
    swap(X[1], X[2]);
    swap(Y[1], Y[2]);
  }
  int Bx = X[1], By = Y[1], Ax = X[2], Ay = Y[2], Dx = X[3], Dy = Y[3], Cx = X[0], Cy = Y[0];
  cout << "A = (" << Ax << "," << Ay << ")\n"
       << "B = (" << Bx << "," << By << ")\n"
       << "C = (" << Cx << "," << Cy << ")\n"
       << "D = (" << Dx << "," << Dy << ")\n";
  // graphics
  draw_line(m_renderer, Dx, Dy, Cx, Cy, lineWidth, lineColor, lineColor, lineColor);
  draw_line(m_renderer, Ax, Ay, Cx, Cy, lineWidth, lineColor, lineColor, lineColor);
  draw_line(m_renderer, Bx, By, Cx, Cy, lineWidth, lineColor, lineColor, lineColor);
  draw_line(m_renderer, Ax, Ay, Dx, Dy, lineWidth, lineColor, lineColor, lineColor);
  draw_line(m_renderer, Bx, By, Dx, Dy, lineWidth, lineColor, lineColor, lineColor);
  cout << "enter n:";
  cin >> n;
  double Mac = (double)(Cy - Ay) / (Cx - Ax), Mcd = (double)(Dy - Cy) / (Dx - Cx), Mcb = (double)(By - Cy) / (Bx - Cx);
  for (int i = 0; i < n; i++)
  {
    int Dcb = (Cx - Bx) * i / n, Dcd = (Cx - Dx) * i / n, Dca = (Cx - Ax) * i / n;
    draw_line(m_renderer, Bx + Dcb, By + Dcb * Mcb, Dx + Dcd, Dy + Dcd * Mcd, lineWidth, lineColor, lineColor, lineColor);
    draw_line(m_renderer, Ax + Dca, Ay + Dca * Mac, Dx + Dcd, Dy + Dcd * Mcd, lineWidth, lineColor, lineColor, lineColor);
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

void draw_line(SDL_Renderer *Renderer, int x_1, int y_1, int x_2, int y_2, int width, int R, int G, int B)
{
  thickLineRGBA(Renderer, x_1, y_1, x_2, y_2, width, R, G, B, 255);
  //  SDL_RenderPresent(Renderer);
}

void window_color(SDL_Renderer *Renderer, int R, int G, int B)
{
  SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
  SDL_RenderClear(Renderer);
  // Show the window
  // SDL_RenderPresent( Renderer );
}