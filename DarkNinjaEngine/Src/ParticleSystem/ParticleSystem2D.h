#pragma once


#include <glm/glm/vec2.hpp>
#include <glm/glm/vec4.hpp>

#include "ComponentsSystem/Components.h"
#include "ComponentsSystem/Entity.h"
#include "ComponentsSystem/RenderingSystem/Camera.h"
#include <random>
#undef min
#undef max
namespace Engine
{

struct ParticleProps
{
	glm::vec2 Position;
	glm::vec2 Velocity, VelocityVariation;
	glm::vec4 ColorBegin, ColorEnd;
	float SizeBegin, SizeEnd, SizeVariation;
	float LifeTime = 1.0f;
};


class Random
{
public:
	static void Init()
	{
		s_RandomEngine.seed(std::random_device()());
	}

	static float Float()
	{
		return (float)s_Distribution(s_RandomEngine) / (float)std::numeric_limits<uint32_t>::max();
	}

private:
	static std::mt19937 s_RandomEngine;
	static std::uniform_int_distribution<std::mt19937::result_type> s_Distribution;
};
	
class ParticleSystem:public Engine::Components
{
public:
	ParticleSystem();

	void Init() override;
	void Update() override;
	void End() override;

	void Emit(const ParticleProps& particleProps);
private:

	void UpdateParticles();
	void RenderParticles();
	void InitParticles();
	
	struct Particle
	{
		glm::vec2 Position;
		glm::vec2 Velocity;
		glm::vec4 ColorBegin, ColorEnd;
		float Rotation = 0.0f;
		float SizeBegin, SizeEnd;

		float LifeTime = 1.0f;
		float LifeRemaining = 0.0f;

		bool Active = false;
	};
	Particle _particle_;
	std::vector<Particle> m_ParticlePool;
	uint32_t m_PoolIndex = 999;
	std::vector<Engine::Entity*> List;
	vec3 Velocity, VelocityVariation;

};
}