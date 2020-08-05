#pragma once


#include <map>
#include <vector>

#include "Components.h"

#include "../Logger.h"
#include "Transform/Transform.h"


namespace Engine
{
	class RenderingSystem;


#pragma region  Entityclass
	class Entity
	{
	public:
		Entity(const char* name);
		~Entity();


		void Init();
		void ComponentInit();
		void Update();
		void UpdateOnGUI();
		void End();

		void AttachComponent(Components* component);

		template <class T>
		T* GetComponent();

		std::string GetName() const { return _entity_name_; }
	private:
		std::vector<Components*> _components_list_;


		std::string _entity_name_;


		void AddGameObject();
	};

	template <class T>
	T* Entity::GetComponent()
	{
		
		T* ptr = nullptr;

		for (int i = 0; i < _components_list_.size(); i++)
		{
			//checks if the given component exists in the entity component list;
			ptr = dynamic_cast<T*>(_components_list_.at(i));
			if (ptr)
				break;
		}
		return ptr;


		//for each (Components* components in _components_list_)
		//{
		//	//checks if the given component exists in the entity component list;
		//	if (dynamic_cast<T>(*components))
		//		return (T)(*components);
		//}
		//return nullptr;
	}
#pragma endregion 

#pragma region Entity Manager
	//Singleton Class.
	class EntityManager
	{
		friend RenderingSystem;
	
	public:
		// Delete copy constructor.
		EntityManager(const EntityManager&) = delete;
		EntityManager();
		void Init();
		void Update();
		void UpdateOnGUI();
		void End();
		void AddEntity(Entity* entity);

		int GetGameObjectCount() const { return _entity_list_stack_.size(); }

		int GetEmptyNameGameObjectCount() const { return _empty_name_gameobject_count_; }
		void IncreaseEmptyNameGameObjectCount() { _empty_name_gameobject_count_++; }
		static EntityManager& Instance() { return _instance_; }
	private:

		static EntityManager _instance_;
		int _game_object_count_ = 0;

		int _empty_name_gameobject_count_ = 0;


		std::map<std::string, Entity*> _entity_list_stack_;
		std::map<std::string, SmartPointer<Entity>> _entity_smart_list_stack;
	};

#pragma endregion 



}

