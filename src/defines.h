#pragma once

#define SCR_WIDTH   131 // display width
#define SCR_HEIGHT  175 // display height
#define SCR_COLUMS  16  // 8x8 text columns
#define SCR_LINES   22  // 8x8 text lines
//#define SCR_COLOR   0x0000  // back screen color
#define SCR_DOWN    167 //bottom of the screen. used in the game so as not to overwrite points and lives
#define LEFT        0	// for LEFT
#define RIGHT       1	// for RIGHT
#define UP          0	// for UP
#define DOWN        1	// for 

#define COLOR_MENU_BOTTOM_PAPER           0xD6BA  //  ZX_WHITE
#define COLOR_MENU_BOTTOM_INK             0x0000  //  ZX_BLACK
#define COLOR_MENU_TOP_PAPER                0x0000  //  ZX_BLACK
#define COLOR_MENU_TOP_INACTIVE_LINE_INK    0x0000  //  ZX_BLACK
#define COLOR_MENU_TOP_ACTIVE_LINE_INK      0xFFFF  //  ZX_WHITE_BR
#define COLOR_MENU_LINE_INK                 0x0000  //  ZX_BLACK
#define COLOR_MENU_INACTIVE_LINE_PAPER      0xFFFF  //  ZX_WHITE
#define COLOR_MENU_ACTIVE_LINE_PAPER        0x07FF  //  ZX_CYAN_BR
#define COLOR_LOGO_0    0x0000  //  ZX_BLACK
#define COLOR_LOGO_1    0xF800  //  ZX_RED_BR
#define COLOR_LOGO_2    0xFFE0  //  ZX_YELLOW_BR
#define COLOR_LOGO_3    0x07E0  //  ZX_GREEN_BR
#define COLOR_LOGO_4    0x07FF  //  ZX_CYAN_BR

#define LINE_TYPE_TOP       0
#define LINE_TYPE_MENU      1
#define LINE_TYPE_BOTTOM    2

#define MENU_LINES_NUMBER 20

#define PIN_BAT     35  // pin for ADC read voltage from BAT
#define PIN_BTN_A   25  // pin for btn left (pull up)
#define PIN_BTN_B   26  // pin for btn right (pull up)
#define PIN_BTN_ANALOG  12  // pin for 3 analog btns (1-4095, 2-2700, 3-2000, NC-0)

#define PIN_RES_LEFT_X  32  // pin for left horisontal resistor
#define PIN_RES_LEFT_Y  34  // pin for left vertical resistor
#define PIN_RES_RIGHT_X 27  // pin for right horisontal resistor
#define PIN_RES_RIGHT_Y 33  // pin for right vertical resistor

#define RES_MAP_MIN     0
#define RES_MAP_MAX     131 // == display width
#define RES_CENTRE_ZONE 10

#define BTN_ANALOG_0_1_BORDER   1000    // 0-2000
#define BTN_ANALOG_1_2_BORDER   2350    // 2000-2700
#define BTN_ANALOG_2_3_BORDER   3400    // 2700-4095

#define BTN_ANALOG_PRESSED_NO_ONE   0   //no analog btn pressed
#define BTN_ANALOG_PRESSED_ESCAPE   1   //escape analog btn pressed
#define BTN_ANALOG_PRESSED_SELECT   2   //select analog btn pressed
#define BTN_ANALOG_PRESSED_START    3   //start analog btn pressed

#define BTN_DIGITAL_PRESSED_NO_ONE  0   // no pressed btns

#define ON          1   // for ON
#define OFF         0   // for OFF

#define MODE_START   0
#define MODE_MENU    1

