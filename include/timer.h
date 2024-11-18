#ifndef TIMER_H
#define TIMER_H

#include <time.h>

// Estrutura para armazenar o tempo inicial
typedef struct {
    time_t start_time; // Tempo inicial
} Timer;

// Inicializa o temporizador
void start_timer(Timer *timer);

// Retorna o tempo decorrido em segundos
int get_elapsed_time(Timer *timer);

#endif
