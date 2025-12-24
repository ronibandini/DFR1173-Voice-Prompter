#ifndef DFR1173_h
#define DFR1173_h

#include "Arduino.h"

class DFR1173 {
  public:
    DFR1173(HardwareSerial& serial, int busyPin);
    void begin(unsigned long baud = 9600);
    void playTrack(uint8_t track_number);
    void nextTrack();
    void previousTrack();
    void pausePlayback();
    void resumePlayback();
    void stopPlayback();
    void setVolume(uint8_t level);
    void increaseVolume();
    void decreaseVolume();
    void repeatPlayback(uint8_t track_number);
    void randomPlayback();
    void playSpecificFolder(uint8_t folder_number, uint8_t file_number);
    void compositePlayback(uint8_t file_sequence[], size_t length);
    void resetModule();
    void enterLowPowerMode();
    void isPlaying();

  private:
    HardwareSerial* _serial;
    int _busyPin;
    void sendCommand(uint8_t command[], size_t length);
};

#endif
