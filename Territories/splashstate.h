// Author: Timur Karasapan
// Email: timur.karasapan@gmail.com
// Twitter: #LinkerError
//
// Last Update: 12/11/2013 : 10:32 PM (EST)
// Version: 1.0.0

#ifndef SRC_SPLASHSTATE_H
#define SRC_SPLASHSTATE_H

#include "GameStateManager.h"
#include "Button.h"

using namespace std;

// First GameState of the application
class SplashState : public GameState
{
//======================================================//
//                     Properties                       //
//======================================================//
private:
	// Pointer to splash screen texture 
	SDL_Texture* ptr_screen_;

//======================================================//
//                      Behaviors                       //
//======================================================// 	
public:
	SplashState() : ptr_screen_(nullptr){}
	~SplashState() {}

	// Splash state initialization method
	virtual void Init(WindowManager* w);

	// Splash state clean (destruction) method	
	virtual void Clean();

	// Splash state event handler method	
	virtual void HandleEvents(SDL_Event* event);

	// Splash state logic update method
	virtual void Update(WindowManager* w);

	// Splash state render method
	virtual void Render(WindowManager* w);
	
};

#endif