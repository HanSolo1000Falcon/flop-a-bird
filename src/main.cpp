#include "constants.hpp"
#include "gamemanager.hpp"
#include "raylib.h"

int main() {
  InitWindow(constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT, "Flop A Bird");
  SetTargetFPS(60);

  GameManager().InitLoop();

  return 0;
}
