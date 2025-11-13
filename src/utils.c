#include <stdio.h>

void pause(void) {
    while(getchar() != '\n');
}

void clear_buffer(void) {
    while(getchar() != '\n');
}

void clear_screen(void) {
    printf("\033c\033[H");
}