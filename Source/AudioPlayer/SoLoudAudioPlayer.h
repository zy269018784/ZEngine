#pragma once
#include "IAudioPlayer.h"
#include <filesystem>

class SoLoudAudioPlayer : public IAudioPlayer
{
public:
	SoLoudAudioPlayer();
	explicit SoLoudAudioPlayer(const std::filesystem::path& filename);
	~SoLoudAudioPlayer();
	virtual void Play() override;
};