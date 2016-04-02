/* 
 * File:   calibrations.h
 * Author: Justin
 *
 * Created on March 26, 2016, 10:32 AM
 */


#include"handlers.h"
#include"turretFunctions.h"

#ifndef CALIBRATIONS_H
#define	CALIBRATIONS_H


void calibrate();
void calibrateDispenserThreshold();
void calibrateTurret();

void calibrate()
{
    rotateDisk(0);
    calibrateTurret();
    calibrateDispenserThreshold();
    calibrateIR();
    //read values
}

void calibrateDispenserThreshold()
{
    
}

void calibrateTurret()
{
    turnTurret(RIGHT);
    setLow(&turretButtonPressed);
    while(1)
    {
        if(_RA4 == 1)
        {
            setHigh(&turretButtonPressed);
        }
        
        if(turretButtonPressed)
        {
            break;
        }
    }
    toggleOffTurret();
}

#endif	/* CALIBRATIONS_H */

