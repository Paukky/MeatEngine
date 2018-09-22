#pragma once
#include <glad\glad.h>
#include "Shader.h"

class RenderManager {
public:
	RenderManager();
	~RenderManager();
	Shader* firstShader;
	void initRender();
	void Draw();
private:
	
	unsigned int VAO, VBO;
	
	
	float vertices[9] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};
	
	
};