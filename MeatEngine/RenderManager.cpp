#include "RenderManager.h"

void RenderManager::initRender()
{
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,GL_STATIC_DRAW);

}

RenderManager::~RenderManager()
{
}

void RenderManager::Draw()
{

}
