#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

SDL_Surface *load_media_raw(std::string file_name, SDL_Surface *screen_surface);
SDL_Surface *load_media_converted(std::string file_name, SDL_Surface *screen_surface);
SDL_Texture *load_media_texture(std::string file_name, SDL_Renderer *renderer, bool color_key);