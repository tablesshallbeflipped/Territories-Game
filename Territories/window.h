// Author: Timur Karasapan
// Email: timur.karasapan@gmail.com
// Twitter: #LinkerError
//
// Last Update: 25/09/2014 : 9:23 PM (EST)
// Version: 1.0.5

#ifndef SDL2_FRAMEWORK_WINDOW_H
#define SDL2_FRAMEWORK_WINDOW_H

#include "SDL.h"
#include <iostream>

using std::cout;
using std::endl;

// Manages the application's window and associated renderer,
// provides public accessors methods to indirectly expose
// both the window and renderer. Handles all (global) SDL_WINDOW
// based events. 
// 
// Usage Example:
// 		WindowManager window_manager_;   
// 		window_manager_.Init();
class WindowManager
{
//======================================================//
//                      Properties                      //
//======================================================//
private:
	//  Pointer to the application's window.
	SDL_Window* ptr_app_window_;

	//  Pointer to the renderer. Access to the renderer
	//  is required for all drawing operations. 	
	SDL_Renderer* ptr_renderer_;	

	//Value, in pixels, of the window's width.
	int width_;

	//Value, in pixels, of the window's height.
	int height_;

	//Used to track whether or not the window has mouse focus
	bool is_mouse_focused_;	

	//Used to track whether or not the window has keyboard focus	
	bool is_keyboard_focused_;

	//Used to track whether or not the window has keyboard focus
	bool is_fullscreen_; 

//======================================================//
//                      Behaviors                       //
//======================================================//	
public:
	// Initializes properties to default values, pointers are set to nullptr
	WindowManager();
	~WindowManager();	

	// Creates the application window for SDL and the 2D rendering
	// context for the window. Also responsible for setting renderer
	// scale quality. 
	bool Init();

	// Processes all events of type SDL_WINDOWEVENT
	void HandleEvents(SDL_Event* event);

	// Accessors 
	inline int getWidth() const 		{ return width_; }				
	inline int getHeight() const 		{ return height_; }
	inline bool isMouseFocused() const 			{ return is_mouse_focused_; }
	inline SDL_Window* getWindow() const 		{ return ptr_app_window_; }	
	inline bool isKeyboardFocused() const 		{ return is_keyboard_focused_; }
	inline SDL_Renderer* getRenderer() const 	{ return ptr_renderer_; }		
};

#endif