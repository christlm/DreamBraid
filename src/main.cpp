#include "Block.h"
#include "Sprite.h"

//The image offsets. BAD implement
int ImageOffsetX = 0;
int ImageOffsetY = 0;

//The surfaces that will be used
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface( background );
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    bool quit = false;
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return 1;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Hello World", NULL );

    //Load the images
    background = load_image(RES_BACKGROUND_PATH.c_str());
    Block gl_block(screen);
    Sprite sprite(screen);

    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }

    while( quit == false )
    {
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }

            if (event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                        //ImageOffsetY -= 10;
                        sprite.move_up(+10);
                        break;
                    case SDLK_DOWN:
                        //ImageOffsetY += 10;
                        sprite.move_up(-10);
                        break;
                    case SDLK_LEFT:
                        ImageOffsetX += 10;
                        sprite.move_left(-10);
                        break;
                    case SDLK_RIGHT:
                        ImageOffsetX -= 10;
                        sprite.move_right(10);
                        break;
                    default:
                        break;
                }
            }

            //TODO: ugly code!
            //重绘背景和阶梯，向左移动时会有残影
            //Update the screen
            apply_surface( 0, 0, background, screen,ImageOffsetX,ImageOffsetY);
            gl_block.onDraw(ImageOffsetX,ImageOffsetY);
            sprite.draw_sprite();
            if( SDL_Flip( screen ) == -1 )
            {
                return 1;
            }
        }
    }
    clean_up();
    return 0;
}
