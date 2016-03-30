/* 
 * File:   eventUpdaters.h
 * Author: Justin
 *
 * Created on February 15, 2016, 12:05 PM
 */


//IMPORTANT NOTE
//---------on off button and timer 1 are the only interrupts!!
//Must close the ball drop pin when entering other states

#include "constants.h"
#include "functions.h"

#ifndef EVENTUPDATERS_H
#define	EVENTUPDATERS_H

//function stubs ------------------------------
void checkDispenserLightDetected();
void checkDispenserLightThresholdMet();
void checkBinLightDetected();
void checkBinLightNotDetected();
void checkBinLightThresholdMet();
void checkOneSonicSensorThresholdMet();
void checkTwoSonicSensorThresholdMet();
void checkButtonPressed();
void checkLeftBinLightDetected();
void checkRightBinLightDetected();
void checkFrontBinLightDetected();
void checkFrontButtonsPressed();

//----------------------------------------------

void checkDispenserLightDetected() {
    static float max = 0;
    static int counter = 0;
    static float prevVal = 0;
    
    float sum = 0;
    int count = 0;
    while (count < 70) {
        sum = sum + readAD(16);
        count++;
    }
    float voltageFront = sum / 70.0;
    if (voltageFront > IRDISPENSERTHRESHOLD){
        setHigh(&dispenserLightDetected);
    }
    
    //code to find max threshold!!!
    /*if (((voltageFront - prevVal) < IRDELTA) && ((prevVal - voltageFront) < IRDELTA)) {
        
        if (voltageFront > max) {
            //set a new max
            max = voltageFront;
            counter = 0;
        } 
        else {
            //increment the counter
            counter = counter + 1;
        }
    }
    if ((counter > 50) && (voltageFront > IRDISPENSERTHRESHOLD)){
        setHigh(&dispenserLightDetected);
        counter = 0;
        
    }
    prevVal = voltageFront;*/
    
}



void checkDispenserLightThresholdMet() {
    float sum = 0;

    int count = 0;
    while (count < 70) {
        sum = sum + readAD(16);
        count++;
    }

    float voltageFront = sum / 70.0;
    if (voltageFront > IRDISPENSERTHRESHOLD) {
        setHigh(&dispenserLightThresholdMet);
    }
}

void checkBinLightDetected() {

}

void checkBinLightNotDetected() {

}

void checkBinLightThresholdMet() {

}

void checkOneSonicSensorThresholdMet() {

}

void checkTwoSonicSensorThresholdMet() {

}

void checkButtonPressed() {

}

void checkFrontBinLightDetected() {
    float sum = 0;

    int count = 0;
    while (count < 70) {
        sum = sum + readAD(15);
        count++;
    }

    float voltageFront = sum / 70.0;
    if (voltageFront > IRBINTHRESHOLD) {
        setHigh(&frontBinLightDetected);
    }
}

void checkRightBinLightDetected() {
    float sum = 0;

    int count = 0;
    while (count < 70) {
        sum = sum + readAD(17);
        count++;
    }

    float voltageRight = sum / 70.0;
    if (voltageRight > IRBINTHRESHOLD) {
        setHigh(&rightBinLightDetected);
    }
}

void checkLeftBinLightDetected() {
    float sum = 0;

    int count = 0;
    while (count < 70) {
        sum = sum + readAD(18);
        count++;
    }

    float voltageLeft = sum / 70.0;
    if (voltageLeft > IRBINTHRESHOLD) {
        setHigh(&leftBinLightDetected);
    }
}

void checkFrontButtonsPressed() {
    if (_RB7 == 1) {
        setHigh(&frontButtonsPressed);
    }
}






#endif	/* EVENTUPDATERS_H */

