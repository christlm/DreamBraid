#include "mSDL.h"

SDL_Surface *load_image(std::string filename)
{
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
    //Return the optimized image
    return optimizedImage;
}


void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, int ImageOffsetX, int ImageOffsetY)
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Give the offsets to the rectangle
    offset.x = x + ImageOffsetX;
    offset.y = y + ImageOffsetY;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

void move_bg( int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, &offset, destination, NULL);
}
