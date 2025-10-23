#include "SFMLWindow.h"

SFMLWindow::SFMLWindow(int Width, int Height, const char* Title, GraphicsAPI API)
{
	Handle = new sf::Window(sf::VideoMode({ (unsigned int)Width, (unsigned int)Height }), Title);
}

SFMLWindow::~SFMLWindow()
{
	delete Handle;
}


void SFMLWindow::Resize(int Width, int Height)
{
	Handle->setSize({ (unsigned int)Width, (unsigned int)Height });
}