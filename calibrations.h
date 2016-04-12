/* 
 * File:   calibrations.h
 * Author: Justin
 *
 * Created on March 26, 2016, 10:32 AM
 */


#include"handlers.h"
#include"turretFunctions.h"
#include"functions.h"

#ifndef CALIBRATIONS_H
#define	CALIBRATIONS_H


void calibrate();
void calibrateDispenserThreshold();
void calibrateTurret();
void calibrateIR(unsigned char);

void calibrate()
{
    rotateDisk(TRIGGERDEGREE2);
    calibrateTurret();
    calibrateDispenserThreshold();
    calibrateIR(BIN);
    calibrateIR(DISPENSER);
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

//configure the IR sensors
void calibrateIR(unsigned char irChoice){
    float maxIRThreshold;
    updateIRArray();
    //find the average of the lower 3 readings
    int i = 0; 
    while (i < 4)
    {
        int j = i + 1;
        while (j < 4)
        {
            if (IRValArray[i] > IRValArray[j])
            {
                float a =  IRValArray[i];
                IRValArray[i] = IRValArray[j];
                IRValArray[j] = a;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    float t = IRValArray[0] + IRValArray[1] + IRValArray[2];
    
    if(irChoice == DISPENSER)
    {
        //calculate delta
        maxIRThreshold = IRValArray[3];//save the max voltage
        float difference = maxIRThreshold - (t / 3.0);
        float delta = 5.0/6.0 * difference;        
        dispenserThreshold = (t / 3.0) + DISPENSERIRDELTA;   
    }
    else if(irChoice == BIN)
    {
        maxIRThreshold = IRValArray[3];//save the max voltage
        float difference = maxIRThreshold - (t / 3.0);
        float delta = 5.0/6.0 * difference;        
        IRthreshold = (t / 3.0) + BINIRDELTA; 
    }

 
    //t is the value to calibrate to
}

#endif	/* CALIBRATIONS_H */

