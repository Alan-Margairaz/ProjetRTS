#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

using namespace std;

// Dimensions de l'écran
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Dimensions de l'image du personnage
const int PLAYER_WIDTH = 64;
const int PLAYER_HEIGHT = 64;

// Fonction pour charger une image
SDL_Texture *LoadTexture(string path, SDL_Renderer *renderer)
{
    SDL_Texture *texture = nullptr;
    SDL_Surface *surface = IMG_Load(path.c_str());
    if (surface == nullptr)
    {
        cout << "Impossible de charger l'image " << path << endl;
    }
    else
    {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture == nullptr)
        {
            cout << "Impossible de créer la texture à partir de l'image " << path << endl;
        }
        SDL_FreeSurface(surface);
    }
    return texture;
}

int main(int argc, char *args[])
{
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL n'a pas pu être initialisé : " << SDL_GetError() << endl;
        return 1;
    }

    // Création de la fenêtre
    SDL_Window *window = SDL_CreateWindow("Jeu de personnage", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        cout << "La fenêtre n'a pas pu être créée : " << SDL_GetError() << endl;
        return 1;
    }

    // Création du renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        cout << "Le renderer n'a pas pu être créé : " << SDL_GetError() << endl;
        return 1;
    }

    // Chargement de l'image du personnage
    SDL_Texture *playerTexture = LoadTexture("player.png", renderer);
    if (playerTexture == nullptr)
    {
        return 1;
    }

    // Chargement de l'image de la ferme
    SDL_Texture *farmTexture = LoadTexture("farm.png", renderer);
    if (farmTexture == nullptr)
    {
        return 1;
    }

    // Position initiale du personnage
    int playerX = SCREEN_WIDTH / 2 - PLAYER_WIDTH / 2;
    int playerY = SCREEN_HEIGHT / 2 - PLAYER_HEIGHT / 2;

    std::vector<SDL_Rect> farms;

    // Boucle principale
    bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        // Gestion des événements
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
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
                case SDLK_e:
                }
            }
        }

        // Effacer l'écran
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Afficher le personnage
        SDL_Rect playerRect = {playerX, playerY, PLAYER_WIDTH, PLAYER_HEIGHT};
        SDL_RenderCopy(renderer, playerTexture, nullptr, &playerRect);

        // Mettre à jour l'affichage
        SDL_RenderPresent(renderer);
    }

    // Libération des ressources
    SDL_DestroyTexture(playerTexture);
    SDL_DestroyTexture(farmTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}