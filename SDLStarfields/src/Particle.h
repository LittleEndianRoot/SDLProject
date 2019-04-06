/*
 * Particle.h
 *
 *  Created on: 6 Apr 2019
 *      Author: endian
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace littleendianroot
{

struct Particle
{
	double m_x;
	double m_y;

public:
	Particle();
	virtual ~Particle();
};

} /* namespace littleendianroot */

#endif /* PARTICLE_H_ */
