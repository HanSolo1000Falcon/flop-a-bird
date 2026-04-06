#ifndef fab_bird
#define fab_bird

#include "gamemanager.hpp"
#include "pipe.hpp"
#include "raylib.h"

class Bird {
private:
  Vector2 currentPosition;
  Vector2 currentVelocity;

  GameManager &gameManager;

  bool overlappedX;

public:
  Bird(GameManager &gameManager) : gameManager(gameManager) {}

  Vector2 GetPosition() const;

  void Tick(const float &frameDelta, const Pipe &closestPipe);
  void Render();
  void Awake();
};

#endif
