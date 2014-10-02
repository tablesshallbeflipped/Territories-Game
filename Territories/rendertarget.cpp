// Author: Timur Karasapan
// Email: timur.karasapan@gmail.com
// Twitter: #LinkerError
//
// Last Update: 26/09/2014 : 1:48 PM (EST)
// Version: 1.0.5

#include "RenderTarget.h"

// Creates an SDL_Texture, using the width and height of the application window.
// The texture is created with a pixel format of SDL_PIXELFORMAT_ARGB8888 and 
// the SDL_TEXTUREACCESS_TARGET flag, allowing the texture to be targeted by 
// the renderer.
RenderTarget::RenderTarget(SDL_Renderer* r, const int width, const int height) : ptr_texture_(nullptr)
{
	 ptr_texture_ = SDL_CreateTexture(r, 					            // Renderer
                               SDL_PIXELFORMAT_ARGB8888,    // Pixel Format
                               SDL_TEXTUREACCESS_TARGET, 	  // Access Type TARGET allows texutre to be used as rendering target |Note: Currently undocumented in SDL2 wiki
                               width, height); 				      // Width and Height of Window
}

RenderTarget::~RenderTarget()
{
    SDL_DestroyTexture(ptr_texture_);
    ptr_texture_ = nullptr;
}

// Sets ptr_texture_ as the render target for draw operations. Then selects the
// color for drawing (black). Finally, the entire RenderTarget is then cleared
// to the selected color.
void RenderTarget::AquireRenderTarget(SDL_Renderer* r)
{
	SDL_SetRenderTarget( r, ptr_texture_ );
    SDL_SetRenderDrawColor( r, 0, 0, 0, 255);
    SDL_RenderClear(r);							
}

// This will display the new contents of the render target by updating the
// screen with all rendering operations performed since AquireRenderTarget
// was invoked. Finally, the render target is reset back to the application's
// default Renderer.
void RenderTarget::ReleaseRenderTarget(SDL_Renderer* r)
{
    SDL_RenderPresent(r);
    SDL_SetRenderTarget( r, nullptr );
}

// Safely disposes of the current instance of ptr_texture_ then creates a 
// new instance of ptr_texture_, using the width and height of the application
// window. The texture is created with a pixel format of 
// SDL_PIXELFORMAT_ARGB8888 and the SDL_TEXTUREACCESS_TARGET flag, allowing the
// texture to be targeted by the renderer.
void RenderTarget::Reset(SDL_Renderer* r, int width, int height)
{
	if (ptr_texture_)
	{
		SDL_DestroyTexture(ptr_texture_);
	}
	
	ptr_texture_ = ptr_texture_ = SDL_CreateTexture(r,//Renderer
                SDL_PIXELFORMAT_ARGB8888,  		//Pixel Format
                SDL_TEXTUREACCESS_TARGET, 		//Access Type
                width, height); 				//Width and Height of Window 
}