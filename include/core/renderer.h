#include "SDL.h"

namespace DreamBraid {
	namespace Core {
		class Renderer {
		public:
			Renderer(){}
			~Renderer(){}

			int Init();
			int Destroy();

		private:
			SDL_Window*   m_window;
			SDL_Renderer* m_renderer;
		};
	}
}