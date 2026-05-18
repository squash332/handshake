#pragma once

#include "raylib.h"

constexpr int VIRTUAL_HEIGHT = 600;
constexpr int VIRTUAL_WIDTH = 800;

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
