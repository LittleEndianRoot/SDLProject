/*
 * Swarm.h
 *
 *  Created on: 9 Apr 2019
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

public:
	Swarm();
	virtual ~Swarm();
	void update();

	const Particle *const getParticles() { return m_pParticle; }
};

} /* namespace littleendianroot */

#endif /* SWARM_H_ */
