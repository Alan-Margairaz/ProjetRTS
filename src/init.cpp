#include "init.hpp"

bool init_SDL()
{
	int img_flags;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL could not initialize. SDL_Error: " << SDL_GetError() << '\n';
		return false;
	}
	img_flags = IMG_INIT_PNG;
	if (!(IMG_Init(img_flags) & img_flags))
	{
		std::cerr << "SDL_image could not initalize. SDL_Error: " << IMG_GetError() << '\n';
		return false;
	}
	return true;
}

SDL_Window *init_window()
{
	SDL_Window *window;

	if ((window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN)) == NULL)
	{
		std::cerr << "Window could not be created. SDL_Error: " << SDL_GetError() << '\n';
		return NULL;
	}
	return window;
}

SDL_Surface *init_window_surface(SDL_Window *window)
{
	SDL_Surface *surface;

	if ((surface = SDL_GetWindowSurface(window)) == NULL)
	{
		std::cerr << "Window surface could not be created. SDL_Error: " << SDL_GetError() << '\n';
		return NULL;
	}
	return surface;
}

SDL_Renderer *init_window_renderer(SDL_Window *window)
{
	SDL_Renderer *renderer;

	if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)) == NULL)
	{
		std::cerr << "Renderer could not be created. SDL_Error: " << SDL_GetError() << '\n';
		return NULL;
	}
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	return renderer;
}

void close(SDL_Window *window, SDL_Renderer *renderer)
{
	SDL_DestroyWindow(window);
	window = NULL;
	if (renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
	}
	SDL_Quit();
}