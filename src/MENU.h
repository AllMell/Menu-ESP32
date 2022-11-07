#pragma once

class MENU{
    public:
        MENU(){
            _menu_x = 0; _menu_width = 17; _menu_y = 1; _menu_height = 20; 
            _menu_color_ink = ZX_BLACK; _menu_color_paper = ZX_WHITE_BR; uint16_t _menu_color_select_paper = ZX_CYAN_BR;
        }
        MENU(uint8_t menu_x, uint8_t menu_width, uint8_t menu_y, uint8_t menu_height,
        uint16_t menu_color_ink, uint16_t menu_color_paper, uint16_t menu_color_select_paper)
        {
            _menu_x = menu_x; 
            _menu_width = menu_width; 
            _menu_y = menu_y; 
            _menu_height = menu_height;
        }
        void Set(uint8_t menu_x, uint8_t menu_width, uint8_t menu_y, uint8_t menu_height, 
        uint16_t menu_color_ink, uint16_t menu_color_paper, uint16_t menu_color_select_paper)
        {
            _menu_x = menu_x; 
            _menu_width = menu_width;
            _menu_y = menu_y;
            _menu_height = menu_height; 
            _menu_color_ink = menu_color_ink; 
            _menu_color_paper = menu_color_paper; 
            _menu_color_select_paper = menu_color_select_paper;
        }
        
        
    private:
        uint8_t _menu_x;
        uint8_t _menu_width;
        uint8_t _menu_y;
        uint8_t _menu_height;
        uint16_t _menu_color_ink;
        uint16_t _menu_color_paper;
        uint16_t _menu_color_select_paper;
        
};

for (int i = 0; i < _menu_height; i++) {
                                
}