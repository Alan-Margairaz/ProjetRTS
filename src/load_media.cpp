#include "load_media.hpp"

SDL_Surface *load_media_raw(std::string file_name, SDL_Surface *screen_surface)
{
	SDL_Surface *surface = NULL;
	SDL_Surface *converted_surface = NULL;

	if ((surface = SDL_LoadBMP(file_name.c_str())) == NULL)
	{
		std::cerr << "Unable to load image " << file_name << ". SDL Error: " << SDL_GetError() << '\n';
		return NULL;
	}
	else if ((converted_surface = SDL_ConvertSurface(surface, screen_surface->format, 0)) == NULL)
	{
		std::cerr << "Unable to convert image " << file_name << ". SDL Error: " << SDL_GetError() << '\n';
	}
	SDL_FreeSurface(surface);
	return converted_surface;
}

SDL_Surface *load_media_converted(std::string file_name, SDL_Surface *screen_surface)
{
	SDL_Surface *surface = NULL;
	SDL_Surface *converted_surface = NULL;

	if ((surface = IMG_Load(file_name.c_str())) == NULL)
	{
		std::cerr << "Unable to load image " << file_name << ". SDL Error: " << IMG_GetError() << '\n';
		return NULL;
	}
	if ((converted_surface = SDL_ConvertSurface(surface, screen_surface->format, 0)) == NULL)
	{
		std::cerr << "Unable to convert image " << file_name << ". SDL Error: " << SDL_GetError() << '\n';
	}
	SDL_FreeSurface(surface);
	return converted_surface;
}

SDL_Texture *load_media_texture(std::string file_name, SDL_Renderer *renderer, bool color_key)
{
	SDL_Texture *texture = NULL;
	SDL_Surface *surface = NULL;

	if ((surface = IMG_Load(file_name.c_str())) == NULL)
	{
		std::cerr << "Unable to load image " << file_name << ". SDL Error: " << IMG_GetError() << '\n';
		return NULL;
	}
	if (color_key)
	{
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	}
	if ((texture = SDL_CreateTextureFromSurface(renderer, surface)) == NULL)
	{
		std::cerr << "Unable to create texture from " << file_name << ". SDL Error: " << SDL_GetError() << '\n';
	}
	SDL_FreeSurface(surface);
	return texture;
}