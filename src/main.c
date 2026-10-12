#include <SDL2/SDL.h>
#include <stdio.h>

int main(void) {

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "SDL Could not initialize: %s\r\n", SDL_GetError());
    return 1;
  }

  Uint32 pos = SDL_WINDOWPOS_CENTERED;
  SDL_Window *window =
      SDL_CreateWindow("Title", pos, pos, 800, 600, SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer = SDL_CreateRenderer(
      window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (!window || !renderer) {
    fprintf(stderr, "SDL Could not create window: %s\r\n", SDL_GetError());
    return 1;
  }

  int running = 1;
  while (running) {
    SDL_Event evt;
    while (SDL_PollEvent(&evt)) {
      if (evt.type == SDL_QUIT) {
        running = 0;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
    SDL_Delay(16);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
