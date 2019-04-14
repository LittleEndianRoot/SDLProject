/*
 * Particle.h
 *
 *  Created on: 14 Apr 2019
 *      Author: endian
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace littleendianroot
{

struct Particle
{
public:
	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;

private:
	void init();

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

}
#endif /* PARTICLE_H_ */
