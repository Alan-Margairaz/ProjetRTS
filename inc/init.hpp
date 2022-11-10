#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

constexpr int screen_width = 900;
constexpr int screen_height = 600;

bool init_SDL();
SDL_Window *init_window();
SDL_Surface *init_window_surface(SDL_Window *window);
SDL_Renderer *init_window_renderer(SDL_Window *window);
void close(SDL_Window *window, SDL_Renderer *renderer);