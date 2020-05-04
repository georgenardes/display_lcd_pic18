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
#include <stdio.h>
#include <string.h>

t_display_port *lcd;

void main(void) {
    ADCON1 = 0x0F;
    TRISD = 0x0;
        
    lcd = &PORTD;
            
    function_set(lcd, 0, 1, 0);
    display_onoff_control(lcd, 1, 1, 0);
    entry_mode_set(lcd, 1,0);
    goto_XY(lcd, 1, 1);                 //linha 1, coluna 1
    
    char palavra[16] = "DIOGO MARCHI";
    int tamanho = (int)strlen(palavra); //isto funciona só para delimitador de 1 caractere
    for(int i = 0; i < tamanho; i ++)
        write_char(lcd, palavra[i]);
   
    
    goto_XY(lcd, 2, 1);                 //linha 2, coluna 1
    
    char palavra2[16] = "GEORGE DE BORBA";
    int tamanho2 = (int)strlen(palavra2); //pega quantidade de caracteres
    for(int i = 0; i < tamanho2; i ++)
        write_char(lcd, palavra2[i]);
    
        
    while(1){
        
    }
    
}
