

#include <iostream>
#include <Core.h>



class Pong : public Engine::Application
{
public:
	Pong()
	{}
	~Pong()
	{
		std::cout << "Game over!!";
	}
};

Engine::Application* Engine::CreateApplication()
{
	return new Pong();
}
