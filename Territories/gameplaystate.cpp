
#include "GameplayState.h"

void GameplayState::Init(WindowManager* w)
{
    string str2 = "Menu";

    SDL_Color buttonColor = {0, 255, 0, 255};

	game_menu_btn_ = new Button(w->getRenderer(), str2, buttonColor, 28);

	game_menu_btn_->setPosition(25, 550);

}

void GameplayState::Clean()
{
    cout << "|-->GameplayState::Clean() Invoked" << endl;

	delete game_menu_btn_;

}

void GameplayState::HandleEvents(SDL_Event* event) 
{
	game_menu_btn_->HandleEvents(event);

    switch(event->type) 
    {
        case SDL_MOUSEBUTTONDOWN: 
			if (event->button.button == SDL_BUTTON_LEFT || event->button.button == SDL_BUTTON_RIGHT)
            {
                cout << "|--> Mouse Click(" << event->button.x << ", "
                << event->button.y << ") | Current State: GameplayState" << endl;
				GameStateManager::setCurrentState(3);
               // OnLeftBtnDown(event->button.x, event->button.y);
            }
            break;
    }

}

void GameplayState::Update(WindowManager* w)
{
	if (game_menu_btn_->getState() == CLICKED)
	{
		GameStateManager::setCurrentState(GAMESTATE_TERMINATE);
	}
}


void GameplayState::Render(WindowManager* w)
{

	RenderingEngine::DrawTexture(w->getRenderer(), game_menu_btn_->getTexture(), game_menu_btn_->getBoundingBox().x, game_menu_btn_->getBoundingBox().y);

	
}

void GameplayState::Reset(WindowManager* w)
{
	cout << "|-->GameplayState::Reset() Invoked" << endl;

}