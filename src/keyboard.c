#include "keyboard.h"
#include <termios.h>
#include <unistd.h>

// CLI-lib
static struct termios initialSettings, newSettings;
static int peekCharacter;

void keyboardInit() {
    tcgetattr(0, &initialSettings);
    newSettings = initialSettings;
    newSettings.c_lflag &= ~ICANON;
    newSettings.c_lflag &= ~ECHO;
    newSettings.c_cc[VMIN] = 1;
    newSettings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &newSettings);
}

void keyboardDestroy() {
    tcsetattr(0, TCSANOW, &initialSettings);
}

int keyhit() {
    unsigned char ch;
    int nread;

    if (peekCharacter != -1) return 1;

    newSettings.c_cc[VMIN] = 0;
    tcsetattr(0, TCSANOW, &newSettings);
    nread = read(0, &ch, 1);
    newSettings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &newSettings);

    if (nread == 1) {
        peekCharacter = ch;
        return 1;
    }
    return 0;
}

int readch() {
    char ch;
    if (peekCharacter != -1) {
        ch = peekCharacter;
        peekCharacter = -1;
        return ch;
    }
    read(0, &ch, 1);
    return ch;
}

// Sua função existente para capturar entrada do jogador
char get_key() {
    return readch(); // Utiliza CLI-lib para capturar a tecla pressionada
}
