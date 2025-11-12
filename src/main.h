#include "game.h"
#include "raylib.h"

Font font = {0};
static const int screenWidth = 1080;
static const int screenHeight = 720;

void Initialization(void);
void GameLoop(void);
void DrawScreen(void);
void Cleanup(void);
