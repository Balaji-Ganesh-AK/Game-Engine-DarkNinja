#include "pch.h"
#include  "Entity.h"

Engine::EntityManager Engine::EntityManager::_instance_;
//Engine::EntityManager EntityManagerMain;
namespace Engine
{

	Entity::Entity(const char* name):_entity_name_(name ? _strdup(name): nullptr)
	{
		Init();
	}

	Entity::~Entity()
	{
	}

	void Entity::Init()
	{
		if (_entity_name_ == "")
		{
			EntityManager::Instance().IncreaseEmptyNameGameObjectCount();
			//EntityManagerMain.IncreaseEmptyNameGameObjectCount();
			_entity_name_ = "EmptyGameObject ";
			_entity_name_ += std::to_string(EntityManager::Instance().GetEmptyNameGameObjectCount());
			//_entity_name_ += std::to_string(EntityManagerMain.GetEmptyNameGameObjectCount());
		}

		AddGameObject();
	}

	void Entity::Update()
	{

		for(int i = 0; i<_components_list_.size(); i ++)
		{
			_components_list_[i]->Update();
		}
	}

	void Entity::End()
	{
	}

	void Entity::AttachComponent(Components* component)
	{
		if(component)
		{
			_components_list_.push_back(component);
		}
	}

	void Entity::AddGameObject()
	{
		EntityManager::Instance().AddEntity(this);
		//EntityManagerMain.AddEntity(this);
	}

	EntityManager::EntityManager()
	{
	}

	void EntityManager::Update()
	{
		for(auto it= EntityManager::Instance()._entity_list_stack_.begin(); it!= EntityManager::Instance()._entity_list_stack_.end(); ++it)
		{
			it->second->Update();
		}

	}

	void EntityManager::AddEntity(Entity* entity)
	{
		_entity_list_stack_.insert({entity->GetName(), entity});
	}

	

}
