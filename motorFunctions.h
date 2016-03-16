/* 
 * File:   motorFunctions.h
 * Author: Justin
 *
 * Created on February 27, 2016, 10:00 AM
 */

#include<p24F16KA301.h>

#ifndef MOTORFUNCTIONS_H
#define	MOTORFUNCTIONS_H

//void toggleMotors(unsigned char, int);
void setMotorDirection(unsigned char, int);
//void setMotorSpeed(unsigned char, int);
void toggleMotorsOn();
void toggleMotorsOff();
void setBothMotorSpeeds(int);
void rotateXDegrees(int);
void driveStraight(int speed, int direction);

//used only with separate OC signals
//void setMotorSpeed(unsigned char motor, int speed)
//{
//    switch(motor)
//    {
//        case LEFT:
//            PR2 = speed;
//            break;
//                
//        case RIGHT:
//            PR3 = speed;
//            break;
//    }                    
//                    
//}

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

// used only for separate OC signals
//void toggleMotors(unsigned char motor, int onoff)
//{
//    switch(motor)
//    {
//        case LEFT:
//            if(onoff == 1)
//                OC2R = 300;
//            else
//                OC2R = 0;
//            break;
//                
//        case RIGHT:
//            if(onoff == 1)
//                OC3R = 300;
//            else
//                OC3R = 0;
//            break;
//    }                    
//                    
//}

void toggleMotorsOn()
{
    OC2R = 300;
}

void toggleMotorsOff()
{
    OC2R = 0;
}

void setBothMotorSpeeds(int speed)
{
    PR2 = speed;
}

void rotateXDegrees(int degree)
{
    toggleMotorsOff();
    
    //set motor direction
    setMotorDirection(LEFT,BACKWARD);
    setMotorDirection(RIGHT,FORWARD); 
    
     //set motor speeds
//    setMotorSpeed(LEFT,MOTORLOWSPEED);
//    setMotorSpeed(RIGHT, MOTORLOWSPEED);  
    setBothMotorSpeeds(MOTORLOWSPEED);
    
    //turn on motors
//    toggleMotors(LEFT,ON);
//    toggleMotors(RIGHT,ON); 
    toggleMotorsOn();
    
    //clearEventInfo(PERIODCOUNTRIGHT);
    setLow(&motorPeriodCount);
    //PR4 = MOTORLOWSPEED;
    
    //convert degree to counts
    int count = QUARTERTURNCOUNT/90.0 * degree;
    
    while(motorPeriodCount < count)
    {          
    }
    
}

void driveStraight(int speed, int direction)
{
    //set motor direction
    setMotorDirection(LEFT,direction);
    setMotorDirection(RIGHT,direction); 
    
     //set motor speed
    setBothMotorSpeeds(speed);
    
    //turn on motors
    toggleMotorsOn();
}

#endif	/* MOTORFUNCTIONS_H */

