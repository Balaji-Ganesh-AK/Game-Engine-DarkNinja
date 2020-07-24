

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

		if (show_another_window)
			ImGui::ShowDemoWindow(&show_another_window);
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

		test->AttachComponent(new Level());
	
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
