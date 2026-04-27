#pragma once

#include <GLFW/glfw3.h>
#include <string>

class WaffleEngine {
private:
  static GLFWwindow *window;

public:
  static void Init();
  static void CreateWindow(int width, int height, const std::string &title);
};
