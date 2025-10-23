
#include "RHIApplicationScene.h"
#include "ZEngine.h"
#include "AudioPlayer/SFMLAudioPlayer.h"
#include "Window/SFMLWindow.h"
#include "Window/GLFWWidnow.h"
#include "Window/SDLWindow.h"

#include <thread>
int HelloQML(int argc, char* argv[]);
ZEngine::ZEngine()
{
	//Player = new SFMLAudioPlayer("1.mp3");
	
}

ZEngine::~ZEngine()
{
	delete Player;
}

void ZEngine::Run(int argc, char* argv[])
{	
	//HelloQML(argc, argv);
#if USE_RHI_VULKAN
	Window = new GLFWWidnow(800, 600, "hellow window", GraphicsAPI::Vulkan);
#else
	Window = new GLFWWidnow(800, 600, "hellow window", GraphicsAPI::460);
#endif
	RHIApplicationScene App(((GLFWWidnow *)Window)->GetHandle());
	App.Run();

	Player = new SFMLAudioPlayer("1.mp3");
	Player->Play();
	std::this_thread::sleep_for(std::chrono::seconds(20));
}