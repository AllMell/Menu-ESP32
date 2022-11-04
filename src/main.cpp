#include <Arduino.h>
#include "defines.h"
#include "variables.h"
#include "LPH91572.h"
#include "ANALOG_STICK.h"
#include "ANALOG_BATTON.h"
#include "DIGITAL_BATTON.h"
#include "SD_MMC_FS_functions.h"

void setup(){
    delay(1000);
    pinMode(2, INPUT_PULLUP); //for SD CARD
    Serial.begin(115200);
    LCD_init();
    LCD_FillScreen(BLACK);

    uint16_t* framebuffer = (uint16_t*)heap_caps_malloc(132 * 176 * sizeof(uint16_t), MALLOC_CAP_DMA);
    memset(framebuffer, 0, 132 * 176 * sizeof(uint8_t));
    Serial.println();
    Serial.printf("Total heap: %dB\n", ESP.getHeapSize());
    Serial.printf("Free heap: %dB\n", ESP.getFreeHeap());
    Serial.printf("Total PSRAM: %dB\n", ESP.getPsramSize());
    Serial.printf("Free PSRAM: %dB\n", ESP.getFreePsram());

    logMemory();
    byte* psdRamBuffer = (byte*)ps_malloc(500000);
    logMemory();

    free(psdRamBuffer);
    logMemory();

    if(!SD_MMC.begin("/sdcard",true)){
        Serial.printf("Card Mount Failed");
        return;
    }
    uint8_t cardType = SD_MMC.cardType();

    if(cardType == CARD_NONE){
        Serial.printf("No SD_MMC card attached");
        return;
    }

    Serial.printf("SD_MMC Card Type: ");
    if(cardType == CARD_MMC){
        Serial.printf("MMC");
    } else if(cardType == CARD_SD){
        Serial.printf("SDSC");
    } else if(cardType == CARD_SDHC){
        Serial.printf("SDHC");
    } else {
        Serial.printf("UNKNOWN");
    }

    uint64_t cardSize = SD_MMC.cardSize() / (1024 * 1024);
    Serial.printf("\nSD_MMC Card Size: %lluMB\n", cardSize);

    listDir(SD_MMC, "/", 0);
    createDir(SD_MMC, "/mydir");
    listDir(SD_MMC, "/", 0);
    removeDir(SD_MMC, "/mydir");
    listDir(SD_MMC, "/", 2);
    writeFile(SD_MMC, "/hello.txt", "Hello ");
    appendFile(SD_MMC, "/hello.txt", "World!\n");
    readFile(SD_MMC, "/hello.txt");
    deleteFile(SD_MMC, "/foo.txt");
    renameFile(SD_MMC, "/hello.txt", "/foo.txt");
    readFile(SD_MMC, "/foo.txt");
    testFileIO(SD_MMC, "/test.txt");
    Serial.printf("Total space: %lluMB\n", SD_MMC.totalBytes() / (1024 * 1024));
    Serial.printf("Used space: %lluMB\n", SD_MMC.usedBytes() / (1024 * 1024));
    LCD_Puts("OK",0,0,0xffff,0x0000,0,0,0);
}

void loop() {
  
}