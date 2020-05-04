/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   lcd_hd_44780.h
 * Author: 
 * Diogo Marchi Agenor
 * George de Borba Nardes
 *          
 *  
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "config.h"

typedef struct {
    char RS:1;
    char R_W:1;
    char E:1;
    char NA:1;
    char data:4;
}t_display_port;


/**      
    
    @Description:  define a largura de dados, qtd de linhas e fonte
      
    @Parameters: ponteiro do tipo t_display_port, 
                data_lenght: 1 para 8bit; 0 para 4bit 
                num_lines: 1 para 2 linha; 0 para 1 linha
    @Returns: Void      
 */
void function_set(t_display_port *lcd, char data_lenght, 
        char num_lines, char char_font);

/**      
    
    @Description:  Habilita display e o cursor. Também define se o caracter
 indicado pelo cursor irá piscar
 
    @Parameters: ponteiro do tipo t_display_port, 
                diplay_on: 1 habilita; 0 desabilita
                cusor_on: 1 habilita; 0 desabilita
                blink: 1 habilita; 0 desabilita
    @Returns: Void      
 */
void display_onoff_control(t_display_port *lcd, char display_on,
        char cursor_on, char blink);

/**      
    
    @Description:  define se o endereco DDRAM será incrementado ou decrementado
                  e se o diplay será deslocado ou não
    @Parameters: ponteiro do tipo t_display_port, 
                move_direction: 1 para esquerda; 0 para direita
                display_shift: 1 habilita; 0 desabilita
    @Returns: Void      
 */
void entry_mode_set(t_display_port *lcd,char move_direction, 
        char display_shift);

/**      
    
    @Description:  
      
    @Parameters: ponteiro do tipo t_display_port, 
                x
                y: 
    @Returns: Void      
 */
void goto_XY(t_display_port *lcd,
        unsigned char x, unsigned char y);

/**      
    
    @Description:  
 *       
    @Parameters: ponteiro do tipo t_display_port, 
                c:
    @Returns: Void      
 */
void lcd_cmd(t_display_port *lcd, char c);

/**      
    
    @Description:  
      
    @Parameters: ponteiro do tipo t_display_port, 
                c:
    @Returns: Void      
 */
void write_char(t_display_port *lcd, char c);

/**      
    
    @Description:  limpa o display      
    @Parameters: ponteiro do tipo t_display_port,                 
    @Returns: Void      
 */
void clear_diplay(t_display_port *lcd);



/**      
    @Description:  Retorna ao erndereço DDRAM para 0
    @Parameters: ponteiro do tipo t_display_port,       
    @Returns: Void      
 */
void return_home(t_display_port *lcd);

#endif	/* XC_HEADER_TEMPLATE_H */

