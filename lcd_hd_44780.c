#include "lcd_hd_44780.h"




void function_set(t_display_port *lcd, char data_lenght, 
        char num_lines, char char_font){        
    lcd->E = 0;
    lcd->RS = 0;
    lcd->R_W = 0;
    
    /* function set habilitado */
    lcd->data = 0x02;
    __delay_ms(1);
    
    /* habilita display */
    lcd->E = 1;
    __delay_ms(1);
    
    /* limpa saidas */
    lcd->E = 0;                
    __delay_ms(5);
          
    
    /* tamanho de dados */
    lcd->data = 0x02|data_lenght;    
    __delay_ms(1);
    
    /* habilita display */
    lcd->E = 1;
    __delay_ms(1);
    
    /* limpa saidas */
    lcd->E = 0;                
    __delay_ms(5);
    lcd->data = 0x00;        
    
    /* -- segunda parte -- */        
    
    /* numero de linhas e fonte */
    lcd->data = lcd->data|(num_lines<<3)|(char_font<<2);    
    __delay_ms(1);
    
    /* habilita display */
    lcd->E = 1;
    __delay_ms(1);
    
    /* limpa saidas */
    lcd->E = 0;                
    __delay_ms(5);
    lcd->data = 0x00;        
}

void display_onoff_control(t_display_port *lcd, char display_on, 
        char cursor_on, char blink){
    lcd->E = 0;
    lcd->RS = 0;
    lcd->R_W = 0;
        
    lcd->data = 0x00;
    __delay_ms(1);
    
    /* habilita display */
    lcd->E = 1;
    __delay_ms(1);
    
    /* limpa saidas */
    lcd->E = 0;                     
    __delay_ms(5);
    
    /* -- segunda parte -- */        
    
    /* numero de linhas e fonte */
    lcd->data = (0x08)|(display_on<<2)|(cursor_on<<1)|(blink);    
    __delay_ms(1);
    
    /* habilita display */
    lcd->E = 1;
    __delay_ms(1);
    
    /* limpa saidas */
    lcd->E = 0;                
    __delay_ms(5);
    lcd->data = 0x00;        
}


void entry_mode_set(t_display_port *lcd, char move_direction, char display_shift){
    lcd->E = 0;
    lcd->RS = 0;
    lcd->R_W = 0;
    
    lcd->data = 0x00;
    __delay_ms(1);
    
    /* habilita display */
    lcd->E = 1;
    __delay_ms(1);
    
    /* limpa saidas */
    lcd->E = 0;                     
    __delay_ms(5);
    
    /* -- segunda parte -- */ 
    lcd->data = 0x04|(move_direction<<1)|display_shift;
    __delay_ms(1);
    
    /* habilita display */
    lcd->E = 1;
    __delay_ms(1);
    
    /* limpa saidas */
    lcd->E = 0;                     
    lcd->data = 0x00;
    __delay_ms(5);
    
}

void goto_XY(t_display_port *lcd, char x, char y){
    
}

void write_char(t_display_port *lcd, char c){
    lcd->E = 0;
    lcd->RS = 1;
    lcd->R_W = 0;
    
    /* primeira parte do char */
    lcd->data = (c>>4);
    __delay_ms(1);
    
    /* habilita display */
    lcd->E = 1;
    __delay_ms(1);
    
    /* limpa saidas */
    lcd->E = 0;                         
    __delay_ms(5);
    
    /* segunda parte do char */
    lcd->data = (c);
    __delay_ms(1);
    
    /* habilita display */
    lcd->E = 1;
    __delay_ms(1);
    
    /* limpa saidas */
    lcd->E = 0;
    lcd->RS = 0;
    lcd->data = 0x00;
    __delay_ms(5);
}
