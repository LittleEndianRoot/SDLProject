/*
 * Particles.h
 *
 *  Created on: 9 Apr 2019
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

	double m_xspeed;
	double m_yspeed;

public:
	Particle();
	virtual ~Particle();
	void update();
};

} /* namespace littleendianroot */

#endif /* PARTICLE_H_ */
