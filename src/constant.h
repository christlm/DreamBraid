#ifndef __CONSTANT_HPP__
#define __CONSTANT_HPP__


//The attributes of the screen
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
const int BLOCK_NUM = 10;

//The attributes of the resource
const std::string RES_MAP_PATH = "../res/map.txt";
const std::string RES_BLOCK_PATH = "../res/block.png";
const std::string RES_BACKGROUND_PATH = "../res/background.png";
const std::string RES_SPRITE_PATH = "../res/sprite.png";

// Better write this value into map file
const int RES_BACKGROUND_WIDTH = 3786;
const int RES_BACKGROUND_HEIGHT = 620;

//精灵开始起点
const int SPRITE_START_X = 0;
const int SPRITE_START_Y = 400;

//背景移动速度
const int BG_MOVE_RATE = 10;
const int BG_LENGTH = 3786;
//精灵移动速度
const int SP_MOVE_RATE = 1;

const int SP_WIDTH = 49;
const int SP_HEIGHT = 46;

//Frame Per Second
const int FRAMES_PER_SECOND = 10;
#endif
