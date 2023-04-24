#pragma once

#define MAP_TILE_SIZE			48

#define MAX_TILES				15

#define MAP_WIDTH				15
#define MAP_HEIGHT				15

#define MAP_RENDER_WIDTH		15
#define MAP_RENDER_HEIGHT		20

#define MAP_TO_SCREEN(x)		(x * MAP_TILES_SIZE) + MAP_TILES / 2

#define TILE_WALL				0
#define TILE_GROUND				5

#define CAMERA_MOVE_SPEED		12

enum
{
	ET_WORLD,
	ET_SOLDIERS,
	ET_FARMS,
	ET_CASTLES,
	ET_WALLS
};

enum e_dir
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

enum TileType {
  GRASS,
  TREE,
  STONE
};