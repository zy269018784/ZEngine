#pragma once
#include "IAudioPlayer.h"
#include <filesystem>
#include <string>
#include <irrKlang.h>

class irrKlangAudioPlayer : public IAudioPlayer
{
public:
	irrKlangAudioPlayer();
	explicit irrKlangAudioPlayer(const std::filesystem::path& filename);
	~irrKlangAudioPlayer();
	virtual void Play() override;
private:
	std::filesystem::path File;
public:
	irrklang::ISoundEngine* Engine = nullptr;
};