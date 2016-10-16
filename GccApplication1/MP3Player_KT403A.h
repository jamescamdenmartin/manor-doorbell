#ifndef __MP3PLAYER_KT403A_H__
#define __MP3PLAYER_KT403A_H__

#include "globaldefinitions.h"
#include "uart.h"

void initMP3(void);
void SelectPlayerDevice(uint8_t device);
void SpecifyMusicPlay(uint16_t index);
void SpecifyfolderPlay(uint8_t folder, uint8_t index);
void PlayPause(void);
void PlayResume(void);
void PlayNext(void);
void PlayPrevious(void);
void PlayLoop(void);
void SetVolume(uint8_t volume);
void IncreaseVolume(void);
void DecreaseVolume(void);
uint8_t QueryPlayStatus(void);
void printReturnedData(void);
char readUART_Char(void);

#endif