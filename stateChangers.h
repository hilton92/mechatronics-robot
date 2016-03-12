/* 
 * File:   stateChangers.h
 * Author: Justin
 *
 * Created on February 6, 2016, 2:03 PM
 */
#include "handlers.h"
#include "motorFunctions.h"

#ifndef STATECHANGERS_H
#define	STATECHANGERS_H

//functions to use----------------------------------------
void changeToState(unsigned char);
void turnFindIR();
void faceDispenser();
void driveToCornerQuick();
void driveIntoCorner();
void loadBalls();
void driveToMiddle();
void waitForBinLight();
void faceLeftBinLight();
void faceRightBinLight();
void faceFrontBinLight();
void shootGoals();
void closeSolenoid();
void setToNullState();

void changeToState(unsigned char state)
{
    //reset the events
    clearEvents();
    
    //reset back to null state
    setToNullState();
    
    
    switch (state)
    {
        case TURNFINDIR:
            
            //enter the state
            turnFindIR();
            break;
        case FACEDISPENSER:
            
            //enter the state
            faceDispenser();
            break;
        case DRIVETOCORNERQUICK:
            
            //enter the state
            driveToCornerQuick();
            break;
            
        case DRIVEINTOCORNER:
            
            //enter the state
            driveIntoCorner();
            break;
            
        case LOADBALLS:
           
            //enter the state
            loadBalls();
            break;
            
         case DRIVETOMIDDLE:
            
            //enter the state
             driveToMiddle();
            break;   
            
        case WAITFORBINLIGHT:
            //enter the state
            waitForBinLight();
            break;
            
        case FACELEFTBINLIGHT:
            //enter the state
            faceLeftBinLight();
            break;
            
        case FACERIGHTBINLIGHT:
            //enter the state
            faceRightBinLight();
            break;
            
        case FACEFRONTBINLIGHT:
            //enter the state
            faceFrontBinLight();
            break;
            
        case SHOOTGOALS:
            //enter the state
            shootGoals();
            break;
        
        case CLOSESOLENOID:
            //enter the state
            closeSolenoid();
            break;
            
    }
    
}



void turnFindIR()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded, periodCount)
    
}

void faceDispenser()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    
}

void driveToCornerQuick()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    
}

void driveIntoCorner()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    
}

void loadBalls()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    
}

void driveToMiddle()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    
}

void waitForBinLight()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded, periodCount)    
}

void faceLeftBinLight()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded, periodCount)
    
}

void faceRightBinLight()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded, periodCount)
    
}

void faceFrontBinLight()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded, periodCount)
    
}

void shootGoals()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    
}

void closeSolenoid()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded, periodCount)
    
}

void setToNullState()
{
    //disengage all motors and actuators 
//    toggleMotors(LEFT,OFF);
//    toggleMotors(RIGHT,OFF);   
    toggleMotorsOff();
}
#endif	/* STATECHANGERS_H */

