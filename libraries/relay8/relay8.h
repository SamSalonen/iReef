/*
  relay8.h - Arduino and chipKit library support for relay boards
  Copyright (C)2013 Henning Karlsen. All right reserved
  
  You can find the latest version of the library at 
  http://www.henningkarlsen.com/electronics

  This library supports from 1 to 8 relays.

  If you make any modifications or improvements to the code, I would appreciate
  that you share the code with me so that I might include it in the next release.
  I can be contacted through http://www.henningkarlsen.com/electronics/contact.php

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef relay8_h
#define relay8_h

#if defined(__AVR__)
  #if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega32U4__)
	#include "Arduino.h"
  #else
    #error "Unsupported AVR MCU!"
  #endif  
#elif defined(__PIC32MX__)
  #if defined(__32MX320F128H__) || defined(__32MX795F512L__)
	#include "Wprogram.h"
  #else
    #error "Unsupported PIC32 MCU!"
  #endif  
#elif defined(__arm__)
  #if defined(__SAM3X8E__)
	#include "Arduino.h"
  #else
    #error "Unsupported ARM MCU!"
  #endif  
#else
  #error "Unsupported MCU architecture!"
#endif

#define MAX_RELAYS			8
#define DEFAULT_DELAY_TIME	250
#define	NOT_IN_USE			9999

// OUTPUT_ON_LEVEL should be set to HIGH or LOW according to what signal switches your relays ON.
#define OUTPUT_ON_LEVEL	HIGH

class relay8
{ 
public:
	relay8(int pin1, int pin2=NOT_IN_USE, int pin3=NOT_IN_USE, int pin4=NOT_IN_USE, int pin5=NOT_IN_USE, int pin6=NOT_IN_USE, int pin7=NOT_IN_USE, int pin8=NOT_IN_USE);

	int		numberOfRelays();

	void	on(int relay);
	void	off(int relay);
	void	allOn();
	void	allOff();

	void	cycle(int delay_time=DEFAULT_DELAY_TIME);
	void	cycleUp(int delay_time=DEFAULT_DELAY_TIME);
	void	cycleDown(int delay_time=DEFAULT_DELAY_TIME);

	void	chaseUpOn(int delay_time=DEFAULT_DELAY_TIME);
	void	chaseUpOff(int delay_time=DEFAULT_DELAY_TIME);
	void	chaseDownOn(int delay_time=DEFAULT_DELAY_TIME);
	void	chaseDownOff(int delay_time=DEFAULT_DELAY_TIME);

private:
	int _relay_pin[8];
	int _number_of_relays;
};


#endif