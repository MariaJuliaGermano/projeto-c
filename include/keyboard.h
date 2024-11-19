#ifndef KEYBOARD_H
#define KEYBOARD_H

// Funções atuais
char get_key(); // Captura teclas do usuário

// Funções da CLI-lib
void keyboardInit();       // Inicializa o teclado
void keyboardDestroy();    // Restaura as configurações do teclado
int keyhit();              // Verifica se há uma tecla pressionada
int readch();              // Lê a tecla pressionada

#endif
