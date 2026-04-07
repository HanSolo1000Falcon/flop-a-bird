#include <cstdlib>

#include "constants.hpp"
#include "pipe.hpp"
#include "raylib.h"

float Pipe::GetTimeAlive() const { return timeAlive; }
int Pipe::GetGapPosition() const { return gapPosition; }

void Pipe::Tick(const float &frameDelta) { timeAlive += frameDelta; }

void Pipe::Render() {
  const float formatted = -(timeAlive - constants::PIPE_LIFE_LENGTH);
  const int positionX =
      formatted * (constants::WINDOW_WIDTH / constants::PIPE_LIFE_LENGTH);

  DrawTexturePro(
      pipeTexture,
      (Rectangle){0, 0, (float)-pipeTexture.width, (float)pipeTexture.height},
      (Rectangle){positionX + constants::PIPE_WIDTH / 2.0f, 0,
                  (float)constants::PIPE_WIDTH,
                  (float)pipeTexture.height *
                      (constants::PIPE_WIDTH / (float)pipeTexture.width)},
      (Vector2){constants::PIPE_WIDTH / 2.0f,
                gapPosition - constants::GAP_SIZE / 2.0f},
      180, WHITE);

  DrawTexturePro(
      pipeTexture,
      (Rectangle){0, 0, (float)pipeTexture.width, (float)pipeTexture.height},
      (Rectangle){positionX + constants::PIPE_WIDTH / 2.0f,
                  gapPosition + constants::GAP_SIZE / 2.0f,
                  (float)constants::PIPE_WIDTH,
                  (float)pipeTexture.height *
                      (constants::PIPE_WIDTH / (float)pipeTexture.width)},
      (Vector2){constants::PIPE_WIDTH / 2.0f, 0}, 0, WHITE);
}

void Pipe::Awake(Texture2D pipeTexture) {
  gapPosition =
      (rand() % (constants::WINDOW_HEIGHT - constants::GAP_SIZE * 2)) +
      constants::GAP_SIZE;
  this->pipeTexture = pipeTexture;
}
