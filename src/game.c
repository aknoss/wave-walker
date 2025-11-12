#include "game.h"
#include "raylib.h"

static int finishScreen = 0;

void InitGameScreen(void) { finishScreen = 0; }

void UpdateGameScreen(void) {}

void DrawGameScreen(void) {
  DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), PURPLE);
  DrawText("Hello World", 130, 220, 20, MAROON);
}

void UnloadGameScreen(void) {
  // TODO: Unload GAMEPLAY screen variables here!
}

int FinishGameScreen(void) { return finishScreen; }
