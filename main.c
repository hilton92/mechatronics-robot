
#include<p24F16KA301.h>
//#include<xc.h>

#include"constants.h"
#include"handlers.h"
#include"configurations.h"
#include"eventUpdaters.h"
#include"stateChangers.h"
#include"motorFunctions.h"
#include"interrupt.h"
#include"functions.h"

//-----------------------------------------------------
// Function STUBS
void mainConfig();
void caseSwitch();
int mainTest();




//-----------------------------------------------------
// Configurations
// Select oscillator

_FOSCSEL(FNOSC_FRC);// & SOSCSRC_DIG);

_FICD(ICS_PGx3);

//_FOSC(OSCIOFNC_OFF);



//-----------------------------------------------------
// Main Function

//global events-  0 or 1 --------------------
int dispenserLightDetected = 0;
int dispenserLightThresholdMet = 0;
int binLightDetected = 0;
int binLightNotDetected = 0;
int binLightThresholdMet = 0;
int oneSonicSensorThresholdMet = 0;
int twoSonicSensorThresholdMet = 0;
int timer1Met = 0;
int buttonPressed = 0;
int leftBinLightDetected = 0;
int rightBinLightDetected = 0;
int frontBinLightDetected = 0;


//global no cyclic clearing variables
int ballsFull = 0;
int timer5Met = 0;

//global state info variables----------------
int motorPeriodCount = 0;
int turretPeriodCount = 0;
int shootTime = 0;


int main()
{
    int testing = 1;
    
    if(testing)
    {
//        mainConfig();
//        mainTest();
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
    configureAD();
    configureIOPins();   
    configureTimers();
    configureTimerInterrupts();
    setToNullState();
}





/////////////////////////---------------------------------------Tests



void driveToCornerQuickTest();
void testIRSensors();

int mainTest()
{
    
    //testIRSensors();
//    driveToCornerQuickTest();
//        
//    delayMS(2000);
// 
//    setToNullState();  
//    rotateXDegrees(180);
//    setToNullState();
//    driveToCornerQuickTest();
//    
//
//    delayMS(2000);

    rotateTurret(90, LEFT);
    setToNullState();

    return 0;
}


void testIRSensors()
{
   
    while(ADC1BUF11 < 2000)
    {
        rotateXDegrees(2);
        delayMS(300);
    }
}
    
void driveToCornerQuickTest()
{
   
    //set motor direction
    setMotorDirection(LEFT,FORWARD);
    setMotorDirection(RIGHT,FORWARD); 
    
     //set motor speed
    setBothMotorSpeeds(MOTORHIGHSPEED);

    
    //turn on motors
//    toggleMotors(LEFT,ON);
//    toggleMotors(RIGHT,ON);  
    toggleMotorsOn();

}


   
