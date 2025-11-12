#include "raylib.h"
#include "screens.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

Font font = {0};
Music music = {0};
Sound fxCoin = {0};

static const int screenWidth = 1080;
static const int screenHeight = 720;

void Initialization(void);
void GameLoop(void);
void DrawScreen(void);
void Cleanup(void);

int main(void) {
  Initialization();

  GameLoop();

  Cleanup();
  return 0;
}

void Initialization(void) {
  InitWindow(screenWidth, screenHeight, "rayne");
  InitGameplayScreen();
}

void GameLoop(void) {
#if defined(PLATFORM_WEB)
  emscripten_set_main_loop(DrawScreen, 60, 1);
#else
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    DrawScreen();
  }
#endif
}

void DrawScreen(void) {
  BeginDrawing();
  ClearBackground(RAYWHITE);
  DrawGameplayScreen();
  EndDrawing();
}

void Cleanup(void) {
  UnloadGameplayScreen();
  UnloadFont(font);
  CloseWindow();
}
