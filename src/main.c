#include "main.h"
#include "constants.h"
#include "game.h"
#include <SDL3/SDL.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

static Uint64 lastTick = 0;
static float deltaTime = 0.0f;

static void Initialization(GameState *);
static void GameLoop(void);
static void Cleanup(void);

float GetDeltaTime(void) { return deltaTime; }

int main(void) {
  GameState game = {0};

  Initialization(&game);
  InitGameScreen();

  while (game.isRunning) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        game.isRunning = false;
      }
    }

    Uint64 now = SDL_GetPerformanceCounter();
    deltaTime = (float)(now - lastTick) / (float)SDL_GetPerformanceFrequency();
    lastTick = now;

    GameLoop();

    SDL_Delay(16); // ~60 FPS
  }

  Cleanup();
  return 0;
}

static void Initialization(GameState *game) {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow(GAME_NAME, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  renderer = SDL_CreateRenderer(window, NULL);
  lastTick = SDL_GetPerformanceCounter();
  *game = (GameState){.isRunning = true, .currentSceneId = SCENE_MENU};
}

static void GameLoop(void) {
  UpdateGameScreen();

  SDL_SetRenderDrawColor(renderer, 245, 245, 245, 255); // RAYWHITE equivalent
  SDL_RenderClear(renderer);
  DrawGameScreen();
  SDL_RenderPresent(renderer);
}

static void Cleanup(void) {
  UnloadGameScreen();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
