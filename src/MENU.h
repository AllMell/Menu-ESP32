#pragma once

class MENU{
    public:
        MENU(){
            _menu_x = 0; _menu_width = 17; _menu_y = 1; _menu_height = 20; _font = SYMBOLS; _menu_color_ink = ZX_BLACK; _menu_color_paper = ZX_WHITE_BR; uint16_t _menu_color_select_paper = ZX_CYAN_BR;
        }
        MENU(uint8_t menu_x, uint8_t menu_width, uint8_t menu_y, uint8_t menu_height, uint8_t font, uint16_t menu_color_ink, uint16_t menu_color_paper, uint16_t menu_color_select_paper)
        {
            _menu_x = menu_x; _menu_width = menu_width; _menu_y = menu_y; _menu_height = menu_height; _font = font; _menu_color_ink = menu_color_ink; _menu_color_paper = menu_color_paper; _menu_color_select_paper = menu_color_select_paper;
        }
        void Set(uint8_t menu_x, uint8_t menu_width, uint8_t menu_y, uint8_t menu_height, uint8_t font, uint16_t menu_color_ink, uint16_t menu_color_paper, uint16_t menu_color_select_paper)
        {
            _menu_x = menu_x; _menu_width = menu_width; _menu_y = menu_y; _menu_height = menu_height; _font = font; _menu_color_ink = menu_color_ink; _menu_color_paper = menu_color_paper; _menu_color_select_paper = menu_color_select_paper;
        }
        
        void Show_menu(){
            for (int i = _menu_y; i < _menu_height; i++) {
                Show_line(i);
            }
            Show_select_line();
        }

        void Update(){

        }

        ~MENU(){
            free (Files_table);
        }
    private:

        void Show_line(uint8_t line_namber){
                Set_menu_font();
                LCD_Puts(Files_table->file_name, 8*_menu_x, 8*(_menu_y + line_namber), _menu_color_ink, _menu_color_paper, 1, 1, 0);
                Serial.print("Menu line show: ");Serial.println(Files_table->file_name);
                Set_system_font();
        }
        void Hide_line(uint8_t line_namber){
                Set_menu_font();
                LCD_Puts(Files_table->file_name, 8*_menu_x, 8*(_menu_y + line_namber), _menu_color_paper, _menu_color_paper, 1, 1, 0);
                Serial.print("Menu line hide: "); Serial.println(Files_table->file_name);
                Set_system_font();
        }

        void Show_select_line(){
                Set_menu_font();
                Serial.print("Menu select line show: ");Serial.println(Files_table->file_name);
                Set_system_font();
        }

        void Set_menu_font(){
            _system_font_bufer = LCD_get_font();
            LCD_set_font(_font);
        }

        void Set_system_font(){
            LCD_set_font(_system_font_bufer);
        }
        uint8_t _menu_x;
        uint8_t _menu_width;
        uint8_t _menu_y;
        uint8_t _menu_height;
        uint8_t _font;
        uint8_t _system_font_bufer;
        uint16_t _menu_color_ink;
        uint16_t _menu_color_paper;
        uint16_t _menu_color_select_paper;
        
        
};

//for (int i = 0; i < _menu_height; i++) {
                                
//}