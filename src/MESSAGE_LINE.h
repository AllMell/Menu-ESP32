#pragma once

class MESSAGE_LINE{
    public:
        void Setup(uint8_t line_namber, uint8_t line_type){
            _line_namber = line_namber; _line_type = line_type; _active = OFF; _enable = ON;
            switch (_line_type){
                case LINE_TYPE_TOP:
                        _color_active_ink = ZX_YELLOW_BR;
                        _color_active_paper = ZX_BLACK;
                        _color_inactive_ink = ZX_BLACK;
                        _color_inactive_paper = ZX_BLACK;
                    break;
                case LINE_TYPE_MENU:
                        _color_active_ink = ZX_BLACK;
                        _color_active_paper = ZX_CYAN_BR;
                        _color_inactive_ink = ZX_WHITE_BR;
                        _color_inactive_paper = ZX_WHITE_BR;
                    break;
                case LINE_TYPE_BOTTOM:
                        _color_active_ink = ZX_BLACK;
                        _color_active_paper = ZX_WHITE;
                        _color_inactive_ink = ZX_BLACK;
                        _color_inactive_paper = ZX_WHITE;
                    break;
                default:
                    break;
            }
        }
        void Set_const_message(uint8_t str_namber){
            _str_namber = str_namber;            
            strcpy_P(text_buffer, (char*)(str_table[_str_namber]));   
        }
        void Set_text(char *text){
            strcpy(text_buffer, (char*)text);
        }
        bool Show(){
            if(_enable){
                LCD_Puts(text_buffer, 0, 8*_line_namber, _color_out_ink, _color_out_paper, 1, 1, 0);
                Serial.printf(text_buffer);
                return _enable;
            }
        }
        
        void Activate(){
            _active = ON;
            _Update();
        }
        void Deactivate(){
            _active = OFF;
            _Update();
        }
        void Enable(){
            _enable = ON;
            _Update();
        }
        void Disable(){
            _enable = OFF;
            _Update();
        }
    private:
        void _Update(){
            if(_enable){
                if(_active){
                    _color_out_ink = _color_active_ink;
                    _color_out_paper = _color_active_paper;
                } else {
                    _color_out_ink = _color_inactive_ink;
                    _color_out_paper = _color_inactive_paper;
                }
            } else {
                _color_out_ink = _color_inactive_paper;
                _color_out_paper = _color_inactive_paper;
            }
        }

        bool _active;
        bool _enable;
        char text_buffer[16];
        uint8_t _str_namber;
        uint8_t _line_namber;
        uint8_t _line_type;
        uint16_t _color_active_ink;
        uint16_t _color_active_paper;
        uint16_t _color_inactive_ink;
        uint16_t _color_inactive_paper;
        uint16_t _color_out_ink;
        uint16_t _color_out_paper;
    

};

