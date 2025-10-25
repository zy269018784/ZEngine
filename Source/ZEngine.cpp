#include "RHIApplicationScene.h"
#include "ZEngine.h"
#include "AudioPlayer/SFMLAudioPlayer.h"
#include "Window/SFMLWindow.h"
#include "Window/GLFWWidnow.h"
#include "Window/SDLWindow.h"
#include "Image/Image.h"

#include <thread>
#include <iostream>

int HelloQML(int argc, char* argv[]);
ZEngine::ZEngine()
{
	Player = new SFMLAudioPlayer("1.mp3");
#if USE_RHI_VULKAN
	Window = new GLFWWidnow(800, 600, "hellow window", GraphicsAPI::Vulkan);
#else
	Window = new GLFWWidnow(800, 600, "hellow window", GraphicsAPI::OpenGL460);
#endif
}

ZEngine::~ZEngine()
{
	delete Player;
}

void ZEngine::Run(int argc, char* argv[])
{	
	Image* img = Image::Read("3.webp");
	std::cout << "write " << std::endl;
	img->Write("4.jpg");
	img->Write("4.hdr");
	img->Write("4.bmp");
	img->Write("4.tga");
	img->Write("4.exr");
	img->Write("4.png");
	img->Write("4.webp");
	img->Write("4.gif");
	delete img;

	Player->Play();

	RHIApplicationScene App(((GLFWWidnow *)Window)->GetHandle());
	App.Run();
	delete Window;
}