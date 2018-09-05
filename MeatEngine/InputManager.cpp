#include "InputManager.h"
InputManager* InputManager::instance = NULL;
InputManager::InputManager() {
}
InputManager::~InputManager()
{
}

InputManager* InputManager::getInstance()
{
	if (instance == NULL) {
		instance = new InputManager();
	}
	return instance;
}

void InputManager::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}
