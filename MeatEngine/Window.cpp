#include "Window.h"

Window* Window::instance = NULL;

Window * Window::getInstance()
{
	if (instance == NULL) {
		instance = new Window();
	}

	return instance;
}
//void Window::framebuffer_size_callback(GLFWwindow * window, int width, int height)
//{
//	
//}
void Window::initWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	win = glfwCreateWindow(800, 600, "MeatEngine", NULL, NULL);
	glfwMakeContextCurrent(win);
	
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glViewport(0, 0, 800, 600);
}

Window::Window() {

}
Window::~Window()
{
	glfwDestroyWindow(win);
	glfwTerminate();
}

