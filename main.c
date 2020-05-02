/*
 * File:   main.c
 * Author: George
 *
 * Created on 1 de Maio de 2020, 08:57
 */


#include <xc.h>
#include "config.h"
#include "lcd_hd_44780.h"

t_display_port *lcd;

void main(void) {
    ADCON1 = 0x0F;
    TRISD = 0x0;
    
    init_lcd(lcd, &PORTD);
            
    function_set(lcd, 0, 0, 0);
    display_onoff_control(lcd, 1, 1, 0);
    entry_mode_set(lcd, 1,0);
        
    write_char(lcd, 'H');
    write_char(lcd, 'E');
    write_char(lcd, 'L');
    write_char(lcd, 'L');
    write_char(lcd, 'O');
    write_char(lcd, ' ');
    write_char(lcd, 'W');
    write_char(lcd, 'O');
    write_char(lcd, 'R');
    write_char(lcd, 'L');
    write_char(lcd, 'D');
        
    while(1){
        
    }
    
}
