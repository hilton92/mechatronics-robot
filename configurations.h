/* 
 * File:   configurations.h
 * Author: Justin
 *
 * Created on February 6, 2016, 11:44 AM
 */

#include "handlers.h"

#ifndef CONFIGURATIONS_H
#define	CONFIGURATIONS_H

//Stubs----------
void configureEvents();
void chooseADpin(int pin);
void configureAD();
void configurePWM(int ocx, int timer, int period);
float readAD(int pin); //reads in value from 0 to 3.3 volts
//---------------



//This function turns on the analog pin to be scanned
void chooseADpin(int pin)
{
    
    // AD1CSS registers
    // SET THE BITS CORRESPONDING TO CHANNELS THAT YOU WANT
    // TO SAMPLE
    switch(pin)
    {
            case 2: //AN0 pin 2
               _CSS0 = 1;
               break;
            case 3: //AN1 pin 3
               _CSS1 = 1;
               break;
            case 4: //AN2 pin 4   
               _CSS2 = 1;
               break;
            case 5: //AN3 pin 5     
               _CSS3 = 1;
               break;
            case 6: //AN4 pin 6    
               _CSS4 = 1;
               break;
            case 18: //AN9 pin 18    
               _CSS9 = 1;
               break;
            case 17:  //AN10 pin 17    
               _CSS10 = 1;
               break;
            case 16:  //AN11 pin 16 
               _CSS11 = 1;
               break;
            case 15: //AN12 pin 15 
               _CSS12 = 1;
               break;
            case 7: //AN13 pin 7           
               _CSS13 = 1;
               break;
            case 8: //AN14 pin 8   
               _CSS14 = 1;
               break;
            case 9: //AN15 pin 9   
               _CSS15 = 1;
               break;
    }
}

// This function configures the A/D to read from
// multiple channels in scan mode.
void configureAD(void)
{
    
    _ADON = 0;    // AD1CON1<15> -- Turn off A/D

    
    // AD1CON1 register
    _MODE12 = 1;  // AD1CON1<10> -- 12-bit A/D operation
    _FORM = 0;    // AD1CON1<9:8> -- Unsigned integer output
    _SSRC = 7;    // AD1CON1<7:4> -- Auto conversion
			  // (internal counter)
    _ASAM = 1;    // AD1CON1<2> -- Auto sampling
    _ADSIDL = 0;  // AD1CON1<13> -- A/D continues in idle mode

    // AD1CON2 register
    _PVCFG = 0;   // AD1CON2<15:14> -- Use VDD as positive
                  // ref voltage
    _NVCFG = 0;   // AD1CON2<13> -- Use VSS as negative
                  // ref voltage
    _BUFREGEN = 1;// AD1CON2<11> -- Result appears in buffer
                  // location corresponding to channel
    _CSCNA = 1;   // AD1CON2<10> -- Scans inputs specified
                  // in AD1CSSx registers
    _SMPI = 3;	  // AD1CON2<6:2> -- Every 4th conversion sent
                  // to buffer (if sampling 4 channels)
    _ALTS = 0;    // AD1CON2<0> -- Sample MUXA only

    // AD1CON3 register
    _ADRC = 0;    // AD1CON3<15> -- Use system clock
    _SAMC = 0;    // AD1CON3<12:8> -- Auto sample every A/D
                  // period TAD
    _ADCS = 0x3F; // AD1CON3<7:0> -- A/D period TAD = 64*TCY
    
    
    _ADON = 1;    // AD1CON1<15> -- Turn on A/D
}

void configurePWM(int ocx, int timer, int period)
{
    // PERIOD EXAMPLE: Fcy/PRESCLER/DESIREDHZ 
    // SERVO INFO: 250=0deg=.5ms 1200=180deg=2.4ms     
    //             OC1R =  250 + (float)ADC1BUF4 / 4095 * 950;
    // OCR INFO: pulseTimeOn/PeriodTimeOn * PRx = OCxR
    

    int octsel;
    int syncsel;
    
    //switch into timer
    switch(timer)
    {
            case 1:
               octsel = 0b100;
               syncsel = 0b01011;
               PR1 = period;
               break;
            case 2:
               octsel = 0b000;
               syncsel = 0b01100;
               PR2 = period;
               break;
            case 3:
               octsel = 0b001;
               syncsel = 0b01101;
               PR3 = period;
               break;
            case 4:
               octsel = 0b010; 
               syncsel = 0b01110;
               PR4 = period;
               break;
            case 5:
               octsel = 0b011;
               syncsel = 0b01111;
               PR5 = period;
               break;
    }
    
    //switch into 3 different OC pins
    switch(ocx)
    {    
            //Pin 14
            case 1:  
                _TRISA6 = 0;
                OC1CON1bits.OCTSEL = octsel; 
                OC1CON1bits.OCM = 0b110; //center aligned
                OC1CON2bits.SYNCSEL = syncsel; 
                break;
                
            //Pin 4
            case 2:
                _TRISB0 = 0;
                OC2CON1bits.OCTSEL = octsel; 
                OC2CON1bits.OCM = 0b110; //center aligned
                OC2CON2bits.SYNCSEL = syncsel; 
                break; 
                
                
            //Pin 5
            case 3:
                _TRISA6 = 0;
                OC3CON1bits.OCTSEL = octsel; 
                OC3CON1bits.OCM = 0b110; //center aligned
                OC3CON2bits.SYNCSEL = syncsel; 
                break;
    } 
                        
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

void configureEvents()
{
    initializeEvents();    
}



#endif	/* CONFIGURATIONS_H */

