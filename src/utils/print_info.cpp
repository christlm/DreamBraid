#include "utils/print_info.h"

#include "SDL.h"

int DreamBraid::Utils::PrintRenderDriversInfo(std::ostream& out) {
	SDL_RendererInfo render_info;
	uint32_t driver_num = SDL_GetNumRenderDrivers();
	for (uint32_t i = 0; i < driver_num; ++i) {
		SDL_GetRenderDriverInfo(i, &render_info);
		out << "========== Render Info ==========" << "\n";
		out << "Name:                " << render_info.name << "\n";
		out << "Flags:               " << render_info.flags << "\n";
		out << "Texture formats num: " << render_info.num_texture_formats << "\n";
		out << "Max texture width:   " << render_info.max_texture_width << "\n";
		out << "Max texture height:  " << render_info.max_texture_height << "\n";
		out << "=================================" << "\n\n";

		// value in render_info.texture_formats is all 0 and 372645892, seems meaningless
	}
	return 0;
}