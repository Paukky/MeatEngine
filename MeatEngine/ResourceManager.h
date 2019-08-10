#pragma once
#include "Shader.h"
#include "Texture2D.h"
#include <unordered_map>


class ResourceManager {
public:
	static ResourceManager* getInstance();

	
	// Load Resource Files and then store it to its respective storage
	static void LoadShader(const char* vShaderFile, const char* vFragFile, std::string name);
	static void LoadTexture(const GLchar* file, bool alpha, std::string name);

	// Retrieves a stored texture
	static Shader GetShader(std::string name);
	static Texture2D GetTexture(std::string name);

	//Properly de-allocates all loaded resources
	static void	Clear();

private:
	static ResourceManager* instance;

	//Resource Storage
	static std::unordered_map<std::string, Shader> Shaders;
	static std::unordered_map<std::string, Texture2D> Textures;

	static Shader loadShaderFromFile(const char* vShaderFile, const char* fShaderFile);
	static Texture2D loadTextureFromFile(const char* file, bool alpha);
};