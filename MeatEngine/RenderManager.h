#pragma once
#include <glad\glad.h>


class RenderManager {
public:
	unsigned int VBO;
	void initRender();
private:
	RenderManager();
	~RenderManager();
	float vertices[9] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};
	virtual void Draw();
	
};