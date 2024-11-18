#include "timer.h"
#include <time.h>

void start_timer(Timer *timer) {
    timer->start_time = time(NULL); // Salva o tempo inicial
}

int get_elapsed_time(Timer *timer) {
    return (int)(time(NULL) - timer->start_time); // Retorna o tempo decorrido
}
