
#include<p24F16KA301.h>

//#include"enums.h"
//#include"handlers.h"
//#include"configurations.h"
//#include"eventUpdaters.h"
//#include"stateChangers.h"




void driveToCornerQuickTest();

int mainTest()
{
    
    driveToCornerQuickTest();
    return 0;
}

void driveToCornerQuickTest()
{
       // Configure A/D
//    configureAD();
//    chooseADpin(6);
//    chooseADpin(7);
//    chooseADpin(8);
    
    // Configure PWM pins
    //configurePWM(1,3,12500);
    configurePWM(2,3,12500); //right motor
    configurePWM(3,3,12500); //left motor
    
    _TRISA0 = 0; //pin 2 two right motor direction
    _TRISA1 = 0; //pin 3 left motor direction
    
    ANSA = 0;
    ANSB = 0;
    
    _LATA0 = 1;
    _LATA1 = 1;
    
    
    T3CONbits.TON = 1; //Turn on timer 3
    T3CONbits.TCKPS = 0b01; //1:8 ratio for timer 3
    T3CONbits.TCS = 0;  //set timer 3 to internal clock
    OC2R =  6250;
    OC3R =  6250;    

}
