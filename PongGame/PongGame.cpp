

#include <iostream>
#include <Core.h>



class Pong : public Engine::Application
{
public:
	Pong()
	{}
	~Pong()
	{}
};

Engine::Application* Engine::CreateApplication()
{
	return new Pong();
}
