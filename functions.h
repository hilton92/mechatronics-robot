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

void rotateTurret(int degree)
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
    setLow(&periodCount);
    //PR4 = MOTORLOWSPEED;
    
    //convert degree to counts
    int count = QUARTERTURNCOUNT/90.0 * degree;
    
    while(motorPeriodCount < count)
    {          
    }
    
	//rotate left
	if(degree < 0)
	{

	}

	//rotate right
	else
	{

	}
}

#endif	/* FUNCTIONS_H */

