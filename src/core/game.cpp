#include "core/game.h"

using namespace DreamBraid::Core;

int Game::Init() {
	m_renderer = new Renderer();
	
	int result = m_renderer->Init();
	if (result != 0) {
		return -1;
	}

	return 0;
}

int Game::Destoy() {
	m_renderer->Destroy();
	delete m_renderer;
	m_renderer = nullptr;

	return 0;
}