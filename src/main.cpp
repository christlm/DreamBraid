#include "Block.h"
#include "Sprite.h"

int ScreenOffsetX = 0;
int ScreenOffsetY = 0;
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
    Uint8 *keystate;
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
    SDL_WM_SetCaption( "Braid's Road", NULL );

    //Load the images
    background = load_image(RES_BACKGROUND_PATH.c_str());
    if (!background)
    {
        cout << "load background image failed." << endl;
    }
    Block gl_block(background);
    Sprite sprite(screen);

    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }

    while (!quit)
    {
        if (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;

                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                        case SDLK_q:
                            quit = true;
                            break;
                    }
                    break;
            }
        }

        keystate = SDL_GetKeyState(NULL);

        if (keystate[SDLK_LEFT] ) {
            sprite.move_left(SP_MOVE_RATE);
        }
        if (keystate[SDLK_RIGHT] ) {
            if (SCREEN_WIDTH - sprite.get_x_position() < SCREEN_WIDTH / 4) {
                ScreenOffsetX += SCREEN_WIDTH / 4 ;
                sprite.set_x_position(-SCREEN_WIDTH / 2);
            }
            sprite.move_right(SP_MOVE_RATE);
        }
        if (keystate[SDLK_UP] ) {
            sprite.move_up(SP_MOVE_RATE);
        }
        if (keystate[SDLK_DOWN] ) {
            sprite.move_down(SP_MOVE_RATE);
        }

        //Update the screen
        move_bg(ScreenOffsetX, ScreenOffsetY, background, screen);
        sprite.draw_sprite();
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
    }
    clean_up();
    return 0;
}
