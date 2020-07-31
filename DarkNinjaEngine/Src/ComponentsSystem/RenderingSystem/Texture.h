#pragma once

namespace Engine
{
	class Texture
	{
	public:
		


		virtual void Bind(uint32_t slot =0) const = 0;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetData(void* data, uint32_t size)const =0;
	};


	//Specific for all 2D Texture
	class Texture2D:public Texture
	{
	public:
		//Gets the file path of the 
		
		static std::shared_ptr<Texture2D> Create(const std::string& path);
		static std::shared_ptr<Texture2D> Create(uint32_t width, uint32_t height);
		//static Texture2D* Create(const std::string& path);
		
	};
}
