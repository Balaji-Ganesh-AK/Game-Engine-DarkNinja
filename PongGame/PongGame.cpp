

#include <iostream>
#include <../Core.h>


class Level : public Engine::Components
{
public:

	Level();
	~Level();
	void Update() override;


	void Init() override;


	void End() override;

};
Level::Level()
{
}

Level::~Level()
{
}

void Level::Update()
{
	DNE_CLIENT_TRACE("Level component");
}

void Level::Init()
{
	DNE_CLIENT_TRACE("Created");
}

void Level::End()
{
}


class Pong : public Engine::Application
{
public:
	Pong()
	{
		Engine::Entity* test = new Engine::Entity("Test");

		//test->AttachComponent(new Level());
	
	}
	~Pong()
	{
		std::cout << "Game over!!";
	}
};

Engine::Application* Engine::CreateApplication()
{
	return new Pong();
}
