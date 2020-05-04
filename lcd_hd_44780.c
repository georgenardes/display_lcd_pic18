/* 
 * File:   lcd_hd_44780.c
 * Author: 
 * Diogo Marchi Agenor
 * George de Borba Nardes
 *          
 *  
 */

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

void lcd_cmd(t_display_port *lcd, char a){
    lcd->RS = 0;
    lcd->data = (a);
    __delay_ms(1);
    
    /* habilita display */
    lcd->E = 1;
    __delay_ms(1);
    
    /* limpa saidas */
    lcd->E = 0;                         
    __delay_ms(5);
    lcd->data = 0x0;
}

void goto_XY(t_display_port *lcd, unsigned char x, unsigned char y){
    unsigned char temp,z,a;
    if(x == 1)
    {
       temp = 0x80 + y - 1;
       z = temp>>4;
       a = temp;
       lcd_cmd(lcd, z);
       __delay_ms(1);
       lcd_cmd(lcd, a);
    }
    else if(x == 2)
    {
       temp = 0xC0 + y - 1;
       z = temp>>4;
       a = temp;
       lcd_cmd(lcd, z);
       __delay_ms(1);
       lcd_cmd(lcd, a);
    } 
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
    __delay_ms(5);
    lcd->data = 0x00;
    
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

void clear_display(t_display_port *lcd){
    lcd->E = 0;
    lcd->RS = 0;
    lcd->R_W = 0;
    
    /* primeira parte */
    lcd->E = 0;
    lcd->data = 0x0;
    __delay_ms(1);
    
    /* pulso no display */
    lcd->E = 1;
    __delay_ms(1);
            
    lcd->E = 0;
    __delay_ms(1);
    
    /* segunda parte */
    lcd->data = 0x1;
    
    /* pulso no display  */
    lcd->E = 1;
    __delay_ms(1);
    
    /* finalizando */
    lcd->E = 0;
    __delay_ms(1);
    lcd->data = 0x0;
    
}

void return_home(t_display_port *lcd){
    lcd->E = 0;
    lcd->RS = 0;
    lcd->R_W = 0;
    
    /* primeira parte */
    lcd->E = 0;
    lcd->data = 0x0;
    __delay_ms(1);
    
    /* pulso no display */
    lcd->E = 1;
    __delay_ms(1);
            
    lcd->E = 0;
    __delay_ms(1);
    
    /* segunda parte */
    lcd->data = 0x2;
    
    /* pulso no display  */
    lcd->E = 1;
    __delay_ms(1);
    
    /* finalizando */
    lcd->E = 0;
    __delay_ms(1);
    lcd->data = 0x0;
    
}