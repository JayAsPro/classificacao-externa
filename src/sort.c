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

#define TAM_VET_TRAB 5

FILE* nova_particao(FILE* arq, size_t num_particao, int* vetor_trabalho) {
    // A criação da partição começa da posição em que o cursor parou.
    char nome_arq[16] = {0};
    sprintf(nome_arq, "tmp/part%zu.bin", num_particao);
    
    FILE* part = fopen(nome_arq, "wb");
    
    int pos_validas[TAM_VET_TRAB];
    for(int i = 0; i < TAM_VET_TRAB; i++)
        pos_validas[i] = 1;
    
    int i = 0;
    while(!feof(arq)) {
        fread(&vetor_trabalho[i], sizeof(produto), 1, arq);
        pos_validas[i] = 1;
        i += 1;
    }
    
    return NULL;
}

FILE* classificacao_externa(FILE* arq) {
    FILE** particoes = NULL;
    size_t num_particoes = 0;
    
    rewind(arq);
    
    produto vetor_trabalho[TAM_VET_TRAB] = {0};
    
    while(!feof(arq)) {
        num_particoes += 1;
        particoes = realloc(particoes, num_particoes);
        
        //particoes[num_particoes - 1] = nova_particao(arq, num_particoes - 1, vetor_trabalho);
    }
    
    // Finalização.
    for(size_t i = 0; i < sizeof(particoes); i++) {
        fclose(particoes[i]);
        // remove();
    }
    
    free(particoes);
}