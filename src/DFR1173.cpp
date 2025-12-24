#include "DFR1173.h"

DFR1173::DFR1173(HardwareSerial& serial, int busyPin) {
  _serial = &serial;
  _busyPin = busyPin;
}

void DFR1173::begin(unsigned long baud) {
  pinMode(_busyPin, INPUT_PULLUP);
  _serial->begin(baud);
}

void DFR1173::sendCommand(uint8_t command[], size_t length) {
  for (size_t i = 0; i < length; i++) {
    _serial->write(command[i]);
  }
}

void DFR1173::playTrack(uint8_t track_number) {
  uint8_t command[] = {0x7E, 0x03, 0x00, 0x02, 0x00, track_number, 0xEF};
  sendCommand(command, sizeof(command));
}

void DFR1173::nextTrack() {
  uint8_t command[] = {0x7E, 0x01, 0x00, 0x02, 0x00, 0x00, 0xEF};
  sendCommand(command, sizeof(command));
}

void DFR1173::previousTrack() {
  uint8_t command[] = {0x7E, 0x02, 0x00, 0x02, 0x00, 0x00, 0xEF};
  sendCommand(command, sizeof(command));
}

void DFR1173::pausePlayback() {
  uint8_t command[] = {0x7E, 0x0E, 0x00, 0x02, 0x00, 0x00, 0xEF};
  sendCommand(command, sizeof(command));
}

void DFR1173::resumePlayback() {
  uint8_t command[] = {0x7E, 0x0D, 0x00, 0x02, 0x00, 0x00, 0xEF};
  sendCommand(command, sizeof(command));
}

void DFR1173::stopPlayback() {
  uint8_t command[] = {0x7E, 0x16, 0x00, 0x02, 0x00, 0x00, 0xEF};
  sendCommand(command, sizeof(command));
}

void DFR1173::setVolume(uint8_t level) {
  if (level > 30) return;
  uint8_t command[] = {0x7E, 0x06, 0x00, 0x02, 0x00, level, 0xEF};
  sendCommand(command, sizeof(command));
}

void DFR1173::increaseVolume() {
  uint8_t command[] = {0x7E, 0x04, 0x00, 0x02, 0x00, 0x00, 0xEF};
  sendCommand(command, sizeof(command));
}

void DFR1173::decreaseVolume() {
  uint8_t command[] = {0x7E, 0x05, 0x00, 0x02, 0x00, 0x00, 0xEF};
  sendCommand(command, sizeof(command));
}

void DFR1173::repeatPlayback(uint8_t track_number) {
  uint8_t command[] = {0x7E, 0x08, 0x00, 0x02, 0x00, track_number, 0xEF};
  sendCommand(command, sizeof(command));
}

void DFR1173::randomPlayback() {
  uint8_t command[] = {0x7E, 0x18, 0x00, 0x02, 0x00, 0x00, 0xEF};
  sendCommand(command, sizeof(command));
}

void DFR1173::playSpecificFolder(uint8_t folder_number, uint8_t file_number) {
  uint8_t command[] = {0x7E, 0x0F, 0x00, 0x02, folder_number, file_number, 0xEF};
  sendCommand(command, sizeof(command));
}

void DFR1173::compositePlayback(uint8_t file_sequence[], size_t length) {
  uint8_t command[4 + length + 1]; 
  command[0] = 0x7E;
  command[1] = 0x21;
  command[2] = 0x00;
  command[3] = length;
  for (size_t i = 0; i < length; i++) {
    command[4 + i] = file_sequence[i];
  }
  command[4 + length] = 0xEF;
  sendCommand(command, 4 + length + 1);
}

void DFR1173::resetModule() {
  uint8_t command[] = {0x7E, 0x0C, 0x00, 0x02, 0x00, 0x00, 0xEF};
  sendCommand(command, sizeof(command));
}

void DFR1173::enterLowPowerMode() {
  uint8_t command[] = {0x7E, 0x0A, 0x00, 0x02, 0x00, 0x01, 0xEF};
  sendCommand(command, sizeof(command));
}

void DFR1173::isPlaying() {
  delay(300); 
  while (digitalRead(_busyPin) == LOW) {
    delay(100); 
  }
}
