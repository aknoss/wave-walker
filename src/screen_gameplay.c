
#include "raylib.h"
#include "screens.h"

static int framesCounter = 0;
static int finishScreen = 0;

void InitGameplayScreen(void) {
  framesCounter = 0;
  finishScreen = 0;
}

void UpdateGameplayScreen(void) {
  if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
    finishScreen = 1;
    PlaySound(fxCoin);
  }
}

void DrawGameplayScreen(void) {
  DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), PURPLE);
  Vector2 pos = {20, 10};
  DrawTextEx(font, "GAMEPLAY SCREEN", pos, font.baseSize * 3.0f, 4, MAROON);
  DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
}

void UnloadGameplayScreen(void) {
  // TODO: Unload GAMEPLAY screen variables here!
}

int FinishGameplayScreen(void) { return finishScreen; }
