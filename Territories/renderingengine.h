// Author: Timur Karasapan
// Email: timur.karasapan@gmail.com
// Twitter: #LinkerError
//
// Last Update: 26/09/2014 : 1:48 PM (EST)
// Version: 1.0.5

#ifndef SRC_FRAMEWORK_SDLROOT_H
#define SRC_FRAMEWORK_SDLROOT_H

#include <iostream>

#include "Window.h"
#include "RenderTarget.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

using std::string;
using std::cout;
using std::endl;

// Convenient struct which pairs a pointer to an SDL_Texture with an SDL_Rect
// to serve as the texture's bounding box. (See Button.h/Button.cpp)
typedef struct TextureBB
{

public:
	// Pointer to SDL_Texture 
	SDL_Texture* tex;	     

	// Stores the position (x,y) and dimensions (w,h) of tex
	SDL_Rect dimensions;  
    
    // Defualt Constructor; gives member properties default values
	TextureBB() : tex(nullptr) 
	{
		dimensions.x =0;
		dimensions.y =0;
		dimensions.h =0;
		dimensions.w =0;
	}

}TextureBB;





// The RenderingEngine encapsulates the  
//
//
class RenderingEngine 
{
//======================================================//
//                     Properties                       //
//======================================================//
private:
	// Holds an instance of an SDL_Window and SDL_Renderer object.
	// Manages the application window, including events.
    WindowManager window_manager_;	//Application Window

    // SDL_TEXTUREACCESS_TARGET
    RenderTarget scene_;			//Application's {default} RenderTarget

//======================================================//
//                      Behaviors                       //
//======================================================//
public:
    RenderingEngine() {}; 
    ~RenderingEngine() {};

    // Initializes the SDL system, SDL_img & SDL_ttf extention library.
    // Constructs the WindowManager object and the RenderTarget.
	bool Init(); 

	// Unloads SDL SubSystems, Frees Assocaited Memory
	void Clean();  

	// Pre-Rendering operation, needs to be called before any draw operations
	// each frame/tick.
	void Begin();

	// Draws scene_ to the screen
	void RenderScene();

	//Post-Rendering operation, needs to be called after all draw operations
	// for each frame/tick.
	void End();
    
    // Accessor method for window_manager_
	inline WindowManager&  getWindow()    { return window_manager_; }

	// Accessor method for window_manager_.getRenderer()
	inline SDL_Renderer*   getRenderer()  { return window_manager_.getRenderer(); }

	// Accessor method for scene_	
	inline RenderTarget&   getScene() 	  { return scene_; }
//
//	Static Rendering Operations
//
	// Creates an SDL_Texture based on the passed in string and font.
	//    @param text The string sequence to be converted into a texture
	//    @param textColor the color value (RGB) of the text.
	//    @param font the font used to render @param text
	static SDL_Texture* CreateTextureFromString(SDL_Renderer* r, const string& text, const SDL_Color& textColor, TTF_Font* font);

	// Loads an external image file and converts it into an SDL_Texture.
	//    @param r Pointer to the Renderer
	//    @param imgLocation The location on disk of the image to be loaded.  
	static SDL_Texture* LoadTexture(SDL_Renderer* r, string imgLocation);

	// Draws texture to current render target. (scene_ by default)
	//    @param tex Pointer to Texture to be drawn. 
	//    @param x X Position on Screen
	//    @param y Y Position on Screen
	//    @param w Width of Texture   {Optional}
	//    @param h Height of Texture  {Optional}
	static void DrawTexture(SDL_Renderer* r, SDL_Texture *tex, int x, int y, int w = 0, int h = 0);

	// Safely destroys an SDL_Texture object and sets the referance to the
	// arguement to nullptr.
	//    @param tex Texture to free from memory {Ref to Pointer}
	static void DestroyTexture(SDL_Texture*& tex);

	// Safely destroys a TextureBB object and sets the referance to the
	// arguement to nullptr.
	//	@param tex Texture to free from memory {Ref to Pointer}
	static void DestroyTexture(TextureBB*& tex);
};

#endif
