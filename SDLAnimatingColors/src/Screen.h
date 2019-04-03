/*
 * Screen.h
 *
 *  Created on: 3 Apr 2019
 *      Author: endian
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace littleendianroot
{

class Screen
{
private:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

public:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;

public:
	Screen();
	bool init();
	bool processEvents();
	void close();
};

} /* namespace littleendianroot */

#endif /* SCREEN_H_ */
