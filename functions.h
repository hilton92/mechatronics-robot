/* 
 * File:   functions.h
 * Author: Justin
 *
 * Created on February 23, 2016, 10:17 PM
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

void toggleMotors(unsigned char, int);
void setMotorDirection(unsigned char, int);


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
                OC2R = 10;
            else
                OC2R = 0;
            break;
                
        case RIGHT:
            if(onoff == 1)
                OC3R = 10;
            else
                OC3R = 0;
            break;
    }                    
                    
}

#endif	/* FUNCTIONS_H */

