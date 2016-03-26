/* 
 * File:   configurations.h
 * Author: Justin
 *
 * Created on February 6, 2016, 11:44 AM
 */

#include "handlers.h"
#include "caseSwitch.h"

#ifndef CONFIGURATIONS_H
#define	CONFIGURATIONS_H

//Stubs----------
void configureEvents();
void chooseADpin(int pin);
void configureAD();
void configurePWM(int ocx, int timer, int period);
//float readAD(int pin); //reads in value from 0 to 3.3 volts
void configureTimerXInterrupt(int timer);
void configureTimer(int timer, int perscaler);
void calibrate();
//---------------

//configure timer
void configureTimer(int timer, int prescaler)
{
    switch(timer)
    {
            case 1:
                T1CONbits.TON = 1;
                T1CONbits.TCKPS = prescaler; 
                T1CONbits.TCS = 0;  //set timer 1 to internal clock
                break;
               
            case 2:
                T2CONbits.TON = 1;
                T2CONbits.TCKPS = prescaler; 
                T2CONbits.TCS = 0;  //set timer 2 to internal clock
                break;
            case 3:
                T3CONbits.TON = 1;
                T3CONbits.TCKPS = prescaler; 
                T3CONbits.TCS = 0;  //set timer 3 to internal clock
                break;
            case 4:
                T4CONbits.TON = 1;
                T4CONbits.TCKPS = prescaler; 
                T4CONbits.TCS = 0;  //set timer 4 to internal clock
                break;
            case 5:
                T5CONbits.TON = 1;
                T5CONbits.TCKPS = prescaler; 
                T5CONbits.TCS = 0;  //set timer 5 to internal clock
                break;
    }               
}

void configureTimers()
{
    configureTimer(2,PRESCALE_ONE_8);  //Both Motors
    configureTimer(5,PRESCALE_ONE_256);  //For the timer function
    configureTimer(3,PRESCALE_ONE_8);  //Turret Motor
    configureTimer(4,PRESCALE_ONE_8); //Servo Motor
    configureTimer(1,PRESCALE_ONE_1); //for the Ultrasonic counter
}

void configureTimerInterrupts()
{
    configureTimerXInterrupt(1);
    configureTimerXInterrupt(2);
    configureTimerXInterrupt(5);
    configureTimerXInterrupt(3);
}

//Configures the pins to be output or input pins
void configureIOPins()
{
    ANSB = 0;
    ANSA = 0;    
    
    _TRISA0 = 0; //left motor direction pin 2
    _TRISA1 = 0; //right motor direction pin 3
    _TRISB9 = 0; //turret direction pin 13
    _TRISB7 = 1; //front bumper buttons
    _TRISA6 = 0; //servo motor
    _TRISB2 = 1; //Ultrasonic 1 input
    _TRISA2 = 0; //Ultrasonic 1 output
    _TRISA3 = 1; //Ultrasonic 2 input
    _TRISB4 = 1; //Ultrasonic 2 output
    _TRISA4 = 1; //turret stopper button
    
    //configure motor pins
    configurePWM(2,2,500); //left motor pin 4 RB0 
    configurePWM(3,3,500); //turret motor pin 5 RB1
    
    //configure servo
    configurePWM(1,4,12500); //250 to 950 
    
    //Configure the analog pins for IR
    chooseADpin(15);
    chooseADpin(16);
    chooseADpin(17);
    chooseADpin(18);
  
}

void configureTimerXInterrupt(int timer)
{
    switch(timer)
    {
            case 1:
                //T1CONbits.TON = 1;     //Turn on Timer1
                //T1CONbits.TCS = 0;     //Select internal clock as timer clock
                _T1IP = 4;  // Setting the priority to be 4
                _T1IE = 1;  // Enable Timer 1 interrupt
                _T1IF = 0;  // Clear Timer1 interrupt flag
                break;
               
            case 2:
              //  T2CONbits.TON = 1;     //Turn on Timer2
              //  T2CONbits.TCS = 0;     //Select internal clock as timer clock
                _T2IP = 4;  // Setting the priority to be 4
                _T2IE = 1;  // Enable Timer 2 interrupt
                _T2IF = 0;  // Clear Timer2 interrupt flag
                break;
            case 3:
                //T3CONbits.TON = 1;     //Turn on Timer3
                //T3CONbits.TCS = 0;     //Select internal clock as timer clock
                _T3IP = 4;  // Setting the priority to be 4
                _T3IE = 1;  // Enable Timer 3 interrupt
                _T3IF = 0;  // Clear Timer3 interrupt flag
                break;
            case 4:
                //T3CONbits.TON = 1;     //Turn on Timer3
                //T3CONbits.TCS = 0;     //Select internal clock as timer clock
                _T4IP = 4;  // Setting the priority to be 4
                _T4IE = 1;  // Enable Timer 3 interrupt
                _T4IF = 0;  // Clear Timer3 interrupt flag
                break;
            case 5:
                //T3CONbits.TON = 1;     //Turn on Timer3
                //T3CONbits.TCS = 0;     //Select internal clock as timer clock
                _T5IP = 4;  // Setting the priority to be 4
                _T5IE = 1;  // Enable Timer 3 interrupt
                _T5IF = 0;  // Clear Timer3 interrupt flag
                break;
    }               
}

//This function turns on the analog pin to be scanned
void chooseADpin(int pin)
{
    
    // AD1CSS registers
    // SET THE BITS CORRESPONDING TO CHANNELS THAT YOU WANT
    // TO SAMPLE
    switch(pin)
    {
            case 2: //AN0 pin 2
                _ANSA0 = 1;
               _CSS0 = 1;
               break;
            case 3: //AN1 pin 3
                _ANSA1 = 1;
               _CSS1 = 1;
               break;
            case 4: //AN2 pin 4
                _ANSB0 = 1;
               _CSS2 = 1;
               break;
            case 5: //AN3 pin 5
                _ANSB1 = 1;
               _CSS3 = 1;
               break;
            case 6: //AN4 pin 6
                _ANSB2 = 1;
               _CSS4 = 1;
               break;
            case 18: //AN9 pin 18
                _ANSB15 = 1;
               _CSS9 = 1;
               break;
            case 17:  //AN10 pin 17
                _ANSB14 = 1;
               _CSS10 = 1;
               break;
            case 16:  //AN11 pin 16
                _ANSB13 = 1;
               _CSS11 = 1;
               break;
            case 15: //AN12 pin 15
                _ANSB12 = 1;
               _CSS12 = 1;
               break;
            case 7: //AN13 pin 7
                _ANSA2 = 1;
               _CSS13 = 1;
               break;
            case 8: //AN14 pin 8
                _ANSA3 = 1;
               _CSS14 = 1;
               break;
            case 9: //AN15 pin 9
                _ANSB4 = 1;
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



void configureEvents()
{
    initializeEvents();    
}





#endif	/* CONFIGURATIONS_H */

