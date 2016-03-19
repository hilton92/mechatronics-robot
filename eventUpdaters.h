/* 
 * File:   eventUpdaters.h
 * Author: Justin
 *
 * Created on February 15, 2016, 12:05 PM
 */


//IMPORTANT NOTE
//---------on off button and timer 1 are the only interrupts!!
//Must close the ball drop pin when entering other states

#include "constants.h"

#ifndef EVENTUPDATERS_H
#define	EVENTUPDATERS_H

//function stubs ------------------------------
void checkDispenserLightDetected();
void checkDispenserLightThresholdMet();
void checkBinLightDetected();
void checkBinLightNotDetected();
void checkBinLightThresholdMet();
void checkOneSonicSensorThresholdMet();
void checkTwoSonicSensorThresholdMet();
void checkButtonPressed();
void checkLeftBinLightDetected();
void checkRightBinLightDetected();
void checkFrontBinLightDetected();

//----------------------------------------------

void checkDispenserLightDetected()
{
    
}

void checkDispenserLightThresholdMet()
{
    
}

void checkBinLightDetected()
{
    
}

void checkBinLightNotDetected()
{
    
}

void checkBinLightThresholdMet()
{
    
}

void checkOneSonicSensorThresholdMet()
{
    
}

void checkTwoSonicSensorThresholdMet()
{
    
}

void checkButtonPressed()
{
    
}

void checkFrontBinLightDetected()
{
    if(readAD(16) > IRBINTHRESHOLD)
    {
        setHigh(&frontBinLightDetected&);
    }
}

void checkRightBinLightDetected()
{
    if(readAD(17) > IRBINTHRESHOLD)
    {
        setHigh(&rightBinLightDetected&);
    }
}

void checkLeftBinLightDetected()
{
    if(readAD(18) > IRBINTHRESHOLD)
    {
        setHigh(&leftBinLightDetected&);
    }
}






#endif	/* EVENTUPDATERS_H */

