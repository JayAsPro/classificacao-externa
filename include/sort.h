/*
    Alunos: João Vitor Assumpção Proença
            João Vitor Spala
    Disciplina: Programação com Arquivos
    Professora: Isabel Leite Cafezeiro

    TRABALHO 1 - Classificação Externa por Seleção com Substituição

    Funções para ordernar um arquivo binário utilizando classificação externa
    por seleção com substituição.
*/

#ifndef SORT_H
#define SORT_H

#include <stdio.h>

// Retorna o número de partições geradas
size_t classificacao_externa(FILE* arq);

// Imprime as partições geradas
void imprime_particoes(size_t num_particoes);

#endif
