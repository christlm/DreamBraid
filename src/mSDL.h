#ifndef __MSDL_H__
#define __MSDL_H__

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>

extern SDL_Surface *load_image(std::string filename);

extern void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, int ImageOffsetX, int ImageOffsetY);

#endif
