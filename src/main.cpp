#include "init.hpp"
#include "load_media.hpp"
#include "NPC.hpp"
#include "Farms.h"
#include "GameController.h"
#include "Soldiers.h"
#include "Walls.h"

#define TEXTURE_PATH "dot.png"

enum e_dir
{
	RIGHT,
	LEFT
};

int main(int argc, char **argv)
{
	NPC Creation();
	Creation();	
	
	
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Event e;
	int quit;
	SDL_Texture *dot_texture = NULL;
	int diameter = 30;
	int speed = 100; // 100 pixel par seconde
	e_dir dir = RIGHT;
	SDL_Rect dot_rect = {0, screen_height / 2, diameter, diameter};
	double dot_x, shift = 0.0;
	Uint64 clock, time, fpsclock;
	int frames;

	(void)argc;
	(void)argv;

	if (!init_SDL())
		return 1;
	if ((window = init_window()) == NULL)
		return 1;
	if ((renderer = init_window_renderer(window)) == NULL)
		return 1;
	if ((dot_texture = load_media_texture(TEXTURE_PATH, renderer, true)) == NULL)
		return 1;

	quit = false;
	// On init les clocks
	clock = fpsclock = SDL_GetTicks64();
	while (!quit)
	{
		// Calcul du framerate
		if (SDL_GetTicks64() - fpsclock >= 1000)
		{
			std::cout << "FPS: " << frames << '\n';
			frames = 0;
			fpsclock = SDL_GetTicks64();
		}

		// Rendering
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, dot_texture, NULL, &dot_rect);
		SDL_RenderPresent(renderer);
		++frames;

		// Time-dependant speed

		// time : combien de temps s'est passe depuis le dernier mouvement en ms
		time = SDL_GetTicks64() - clock;
		// shift : la vitesse * ( time / 1 seconde ) -> C'est la distance parcourue, vitesse = distance / temps <=> distance = vitesse * temps
		shift = (double)speed * ((double)time / 1000.0);
		// On reset la clock pour le futur calcul de time
		clock = SDL_GetTicks64();

		if (dir == RIGHT)
		{
			dot_x += shift;
			if ((int)dot_x + diameter >= screen_width)
			{
				dir = LEFT;
			}
		}
		else if (dir == LEFT)
		{
			dot_x -= shift;
			if ((int)dot_x <= 0)
			{
				dir = RIGHT;
			}
		}
		dot_rect.x = (int)dot_x;

		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}
	close(window, renderer);
	return 0;
}