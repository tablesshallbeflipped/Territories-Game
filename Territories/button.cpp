#include "Button.h"

Button::Button(SDL_Renderer* r, const string& label, SDL_Color& textColor, const Uint8 fontSize) : 
ptr_font_(nullptr),	
 current_state_(NORMAL)
{
	ptr_font_ = TTF_OpenFont( "_resources/TPBAFK-Regular.otf", fontSize );

    if( ptr_font_ == nullptr )
    {
        cout << "Error @ TTF INIT" << SDL_GetError() << endl;
    }

	label_texbb_.tex = RenderingEngine::CreateTextureFromString(r, label, textColor, ptr_font_);
	
	GenerateBoundingBox(label_texbb_); 	
}

Button::~Button()
{
    TTF_CloseFont( ptr_font_ );
	ptr_font_ = nullptr;
}

void Button::HandleEvents(SDL_Event* event) 
{
	if (current_state_ != NORMAL )
	{
		current_state_ = NORMAL;
	}

	switch(event->type)
	{
		case SDL_MOUSEMOTION:
				if (isInsideRect(label_texbb_.dimensions, event->motion.x, event->motion.y))
				{
					current_state_ = HOVERING;
				}
				break;

		case SDL_MOUSEBUTTONDOWN:
				if (isInsideRect(label_texbb_.dimensions, event->button.x, event->button.y))
				{
					current_state_ = CLICKED;
#ifdef DEBUG
					cout << "Button Clicked" << endl;
#endif
				}
				break;

		case SDL_MOUSEBUTTONUP:
				if (isInsideRect(label_texbb_.dimensions, event->button.x, event->button.y))
				{
					current_state_ = RELEASED;
#ifdef DEBUG
					cout << "Button Released" << endl;
#endif
				}
	}

}

void Button::GenerateBoundingBox(TextureBB& texbb)
{
	int w,h;
	SDL_QueryTexture(texbb.tex, NULL, NULL, &w, &h);

    label_texbb_.dimensions.x = 0;
    label_texbb_.dimensions.y = 0; 
    label_texbb_.dimensions.w = w; 
    label_texbb_.dimensions.h = h; 
}

bool Button::isInsideRect(const SDL_Rect& rect, const int x, const int y) const
{
	if ( x > rect.x && x < rect.x+rect.w && 
		y > rect.y && y < rect.y+rect.h )
	{
		return true;
	}
	else
	{
		return false;
	}

}