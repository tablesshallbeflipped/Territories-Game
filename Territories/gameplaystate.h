#ifndef SRC_GAMEPLAYSTATE_H
#define SRC_GAMEPLAYSTATE_H

#include "Constants.h"
#include "GameState.h"
#include "GameStateManager.h"
#include "Camera.h"
#include "Button.h"
#include "Texture.h"

enum PlayerType
{
   

   
};

class GameplayState : public GameState
{
private:
	Button* game_menu_btn_;
	Texture world_map_;
	Texture player_;

	// Camera Object (defines the viewport)
	Camera camera_;

public:

	GameplayState() : game_menu_btn_(nullptr), camera_(0,0, SCREEN_WIDTH, SCREEN_HEIGHT) {}

// Behaviors
	virtual void Init(WindowManager* w);
	virtual void Clean();
	virtual void HandleEvents(SDL_Event* event);
	virtual void Update(WindowManager* w);
	virtual void Render(WindowManager* w);

};

#endif