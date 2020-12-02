#pragma once

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <vector>
#include <limits>

namespace GameEngine
{
	class SoundManager
	{
	public:
		typedef size_t SoundId;
		static SoundId constexpr INVALID_SOUND_ID = std::numeric_limits<size_t>::max();
		static unsigned int constexpr MAX_SOUND_INSTANCES = 256; // SMFL supports a maximum of 256 sound and music instances. 
		

	private:
		struct SoundInstance
		{
			sf::Sound m_sound;
			unsigned int m_recentlyPlayedIndex;
		};
		typedef std::vector<SoundInstance>::iterator SoundInstancePtr;

		struct SoundResource
		{
			unsigned int m_numInstances = 0; // How many references there are to this sound resource
			std::string m_filename;
			sf::SoundBuffer m_soundBuffer;
		};

	public:
		explicit SoundManager(unsigned int numSimultaneousSounds);
		~SoundManager();

		SoundId LoadSoundFromFile(std::string const& filename);
		void PlaySound(SoundId const soundIdToPlay, bool useExistingSoundInstance = false);
		void PlayMusic(std::string const& filename);

	private:
		bool IsValidSoundId(SoundId const soundId) const;
		SoundInstancePtr FindNextAvailableSoundInstance();
		SoundInstancePtr FindLeastRecentlyUsedSoundInstance();
		SoundInstancePtr FindSoundInstancePlayingSoundId(SoundId const soundId);
		SoundId FindSoundResource(std::string const& filename) const;
		SoundId CreateNewSoundResource(std::string const& filename);
		void PlaySoundWithSoundInstance(SoundId const resourceId, SoundInstancePtr soundInstance);

		void ReleaseSound(SoundId const resourceId);
	private:
		static sf::Music sm_music; // We currently only support one music at a time.
		static unsigned int sm_totalSoundInstances;
		static std::vector<SoundResource> sm_soundResources;

		std::vector<SoundInstance> m_soundInstances;
		std::vector<SoundId> m_loadedSounds;
	};
}