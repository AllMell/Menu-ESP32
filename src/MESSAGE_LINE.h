#pragma once

class MESSAGE_LINE{
    public:
        MESSAGE_LINE(){
            _line_y = 0; _line_x = 0; _line_len = 16; _color_ink = ZX_BLACK; _color_paper = ZX_WHITE_BR; _font = SYMBOLS;
        }
        MESSAGE_LINE(uint8_t line_y, uint8_t line_x, uint8_t line_len, uint16_t color_ink, uint16_t color_paper, uint8_t font){
            _line_y = line_y; _line_x = line_x; _line_len = line_len; _color_ink = color_ink; _color_paper = color_paper; _font = font;
        }
        void Set(uint8_t line_y, uint8_t line_x, uint8_t line_len, uint16_t color_ink, uint16_t color_paper, uint8_t font){
            _line_y = line_y; _line_x = line_x; _line_len = line_len; _color_ink = color_ink; _color_paper = color_paper; _font = font;
        }
        void Show_const_message(uint8_t str_namber){
            _str_namber = str_namber;            
            strcpy_P(_text_buffer, (char*)(str_table[_str_namber]));
            Show();
        }
        void Show_text(char *text){
            strcpy(_text_buffer, (char*)text);
            Show();
        }
        void Show(){
                _system_font_bufer = LCD_get_font();
                LCD_set_font(_font);
                LCD_Puts(_text_buffer, 8*_line_x, 8*_line_y, _color_ink, _color_paper, 1, 1, 0);
                Serial.print("Message show: ");Serial.println(_text_buffer);
                LCD_set_font(_system_font_bufer);
        }
        void Hide(){
                _system_font_bufer = LCD_get_font();
                LCD_set_font(_font);
                LCD_Puts(_text_buffer, 8*_line_x, 8*_line_y, _color_paper, _color_paper, 1, 1, 0);
                Serial.print("Message hide: "); Serial.println(_text_buffer);
                LCD_set_font(_system_font_bufer);
        }
        
        ~MESSAGE_LINE(){
            Show_const_message(3);
        };

    private:
        void Len_up(){

        }
        uint8_t _line_y;
        uint8_t _line_x;
        uint8_t _line_len;
        uint16_t _color_ink;
        uint16_t _color_paper;
        uint8_t _font;
        uint8_t _system_font_bufer;
        char _text_buffer[18];
        uint8_t _str_namber;
};

