/*
    Alunos: João Vitor Assumpção Proença
            João Vitor Spala
    Disciplina: Programação com Arquivos
    Professora: Isabel Leite Cafezeiro

    TRABALHO 1 - Classificação Externa por Seleção com Substituição

    Implementação das funções em sort.h.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM_VET_TRAB 5

FILE* nova_particao(FILE* arq) {
    // A criação da partição começa da posição em que o cursor parou.
    int vetor_trabalho[TAM_VET_TRAB];
    
    //fread(&)
}

FILE* classificacao_externa(FILE* arq) {
    FILE** particoes = NULL;
    size_t num_particoes = 0;
    
    rewind(arq);
    
    while(!feof(arq)) {
        num_particoes += 1;
        particoes = realloc(particoes, num_particoes);
        
        particoes[num_particoes - 1] = nova_particao(arq);
    }
    
    
    // Finalização.
    for(size_t i = 0; i < sizeof(particoes); i++) {
        fclose(particoes[i]);
        // remove();
    }
    
    free(particoes);
}