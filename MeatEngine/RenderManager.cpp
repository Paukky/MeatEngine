#include "RenderManager.h"

void RenderManager::initRender()
{
	
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	firstShader = new Shader("../Resources/vertShader.glsl", "../Resources/fragShader.glsl");
}

RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
}

void RenderManager::Draw()
{
	glUseProgram(firstShader->getShaderProgram());
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
