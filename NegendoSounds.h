#ifndef NegendoSounds_h
#define NegendoSounds_h

#include "Sounds.h"
#include "TimerFreeTone.h"

#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class NegendoSounds
{
public:
	NegendoSounds(){}
	void setPin(int pin);
	void _tone (float noteFrequency, long noteDuration, int silentDuration);
	//void generateNote (float noteFrequency);
	void _playNote(float noteFrequency, long noteDuration);
    void bendTones (float initFrequency, float finalFrequency, float prop, long noteDuration, int silentDuration);
    void sing(int songName);
    NegendoSounds(int _pinBuzzer);
private:
	int Buzzer_pin;

protected:
	
};
#endif