#include "game.h"
#include "raylib.h"

#ifndef MAIN_H
#define MAIN_H

struct Player {
  Collider collider;
};
struct Object {
  Collider collider;
};
Font font = {0};
static const int screenWidth = 1080;
static const int screenHeight = 720;

void Initialization(void);
void GameLoop(void);
void UpdateDrawFrame(void);
void Cleanup(void);

#endif // MAIN_H
