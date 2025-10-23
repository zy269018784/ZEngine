#include "irrKlangAudioPlayer.h"
#include <iostream>
#include <thread>
irrKlangAudioPlayer::irrKlangAudioPlayer()
{
	//Engine = irrklang::createIrrKlangDevice();
	std::cout << "createIrrKlangDevice "  << std::endl;
}

irrKlangAudioPlayer::irrKlangAudioPlayer(const std::filesystem::path& filename)
{
	Engine = irrklang::createIrrKlangDevice();
	std::cout << "createIrrKlangDevice " << filename << std::endl;
	File = filename;
}

irrKlangAudioPlayer::~irrKlangAudioPlayer()
{
	//Engine->drop(); // delete engine
}

void irrKlangAudioPlayer::Play()
{
	std::cout << "irrKlangAudioPlayer Play 1111111 " << std::endl;
	if (!Engine)
		return; // error starting up the engine

	std::string str1 = File.filename().string();
	// play some sound stream, looped
	Engine->play2D("1.mp3", true);
	std::cout << "player " << std::endl;
	//std::this_thread::sleep_for(std::chrono::seconds(20));
	Engine->drop(); // delete engine
};