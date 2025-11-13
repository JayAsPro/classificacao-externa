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
    if(arq == NULL) {
        printf("\nErro ao recriar o arquivo %s!\n", nome_arq);
    }
    return arq;
}

void popular_dados_teste(FILE* arq) {
    printf("\nPopulando arquivo com dados de teste...\n");
    
    // Dados desordenados para testar a classificação externa
    insere(arq, 50, 15.50);
    insere(arq, 10, 25.00);
    insere(arq, 30, 10.75);
    insere(arq, 70, 32.40);
    insere(arq, 20, 18.90);
    insere(arq, 40, 22.30);
    insere(arq, 60, 14.20);
    insere(arq, 15, 28.50);
    insere(arq, 25, 11.60);
    insere(arq, 80, 35.00);
    insere(arq, 5, 9.99);
    insere(arq, 45, 19.75);
    insere(arq, 35, 16.80);
    insere(arq, 55, 27.30);
    insere(arq, 65, 13.40);
    
    printf("\n✓ 15 produtos inseridos com sucesso!\n");
}
