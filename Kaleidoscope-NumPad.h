#pragma once

#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-Macros.h"
#include "LEDUtils.h"

class NumPad_ : public KaleidoscopePlugin {
 public:
  NumPad_(void) {}


  static void ledeffectlayer1(uint8_t r,uint8_t c,Key k);
  static void ledeffectlayer2(uint8_t r,uint8_t c,Key k);
  static void ledeffectlayer3(uint8_t r,uint8_t c,Key k);
  static void ledeffectlayer4(uint8_t r,uint8_t c,Key k);
  static void ledeffectlayer5(uint8_t r,uint8_t c,Key k);
  static void ledeffectlayer6(uint8_t r,uint8_t c,Key k);
  static void ledeffectlayer7(uint8_t r,uint8_t c,Key k);
  static void ledeffectlayer8(uint8_t r,uint8_t c,Key k);
  static void ledeffectlayer9(uint8_t r,uint8_t c,Key k);
  void begin(void) final;

  static uint8_t numPadLayer;
  static cRGB numpad_color;
  static uint8_t ActiveLayer;

 private:
  static void loopHook(const bool postClear);

  static byte row, col;
  static bool cleanupDone;
};


extern NumPad_ NumPad;

