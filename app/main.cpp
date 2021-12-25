#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

constexpr const int NUM{1};

GLuint renderingProgram{};
GLuint vertex[NUM]{};

auto createShaderProgram() -> GLuint;

auto init(GLFWwindow *window) -> void;

auto display(GLFWwindow *window, double currentTime) -> void;

auto main() -> int {
  if (!glfwInit()) {
    std::cerr << "Can't initialize glfw\n";
    return EXIT_FAILURE;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  auto *window = glfwCreateWindow(600, 600, "Hello World", nullptr, nullptr);
  if (!window) {
    std::cerr << "Can't create window\n";
    glfwTerminate();
    return EXIT_FAILURE;
  }

  glfwMakeContextCurrent(window);

  if (glewInit() != GLEW_OK) {
    std::cerr << "Can't initialize glew\n";
    return EXIT_FAILURE;
  }

  glfwSwapInterval(1);

  init(window);

  while (!glfwWindowShouldClose(window)) {
    display(window, glfwGetTime());

    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();

  return EXIT_SUCCESS;
}

auto createShaderProgram() -> GLuint {
  const char *vertexShaderSource =
      "#version 430\n"
      "void main(void)\n"
      "{ gl_Position = vec4(0.0, 0.0, 0.0, 1.0); }";
  const char *fragmentShaderSource =
      "#version 430\n"
      "out vec4 color;\n"
      "void main(void)\n"
      "{ color = vec4(0.0, 0.0, 1.0, 1.0); }";

  auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
  auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
  glCompileShader(vertexShader);
  glCompileShader(fragmentShader);

  GLuint vertexFragmentProgram = glCreateProgram();
  glAttachShader(vertexFragmentProgram, vertexShader);
  glAttachShader(vertexFragmentProgram, fragmentShader);
  glLinkProgram(vertexFragmentProgram);

  return vertexFragmentProgram;
}

auto init(GLFWwindow *window) -> void {
  renderingProgram = createShaderProgram();
  glGenVertexArrays(NUM, vertex);
  glBindVertexArray(vertex[0]);
}

auto display(GLFWwindow *window, double currentTime) -> void {
  glUseProgram(renderingProgram);
  glPointSize(30.0f);
  glDrawArrays(GL_POINTS, 0, 1);
}