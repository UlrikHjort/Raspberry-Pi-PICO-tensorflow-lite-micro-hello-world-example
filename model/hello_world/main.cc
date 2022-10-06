#include "main_functions.h"
#include <stdio.h>
#include <pico/stdlib.h>

int main(int argc, char* argv[]) {
        stdio_init_all();
        setup();
        while (true) {
                loop();
        }
}
