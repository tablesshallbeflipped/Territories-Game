// Author: Timur Karasapan
// Email: timur.karasapan@gmail.com
// Twitter: #LinkerError
//
// Last Update: 26/09/2014 : 1:48 PM (EST)
// Version: 1.0.5

#include "SplashState.h"

// Loads the splash screen's image resource
void SplashState::Init(WindowManager* w)
{ 
	cout << "|-->SplashState::Init() Invoked" << endl;

   // ptr_splash_screen_ = RenderingEngine::LoadTexture(w->getRenderer(), "_resources\\splashScreen.png");
}

// Cleans the object in preperation for safe descruction of object.
void SplashState::Clean()
{
	cout << "|-->SplashState::Clean() Invoked" << endl;
	
	RenderingEngine::DestroyTexture(ptr_splash_screen_);
}

// Handles events for the splash state
void SplashState::HandleEvents(SDL_Event* event) 
{
	switch(event->type) 
	{
		case SDL_MOUSEBUTTONDOWN: 
		    if(event->button.button == SDL_BUTTON_LEFT || event->button.button == SDL_BUTTON_RIGHT ) 
		    {
		    	cout << " | Current State: SplashState" << endl;
		    }
		    break;


		    
		case SDL_KEYDOWN: 
		    /* Change States when Escape is pressed */
		    if (event->key.keysym.sym == SDLK_RETURN )
		    {
		        GameStateManager::setCurrentState(GAMESTATE_LOADING);
		        
		    }
		    break;
	}
}

// All GameState's require an Update(WindowManager* w) method but given the simplicity of the
// splash state, no logic needs updated so the code body is kept empty.
void SplashState::Update(WindowManager* w) {}

// All Draw operations for the splash state are preformed here. Everything 
// drawn within this method is drawn to the RenderingEngine's scene_ property.
void SplashState::Render(WindowManager* w) 
{
	// Background Fill
	ptr_splash_screen_ = RenderingEngine::LoadTexture(w->getRenderer(), "_resources\\spalshBackground.jpg");

	// Set the Renderer Color to desired value for drawing the background. 
	SDL_SetRenderDrawColor(w->getRenderer(), 80, 20, 162, 255 );
	
	// Define the x and y as well as width and height properties of the
    // background image. 
	SDL_Rect bgRect = { 0, 0, w->getWidth(), w->getHeight() };
	
	// Paint the area defined by bgRect to the Scene2D object within
    // RenderingEngine
	SDL_RenderFillRect(w->getRenderer(), &bgRect);

// Draw title screen

	//Draw the ptr_splash_screen_ image to the Scene2D object within RenderingEngine	
	RenderingEngine::DrawTexture(w->getRenderer(), ptr_splash_screen_, 0, 0, 600,800 );
}