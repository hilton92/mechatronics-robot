
#include<p24F16KA301.h>

#include"enums.h"
#include"events.h"
#include"configurations.h"
#include"eventCheckers.h"
#include"stateChangers.h"

//-----------------------------------------------------
// Function STUBS
void mainConfig();


//-----------------------------------------------------
// Configurations
// Select oscillator
_FOSCSEL(FNOSC_LPRC);



//-----------------------------------------------------
// Main Function


int main()
{
    //state variables
    unsigned char currentState = WAITFORBUTTON;
    
    while(1)
    {
        switch (currentState)
        {
            case WAITFORBUTTON:
               
                while(1)
                { 
                    //state specific updaters
                    checkButtonPressed();
                    
                    //check event status
                    if(getEventStatus(BUTTONPRESSED) == 1)
                    {
                        //update state variable
                        currentState = TURNFINDDISPENSER;
                        
                        //change to the state
                        changeToState(TURNFINDDISPENSER);
                        
                        //break out of the while loop
                        break;
                    }
                    
                    //check other state specific events
                    else if(1)
                    {
                        
                    }
                  
                }
                break;
                
        }
    }

    return 0;
}

//call the needed initialization configurations
void mainConfig()
{
    configureEvents();
}