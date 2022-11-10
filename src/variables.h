#pragma once

uint8_t mode;

char buffer[17];//for messages
const char str_0[] = "                 "; // 16 spaces
const char str_1[] = "River Raid.tap";
const char str_2[] = "RESTART";
const char str_3[] = "DELETE OBJ";
const char str_4[] = "";
const char str_5[] = "";
const char str_6[] = "";
const char str_7[] = "";
const char str_8[] = "";
const char str_9[] = "";
const char str_10[] = "";
const char str_11[] = "";
const char str_12[] = "";
const char str_13[] = "";
const char str_14[] = "";
const char* const str_table[] = {str_0, str_1, str_2, str_3, str_4, str_5, str_6, str_7, str_8, str_9, str_10, str_11, str_12, str_13, str_14};

struct Files_Struct{
    char file_name[64];
    char file_type[6];
    uint16_t position_in_dir;   
};

struct Position_Struct{
    uint8_t position_in_dir = 0;
    uint8_t position_in_dir_old =1;
    uint8_t position_on_page = 0;
    uint8_t position_on_page_old = 1;
    uint8_t current_page = 0;
    uint8_t current_page_old = 1;
    uint16_t patf_stack_point = 0;
    uint16_t patf_stack[64];
    char patf[30] = "Hellow";
    String str = "QWERTY";
};

const uint16_t logo[5][2]= {{ZX_BLACK, ZX_RED_BR},
                            {ZX_RED_BR, ZX_YELLOW_BR},
                            {ZX_YELLOW_BR, ZX_GREEN_BR},
                            {ZX_GREEN_BR, ZX_CYAN_BR},
                            {ZX_CYAN_BR, ZX_BLACK}};



//Position_Struct* CP_pointer = &Current_position;
//Position_Struct Current_position;

