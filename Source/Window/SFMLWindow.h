#pragma once
#include "IWindow.h"
#include <SFML/Window.hpp>
class SFMLWindow : public IWindow
{
public:
	SFMLWindow() = default;
	SFMLWindow(int Width, int Height, const char* Title, GraphicsAPI API);
	virtual ~SFMLWindow();
public:
	virtual void Resize(int Width, int Height) override;
private:
	sf::Window* Handle;
};