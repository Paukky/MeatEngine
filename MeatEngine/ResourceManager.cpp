#include "ResourceManager.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

//Static variables must be declared somewhere in the project; usually in its respective cpp like this:
ResourceManager* ResourceManager::instance = NULL;
std::unordered_map<std::string, Shader> ResourceManager::Shaders;
std::unordered_map<std::string, Texture2D> ResourceManager::Textures;

ResourceManager* ResourceManager::getInstance()
{
	if (instance == NULL) {
		instance = new ResourceManager();
	}
	return instance;
}

// Doing Shaders[name] CREATES gpu Resource BIG NONO
// you want to iterate through each elements to find what you want
// s->first means the String of the pair, vice versa for s-> second
Shader ResourceManager::GetShader(std::string name) {
	std::unordered_map<std::string, Shader>::iterator s = Shaders.find(name);
	if (s == Shaders.end()) {
		std::cerr << "No Shader found under this name: " << name << std::endl;
	}
	else {
		return s->second;	
	}
}

Texture2D ResourceManager::GetTexture(std::string name)
{
	std::unordered_map<std::string, Texture2D>::iterator t = Textures.find(name);
	if (t == Textures.end()) {
		std::cerr << "No Shader found under this name: " << name << std::endl;
	}
	else {
		return t->second;
	}
}

void ResourceManager::LoadShader(const char* vShaderFile, const char* vFragFile, std::string name)
{
	 Shaders.try_emplace(name, loadShaderFromFile(vShaderFile, vFragFile));
}


void ResourceManager::LoadTexture(const GLchar * file, bool alpha, std::string name)
{
	Textures.try_emplace(name, loadTextureFromFile(file, alpha));
}

Shader ResourceManager::loadShaderFromFile(const char*vShaderFile, const char* fShaderFile) {
	Shader shader;
	shader.readCompileAttach(vShaderFile, fShaderFile);
	return shader;
}

Texture2D ResourceManager::loadTextureFromFile(const char* file, bool alpha)
{
	// Create Texture object
	Texture2D texture;
	if (alpha)
	{
		texture.Internal_Format = GL_RGBA;
		texture.Image_Format = GL_RGBA;
	}
	// Load image
	int width, height;
	unsigned char* image = stbi_load(file, &width, &height, 0, 0);
	// Now generate texture
	texture.Generate(width, height, image);
	// And finally free image data
	stbi_image_free(image);
	return texture;
}

void ResourceManager::Clear()
{
}