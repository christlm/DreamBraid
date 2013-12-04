#include "core/renderer.h"
#include "core/config.h"

using namespace DreamBraid::Core;

int Renderer::Init() {
	m_window = ::SDL_CreateWindow(Config::WINDOW_TITLE, Config::WINDOW_POS_X, 
								  Config::WINDOW_POS_Y, Config::WINDOW_WIDTH,
								  Config::WINDOW_HEIGHT, Config::WINDOW_FLAGS);
	if (m_window == nullptr) {
		return -1;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, Config::RENDERER_FLAGS);
	if (m_renderer == nullptr) {
		return 1;
	}
}