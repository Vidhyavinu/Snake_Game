#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

#include "SDL.h"
#include "SDL_ttf.h"
#include <SDL_image.h>

int main(int argc, char* args[]) {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  constexpr std::size_t kBorderWidth{ kScreenWidth-(kScreenWidth / kGridWidth)};
  constexpr std::size_t kBorderHeight{ kScreenHeight-(kScreenHeight / kGridHeight)};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight, kBorderWidth, kBorderHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, kBorderWidth, kBorderHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}
