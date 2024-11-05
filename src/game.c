#include <stdio.h>
#include <string.h>
#include "keyboard.h"
#include "screen.h"
#include "timer.h"
#include "game.h"

#define MAX_TENTATIVAS 6
#define TAMANHO_PALAVRA 20

void inicializa_palavra(char* palavra, char* letras_acertadas) {
    int tamanho = strlen(palavra);
    for (int i = 0; i < tamanho; i++) {
        letras_acertadas[i] = '_';
    }
    letras_acertadas[tamanho] = '\0';
}

void exibir_status(int tentativas, char* letras_acertadas) {
    screenSetColor(WHITE, BLACK);
    screenGotoxy(SCRSTARTX, SCRSTARTY);
    printf("Palavra: %s\n", letras_acertadas);
    screenGotoxy(SCRSTARTX, SCRSTARTY + 1);
    printf("Tentativas restantes: %d\n", tentativas);
    screenUpdate();
}

int verifica_letra(char letra, char* palavra, char* letras_acertadas) {
    int acertou = 0;
    for (int i = 0; i < strlen(palavra); i++) {
        if (palavra[i] == letra && letras_acertadas[i] == '_') {
            letras_acertadas[i] = letra;
            acertou = 1;
        }
    }
    return acertou;
}

int jogo_completo(char* letras_acertadas) {
    return strchr(letras_acertadas, '_') == NULL;
}

void start_game() {
    char palavra_secreta[TAMANHO_PALAVRA] = "programacao";
    char letras_acertadas[TAMANHO_PALAVRA];
    int tentativas = MAX_TENTATIVAS;

    inicializa_palavra(palavra_secreta, letras_acertadas);
    screenInit(1); 

    while (tentativas > 0) {
        exibir_status(tentativas, letras_acertadas);

        if (keyhit()) { 
            char letra = readch();  
            if (!verifica_letra(letra, palavra_secreta, letras_acertadas)) {
                tentativas--;
            }

            if (jogo_completo(letras_acertadas)) {
                screenGotoxy(SCRSTARTX, SCRENDY - 2);
                printf("Parabéns! Você acertou a palavra: %s\n", palavra_secreta);
                break;
            }
        }
        
        timerUpdateTimer(500);  
        if (timerTimeOver()) {
            screenGotoxy(SCRSTARTX, SCRENDY - 3);
            timerPrint();
            screenUpdate();
        }
    }

    if (tentativas == 0) {
        screenGotoxy(SCRSTARTX, SCRENDY - 2);
        printf("Você perdeu! A palavra era: %s\n", palavra_secreta);
    }

    screenDestroy(); 
}
