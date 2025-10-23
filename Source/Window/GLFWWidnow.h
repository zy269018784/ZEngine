#pragma once
#include "IWindow.h"
#include <GLFW/glfw3.h>

class GLFWWidnow : public IWindow
{
public:
	GLFWWidnow() = default;
	GLFWWidnow(int Width, int Height, const char* Title, GraphicsAPI API);
	virtual ~GLFWWidnow();
public:
	GLFWwindow* GetHandle() const;
	GLFWkeyfun SetKeyCallback(GLFWkeyfun Callback);
	GLFWmousebuttonfun 	SetMouseButtonCallback(GLFWmousebuttonfun Callback);
	GLFWcursorposfun 	SetCursorPosCallback(GLFWcursorposfun Callback);
public:
	virtual void Resize(int Width, int Height) override;
private:
	GLFWwindow* Handle;
};