/* 
 * File:   caseSwitch.h
 * Author: Justin
 *
 * Created on February 27, 2016, 10:12 AM
 */
#include "stateChangers.h"
#include "eventUpdaters.h"


#ifndef CASESWITCH_H
#define	CASESWITCH_H

//function prototypes
void caseSwitch();

//-----------------


void caseSwitch()
{
    //initialize state variable and state
    static unsigned char currentState = DRIVETOMIDDLE;
    
    //initialize state
    //changeToState(WAITFORBUTTON);
    
    while(1)
    {

        switch (currentState)
        {

            case TURNFINDIR:

                while(1)
                { 
                    //state specific updaters
                    checkDispenserLightDetected();
                    checkBinLightDetected();                   
                    
                    //check event status
                    if(getEvent(&dispenserLightDetected) && !getEventInfo(&ballsFull) )
                    {
                        //update state variable
                        currentState = FACEDISPENSER;

                        //change to the state
                        changeToState(FACEDISPENSER);

                        //break out of the while loop
                        break;
                    }

                    //check other state specific events
                    else if(getEvent() && getEventStatus(BALLSFULL))
                    {

                        //update state variable
                        currentState = FACEBIN;

                        //change to the state
                        changeToState(FACEBIN);

                        //break out of the while loop
                        break;
                    }

                }
                break;
  
                
                
                

            case FACEDISPENSER:

                while(1)
                { 
                    //state specific updaters
                    checkDispenserLightThresholdMet();
                    checkButtonPressed();
                    
                    if(getEventStatus(BUTTONPRESSED))
                    {
                        //update state variable
                        currentState = WAITFORBUTTON;
                        
                        //change to the state
                        changeToState(WAITFORBUTTON);
                        
                        //break out of while loop
                        break;
                    }
                    
                    //check event status
                    else if(getEventStatus(DISPENSERLIGHTTHRESHOLDMET) == 1)
                    {
                        //update state variable
                        currentState = DRIVETOCORNERQUICK;

                        //change to the state
                        changeToState(DRIVETOCORNERQUICK);

                        //break out of the while loop
                        break;
                    }

                }
                break;
                
            case DRIVETOCORNERQUICK:

                while(1)
                { 
                    //state specific updaters
                    checkOneSonicSensorThresholdMet();
                    checkButtonPressed();
                    
                    if(getEventStatus(BUTTONPRESSED))
                    {
                        //update state variable
                        currentState = WAITFORBUTTON;
                        
                        //change to the state
                        changeToState(WAITFORBUTTON);
                        
                        //break out of while loop
                        break;
                    }
                    
                    //check event status
                    else if(getEventStatus(ONESONICSENSORTHRESHOLDMET))
                    {
                        //update state variable
                        currentState = DRIVEINTOCORNER;

                        //change to the state
                        changeToState(DRIVEINTOCORNER);

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
                    checkButtonPressed();
                    
                    if(getEventStatus(BUTTONPRESSED))
                    {
                        //update state variable
                        currentState = WAITFORBUTTON;
                        
                        //change to the state
                        changeToState(WAITFORBUTTON);
                        
                        //break out of while loop
                        break;
                    }
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

                while(1)
                { 
                    checkButtonPressed();
                    
                    if(getEventStatus(BUTTONPRESSED))
                    {
                        //update state variable
                        currentState = WAITFORBUTTON;
                        
                        //change to the state
                        changeToState(WAITFORBUTTON);
                        
                        //break out of while loop
                        break;
                    }
                    
                    //check event status
                    else if(getEventStatus(TIMER1MET) )
                    {
                        //update state variable
                        currentState = DRIVETOMIDDLE;

                        //change to the state
                        changeToState(DRIVETOMIDDLE);

                        //break out of the while loop
                        break;
                    }



                }
                break;

            case DRIVETOMIDDLE:

                while(1)
                { 
                    checkButtonPressed();
                    
                    if(getEventStatus(BUTTONPRESSED))
                    {
                        //update state variable
                        currentState = WAITFORBUTTON;
                        
                        //change to the state
                        changeToState(WAITFORBUTTON);
                        
                        //break out of while loop
                        break;
                    }
                    
                    //check event status
                    else if(getEventStatus(TIMER1MET))
                    {
                        //update state variable
                        currentState = TURNFINDIR;

                        //change to the state
                        changeToState(TURNFINDIR);

                        //break out of the while loop
                        break;
                    }



                }
                break;
                
            case WAITFORBINLIGHT:

                while(1)
                { 
                    //state specific updaters
                    checkLeftIRThresholdMet();
                    checkButtonPressed();
                    
                    if(getEventStatus(BUTTONPRESSED))
                    {
                        //update state variable
                        currentState = WAITFORBUTTON;
                        
                        //change to the state
                        changeToState(WAITFORBUTTON);
                        
                        //break out of while loop
                        break;
                    }
                    
                    //check event status
                    else if(getEventStatus(BINLIGHTTHRESHOLDMET) == 1)
                    {
                        //update state variable
                        currentState = DRIVETOCORNERQUICK;

                        //change to the state
                        changeToState(DRIVETOCORNERQUICK);

                        //break out of the while loop
                        break;
                    }



                }
                break;  

            case BACKUPTOSHOOT:

                while(1)
                { 
                    //state specific updaters
                    checkButtonPressed();
                    checkButtonPressed();
                    
                    if(getEventStatus(BUTTONPRESSED))
                    {
                        //update state variable
                        currentState = WAITFORBUTTON;
                        
                        //change to the state
                        changeToState(WAITFORBUTTON);
                        
                        //break out of while loop
                        break;
                    }
                    
                    //check event status
                    else if(getEventStatus(BUTTONPRESSED) == 1)
                    {
                        //update state variable
                        currentState = TURNFINDIR;

                        //change to the state
                        changeToState(TURNFINDIR);

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
                    checkButtonPressed();
                    
                    if(getEventStatus(BUTTONPRESSED))
                    {
                        //update state variable
                        currentState = WAITFORBUTTON;
                        
                        //change to the state
                        changeToState(WAITFORBUTTON);
                        
                        //break out of while loop
                        break;
                    }
                    
                    //check event status
                    else if(getEventStatus(BINLIGHTNOTDETECTED) || !getEventStatus(BALLSFULL))
                    {
                        //update state variable
                        currentState = DRIVETOMIDDLE;

                        //change to the state
                        changeToState(DRIVETOMIDDLE);

                        //break out of the while loop
                        break;
                    }
                }
                break;


        }
    }*/
}

#endif	/* CASESWITCH_H */
