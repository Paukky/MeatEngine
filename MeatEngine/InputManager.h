#pragma once
#include <glad\glad.h>
#include "Window.h"
class InputManager {
private:
	InputManager();
	~InputManager();
	static InputManager* instance;
public:
	static InputManager* getInstance();
	void processInput(GLFWwindow* window);

};