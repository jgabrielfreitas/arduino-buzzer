/*
  Melody
 Plays a melody
 circuit:
 * 8-ohm speaker on digital pin 8
 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe
This example code is in the public domain.
 http://arduino.cc/en/Tutorial/Tone
 */
 #include "pitches.h"

int melody[] = {  //Define the melody as being the notes following using those defined in pitches.h
NOTE_E4, NOTE_G4, NOTE_D4, NOTE_C4, NOTE_D4, 
NOTE_E4, NOTE_G4, NOTE_D4,   0,     NOTE_E4, 
NOTE_G4, NOTE_D5, NOTE_C5, NOTE_G4, NOTE_F4, 
NOTE_E4, NOTE_D4,    0,    NOTE_E4, NOTE_G4, 
NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4, 
NOTE_D4,    0,    NOTE_E4, NOTE_G4, NOTE_D5, 
NOTE_C5, NOTE_G4};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {                                               //Define the note durations, 1 to 1 with melody    1 = 8 beats 
  2,4,2,8,8,                                                          //                                                 2 = 4 beats (whole note)
  2,4,2,4,2,                                                          //                                                 4 = 2 beats (half note)
  4,2,4,2,8,                                                          //                                                 8 = 1 beats (quarter note)
  8,2,4,2,4,
  2,8,8,2,4,
  2,4,2,4,2,
  4,1 };

int pin = 9;

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 45; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(pin, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(pin);
  }
}

void loop() {
  // no need to repeat the melody.
}
