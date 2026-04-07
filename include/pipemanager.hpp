#ifndef fab_pipemanager
#define fab_pipemanager

#include <memory>
#include <vector>

#include "pipe.hpp"
#include "raylib.h"

class PipeManager {
private:
  float pipeSpawnCooldown;
  std::vector<std::unique_ptr<Pipe>> spawnedPipes;

  Texture2D pipeTexture;

public:
  PipeManager() : pipeSpawnCooldown(0) {}

  Pipe *GetNearestPipe(const Vector2 &birdPosition);

  void Tick(const float &frameDelta);
  void Render();
  void Awake();
};

#endif
