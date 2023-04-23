#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <string>

using namespace std;

class Camera
{
protected:

public:
	Camera();
	~Camera();

	void constrainCamera();
};