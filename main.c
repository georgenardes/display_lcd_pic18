/* 
 * File:   main.c
 * Author: 
 * Diogo Marchi Agenor
 * George de Borba Nardes
 *          
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
        
    lcd = &PORTD;
            
    function_set(lcd, 0, 1, 0);
    display_onoff_control(lcd, 1, 1, 0);
    entry_mode_set(lcd, 1,0);
    goto_XY(lcd, 1, 1);
        
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
    
    goto_XY(lcd, 2, 4);
    write_char(lcd, 'A');
    write_char(lcd, 'E');
    write_char(lcd, ' ');
    write_char(lcd, 'F');
    write_char(lcd, 'D');
    write_char(lcd, 'P');

        
    while(1){
        
    }
    
}
