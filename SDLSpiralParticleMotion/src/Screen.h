/*
 * Screen.h
 *
 *  Created on: 14 Apr 2019
 *      Author: endian
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace littleendianroot
{

class Screen
{
public:
	int const static SCREEN_WIDTH = 800;
	int const static SCREEN_HEIGHT = 600;

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;
	Uint32 *m_blurBuffer;

public:
	Screen();
	bool init();
	void clear();
	void update();
	void boxBlur();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	bool processEvents();
	void close();
};

} /*namespace littleendianroot*/

#endif /* SCREEN_H_ */
