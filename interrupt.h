/* 
 * File:   interrupt.h
 * Author: Justin
 *
 * Created on February 23, 2016, 9:59 PM
 */

#include<p24F16KA301.h>

#ifndef INTERRUPT_H
#define	INTERRUPT_H

void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void)
{

    // Remember to clear the Timer1 interrupt flag when
    // this ISR is entered.
    // PLACE CODE TO CLEAR THE TIMER1 INTERRUPT FLAG HERE
    _T1IF = 0;
    TMR1 = 0;
}

void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void)
{

    // Remember to clear the Timer1 interrupt flag when
    // this ISR is entered.
    // PLACE CODE TO CLEAR THE TIMER1 INTERRUPT FLAG HERE
    _T2IF = 0;
    TMR2 = 0;

}

void __attribute__((interrupt, no_auto_psv)) _T3Interrupt(void)
{

    // Remember to clear the Timer1 interrupt flag when
    // this ISR is entered.
    // PLACE CODE TO CLEAR THE TIMER1 INTERRUPT FLAG HERE
    _T3IF = 0;
    TMR3 = 0;

}

void __attribute__((interrupt, no_auto_psv)) _T4Interrupt(void)
{

    // Remember to clear the Timer1 interrupt flag when
    // this ISR is entered.
    // PLACE CODE TO CLEAR THE TIMER1 INTERRUPT FLAG HERE
    _T4IF = 0;
    TMR4 = 0;
    periodCountRight++;
}

void __attribute__((interrupt, no_auto_psv)) _T5Interrupt(void)
{

    // Remember to clear the Timer1 interrupt flag when
    // this ISR is entered.
    // PLACE CODE TO CLEAR THE TIMER1 INTERRUPT FLAG HERE
    _T5IF = 0;
    TMR5 = 0;
    incrementEventInfo(PERIODCOUNTRIGHT, 1);
}


#endif	/* INTERRUPT_H */

