#include <iostream>

#include "raylib.h"
#include "constants.hpp"
#include "gamemanager.hpp"

int main() {
  InitWindow(constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT, "Flop A Bird");
  SetTargetFPS(60);

  GameManager().InitLoop();

  return 0;
}
