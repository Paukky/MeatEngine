#pragma once
#include "glad\glad.h"
#include "Logger.h"
#include <fstream>
#include <sstream>
class Shader {
public:
	Shader(const char* vShaderFile, const char* vFragFile);
	int getShaderProgram();
private:

	int vertexShader, fragmentShader = 0;
	int shaderProgram;
	int success;
	char infoLog[512];
	void  readCompileAttach(const char* vShaderFile, const char* vFragFile);
	std::string readTextFile(const char* ShaderFile);
};