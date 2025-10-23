#pragma once
#include "IWindow.h"
#include <SDL3/SDL_video.h>
class SDLWindow : public IWindow
{
public:
	SDLWindow() = default;
	SDLWindow(int Width, int Height, const char* Title, GraphicsAPI API);
	virtual ~SDLWindow();
public:
	virtual void Resize(int Width, int Height) override;
private:
	SDL_Window* Handle = nullptr;
};