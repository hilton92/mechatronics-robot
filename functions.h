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
    rotateDisk(180);
    delayMS(TRIGGERDELAY);
    rotateDisk(0);
    delayMS(TRIGGERDELAY);
    
    rotateDisk(180);
    delayMS(TRIGGERDELAY);
    rotateDisk(0);
    delayMS(TRIGGERDELAY);
    
    rotateDisk(180);
    delayMS(TRIGGERDELAY);
//    rotateDisk(0);
//    delayMS(500);
    
    

}


#endif	/* FUNCTIONS_H */

