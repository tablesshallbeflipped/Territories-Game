#ifndef SRC_FRAMEWORK_GAME_H
#define SRC_FRAMEWORK_GAME_H

#include <iostream>
#include <sstream>


#include "GameStateManager.h"
#include "Timer.h"

using std::cout;
using std::endl;

class GameEngine
{
private:

    RenderingEngine rendering_engine_;

    GameStateManager game_state_manager_;

    SDL_Event event_;

    bool is_running_;
        
    Timer appLifeTimer_;

    Uint32 numFrames_;  
      
    void DrawAvgFPS();                  

    bool Init();
            
    void Clean();

    void HandleEvents();

    void Render();  


public:
    GameEngine();
    ~GameEngine() {};
   
    void Run();


};
#endif