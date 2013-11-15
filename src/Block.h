#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <fstream>
#include <vector>
#include "mSDL.h"
#include "constant.h"

using namespace std;

class Block {
    public:
        Block(SDL_Surface * background);
        ~Block();
        //加载地图
        void onMapLoad();
        //绘制地图
        void onMapDraw();
    private:
        //读取文件流
        fstream m_infile;
        SDL_Surface *block[BLOCK_NUM];
        SDL_Surface * m_background;
        //地图的坐标，以及连续块的长度
        vector<int> m_VecXPos;
        vector<int> m_VecYPos;
        vector<int> m_VecLen;
};

#endif
