#include "GameEngine/Util/SoundManager.h"

#include <assert.h>
#include <algorithm>

using namespace GameEngine;

sf::Music SoundManager::sm_music;
unsigned int SoundManager::sm_totalSoundInstances;
std::vector<SoundManager::SoundResource> SoundManager::sm_soundResources;

SoundManager::SoundManager(unsigned int numSimultaneousSounds)
{
	sm_totalSoundInstances += numSimultaneousSounds;
	assert(sm_totalSoundInstances < SoundManager::MAX_SOUND_INSTANCES); // Run out of total sound instances, try reducing the number each sound manager is using
	m_soundInstances.resize(numSimultaneousSounds);
	for (SoundManager::SoundInstancePtr soundInstance = m_soundInstances.begin(); soundInstance != m_soundInstances.end(); ++soundInstance)
	{
		soundInstance->m_recentlyPlayedIndex = numSimultaneousSounds;
	}
	m_nextAvailableSoundId = 0;
}


SoundManager::~SoundManager()
{
	for (SoundId const resourceId : m_loadedSounds)
	{
		ReleaseSound(resourceId);
	}
	sm_totalSoundInstances -= static_cast<unsigned int>(m_soundInstances.size());
}


SoundManager::SoundId SoundManager::LoadSoundFromFile(std::string const& filename)
{
	SoundManager::SoundId resourceId = FindSoundResource(filename);
	if (resourceId != SoundManager::INVALID_SOUND_ID) // Already have loaded the resource so just link to that one
	{
		if (std::find(m_loadedSounds.begin(), m_loadedSounds.end(), resourceId) == m_loadedSounds.end()) // This manager hasn't loaded this sound yet.
		{
			if (SoundResource * soundResource = FindSoundResourceById(resourceId))
			{
				soundResource->m_numInstances += 1;
				m_loadedSounds.push_back(resourceId);
			}
		}
		return resourceId;
	}

	resourceId = CreateNewSoundResource(filename); // No manager has loaded this sound yet so we need to create it
	assert(resourceId != SoundManager::INVALID_SOUND_ID); // Unable to create a new resource
	m_loadedSounds.push_back(resourceId);
	return resourceId;
}


void SoundManager::PlaySound(SoundManager::SoundId const soundId, bool useExistingSoundInstance /*= false*/)
{
	if (!IsValidSoundId(soundId))
	{
		return;
	}

	SoundManager::SoundInstancePtr sound = m_soundInstances.end();
	if (useExistingSoundInstance) // Attempt to find the sound instance that is already linked to this SoundId
	{
		sound = FindSoundInstancePlayingSoundId(soundId); // This will restart the sound if it is already playing.
	}

	if (sound == m_soundInstances.end()) // Find the first sound instance that isn't playing any sound at the moment
	{
		sound = FindNextAvailableSoundInstance();
	}

	if (sound == m_soundInstances.end()) // Find the sound instance that started player least recently, hopefully this one is close to ending.
	{
		sound = FindLeastRecentlyUsedSoundInstance();
	}

	assert(sound != m_soundInstances.end()); // We should have found a sound instance by now
	PlaySoundWithSoundInstance(soundId, sound);
}


void SoundManager::PlayMusic(std::string const& filename)
{
	sm_music.stop();
	if (!sm_music.openFromFile(filename))
	{
		return;
	}
	sm_music.play();
}


SoundManager::SoundId SoundManager::CreateNewSoundResource(std::string const& filename)
{
	SoundManager::SoundId resourceId = m_nextAvailableSoundId;
	SoundManager::SoundResource newResource;
	newResource.m_numInstances = 1;
	newResource.m_filename = filename;
	newResource.m_soundId = m_nextAvailableSoundId;
	if (!newResource.m_soundBuffer.loadFromFile(filename))
	{
		return SoundManager::INVALID_SOUND_ID;
	}
	sm_soundResources.push_back(newResource);
	++m_nextAvailableSoundId;
	return resourceId;
}


void SoundManager::ReleaseSound(SoundManager::SoundId const soundId)
{
	if (SoundManager::SoundResource * soundResource = FindSoundResourceById(soundId))
	{
		soundResource->m_numInstances -= 1;

		if (soundResource->m_numInstances == 0)
		{
			std::remove_if(sm_soundResources.begin(), sm_soundResources.end(), [&](SoundManager::SoundResource& soundRes) { return soundRes.m_soundId == soundId; });
		}
	}
}


SoundManager::SoundId SoundManager::FindSoundResource(std::string const& filename) const
{
	for (std::vector<SoundResource>::iterator i = sm_soundResources.begin(); i != sm_soundResources.end(); ++i)
	{
		SoundManager::SoundResource const& soundResource = *i;

		if (soundResource.m_filename == filename)
		{
			return soundResource.m_soundId;
		}
	}

	return SoundManager::INVALID_SOUND_ID;
}


SoundManager::SoundResource* SoundManager::FindSoundResourceById(SoundId const soundId) const
{
	if (!IsValidSoundId(soundId))
	{
		return nullptr;
	}

	auto findSoundResFunc = [&](SoundManager::SoundResource const& soundResource) { return soundResource.m_soundId == soundId; };
	auto soundResourceIt = std::find_if(sm_soundResources.begin(), sm_soundResources.end(), findSoundResFunc);

	if (soundResourceIt == sm_soundResources.end())
	{
		return nullptr;
	}

	return &(*soundResourceIt);
}


void SoundManager::PlaySoundWithSoundInstance(SoundManager::SoundId const resourceId, SoundManager::SoundInstancePtr soundInstance)
{
	SoundResource* soundResource = FindSoundResourceById(resourceId);

	if (soundResource == nullptr)
	{
		return;
	}

	soundInstance->m_sound.stop();
	soundInstance->m_sound.setBuffer(soundResource->m_soundBuffer);
	soundInstance->m_sound.play();

	// Keep track of least recently used
	soundInstance->m_recentlyPlayedIndex = 0;
	for (SoundManager::SoundInstance& soundInstance : m_soundInstances)
	{
		soundInstance.m_recentlyPlayedIndex += 1;
	}
}


bool SoundManager::IsValidSoundId(SoundManager::SoundId const soundId) const
{
	return soundId != SoundManager::INVALID_SOUND_ID;
}


SoundManager::SoundInstancePtr SoundManager::FindNextAvailableSoundInstance()
{
	for (SoundManager::SoundInstancePtr soundInstance = m_soundInstances.begin(); soundInstance != m_soundInstances.end(); ++soundInstance)
	{
		if (soundInstance->m_sound.getStatus() == sf::SoundSource::Stopped)
		{
			return soundInstance;
		}
	}

	return m_soundInstances.end();
}


SoundManager::SoundInstancePtr SoundManager::FindLeastRecentlyUsedSoundInstance()
{
	SoundManager::SoundInstancePtr leastRecentlyUsed = m_soundInstances.begin();
	for (SoundManager::SoundInstancePtr soundInstance = m_soundInstances.begin(); soundInstance != m_soundInstances.end(); ++soundInstance)
	{
		if (soundInstance->m_recentlyPlayedIndex > leastRecentlyUsed->m_recentlyPlayedIndex)
		{
			leastRecentlyUsed = soundInstance;
		}
	}

	return leastRecentlyUsed;
}


SoundManager::SoundInstancePtr SoundManager::FindSoundInstancePlayingSoundId(SoundManager::SoundId const soundId)
{
	if (SoundManager::SoundResource * soundResource = FindSoundResourceById(soundId))
	{
		for (SoundManager::SoundInstancePtr soundInstance = m_soundInstances.begin(); soundInstance != m_soundInstances.end(); ++soundInstance)
		{
			if (soundInstance->m_sound.getBuffer() == &(soundResource->m_soundBuffer))
			{
				return soundInstance;
			}
		}
	}

	return m_soundInstances.end();
}