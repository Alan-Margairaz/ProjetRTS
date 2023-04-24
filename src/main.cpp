#include "init.hpp"
#include "load_media.hpp"
#include "Farms.h"
#include "GameController.h"
#include "Soldiers.h"
#include "Walls.h"
#include "defs.h"
#include "structs.h"
#include "SDL.h"
#include "SDL_image.h"
/*
#define TEXTURE_PATH "dot.png"

int main(int argc, char **argv)
{
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

*/


// La fonction pour charger une texture à partir d'un fichier
SDL_Texture* loadTexture(SDL_Renderer* renderer, const std::string& filename) {
  SDL_Texture* texture = nullptr;
  SDL_Surface* surface = IMG_Load(filename.c_str());
  if (surface) {
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
  }
  return texture;
}

int main(int argc, char* argv[]) {
	(void) argc;
	(void) argv;

  // Initialisation de SDL2
  SDL_Init(SDL_INIT_VIDEO);

  // Création de la fenêtre
  SDL_Window* window = SDL_CreateWindow("Map de jeu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MAP_TILE_SIZE*MAP_HEIGHT, MAP_TILE_SIZE*MAP_WIDTH, SDL_WINDOW_SHOWN);

  // Création du renderer
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // Chargement des textures
  SDL_Texture* grassTexture = loadTexture(renderer, "tiles/tile1.png");
  SDL_Texture* treeTexture = loadTexture(renderer, "tiles/tile2.png");
  SDL_Texture* stoneTexture = loadTexture(renderer, "tiles/tile3.png");

  int index[MAP_WIDTH][MAP_HEIGHT] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  };
  Tile map[MAP_WIDTH][MAP_HEIGHT];

  // Initialisation de la carte
  for (int y = 0; y < MAP_WIDTH; y++) {
	for (int x = 0; x < MAP_HEIGHT; x++) {
  // Choix aléatoire d'un type de tuile
  switch (index[x][y]) {
    case 0:
      map[x][y].type = GRASS;
      map[x][y].texture = grassTexture;
      break;
    case 1:
      map[x][y].type = TREE;
      map[x][y].texture = treeTexture;
      break;
    case 2:
      map[x][y].type = STONE;
      map[x][y].texture = stoneTexture;
      break;
  }
}
}

// Boucle principale du jeu
bool quit = false;
while (!quit) {
// Gestion des événements
SDL_Event event;
while (SDL_PollEvent(&event)) {
if (event.type == SDL_QUIT) {
quit = true;
}
}// Effacement de l'écran
SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
SDL_RenderClear(renderer);

// Affichage de la carte
for (int x = 0; x < MAP_WIDTH; x++) {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    SDL_Rect rect = {x * MAP_TILE_SIZE, y * MAP_TILE_SIZE, MAP_TILE_SIZE, MAP_TILE_SIZE};
    SDL_RenderCopy(renderer, map[x][y].texture, nullptr, &rect);
  }
}

// Affichage de l'écran
SDL_RenderPresent(renderer);
}

// Libération des textures
SDL_DestroyTexture(grassTexture);
SDL_DestroyTexture(treeTexture);
SDL_DestroyTexture(stoneTexture);

// Fermeture de SDL2
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
IMG_Quit();
SDL_Quit();

return 0;
}