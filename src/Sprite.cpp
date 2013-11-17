#include "Sprite.h"

Sprite::Sprite(SDL_Surface * screen) {
    m_screen = screen;
    m_sfSprite = load_image(RES_SPRITE_PATH.c_str());
    if (!m_sfSprite) {
        std::cout << "can not load sprite img" << std::endl;
    }
    m_rcSprite.x = SPRITE_START_X;
    m_rcSprite.y = SPRITE_START_Y;
    m_ScreenOffsetX = 0;
    m_ScreenOffsetY = 0;
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
    SDL_BlitSurface(m_sfSprite, NULL, m_screen, &m_rcSprite);
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
        move_left(SP_MOVE_RATE);
    }
    if (keystate[SDLK_RIGHT] ) {
        if (SCREEN_WIDTH - get_x_position() < SCREEN_WIDTH / 4) {
            m_ScreenOffsetX += SCREEN_WIDTH / 4 ;
            set_x_position(-SCREEN_WIDTH / 2);
        }
        move_right(SP_MOVE_RATE);
    }
    if (keystate[SDLK_UP] ) {
        move_up(SP_MOVE_RATE);
    }
    if (keystate[SDLK_DOWN] ) {
        move_down(SP_MOVE_RATE);
    }

    //Update the screen
    move_bg(m_ScreenOffsetX, m_ScreenOffsetY, background, m_screen);
    draw_sprite();
    SDL_Flip(m_screen);
}
