/* 
 * File:   caseSwitch.h
 * Author: Justin
 *
 * Created on February 27, 2016, 10:12 AM
 */
#include "stateChangers.h"
#include "eventUpdaters.h"
#include "functions.h"


#ifndef CASESWITCH_H
#define	CASESWITCH_H

//function prototypes
void caseSwitch();

//-----------------


void caseSwitch()
{
    //initialize state variable and state
    static unsigned char currentState = DRIVETOCORNERQUICK;
   
    //initialize state
   changeState(DRIVETOCORNERQUICK, ENTER);
    
    while(1)
    {

        switch (currentState)
        {

            case TURNFINDIR:

                while(1)
                { 
                    //state specific updaters
                    checkDispenserLightDetected();
                    // checkBinLightDetected();                   
                    
                    //check event status
                    if(getEvent(&dispenserLightDetected) )
                    {

                        //exit the state
                        changeState(TURNFINDIR, EXIT);

                        //update state variable
                        currentState = DRIVETOCORNERQUICK;

                        //change to the state
                        changeState(DRIVETOCORNERQUICK, ENTER);

                        //break out of the while loop
                        
                        break;
                    }

//                    //check other state specific events
//                    else if(getEvent(&binLightDetected) && getEventInfo(&ballsFull))
//                    {
//
//                        //update state variable
//                        currentState = FACEBIN;
//
//                        //change to the state
//                        changeToState(FACEBIN);
//
//                        //break out of the while loop
//                        break;
//                    }

                }
                break;
  
                
                
                

            case FACEDISPENSER:

                while(1)
                { 
                    //state specific updaters
                    checkDispenserLightThresholdMet();
                    
                    if(getEvent(&dispenserLightThresholdMet))
                    {
                        //exit state
                        changeState(FACEDISPENSER, EXIT);
                        
                        //update state variable
                        currentState = DRIVETOCORNERQUICK;
                        
                        //change to the state
                        changeState(DRIVETOCORNERQUICK, ENTER);
                        
                        //break out of while loop
                        break;
                    }
                    
                    //check event status
//                    if(getEventStatus(DISPENSERLIGHTTHRESHOLDMET) == 1)
//                    {
//                        //update state variable
//                        currentState = DRIVETOCORNERQUICK;
//
//                        //change to the state
//                        changeToState(DRIVETOCORNERQUICK);
//
//                        //break out of the while loop
//                        break;
//                    }

                }
                break;
                
            case DRIVETOCORNERQUICK:

                while(1)
                { 
                    //state specific updaters
                    checkFrontButtonsPressed();

                    
                    //check event status
                    if(getEvent(&frontButtonsPressed))
                    {
                        //exit state
                        changeState(DRIVETOCORNERQUICK, EXIT);
                        
                        //update state variable
                        currentState = LOADBALLS;

                        //change to the state
                        changeState(LOADBALLS, ENTER);

                        //break out of the while loop
                        break;
                    }

                }
                break;

            case DRIVEINTOCORNER:

                while(1)
                { 
                    //state specific updaters
                    checkTwoSonicSensorThresholdMet();
                    
                    

                    /*
                    //check event status
                    else if(getEventStatus(TWOSONICSENSORTHRESHOLDMET) && !getEventStatus(BALLSFULL))
                    {
                        //update state variable
                        currentState = LOADBALLS;

                        //change to the state
                        changeToState(LOADBALLS);

                        //break out of the while loop
                        break;
                    }

                    //check other state specific events
                    else if(getEventStatus(TWOSONICSENSORTHRESHOLDMET) && getEventStatus(BALLSFULL))
                    {

                        //update state variable
                        currentState = BACKUPTOSHOOT;

                        //change to the state
                        changeToState(BACKUPTOSHOOT);

                        //break out of the while loop
                        break;
                    }
                */
                }
                break;


            case LOADBALLS:

                //exit state
                changeState(LOADBALLS, EXIT);
                        
                //update state variable
                currentState = DRIVETOMIDDLE;

                //change to the state
                changeState(DRIVETOMIDDLE, ENTER);
                
                break;
                

            case DRIVETOMIDDLE:

                while(1)
                {       
                    //state specific updaters

                    // check event status
                    if(getEventInfo(&motorPeriodCount) > DRIVETOMIDDLECOUNT)
                    {
                        //exit the state
                        changeState(DRIVETOMIDDLE, EXIT);

                        //update state variable
                        currentState = WAITFORBINLIGHT;

                        //change to the state
                        changeState(WAITFORBINLIGHT, ENTER);

                        //break out of the while loop
                        break;
                    }



                }
                break;
                
            case FACEFRONTBINLIGHT:

                while(1)
                {       
                    //state specific updaters
                    
                    changeState(FACEFRONTBINLIGHT, EXIT);
                    
                    currentState = SHOOTGOALS;
                    
                    changeState(SHOOTGOALS, ENTER);
                    
                    break;
                    
//                    // check event status
//                    if(getEventInfo(&motorPeriodCount) > DRIVETOMIDDLECOUNT)
//                    {
//                        //exit the state
//                        changeState(DRIVETOMIDDLE, EXIT);
//
//                        //update state variable
//                        currentState = WAITFORBINLIGHT;
//
//                        //change to the state
//                        changeState(WAITFORBINLIGHT, ENTER);
//
//                        //break out of the while loop
//                        break;
//                    }



                }
                break;
            
            case FACERIGHTBINLIGHT:

                while(1)
                {       
                    //state specific updaters

                    changeState(FACERIGHTBINLIGHT, EXIT);
                    
                    currentState = SHOOTGOALS;
                    
                    changeState(SHOOTGOALS, ENTER);
                    
                    break;
                    
//                    // check event status
//                    if(getEventInfo(&motorPeriodCount) > DRIVETOMIDDLECOUNT)
//                    {
//                        //exit the state
//                        changeState(DRIVETOMIDDLE, EXIT);
//
//                        //update state variable
//                        currentState = WAITFORBINLIGHT;
//
//                        //change to the state
//                        changeState(WAITFORBINLIGHT, ENTER);
//
//                        //break out of the while loop
//                        break;
//                    }



                }
                break;
                
            case FACELEFTBINLIGHT:

                while(1)
                {       
                    //state specific updaters

                    changeState(FACELEFTBINLIGHT, EXIT);
                    
                    currentState = SHOOTGOALS;
                    
                    changeState(SHOOTGOALS, ENTER);
                    
                    break;
                    
//                    // check event status
//                    if(getEventInfo(&motorPeriodCount) > DRIVETOMIDDLECOUNT)
//                    {
//                        //exit the state
//                        changeState(DRIVETOMIDDLE, EXIT);
//
//                        //update state variable
//                        currentState = WAITFORBINLIGHT;
//
//                        //change to the state
//                        changeState(WAITFORBINLIGHT, ENTER);
//
//                        //break out of the while loop
//                        break;
//                    }



                }
                break;
                
            case WAITFORBINLIGHT:

                while(1)
                { 
                    //state specific updaters
                    checkLeftBinLightDetected();
                    checkRightBinLightDetected();
                    checkFrontBinLightDetected();
                    
                    //check event status
                    if(getEventInfo(&leftBinLightDetected) == 1)
                    {
                        //exit the state
                        changeState(WAITFORBINLIGHT, EXIT);

                        //update state variable
                        currentState = FACELEFTBINLIGHT;

                        //change to the state
                        changeState(FACELEFTBINLIGHT, ENTER);

                        //break out of the while loop
                        break;
                    }
                    
                    else if(getEventInfo(&rightBinLightDetected) == 1)
                    {
                        //exit the state
                        changeState(WAITFORBINLIGHT, EXIT);

                        //update state variable
                        currentState = FACERIGHTBINLIGHT;

                        //change to the state
                        changeState(FACERIGHTBINLIGHT, ENTER);

                        //break out of the while loop
                        break;
                    }
                    
                    else if (getEventInfo(&frontBinLightDetected) == 1)
                    {
                        //exit the state
                        changeState(WAITFORBINLIGHT, EXIT);

                        //update state variable
                        currentState = FACEFRONTBINLIGHT;

                        //change to the state
                        changeState(FACEFRONTBINLIGHT, ENTER);

                        //break out of the while loop
                        break;
                    }



                }
                break;  

            case SHOOTGOALS:

                while(1)
                { 
                    //state specific updaters

                    
                    checkBinLightNotDetected();
                    
                    //check event status
                    if(!containsBalls())
                    {
                        //exit the state
                        changeState(SHOOTGOALS, EXIT);

                        //update state variable
                        currentState = DRIVETOCORNERQUICK;

                        //change to the state
                        changeState(DRIVETOCORNERQUICK, ENTER);

                        //break out of the while loop
                        break;
                    }
                    
                    else if(getEvent(&binLightNotDetected))
                    {
                        //exit the state
                        changeState(SHOOTGOALS, EXIT);
                        
                        //changeState(FACELEFTBINLIGHT, EXIT);
                        //update state variable
                        currentState = WAITFORBINLIGHT;

                        //change to the state
                        changeState(WAITFORBINLIGHT, ENTER);

                        //break out of the while loop
                        break;
                    }
                    
                    shoot();
                }
                break;


        }
    }
}

#endif	/* CASESWITCH_H */

