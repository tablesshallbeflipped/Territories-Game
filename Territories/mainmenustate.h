#ifndef SRC_MAIN_MENU_STATE_H
#define SRC_MAIN_MENU_STATE_H

#include "GameState.h"
#include "GameStateManager.h"
#include "Button.h"

class MainMenuState : public GameState
{   
private:
    Button* new_game_btn_;

	Button* options_game_btn_;
      
    Button* quit_game_btn_; 

	Button* credits_game_btn_;
    
public:
	MainMenuState() {}
    ~MainMenuState() {}

    virtual void Init(WindowManager* w);

    virtual void Clean();

    virtual void HandleEvents(SDL_Event* event);

    virtual void Update(WindowManager* w);

    virtual void Render(WindowManager* w);
	
};

#endif
