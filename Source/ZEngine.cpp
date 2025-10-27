#include "RHIApplicationScene.h"
#include "ZEngine.h"
#include "AudioPlayer/SFMLAudioPlayer.h"
#include "Window/SFMLWindow.h"
#include "Window/GLFWWidnow.h"
#include "Window/SDLWindow.h"
#include "MultiMedia/ImageFile/ImageFile.h"
#include "MultiMedia/AudioFile/AudioFile.h"

#include <thread>
#include <iostream>

int HelloQML(int argc, char* argv[]);
ZEngine::ZEngine()
{

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
bool HasExtension(const std::filesystem::path& filePath, const std::string& targetExt);
void ZEngine::Run(int argc, char* argv[])
{	
#if 0
	//ImageFile* img = ImageFile::Read("3.webp");
	//std::cout << "write " << std::endl;
	//img->Write("4.jpg");
	//img->Write("4.hdr");
	//img->Write("4.bmp");
	//img->Write("4.tga");
	//img->Write("4.exr");
	//img->Write("4.png");
	//img->Write("4.webp");
	//img->Write("4.gif");
	//delete img;

	AudioFile AF;
	std::string pcmfile = "1.pcm";
	std::string outfile = "1.mp3";

	PCM pcm;
	pcm.SetChannels(2);
	/*
		16位样本
	*/
	pcm.SetBytesPerSample(2);
	pcm.SetSampleRate(44100);
	/*
		FLAC比较特殊, buffer必须是32位.
	*/
	if (HasExtension(outfile, ".flac"))
		pcm.ReadFromRawFile32(pcmfile);
	else
		pcm.ReadFromRawFile(pcmfile);
	auto total_samples = pcm.GetSampleCount();
	std::cout << "total_samples " << total_samples << std::endl;

	//AF.EncodePCM(&pcm, outfile.data());
	AF.EncodePCM(pcmfile.data(), outfile.data());

	Player = new SFMLAudioPlayer(outfile);
	Player->Play();
#endif
	RHIApplicationScene App(((GLFWWidnow *)Window)->GetHandle());
	App.Run();
	delete Window;
}