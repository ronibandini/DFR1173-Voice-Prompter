# DFR1173 Voice Prompter Library

Arduino library designed to control the DFRobot DFR1173 MP3 Voice Prompter module through serial commands.

## Features

- Full playback control: Play, Pause, Resume, Stop.
- Volume management (0-30).
- Track and folder navigation.
- Status verification support via BUSY pin.
- Low power mode.

<img width="977" height="1192" alt="VoicePrompter" src="https://github.com/user-attachments/assets/4853c2be-8e7f-4f0e-923e-dd517a18c201" />

## Wiring (Arduino Nano R4)

| DFR1173 Pin | Arduino Nano R4 Pin |
|-------------|---------------------|
| TX (Green)  | RX (D0)             |
| RX (Yellow) | TX (D1)             |
| BUSY        | D9 (Configurable)   |
| VCC         | 5V                  |
| GND         | GND                 |

## Installation

1. Download this repository as a .zip file.
2. In the Arduino IDE, go to **Sketch -> Include Library -> Add .ZIP Library...**
3. Select the downloaded file.

## Basic Usage

#include <DFR1173.h>

// Instantiate passing the Serial object and the BUSY pin
DFR1173 mp3(Serial1, 9);

void setup() {
  Serial.begin(115200);
  mp3.begin(9600);
  mp3.setVolume(25);
}

void loop() {
  mp3.playTrack(1);
  mp3.isPlaying(); // Blocks execution until audio finishes
  delay(2000);
}
