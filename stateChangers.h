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
void nullState();
void waitForButton();
void turnFindIR();
void faceDispenser();
void driveToCornerQuick();
void driveIntoCorner();
void loadBalls();
void driveToMiddle();
void faceBin();
void backUpToShoot();
void shootGoals();
void setToNullState();

void changeToState(unsigned char state)
{
    //reset the events
    clearEvents();
    
    //reset back to null state
    setToNullState();
    
    switch (state)
    {
        case WAITFORBUTTON:
            
            //enter the state
            waitForButton();
            break;
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
         case FACEBIN:
            
            //enter the state
             faceBin();
            break;
        case BACKUPTOSHOOT:
            
            //enter the state
            backUpToShoot();
            break;
        case SHOOTGOALS:
            //enter the state
            shootGoals();
            break;
            
    }
    
}

void waitForButton()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    
}

void turnFindIR()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    
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

void faceBin()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    
}

void backUpToShoot()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    
}

void shootGoals()
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    
}

void setToNullState()
{
    //disengage all motors and actuators 
    toggleMotors(LEFT,OFF);
    toggleMotors(RIGHT,OFF);   
}
#endif	/* STATECHANGERS_H */

