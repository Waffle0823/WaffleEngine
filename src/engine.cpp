#define GLFW_INCLUDE_NONE
#include "engine.hpp"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

GLFWwindow *WaffleEngine::window = nullptr;

void WaffleEngine::Init() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif // __APPLE__
}

void WaffleEngine::CreateWindow(int width, int height,
                                const std::string &title) {
  if (WaffleEngine::window != nullptr) {
    throw std::runtime_error("Window already exists");
  }

  // TODO: Implement monitor and share paramater
  GLFWwindow *window =
      glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

  if (window == NULL) {
    std::cout << "Failed to initialize GLFW window" << std::endl;
    glfwTerminate();
    throw std::runtime_error("GLFW window initializing failed");
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    throw std::runtime_error("GLAD initializing failed");
  }

  glViewport(0, 0, width, height);

  WaffleEngine::window = window;
}
