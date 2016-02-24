/* 
 * File:   events.h
 * Author: Justin
 *
 * Created on February 5, 2016, 9:45 PM
 */

#include <stdlib.h>

#include "enums.h"



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




//Function Definitions----------------------------------------
int eventManipulator(unsigned char action, unsigned char event, int value)
{
    //event variables 0 = inactive 1 = active
    static int dispenserLightDetected;
    static int dispenserLightThresholdMet;
    static int binLightDetected;
    static int binLightNotDetected;
    static int binLightThresholdMet;
    static int oneSonicSensorThresholdMet;
    static int twoSonicSensorThresholdMet;
    static int timer1Met;
    static int buttonPressed;
    static int ballsFull;
    
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
        perror("getEventStatus received invalid event");
        exit(1);
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
        perror("updateEventActive received invalid event");
        exit(1); 
    }
}

//update an event to high or low
void setEventInactive(unsigned char event)
{
    int status = eventManipulator(UPDATE, event, 0);
    if(status == 200)
    {
        //error 
        perror("updateEventInactive received invalid event");
        exit(1); 
    }
}

void clearEvents()
{
    eventManipulator(CLEAR,0,0);
}

//--------------Do not call from outside this file!!!!
int eventInfoManipulator(unsigned char action, unsigned char attribute, int value)
{
    static int periodCount;
    static int shootTime;
    switch(action)
    {
        case CLEAR:
            switch(attribute)
            {
                case SHOOTTIME:
                    shootTime = 0;
                    return 0;
                    break;
                case PERIODCOUNT:
                    periodCount = 0;
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
                case PERIODCOUNT:
                    periodCount = value;
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
                case PERIODCOUNT:
                    return periodCount;
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
                case PERIODCOUNT:
                    periodCount = periodCount + value;
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
        perror("updateEventActive received invalid event");
        exit(1); 
    }
}

void clearEventInfo(unsigned char event)
{
    int status = eventInfoManipulator(CLEAR, event, 0);
    if(status == -200)
    {
        //error 
        perror("updateEventActive received invalid event");
        exit(1); 
    }
}

int requestEventInfo(unsigned char event)
{
    int status = eventInfoManipulator(REQUEST, event, 1);
    if(status == -200)
    {
        //error 
        perror("updateEventActive received invalid event");
        exit(1); 
    }
    else
    {
        return status;

    }
}

void clearAllEventInfo()
{
    clearEventInfo(SHOOTTIME);
    clearEventInfo(PERIODCOUNT);
}

void initializeEvents()
{
    clearEvents();
    clearAllEventInfo();
    setEventInactive(BALLSFULL);
}



#endif	/* EVENTS_H */

