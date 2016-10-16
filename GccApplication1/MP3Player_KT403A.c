#include "MP3Player_KT403A.h"
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

void initMP3(){
	uart_init( UART_BAUD_SELECT(9600,F_CPU) ); 
    /*
     * now enable interrupt, since UART library is interrupt controlled
     */
    sei();	
	
}


/**************************************************************** 
 * Function Name: SelectPlayerDevice
 * Description: Select the player device, U DISK or SD card.
 * Parameters: 0x01:U DISK;  0x02:SD card
 * Return: none
****************************************************************/ 
void SelectPlayerDevice(uint8_t device)
{
    uart_putc(0x7E);
    uart_putc(0xFF);
    uart_putc(0x06);
    uart_putc(0x09);
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(0x00));
    uart_putc(device);
    uart_putc(0xEF);
    _delay_ms(200);
}

/**************************************************************** 
 * Function Name: SpecifyMusicPlay
 * Description: Specify the music index to play, the index is decided by the input sequence of the music.
 * Parameters: index: the music index: 0-65535.
 * Return: none
****************************************************************/ 
void SpecifyMusicPlay(uint16_t index)
{
    uint8_t hbyte, lbyte;
    hbyte = index / 256;
    lbyte = index % 256;
    uart_putc(0x7E);
    uart_putc(0xFF);
    uart_putc(0x06);
    uart_putc(0x03);
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(hbyte));
    uart_putc((uint8_t)(lbyte));
    uart_putc(0xEF);
    _delay_ms(10);
//  return true;
}

/**************************************************************** 
 * Function Name: SpecifyfolderPlay
 * Description: Specify the music index in the folder to play, the index is decided by the input sequence of the music.
 * Parameters: folder: folder name, must be number;  index: the music index.
 * Return: none
****************************************************************/ 
void SpecifyfolderPlay(uint8_t folder, uint8_t index)
{
    uart_putc(0x7E);
    uart_putc(0xFF);
    uart_putc(0x06);
    uart_putc(0x0F);
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(folder));
    uart_putc((uint8_t)(index));
    uart_putc(0xEF);
    _delay_ms(10);
//  return true;
}

/**************************************************************** 
 * Function Name: PlayPause
 * Description: Pause the MP3 player.
 * Parameters: none
 * Return: none
****************************************************************/ 
void PlayPause(void)
{
    uart_putc(0x7E);
    uart_putc(0xFF);
    uart_putc(0x06);
    uart_putc(0x0E);
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(0x00));
//  uart_putc(0xFE);
//  uart_putc(0xED);
    uart_putc(0xEF);
    _delay_ms(20);
//  return true;
}

/**************************************************************** 
 * Function Name: PlayResume
 * Description: Resume the MP3 player.
 * Parameters: none
 * Return: none
****************************************************************/ 
void PlayResume(void)
{
    uart_putc(0x7E);
    uart_putc(0xFF);
    uart_putc(0x06);
    uart_putc(0x0D);
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(0x00));
//  uart_putc(0xFE);
//  uart_putc(0xEE);
    uart_putc(0xEF);
    _delay_ms(20);
//  return true;
}

/**************************************************************** 
 * Function Name: PlayNext
 * Description: Play the next song.
 * Parameters: none
 * Return: none
****************************************************************/ 
void PlayNext(void)
{
    uart_putc(0x7E);
    uart_putc(0xFF);
    uart_putc(0x06);
    uart_putc(0x01);
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(0x00));
    uart_putc(0xEF);
    _delay_ms(10);
//  return true;
}

/**************************************************************** 
 * Function Name: PlayPrevious
 * Description: Play the previous song.
 * Parameters: none
 * Return: none
****************************************************************/ 
void PlayPrevious(void)
{
    uart_putc(0x7E);
    uart_putc(0xFF);
    uart_putc(0x06);
    uart_putc(0x02);
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(0x00));
    uart_putc(0xEF);
    _delay_ms(10);
//  return true;
}

/**************************************************************** 
 * Function Name: PlayLoop
 * Description: Play loop for all the songs.
 * Parameters: none
 * Return: none
****************************************************************/ 
void PlayLoop(void)
{
    uart_putc(0x7E);
    uart_putc(0xFF);
    uart_putc(0x06);
    uart_putc(0x11);
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(0x00));
    uart_putc(0x01);
    uart_putc(0xEF);
    _delay_ms(10);
//  return true;
}

/**************************************************************** 
 * Function Name: SetVolume
 * Description: Set the volume, the range is 0x00 to 0x1E.
 * Parameters: volume: the range is 0x00 to 0x1E.
 * Return: none
****************************************************************/ 
void SetVolume(uint8_t volume)
{
    uart_putc(0x7E);
    uart_putc(0xFF);
    uart_putc(0x06);
    uart_putc(0x06);
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(0x00));
    uart_putc(volume);
    uart_putc(0xEF);
    _delay_ms(10);
//  return true;
}

/**************************************************************** 
 * Function Name: IncreaseVolume
 * Description: Increase the volume.
 * Parameters: none
 * Return: none
****************************************************************/ 
void IncreaseVolume(void)
{
    uart_putc(0x7E);
    uart_putc(0xFF);
    uart_putc(0x06);
    uart_putc(0x04);
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(0x00));
    uart_putc(0xEF);
    _delay_ms(10);
//  return true;
}

/**************************************************************** 
 * Function Name: DecreaseVolume
 * Description: Decrease the volume.
 * Parameters: none
 * Return: none
****************************************************************/ 
void DecreaseVolume(void)
{
    uart_putc(0x7E);
    uart_putc(0xFF);
    uart_putc(0x06);
    uart_putc(0x05);
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(0x00));
    uart_putc((uint8_t)(0x00));
    uart_putc(0xEF);
    _delay_ms(10);
//  return true;
}

/**************************************************************** 
 * Function Name: QueryPlayStatus
 * Description: Query play status.
 * Parameters: none
 * Return: 0: played out; 1: other.
 * Usage: while(QueryPlayStatus() != 0);  // Waiting to play out.
****************************************************************/ 
uint8_t QueryPlayStatus(void)
{
    unsigned char c[10] = {0};
    uint8_t i = 0;
    //check if there's any data sent from the Grove_Serial_MP3_Player
    while(uart_available())
    {
        c[i] = readUART_Char();
        i++;
		_delay_ms(1);
		if (i == 10) return 0;
//        Serial.print(" 0x");
//        Serial.print(c[i], HEX);
    }
//    Serial.println(" "); 
    
    if(c[3] == 0x3C || c[3] == 0x3D || c[3] == 0x3E)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

char readUART_Char(void){
    for(;;)
    {
        /*
         * Get received character from ringbuffer
         * uart_getc() returns in the lower byte the received character and 
         * in the higher byte (bitmask) the last receive error
         * UART_NO_DATA is returned when no data is available.
         *
         */
        char c = uart_getc();
        if ( c & UART_NO_DATA )
        {
            /* 
             * no data available from UART 
             */
			continue;
        }
        else
        {
            /*
             * new data available from UART
             * check for Frame or Overrun error
             */
            if ( c & UART_FRAME_ERROR )
            {
                /* Framing Error detected, i.e no stop bit detected */
                //uart_puts_P("UART Frame Error: ");
            }
            if ( c & UART_OVERRUN_ERROR )
            {
                /* 
                 * Overrun, a character already present in the UART UDR register was 
                 * not read by the interrupt handler before the next character arrived,
                 * one or more received characters have been dropped
                 */
                //uart_puts_P("UART Overrun Error: ");
            }
            if ( c & UART_BUFFER_OVERFLOW )
            {
                /* 
                 * We are not reading the receive buffer fast enough,
                 * one or more received character have been dropped 
                 */
                //uart_puts_P("Buffer overflow error: ");
            }
			return (unsigned char)c;
        }
	}
}
