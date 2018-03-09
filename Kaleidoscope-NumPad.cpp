#include "Kaleidoscope-NumPad.h"
#include "LEDUtils.h"
#include "Kaleidoscope.h"
#include "layers.h"

byte NumPad_::row = 255, NumPad_::col = 255;
uint8_t NumPad_::numPadLayer;
bool NumPad_::cleanupDone = true;
cRGB NumPad_::numpad_color;
uint8_t NumPad_::ActiveLayer;

void  NumPad_::ledeffectlayer1(uint8_t r,uint8_t c,Key k  ){
	LEDControl.setCrgbAt(r, c,  CRGB(0,200,0));
}

void  NumPad_::ledeffectlayer2(uint8_t r,uint8_t c, Key k ){
 //Added some nice colors for some specials keys
                     if(k == Key_UpArrow || k ==Key_LeftArrow || k == Key_DownArrow || k == Key_RightArrow  
                        || k == LCTRL(Key_Z) || k == LCTRL(Key_X) || k == LCTRL(Key_C) || k == LCTRL(Key_V)) { LEDControl.setCrgbAt(r, c, CRGB(0,200,0));}
                      else {  LEDControl.setCrgbAt(r, c,  CRGB(0,0,200));
                      if  ( (k.flags & IS_CONSUMER)  == IS_CONSUMER) {LEDControl.setCrgbAt(r, c, CRGB(200,0,0));}
                      if  ( k == LSHIFT(Key_LeftControl)) {LEDControl.setCrgbAt(r, c, CRGB(255,255,255));}


                      }
}

void  NumPad_::ledeffectlayer3(uint8_t r,uint8_t c ,Key k ){

	LEDControl.setCrgbAt(r, c,  CRGB(180,0,0));
}

void NumPad_::begin(void) {
  Kaleidoscope.useLoopHook(loopHook);
}
void NumPad_::loopHook(bool postClear) {
  if (!postClear)
    return;

  ActiveLayer =	Layer.top();
   if (ActiveLayer ==0	){
    if (!cleanupDone) {
      LEDControl.set_mode(LEDControl.get_mode_index());
      cleanupDone = true;
    }
    return;
  }


  cleanupDone = false;
  LEDControl.set_mode(LEDControl.get_mode_index());
  Serial.println(ActiveLayer);
  for (uint8_t r = 0; r < ROWS; r++) {
    for (uint8_t c = 0; c < COLS; c++) {
      Key k = Layer.lookupOnActiveLayer(r, c);
      Key layer_key = Layer.getKey(ActiveLayer, r, c);

      if (k == LockLayer(ActiveLayer)) {
        row  = r;
        col = c;
      }

      if (k != layer_key)  { LEDControl.refreshAt(r, c); }
		else {
       		switch(ActiveLayer)
				{
			case 1:	ledeffectlayer1(r,c,k);
						break;
			case 2:	ledeffectlayer2(r,c,k);
						break;

			case 3:	ledeffectlayer3(r,c,k);
						break;
				}
      		 }
    	}
  }

  if (row > ROWS || col > COLS)
    return;

}




  NumPad_ NumPad;




