
#include<p24F16KA301.h>
//#include<xc.h>

#include"constants.h"
//#include"handlers.h"
#include"configurations.h"
#include"eventUpdaters.h"
#include"stateChangers.h"
#include"motorFunctions.h"
#include"interrupt.h"
#include"functions.h"
#include"caseSwitch.h"
#include"calibrations.h"
#include"quadratic.h"

//-----------------------------------------------------
// Function STUBS
void mainConfig();
void caseSwitch();
int mainTest();




//-----------------------------------------------------
// Configurations
// Select oscillator

_FOSCSEL(FNOSC_FRC & SOSCSRC_DIG);

_FICD(ICS_PGx1);

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
int rightButtonPressed = 0;
int leftButtonPressed = 0;
int turretButtonPressed = 0;


//global no cyclic clearing variables
int timer5Met = 0;

//global state info variables----------------
int motorPeriodCount = 0;
int turretPeriodCount = 0;
int shootTime = 0;
int currentBin = 0;

//other globals
int ballCount = 0;
float IRthreshold = 0;
//float MAXIRThreshold = 0;
float IRValArray[4];
float dispenserThreshold;
int firstTime;

int main()
{
    int testing = 0;
    
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
    configureAD();
    configureIOPins();   
    configureTimers();
    configureTimerInterrupts();
    setToNullState();
    calibrate();    
}





/////////////////////////---------------------------------------Tests



void driveToCornerQuickTest();
void testIRSensors();
void testULTRASONIC();

int mainTest()
{
    
//    rotateTurret(150, LEFT);
    findDispenser();
    while(1)
    {
//    checkFrontBinLightDetected();
//    checkRightBinLightDetected();
//    checkLeftBinLightDetected();
//    
//    if(frontBinLightDetected)
//    {
//        rotateTurret(45, RIGHT);
//        rotateTurret(45, LEFT);
//    }
//    
//    if(rightBinLightDetected)
//    {
//        rotateTurret(15, RIGHT);
//    }
//    
//    if(leftBinLightDetected)
//    {
//        rotateTurret(15, LEFT);
//    }
    
//    checkDispenserLightDetected();
//    if(dispenserLightDetected)
//    {
//        rotateTurret(15, RIGHT);
//        rotateTurret(15,LEFT);
//    }
//    
//    
//    
//    clearEvents();
    //OC1R = 1000;
    //rotateDisk(180);
    //testULTRASONIC();
    //triggerLaser();
    //turn(MOTORLOWSPEED, LEFT);
        
    
}
    return 0;
}

void testULTRASONIC(){
    int microseconds = 0;
    //RB2 Ultrasonic 1 (in - echo) pin 6
    //RA2 Ultrasonic 1 (out - trig) pin 7
    //RA3 ULtrasonic 2 (in - echo) pin 8
    //RB4 Ultrasonic 2 (out - trig) pin 9
    while (1){
    _LATA2 = 1;
    delay10Microseconds();
    _LATA2 = 0;
    microseconds = pulseIn(6);
    if (microseconds == 0){
        //threshold met
    }
    else{
        _LATA4 = 0;
    }
    delayMS(100);
    }
    
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


   
