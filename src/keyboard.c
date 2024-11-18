#include "keyboard.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

char get_key() {
    struct termios oldt, newt;
    char ch;

    // Desativa o buffer de entrada
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Captura o caractere pressionado
    ch = getchar();

    // Restaura as configurações do terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
