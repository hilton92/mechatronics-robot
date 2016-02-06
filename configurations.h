/* 
 * File:   configurations.h
 * Author: Justin
 *
 * Created on February 6, 2016, 11:44 AM
 */

#include "events.h"

#ifndef CONFIGURATIONS_H
#define	CONFIGURATIONS_H

void configureEvents()
{
    clearEvents();
    setEventInactive(BALLSLOADED);
}

#endif	/* CONFIGURATIONS_H */

