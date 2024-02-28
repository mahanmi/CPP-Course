#include <iostream>
#include "SDL_Headers.h"
using namespace std;

void switchColors(double &R_R1, double &G_R1, double &B_R1, double &R_R2, double &G_R2, double &B_R2)
{
  double R_R1_i = R_R1, G_R1_i = G_R1, B_R1_i = B_R1, R_R2_i = R_R2, G_R2_i = G_R2, B_R2_i = B_R2;
  R_R1 = R_R2_i, G_R1 = G_R2_i, B_R1 = B_R2_i, R_R2 = R_R1_i, G_R2 = G_R1_i, B_R2 = B_R1_i;
}

int main(int argc, char const *argv[])
{
  int WIDTH = 1200, HEIGHT = 960;
  // Initialize SDL
  SDL_Window *window = SDL_CreateWindow(
      "Q3",                    // Window title
      SDL_WINDOWPOS_UNDEFINED, // Initial x position
      SDL_WINDOWPOS_UNDEFINED, // Initial y position
      WIDTH,                   // Width, in pixels
      HEIGHT,                  // Height, in pixels
      SDL_WINDOW_SHOWN         // Flags
  );
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_Event event;
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
  Mix_Chunk *sound = Mix_LoadWAV("/Users/mahan/Documents/VS Code/C++/SDL/src/Quera/HW6/ZN.mp3");
  // end of initialization
  srand(time(0));
  int R1 = 50, R2 = 75, mod1_x = WIDTH - 2 * R1, mod1_y = HEIGHT - 2 * R1, mod2_x = WIDTH - 2 * R2, mod2_y = HEIGHT - 2 * R2;
  double Vx_R1 = rand() % 8 + 1, Vy_R1 = rand() % 8 + 1, X0_R1 = (rand() % mod1_x) + R1, Y0_R1 = (rand() % mod1_y) + R1, R_R1 = 0, G_R1 = 255, B_R1 = 255;
  double Vx_R2 = rand() % 8 + 1, Vy_R2 = rand() % 8 + 1, X0_R2 = (rand() % mod2_x) + R2, Y0_R2 = (rand() % mod2_y) + R2, R_R2 = 255, G_R2 = 0, B_R2 = 0;
  while (sqrt(pow(X0_R1 - X0_R2, 2) + pow(Y0_R1 - Y0_R2, 2)) <= R1 + R2)
  {
    X0_R2 = (rand() % mod2_x) + R2, Y0_R2 = (rand() % mod2_y) + R2;
  }
  cout << "The initial position of the small circle is (" << X0_R1 << "," << Y0_R1 << ") and its velocity is (" << Vx_R1 << "," << Vy_R1 << ")" << endl
       << "The initial position of the big circle is (" << X0_R2 << "," << Y0_R2 << ") and its velocity is (" << Vx_R2 << "," << Vy_R2 << ")" << endl;
  bool running = true, paused = false;
  while (running)
  {
    if (!paused)
    {
      if (sqrt(pow(X0_R1 - X0_R2, 2) + pow(Y0_R1 - Y0_R2, 2)) <= R1 + R2)
      {

        // Mix_HaltChannel(-1);
        Mix_PlayChannel(-1, sound, 0);
        X0_R1 -= Vx_R1, Y0_R1 -= Vy_R1, X0_R2 -= Vx_R2, Y0_R2 -= Vy_R2;
        double Vx_R1_i = Vx_R1, Vy_R1_i = Vy_R1, Vx_R2_i = Vx_R2, Vy_R2_i = Vy_R2;
        Vx_R1 = 0.2 * Vx_R1_i + 0.8 * Vx_R2_i, Vy_R1 = 0.8 * Vy_R2_i + 0.2 * Vy_R1_i, Vx_R2 = -0.2 * Vx_R2_i + 1.2 * Vx_R1_i, Vy_R2 = 1.2 * Vy_R1_i - 0.2 * Vy_R2_i;
        switchColors(R_R1, G_R1, B_R1, R_R2, G_R2, B_R2);
        cout << "\033[32mThe circles collided. Vx_R1=" << Vx_R1 << " Vy_R1=" << Vy_R1 << " Vx_R2=" << Vx_R2 << " Vy_R2=" << Vy_R2 << "\033[0m" << endl;
      }
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_RenderClear(renderer);
      ellipseRGBA(renderer, X0_R1, Y0_R1, R1, R1, R_R1, G_R1, B_R1, 255);
      ellipseRGBA(renderer, X0_R2, Y0_R2, R2, R2, R_R2, G_R2, B_R2, 255);
      SDL_RenderPresent(renderer);
      Uint32 FPS60 = 1000 / 60;
      SDL_Delay(FPS60);
      if (X0_R1 >= WIDTH - R1 || X0_R1 <= R1)
      {
        X0_R1 -= Vx_R1;
        Vx_R1 *= -1;
        cout << "\033[34mThe small circle hit the boundary. Vx_R1 =" << Vx_R1 << " X_R1=" << X0_R1 << "\033[0m" << endl;
      }
      if (Y0_R1 >= HEIGHT - R1 || Y0_R1 <= R1)
      {
        Y0_R1 -= Vy_R1;
        Vy_R1 *= -1;
        cout << "\033[34mThe small circle hit the boundary. Vy_R1=" << Vy_R1 << " Y_R1=" << Y0_R1 << "\033[0m" << endl;
      }
      if (X0_R2 >= WIDTH - R2 || X0_R2 <= R2)
      {
        X0_R2 -= Vx_R2;
        Vx_R2 *= -1;
        cout << "\033[31mThe big circle hit the boundary. Vx_R2 =" << Vx_R2 << " X_R2=" << X0_R2 << "\033[0m" << endl;
      }
      if (Y0_R2 >= HEIGHT - R2 || Y0_R2 <= R2)
      {
        Y0_R2 -= Vy_R2;
        Vy_R2 *= -1;
        cout << "\033[31mThe big circle hit the boundary. Vy_R2=" << Vy_R2 << " Y_R2=" << Y0_R2 << "\033[0m" << endl;
      }
      X0_R1 += Vx_R1, Y0_R1 += Vy_R1;
      X0_R2 += Vx_R2, Y0_R2 += Vy_R2;
    }
    if (SDL_PollEvent(&event))
    {
      if (event.type == SDL_KEYDOWN)
      {
        int key = event.key.keysym.sym;
        if (key == SDLK_ESCAPE)
          running = false;
        if (key == SDLK_p)
          paused = !paused;
        if (key == SDLK_SPACE || key == SDLK_w)
        {
          Vx_R1 += (abs(Vx_R1) / Vx_R1) * 2, Vy_R1 += (abs(Vy_R1) / Vy_R1) * 2, Vx_R2 += (abs(Vx_R2) / Vx_R2) * 2, Vy_R2 += (abs(Vy_R2) / Vy_R2) * 2;
          cout << "\033[33mThe circles are accelerated. Vx_R1=" << Vx_R1 << " Vy_R1=" << Vy_R1 << " Vx_R2=" << Vx_R2 << " Vy_R2=" << Vy_R2 << "\033[0m" << endl;
        }
        if (key == SDLK_s && (abs(Vx_R1) > 2 && abs(Vy_R1) > 2 && abs(Vx_R2) > 2 && abs(Vy_R2) > 2))
        {
          Vx_R1 -= (abs(Vx_R1) / Vx_R1) * 2, Vy_R1 -= (abs(Vy_R1) / Vy_R1) * 2, Vx_R2 -= (abs(Vx_R2) / Vx_R2) * 2, Vy_R2 -= (abs(Vy_R2) / Vy_R2) * 2;
          cout << "\033[33mThe circles are decelerated. Vx_R1=" << Vx_R1 << " Vy_R1=" << Vy_R1 << " Vx_R2=" << Vx_R2 << " Vy_R2=" << Vy_R2 << "\033[0m" << endl;
        }
        if (key == SDLK_i)
          Mix_PlayChannel(-1, sound, 0);
      }
    }
  }
  Mix_FreeChunk(sound);
  Mix_CloseAudio();
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  IMG_Quit();
  SDL_Quit();
  return 0;
}
