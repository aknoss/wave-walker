#include "game.h"
#include "raylib.h"

static int finishScreen = 0;

void DrawLevel1(void) {
  DrawRectangle(0, GetScreenHeight() - 40, GetScreenWidth(), 40, BROWN);
}

void InitGameScreen(void) { finishScreen = 0; }

void UpdateGameScreen(void) {}

void DrawGameScreen(void) { DrawLevel1(); }

void UnloadGameScreen(void) {
  // TODO: Unload GAMEPLAY screen variables here!
}

int FinishGameScreen(void) { return finishScreen; }
