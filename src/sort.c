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
    // Buscar a primeira posição válida para inicializar i_menor
    int i_menor = -1;
    for(int i = 0; i < tam; i++) {
        if(pos_validas[i]) {
            i_menor = i;
            break;
        }
    }
    
    if(i_menor == -1)
        return -1;
    
    // Encontrar o menor código entre as posições válidas
    for(int i = 0; i < tam; i++) {
        if(pos_validas[i] && vet_trabalho[i].cod < vet_trabalho[i_menor].cod)
            i_menor = i;
    }

    return i_menor;
}

// A criação da partição começa da posição em que o cursor parou.
int nova_particao(FILE* arq, size_t num_particao, produto* vet_trabalho) {
    char nome_part[256] = {0};
    FILE* part = NULL;
    int pos_validas[TAM_VET_TRABALHO] = {0};
    int ultimo_cod = -1;  // Rastreia o último código escrito na partição
    int elementos_escritos = 0;

    sprintf(nome_part, "part%zu.txt", num_particao);
    part = fopen(nome_part, "w");  // Modo texto
    if(part == NULL) {
        printf("\nErro ao criar partição %zu\n", num_particao);
        return 0;
    }
    
    // Inicializar posições válidas (produtos com código != 0)
    for(int i = 0; i < TAM_VET_TRABALHO; i++) {
        if(vet_trabalho[i].cod != 0)
            pos_validas[i] = 1;
    }

    int i_menor = i_menor_cod(vet_trabalho, pos_validas, TAM_VET_TRABALHO);

    // Loop principal: seleção com substituição
    while(i_menor != -1) {
        // Escrever o menor elemento na partição (formato texto)
        fprintf(part, "%d: %.2f\n", vet_trabalho[i_menor].cod, vet_trabalho[i_menor].preco);
        ultimo_cod = vet_trabalho[i_menor].cod;
        elementos_escritos++;
        
        // Ler novo produto do arquivo para substituir
        int leu = fread(&vet_trabalho[i_menor], sizeof(produto), 1, arq);
        
        if(leu > 0) {
            // Novo produto lido com sucesso
            if(vet_trabalho[i_menor].cod < ultimo_cod) {
                // Marca como inválida - vai para próxima partição
                pos_validas[i_menor] = 0;
            }
            // Senão, mantém válido (pos_validas[i_menor] já é 1)
        } else {
            // EOF alcançado - zera para segurança
            pos_validas[i_menor] = 0;
            vet_trabalho[i_menor].cod = 0;
            vet_trabalho[i_menor].preco = 0.0;
        }
        
        // Encontrar próximo menor (sem redeclarar i_menor!)
        i_menor = i_menor_cod(vet_trabalho, pos_validas, TAM_VET_TRABALHO);
    }

    fclose(part);
    
    // Se não escreveu nada, deletar arquivo e retornar 0
    if(elementos_escritos == 0) {
        remove(nome_part);
        return 0;
    }
    
    return 1;  // Retorna 1 para indicar sucesso
}

size_t classificacao_externa(FILE* arq) {
    size_t num_particoes = 0;
    produto vet_trabalho[TAM_VET_TRABALHO] = {0};
    
    rewind(arq);
    
    // Carregar buffer inicial
    int leu;
    int i = 0;
    do {
        leu = fread(&vet_trabalho[i], sizeof(produto), 1, arq);
        if(leu > 0) {
            i += 1;
        }
    } while(i < TAM_VET_TRABALHO && leu > 0);

    // Se não conseguiu ler nenhum produto, retornar 0
    if(i == 0) {
        printf("\nArquivo vazio ou erro de leitura.\n");
        return 0;
    }

    // Gerar partições até não ter mais dados
    int sucesso;
    do {
        sucesso = nova_particao(arq, num_particoes, vet_trabalho);
        if(sucesso) {
            num_particoes++;
            
            // Verificar se ainda há elementos válidos no buffer
            int tem_dados = 0;
            for(int j = 0; j < TAM_VET_TRABALHO; j++) {
                if(vet_trabalho[j].cod != 0) {
                    tem_dados = 1;
                    break;
                }
            }
            
            // Se não há mais dados no buffer, encerrar
            if(!tem_dados) {
                break;
            }
        }
    } while(sucesso);
    
    return num_particoes;
}

void imprime_particoes(size_t num_particoes) {
    char nome_part[256];
    FILE* part;
    int cod;
    float preco;
    
    printf("\n========================================");
    printf("\n   PARTIÇÕES GERADAS: %zu", num_particoes);
    printf("\n========================================\n");
    
    for(size_t i = 0; i < num_particoes; i++) {
        sprintf(nome_part, "part%zu.txt", i);
        part = fopen(nome_part, "r");
        
        if(part == NULL) {
            printf("\n[ERRO] Não foi possível abrir %s\n", nome_part);
            continue;
        }
        
        printf("\n--- Partição %zu (%s) ---\n", i, nome_part);
        
        int count = 0;
        while(fscanf(part, "%d: %f", &cod, &preco) == 2) {
            printf("  Código: %d | Preço: %.2f\n", cod, preco);
            count++;
        }
        
        printf("  Total: %d produtos\n", count);
        fclose(part);
    }
    
    printf("\n========================================\n");
}