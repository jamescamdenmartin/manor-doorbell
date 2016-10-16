/********************************************************************************
Kirkpatrick Manor Doorbell Controller
by Compton

SD Card format:
{root directory}/01/001.mp3   - Front door sounds
{root directory}/02/001.mp3   - Back door sounds

sound names can be from 000.mp3-255.mp3

********************************************************************************/

/********************************************************************************
Includes
********************************************************************************/
#include "globaldefinitions.h"
#include "MP3Player_KT403A.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#include <stdio.h>
#include <stdlib.h>

#include <util/delay.h>
#include "millis.h"

/********************************************************************************
Function Prototypes
********************************************************************************/


/********************************************************************************
Global Constants
********************************************************************************/
uint8_t numberFrontDoorSounds=4;
uint8_t numberBackDoorSounds=1;


/********************************************************************************
Global Variables
********************************************************************************/


/********************************************************************************
Main
********************************************************************************/

int main(void) {
			
	// initialize code
	INPUT(frontDoorButton);
    LOW(frontDoorButton); //Tri state-disable internal pullup
	INPUT(backDoorButton);
    LOW(backDoorButton); //Tri state-disable internal pullup
	
	millis_init(); //Initialize millisecond timer
	millis_pause();
	sei(); //Enable interrupts
	
	initMP3();
	SelectPlayerDevice(0x02);
	SetVolume(0x1A);

	uint8_t previousFrontButtonState=0;
	uint8_t previousBackButtonState=0;
	while (1) {
		if(READ(frontDoorButton) && previousFrontButtonState==0){
			_delay_ms(20);
			if(!(READ(frontDoorButton))) continue;
			_delay_ms(5);
			if(!(READ(frontDoorButton))) continue;
			
			
			SpecifyfolderPlay(0x01,rand()%numberFrontDoorSounds+1); //Choose random sound between 001.mp3 - 255.mp3
			for(uint8_t i=0;i<30;i++){ //Query play status does not work correctly (sometimes gets stuck)
				_delay_ms(100);
			}
			//while(QueryPlayStatus()){
				//wait for sound clip to finish playing
			//}
		}
		if(READ(backDoorButton)  && previousBackButtonState==0){
			_delay_ms(20);
			if(!(READ(backDoorButton))) continue;
			_delay_ms(5);
			if(!(READ(backDoorButton))) continue;			
			
			SpecifyfolderPlay(0x02,rand()%numberBackDoorSounds+1);
			for(uint8_t i=0;i<30;i++){
				_delay_ms(100);
			}
		}
		previousFrontButtonState= READ(frontDoorButton);
		previousBackButtonState=  READ(backDoorButton);
	}

	return 1;
}
