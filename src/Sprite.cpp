#include "Sprite.h"

void Sprite::init() {
    for (int i = 0 ; i < 4 ;i++) {
        m_clipsRight[i].x = i * SP_WIDTH;
        m_clipsRight[i].y = 0;
        m_clipsRight[i].w = SP_WIDTH;
        m_clipsRight[i].h = SP_HEIGHT;
    }
    for (int i = 0 ; i < 4 ;i++) {
        m_clipsLeft[i].x = SP_WIDTH * i;
        m_clipsLeft[i].y = SP_HEIGHT;
        m_clipsLeft[i].w = SP_WIDTH;
        m_clipsLeft[i].h = SP_HEIGHT;
    }
}

Sprite::Sprite(SDL_Surface * screen) {
    m_screen = screen;
    m_sfSprite = load_image(RES_SPRITE_PATH.c_str());
    m_rcSprite.x = SPRITE_START_X;
    m_rcSprite.y = SPRITE_START_Y;
    m_ScreenOffsetX = 0;
    m_ScreenOffsetY = 0;
    m_frame = 0;
    m_bRight = true;
    m_bLstRight = true;
    init();
    draw_sprite();
}

Sprite::~Sprite() {
    SDL_FreeSurface(m_sfSprite);
}

int Sprite::get_x_position() {
    return m_rcSprite.x;
}

int Sprite::get_y_position() {
    return m_rcSprite.y;
}

void Sprite::set_x_position(int offset) {
    m_rcSprite.x += offset;
}

void Sprite::draw_sprite() {
    if (m_bRight) {
        if ( m_bLstRight == false)
            m_frame = 0;
        SDL_BlitSurface(m_sfSprite, &m_clipsRight[m_frame], m_screen, &m_rcSprite);
    } else {
        if ( m_bLstRight == true)
            m_frame = 0;
        SDL_BlitSurface(m_sfSprite, &m_clipsLeft[m_frame], m_screen, &m_rcSprite);
    }
    m_frame ++;
    //每4个循环一次
    if (m_frame >= 4)
        m_frame = 0;
}

void Sprite::move_up(int delta) {
    if (m_rcSprite.y - delta > 0)
        m_rcSprite.y -= delta;
    else
        m_rcSprite.y -= 0;
    draw_sprite();
}

void Sprite::move_down(int delta) {
    if (m_rcSprite.y + delta < SPRITE_START_Y)
        m_rcSprite.y += delta;
    else
        m_rcSprite.y = SPRITE_START_Y;
    draw_sprite();
}

void Sprite::move_left(int delta) {
    if (m_rcSprite.x - delta > 0)
        m_rcSprite.x -= delta;
    else
        m_rcSprite.x = 0;
    draw_sprite();
}

void Sprite::move_right(int delta) {
    if (m_rcSprite.x + delta < SCREEN_WIDTH)
        m_rcSprite.x += delta;
    else
        m_rcSprite.x = SCREEN_WIDTH ;
    draw_sprite();
}

void Sprite::handle_events(SDL_Surface *background) {
    Uint8 *keystate;
    keystate = SDL_GetKeyState(NULL);

    if (keystate[SDLK_LEFT] ) {
        m_bLstRight = m_bRight;
        m_bRight = false;
        move_left(SP_MOVE_RATE);
    }
    if (keystate[SDLK_RIGHT] ) {
        if (SCREEN_WIDTH - get_x_position() < SCREEN_WIDTH / 4) {
            m_ScreenOffsetX += SCREEN_WIDTH / 4 ;
            set_x_position(-SCREEN_WIDTH / 2);
        }
        move_right(SP_MOVE_RATE);
        m_bLstRight = m_bRight;
        m_bRight = true;
    }
    if (keystate[SDLK_UP] ) {
        move_up(SP_MOVE_RATE);
    }
    if (keystate[SDLK_DOWN] ) {
        move_down(SP_MOVE_RATE);
    }

    //Update the screen
    SDL_Rect rectBg;
    rectBg.x = m_ScreenOffsetX;
    rectBg.y = m_ScreenOffsetY;
    rectBg.w = RES_BACKGROUND_WIDTH;
    rectBg.h = RES_BACKGROUND_HEIGHT;

    move_bg(&rectBg, background, m_screen);
    draw_sprite();
    SDL_Flip(m_screen);
}
