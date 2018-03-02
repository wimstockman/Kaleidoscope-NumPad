#include "Kaleidoscope-NumPad.h"
#include "LEDUtils.h"
#include "Kaleidoscope.h"
#include "layers.h"

byte NumPad_::row = 255, NumPad_::col = 255;
uint8_t NumPad_::numPadLayer;
bool NumPad_::cleanupDone = true;
cRGB NumPad_::numpad_color;

void NumPad_::begin(void) {
  Kaleidoscope.useLoopHook(loopHook);
}

void NumPad_::loopHook(bool postClear) {
  if (!postClear)
    return;

  if (!Layer.isOn(numPadLayer)) {
    if (!cleanupDone) {
      LEDControl.set_mode(LEDControl.get_mode_index());
      cleanupDone = true;
    }
    return;
  }

  cleanupDone = false;
  bool numState = !!(kaleidoscope::hid::getKeyboardLEDs() & LED_NUM_LOCK);
  if (!numState) {
    kaleidoscope::hid::pressKey(Key_KeypadNumLock);
  }

  LEDControl.set_mode(LEDControl.get_mode_index());

  for (uint8_t r = 0; r < ROWS; r++) {
    for (uint8_t c = 0; c < COLS; c++) {
      Key k = Layer.lookupOnActiveLayer(r, c);
      Key layer_key = Layer.getKey(numPadLayer, r, c);

      if (k == LockLayer(numPadLayer)) {
        row  = r;
        col = c;
      }

      if ((k != layer_key) || (k.flags != KEY_FLAGS)) {
        LEDControl.refreshAt(r, c);
      } else {
        LEDControl.setCrgbAt(r, c, numpad_color);
      }
    }
  }

  if (row > ROWS || col > COLS)
    return;

cRGB color = breath_compute();
LEDControl.setCrgbAt(row, col, color);
}




  NumPad_ NumPad;



byte FuncPad_::row = 255, FuncPad_::col = 255;
uint8_t FuncPad_::FuncPadLayer;
bool FuncPad_::cleanupDone = true;
cRGB FuncPad_::Funcpad_color;

void FuncPad_::begin(void) {
  Kaleidoscope.useLoopHook(loopHook);
}

void FuncPad_::loopHook(bool postClear) {
  if (!postClear)
    return;

  if (!Layer.isOn(FuncPadLayer)) {
    if (!cleanupDone) {
      LEDControl.set_mode(LEDControl.get_mode_index());
      cleanupDone = true;
    }
    return;
  }

  cleanupDone = false;
  bool FuncState = !!(kaleidoscope::hid::getKeyboardLEDs() & LED_NUM_LOCK);
  if (!FuncState) {
    kaleidoscope::hid::pressKey(Key_KeypadNumLock);
  }

  LEDControl.set_mode(LEDControl.get_mode_index());

  for (uint8_t r = 0; r < ROWS; r++) {
    for (uint8_t c = 0; c < COLS; c++) {
      Key k = Layer.lookupOnActiveLayer(r, c);
      Key layer_key = Layer.getKey(FuncPadLayer, r, c);
        
      if (k == LockLayer(FuncPadLayer)) {
        row  = r;
        col = c;
      }
      if ((k != layer_key)) {    LEDControl.refreshAt(r, c);  } 
        else {
                        
                    //Added some nice colors for some specials keys
                     if(k == Key_UpArrow || k ==Key_LeftArrow || k == Key_DownArrow || k == Key_RightArrow  
                        || k == LCTRL(Key_Z) || k == LCTRL(Key_X) || k == LCTRL(Key_C) || k == LCTRL(Key_V)) { LEDControl.setCrgbAt(r, c, CRGB(0,200,0));}
                      else {  LEDControl.setCrgbAt(r, c, FuncPad_::Funcpad_color);
                      if  ( (k.flags & IS_CONSUMER)  == IS_CONSUMER) {LEDControl.setCrgbAt(r, c, CRGB(200,0,0));}
                      if  ( k == LSHIFT(Key_LeftControl)) {LEDControl.setCrgbAt(r, c, CRGB(255,255,255));}


                      }
              }
        }
  }

  if (row > ROWS || col > COLS)
    return;

}

FuncPad_ FuncPad;

