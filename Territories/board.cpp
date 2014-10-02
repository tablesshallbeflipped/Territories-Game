#include "Board.h"

const int Board::WINNING_COMBOS[NUM_COMBOS][NUM_IN_COMBO] = { {0, 1, 2},
                                                              {3, 4, 5},   
                                                              {6, 7, 8},   
                                                              {0, 3, 6},    
                                                              {1, 4, 7},   
                                                              {2, 5, 8},   
                                                              {0, 4, 8},   
                                                              {2, 4, 6} }; 

int Board::NUM_TURN = 0;   

Board::Board() :  
ptr_grid_texture_(nullptr),       
ptr_game_over_texture_(nullptr),  
ptr_o_texture_(nullptr),          
ptr_x_texture_(nullptr)           
{
    // Set the entire grid to empty 
    //    grid_ =    |0, 0, 0|
    //               |0, 0, 0|
    //               |0, 0, 0|
    for(int i = 0; i < 9; i++) 
    {
        grid_[i] = GRID_TYPE_NONE;
    }
}

Board::~Board()
{
    Board::NUM_TURN = 0; 

    RenderingEngine::DestroyTexture(ptr_grid_texture_);
    RenderingEngine::DestroyTexture(ptr_game_over_texture_);
    RenderingEngine::DestroyTexture(ptr_x_texture_);
    RenderingEngine::DestroyTexture(ptr_o_texture_);
 }

bool Board::Init(SDL_Renderer* r)
{

    ptr_grid_texture_ = RenderingEngine::LoadTexture(r, "_resources/grid.png");
    ptr_game_over_texture_ = RenderingEngine::LoadTexture(r, "_resources/gameOver.png");
    ptr_x_texture_ = RenderingEngine::LoadTexture(r, "_resources/x.png");
    ptr_o_texture_ = RenderingEngine::LoadTexture(r, "_resources/o.png");

    if ( ptr_grid_texture_ && ptr_game_over_texture_ && ptr_x_texture_ && ptr_o_texture_ )
    {
        return true;
    }
    else
    {
        cout << "Board::Init() Failure to Load Texture. | " << SDL_GetError() << endl;
        return false;
    }
}

bool Board::IsFull() const
{  
    bool full = true;
    int i = 0;

    while (full && i < 9)
    {
        if (grid_[i] == GRID_TYPE_NONE)
        {
            full = false;
        }

        ++i;
    }

    return full;
} 

int Board::DetermineWinner() const
{
	bool XisWinner = IsWinner(GRID_TYPE_X);
	bool OisWinner = IsWinner(GRID_TYPE_O);

	if (XisWinner)
	{
	    return GRID_TYPE_X; 
	}
	else if (OisWinner)
	{
	    return GRID_TYPE_O; 
	}
	else if ( IsFull() && !XisWinner && !OisWinner)
	{
	    return -1;
	}
	else if ( !IsFull() && !XisWinner && !OisWinner)
	{
	    return GRID_TYPE_NONE;
	}

}

void Board::ResetGrid()
{
    for(int i = 0; i < 9; i++) 
    {
        grid_[i] = GRID_TYPE_NONE;
    }
}

bool Board::IsWinner(const int piece) const
{

    bool winner = false;
    int i = 0;

    while (!winner && i < NUM_COMBOS)
    {
        int piecesInCombo = 0;

        for (int j = 0; j < NUM_IN_COMBO; ++j)
        {
            if (grid_[WINNING_COMBOS[i][j]] == piece)
            {
                ++piecesInCombo;
            }
        }      

        if (piecesInCombo == NUM_IN_COMBO)
        {
            winner = true;
        }

        ++i;
    }
    
    return winner;
}

