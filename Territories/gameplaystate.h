#ifndef SRC_GAMEPLAYSTATE_H
#define SRC_GAMEPLAYSTATE_H

#include "GameState.h"
#include "GameStateManager.h"

#include "Button.h"

enum PlayerType
{
   

   
};

class GameplayState : public GameState
{
private:

	Button* game_menu_btn_;
         
    PlayerType current_player_;              

    void OnLeftBtnDown(int mX, int mY);

    void Reset(WindowManager* w);

public:

	GameplayState() :  game_menu_btn_(nullptr),
    current_player_() {}

	virtual void Init(WindowManager* w);

	virtual void Clean();

	virtual void HandleEvents(SDL_Event* event);

	virtual void Update(WindowManager* w);

	virtual void Render(WindowManager* w);

};

#endif