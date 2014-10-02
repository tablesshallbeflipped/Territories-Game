#include "GameEngine.h"

GameEngine::GameEngine() 
{
    cout << "GameEngine Ctor Called" << endl;

    is_running_ = true;
    numFrames_ = 0;
}

void GameEngine::Run() 
{
    if ( !Init() )
    {
        cout << "GameEngine initialization failed" << endl;
    }

    while(is_running_) 
    {
        if (GameStateManager::isNewState())
        {
            game_state_manager_.Init(&rendering_engine_.getWindow());
        }

        while(SDL_PollEvent(&event_)) 
        {
            HandleEvents();
        }

        game_state_manager_.Update(&rendering_engine_.getWindow());

        Render();
    }

}

bool GameEngine::Init() 
{

    if ( !rendering_engine_.Init() )
    {
        cout << "Failure to initialize RenderingEngine! @GameEngine::Init()" << endl;
        return false;
    }

    GameStateManager::setCurrentState(GAMESTATE_SPLASH);

    appLifeTimer_ = Timer();
    appLifeTimer_.Start();

    return true;
}

void GameEngine::Clean() 
{
    GameStateManager::setCurrentState(GAMESTATE_NULL);
    rendering_engine_.Clean();
    is_running_ = false;
}

void GameEngine::HandleEvents() 
{
    switch(event_.type) 
    {

        case SDL_QUIT:
            Clean();
            break;
    } 

    rendering_engine_.getWindow().HandleEvents(&event_);

    game_state_manager_.HandleEvents(&event_);

    if ((int)game_state_manager_.getStateType() == -1)
    {
        Clean(); 
    }
}


void GameEngine::DrawAvgFPS()
{
    float avgFPS = numFrames_ / ( appLifeTimer_.getTicks() / 1000.f );
    
    std::stringstream timeText; 
                               
    timeText.str( "" ); 
                                           
    timeText << "Average FPS [" << avgFPS << "] "; 
             
	SDL_Color textColor = {0, 255, 0, 0};	
					
    SDL_Texture* fpsTex;   
    
    TTF_Font* _pFont = TTF_OpenFont( "_resources/TPBAFK-Regular.otf", 28 );
 
	fpsTex = RenderingEngine::CreateTextureFromString(rendering_engine_.getRenderer(), timeText.str(), textColor, _pFont);

    RenderingEngine::DrawTexture(rendering_engine_.getRenderer(), fpsTex, 10, 10); 

    SDL_DestroyTexture(fpsTex);              

    TTF_CloseFont( _pFont );
    _pFont = nullptr;

    numFrames_++;                            
}

void GameEngine::Render() 
{
    rendering_engine_.Begin();

    game_state_manager_.Render(&rendering_engine_.getWindow());
  
    DrawAvgFPS();

    rendering_engine_.getScene().ReleaseRenderTarget(rendering_engine_.getRenderer());

    rendering_engine_.RenderScene();

    rendering_engine_.End();
}

