#pragma once

#include "raylib.h"
#include "constants.hpp"

class Window
{
public:
  Window();
  Window(const Window& other) = delete; // no copying allowed
  ~Window();

  void beginFrame();  
  void endFrame(); 
  bool shouldClose(); 
  void toggleFullscreen();
  void toggleWindowed(); 
private:
    RenderTexture2D target_;
    bool fullscreen_ = false;
};
