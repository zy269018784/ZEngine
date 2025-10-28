#pragma once
#include "IWindow.h"

class LVGLWindow : public IWindow
{
public:
	LVGLWindow() = default;
	LVGLWindow(int Width, int Height, const char* Title, GraphicsAPI API);
	virtual ~LVGLWindow();
public:
	virtual void Resize(int Width, int Height) override;
};