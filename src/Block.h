#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <fstream>
#include <vector>
#include "mSDL.h"
#include "constant.h"

using namespace std;

class Block {
    public:
        Block(SDL_Surface * screen);
        ~Block();
        void onDraw(int ImageOffsetX,int ImageOffsetY);
        SDL_Surface *block[BLOCK_NUM];
        SDL_Surface * m_screen;
        fstream m_infile;
    private:
        vector<int> m_VecXPos;
        vector<int> m_VecYPos;
        vector<int> m_VecLen;
};

#endif
