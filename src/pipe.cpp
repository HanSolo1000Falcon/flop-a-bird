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

  DrawRectangle(positionX, 0, constants::PIPE_WIDTH,
                gapPosition - constants::GAP_SIZE / 2, GREEN);
  DrawRectangle(positionX, gapPosition + constants::GAP_SIZE / 2,
                constants::PIPE_WIDTH, constants::WINDOW_HEIGHT, GREEN);
}

void Pipe::Awake() {
  gapPosition =
      (rand() % (constants::WINDOW_HEIGHT - constants::GAP_SIZE * 2)) +
      constants::GAP_SIZE;
}
