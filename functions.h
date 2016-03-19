/* 
 * File:   functions.h
 * Author: Justin
 *
 * Created on February 23, 2016, 10:17 PM
 */

#include"handlers.h"

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H


//function prototypes
void delayMS(int);


void delayMS(int miliseconds) //max of 4 seconds!!!
{
    
    _T5IF = 0;    
    PR5 = 1/.064 * miliseconds;
    TMR5 = 0;
    setLow(&timer5Met);
    while(!timer5Met)
    {        
    }
    setLow(&timer5Met);
}



#endif	/* FUNCTIONS_H */

