#include "core/renderer.h"

namespace DreamBraid {
	namespace Core {
		class Game {
		public:
			static Game& GetInstance() {
				static Game instance;
				return instance;
			}
			void Destoy();

		private:
			Game(){}
			Game(Game const&);
			void operator=(Game const&);

		public:
			int InitRenderer();

		private:
			Renderer* m_renderer;
		};
	}
}