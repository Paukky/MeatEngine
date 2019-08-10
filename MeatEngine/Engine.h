#pragma once
#include "Window.h"
#include "Logger.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "ResourceManager.h"

class Engine {

public:
	Engine();
	~Engine();
	void Start();
	void Run();
	void Clean();
};