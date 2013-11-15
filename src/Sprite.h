#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "mSDL.h"
#include "constant.h"

class Sprite {
    public:
        Sprite(SDL_Surface * screen);
        ~Sprite();

        //获取精灵x轴坐标
        int get_x_position();
        //获取精灵x轴坐标
        int get_y_position();

        void set_x_position(int offset);
        //精灵移动
        void move_up(int delta);
        void move_down(int delta);
        void move_left(int delta);
        void move_right(int delta);
        void draw_sprite();

    private:
        //精灵移动矩形
        SDL_Rect m_rcSprite;
        //精灵画像
        SDL_Surface * m_sfSprite;
        //屏幕
        SDL_Surface * m_screen;
};

#endif
