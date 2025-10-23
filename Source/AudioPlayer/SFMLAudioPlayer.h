#pragma once
#include "IAudioPlayer.h"
#include <filesystem>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>

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