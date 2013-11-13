#include "Block.h"

Block::Block(SDL_Surface * screen) {
    this->m_screen = screen;
    m_infile.open( RES_MAP_PATH.c_str());
    if (!m_infile) {
        cerr << "can not open file" << std::endl;
        exit(EXIT_FAILURE);
    }
    int x_start, y_start, elements_of_row;
    int index = 0;
    while ( !m_infile.eof() ) {
        m_infile >> x_start >> y_start >> elements_of_row;
        m_VecXPos.push_back(x_start);
        m_VecYPos.push_back(y_start);
        m_VecLen.push_back(elements_of_row);
        block[index] = load_image(RES_BLOCK_PATH.c_str());
        index ++;
    }
}

void Block::onDraw(int ImageOffsetX,int ImageOffsetY) {
    for (unsigned int i = 0; i < m_VecXPos.size();i++) {
        int x_start = m_VecXPos[i];
        for (int j = 0; j < m_VecLen[i];j++) {
            apply_surface( x_start, m_VecYPos[i], block[i], m_screen,ImageOffsetX,ImageOffsetY);
            x_start += block[i]->w ;
        }
    }
}

Block::~Block() {
    for (unsigned int i = 0; i < m_VecXPos.size();i++)
        SDL_FreeSurface(block[i]);
    m_infile.close();
}
