#pragma once
#include "Event/Event.h"
#include "Event/MouseEvent.h"
#include "Event/KeyboardEvent.h"
#include "Event/WindowEvent.h"
#include "RenderingSystem/Camera.h"

namespace Engine
{
	class CameraController
	{
	public:
		 CameraController(OrthographicCamera* camera,bool rotation =false);
		 CameraController( OrthographicCamera& orthographic_camera, bool rotation = false);

		 void Update(float deltatime);

		void OnEvent(Event &e);



#pragma region Events

		bool OnMouseScrolledEvent(MouseScrollEvent& e);
		bool OnWindowResizedEvent(WindowResizeEvent& e);
		
#pragma endregion 


	private:
		OrthographicCamera* _camera_;
		float _camera_screen_ratio_=0.0f;
		float _zoom_level_=1.0f;
		bool _is_rotation_;
		float _camera_rotation_ = 0.0f;
		float _camera_move_speed_ = 1.0f;
		float _camera_rotation_speed_ = 1.0f;

		vec3 _camera_position_;
		
		
	};
}
