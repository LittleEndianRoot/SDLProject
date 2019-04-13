/*
 * Particle.h
 *
 *  Created on: 12 Apr 2019
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

	double m_speed;
	double m_direction;

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

} /* namespace littleendianroot */

#endif /* PARTICLE_H_ */
