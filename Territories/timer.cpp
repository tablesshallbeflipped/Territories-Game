// Author: Timur Karasapan
// Email: timur.karasapan@gmail.com
// Twitter: #LinkerError
//
// Last Update: 26/09/2014 : 1:48 PM (EST)
// Version: 1.0.5

#include "Timer.h"

// Initializes member variables to initial values. Does NOT start the timer.
Timer::Timer()
{  
    paused_ = false;
    started_ = false;
    start_ticks_ = 0;
    paused_ticks_ = 0;
}

// Starts the timer by setting started_ to true and invokes SDL_GetTicks()
// to aquire the current clock time then stores that value within start_ticks_.
void Timer::Start()
{
    //Start the timer
    started_ = true;

    //Unpause the timer
    paused_ = false;

    //Get the current clock time
    start_ticks_ = SDL_GetTicks();
	paused_ticks_ = 0;
}

// Stops the timer by resetting member variables to thier initial values.
void Timer::Stop()
{
    //Stop the timer
    started_ = false;

    //Unpause the timer
    paused_ = false;

	//Clear tick variables
	start_ticks_ = 0;
	paused_ticks_ = 0;
}

// Pauses the timer by first checking to ensure the timer has already been 
// started and hasn't already been paused. Then paused_ is set to true and
// paused_ticks_ is updated.
void Timer::Pause()
{
    //If the timer is running and isn't already paused
    if( started_ && !paused_ )
    {
        //Pause the timer
        paused_ = true;

        //Calculate the paused ticks
        paused_ticks_ = SDL_GetTicks() - start_ticks_;
		start_ticks_ = 0;
    }
}

// Unpauses the timer by first checking to ensure the timer has already been 
// started and been paused. Then paused_ is set to false, paused_ticks_ reset 
// back to it's initial value and start_ticks_ is updated.
void Timer::Unpause()
{
    //If the timer is running and paused
    if( started_ && paused_ )
    {
        //Unpause the timer
        paused_ = false;

        //Reset the starting ticks
        start_ticks_ = SDL_GetTicks() - paused_ticks_;

        //Reset the paused ticks
        paused_ticks_ = 0;
    }
}

// Checks to ensure that the timer has been started. If the timer is also 
// paused at the time getTicks() is invoked then paused_ticks_ will be returned
// If the timer has been started and NOT paused then it will return the total
// time passed (in milliseconds) since the timer started.
Uint32 Timer::getTicks()
{
	//The actual timer time
	Uint32 time = 0;

    //If the timer is running
    if( started_ )
    {
        //If the timer is paused
        if( paused_ )
        {
            //Return the number of ticks when the timer was paused
            time = paused_ticks_;
        }
        else
        {
            //Return the current time minus the start time
            time = SDL_GetTicks() - start_ticks_;
        }
    }

    return time;
}