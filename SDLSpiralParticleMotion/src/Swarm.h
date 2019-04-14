/*
 * Swarm.h
 *
 *  Created on: 14 Apr 2019
 *      Author: endian
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace littleendianroot
{

class Swarm
{
public:
	int const static NPARTICLES = 5000;

private:
	Particle *m_pParticle;
	int lastTime;

public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsedTime);

	Particle const * const getParticle() { return m_pParticle; }
};

}
#endif /* SWARM_H_ */
