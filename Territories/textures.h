#ifndef TEXTURE_H
#define TEXTURE_H

// Preferred Order Include (Local to Global)
// 1. include corresponding h to this cpp (IF applicable)
// 2. include header files from current project 
// 3. include header files from other non-standard, non-system libraries (SDL2)
// 4. Headers from "almost-standard" libraries (Boost)
// 5. include standard C++ headers (e.g. #include <iostream>)
// 6. include standard C headers (e.g. #include <iostream>)

#include "SDL.h" 
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>
#include <string>
#include <stdio.h>

// Using declaration
using std::cout;
using std::endl;
using std::string;


class Texture
{
private:
	int alpha_; // range 0 -255
	string name_; // optional OSI
	SDL_Point rotation_point_; // Point (x,y) preform rotations
	double rotate_; // vale in degrees to rotate
	float scaleX_;
	float scaleY_;
	SDL_Texture* texture_; // pointer to image
	bool visible_; // visiblility
	int width_;
	int height_;
	int x_;
	int y_;

public:
	// constructor(s) && Destructor
	Texture();
	Texture(SDL_Renderer* r, const string& imgLocation);
	~Texture();

	SDL_Texture* createTextureFromText(SDL_Renderer* r, const string& textValue,
		TTF_Font* textFont, SDL_Color textColor);
	SDL_Texture* loadTexture(SDL_Renderer*, const string&);
	// Behaviours (Methods/ Fucntions)

	bool LoadTexture(SDL_Renderer* r, const string& imgLocation);
	bool CreateTextureFromText(SDL_Renderer* r, const string& textValue, TTF_Font* textfont, SDL_Color textColor);
	void Draw(SDL_Renderer*r);
	void render(SDL_Renderer *r, SDL_Texture *tex, int x, int y, int w, int h, bool haveMessage, SDL_Texture *Msg, SDL_Rect Msg_rect);

	inline int alpha() const			{ return alpha_; }
	inline const string& name() const   { return name_; }
	inline int rotationX() const		{ return rotation_point_.x; }
	inline int rotationY() const		{ return rotation_point_.y; }
	inline double rotate() const		{ return rotate_; }
	inline float scaleX() const			{ return scaleX_; }
	inline float scaleY() const			{ return scaleY_; }
	inline SDL_Texture* texture() const { return texture_; }
	inline bool visible() const			{ return visible_; }
	inline int width() const			{ return width_; }
	inline int height() const			{ return height_; }
	inline int x() const				{ return x_; }
	inline int y() const 				{ return y_; }

	void alpha(int newValue);
	inline void name(const string& newValue)	{ name_ = newValue; }
	inline void rotationX(const int newValue)	{ rotation_point_.x = newValue; }
	inline void rotationY(const int newValue)	{ rotation_point_.y = newValue; }
	inline void rotate(const double newValue)	{ rotate_ = newValue; }
	inline void scaleX(const float newValue)	{ scaleX_ = newValue; }
	inline void scaleY(const float newValue)	{ scaleY_ = newValue; }
	inline void visible(const bool newValue)	{ visible_ = newValue; }
	inline void width(const int newValue)		{ width_ = newValue; }
	inline void height(const int newValue)		{ height_ = newValue; }
	inline void x(const int newValue)			{ x_ = newValue; }
	inline void y(const int newValue)			{ y_ = newValue; }

};



#endif