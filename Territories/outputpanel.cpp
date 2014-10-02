#include "OutputPanel.h"

OutputPanel::OutputPanel() : 
ptr_background_tex_(nullptr),  
ptr_ptr_winner_tex_(nullptr), 
ptr_x_victory_tex_(nullptr), 
ptr_o_victory_tex_(nullptr), 
ptr_tie_victory_tex_(nullptr) {}  

OutputPanel::~OutputPanel()
{
    RenderingEngine::DestroyTexture(ptr_background_tex_);
    RenderingEngine::DestroyTexture(ptr_x_victory_tex_);
    RenderingEngine::DestroyTexture(ptr_o_victory_tex_);
    RenderingEngine::DestroyTexture(ptr_tie_victory_tex_);
}

bool OutputPanel::Init(SDL_Renderer* r)
{
	ptr_background_tex_ = RenderingEngine::LoadTexture(r, "_resources/bar.png");
	ptr_x_victory_tex_ = RenderingEngine::LoadTexture(r, "_resources/victoryX.png");
    ptr_o_victory_tex_ = RenderingEngine::LoadTexture(r, "_resources/victoryO.png");
    ptr_tie_victory_tex_ = RenderingEngine::LoadTexture(r, "_resources/victoryNone.png");

    if ( !ptr_background_tex_ || !ptr_o_victory_tex_ || !ptr_x_victory_tex_ || !ptr_tie_victory_tex_ )
    {
    	cout << "OutputPanel::Init() Failure to Load Texture. | " << SDL_GetError() << endl;
    	return false;
    }

    return true;
}

void OutputPanel::setWinnerTex(VictorType newValue)
{
	if (newValue == VICTOR_TYPE_X)
	{
		ptr_ptr_winner_tex_ = &ptr_x_victory_tex_;
	}
	else if (newValue == VICTOR_TYPE_O)
	{
		ptr_ptr_winner_tex_ = &ptr_o_victory_tex_;
	}
    else if (newValue == VICTOR_TYPE_TIE)
    {
        ptr_ptr_winner_tex_ = &ptr_tie_victory_tex_;
    }	
    else if (newValue == VICTOR_TYPE_RESET)
	{
		ptr_ptr_winner_tex_ = nullptr;
	}
}
