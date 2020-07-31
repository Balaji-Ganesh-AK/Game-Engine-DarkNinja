

#include <iostream>
#include <../Core.h>
#include <imgui/imgui.h>





class Level : public Engine::Components
{
public:
	bool show_another_window;
	
	Level();
	~Level();
	void Update() override;


	void Init() override;


	void End() override;

	void OnGUI() override
	{
		
		ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
		ImGui::Text("Hello from another window!");
		if (ImGui::Button("Close Me"))
			show_another_window = false;
		if(ImGui::Button("Show Me"))
			show_another_window = true;
		ImGui::End();

		
	}

};
Level::Level():show_another_window(true)
{
	
}

Level::~Level()
{
}

void Level::Update()
{
	DNE_CLIENT_TRACE("Level component testing!");
}

void Level::Init()
{
	
	DNE_CLIENT_TRACE("asdasd3");
}

void Level::End()
{
}


class Pong : public Engine::Application
{
public:
	Engine::Entity* test = new Engine::Entity("Test");
	Engine::Entity* test1 = new Engine::Entity("Test1");
	Engine::vec3 Position;
	Engine::vec2 Size;
	Pong()
	{

		test->AttachComponent(new Level());
		
		test->AttachComponent(new Engine::Renderer2D());
		test->GetComponent<Engine::Renderer2D>()->DrawQuad("", Engine::vec2(2, 2));
		
		test1->AttachComponent(new Engine::Renderer2D());
		test1->GetComponent<Engine::Renderer2D>()->DrawQuad(Engine::vec4(1, 0, 1, 1), Engine::vec2(1, 1));
	

		
	}
	void GameLoop() override
	{
		if (Engine::Input::IsKeyPressed(Engine::KeyCodes::W))
		{
			Position.y += 0.1f* Engine::TimeStamp::DeltaTime();
			test->GetComponent<Engine::Renderer2D>()->SetPosition(Position);
		}
		if (Engine::Input::IsKeyPressed(Engine::KeyCodes::Space))
		{

			test->GetComponent<Engine::Renderer2D>()->SetScale(Engine::vec2(10, 10));
		}
		if (Engine::Input::IsKeyPressed(Engine::Key::S))
		{
			Position.y -= 0.1f * Engine::TimeStamp::DeltaTime();
			
			test->GetComponent<Engine::Renderer2D>()->SetPosition(Position);
		}
		if (Engine::Input::IsKeyPressed(Engine::Key::D))
		{
			Position.x += 0.1f * Engine::TimeStamp::DeltaTime();
			test->GetComponent<Engine::Renderer2D>()->SetPosition(Position);
		}
		if (Engine::Input::IsKeyPressed(Engine::Key::A))
		{
			Position.x -= 0.1f * Engine::TimeStamp::DeltaTime();
			test->GetComponent<Engine::Renderer2D>()->SetPosition(Position);
		}
		if (Engine::Input::IsKeyPressed(Engine::Key::Q))
		{
			Size.x += 10 * Engine::TimeStamp::DeltaTime();
			Size.y += 10 * Engine::TimeStamp::DeltaTime();
			test->GetComponent<Engine::Renderer2D>()->SetScale(Size);
		}
		if (Engine::Input::IsKeyPressed(Engine::Key::E))
		{
			Size.x -= 10 * Engine::TimeStamp::DeltaTime();
			Size.y -= 10 * Engine::TimeStamp::DeltaTime();
			test->GetComponent<Engine::Renderer2D>()->SetScale(Size);
		}
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
