#pragma once

class MESSAGE_LINE{
    public:
        void Set(uint8_t line){
            _line = line;
        }
        void Show_const_message(uint8_t str_namber, uint16_t color, bool inverse){
            _str_namber = str_namber;
            _inverse = inverse;
            _color = color;
            if(_inverse==true){
                _color_ink = SCR_COLOR;
                _color_paper = _color;
            }
            if(_inverse==false){
                _color_ink = _color;
                _color_paper = SCR_COLOR;
            }
            strcpy_P(text_buffer, (char*)(str_table[_str_namber]));
            Show();
        }
        void Show_text(char *text, uint16_t color, bool inverse){
            strcpy(text_buffer, (char*)text);
            _inverse = inverse;
            _color = color;
            if(_inverse==true){
                _color_ink = SCR_COLOR;
                _color_paper = _color;
            }
            if(_inverse==false){
                _color_ink = _color;
                _color_paper = SCR_COLOR;
            }
            Show();
        }
        void Show(){
            LCD_Puts(text_buffer, 0, 8*_line, _color_ink, _color_paper, 1, 1, 0);
            Serial.printf(text_buffer);
        }
        void Inverse(){
            _color_buffer = _color_ink;
            _color_ink = _color_paper;
            _color_paper = _color_buffer;
            Show();
        }
        void Hide(){
            _color_ink = SCR_COLOR;
            _color_paper = SCR_COLOR;
            Show();
        }
    private:
        char text_buffer[16];
        bool _inverse;
        uint8_t _str_namber;
        uint8_t _line;
        uint16_t _color;
        uint16_t _color_ink;
        uint16_t _color_paper;
        uint16_t _color_buffer;
        bool _state;
    

};

