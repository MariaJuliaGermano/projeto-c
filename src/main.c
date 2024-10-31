#include "cli_lib.h"
#include "game.h"

int main() {
    cli_init(); 
    start_game(); 
    cli_cleanup(); 
    return 0;
}
