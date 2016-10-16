#ifndef GlobalDefinitions_h
#define GlobalDefinitions_h

#define RAMEND 0x08ff

#include <inttypes.h>
//Macros for easier IO Pin handling
#define _BSET(type,name,bit)            (type ## name  |= _BV(bit))
#define _BCLEAR(type,name,bit)          (type ## name  &= ~ _BV(bit))
#define _BTOGGLE(type,name,bit)         (type ## name  ^= _BV(bit))
#define _BGET(type,name,bit)            ((type ## name >> bit) &  1)
#define _BPUT(type,name,bit,value)      (type ## name = ( type ## name & ( ~ _BV(bit)) ) | ( ( 1 & (unsigned char)value ) << bit ))

//these macros are used by end user
#define OUTPUT(pin)            _BSET(DDR,pin)
#define INPUT(pin)             _BCLEAR(DDR,pin)
#define HIGH(pin)              _BSET(PORT,pin)
#define LOW(pin)               _BCLEAR(PORT,pin)
#define TOGGLE(pin)            _BTOGGLE(PORT,pin)
#define READ(pin)              _BGET(PIN,pin)
#define PUT(pin,val)           _BPUT(PORT,pin,val)

//IO Pin definitions
#define frontDoorButton C,0
#define backDoorButton C,2

//UNUSED IO PINS
#define pinUnused1 D,0
#define pinUnused2 D,1
#define pinUnused3 D,2
#define pinUnused4 D,3
#define pinUnused5 D,4
#define pinUnused6 D,5
#define pinUnused8 C,1
#define pinUnused9 C,3
#define pinUnused10 C,4
#define pinUnused11 B,5


//Program constants, 
#define F_CPU 8000000UL
//swipe card clock speed in microseconds. Scanners can tolerate various "card swipe speeds" so just shoot for the average swipe speed
#define swipeCardSpeed 750 
//Button debounce time in milliseconds
#define keypad_debounce_time 25
#endif