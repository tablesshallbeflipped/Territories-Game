#include "MainMenuState.h"

void MainMenuState::Init(WindowManager* w)
{
    cout << "|-->MainMenuState::Init() Invoked" << endl;

    string str = "New Game";
	string str1 = "Options";
    string str2 = "Credits";
    string str3 = "Exit";
	string str4 = "Credits";

    SDL_Color button_text_color = {255, 0, 0, 255};

    int center_x_of_texture;

    int center_x_of_window = (int)floor(w->getWidth() * 0.5);
    int window_height_one_eighth = (int)floor(w->getHeight() * 0.125);

    new_game_btn_ = new Button(w->getRenderer(), str, button_text_color);
        center_x_of_texture = (int)floor(new_game_btn_->getBoundingBox().w * 0.5);//*
        new_game_btn_->setPosition(center_x_of_window - center_x_of_texture, window_height_one_eighth * 2);

	quit_game_btn_ = new Button(w->getRenderer(), str3, button_text_color);
		center_x_of_texture = (int)floor(quit_game_btn_->getBoundingBox().w * 0.5);//*
		quit_game_btn_->setPosition(center_x_of_window - center_x_of_texture, window_height_one_eighth * 3);

	options_game_btn_ = new Button(w->getRenderer(), str1, button_text_color);
		center_x_of_texture = (int)floor(new_game_btn_->getBoundingBox().w * 0.5);
		options_game_btn_->setPosition(center_x_of_window - center_x_of_texture, window_height_one_eighth * 4);

	credits_game_btn_ = new Button(w->getRenderer(), str4, button_text_color);
		center_x_of_texture = (int)floor(credits_game_btn_->getBoundingBox().w * 0.5);
		credits_game_btn_->setPosition(center_x_of_window - center_x_of_texture, window_height_one_eighth * 5);
			

}
void MainMenuState::Clean() 
{
    cout << "|-->MainMenuState::Clean() Invoked" << endl;

    delete new_game_btn_;
    delete quit_game_btn_;
	delete options_game_btn_;
	delete credits_game_btn_;
}

void MainMenuState::HandleEvents(SDL_Event* event) 
{
    new_game_btn_->HandleEvents(event);
    quit_game_btn_->HandleEvents(event);
	options_game_btn_->HandleEvents(event);
	credits_game_btn_->HandleEvents(event);
	

    switch(event->type) 
    {
        case SDL_MOUSEBUTTONDOWN: 
            if(event->button.button == SDL_BUTTON_LEFT || event->button.button == SDL_BUTTON_RIGHT) 
            {
                 cout << "|--> Mouse Click(" << event->button.x << ", "
                << event->button.y << ") | Current State: Main Menu State" << endl;
            }
            break;   
    }

}

void MainMenuState::Update(WindowManager* w) 
{
    if (new_game_btn_->getState() == CLICKED)
    {
        GameStateManager::setCurrentState(GAMESTATE_GAMEPLAY);
        return;
    }

    if (quit_game_btn_->getState() == CLICKED)
    {
        GameStateManager::setCurrentState(GAMESTATE_TERMINATE);
    }
}


void MainMenuState::Render(WindowManager* w)
{
	SDL_SetRenderDrawColor(w->getRenderer(), 80, 20, 162, 255);

	SDL_Rect bgRect = { 0, 0, w->getWidth(), w->getHeight() };

	SDL_RenderFillRect(w->getRenderer(), &bgRect);

	RenderingEngine::DrawTexture(w->getRenderer(), new_game_btn_->getTexture(), new_game_btn_->getBoundingBox().x, new_game_btn_->getBoundingBox().y);
	RenderingEngine::DrawTexture(w->getRenderer(), options_game_btn_->getTexture(), options_game_btn_->getBoundingBox().x, options_game_btn_->getBoundingBox().y);
	RenderingEngine::DrawTexture(w->getRenderer(), quit_game_btn_->getTexture(), quit_game_btn_->getBoundingBox().x, quit_game_btn_->getBoundingBox().y);
	RenderingEngine::DrawTexture(w->getRenderer(), credits_game_btn_->getTexture(), credits_game_btn_->getBoundingBox().x, credits_game_btn_->getBoundingBox().y);
}