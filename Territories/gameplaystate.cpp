#include "Player.h"

#include "GameplayState.h"

void GameplayState::Init(WindowManager* w)
{
	world_map_.LoadTexture(w->getRenderer(), "_resources\\WorldMap.png");
	world_map_.scaleX(2.0);
	world_map_.scaleY(2.0);
	
	player_.LoadTexture(w->getRenderer(), "_resources\\character.png");
    //g=ame_screen_map_ = RenderingEngine::LoadTexture(w->getRenderer(), "_resources\\WorldMap.png");
	//player = RenderingEngine::LoadTexture(w->getRenderer(), "_resources\\character.png");

	// Init Button Stuffs
	string str2 = "Menu";
    SDL_Color buttonColor = {0, 255, 0, 255};
	game_menu_btn_ = new Button(w->getRenderer(), str2, buttonColor, 28);
	game_menu_btn_->setPosition(25, 550);

	// Init Camera obj
	//camera_(player_.x(), player.y(), SCREEN_WIDTH, SCREEN_HEIGHT);


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
				GameStateManager::setCurrentState(-1);
               // OnLeftBtnDown(event->button.x, event->button.y);
            }
            break;
    }

}

void GameplayState::Update(WindowManager* w)
{

}


void GameplayState::Render(WindowManager* w)
{
//========================================================================//
// Background Color Fill (Can be useful during development)
//========================================================================//

	// Set the Renderer Color to desired value for drawing the background. 
	SDL_SetRenderDrawColor(w->getRenderer(), 80, 20, 162, 255);

	// Define the x and y as well as width and height properties of the
	// background image. 
	SDL_Rect bgRect = { 0, 0, w->getWidth(), w->getHeight() };

	// Fill in background
	SDL_RenderFillRect(w->getRenderer(), &bgRect);

//===========//
// World Map 
//===========//
	// Draws the world map to the RenderTarget
	world_map_.Draw(w->getRenderer());
	
//=======//
// Player
//=======//
	// Draws player object to the RenderTarget
	player_.Draw(w->getRenderer());
	
	
}
