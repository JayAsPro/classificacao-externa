/*
    Alunos: João Vitor Assumpção Proença
            João Vitor Spala
    Disciplina: Programação com Arquivos
    Professora: Isabel Leite Cafezeiro

    TRABALHO 1 - Classificação Externa por Seleção com Substituição

    Este é o código principal do programa, baseado no original criado pela professora.
*/

#include <stdio.h>

void clear_buffer(void) {
    int ch;
    while((ch = getchar() != '\n') && ch != EOF);
}

void pause(void) {
    printf("\n\nContinuar...");
    clear_buffer();
}

void clear_screen(void) {
    printf("\033c\033[H");
}