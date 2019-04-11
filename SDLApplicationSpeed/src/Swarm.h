/*
 * Swarm.h
 *
 *  Created on: 11 Apr 2019
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
	const static int NPARTICLES = 5000;

private:
	Particle *m_pParticle;
	int lastTime;

public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsedTime);

	const Particle *const getParticle() { return m_pParticle; }
};

} /* namespace littleendianroot */

#endif /* SWARM_H_ */
