/*
 * Swarm.cpp
 *
 *  Created on: 12 Apr 2019
 *      Author: endian
 */

#include "Swarm.h"

namespace littleendianroot
{

Swarm::Swarm():
		lastTime(0)
{
	m_pParticle = new Particle[NPARTICLES];
}

Swarm::~Swarm()
{
	delete [] m_pParticle;
}

void Swarm::update(int elapsedTime)
{
	int interval = elapsedTime - lastTime;

	for(int i = 0; i < Swarm::NPARTICLES; i++)
	{
		m_pParticle[i].update(interval);
	}

	lastTime = elapsedTime;
}

} /* namespace littleendianroot */
