#pragma once
class IAudioPlayer
{
public:
	IAudioPlayer() = default;
	virtual ~IAudioPlayer() = default;
	/*
		mp3, ogg, flac,
	*/
	virtual void Play() = 0;
};