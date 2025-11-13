/*
    Alunos: João Vitor Assumpção Proença
            João Vitor Spala
    Disciplina: Programação com Arquivos
    Professora: Isabel Leite Cafezeiro

    TRABALHO 1 - Classificação Externa por Seleção com Substituição

    Implementação das funções em arquivoBinario.h. Baseado no código
    disponibilizado pela professora.
*/

#include <stdio.h>
#include <locale.h>
#include <utils.h>
#include <arquivoBinario.h>

void insere(FILE* arq, int cod, float preco) {
    produto p;
    p.cod = cod;
    p.preco = preco;
    
    fseek(arq, 0, SEEK_END);    
    fwrite(&p, sizeof(produto), 1, arq);
}

void imprime_todos(FILE* arq) {
    produto p;
    int tam;
    int cont = 1;
    
    rewind(arq); // o mesmo que: fseek(arq, 0, SEEK_SET); 
    
    tam = fread(&p, sizeof(produto), 1, arq);
    while (tam > 0) {        
        printf("\nProduto(%d)..", cont);
        printf("\n  Codigo: %d", p.cod);
        printf("\n  Preco: %.2f", p.preco);
        printf("\n");
        cont++;
        
        tam = fread(&p, sizeof(produto), 1, arq);
    }
}

FILE* recria_arquivo(FILE* arq, char nome_arq[]) {
    fclose(arq);    
    remove(nome_arq);
    
    arq = fopen(nome_arq, "a+b");
    return arq;
}
