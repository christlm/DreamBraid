#include "core/game.h"

using namespace DreamBraid::Core;

int Game::InitRenderer() {
	m_renderer = new Renderer();
	return 0;
}