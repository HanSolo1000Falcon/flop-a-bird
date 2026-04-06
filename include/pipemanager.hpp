#ifndef fab_pipemanager
#define fab_pipemanager

#include <vector>
#include <memory>

#include "gamemanager.hpp"
#include "pipe.hpp"
#include "constants.hpp"

class PipeManager {
  private:
    const GameManager gameManager;

    float pipeSpawnCooldown;
    std::vector<std::unique_ptr<Pipe>> spawnedPipes;

  public:
    PipeManager(GameManager gameManager) : gameManager(gameManager), pipeSpawnCooldown(constants::PIPE_SPAWN_COOLDOWN) { }

    void Tick(const float &frameDelta);
    void Render();
};

#endif
