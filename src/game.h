#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include "scene.h"

typedef struct {
  SDL_FPoint position;
  SDL_FRect collider;
  int velocity;
} Player;

typedef struct {
  SDL_FRect collider;
} Ground;

Scene GameSceneConstructor(void);

void InitGameScreen(void);
void UpdateGameScreen(void);
void DrawGameScreen(void);
void UnloadGameScreen(void);
int FinishGameScreen(void);

#endif // GAME_H
