#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

auto main() -> int
{
  if (!glfwInit()) {
    return EXIT_FAILURE;
  }

  auto *window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    return EXIT_FAILURE;
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  return EXIT_SUCCESS;
}