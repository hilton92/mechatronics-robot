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
float readAD(int);
void rotateDisk(float);
void triggerLaser();
void delayMicroseconds(float);
int pulseIn(int);
void shoot();
void toogleShooter(int);
void updateIRArray();
int isMaxIR(int);
void toggleSolenoid(unsigned char);



int pulseIn(int pin){
    //this function will return in microseconds the length of a pulse
    //only for ULTRASONIC pins!!
    int counts = 0;
    int microseconds = 0;
    switch (pin){
        case 6:
            //RB2
  
            while (!_RB2){
            }
            TMR1 = 0;
            while (_RB2){}
            TMR1 = counts;
            microseconds = counts * 4;
            break;
        case 7:
            //RA2
            while (!_RA2){
            }
            TMR1 = 0;
            while (_RA2){}
            TMR1 = counts;
            microseconds = counts * 4;
            break;
        case 8:
            //RA3
            while (!_RA3){
            }
            TMR1 = 0;
            while (_RA3){}
            TMR1 = counts;
            microseconds = counts * 4;
            break;
        case 9:
            //RB4
            while (!_RB4){
            }
            TMR1 = 0;
            while (_RB4){}
            TMR1 = counts;
            microseconds = counts * 4;
            break;
    }
    return microseconds;
}

void delay10Microseconds(){
    _T1IF = 0;    
    PR1 = 40;
    TMR1 = 0;
    setLow(&timer1Met);
    while(!timer1Met)
    {        
    }
    setLow(&timer1Met);
}

void updateIRArray(){
    float sum = 0;
    int count = 0;
    while (count < 70) {
        sum = sum + readAD(15);
        count = count + 1;
    }
    IRValArray[0] = sum / 70.0;
    sum = 0;
    count = 0;
    while (count < 70) {
        sum = sum + readAD(16);
        count = count + 1;
    }
    IRValArray[1] = sum / 70.0;
    sum = 0;
    count = 0;
    while (count < 70) {
        sum = sum + readAD(17);
        count = count + 1;
    }
    IRValArray[2] = sum / 70.0;
    sum = 0;
    count = 0;
    while (count < 70) {
        sum = sum + readAD(18);
        count = count + 1;
    }
    IRValArray[3] = sum / 70.0;
}

void delayMS(int milliseconds) //max of 4 seconds!!!
{
    _T5IF = 0;    
    PR5 = 1/.064 * milliseconds;
    TMR5 = 0;
    setLow(&timer5Met);
    while(!timer5Met)
    {        
    }
    setLow(&timer5Met);
}

float readAD(int pin)
{
    float voltage;
    switch(pin)
    {
            case 2: //AN0 pin 2
              voltage = (float)ADC1BUF0 / 4095 * 3.3;
               break;
            case 3: //AN1 pin 3
               voltage = (float)ADC1BUF1 / 4095 * 3.3; 
               break;
            case 4: //AN2 pin 4   
               voltage = (float)ADC1BUF2 / 4095 * 3.3;
               break;
            case 5: //AN3 pin 5     
               voltage = (float)ADC1BUF3 / 4095 * 3.3;
               break;
            case 6: //AN4 pin 6    
               voltage = (float)ADC1BUF4 / 4095 * 3.3;
               break;
            case 18: //AN9 pin 18    
               voltage = (float)ADC1BUF9 / 4095 * 3.3;
               break;
            case 17:  //AN10 pin 17    
               voltage = (float)ADC1BUF10 / 4095 * 3.3;
               break;
            case 16:  //AN11 pin 16 
               voltage = (float)ADC1BUF11 / 4095 * 3.3;
               break;
            case 15: //AN12 pin 15 
               voltage = (float)ADC1BUF12 / 4095 * 3.3;
               break;
            case 7: //AN13 pin 7           
               voltage = (float)ADC1BUF13 / 4095 * 3.3;
               break;
            case 8: //AN14 pin 8   
               voltage = (float)ADC1BUF14 / 4095 * 3.3;
               break;
            case 9: //AN15 pin 9   
               voltage = (float)ADC1BUF15 / 4095 * 3.3;
               break;
    }
    return voltage;
}

void rotateDisk(float degree) // 0 to 180
{
    OC1R =  (int) (250 + degree / 180.0 * 950);
}

void triggerLaser()
{
    rotateDisk(TRIGGERDEGREE);
    delayMS(TRIGGERDELAY);
    rotateDisk(0);
    delayMS(TRIGGERDELAY);
    
    rotateDisk(TRIGGERDEGREE);
    delayMS(TRIGGERDELAY);
    rotateDisk(0);
    delayMS(TRIGGERDELAY);
    
    rotateDisk(TRIGGERDEGREE);
    delayMS(TRIGGERDELAY);
    rotateDisk(0);
    delayMS(TRIGGERDELAY);
    
    rotateDisk(TRIGGERDEGREE);
    delayMS(TRIGGERDELAY);
    rotateDisk(0);
    delayMS(TRIGGERDELAY);
    
    rotateDisk(TRIGGERDEGREE);
    delayMS(TRIGGERDELAY);
    rotateDisk(0);
    delayMS(TRIGGERDELAY);
    
//    rotateDisk(TRIGGERDEGREE);
//    delayMS(TRIGGERDELAY);
//    rotateDisk(0);
//    delayMS(TRIGGERDELAY);
//    
//    rotateDisk(TRIGGERDEGREE);
//    delayMS(TRIGGERDELAY);
//    rotateDisk(0);
//    delayMS(TRIGGERDELAY);
//    rotateDisk(0);
//    delayMS(500);
    
}

void getAverageIR()
{
    
}
void shoot()
{
    toggleSolenoid(ON);
    delayMS(SOLENOIDDELAY);
    toggleSolenoid(OFF);
    decrementByOne(&ballCount);
    delayMS(1000);
    
}

void toggleShooter(int onoff)
{
    switch(onoff)
    {
        case ON:
            _LATB4 = 1;
            break;
        case OFF:
            _LATB4 = 0;
                
    }
     
}

int isMaxIR(int IRPIN){
    int returnBool = 1;
    float anV = 0;
    switch(IRPIN){
        case LEFTIR:
            anV = readAD(18);
            if (anV < readAD(17) || anV < readAD(15) /*|| anV < readAD(16)*/){
                returnBool = 0;
            }
            else{
                returnBool = 1;
            }
            break;
        case RIGHTIR:
            anV = readAD(17);
            if (anV < readAD(18) || anV < readAD(15)/* || anV < readAD(16)*/){
                returnBool = 0;
            }
            else{
                returnBool = 1;
            }
            break;
        case FRONTIR:
            anV = readAD(15);
            if (anV < readAD(17) || anV < readAD(18)/* || anV < readAD(16)*/){
                returnBool = 0;
            }
            else{
                returnBool = 1;
            }
            break;
        case REARIR:
            anV = readAD(16);
            if (anV < readAD(17) || anV < readAD(15) || anV < readAD(18)){
                returnBool = 0;
            }
            else{
                returnBool = 1;
            }
            break;
    }
    return returnBool;
 
 }

void toggleSolenoid(unsigned char toggle)
{
    if(toggle == ON)
    {
        _LATB8 = 1;
    }
    else if(toggle == OFF)
    {
        _LATB8 = 0;
    }

}

#endif	/* FUNCTIONS_H */

