/* 
 * File:   main.c
 * Author: 
 * Diogo Agenor Marchi 
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
        
    write_char(lcd, 'D');
    write_char(lcd, 'I');
    write_char(lcd, 'O');
    write_char(lcd, 'G');
    write_char(lcd, 'O');
    write_char(lcd, ' ');
    write_char(lcd, 'M');
    write_char(lcd, 'A');
    write_char(lcd, 'R');
    write_char(lcd, 'C');
    write_char(lcd, 'H');
    write_char(lcd, 'I');
    
    goto_XY(lcd, 2, 4);
    write_char(lcd, 'G');
    write_char(lcd, 'E');
    write_char(lcd, 'O');
    write_char(lcd, 'R');
    write_char(lcd, 'G');
    write_char(lcd, 'E');
    write_char(lcd, ' ');
    write_char(lcd, 'D');
    write_char(lcd, 'E');
    write_char(lcd, ' ');
    write_char(lcd, 'B');
    write_char(lcd, 'O');
    write_char(lcd, 'R');
    write_char(lcd, 'B');
    write_char(lcd, 'A');
    
    
    
    

        
    while(1){
        
    }
    
}
