#ifndef CAMERA_H
#define CAMERA_H

#include "SDL.h"

class Camera
{
public:
	Camera(int x, int y, int w, int h)
	{
		viewport_.x = x;
		viewport_.y = y;
		viewport_.w = w;
		viewport_.h = h;
	}
	
	void follow(int x, int y)
	{
		viewport_.x = x;
		viewport_.y = y;
	}

	SDL_Rect viewport() { return viewport_; }

private:
	SDL_Rect viewport_;

};

#endif