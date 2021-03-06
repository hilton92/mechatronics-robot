/* 
 * File:   enumns.h
 * Author: Justin
 *
 * Created on February 6, 2016, 12:28 PM
 */
//sublties in the code
//BALLSFULL gets updated using timer3 only during SHOOTGOALS, and by LOADBALLS
//timer 2 used for ultra sonic
//timer 3 used for time shooting goals

#ifndef CONSTANTS_H
#define	CONSTANTS_H

//events
enum {DISPENSERLIGHTDETECTED, DISPENSERLIGHTTHRESHOLDMET, BINLIGHTDETECTED, BINLIGHTNOTDETECTED, BINLIGHTTHRESHOLDMET, ONESONICSENSORTHRESHOLDMET, TWOSONICSENSORTHRESHOLDMET, TIMER1MET, BUTTONPRESSED, BALLSFULL};

//states
enum {TURNFINDIR, FACEDISPENSER, DRIVETOCORNERQUICK, DRIVEINTOCORNER, LOADBALLS, DRIVETOMIDDLE, WAITFORBINLIGHT, FACELEFTBINLIGHT, FACERIGHTBINLIGHT, FACEFRONTBINLIGHT, SHOOTGOALS, CLOSESOLENOID};

//event status variables
enum {SHOOTTIME, PERIODCOUNTRIGHT, PERIODCOUNTLEFT};

//manipulator commands
enum {CLEAR, UPDATE, REQUEST, INCREMENT};

//other enums
enum {LEFT, RIGHT};

enum {BACKWARD, FORWARD};

enum {OFF, ON};

enum {ENTER, EXIT};

enum {LEFTBIN, RIGHTBIN, FRONTBIN};

enum {LEFTIR, RIGHTIR, FRONTIR, REARIR};

enum {DISPENSER, BIN};
//global constants
const unsigned char PRESCALE_ONE_256 = 0b11;
const unsigned char PRESCALE_ONE_64 = 0b10;
const unsigned char PRESCALE_ONE_8 = 0b01;
const unsigned char PRESCALE_ONE_1 = 0b00;
const int MOTORLOWSPEED = 1300; //period for motors
const int MOTORLOWLOWSPEED = 1500; //period for motors
const int MOTORHIGHSPEED = 1300; //period for motors
const int TURRETSPEED = 450; //turret speed 
const unsigned int QUARTERTURNCOUNT = 492;
const unsigned int DRIVETOMIDDLECOUNT = 2113;
const float IRBINTHRESHOLD = 1.45;
const float IRDISPENSERDETECTED = 1.6;
const float IRDISPENSERTHRESHOLD = 1.4;
const unsigned int TRIGGERDELAY = 350;
const float DISPENSERIRDELTA = .68;
const float BINIRDELTA = .62;
const int TRIGGERDEGREE = 0;
const int TRIGGERDEGREE2 = 32;
const int SOLENOIDDELAY = 100;

#endif	/* ENUMS_H */

