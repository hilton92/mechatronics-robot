
#include<p24F16KA301.h>
#include<xc.h>

#include"constants.h"
#include"handlers.h"
#include"configurations.h"
#include"eventUpdaters.h"
#include"stateChangers.h"
#include"motorFunctions.h"
#include"interrupt.h"

//-----------------------------------------------------
// Function STUBS
void mainConfig();
void caseSwitch();
int mainTest();



//-----------------------------------------------------
// Configurations
// Select oscillator
_FOSCSEL(FNOSC_FRC);

_FICD(ICS_PGx3);



//-----------------------------------------------------
// Main Function

int dispenserLightDetected = 0;
int dispenserLightThresholdMet = 0;
int binLightDetected = 0;
int binLightNotDetected = 0;
int binLightThresholdMet = 0;
int oneSonicSensorThresholdMet = 0;
int twoSonicSensorThresholdMet = 0;
int timer1Met = 0;
int buttonPressed = 0;
int ballsFull = 0;

int periodCountLeft = 0;
int periodCountRight = 0;
int shootTime = 0;

int main()
{
    int testing = 1;
    
    if(testing)
    {
        mainConfig();
        mainTest();
        while(1);
    }
    
    else
    {
        //configurations
        mainConfig();

        //infinite loop through the cases
        caseSwitch();
    }
 
    return 0;
}

//call the needed initialization configurations
void mainConfig()
{
    configureEvents();
    configureIOPins();
    configureTimers();
    configureTimerInterrupts();
}





/////////////////////////Tests



void driveToCornerQuickTest();
void rotate90();

int mainTest()
{
    
    
    driveToCornerQuickTest();
    
    unsigned int i = 0;
    unsigned int k = 0;
    while(i < 60000)
    {
        i++;
        while(k < 5)
        {
            k++;
        }
        k = 0;
    }
 
    setToNullState();  
    rotate90();
    setToNullState();
    driveToCornerQuickTest();
    
    i = 0;
    k = 0;
    while(i < 60000)
    {
        i++;
        while(k < 5)
        {
            k++;
        }
        k = 0;
    }

    setToNullState();

    return 0;
}

void driveToCornerQuickTest()
{
   
    //set motor direction
    setMotorDirection(LEFT,FORWARD);
    setMotorDirection(RIGHT,FORWARD); 
    
     //set motor speed
    setMotorSpeed(LEFT,MOTORHIGHSPEED);
    setMotorSpeed(RIGHT, MOTORHIGHSPEED);  
    
    //turn on motors
//    toggleMotors(LEFT,ON);
//    toggleMotors(RIGHT,ON);  
    toggleMotorsOn();

}
   
void rotate90()
{
    //set motor direction
    setMotorDirection(LEFT,BACKWARD);
    setMotorDirection(RIGHT,FORWARD); 
    
     //set motor speed
    setMotorSpeed(LEFT,MOTORLOWSPEED);
    setMotorSpeed(RIGHT, MOTORLOWSPEED);  
    
    //turn on motors
//    toggleMotors(LEFT,ON);
//    toggleMotors(RIGHT,ON); 
    toggleMotorsOn();
    
    //clearEventInfo(PERIODCOUNTRIGHT);
    periodCountRight = 0;
    PR4 = MOTORLOWSPEED;
    while(periodCountRight < 492)
    {            
    }
    
    int i = 8;
}