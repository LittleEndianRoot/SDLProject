/*
 * Swarm.cpp
 *
 *  Created on: 9 Apr 2019
 *      Author: endian
 */

#include "Swarm.h"

namespace littleendianroot
{

Swarm::Swarm()
{
	m_pParticle = new Particle[NPARTICLES];

}

Swarm::~Swarm()
{
	delete [] m_pParticle;
}

void Swarm::update()
{
	for(int i = 0; i < Swarm::NPARTICLES; i++)
	{
		m_pParticle[i].update();
	}
}

} /* namespace littleendianroot */
