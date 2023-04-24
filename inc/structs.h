#pragma once

struct Entity
{
	unsigned int id;
	int type;							// Type of the entity
	int x;								// x & y = entity location on the map
	int y;								
	int side;
	int solid;							// Says whether the entity is solid & blocks movement
	int facing;
	void (*draw) (Entity* self);
	Entity *next;
};

struct MapTile
{
	int tile;							// Represents the type of tile it is
	TileType type;
  	SDL_Texture* texture;
};

struct Stage					// Struct to hold the data of the current stage we're playing
{
	SDL_Point camera;
	unsigned int entityId;
	MapTile map[MAP_WIDTH][MAP_HEIGHT]; // Multidimensionnal array of MapTiles with MAP_WIDTH & MAP_HEIGHT size
	Entity entityHead, *entityTail;
	Entity *currentEntity;				// Pointer to the current entity selected
	int animating;						// Flag to know whether animations are playing or not
	struct selectedTile					// Holds the location of tile the player's hovering with his/her mouse
	{
		int x;
		int y;
	};						
};

struct Tile {
  TileType type;
  SDL_Texture* texture;
};