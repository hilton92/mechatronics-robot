/* 
 * File:   events.h
 * Author: Justin
 *
 * Created on February 5, 2016, 9:45 PM
 */



//#include "constants.h"



#ifndef HANDLERS_H
#define	HANDLERS_H

//functions to use------------------------------------------------------------------------

void clearEvents();
void clearEventInfo();
void initializeEvents();
void setLow(int*);
void setHigh(int*);
void incrementByOne(int*);
int getEvent(int*);
int getEventInfo(int*);
void decrementByOne(int*);
void setBallsFull();
int containsBalls();

//----------------------------------------------------------

//other stubs  !!!!!!!--Do not call these functions directly
int eventInfoManipulator(unsigned char, unsigned char, int );
int eventManipulator(unsigned char, unsigned char, int); 



//event variables 1 or 0
extern int dispenserLightDetected;
extern int dispenserLightThresholdMet;
extern int binLightDetected;
extern int binLightNotDetected;
extern int binLightThresholdMet;
extern int oneSonicSensorThresholdMet;
extern int twoSonicSensorThresholdMet;
extern int timer1Met;
extern int buttonPressed;
extern int leftBinLightDetected;
extern int rightBinLightDetected;
extern int frontBinLightDetected;
extern int frontButtonsPressed;
extern int turretButtonPressed;

//event info variables
extern int motorPeriodCount;
extern int turretPeriodCount;
extern int shootTime;
extern int timer5Met;
extern int currentBin;
 
//other globals
extern int ballCount;
extern float IRthreshold;
//extern float MAXIRThreshold;
extern float IRValArray[4];
extern float dispenserThreshold;
extern int firstTime;
//Function Definitions----------------------------------------



void clearEvents()
{
    dispenserLightDetected = 0;
    dispenserLightThresholdMet = 0;
    binLightDetected = 0;
    binLightNotDetected = 0;
    binLightThresholdMet = 0;
    oneSonicSensorThresholdMet = 0;
    twoSonicSensorThresholdMet = 0;
    timer1Met = 0;
    leftBinLightDetected = 0;
    rightBinLightDetected = 0;
    frontBinLightDetected = 0;
    frontButtonsPressed = 0;
    turretButtonPressed = 0;
}


void clearEventInfo()
{
    shootTime = 0;
    motorPeriodCount = 0;
    turretPeriodCount = 0;
}

void initializeEvents()
{
    clearEvents();
    clearEventInfo();
    ballCount = 0;
    timer5Met = 0;
    firstTime = 1;
}

void setHigh(int *variable)
{
    *variable = 1;
}

void setLow(int *variable)
{
    *variable = 0;
}

void incrementByOne(int *variable)
{
    *variable = *variable + 1;
}

int getEvent(int *variable)
{
    if(*variable == 1)
    {
        return 1;
    }
    else if(*variable == 0)
    {
        return 0;
    }  
    
    //error
    else
    {
//        exit(0);
        return 0;
    }
}

int getEventInfo(int *variable)
{
    return *variable;
}

//ball specific handlers

void decrementByOne(int *variable)
{
    *variable = *variable - 1;
}

void setBallsFull()
{
    ballCount = 6;
}


int containsBalls()
{
    if(ballCount > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
#endif	/* EVENTS_H */

