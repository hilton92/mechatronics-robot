/* 
 * File:   motorFunctions.h
 * Author: Justin
 *
 * Created on February 27, 2016, 10:00 AM
 */

#include<p24F16KA301.h>

#ifndef MOTORFUNCTIONS_H
#define	MOTORFUNCTIONS_H

void toggleMotors(unsigned char, int);
void setMotorDirection(unsigned char, int);
void setMotorSpeed(unsigned char, int);

void setMotorSpeed(unsigned char motor, int speed)
{
    switch(motor)
    {
        case LEFT:
            PR2 = speed;
            break;
                
        case RIGHT:
            PR3 = speed;
            break;
    }                    
                    
}

void setMotorDirection(unsigned char motor, int direction)
{
    switch(motor)
    {
        case LEFT:
            _LATA0 = direction;
            break;
                
        case RIGHT:
            _LATA1 = direction;
            break;
    }                    
                    
}

void toggleMotors(unsigned char motor, int onoff)
{
    switch(motor)
    {
        case LEFT:
            if(onoff == 1)
                OC2R = 300;
            else
                OC2R = 0;
            break;
                
        case RIGHT:
            if(onoff == 1)
                OC3R = 300;
            else
                OC3R = 0;
            break;
    }                    
                    
}

void toggleMotorsOn()
{
    OC2R = 300;
}

#endif	/* MOTORFUNCTIONS_H */

