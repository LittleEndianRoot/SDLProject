/*
 * Particle.cpp
 *
 *  Created on: 11 Apr 2019
 *      Author: endian
 */
#include <stdlib.h>
#include <math.h>
#include "Particle.h"

namespace littleendianroot
{

Particle::Particle():
		m_x(0), m_y(0)
{
	m_direction = (2.0 * M_PI * rand())/RAND_MAX;
	m_speed = (0.0001 * rand())/RAND_MAX;

}

Particle::~Particle()
{

}

void Particle::update(int interval)
{
	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	m_x += xspeed * interval;
	m_y += yspeed * interval;
}

} /* namespace littleendianroot */
