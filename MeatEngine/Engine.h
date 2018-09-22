#pragma once
#include "Window.h"
#include "Logger.h"
#include "InputManager.h"
#include "RenderManager.h"

class Engine {

public:
	RenderManager ren;
	Engine();
	~Engine();
	void Start();
	void Run();
	void Clean();
};