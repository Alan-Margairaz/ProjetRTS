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

// La fonction pour charger une texture à partir d'un fichier
SDL_Texture *loadTexture(SDL_Renderer *renderer, const std::string &filename)
{
	SDL_Texture *texture = nullptr;
	SDL_Surface *surface = IMG_Load(filename.c_str());
	if (surface)
	{
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
	}
	return texture;
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	// Initialisation de SDL2
	SDL_Init(SDL_INIT_VIDEO);

	// Création de la fenêtre
	SDL_Window *window = SDL_CreateWindow("GameWindow", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MAP_TILE_SIZE * MAP_HEIGHT, MAP_TILE_SIZE * MAP_WIDTH, SDL_WINDOW_SHOWN);

	// Création du renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// Chargement des textures
	SDL_Texture *grassTexture = loadTexture(renderer, "tiles/tile1.png");
	SDL_Texture *treeTexture = loadTexture(renderer, "tiles/tile2.png");
	SDL_Texture *stoneTexture = loadTexture(renderer, "tiles/tile3.png");
	SDL_Texture *playerTexture = loadTexture(renderer, "tiles/Knight1.png");
	SDL_Texture *farmTexture = loadTexture(renderer, "tiles/Farm.png");

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
	for (int y = 0; y < MAP_WIDTH; y++)
	{
		for (int x = 0; x < MAP_HEIGHT; x++)
		{
			// Choix aléatoire d'un type de tuile
			switch (index[x][y])
			{
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

	int playerX = 343;
    int playerY = 273;

	std::vector<SDL_Rect> farms;

	// Boucle principale du jeu
	bool quit = false;
	while (!quit)
	{
		// Gestion des événements
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    playerY -= 10;
                    break;
                case SDLK_DOWN:
                    playerY += 10;
                    break;
                case SDLK_LEFT:
                    playerX -= 10;
                    break;
                case SDLK_RIGHT:
                    playerX += 10;
                    break;
				case SDLK_1:
				    playerTexture = loadTexture(renderer, "tiles/Knight1.png");
					break;
				case SDLK_2:
					playerTexture = loadTexture(renderer, "tiles/Knight2.png");
					break;
				case SDLK_3:
					playerTexture = loadTexture(renderer, "tiles/Knight3.png");
					break;
                case SDLK_e:
                    SDL_Rect farmRect = {playerX, playerY, MAP_TILE_SIZE, MAP_TILE_SIZE};
                    farms.push_back(farmRect);
                    break;
				}
            }
		} // Effacement de l'écran
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		// Affichage de la carte
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			for (int y = 0; y < MAP_HEIGHT; y++)
			{
				SDL_Rect rect = {x * MAP_TILE_SIZE, y * MAP_TILE_SIZE, MAP_TILE_SIZE, MAP_TILE_SIZE};
				SDL_RenderCopy(renderer, map[x][y].texture, nullptr, &rect);
			}
		}

		SDL_Rect playerRect = {playerX, playerY, PLAYER_WIDTH, PLAYER_HEIGHT};
        SDL_RenderCopy(renderer, playerTexture, nullptr, &playerRect);

    	// Affichage des fermes
    	for(SDL_Rect farmRect : farms)
    	{
        	SDL_RenderCopy(renderer, farmTexture, nullptr, &farmRect);
    	}

		// Affichage de l'écran
		SDL_RenderPresent(renderer);
	}

	// Libération des textures
	SDL_DestroyTexture(grassTexture);
	SDL_DestroyTexture(treeTexture);
	SDL_DestroyTexture(stoneTexture);
	SDL_DestroyTexture(playerTexture);
    SDL_DestroyTexture(farmTexture);

	// Fermeture de SDL2
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}