#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "mSDL.h"
#include "constant.h"

class Sprite {
    public:
        Sprite(SDL_Surface * screen);
        ~Sprite();
        //获取整张sprite各个状态的图像
        void init();

        //获取精灵x轴坐标
        int get_x_position();
        //获取精灵x轴坐标
        int get_y_position();
        //设置精灵坐标
        void set_x_position(int offset);

        //精灵移动
        void move_up(int delta);
        void move_down(int delta);
        void move_left(int delta);
        void move_right(int delta);

        //绘画精灵
        void draw_sprite();

        //响应键盘输入
        void handle_events(SDL_Surface * background);

    private:
        //精灵移动矩形
        SDL_Rect m_rcSprite;
        //精灵向右移动
        SDL_Rect m_clipsRight[4];
        //精灵向左移动
        SDL_Rect m_clipsLeft[4];
        //精灵画像
        SDL_Surface * m_sfSprite;
        //屏幕
        SDL_Surface * m_screen;
        int m_ScreenOffsetX;
        int m_ScreenOffsetY;
        int m_frame;
        //判断当前是否是向右
        bool m_bRight;
        //判断前次是否是向右
        bool m_bLstRight;
};

#endif
