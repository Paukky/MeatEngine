#include "Shader.h"

int Shader::getShaderProgram()
{
	return shaderProgram;
}

Shader::Shader(const char * vShaderFile, const char * vFragFile) {
	readCompileAttach(vShaderFile, vFragFile);	
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

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

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);


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


