#ifndef SRC_FRAMEWORK_GAMESTATE_MANAGER_H
#define SRC_FRAMEWORK_GAMESTATE_MANAGER_H
 
#include "GameState.h"
#include "SplashState.h"
#include "LoadingState.h"
#include "MainMenuState.h"
#include "GameplayState.h"

enum StateType
{
    GAMESTATE_TERMINATE = -1,   

    GAMESTATE_NULL, 

    GAMESTATE_SPLASH,

    GAMESTATE_LOADING, 

    GAMESTATE_MAINMENU,

    GAMESTATE_GAMEPLAY
};

class GameStateManager 
{

private:
    static GameState* ptr_current_state_;

    static StateType state_type_;

    static bool is_state_change_;

public:
    GameStateManager() {}
    ~GameStateManager();

    void Init(WindowManager* w);

    void HandleEvents(SDL_Event* event);

    void Update(WindowManager* w);

    void Render(WindowManager* w);

    inline static StateType getStateType() { return state_type_; }  

    inline static bool isNewState() { return is_state_change_; }

    static void setCurrentState(int gameStateID);
;
};
 
#endif