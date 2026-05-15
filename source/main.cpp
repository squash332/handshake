#include <iostream>
#include <string>
#include "raylib.h"
#include "game.hpp"

int main()
{
  auto const message = "Hello from the game!";
  std::cout << message << '\n';
  InitWindow(800, 600, "Handshake");
  SetTargetFPS(60);

  while(!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
