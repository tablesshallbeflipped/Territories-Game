// Preferred Order Include (Local to Global)
// 1. include corresponding h to this cpp (IF applicable)
// 2. include header files from current project 
// 3. include header files from other non-standard, non-system libraries (SDL2)
// 4. Headers from "almost-standard" libraries (Boost)
// 5. include standard C++ headers (e.g. #include <iostream>)
// 6. include standard C headers (e.g. #include <iostream>)

#include "Texture.h"

//(explicit ) default Constructor: responsible for instantianting member properties
Texture::Texture()
{
	// Instantiate member proeprties to default values
	alpha_ = 255;
	name_ = "";
	rotation_point_.x = 0;
	rotation_point_.y = 0;
	rotate_ = 0.0;
	scaleX_ = 1.0f;
	scaleY_ = 1.0f;
	texture_ = nullptr;
	visible_ = true;
	width_ = 0;
	height_ = 0;
	x_ = 0;
	y_ = 0;
}


Texture::Texture(SDL_Renderer* r, const string& imgLocation)
{
	alpha_ = 255;
	name_ = "";
	rotation_point_.x = 0;
	rotation_point_.y = 0;
	rotate_ = 0.0;
	scaleX_ = 1.0f;
	scaleY_ = 1.0f;
	texture_ = nullptr;
	visible_ = true;
	width_ = 0;
	height_ = 0;
	x_ = 0;
	y_ = 0;

	// LoadTexture Objects images data into texture_ property
	if (!LoadTexture(r, imgLocation))
	{
		//failure
	}
}

Texture::~Texture()
{
	SDL_DestroyTexture(texture_);
	texture_ = nullptr;
}

bool Texture::LoadTexture(SDL_Renderer* r, const string& imgLocation)
{
	texture_ = IMG_LoadTexture(r, imgLocation.c_str());

	if (texture_ == nullptr)
	{
		//TODO:: handels erros
		cout << "@Texture::LoadTexture -- failed to load Texture( " + name_ + " ) :\n" << SDL_GetError() << endl;
		return false;
	}

	SDL_QueryTexture(texture_, NULL, NULL, &width_, &height_);

	rotation_point_.x = int(width_ * 0.5f);
	rotation_point_.y = int(width_ * 0.5f);

	return true;
}

void Texture::Draw(SDL_Renderer* r)
{
	// visible check
	if (!visible_)
	{
		return;
	}

	SDL_Rect dst = { x_, y_, (int)(width_*scaleX_), (int)(height_*scaleY_) };

	SDL_RenderCopyEx(r, texture_, NULL, &dst, rotate_, &rotation_point_, SDL_FLIP_NONE);
}


//while the below funtion is not complex it is not simple
//either each time the alpha mutator is invoked it will execute 3 condiditons
//checks, a call to a method which is located in an exteranl lib/dll and
//executes between one and two assignemnts
//
// so what?
//
//its for the above reasons that the below mutators is implemetes
//outside the header fild and why it is not marked as inline

void Texture::alpha(int newValue)
{
	if (newValue < 0) { newValue = 0; }
	if (newValue > 255) { newValue = 255; }

	if (SDL_SetTextureAlphaMod(texture_, newValue) < 0)
	{
		cout << "@Texture::alpha(int newvalue) -- SDL_SetTextureAlphaMod call failed:\n" << SDL_GetError() << endl;
	}
	else
	{
		alpha_ = newValue;
	}
}

bool Texture::CreateTextureFromText(SDL_Renderer* r, const string& textValue, TTF_Font* textFont, SDL_Color textColor)
{
	/// render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(textFont, textValue.c_str(), textColor);


	// will hold final texture
	SDL_Texture* final_texture = nullptr;

	if (textSurface == nullptr)
	{
		return false;
	}
	else
	{
		//create texture from surface pixels
		final_texture = SDL_CreateTextureFromSurface(r, textSurface);

		if (final_texture == nullptr)
		{
			return false;
		}

		// get rid of old surface
		SDL_FreeSurface(textSurface);
	}

	return final_texture;

	SDL_QueryTexture(texture_, NULL, NULL, &width_, &height_);

	rotation_point_.x = int(width_* 0.5f);
	rotation_point_.y = int(height_* 0.5f);

	return true;
}




