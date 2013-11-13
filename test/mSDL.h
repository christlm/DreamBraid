/* mSDL.h

Functions:

SDL_Surface * openWindow(string, int, int, int);
-initializes all SDL libraries, creates an SDL window surface and creates a caption for it
-also takes the screen height width and bits per pixel as arguments from the main function
-returns pointer to the new window surface pointer

SDL_Surface * load(string); 
-loads images and optimizes them to the display window, takes the filename of the
image as the only argument and outputs a pointer to the SDL_Surface of the 

void apply_image(SDL_Surface *image, SDL_Surface *currentWindow, SDL_Rect * clip, int xpos, int ypos);
-adds an image to the window and updates it
-uses SDL_Surface *, SDL_Rect * and integers to take in the window surface, the image surface, the image offset (clip), and the desired coordinates for the image and updates the SDL window using SDL_Flip after blitting the image and the window surface at the proper coordinates

*/

#ifndef MSDL_H
#define MSDL_H

#include"SDL/SDL.h"		//sdl base library
#include"SDL/SDL_image.h"	//sdl library to deal with functions
#include"SDL/SDL_ttf.h"		//sdl library to deal with text on the screen
#include<string>		//stl library to allow for use of strings
using namespace std;


SDL_Surface *openWindow (string windowCaption = "Default Caption", int windowWidth = 640, int windowHeight = 480, int bpp = 32);


SDL_Surface *load (string imageName);

SDL_Surface *loadBackground (string imageName);

void apply_image (SDL_Surface * image, SDL_Surface * currentWindow, SDL_Rect * clip, int xpos, int ypos);
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, int ImageOffsetX, int ImageOffsetY);
SDL_Surface *load_image( string filename );
#endif
