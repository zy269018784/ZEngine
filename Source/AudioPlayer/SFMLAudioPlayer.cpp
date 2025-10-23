#include "SFMLAudioPlayer.h"

SFMLAudioPlayer::SFMLAudioPlayer()
	: Music(nullptr)
{

}

SFMLAudioPlayer::SFMLAudioPlayer(const std::filesystem::path& filename)
{
	Music = new sf::Music(filename);
}

SFMLAudioPlayer::~SFMLAudioPlayer()
{
	delete Music;
}

void SFMLAudioPlayer::Play()
{
	Music->play();
};