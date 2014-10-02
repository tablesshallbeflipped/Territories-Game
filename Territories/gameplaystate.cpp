
#include "GameplayState.h"

void GameplayState::Init(WindowManager* w)
{
    string str = "New Game!";
    string str2 = "Main Menu";

    SDL_Color buttonColor = {0, 255, 0, 255};

    new_game_btn_ = new Button( w->getRenderer(), str, buttonColor, 28);   
    exit_game_btn_ = new Button( w->getRenderer(), str2, buttonColor, 28); 
    
    new_game_btn_->setPosition(25, 550);     
    exit_game_btn_->setPosition(425, 550);
}

void GameplayState::Clean()
{
    cout << "|-->GameplayState::Clean() Invoked" << endl;

    delete new_game_btn_;
    delete exit_game_btn_;

    is_winner_ = false;
    current_player_ = PLAYER_TYPE_X;
}

void GameplayState::HandleEvents(SDL_Event* event) 
{
    new_game_btn_->HandleEvents(event);
    exit_game_btn_->HandleEvents(event);

    switch(event->type) 
    {
        case SDL_MOUSEBUTTONDOWN: 
            if(event->button.button == SDL_BUTTON_LEFT) 
            {
                cout << "|--> Mouse Click(" << event->button.x << ", "
                << event->button.y << ") | Current State: GameplayState" << endl;
                
               // OnLeftBtnDown(event->button.x, event->button.y);
            }
            break;
    }

}

void GameplayState::Update(WindowManager* w) 
{
    //  _Board->DetermineWinner() return value(s) key:
    //
    //   -1  ==  Tie                (Game Over)
    //   0  ==  No Winners Yet      (Continue Game)
    //   1  ==  X is the VICTOR     (Game Over)
    //   2  ==  Y is the VICTOR     (Game Over)

    // No winners possible until at least 5th turn

    if (is_winner_)
    {
        if (new_game_btn_->getState() == CLICKED)
        {
            Reset(w);
            return;
        }    

        if (exit_game_btn_->getState() == CLICKED)
        {
            GameStateManager::setCurrentState(GAMESTATE_MAINMENU);
        }

    }

}

void GameplayState::Render(WindowManager* w)
{

	if (is_winner_)
	{
		RenderingEngine::DrawTexture(w->getRenderer(), new_game_btn_->getTexture(), new_game_btn_->getBoundingBox().x, new_game_btn_->getBoundingBox().y);

		RenderingEngine::DrawTexture(w->getRenderer(), exit_game_btn_->getTexture(), exit_game_btn_->getBoundingBox().x, exit_game_btn_->getBoundingBox().y);
	}


}

void GameplayState::Reset(WindowManager* w)
{
	cout << "|-->GameplayState::Reset() Invoked" << endl;

}