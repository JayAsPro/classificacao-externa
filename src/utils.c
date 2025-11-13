/*
    Alunos: João Vitor Assumpção Proença
            João Vitor Spala
    Disciplina: Programação com Arquivos
    Professora: Isabel Leite Cafezeiro

    TRABALHO 1 - Classificação Externa por Seleção com Substituição

    Implementação das funções em utils.h.
*/

#include <stdio.h>

void clear_buffer(void) {
    int ch;
    while((ch = getchar() != '\n') && ch != EOF);
}

void pause(void) {
    printf("\n\nENTER para continuar...");
    clear_buffer();
}

void clear_screen(void) {
    printf("\033c\033[H");
}