#ifndef SRC_BOARD_H    
#define SRC_BOARD_H  

#include "RenderingEngine.h"

class Board
{  
private:
    static const int NUM_COMBOS = 8;

    static const int NUM_IN_COMBO = 3;

    static const int WINNING_COMBOS[NUM_COMBOS][NUM_IN_COMBO];  
    
    int grid_[9];

    SDL_Texture* ptr_grid_texture_; 

    SDL_Texture* ptr_game_over_texture_; 

    SDL_Texture* ptr_o_texture_;
        
    SDL_Texture* ptr_x_texture_;

    bool IsWinner(const int piece) const;

public:
    enum GridType
    {
        GRID_TYPE_NONE = 0,

        GRID_TYPE_X,

        GRID_TYPE_O
    };

    static int NUM_TURN; 

    Board();
    ~Board();

    bool Init(SDL_Renderer* r);

    // Checks if there is a winner
    //    @return -1 Tie              (Game Over)
    //    @return 0  No Winners Yet   (Continue Game)
    //    @return 1  X is the VICTOR  (Game Over)
    //    @return 2  Y is the VICTOR  (Game Over)
    int DetermineWinner() const;

    bool IsFull() const;

    inline int* getGrid() { return grid_; }
		     
    inline SDL_Texture* getGridTexture() const { return ptr_grid_texture_; }

    inline SDL_Texture* getGameOverTexture() const { return ptr_game_over_texture_; }  

    inline SDL_Texture* getOTexture() const { return ptr_o_texture_; }

    inline SDL_Texture* getXTexture() const { return ptr_x_texture_; }

    void ResetGrid();
    
    inline void SetCell(const int id, const int type)
    {
        if(id < 0 || id >= 9)   { return; }
        if(type < 0 || type > GRID_TYPE_O)   { return; }

        grid_[id] = type;
        Board::NUM_TURN++;
    }
      
};

#endif
