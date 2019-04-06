/*
 * Particle.cpp
 *
 *  Created on: 6 Apr 2019
 *      Author: endian
 */

#include "Particle.h"
#include <stdlib.h>

namespace littleendianroot
{

Particle::Particle()
{
	m_x = ((2.0 * rand())/RAND_MAX) - 1;
	m_y = ((2.0 * rand())/RAND_MAX) - 1;

}

Particle::~Particle()
{
	// TODO Auto-generated destructor stub
}

} /* namespace littleendianroot */
