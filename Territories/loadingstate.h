#ifndef SRC_LOADINGSTATE_H
#define SRC_LOADINGSTATE_H

#include "GameState.h"
#include "GameStateManager.h"
#include "Timer.h"

 
class LoadingState : public GameState
{

private:
	SDL_Texture * ptr_background_texture_;	

	Timer state_life_timer_;	

public:
	LoadingState() : ptr_background_texture_(nullptr) {}
	~LoadingState() {}

	virtual void Init(WindowManager* w);

	virtual void Clean();
	
	virtual void HandleEvents(SDL_Event* event);

	virtual void Update(WindowManager* w);

	virtual void Render(WindowManager* w);
};

#endif