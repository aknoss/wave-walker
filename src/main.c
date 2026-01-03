#include "main.h"

int main(void) {
  Initialization();

  GameLoop();

  Cleanup();
  return 0;
}

void Initialization(void) {
  SetTraceLogLevel(LOG_DEBUG);
  InitWindow(screenWidth, screenHeight, "wave-walker");
  InitGameScreen();
}

void GameLoop(void) {
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    UpdateDrawFrame();
  }
}

void UpdateDrawFrame(void) {
  UpdateGameScreen();
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
