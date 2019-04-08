/*
 * Swarm.cpp
 *
 *  Created on: 7 Apr 2019
 *      Author: endian
 */

#include "Swarm.h"

namespace littleendianroot
{

Swarm::Swarm()
{
	m_pParticles = new Particle[NPARTICLES];

}

Swarm::~Swarm()
{
	delete [] m_pParticles;
}

void Swarm::update()
{
	for(int i = 0; i < Swarm::NPARTICLES; i++)
	{
		m_pParticles[i].update();
	}
}

} /* namespace littleendianroot */
