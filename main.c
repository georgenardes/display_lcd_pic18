/*
 * File:   main.c
 * Author: George
 *
 * Created on 1 de Maio de 2020, 08:57
 */


#include <xc.h>
#include <pic18f4520.h>
#pragma config MCLRE = ON, WDT = OFF, OSC = HS

#define _XTAL_FREQ 16000000

typedef struct {
    char RS:1;
    char R_W:1;
    char E:1;
    char NA:1;
    char data:4;
}t_display_port;

t_display_port *lcd;

void init_lcd();
void function_set(char data_lenght, char num_lines, char char_font);
void display_onoff_control(char display_on, char cursor_on, char blink);
void entry_mode_set(char move_direction, char display_shift);
void goto_XY(char x, char y);
void write_char(char c);


void main(void) {
    ADCON1 = 0x0F;
    TRISD = 0x0;
    
    init_lcd();
    
    function_set(0, 0, 0);
    display_onoff_control(1, 1, 0);
    entry_mode_set(1,0);
        
    write_char('H');
    write_char('E');
    write_char('L');
    write_char('L');
    write_char('O');
    write_char(' ');
    write_char('W');
    write_char('O');
    write_char('R');
    write_char('L');
    write_char('D');
        
    while(1){
        
    }
    
}

/* define a largura de dados, qtd de linhas e fonte*/
void function_set(char data_lenght, char num_lines, char char_font){        
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


void display_onoff_control(char display_on, char cursor_on, char blink){
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


void entry_mode_set(char move_direction, char display_shift){
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


void init_lcd(){
    lcd = &PORTD;                
}

void goto_XY(char x, char y){
    
}

void write_char(char c){
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
