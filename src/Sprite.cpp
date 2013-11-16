#include "Sprite.h"

Sprite::Sprite(SDL_Surface * screen) {
    m_screen = screen;
    m_sfSprite = load_image(RES_SPRITE_PATH.c_str());
    if (!m_sfSprite) {
        std::cout << "can not load sprite img" << std::endl;
    }
    m_rcSprite.x = SPRITE_START_X;
    m_rcSprite.y = SPRITE_START_Y;
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

