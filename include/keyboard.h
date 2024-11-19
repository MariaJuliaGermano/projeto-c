/**
 * keyboard.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
*/

#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

/**
 * Inicializa o teclado.
 * Configura o terminal para capturar entradas de teclado sem buffer.
 */
void keyboardInit();

/**
 * Restaura as configurações originais do teclado.
 */
void keyboardDestroy();

/**
 * Verifica se há uma tecla pressionada.
 *  1 se há uma tecla pronta para ser lida, 0 caso contrário.
 */
int keyhit();

/**
 * Lê o caractere da tecla pressionada.
 *  o código ASCII da tecla pressionada.
 */
int readch();

#endif /* __KEYBOARD_H__ */
