#include "Engine.h"

Engine::Engine()
{
}

Engine::~Engine() {

}
void Engine::Start()
{
	Window::getInstance()->initWindow();
	ResourceManager::getInstance()->LoadShader("../Resources/vertShader.glsl", "../Resources/fragShader.glsl", "test");

}

void Engine::Run()
{

	while (!glfwWindowShouldClose(Window::getInstance()->win)) {
		InputManager::getInstance()->processInput(Window::getInstance()->win);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(Window::getInstance()->win);
		glfwPollEvents();
	}
}

void Engine::Clean()
{
	Window::getInstance()->~Window();
	glfwTerminate();
}
