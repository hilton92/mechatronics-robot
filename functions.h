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
void toggleOnTurret();
void toggleOffTurret();
void setTurretSpeed();

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

void rotateTurret(double degree, int direction)
{
    //toggleMotorsOff();
    
    // turn motors off
    toggleOffTurret();
    
    //set motor direction
//    setMotorDirection(LEFT,BACKWARD);
//    setMotorDirection(RIGHT,FORWARD); 
    
     //set motor speeds
//    setMotorSpeed(LEFT,MOTORLOWSPEED);
//    setMotorSpeed(RIGHT, MOTORLOWSPEED);  
  //  setBothMotorSpeeds(MOTORLOWSPEED);
    
    //turn on motors
//    toggleMotors(LEFT,ON);
//    toggleMotors(RIGHT,ON); 
   // toggleMotorsOn();
    
    //clearEventInfo(PERIODCOUNTRIGHT);
    setLow(&turretPeriodCount);
    //PR4 = MOTORLOWSPEED;
    

    
	//rotate left
	if(direction == LEFT )
	{
        _LATB9 = 1;
	}

	//rotate right
	else
	{
        _LATB9 = 0;
	}
    
      
     //convert degree to counts   
    int count = (int) (degree  / 0.05625);
    
    // set the speed
    setTurretSpeed(TURRETSPEED);   
    
    // toggle motors on
    toggleOnTurret();
    
    while(turretPeriodCount < count)
    {          
    }   
    
    // toggle motors off
    toggleOffTurret();
    
}

void toggleOnTurret()
{
    OC3R = 100;
}

void toggleOffTurret()
{
    OC3R = 0;
}

void setTurretSpeed(unsigned int speed)
{
    PR3 = speed;
}

#endif	/* FUNCTIONS_H */

