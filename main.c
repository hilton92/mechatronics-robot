
#include<p24F16KA301.h>
#include<xc.h>

#include"constants.h"
#include"handlers.h"
#include"configurations.h"
#include"eventUpdaters.h"
#include"stateChangers.h"
#include"motorFunctions.h"

//-----------------------------------------------------
// Function STUBS
void mainConfig();
void caseSwitch();



//-----------------------------------------------------
// Configurations
// Select oscillator
_FOSCSEL(FNOSC_FRC);

_FICD(ICS_PGx3);



//-----------------------------------------------------
// Main Function


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
    
    int i = 0;
    while(i < 5)
    {
        i = i + 1;
    }
 
    setToNullState();  
    rotate90();
 //   setToNullState();
//    driveToCornerQuickTest();
//    
//    i = 0;
//    while(i < 10000)
//    {
//        i++;
//    }
//
//    setToNullState();

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
    toggleMotors(LEFT,ON);
    toggleMotors(RIGHT,ON);  

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
    toggleMotors(LEFT,ON);
    toggleMotors(RIGHT,ON); 
    
    clearEventInfo(PERIODCOUNTRIGHT);
    PR4 = MOTORLOWSPEED;
        while(requestEventInfo(PERIODCOUNTRIGHT) < 492)
        {            
        }
    
    int i = 8;
}