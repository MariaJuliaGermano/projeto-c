#include "timer.h"

// Inicializa o temporizador com o tempo atual
void start_timer(Timer *timer) {
    timer->start_time = time(NULL);
}

// Retorna o tempo decorrido em segundos desde o início
int get_elapsed_time(Timer *timer) {
    return (int)(time(NULL) - timer->start_time);
}
