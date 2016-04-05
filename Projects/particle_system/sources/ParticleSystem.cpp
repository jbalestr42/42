#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(void) :
	m_particleCount(10u)
{ }

ParticleSystem::ParticleSystem(ParticleSystem const & particleSystem)
{
	*this = particleSystem;
}

ParticleSystem::~ParticleSystem(void) { }

ParticleSystem & ParticleSystem::operator=(ParticleSystem const & particleSystem)
{
	(void)particleSystem;
	return (*this);
}
