#ifndef SRC_FRAMEWORK_BUTTON_H
#define SRC_FRAMEWORK_BUTTON_H

#include "RenderingEngine.h"
#include "RenderTarget.h"


enum ButtonState
{
	NORMAL = 0, 

	HOVERING,

	CLICKED,

	RELEASED,
};


class Button
{

private:

	TTF_Font* ptr_font_;

	TextureBB label_texbb_;		


	ButtonState current_state_;	

	void GenerateBoundingBox(TextureBB& texbb);		

	bool isInsideRect(const SDL_Rect& rect, const int x, const int y) const;

public:
	Button() : ptr_font_(nullptr), current_state_(NORMAL) {}
	
	Button(SDL_Renderer* r, const string& label, SDL_Color& textColor, const Uint8 fontSize = 42);
	
	~Button();							

	void HandleEvents(SDL_Event* event);

	inline SDL_Texture* getTexture() const { return label_texbb_.tex; }	

	inline SDL_Rect	getBoundingBox() const { return label_texbb_.dimensions; }

	inline ButtonState 	getState() const { return current_state_; }

	inline void setPosition(const int x, const int y)
	{
		label_texbb_.dimensions.x = x;
		label_texbb_.dimensions.y = y;
	}

	
};

#endif