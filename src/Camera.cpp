#include "Camera.h"

#include "defs.h"
#include "structs.h"

using namespace std;

Camera::Camera()
{
	
}


Camera::~Camera()
{
	
}

// Limits the camera's coordinates to 0 minimum and maximum to the MAP_WIDTH:
void Camera::constrainCamera()
{
	stage.camera.x = MIN(MAX(stage.camera.x, 0), (MAP_WIDTH * TILE_SIZE) - SCREEN_WIDTH);
	stage.camera.y = MIN(MAX(stage.camera.y, 0), (MAP_HEIGHT * TILE_SIZE) - SCREEN_WIDTH);
}