#include "pch.h"
#include "ParticleSystem2D.h"

#include "glm/glm/gtc/constants.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include "ComponentsSystem/RenderingSystem/Renderer2D.h"
#include "glm/glm/gtx/compatibility.hpp"
#include "Utlis/TimeStamp.h"

namespace Engine
{
	

std::mt19937 Random::s_RandomEngine;
std::uniform_int_distribution<std::mt19937::result_type> Random::s_Distribution;


ParticleSystem::ParticleSystem()
{
	m_ParticlePool.resize(1000);
}

void ParticleSystem::Init()
{
	InitParticles();
}

void ParticleSystem::Update()
{
	UpdateParticles();
	RenderParticles();
}

void ParticleSystem::End()
{
}


void ParticleSystem::Emit(const ParticleProps& particleProps)
{
	Particle& particle = m_ParticlePool[m_PoolIndex];
	particle.Active = true;
	particle.Position = particleProps.Position;
	particle.Rotation = Random::Float() * 2.0f * glm::pi<float>();

	// Velocity
	particle.Velocity = particleProps.Velocity;
	particle.Velocity.x += particleProps.VelocityVariation.x * (Random::Float() - 0.5f);
	particle.Velocity.y += particleProps.VelocityVariation.y * (Random::Float() - 0.5f);

	// Color
	particle.ColorBegin = particleProps.ColorBegin;
	particle.ColorEnd = particleProps.ColorEnd;

	particle.LifeTime = particleProps.LifeTime;
	particle.LifeRemaining = particleProps.LifeTime;
	particle.SizeBegin = particleProps.SizeBegin + particleProps.SizeVariation * (Random::Float() - 0.5f);
	particle.SizeEnd = particleProps.SizeEnd;

	m_PoolIndex = --m_PoolIndex % m_ParticlePool.size();
}

void ParticleSystem::UpdateParticles()
{
	for (auto& particle : m_ParticlePool)
	{
		if (!particle.Active)
			continue;

		if (particle.LifeRemaining <= 0.0f)
		{
			particle.Active = false;
			continue;
		}

		particle.LifeRemaining -= Engine::TimeStamp::DeltaTime();
		particle.Position += particle.Velocity * (float)Engine::TimeStamp::DeltaTime();
		particle.Rotation += 0.01f * Engine::TimeStamp::DeltaTime();
	}


	for(auto& particle :List)
	{
		if(!particle->IsActive)
			continue;


		/*float tempLifeRemainig = particle->GetComponent<ParticleSystem>()->_particle_.LifeRemaining;
		if (tempLifeRemainig <= 0.0f)
		{
			particle->IsActive = false;
			continue;
		}*/

		//tempLifeRemainig -= Engine::TimeStamp::DeltaTime();
		Velocity.x +=(Random::Float() - 0.5f);
		Velocity.y += (Random::Float() - 0.5f);

		vec3 tempPos= Velocity * (float)Engine::TimeStamp::DeltaTime();
		particle->GetComponent<Transform>()->SetPosition(tempPos);
	
	}
}

void ParticleSystem::RenderParticles()
{
	for (auto& particle : m_ParticlePool)
	{
		if (!particle.Active)
			continue;

		// Fade away particles
		float life = particle.LifeRemaining / particle.LifeTime;
		glm::vec4 color = glm::lerp(particle.ColorEnd, particle.ColorBegin, life);
		//color.a = color.a * life;

		float size = glm::lerp(particle.SizeEnd, particle.SizeBegin, life);
	}

		

}

void ParticleSystem::InitParticles()
{
	for (int i = 0; i < 1000; i++)
	{
		Engine::Entity* testt = new Engine::Entity("");
		testt->AttachComponent(new Engine::Renderer2D());
		testt->GetComponent<Engine::Renderer2D>()->DrawQuad();
		
		


		List.push_back(testt);
	}
}

}