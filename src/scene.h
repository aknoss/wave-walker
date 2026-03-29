#ifndef SCENE_H
#define SCENE_H

typedef enum {
  SCENE_MENU,
  SCENE_SELECT_LEVEL,
  SCENE_GAME,
} SceneId;

typedef struct {
  void (*update)(void *);
  void (*draw)(void *);
} Scene;

#endif // SCENE_H
