#include "main.h"
#include "game.h"
#include "raylib.h"

const char *GAME_NAME = "Wave Walker";
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;
Font font = {0};

static void Initialization(void);
static void GameLoop(void);
static void Cleanup(void);

bool isGameRunning = true;

int main(void) {
  Initialization();

  while (isGameRunning) {
    isGameRunning = !WindowShouldClose();
    GameLoop();
  }

  Cleanup();
  return 0;
}

static void Initialization(void) {
  SetTraceLogLevel(LOG_DEBUG);
  SetTargetFPS(60);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
  InitGameScreen();
}

static void GameLoop(void) {
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
