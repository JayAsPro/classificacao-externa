/*
    Alunos: João Vitor Assumpção Proença
            João Vitor Spala
    Disciplina: Programação com Arquivos
    Professora: Isabel Leite Cafezeiro

    TRABALHO 1 - Classificação Externa por Seleção com Substituição

    Funções para criação e manipulação de um arquivo binário que representa
    uma lista de produtos. Baseado no código disponibilizado pela professora.
*/

#ifndef ARQUIVOBINARIO_H
#define ARQUIVOBINARIO_H

typedef struct sproduto {
    int cod;
    float preco;
} produto;

void insere(FILE* arq, int cod, float preco);

void imprime_todos(FILE* arq);

FILE* recria_arquivo(FILE* arq, char nome_arq[]);

#endif
