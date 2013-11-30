#include <iostream>
#include <SDL.h>

int main(int argc, char **argv) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	
	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_RendererInfo render_info;
	int driver_num = SDL_GetNumRenderDrivers();
	for (int i = 0; i < driver_num; ++i) {
		SDL_GetRenderDriverInfo(i, &render_info);
		std::cout << "=== Render Info ===" << std::endl;
		std::cout << "Name: " << render_info.name << std::endl;
		std::cout << "Flags: " << render_info.flags << std::endl;
		std::cout << "Texture formats: " << render_info.num_texture_formats << std::endl;
		std::cout << "Max texture width: " << render_info.max_texture_width << std::endl;
		std::cout << "Max texture height: " << render_info.max_texture_height << std::endl;
		std::cout << std::endl;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr){
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Surface *bmp = SDL_LoadBMP("./res/hello.bmp");
	if (bmp == nullptr){
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
	SDL_FreeSurface(bmp);
	if (tex == nullptr){
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_RenderClear(ren);
	SDL_RenderCopy(ren, tex, NULL, NULL);
	SDL_RenderPresent(ren);

	SDL_Delay(2000);

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();

	SDL_Quit();

	return 0;
}