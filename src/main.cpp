#include "Block.h"
#include "Sprite.h"

//The image offsets. BAD implement
int ImageOffsetX = 0;
int ImageOffsetY = 0;

int ScreenOffsetX = 0;
int ScreenOffsetY = 0;
int Screen_X_Left = 0;
int Screen_X_Right = SCREEN_WIDTH;
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
    Block gl_block(screen);
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

        /* handle sprite movement */
        keystate = SDL_GetKeyState(NULL);

        if (keystate[SDLK_LEFT] ) {
            sprite.move_left(SP_MOVE_RATE);
        }
        if (keystate[SDLK_RIGHT] ) {
            if (Screen_X_Right - sprite.get_x_position() < SCREEN_WIDTH / 4) {
                ScreenOffsetX += SCREEN_WIDTH / 4 ;
                Screen_X_Right += ScreenOffsetX;
                Screen_X_Left += ScreenOffsetX;
                sprite.set_x_position(-ScreenOffsetX);
                cout << "here" << endl;
            }
            sprite.move_right(SP_MOVE_RATE);
        }
        if (keystate[SDLK_UP] ) {
            sprite.move_up(SP_MOVE_RATE);
        }
        if (keystate[SDLK_DOWN] ) {
            sprite.move_down(SP_MOVE_RATE);
        }

        //TODO: ugly code!
        //重绘背景和阶梯，向左移动时会有残影
        //Update the screen
        //apply_surface( 0, 0, background, screen,ImageOffsetX,ImageOffsetY);
        move_bg(ScreenOffsetX, ScreenOffsetY, background, screen);
        //gl_block.onDraw(ImageOffsetX,ImageOffsetY);
        sprite.draw_sprite();
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
    }
    clean_up();
    return 0;
}
