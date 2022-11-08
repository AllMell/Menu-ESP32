#include <Arduino.h>
#include "LPH91572.h"
#include "defines.h"
#include "variables.h"
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
    LCD_set_font(SYMBOLS);
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
    //delay(2000);
    LCD_FillScreen(ZX_WHITE);
    mode = MODE_MENU;

    Serial.println("----0----");
    Serial.printf("Total heap : %dB\n", ESP.getHeapSize());
    Serial.printf("Free heap  : %dB\n", ESP.getFreeHeap());
    Serial.printf("Total PSRAM: %dB\n", ESP.getPsramSize());
    Serial.printf("Free PSRAM : %dB\n", ESP.getFreePsram());


MENU Menu1;

    Serial.println("----1----");
    Serial.printf("Total heap : %dB\n", ESP.getHeapSize());
    Serial.printf("Free heap  : %dB\n", ESP.getFreeHeap());
    Serial.printf("Total PSRAM: %dB\n", ESP.getPsramSize());
    Serial.printf("Free PSRAM : %dB\n", ESP.getFreePsram());

MENU *Menu2 = (MENU*)ps_malloc(sizeof(MENU));

    Serial.println("----2----");
    Serial.printf("Total heap : %dB\n", ESP.getHeapSize());
    Serial.printf("Free heap  : %dB\n", ESP.getFreeHeap());
    Serial.printf("Total PSRAM: %dB\n", ESP.getPsramSize());
    Serial.printf("Free PSRAM : %dB\n", ESP.getFreePsram());



//test_message.Show_const_message(1);

//test_message.Hide();


char str[10];
Serial.print("Files_table size: "); Serial.println(ultoa(MENU_LINES_NUMBER * sizeof(Files_Struct),str,10));

uint32_t chipId = 0;

for(int i=0; i<17; i=i+8) {
	chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
}

Serial.printf("ESP32 Chip model = %s Rev %d\n", ESP.getChipModel(), ESP.getChipRevision());
Serial.printf("This chip has %d cores\n", ESP.getChipCores());
Serial.print("Chip ID: "); Serial.println(chipId);
  
//test_message.~MESSAGE_LINE();




Position_Struct* Current_position = (Position_Struct*)malloc(sizeof(Position_Struct));

//struct Position_Struct *P_Current_position;
//CP_pointer = &Current_position;

Current_position->patf_stack[5] = 10;
Current_position->patf_stack[33] = 119;
uint8_t test1 = Current_position->patf_stack[5];
uint8_t test2 = Current_position->patf_stack[33];
Serial.println(Current_position->patf_stack[5]);
Serial.println(Current_position->patf_stack[33]);
Serial.printf("%d \n", test1);
Serial.printf("%d \n", test2);

strcat(Current_position->patf, "12345");
strcat(Current_position->patf, "67890");
strcat(Current_position->patf, "ABCDEFGHIJ");
Serial.println(Current_position->patf);
Serial.printf(Current_position->patf);

String Str = Current_position->str;
Current_position->str = Current_position->str + "AAAAA";
Current_position->str = Current_position->str + "BBBBB";
Serial.println();
Serial.println(Current_position->str);
Serial.println(Str);

MESSAGE_LINE test_message(0, 0, 16, 17, ZX_CYAN_BR, BLACK, SYMBOLS_BOLD);
MESSAGE_LINE test_message2(1, 0, 16, 17, ZX_GREEN_BR, BLACK, SYMBOLS_BOLD);
MESSAGE_LINE test_message3(2, 0, 16, 17, ZX_YELLOW_BR, BLACK, SYMBOLS_BOLD);
MESSAGE_LINE test_message4(3, 0, 16, 17, ZX_BLUE_BR, BLACK, SYMBOLS_BOLD);

test_message.Show_text((char*)"1234567890");
test_message2.Show_text((char*)Current_position->patf);
test_message3.Show_text((char*)"1234567890123456");
test_message4.Show_const_message(1);
    
    Serial.println("----3----");
    Serial.printf("Total heap : %dB\n", ESP.getHeapSize());
    Serial.printf("Free heap  : %dB\n", ESP.getFreeHeap());
    Serial.printf("Total PSRAM: %dB\n", ESP.getPsramSize());
    Serial.printf("Free PSRAM : %dB\n", ESP.getFreePsram());
}

void loop() {



}