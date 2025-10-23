#pragma once
class IAudioPlayer;
//class IWindow;
#include "Window/GLFWWidnow.h"
class ZEngine
{
public:
	ZEngine();
	virtual ~ZEngine();
public:
	void Run(int argc, char* argv[]);
private:
	IAudioPlayer* Player = nullptr;
	GLFWWidnow* Window = nullptr;
};