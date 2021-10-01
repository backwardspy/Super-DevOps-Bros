#pragma once

#include "audio/mp3-stream.hpp"

#ifdef PICO_BUILD
#include "audio/audio.hpp"
#endif // !PICO_BUILD


namespace AudioHandler {
	class AudioHandler {
	public:
		AudioHandler();

		void set_volume(uint32_t = 0xffff);
		void set_volume(uint8_t, uint32_t);
		
		void load(uint8_t, const uint8_t[], const uint32_t);
		void load(uint8_t, uint8_t);
		void play(uint8_t, uint8_t = 0);
		bool is_playing(uint8_t);
		void update(float dt);

	protected:
#ifdef PICO_BUILD
		float t = 0.0f;
#else
		blit::MP3Stream mp3_channels[8];
		const char* filenames[8] = {
			"temp0.mp3", "temp1.mp3", "temp2.mp3", "temp3.mp3", "temp4.mp3", "temp5.mp3", "temp6.mp3", "temp7.mp3"
		};
#endif // !PICO_BUILD
	};
}