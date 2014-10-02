#ifndef SRC_OUTPUT_PANEL_H
#define SRC_OUTPUT_PANEL_H

#include "RenderingEngine.h"

class OutputPanel
{

private: 
    SDL_Texture*  ptr_background_tex_;  

    SDL_Texture** ptr_ptr_winner_tex_;

    SDL_Texture*  ptr_x_victory_tex_;

    SDL_Texture*  ptr_o_victory_tex_;   
    
    SDL_Texture*  ptr_tie_victory_tex_;     
public:

    enum VictorType
    {
        VICTOR_TYPE_RESET = -1,
    
        VICTOR_TYPE_X,
    
        VICTOR_TYPE_O,
    
        VICTOR_TYPE_TIE,
    };
    
	OutputPanel();

	~OutputPanel();	

	bool Init(SDL_Renderer* r);

	inline SDL_Texture* getBackgroundTex() const { return ptr_background_tex_; }
	
	inline SDL_Texture** getWinnerTex() const { return ptr_ptr_winner_tex_; }	

	void setWinnerTex(VictorType newValue);	
};

#endif