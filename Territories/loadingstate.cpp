#include "LoadingState.h"

void LoadingState::Init(WindowManager* w)
{
    cout << "|-->LoadingState::Init() Invoked" << endl;
    
    ptr_background_texture_ = RenderingEngine::LoadTexture(w->getRenderer(), "_resources\\loadingScreen.png");
    state_life_timer_.Start();
}

void LoadingState::Clean()
{
    cout << "|-->LoadingState::Clean() Invoked" << endl;
    RenderingEngine::DestroyTexture(ptr_background_texture_);
}

void LoadingState::HandleEvents(SDL_Event* event) 
{
    switch(event->type) 
    {
        case SDL_MOUSEBUTTONDOWN: 
            if(event->button.button == SDL_BUTTON_LEFT || event->button.button == SDL_BUTTON_RIGHT) 
            {
                cout << " | Current State: LoadingState" << endl;
            }
            break; 
    }

}

// Update method for the loading state, checks to see if enough seconds have
// passed since the timer object started. If it has then the current gamestate
// is changed to GAMESTATE_MAINMENU.
void LoadingState::Update(WindowManager* w) 
{
    if( ( state_life_timer_.getTicks() / 1000.f ) >= 1)

    {
        GameStateManager::setCurrentState(GAMESTATE_MAINMENU);
    }
}

// All Draw operations for the loading state are preformed here. Everything 
// drawn within this method is drawn to the RenderingEngine's scene_ property.
void LoadingState::Render(WindowManager* w) 
{

// Background Fill

    // Set the Renderer Color to desired value for drawing the background. 
    SDL_SetRenderDrawColor(w->getRenderer(), 80, 20, 162, 255 );
    
    // Define the x and y as well as width and height properties of the
    // background image. 
    SDL_Rect bgRect = { 0, 0, w->getWidth(), w->getHeight() };
    
    // Paint the area defined by bgRect to the Scene2D object within
    // RenderingEngine
    SDL_RenderFillRect(w->getRenderer(), &bgRect);

// Draw the loading tex

    //Draw the ptr_background_texture_ image to the Scene2D object within RenderingEngine
	RenderingEngine::DrawTexture(w->getRenderer(), ptr_background_texture_, 0, 0);
}
