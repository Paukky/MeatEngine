#include "Shader.h"

GLint &Shader::Use()
{
	glUseProgram(this->ID);
	return ID;
}

	
void Shader::readCompileAttach(const char * vShaderFile, const char * vFragFile)
{
	#pragma region Vertex Shader Compilation
	std::string retVertShader = readTextFile(vShaderFile);
	const char* vShaderCode = retVertShader.c_str();
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		//Logger::getInstance()->printMsg(infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	#pragma endregion 

	#pragma region Fragment Shader Compilation
	std::string retFragShader = readTextFile(vFragFile);
	const char* fShaderCode = retFragShader.c_str();
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, 0);
	glCompileShader(fragmentShader);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		//Logger::getInstance()->printMsg(infoLog);
		std::cout << "ERROR::SHADER::FRAG::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
#pragma endregion

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

std::string Shader::readTextFile(const char* shaderFile)
{
	std::string retText;
	std::ifstream fileStream;
	std::stringstream shaderStream;
	fileStream.open(shaderFile);
	shaderStream << fileStream.rdbuf();
	fileStream.close();

	return retText = shaderStream.str();
}


