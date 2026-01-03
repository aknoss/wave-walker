#include "main.h"

static void Initialization(void);
static void GameLoop(void);
static void UpdateDrawFrame(void);
static void Cleanup(void);

int main(void) {
  Initialization();

  GameLoop();

  Cleanup();
  return 0;
}

static void Initialization(void) {
  SetTraceLogLevel(LOG_DEBUG);
  SetTargetFPS(60);

  InitWindow(screenWidth, screenHeight, "wave-walker");
  InitGameScreen();
}

static void GameLoop(void) {
  while (!WindowShouldClose()) {
    UpdateDrawFrame();
  }
}

static void UpdateDrawFrame(void) {
  UpdateGameScreen();
  BeginDrawing();
  ClearBackground(RAYWHITE);
  DrawGameScreen();
  EndDrawing();
}

static void Cleanup(void) {
  UnloadGameScreen();
  UnloadFont(font);
  CloseWindow();
}
