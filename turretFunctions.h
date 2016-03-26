/* 
 * File:   turretFunctions.h
 * Author: Justin
 *
 * Created on March 19, 2016, 8:09 AM
 */

#ifndef TURRETFUNCTIONS_H
#define	TURRETFUNCTIONS_H

void toggleOnTurret();
void toggleOffTurret();
void setTurretSpeed();

void rotateTurret(double degree, int direction)
{    
    // turn motors off
    toggleOffTurret();
    
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

void turnTurret(int direction)
{
    // turn motors off
    toggleOffTurret();
    
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
    
    // set the speed
    setTurretSpeed(TURRETSPEED);   
    
    // toggle motors on
    toggleOnTurret();
}

#endif	/* TURRETFUNCTIONS_H */

