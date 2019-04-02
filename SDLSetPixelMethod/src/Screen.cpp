/*
 * Screen.cpp
 *
 *  Created on: 2 Apr 2019
 *      Author: endian
 */

#include <iostream>
#include "Screen.h"

using namespace std;

namespace littleendianroot
{

Screen::Screen():
		m_window, m_renderer, m_texture, m_buffer
{
	// TODO Auto-generated constructor stub

}

bool Screen::init()
{

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "INFO: Failed to initialise video." << endl;
		cout << "ERROR: " << SDL_GetError() << endl;
		SDL_Quit();
		return false;
	}

	m_window = SDL_CreateWindow("Particle Fire Explosion",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDWOPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_Window_SHOWN);

	if(m_window == NULL)
	{
		cout << "INFO: Failed to create m_window" << endl;
		cout << "ERROR: " << SDL_GetError() << endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_Createm_renderer(m_window, -1, SDL_m_renderer_PRESENTVSYNC);

	if(m_renderer == NULL)
	{
		cout << "INFO: Could not create m_renderer" << endl;
		cout << "ERROR: " << SDL_GetError() << endl;
		SDL_Destroym_window(m_window);
		SDL_Destroym_renderer(m_renderer);
		SDL_Quit();
		return false;
	}

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TextureACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if(m_texture == NULL)
	{
		cout << "INFO: Could not create m_texture" << endl;
		cout << "ERROR: " << SDL_GetError() << endl;
		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texture);
		SDL_Quit();
		return false;
	}



	return true;
}

bool Screen::events()
{

	return true;
}

void Screen::close()
{

}


} /* namespace littleendianroot */
