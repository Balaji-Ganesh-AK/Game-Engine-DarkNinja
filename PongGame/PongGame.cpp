

#include <iostream>
#include <../Core.h>
#include <imgui/imgui.h>


Engine::vec3 Position = Engine::vec3(1,1,0);
Engine::vec3 Positiontest;
Engine::vec4 Color = Engine::vec4(1, 0, 0, 1);
std::vector<Engine::Entity*> List;

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
		ImGui::DragFloat2("Square Position", &Positiontest.x);
		ImGui::ColorEdit4("Square Position", &Color.x);
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
	//DNE_CLIENT_TRACE("Level component testing!");
}

void Level::Init()
{
	
	DNE_CLIENT_TRACE("");
}

void Level::End()
{
}


class Pong : public Engine::Application
{
public:
	Engine::Entity* test = new Engine::Entity("BG");
	Engine::Entity* test1 = new Engine::Entity("Test1");
	
	

	
	Engine::vec2 Size;
	Pong();

	void GameLoop() override
	{
			
		test1->GetComponent<Engine::Renderer2D>()->SetColor(Color);
		if (Engine::Input::IsKeyPressed(Engine::KeyCodes::W))
		{
			Position.y += 1.0f* Engine::TimeStamp::DeltaTime();
			test->GetComponent<Engine::Transform>()->SetPosition(Position);
		}
		if (Engine::Input::IsKeyPressed(Engine::KeyCodes::Space))
		{
			test->IsActive = !test->IsActive;
			
		}
		if (Engine::Input::IsKeyPressed(Engine::Key::S))
		{
			Position.y -= 1.0f * Engine::TimeStamp::DeltaTime();
			
			test->GetComponent<Engine::Transform>()->SetPosition(Position);
		}
		if (Engine::Input::IsKeyPressed(Engine::Key::D))
		{
			Position.x += 1.0f * Engine::TimeStamp::DeltaTime();
			test->GetComponent<Engine::Transform>()->SetPosition(Position);
		}
		if (Engine::Input::IsKeyPressed(Engine::Key::A))
		{
			Position.x -= 1.0f * Engine::TimeStamp::DeltaTime();
			test->GetComponent<Engine::Transform>()->SetPosition(Position);
		}
		if (Engine::Input::IsKeyPressed(Engine::Key::Q))
		{
			Size.x += 10 * Engine::TimeStamp::DeltaTime();
			Size.y += 10 * Engine::TimeStamp::DeltaTime();
			test->GetComponent<Engine::Transform>()->SetScale(Size);
		}
		if (Engine::Input::IsKeyPressed(Engine::Key::E))
		{
			Size.x -= 10 * Engine::TimeStamp::DeltaTime();
			Size.y -= 10 * Engine::TimeStamp::DeltaTime();
			test->GetComponent<Engine::Transform>()->SetScale(Size);
		}


	
		
	}
	
	~Pong()
	{
		std::cout << "Game over!!";
	}
};

Pong::Pong()
{
	test->AttachComponent(new Level());

	test->AttachComponent(new Engine::Renderer2D());
	//test->GetComponent<Engine::Renderer2D>()->DrawQuad();
	test->GetComponent<Engine::Renderer2D>()->DrawQuad("Resources/Assets/Textures/Checkerboard.png");
	test->GetComponent<Engine::Transform>()->SetPosition(Position);
	
	test->GetComponent<Engine::Transform>()->SetScale(Engine::vec2(100,100));

	test1->AttachComponent(new Engine::Renderer2D());
	//test->GetComponent<Engine::Renderer2D>()->DrawQuad();
	test1->GetComponent<Engine::Renderer2D>()->DrawQuad();
	test1->GetComponent<Engine::Transform>()->SetPosition(Position);
	test1->GetComponent<Engine::Transform>()->SetRotation(10);
	test1->AttachComponent(new Engine::ParticleSystem());
	
	test->IsActive = false;
	

	
	

	
}

Engine::Application* Engine::CreateApplication()
{
	return new Pong();
}
