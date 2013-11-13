#include"mSDL.h"


SDL_Surface * openWindow (string windowCaption, int windowWidth, int windowHeight, int bpp) {
    SDL_Init (SDL_INIT_EVERYTHING);
    SDL_Surface *tempWindow;
    tempWindow = SDL_SetVideoMode (windowWidth, windowHeight, bpp, SDL_SWSURFACE);
    SDL_WM_SetCaption (windowCaption.c_str (), NULL);
    return tempWindow;
}


SDL_Surface * load (string imageName) {
    if(imageName.empty())
        return NULL;
    SDL_Surface *tempImage = IMG_Load (imageName.c_str ());
    SDL_Surface *optimizeImage = SDL_DisplayFormat (tempImage);
    SDL_SetColorKey (optimizeImage, SDL_SRCCOLORKEY, SDL_MapRGB (optimizeImage->format, 255, 0, 255));
    SDL_FreeSurface (tempImage);
    return optimizeImage;
}


SDL_Surface * loadBackground (string imageName) {
    if(imageName.empty())
        return NULL;

    //loads image based on filename
    SDL_Surface *tempImage = IMG_Load (imageName.c_str ());

    //optimizes image based on window settings
    SDL_Surface *optimizeImage = SDL_DisplayFormat (tempImage);

    //frees original unoptimized image
    SDL_FreeSurface (tempImage);
    return optimizeImage;
}


//puts an image on the surface of the window based on the offset from the origin of the window and where the image is clipped relative to the sprite sheet
void apply_image (SDL_Surface * image, SDL_Surface * currentWindow, SDL_Rect * clip, int xpos, int ypos) {

    SDL_Rect offset;	//set window offsets
    offset.x = xpos;
    offset.y = ypos;

    // makes the window background plain white (no image at this point)
    // adds image to the window surface
    SDL_BlitSurface (image, clip, currentWindow, &offset);

    //updates the window so that current image and position is displayed
    //SDL_Flip (currentWindow);
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, int ImageOffSetX, int ImageOffSetY)
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Give the offsets to the rectangle
    offset.x = x + ImageOffSetX;
    offset.y = y + ImageOffSetY;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

SDL_Surface *load_image( std::string filename )
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




