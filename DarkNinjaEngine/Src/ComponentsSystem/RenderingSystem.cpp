#include "pch.h"
#include "RenderingSystem.h"

#include "RenderingSystem/Renderer2D.h"
#include "Transform/Transform.h"


namespace Engine
{
	RenderingSystem* RenderingSystem::_instance_ = new RenderingSystem();
	RenderingSystem::Render2DData* RenderingSystem::_data_ = new Render2DData();
	
	void RenderingSystem::Run()
	{
		
		for (auto it = EntityManager::Instance()._entity_list_stack_.begin(); it != EntityManager::Instance()._entity_list_stack_.end(); ++it)	
		{


			if(it->second->GetComponent<Renderer2D>())
			{
				
				it->second->GetComponent<Renderer2D>()->_texture_->Bind();
				Renderer::Submit(it->second->GetComponent<Renderer2D>()->_vertex_array_square_,
				                 it->second->GetComponent<Renderer2D>()->_texture_shader_,
				                 it->second->GetComponent<Transform>()->GetTransformMatrix(),
								 it->second->GetComponent<Renderer2D>()->_color_);
				
			

				
			}
		}
	}

	void RenderingSystem::Shutdown()
	{
		delete _instance_;
		delete _data_;
	}

}
