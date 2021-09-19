#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/View.hpp>

namespace GameEngine
{
	class CameraManager
	{
	public:
		~CameraManager();
		static CameraManager* GetInstance() { if (!sm_instance) sm_instance = new CameraManager(); return sm_instance; }
		static bool IsFollowCameraEnabled() { return false; }

		sf::View& GetCameraView() { return m_cameraView; }

	private:
		CameraManager();
		static CameraManager* sm_instance;

		sf::View m_cameraView;
	};	
}
