#include <Arduino.h>
#include "defines.h"
#include "variables.h"
#include "LPH91572.h"
#include "ANALOG_STICK.h"
#include "ANALOG_BATTON.h"
#include "DIGITAL_BATTON.h"
#include "SD_MMC_FS_functions.h"
#include "MESSAGE_LINE.h"
#include "MENU.h"

void setup(){
    mode = MODE_START;
    pinMode(2, INPUT_PULLUP); //for SD CARD
    Serial.begin(115200);
    LCD_init();
    LCD_FillScreen(BLACK);

    if(!SD_MMC.begin("/sdcard",true)){
        Serial.printf("SD Mount Failed");
        LCD_Puts_Shadow((char*)"SD Mount Failed", 0, 0, RED, 0, 0, 0);
        return;
    }
    uint8_t cardType = SD_MMC.cardType();

    if(cardType == CARD_NONE){
        Serial.printf("No SD_MMC card");
        LCD_Puts_Shadow((char*)"No SD_MMC card", 0, 0, RED, 0, 0, 0);
        return;
    }

    Serial.printf("SD_MMC Card Type: ");
    LCD_Puts_Shadow((char*)"SD_MMC: ", 0, 0, GREEN, 0, 0, 0);

    if(cardType == CARD_MMC){
        Serial.printf("MMC");
        LCD_Puts_Shadow((char*)"MMC", 64, 0, GREEN, 0, 0, 0);
    } else if(cardType == CARD_SD){
        Serial.printf("SDSC");
        LCD_Puts_Shadow((char*)"SDSC", 64, 0, GREEN, 0, 0, 0);
    } else if(cardType == CARD_SDHC){
        Serial.printf("SDHC");
        LCD_Puts_Shadow((char*)"SDHC", 64, 0, GREEN, 0, 0, 0);
    } else {
        Serial.printf("UNKNOWN");
        LCD_Puts_Shadow((char*)"UNKNOWN", 64, 0, GREEN, 0, 0, 0);
    }

    uint64_t cardSize = SD_MMC.cardSize() / (1024 * 1024);
    Serial.printf("\nSD_MMC Card Size: %lluMB\n", cardSize);
    LCD_Puts_Shadow((char*)"Size(Mb): ", 0, 8, GREEN, 0, 0, 0);
    LCD_Puts_Shadow(ultoa(cardSize, buffer, 10), 80, 8, GREEN, 0, 0, 0);
    LCD_Puts_Shadow((char*)"Русский язык", 0, 16, GREEN, 0, 0, 0);
    Serial.printf("Total space: %lluMB\n", SD_MMC.totalBytes() / (1024 * 1024));
    Serial.printf("Used space: %lluMB\n", SD_MMC.usedBytes() / (1024 * 1024));
    delay(3000);
    LCD_FillScreen(BLACK);
    mode = MODE_MENU;
}

void loop() {

}