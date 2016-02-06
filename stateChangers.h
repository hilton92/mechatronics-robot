/* 
 * File:   stateChangers.h
 * Author: Justin
 *
 * Created on February 6, 2016, 2:03 PM
 */
#include"events.h"

#ifndef STATECHANGERS_H
#define	STATECHANGERS_H

void changeToState(unsigned char state)
{
    //reset the events
    clearEvents();
    
    switch (state)
    {
        case BUTTONPRESSED:
            //reset timers
            //set or unset certain variables(i.e. ballsLoaded)
            
            //enter the state
            
            break;
            
    }
}

#endif	/* STATECHANGERS_H */

