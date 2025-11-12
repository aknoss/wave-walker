#include "main.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

int main(void) {
  Initialization();

  GameLoop();

  Cleanup();
  return 0;
}

void Initialization(void) {
  InitWindow(screenWidth, screenHeight, "rayne");
  InitGameScreen();
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
  DrawGameScreen();
  EndDrawing();
}

void Cleanup(void) {
  UnloadGameScreen();
  UnloadFont(font);
  CloseWindow();
}
