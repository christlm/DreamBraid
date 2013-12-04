#include "SDL.h"

namespace DreamBraid {
	namespace Core {
		namespace Config {
			const int WINDOW_WIDTH = 1024;
			const int WINDOW_HEIGHT = 768;
			const int WINDOW_POS_X = SDL_WINDOWPOS_CENTERED;
			const int WINDOW_POS_Y = SDL_WINDOWPOS_CENTERED;
			const char* WINDOW_TITLE = "DreamBraid";
			const int WINDOW_FLAGS = SDL_WINDOW_SHOWN;

			const int RENDERER_FLAGS = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
		}
	}
}