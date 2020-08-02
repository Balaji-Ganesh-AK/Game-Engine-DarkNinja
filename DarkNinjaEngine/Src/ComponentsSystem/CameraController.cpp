#include "pch.h"
#include "CameraController.h"
#include "Utlis/Helper.h"
#include "Input.h"


namespace Engine
{
	CameraController::CameraController(OrthographicCamera* camera, bool rotation):_camera_(camera),_camera_rotation_(rotation)
	{
	}

	CameraController::CameraController( OrthographicCamera& orthographic_camera, bool rotation) : _camera_(&orthographic_camera), _camera_rotation_(rotation)
	{
		_camera_screen_ratio_ = _camera_->GetCameraSize().y;
		
	}

	void Engine::CameraController::Update(float deltatime)
{
	if(Input::IsKeyPressed(KeyCodes::Up) )
	{
		_camera_position_.y += _camera_move_speed_ * deltatime;
	}
	else if(Input::IsKeyPressed(KeyCodes::Down))
	{
		_camera_position_.y -= _camera_move_speed_ * deltatime;
	}
	else if (Input::IsKeyPressed(KeyCodes::Left))
	{
		_camera_position_.x -= _camera_move_speed_ * deltatime;
	}
	else if (Input::IsKeyPressed(KeyCodes::Right))
	{
		_camera_position_.x += _camera_move_speed_ * deltatime;
	}

	if(_is_rotation_)
	{
		//TODO: implement rotation keys.
	}
	_camera_->SetPosition(_camera_position_);
	_camera_move_speed_ = _zoom_level_;
		
}

void Engine::CameraController::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<MouseScrollEvent>(DNE_BIND_SINGLE_EVENT(CameraController::OnMouseScrolledEvent));
	dispatcher.Dispatch<WindowResizeEvent>(DNE_BIND_SINGLE_EVENT(CameraController::OnWindowResizedEvent));
		
}

bool Engine::CameraController::OnMouseScrolledEvent(MouseScrollEvent& e)
{
	_zoom_level_ -= e.GetMouseY()*0.5f;
	_zoom_level_ = std::max(_zoom_level_, 0.25f);
	
	_camera_->SetProjection(-_camera_screen_ratio_*_zoom_level_,_camera_screen_ratio_*_zoom_level_,-_zoom_level_,_zoom_level_);
	return false;
}

bool Engine::CameraController::OnWindowResizedEvent(WindowResizeEvent& e)
{
	_camera_screen_ratio_ = static_cast<float>(e.GetWidth()) / static_cast<float>(e.GetHeight());

	
	
	_camera_->SetProjection(-_camera_screen_ratio_ * _zoom_level_, _camera_screen_ratio_ * _zoom_level_, -_zoom_level_, _zoom_level_);
	return false;
}
	

	
}
