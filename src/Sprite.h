#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "mSDL.h"
#include "constant.h"

class Sprite {
    public:
        Sprite(SDL_Surface * screen);
        ~Sprite();
        int get_x_position();
        int get_y_position();
        void move_up(int delta);
        void move_down(int delta);
        void move_left(int delta);
        void move_right(int delta);
        void draw_sprite();
        

    private:
        SDL_Rect m_rcSprite;
        SDL_Surface * m_sfSprite;
        SDL_Surface * m_screen;
};

#endif
