#include "SDLWindow.h"
#include <SDL3/SDL.h>
SDLWindow::SDLWindow(int Width, int Height, const char* Title, GraphicsAPI API)
{
	SDL_Init(SDL_INIT_VIDEO);
	Handle = SDL_CreateWindow(Title, Width, Height, SDL_WINDOW_RESIZABLE);
}

SDLWindow::~SDLWindow()
{
	SDL_DestroyWindow(Handle);
}

void SDLWindow::Resize(int Width, int Height)
{
	SDL_SetWindowSize(Handle, Width, Height);
}