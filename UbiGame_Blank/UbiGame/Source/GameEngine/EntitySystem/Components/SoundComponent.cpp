#include "GameEngine/EntitySystem/Components/SoundComponent.h"

using namespace GameEngine;

SoundComponent::SoundComponent()
	: m_soundManager()
{
	m_soundManager = std::make_unique<SoundManager>(1); // Be default each sound manager can play 1 sound at a time
}


SoundComponent::~SoundComponent()
{

}

void SoundComponent::OnAddToWorld()
{
	Component::OnAddToWorld();
}


void SoundComponent::OnRemoveFromWorld()
{
	Component::OnAddToWorld();
}


void SoundComponent::SetNumSimultaneousSounds(unsigned int const numSimultaneousSounds)
{
	m_soundManager.reset(new SoundManager(numSimultaneousSounds));
}


SoundManager::SoundId SoundComponent::LoadSoundFromFile(std::string const& filename)
{
	if (!m_soundManager)
	{
		return SoundManager::INVALID_SOUND_ID;
	}

	return m_soundManager->LoadSoundFromFile(filename);
}


void SoundComponent::PlaySound(SoundManager::SoundId const soundIdToPlay, bool useExistingSoundInstance /*= false*/)
{
	if (!m_soundManager)
	{
		return;
	}

	m_soundManager->PlaySound(soundIdToPlay, useExistingSoundInstance);
}