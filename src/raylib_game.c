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

static void UpdateDrawFrame(void);

int main(void) {
  InitWindow(screenWidth, screenHeight, "rayne");

  InitAudioDevice();

  font = LoadFont("resources/mecha.png");
  fxCoin = LoadSound("resources/coin.wav");

  SetMusicVolume(music, 1.0f);
  PlayMusicStream(music);

  InitGameplayScreen();

#if defined(PLATFORM_WEB)
  emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    UpdateDrawFrame();
  }
#endif

  UnloadGameplayScreen();
  UnloadFont(font);
  UnloadMusicStream(music);
  UnloadSound(fxCoin);
  CloseAudioDevice();
  CloseWindow();

  return 0;
}

static void UpdateDrawFrame(void) {
  BeginDrawing();
  ClearBackground(RAYWHITE);
  DrawGameplayScreen();
  EndDrawing();
}
