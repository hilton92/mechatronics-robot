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
    float sum = 0;
    int count = 0;
    while (count < 70) {
        sum = sum + readAD(16);
        count++;
    }
    float voltageFront = sum / 70.0;
    if (voltageFront > IRthreshold && (isMaxIR(REARIR) == 1)){
        setHigh(&dispenserLightDetected);
    }
    
}



void checkDispenserLightThresholdMet() {
    float sum = 0;

    int count = 0;
    while (count < 70) {
        sum = sum + readAD(16);
        count++;
    }

    float voltageFront = sum / 70.0;
    if (voltageFront > IRthreshold) {
        setHigh(&dispenserLightThresholdMet);
    }
}

void checkBinLightDetected() {

}


void checkBinLightNotDetected()
{
    clearEvents();
    checkLeftBinLightDetected();
    checkRightBinLightDetected();
    checkFrontBinLightDetected();
    
    if(currentBin == LEFTBIN && !getEvent(&leftBinLightDetected))
    {
        setHigh(&binLightNotDetected);
    }
    
    else if(currentBin == RIGHTBIN && !getEvent(&rightBinLightDetected))
    {
        setHigh(&binLightNotDetected);
    }
    
    else if(currentBin == FRONTBIN && !getEvent(&frontBinLightDetected))
    {
        setHigh(&binLightNotDetected);
    }
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
    if (voltageFront > IRthreshold && (isMaxIR(FRONTIR) == 1) ) {
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
    if (voltageRight > IRthreshold && (isMaxIR(RIGHTIR) == 1)) {
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
    if (voltageLeft > IRthreshold && (isMaxIR(LEFTIR) == 1)) {
        setHigh(&leftBinLightDetected);
    }
}

void checkFrontButtonsPressed() {
    if (_RB7 == 1) {
        setHigh(&frontButtonsPressed);
    }
}






#endif	/* EVENTUPDATERS_H */

