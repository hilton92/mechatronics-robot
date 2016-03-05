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

int getEventStatus(unsigned char event);
void setEventActive(unsigned char);
void setEventInactive(unsigned char);
void clearEvents();
void incrementEventInfo(unsigned char, int);
void clearEventInfo(unsigned char );
int requestEventInfo(unsigned char);
void initializeEvents();

//----------------------------------------------------------

//other stubs  !!!!!!!--Do not call these functions directly
int eventInfoManipulator(unsigned char, unsigned char, int );
int eventManipulator(unsigned char, unsigned char, int); 




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

extern int periodCountLeft;
extern int periodCountRight;
extern int shootTime;

//Function Definitions----------------------------------------
int eventManipulator(unsigned char action, unsigned char event, int value)
{
    //event variables 0 = inactive 1 = active

    
    //ACTION CLEAR--note balls loaded doesn't get cleared
    if (action == CLEAR)
    {
        dispenserLightDetected = 0;
        dispenserLightThresholdMet = 0;
        binLightDetected = 0;
        binLightNotDetected = 0;
        binLightThresholdMet = 0;
        oneSonicSensorThresholdMet = 0;
        twoSonicSensorThresholdMet = 0;
        timer1Met = 0;
        buttonPressed = 0;
    }
    
    //ACTION UPDATE
    else if(action == UPDATE)
    {
        switch (event)
        {
            case DISPENSERLIGHTDETECTED:
                dispenserLightDetected = value;
                break;
                
            case DISPENSERLIGHTTHRESHOLDMET: 
                dispenserLightThresholdMet = value;
                break;
            
            case BINLIGHTDETECTED:
                binLightDetected = value;
                break;
                
            case BINLIGHTTHRESHOLDMET:
                binLightThresholdMet = value;
                break;
                
           case BINLIGHTNOTDETECTED:
                binLightNotDetected = value;
                break;
                
            case ONESONICSENSORTHRESHOLDMET:
                oneSonicSensorThresholdMet = value;
                break;
                
            case TWOSONICSENSORTHRESHOLDMET:
                twoSonicSensorThresholdMet = value;
                break;
                
            case TIMER1MET:
                timer1Met = value;
                break;
                
            case BUTTONPRESSED:
                buttonPressed = value;
                break;
            
            case BALLSFULL:
                ballsFull = value;
                break;
                
            default:
                //failed return state
                return 200;
                break;
        }
    }
    
    //ACTION REQUEST
    else if(action == REQUEST)
    {
        switch (event)
        {
            case DISPENSERLIGHTDETECTED:
                return dispenserLightDetected;
                break;
                
            case DISPENSERLIGHTTHRESHOLDMET: 
                return dispenserLightThresholdMet;
                break;
            
            case BINLIGHTDETECTED:
                return binLightDetected;
                break;
                
            case BINLIGHTNOTDETECTED:
                return binLightNotDetected;
                break;
                
            case BINLIGHTTHRESHOLDMET:
                return binLightThresholdMet;
                break;
                
            case ONESONICSENSORTHRESHOLDMET:
                return oneSonicSensorThresholdMet;
                break;
                
            case TWOSONICSENSORTHRESHOLDMET:
                return twoSonicSensorThresholdMet;
                break;
                
            case TIMER1MET:
                return timer1Met;
                break;
                
            case BUTTONPRESSED:
                return buttonPressed;
                break;
                
            case BALLSFULL:
                return ballsFull;
                break;
                
            default:
                //failed return state
                return 200;
                break;
        }
    }
    
    //default return
    return 0;
}


//request the status of an event
int getEventStatus(unsigned char event)
{
    int status = eventManipulator(REQUEST, event, 0);
    if(status == 200)
    {
        //error 
       // perror("getEventStatus received invalid event");
        //exit(1);
        return 200;
    }
    else
    {
        return status;
    }
}

//update an event to high or low
void setEventActive(unsigned char event)
{
    int status = eventManipulator(UPDATE, event, 1);
    if(status == 200)
    {
        //error 
       // perror("updateEventActive received invalid event");
        //exit(1); 
    }
}

//update an event to high or low
void setEventInactive(unsigned char event)
{
    int status = eventManipulator(UPDATE, event, 0);
    if(status == 200)
    {
        //error 
       // perror("updateEventInactive received invalid event");
        //exit(1); 
    }
}

void clearEvents()
{
    eventManipulator(CLEAR,0,0);
}

//--------------Do not call from outside this file!!!!
int eventInfoManipulator(unsigned char action, unsigned char attribute, int value)
{

    switch(action)
    {
        case CLEAR:
            switch(attribute)
            {
                case SHOOTTIME:
                    shootTime = 0;
                    return 0;
                    break;
                case PERIODCOUNTLEFT:
                    periodCountLeft = 0;
                    return 0;
                    break;
                case PERIODCOUNTRIGHT:
                    periodCountRight = 0;
                    return 0;
                    break;
            }
            break; 
        case UPDATE:
            switch(attribute)
            {
                case SHOOTTIME:
                    shootTime = value;
                    return 0;
                    break;
                case PERIODCOUNTLEFT:
                    periodCountLeft = value;
                    return 0;
                    break;
                case PERIODCOUNTRIGHT:
                    periodCountRight = value;
                    return 0;
                    break;
            }
            break;
        case REQUEST:
            switch(attribute)
            {
                case SHOOTTIME:
                    return shootTime;
                    break;
                case PERIODCOUNTLEFT:
                    return periodCountLeft;
                    break;
                case PERIODCOUNTRIGHT:
                    return periodCountRight;
                    break;
            }
            break;
        case INCREMENT:
            switch(attribute)
            {
                case SHOOTTIME:
                    shootTime = shootTime + value;
                    return 0;
                    break;
                case PERIODCOUNTLEFT:
                    periodCountLeft = periodCountLeft + value;
                    return 0;
                    break;
                case PERIODCOUNTRIGHT:
                    periodCountRight = periodCountRight + value;
                    return 0;
                    break;
            }
            break;
    }
    return -200;
}


void incrementEventInfo(unsigned char event, int value)
{
    int status = eventInfoManipulator(INCREMENT, event, value);
    if(status == -200)
    {
        //error 
       // perror("updateEventActive received invalid event");
       // exit(1); 
    }
}

void clearEventInfo(unsigned char event)
{
    int status = eventInfoManipulator(CLEAR, event, 0);
    if(status == -200)
    {
        //error 
        //perror("updateEventActive received invalid event");
       // exit(1); 
    }
}

int requestEventInfo(unsigned char event)
{
    int status = eventInfoManipulator(REQUEST, event, 1);
    if(status == -200)
    {
        //error 
        //perror("updateEventActive received invalid event");
       // exit(1); 
        return 200;
    }
    else
    {
        return status;

    }
}

void clearAllEventInfo()
{
    clearEventInfo(SHOOTTIME);
    clearEventInfo(PERIODCOUNTRIGHT);
    clearEventInfo(PERIODCOUNTLEFT);
}

void initializeEvents()
{
    clearEvents();
    clearAllEventInfo();
    setEventInactive(BALLSFULL);
}



#endif	/* EVENTS_H */

