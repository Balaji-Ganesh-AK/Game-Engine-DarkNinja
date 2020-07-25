#pragma once
#include "ComponentsSystem/Components.h"


namespace Engine
{
	class TextureComponent
	{
	public:
		
	/*	virtual void Init() ;
		virtual void Update() ;
		virtual void End() ;*/

		virtual void Bind(uint32_t slot =0) const = 0;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
	};


	//Specific for all 2D Texture
	class Texture2D:public TextureComponent
	{
	public:
		//Gets the file path of the 
		
		static std::shared_ptr<Texture2D> Create(const std::string& path);
		//static Texture2D* Create(const std::string& path);
		
	};
}
