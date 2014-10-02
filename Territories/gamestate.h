#ifndef SDL2_FRAMEWORK_GAMESTATE_H
#define SDL2_FRAMEWORK_GAMESTATE_H

#include <iostream>
#include "RenderingEngine.h"

using std::cout;
using std::endl;


class GameState
{

public:
	virtual ~GameState() {};

	virtual void Init(WindowManager* w) = 0;

    virtual void Clean() = 0;
		
	virtual void HandleEvents(SDL_Event* event) = 0;

	virtual void Update(WindowManager* w) = 0;

	virtual void Render(WindowManager* w) = 0;

protected:
        GameState() {}
};

#endif

