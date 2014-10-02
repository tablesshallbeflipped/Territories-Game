#include "GameStateManager.h"

GameState* GameStateManager::ptr_current_state_ = nullptr;
bool GameStateManager::is_state_change_ = false;
StateType GameStateManager::state_type_ = GAMESTATE_NULL;

GameStateManager::~GameStateManager()
{
    if(ptr_current_state_)
    {
       ptr_current_state_->Clean();
       delete ptr_current_state_;
    }
    else
    {
        delete ptr_current_state_;
    }
}

void GameStateManager::Init(WindowManager* w)
{
    is_state_change_ = false;

    if(ptr_current_state_ && !is_state_change_) 
    {
        ptr_current_state_->Init(w);
    } 
}

void GameStateManager::HandleEvents(SDL_Event* event) 
{
    if(ptr_current_state_ && !is_state_change_) 
    {
        ptr_current_state_->HandleEvents(event);
    }
}

void GameStateManager::Update(WindowManager* w) 
{
    if(ptr_current_state_ && !is_state_change_)
    {
        ptr_current_state_->Update(w);
    } 
}
 
void GameStateManager::Render(WindowManager* w) 
{
    if(ptr_current_state_ && !is_state_change_) 
    {
        ptr_current_state_->Render(w);
    }
}


void GameStateManager::setCurrentState(int gameStateID) 
{
    is_state_change_ = true;
    state_type_ = (StateType)gameStateID;
    
    if(ptr_current_state_)
    {
       ptr_current_state_->Clean();
       delete ptr_current_state_;
       ptr_current_state_ = nullptr;
    } 

    switch (gameStateID)
    {
        case GAMESTATE_SPLASH:
            ptr_current_state_ = new SplashState();
            break;

        case GAMESTATE_LOADING:
            ptr_current_state_ = new LoadingState();
            break;

        case GAMESTATE_MAINMENU:
            ptr_current_state_ = new MainMenuState();
            break;

        case GAMESTATE_GAMEPLAY:
            ptr_current_state_ = new GameplayState();
            break;
    }      
 
}