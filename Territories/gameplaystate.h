#ifndef SRC_GAMEPLAYSTATE_H
#define SRC_GAMEPLAYSTATE_H

#include "GameState.h"
#include "GameStateManager.h"
#include "Board.h"
#include "OutputPanel.h"
#include "Button.h"

enum PlayerType
{
    PLAYER_TYPE_X = 0,

    PLAYER_TYPE_O
};

class GameplayState : public GameState
{
private:

    Button* new_game_btn_;
         
    Button* exit_game_btn_; 

    Board game_board_;

    OutputPanel output_panel_;

    bool is_winner_;    
              
    PlayerType current_player_;              

    void OnLeftBtnDown(int mX, int mY);

    void Reset(WindowManager* w);

public:

    GameplayState() : new_game_btn_(nullptr), exit_game_btn_(nullptr),
    is_winner_(false), current_player_(PLAYER_TYPE_X) {}

	virtual void Init(WindowManager* w);

	virtual void Clean();

	virtual void HandleEvents(SDL_Event* event);

	virtual void Update(WindowManager* w);

	virtual void Render(WindowManager* w);

};

#endif