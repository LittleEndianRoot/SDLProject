/*
 * Swarm.cpp
 *
 *  Created on: 6 Apr 2019
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

} /* namespace littleendianroot */
