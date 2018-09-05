#pragma once
#include <glad\glad.h>
#include <GLFW\glfw3.h>
class Window {
private:
	static Window* instance;
	
public:	

	Window();
	~Window();
	GLFWwindow* win;
	static Window* getInstance();

	void initWindow();
	//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};