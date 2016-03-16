/* 
 * File:   stateChangers.h
 * Author: Justin
 *
 * Created on February 6, 2016, 2:03 PM
 */
#include "handlers.h"
#include "motorFunctions.h"
#include "functions.h"

#ifndef STATECHANGERS_H
#define	STATECHANGERS_H

//functions to use----------------------------------------
void changeState(unsigned char, unsigned char);
void turnFindIR(unsigned char);
void faceDispenser(unsigned char);
void driveToCornerQuick(unsigned char);
void driveIntoCorner(unsigned char);
void loadBalls(unsigned char);
void driveToMiddle(unsigned char);
void waitForBinLight(unsigned char);
void faceLeftBinLight(unsigned char);
void faceRightBinLight(unsigned char);
void faceFrontBinLight(unsigned char);
void shootGoals(unsigned char);
void closeSolenoid(unsigned char);
void setToNullState();

void changeState(unsigned char state, unsigned char direction)
{
    if(direction == EXIT)
    {
        //reset the events
        clearEvents();
        
        //reset back to null state
        setToNullState();
    }
    
    switch (state)
    {
        case TURNFINDIR:
            
            //enter the state
            turnFindIR(direction);
            break;
        case FACEDISPENSER:
            
            //enter the state
            faceDispenser(direction);
            break;
        case DRIVETOCORNERQUICK:
            
            //enter the state
            driveToCornerQuick(direction);
            break;
            
        case DRIVEINTOCORNER:
            
            //enter the state
            driveIntoCorner(direction);
            break;
            
        case LOADBALLS:
           
            //enter the state
            loadBalls(direction);
            break;
            
         case DRIVETOMIDDLE:
            
            //enter the state
             driveToMiddle(direction);
            break;   
            
        case WAITFORBINLIGHT:
            //enter the state
            waitForBinLight(direction);
            break;
            
        case FACELEFTBINLIGHT:
            //enter the state
            faceLeftBinLight(direction);
            break;
            
        case FACERIGHTBINLIGHT:
            //enter the state
            faceRightBinLight(direction);
            break;
            
        case FACEFRONTBINLIGHT:
            //enter the state
            faceFrontBinLight(direction);
            break;
            
        case SHOOTGOALS:
            //enter the state
            shootGoals(direction);
            break;
        
        case CLOSESOLENOID:
            //enter the state
            closeSolenoid(direction);
            break;
            
    }
    
}



void turnFindIR(unsigned char direction)
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded, periodCount)
    if(direction == EXIT)
    {

    }
    else
    {

    }
}

void faceDispenser(unsigned char direction)
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    if(direction == EXIT)
    {

    }
    else
    {
        
    } 
}

void driveToCornerQuick(unsigned char direction)
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    if(direction == EXIT)
    {

    }
    else
    {
        
    } 
}

void driveIntoCorner(unsigned char direction)
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    if(direction == EXIT)
    {

    }
    else
    {
        
    }
}

void loadBalls(unsigned char direction)
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    if(direction == EXIT)
    {

    }
    else
    {
        
    }
}

void driveToMiddle(unsigned char direction)
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    if(direction == EXIT)
    {
        rotateTurret(90, LEFT);
    }
    else
    {
        driveStraight(MOTORLOWSPEED,BACKWARD);
    }
}

void waitForBinLight(unsigned char direction)
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded, periodCount) 
    if(direction == EXIT)
    {

    }
    else
    {
        //rotateTurret(90, LEFT);
    }   
}

void faceLeftBinLight(unsigned char direction)
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded, periodCount)
    if(direction == EXIT)
    {

    }
    else
    {
        
    }
}

void faceRightBinLight(unsigned char direction)
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded, periodCount)
    if(direction == EXIT)
    {

    }
    else
    {
        
    }
}

void faceFrontBinLight(unsigned char direction)
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded, periodCount)
    if(direction == EXIT)
    {

    }
    else
    {
        
    }
}

void shootGoals(unsigned char direction)
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded)
    if(direction == EXIT)
    {

    }
    else
    {
        
    }
}

void closeSolenoid(unsigned char direction)
{
    //reset timers
    //set or unset certain variables(i.e. ballsLoaded, periodCount)
    if(direction == EXIT)
    {

    }
    else
    {
        
    }
}

void setToNullState()
{
    //disengage all motors and actuators 
//    toggleMotors(LEFT,OFF);
//    toggleMotors(RIGHT,OFF);   
    toggleMotorsOff();
    

}
#endif	/* STATECHANGERS_H */

