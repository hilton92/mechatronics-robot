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

#ifndef ENUMS_H
#define	ENUMS_H

//events
enum {DISPENSERLIGHTDETECTED, DISPENSERLIGHTTHRESHOLDMET, BINLIGHTDETECTED, BINLIGHTNOTDETECTED, BINLIGHTTHRESHOLDMET, ONESONICSENSORTHRESHOLDMET, TWOSONICSENSORTHRESHOLDMET, TIMER1MET, BUTTONPRESSED, BALLSFULL};

//states
enum {WAITFORBUTTON, TURNFINDIR, FACEDISPENSER, DRIVETOCORNERQUICK, DRIVEINTOCORNER, LOADBALLS, DRIVETOMIDDLE, FACEBIN, BACKUPTOSHOOT, SHOOTGOALS};

//event status variables
enum {SHOOTTIME, PERIODCOUNT};

//manipulator commands
enum {CLEAR, UPDATE, REQUEST, INCREMENT};

//other enums
enum {LEFT, RIGHT};

//global constants
const unsigned char ONE_256 = 0b11;
const unsigned char ONE_64 = 0b10;
const unsigned char ONE_8 = 0b01;
const unsigned char ONE_1 = 0b00;

#endif	/* ENUMS_H */

