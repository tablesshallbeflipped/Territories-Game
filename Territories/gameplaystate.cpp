
#include "GameplayState.h"

void GameplayState::Init(WindowManager* w)
{
    cout << "|-->GameplayState::Init() Invoked" << endl;

    if ( !game_board_.Init(w->getRenderer()) )
    {
        cout << "Error @ GameplayState::Init() | Board object failed to initilize" << endl;
    }
 
    if ( !output_panel_.Init(w->getRenderer()) )
    {
        cout << "Error @ GameplayState::Init() | Output Panel object failed to initilize" << endl;
    }

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
                
                OnLeftBtnDown(event->button.x, event->button.y);
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
    if ( Board::NUM_TURN >= 5)	
    {
        int victor = game_board_.DetermineWinner();

        if ( victor > 0 )
        {
            if (victor == game_board_.GRID_TYPE_X)
            {
                output_panel_.setWinnerTex(output_panel_.VICTOR_TYPE_X);
            }
            else
            {
                 output_panel_.setWinnerTex(output_panel_.VICTOR_TYPE_O);
            }    
        }
        else if ( victor < 0 )
        {
             output_panel_.setWinnerTex(output_panel_.VICTOR_TYPE_TIE);
        }

        if ( victor != 0)
        {
            is_winner_ = true;
        }
    }

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
    if (!is_winner_)
    {
        RenderingEngine::DrawTexture(w->getRenderer(), game_board_.getGridTexture(), 0, 0);
    }
    else
    {
        RenderingEngine::DrawTexture(w->getRenderer(), game_board_.getGameOverTexture(), 0, 0);
    }
    
    if (!is_winner_)
    {
        for(int i = 0; i < 9; i++) 
        {
            int X = (i % 3) * 200;
            int Y = (i / 3) * 200;

            if(game_board_.getGrid()[i] == game_board_.GRID_TYPE_X) 
            {
                RenderingEngine::DrawTexture(w->getRenderer(), game_board_.getXTexture(), X, Y);
            }
            else if(game_board_.getGrid()[i] == game_board_.GRID_TYPE_O) 
            {
                RenderingEngine::DrawTexture(w->getRenderer(), game_board_.getOTexture(), X, Y);
            }
        }
    }

    if (is_winner_)
    {
        RenderingEngine::DrawTexture(w->getRenderer(), new_game_btn_->getTexture(), new_game_btn_->getBoundingBox().x, new_game_btn_->getBoundingBox().y);
        
        RenderingEngine::DrawTexture(w->getRenderer(), exit_game_btn_->getTexture(), exit_game_btn_->getBoundingBox().x, exit_game_btn_->getBoundingBox().y);
    }

    RenderingEngine::DrawTexture(w->getRenderer(), output_panel_.getBackgroundTex(), 0, 600);

    if (is_winner_)
    {
        RenderingEngine::DrawTexture(w->getRenderer(), *output_panel_.getWinnerTex(), 0, 600);

    }
}

void GameplayState::OnLeftBtnDown(int mX, int mY) 
{
    int ID = int( ( (mX / 200) + (mY / 200) * 3)  );
 
    if(game_board_.getGrid()[ID] != game_board_.GRID_TYPE_NONE) 
    {
        return;
    }

    if(current_player_ == PLAYER_TYPE_X) 
    {
        game_board_.SetCell(ID, game_board_.GRID_TYPE_X);
        current_player_ = PLAYER_TYPE_O;
    }
    else
    {
        game_board_.SetCell(ID, game_board_.GRID_TYPE_O);
        current_player_ = PLAYER_TYPE_X;
    }
}

void GameplayState::Reset(WindowManager* w)
{
    cout << "|-->GameplayState::Reset() Invoked" << endl;

    is_winner_ = false;
    current_player_ = PLAYER_TYPE_X;

    output_panel_.setWinnerTex(output_panel_.VICTOR_TYPE_RESET);

    game_board_.ResetGrid();
}