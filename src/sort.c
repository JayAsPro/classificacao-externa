/*
    Alunos: João Vitor Assumpção Proença
            João Vitor Spala
    Disciplina: Programação com Arquivos
    Professora: Isabel Leite Cafezeiro

    TRABALHO 1 - Classificação Externa por Seleção com Substituição

    Implementação das funções em sort.h.
*/

#include <stdlib.h>
#include <stdio.h>
#include <arquivoBinario.h>

#define TAM_VET_TRABALHO 5

int i_menor_cod(produto* vet_trabalho, int* pos_validas, int tam) {
    int i_menor = 0;
    
    for(int i = 0; i < tam; i++) {
        if(vet_trabalho[i].cod < vet_trabalho[i_menor].cod && pos_validas[i])
            i_menor = i;
    }

    if(!pos_validas[i_menor])
        i_menor = -1;

    return i_menor;
}

// A criação da partição começa da posição em que o cursor parou.
FILE* nova_particao(FILE* arq, size_t num_particao, produto* vet_trabalho) {
    char nome_part[256] = {0};
    FILE* part = NULL;
    int pos_validas[TAM_VET_TRABALHO] = {0};

    sprintf(nome_part, "part%zu.bin", num_particao);
    part = fopen(nome_part, "wb");
    printf("\n%p\n", part);
    
    for(int i = 0; i < TAM_VET_TRABALHO; i++) {
        if(vet_trabalho[i].cod != 0)
            pos_validas[i] = 1;
    }

    int i_menor = i_menor_cod(vet_trabalho, pos_validas, TAM_VET_TRABALHO);

    while(i_menor != -1) {
        fwrite(&vet_trabalho[i_menor], sizeof(produto), 1, part);
        fread(&vet_trabalho[i_menor], sizeof(produto), 1, arq);
        int i_menor = i_menor_cod(vet_trabalho, pos_validas, TAM_VET_TRABALHO);
    }

    return part;
}

FILE* classificacao_externa(FILE* arq) {
    FILE** particoes = NULL;
    size_t num_particoes = 0;
    produto vet_trabalho[TAM_VET_TRABALHO] = {0};
    
    rewind(arq);
    
    int ver;
    int i = 0;
    do {
        ver = fread(&vet_trabalho[i], sizeof(produto), 1, arq);
        i += 1;
    } while(i < TAM_VET_TRABALHO && ver > 0);

    do {
        num_particoes += 1;
        particoes = realloc(particoes, num_particoes);
        
        particoes[num_particoes - 1] = nova_particao(arq, num_particoes - 1, vet_trabalho);
    } while(particoes[num_particoes - 1] != NULL);
    
    // Finalização.
    for(size_t i = 0; i < sizeof(particoes); i++)
        fclose(particoes[i]);
    
    free(particoes);
}