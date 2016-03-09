/* 
 * File:   events.h
 * Author: Justin
 *
 * Created on February 5, 2016, 9:45 PM
 */

#include <stdlib.h>

#include "constants.h"



#ifndef HANDLERS_H
#define	HANDLERS_H

//functions to use------------------------------------------------------------------------

void clearEvents();
void clearEventInfo();
void initializeEvents();
void setLow(int*);
void setHigh(int*);
void incrementByOne(int*);

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
extern int ballsFull;

//event info variables
extern int periodCount;
extern int shootTime;
extern int timer5Met;
 

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
}


void clearEventInfo()
{
    shootTime = 0;
    periodCount = 0;
}

void initializeEvents()
{
    clearEvents();
    clearEventInfo();
    ballsFull = 0;
    timer5Met = 0;
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



#endif	/* EVENTS_H */

