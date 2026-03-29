#ifndef MAIN_H
#define MAIN_H

#include <SDL3/SDL.h>
#include <stdbool.h>
#include "scene.h"

extern SDL_Window *window;
extern SDL_Renderer *renderer;

typedef struct {
  bool isRunning;
  SceneId currentSceneId;
} GameState;

#endif // MAIN_H
