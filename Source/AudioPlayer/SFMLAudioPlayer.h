#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include "IAudioPlayer.h"
#include <filesystem>

class SFMLAudioPlayer : public IAudioPlayer
{
public:
	SFMLAudioPlayer();
	explicit SFMLAudioPlayer(const std::filesystem::path& filename);
	~SFMLAudioPlayer();
	virtual void Play() override;
private:
	sf::Music *Music;
};
