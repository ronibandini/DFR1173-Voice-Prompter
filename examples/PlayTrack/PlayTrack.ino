// DFRobot DFR1173 mp3 voice prompter example code
// Roni Bandini, MIT License, 12/2025
// Connect Prompter TX to Ardino RX, Prompter RX to Arduino TX and Prompter Busy to Arduino 9

#include "DFR1173.h"

DFR1173 mp3(Serial1, 9);

void setup() {
  Serial.begin(115200);
  mp3.begin(9600);
  
  delay(1000);
  Serial.println("Voice prompter started...");
  mp3.setVolume(25);
}

void loop() {
  Serial.println("Playing track 1...");
  mp3.playTrack(1);
  mp3.isPlaying();
  
  Serial.println("Audio finished...");
  delay(2000);
}
