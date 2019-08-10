#pragma once
#include "glad\glad.h"
#include "Logger.h"
#include <fstream>
#include <sstream>
class Shader {
public:
	void  readCompileAttach(const char* vShaderFile, const char* vFragFile);
	GLint &Use();
	Shader() {};
private:
	GLint ID;
	GLint shaderProgram;
	int vertexShader, fragmentShader = 0;
	int success;
	char infoLog[512];
	std::string readTextFile(const char* ShaderFile);
};