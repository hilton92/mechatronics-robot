/* 
 * File:   events.h
 * Author: Justin
 *
 * Created on February 5, 2016, 9:45 PM
 */

#include <string.h>
#include <stdlib.h>

#include "enums.h"



#ifndef EVENTS_H
#define	EVENTS_H


enum {CLEAR, UPDATE, REQUEST};

///////////////////-----only call from within events.h!!!!!
int eventManipulator(unsigned char action, unsigned char event, int value)
{
    //event variables
    int dispenserLightDetected;
    int dispenserLightThresholdMet;
    int binLightDetected;
    int binLightThresholdMet;
    int cornerSensorThresholdMet;
    int cornerSensorsEquivalent;
    int timerEvent;
    int buttonPressed;
    int ballsLoaded;
    
    //ACTION CLEAR--note balls loaded doesn't get cleared
    if (action == CLEAR)
    {
        dispenserLightDetected = 0;
        dispenserLightThresholdMet = 0;
        binLightDetected = 0;
        binLightThresholdMet = 0;
        cornerSensorThresholdMet = 0;
        cornerSensorsEquivalent = 0;
        timerEvent = 0;
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
                
            case CORNERSENSORTHRESHOLDMET:
                cornerSensorThresholdMet = value;
                break;
                
            case CORNERSENSORSEQUIVALENT:
                cornerSensorsEquivalent = value;
                break;
                
            case TIMEREVENT:
                timerEvent = value;
                break;
                
            case BUTTONPRESSED:
                buttonPressed = value;
                break;
            
            case BALLSLOADED:
                ballsLoaded = value;
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
                
            case BINLIGHTTHRESHOLDMET:
                return binLightThresholdMet;
                break;
                
            case CORNERSENSORTHRESHOLDMET:
                return cornerSensorThresholdMet;
                break;
                
            case CORNERSENSORSEQUIVALENT:
                return cornerSensorsEquivalent;
                break;
                
            case TIMEREVENT:
                return timerEvent;
                break;
                
            case BUTTONPRESSED:
                return buttonPressed;
                break;
                
            case BALLSLOADED:
                return ballsLoaded;
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



#endif	/* EVENTS_H */

