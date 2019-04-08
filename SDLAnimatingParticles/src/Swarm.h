/*
 * Swarm.h
 *
 *  Created on: 7 Apr 2019
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
	const static int NPARTICLES = 1000;

private:
	Particle *m_pParticles;

public:
	Swarm();
	virtual ~Swarm();
	void update();

	const Particle *const getParticle() { return m_pParticles; }
};

} /* namespace littleendianroot */

#endif /* SWARM_H_ */
