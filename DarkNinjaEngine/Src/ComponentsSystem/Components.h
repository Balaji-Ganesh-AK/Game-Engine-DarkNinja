#pragma once
namespace Engine
{
	class Components
	{

	public:
	
		virtual ~Components() = default;

		virtual void Init() =0;
		virtual void Update() =0 ;
		virtual void End() =0 ;

		//Can create custom GUI window for a particular component;
		virtual void OnGUI() {};
	};

	
}


